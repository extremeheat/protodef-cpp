#pragma once
#include <string>
#define CHECK_BOUNDS(index) if (index >= this->length) { return false; }
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

  int sizeOfVarIntPrefixedString(std::string value) { return sizeOfVarInt(value.length()) + value.length(); }
  int sizeOfVarIntPrefixedBuffer(char *value, int bufferLength) { return sizeOfVarInt(bufferLength) + bufferLength; }
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
  int sizeOfVarInt64PrefixedString(std::string value) { return sizeOfVarInt64(value.length()) + value.length(); }
  int sizeOfVarInt64PrefixedBuffer(char *value, int bufferLength) { return sizeOfVarInt64(bufferLength) + bufferLength; }
  int sizeOfZigZagVarIntPrefixedString(std::string value) { return sizeOfZigZagVarInt(value.length()) + value.length(); }
  int sizeOfBuffer(char *value, int bufferLength) { return bufferLength; }

  bool writeByte(int8_t value) {
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
  bool writeIntPrefixedString(std::string &value) {
    CHECK_BOUNDS(writeIndex + value.length() + 4);
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length() + 4;
    return true;
  }
  bool writeUnsignedVarIntPrefixedString(std::string &value) {
    CHECK_BOUNDS(writeIndex + sizeOfVarIntPrefixedString(value));
    int wroteLength = writeUnsignedVarInt(value.length());
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length();
    return wroteLength;
  }
  bool writeZigZagVarIntPrefixedString(std::string &value) {
    CHECK_BOUNDS(writeIndex + sizeOfZigZagVarIntPrefixedString(value));
    writeZigZagVarInt(value.length());
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length();
    return true;
  }
  bool writeBuffer(BinaryStream &value) {
    CHECK_BOUNDS(writeIndex + value.length);
    memcpy(buffer + writeIndex, value.buffer, value.length);
    writeIndex += value.length;
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
  bool writeUnsignedVarLong(uint64_t value) {
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
  bool writeZigZagVarInt(int32_t value) {
    return writeUnsignedVarInt((value << 1) ^ (value >> 31));
  }
  bool writeZigZagVarLong(int64_t value) {
    return writeUnsignedVarLong((value << 1) ^ (value >> 63));
  }
  // Read methods must be checked by the caller
  int8_t readByte() {
    return buffer[readIndex++];
  }
  uint16_t readUShortBE() {
    uint16_t value = buffer[readIndex++] << 8;
    value |= buffer[readIndex++];
    return value;
  }
  uint32_t readUIntBE() {
    uint32_t value = buffer[readIndex++] << 24;
    value |= buffer[readIndex++] << 16;
    value |= buffer[readIndex++] << 8;
    value |= buffer[readIndex++];
    return value;
  }
  uint64_t readULongBE() {
    uint64_t value = static_cast<uint64_t>(buffer[readIndex++]) << 56LL;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 48;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 40;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 32;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 24;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 16;
    value |= static_cast<uint64_t>(buffer[readIndex++]) << 8;
    value |= static_cast<uint64_t>(buffer[readIndex++]);
    return value;
  }
  int16_t readShortBE() {
    return readUShortBE();
  }
  int32_t readIntBE() {
    return readUIntBE();
  }
  int64_t readLongBE() {
    return readULongBE();
  }
  float readFloatBE() {
    uint32_t value = readUIntBE();
    return *(float *)&value;
  }
  double readDoubleBE() {
    uint64_t value = readULongBE();
    return *(double *)&value;
  }
  uint16_t readUShortLE() {
    uint16_t value;
    memcpy(&value, buffer + readIndex, 2);
    readIndex += 2;
    return value;
  }
  uint32_t readUIntLE() {
    uint32_t value;
    memcpy(&value, buffer + readIndex, 4);
    readIndex += 4;
    return value;
  }
  uint64_t readULongLE() {
    uint64_t value;
    memcpy(&value, buffer + readIndex, 8);
    readIndex += 8;
    return value;
  }
  int16_t readShortLE() {
    return readUShortLE();
  }
  int32_t readIntLE() {
    return readUIntLE();
  }
  int64_t readLongLE() {
    return readULongLE();
  }
  float readFloatLE() {
    uint32_t value = readUIntLE();
    return *(float *)&value;
  }
  double readDoubleLE() {
    uint64_t value = readULongLE();
    return *(double *)&value;
  }
  bool readBool() {
    return readByte() != 0;
  }
  std::string readCString() {
    std::string value;
    while (true) {
      char c = readByte();
      if (c == 0) break;
      value += c;
    }
    return value;
  }
};

#define TRY_WRITE(type)