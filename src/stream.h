#pragma once
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
  int sizeOfByte(int8_t value) { return 1; }
  int sizeOfUShort(uint16_t value) { return 2; }
  int sizeOfUInt(uint32_t value) { return 4; }
  int sizeOfULong(uint64_t value) { return 8; }
  int sizeOfShort(int16_t value) { return 2; }
  int sizeOfInt(int32_t value) { return 4; }
  int sizeOfLong(int64_t value) { return 8; }
  int sizeOfFloat(float value) { return 4; }
  int sizeOfDouble(double value) { return 8; }
  int sizeOfUShortLE(uint16_t value) { return 2; }
  int sizeOfUIntLE(uint32_t value) { return 4; }
  int sizeOfULongLE(uint64_t value) { return 8; }
  int sizeOfShortLE(int16_t value) { return 2; }
  int sizeOfIntLE(int32_t value) { return 4; }
  int sizeOfLongLE(int64_t value) { return 8; }
  int sizeOfFloatLE(float value) { return 4; }
  int sizeOfDoubleLE(double value) { return 8; }
  int sizeOfBool(bool value) { return 1; }
  int sizeOfVarIntPrefixedString(std::string value) { return sizeOfVarInt(value.length()) + value.length(); }

  bool writeByte(int8_t value) {
    if (writeIndex >= length) return false;
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeUShortBE(uint16_t value) {
    if (writeIndex + 2 > length) return false;
    buffer[writeIndex++] = value >> 8;
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeUIntBE(uint32_t value) {
    if (writeIndex + 4 > length) return false;
    buffer[writeIndex++] = value >> 24;
    buffer[writeIndex++] = value >> 16;
    buffer[writeIndex++] = value >> 8;
    buffer[writeIndex++] = value;
    return true;
  }
  bool writeULongBE(uint64_t value) {
    if (writeIndex + 8 > length) return false;
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
    if (writeIndex + 2 > length) return false;
    memcpy(buffer + writeIndex, &value, 2);
    return true;
  }
  bool writeUIntLE(uint32_t value) {
    if (writeIndex + 4 > length) return false;
    memcpy(buffer + writeIndex, &value, 4);
    return true;
  }
  bool writeULongLE(uint64_t value) {
    if (writeIndex + 8 > length) return false;
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
  bool writeCString(std::string value) {
    if (writeIndex + value.length() + 1 > length) return false;
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length();
    buffer[writeIndex++] = 0;
    return true;
  }
  bool writeIntPrefixedString(std::string value) {
    if (writeIndex + value.length() + 4 > length) return false;
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length() + 4;
    return true;
  }
  bool writeUnsignedVarIntPrefixedString(std::string value) {
    if (writeIndex + value.length() + 5 > length) return false;
    int wroteLength = writeUnsignedVarInt(value.length());
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length();
    return wroteLength;
  }
  bool writeZigZagVarIntPrefixedString(std::string value) {
    if (writeIndex + value.length() + 5 > length) return false;
    writeZigZagVarInt(value.length());
    memcpy(buffer + writeIndex, value.c_str(), value.length());
    writeIndex += value.length();
    return true;
  }
  bool writeBuffer(BinaryStream value) {
    if (writeIndex + value.length > length) return false;
    memcpy(buffer + writeIndex, value.buffer, value.length);
    writeIndex += value.length;
    return true;
  }
  int writeUnsignedVarInt(uint32_t value) {
    if (writeIndex + 5 > length) return -1;
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
    if (writeIndex + 10 > length) return -1;
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
    uint64_t value = buffer[readIndex++] << 56;
    value |= buffer[readIndex++] << 48;
    value |= buffer[readIndex++] << 40;
    value |= buffer[readIndex++] << 32;
    value |= buffer[readIndex++] << 24;
    value |= buffer[readIndex++] << 16;
    value |= buffer[readIndex++] << 8;
    value |= buffer[readIndex++];
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
  }
  uint32_t readUIntLE() {
    uint32_t value;
    memcpy(&value, buffer + readIndex, 4);
    readIndex += 4;
  }
  uint64_t readULongLE() {
    uint64_t value;
    memcpy(&value, buffer + readIndex, 8);
    readIndex += 8;
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
}