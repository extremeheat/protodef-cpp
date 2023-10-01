#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include "./build/protocol.h"

int main () {
  printf("Hello world\n");
  // Boilerplate to read bigtest.nbt into 'buffer', size into 'size'
  FILE *fp = fopen("bigtest.nbt", "rb");
  if (!fp) {
    printf("Failed to open bigtest.nbt\n"); return 1;
  }
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *buffer = (char *)malloc(size);
  fread(buffer, size, 1, fp);
  fclose(fp);

  // Decode bigtest.nbt
  pdef::Stream stream(buffer, size);
  printf("Decoding bigtest.nbt (%lld bytes)\n", size);
  
  pdef::proto::nbt nbt;
  if (pdef::proto::decode::nbt(stream, nbt)) {
    printf("Decoded bigtest.nbt\n");
  } else {
    printf("Failed to decode bigtest.nbt\n");
    return 1;
  }
  
  // Now let's dump the JSON
  pdef::Stream jsonStream(1024 * 1024);
  printf("Dumping JSON\n");
  if (pdef::proto::toJSON::nbt(jsonStream, nbt)) {
    printf("Dumping %d bytes of JSON\n", jsonStream.writeIndex);
  } else {
    printf("Failed to dump JSON\n");
    return 1;
  }
  jsonStream.dumpWrittenStringToStdout();
  return 0;
}