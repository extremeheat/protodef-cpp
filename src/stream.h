#pragma once
#include <string>
#include <vector>
#define CHECK_BOUNDS(index) if (index >= this->length) { return false; }
namespace pdef {
/*
  u8: 'writeByte',
  u16: 'writeUShortBE',
  u32: 'writeUIntBE',
  u64: 'writeULongBE',
  i8: 'writeByte',
  i16: 'writeShortBE',
  i32: 'writeIntBE',
  i64: 'writeLongBE',
  f32: 'writeFloatBE',
  f64: 'writeDoubleBE',
  lu16: 'writeUShortLE',
  lu32: 'writeUIntLE',
  lu64: 'writeULongLE',
  li16: 'writeShortLE',
  li32: 'writeIntLE',
  li64: 'writeLongLE',
  lf32: 'writeFloatLE',
  lf64: 'writeDoubleLE',
  bool: 'writeBool',
  string: 'writeString',
  buffer: 'writeBuffer',
  varint: 'writeUnsignedVarInt',
  varint64: 'writeUnsignedVarLong',
  zigzag32: 'writeZigZagVarInt',
  zigzag64: 'writeZigZagVarLong',
*/
struct BinaryStream {
  char *buffer;
  int length;
  int writeIndex = 0;
  int readIndex = 0;

  BinaryStream(int length) : length(length) {}

  // Varints
  int sizeOfVarInt(int32_t value) {
    if (value < 0) return 10;
    if (value < 0x80) return 1;
    if (value < 0x4000) return 2;
    if (value < 0x200000) return 3;
    if (value < 0x10000000) return 4;
    return 5;
  }
  int sizeOfZigZagVarInt(int32_t value) { return sizeOfVarInt((value << 1) ^ (value >> 31)); }
  int sizeOfVarLong(int64_t value) {
    if (value < 0) return 10;
    if (value < 0x80) return 1;
    if (value < 0x4000) return 2;
    if (value < 0x200000) return 3;
    if (value < 0x10000000) return 4;
    if (value < 0x800000000) return 5;
    if (value < 0x40000000000) return 6;
    if (value < 0x2000000000000) return 7;
    if (value < 0x100000000000000) return 8;
    return 9;
  }
  int sizeOfZigZagVarLong(int64_t value) { return sizeOfVarLong((value << 1) ^ (value >> 63)); }
  int sizeOfVarInt64(int64_t value) { return sizeOfVarLong(value); }

  // Buffer/String
  int sizeOfBuffer(std::vector<unsigned char> &buffer) { return buffer.size(); }
  int sizeOfString(std::string &value) { return value.length(); }
  
  bool writeByte(int8_t value) {
    CHECK_BOUNDS(writeIndex);
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeUByte(uint8_t value) {
    CHECK_BOUNDS(writeIndex);
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeUShortBE(uint16_t value) {
    CHECK_BOUNDS(writeIndex + 2);
    buffer[writeIndex++] = value >> 8;
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeUIntBE(uint32_t value) {
    CHECK_BOUNDS(writeIndex + 4);
    buffer[writeIndex++] = value >> 24;
    buffer[writeIndex++] = value >> 16;
    buffer[writeIndex++] = value >> 8;
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeULongBE(uint64_t value) {
    CHECK_BOUNDS(writeIndex + 8);
    buffer[writeIndex++] = value >> 56;
    buffer[writeIndex++] = value >> 48;
    buffer[writeIndex++] = value >> 40;
    buffer[writeIndex++] = value >> 32;
    buffer[writeIndex++] = value >> 24;
    buffer[writeIndex++] = value >> 16;
    buffer[writeIndex++] = value >> 8;
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeShortBE(int16_t value) {
    return writeUShortBE(value);
  }
  bool writeIntBE(int32_t value) {
    return writeUIntBE(value);
  }
  bool writeLongBE(int64_t value) {
    return writeULongBE(value);
  }
  bool writeFloatBE(float value) {
    return writeUIntBE(*(uint32_t *)&value);
  }
  bool writeDoubleBE(double value) {
    return writeULongBE(*(uint64_t *)&value);
  }
  bool writeUShortLE(uint16_t value) {
    CHECK_BOUNDS(writeIndex + 2);
    memcpy(buffer + writeIndex, &value, 2);
    return true;
  }
  bool writeUIntLE(uint32_t value) {
    CHECK_BOUNDS(writeIndex + 4);
    memcpy(buffer + writeIndex, &value, 4);
    return true;
  }
  bool writeULongLE(uint64_t value) {
    CHECK_BOUNDS(writeIndex + 8);
    memcpy(buffer + writeIndex, &value, 8);
    return true;
  }
  bool writeShortLE(int16_t value) {
    return writeUShortLE(value);
  }
  bool writeIntLE(int32_t value) {
    return writeUIntLE(value);
  }
  bool writeLongLE(int64_t value) {
    return writeULongLE(value);
  }
  bool writeFloatLE(float value) {
    return writeUIntLE(*(uint32_t *)&value);
  }
  bool writeDoubleLE(double value) {
    return writeULongLE(*(uint64_t *)&value);
  }
  bool writeBool(bool value) {
    return writeByte(value ? 1 : 0);
  }
  bool writeCString(std::string &value) {
    CHECK_BOUNDS(writeIndex + value.length() + 1);
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length();
    buffer[writeIndex++] = 0;
    return true;
  }
  bool writeString(std::string &value) {
    CHECK_BOUNDS(writeIndex + value.length());
    memcpy(buffer + writeIndex, value.data(), value.length());
    writeIndex += value.length();
    return true;
  }
  bool writeBuffer(std::vector<unsigned char> &value) {
    CHECK_BOUNDS(writeIndex + value.size());
    memcpy(buffer + writeIndex, value.data(), value.size());
    writeIndex += value.size();
    return true;
  }
  int writeUnsignedVarInt(uint32_t value) {
    CHECK_BOUNDS(writeIndex + sizeOfVarInt(value));
    int j = 0;
    do {
      uint8_t temp = value & 0b01111111;
      value >>= 7;
      if (value != 0) {
        temp |= 0b10000000;
      }
      buffer[writeIndex++] = temp;
      j++;
    } while (value != 0);
    return j; 
  }
  int writeUnsignedVarInt(int32_t value) {
    return writeUnsignedVarInt((uint32_t&) value);
  }
  int writeUnsignedVarLong(uint64_t value) {
    CHECK_BOUNDS(writeIndex + sizeOfVarInt64(value));
    int j = 0;
    do {
      uint8_t temp = value & 0b01111111;
      value >>= 7;
      if (value != 0) {
        temp |= 0b10000000;
      }
      buffer[writeIndex++] = temp;
      j++;
    } while (value != 0);
    return j;
  }
  int writeUnsignedVarLong(int64_t value) {
    return writeUnsignedVarLong((uint64_t&) value);
  }
  bool writeZigZagVarInt(int32_t value) {
    return writeUnsignedVarInt((value << 1) ^ (value >> 31));
  }
  bool writeZigZagVarLong(int64_t value) {
    return writeUnsignedVarLong((value << 1) ^ (value >> 63));
  }
  bool readUnsignedVarInt(uint32_t &value) {
    value = 0;
    int i = 0;
    while (true) {
      uint8_t b;
      if (!readUByte(b)) return false;
      value |= (b & 0b01111111) << i++ * 7;
      if ((b & 0b10000000) == 0) break;
    }
    return true;
  }
  bool readUnsignedVarInt(int32_t &value) {
    return readUnsignedVarInt((uint32_t&) value);
  }
  bool readUnsignedVarLong(uint64_t &value) {
    value = 0;
    int i = 0;
    while (true) {
      uint8_t b;
      if (!readUByte(b)) return false;
      value |= (b & 0b01111111) << i++ * 7;
      if ((b & 0b10000000) == 0) break;
    }
    return true;
  }
  bool readUnsignedVarLong(int64_t &value) {
    return readUnsignedVarLong((uint64_t&) value);
  }
  bool readZigZagVarInt(int32_t &value) {
    uint32_t temp;
    if (!readUnsignedVarInt(temp)) return false;
    value = (temp >> 1) ^ -(temp & 1);
    return true;
  }
  bool readZigZagVarLong(int64_t &value) {
    uint64_t temp;
    if (!readUnsignedVarLong(temp)) return false;
    value = (temp >> 1) ^ -(temp & 1);
    return true;
  }
  bool readByte(int8_t &value) {
    CHECK_BOUNDS(readIndex + 1);
    value = buffer[readIndex++];
    return true;
  }
  bool readUByte(uint8_t &value) {
    CHECK_BOUNDS(readIndex + 1);
    value = buffer[readIndex++];
    return true;
  }
  bool readUShortBE(uint16_t &value) {
    CHECK_BOUNDS(readIndex + 2);
    value = buffer[readIndex++] << 8;
    value |= buffer[readIndex++];
    return true;
  }
  bool readUIntBE(uint32_t &value) {
    CHECK_BOUNDS(readIndex + 4);
    value = buffer[readIndex++] << 24;
    value |= buffer[readIndex++] << 16;
    value |= buffer[readIndex++] << 8;
    value |= buffer[readIndex++];
    return value;
  }
  bool readULongBE(uint64_t &value) {
    CHECK_BOUNDS(readIndex + 8);
    value = static_cast<uint64_t>(buffer[readIndex++]) << 56LL;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 48;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 40;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 32;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 24;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 16;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 8;
    value |= static_cast<uint64_t>(buffer[readIndex++]);
    return true;
  }
  bool readShortBE(int16_t &value) {
    return readUShortBE((uint16_t&) value);
  }
  bool readIntBE(int32_t &value) {
    return readUIntBE((uint32_t&) value);
  }
  bool readLongBE(int64_t &value) {
    return readULongBE((uint64_t&) value);
  }
  bool readFloatBE(float &value) {
    return readUIntBE(*(uint32_t*)&value);
  }
  bool readDoubleBE(double &value) {
    return readULongBE(*(uint64_t*)&value);
  }
  bool readUShortLE(uint16_t &value) {
    CHECK_BOUNDS(readIndex + 2);
    memcpy(&value, buffer + readIndex, 2);
    readIndex += 2;
    return true;
  }
  bool readUIntLE(uint32_t &value) {
    CHECK_BOUNDS(readIndex + 4);
    memcpy(&value, buffer + readIndex, 4);
    readIndex += 4;
    return true;
  }
  bool readULongLE(uint64_t &value) {
    CHECK_BOUNDS(readIndex + 8);
    memcpy(&value, buffer + readIndex, 8);
    readIndex += 8;
    return true;
  }
  bool readShortLE(int16_t &value) {
    return readUShortLE((uint16_t&) value);
  }
  bool readIntLE(int32_t &value) {
    return readUIntLE((uint32_t&) value);
  }
  bool readLongLE(int64_t &value) {
    return readULongLE((uint64_t&) value);
  }
  bool readFloatLE(float &value) {
    CHECK_BOUNDS(readIndex + 4);
    memcpy(&value, buffer + readIndex, 4);
    readIndex += 4;
    return true;
  }
  double readDoubleLE(double &value) {
    CHECK_BOUNDS(readIndex + 8);
    memcpy(&value, buffer + readIndex, 8);
    readIndex += 8;
    return true;
  }
  bool readBool(bool &value) {
    CHECK_BOUNDS(readIndex + 1);
    value = buffer[readIndex++] != 0;
    return true;
  }
  bool readCString(std::string &value) {
    while (true) {
      int8_t c;
      if (!readByte(c)) return false;
      if (c == 0) break;
      value += c;
    }
    return true;
  }
  bool readString(std::string &value, int length) {
    CHECK_BOUNDS(readIndex + length);
    value = std::string(buffer + readIndex, buffer + readIndex + length);
    readIndex += length;
    return true;
  }
  bool readBuffer(std::vector<unsigned char> &value, int length) {
    CHECK_BOUNDS(readIndex + length);
    value = std::vector<unsigned char>(buffer + readIndex, buffer + readIndex + length);
    readIndex += length;
    return true;
  }
};
using Stream = BinaryStream;
}