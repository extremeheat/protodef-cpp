#include "./build/protocol.h"

int main () {
  pdef::proto::packet_available_commands commands_packet {
    .values_len = 0,
    // ._enum_type = pdef::proto::packet_available_commands::_EnumType::Byte,
    .enum_values = {},
    .suffixes = {},
    .enums = {},
    .command_data = {},
    .dynamic_enums = {},
    .enum_constraints = {},
  };
  pdef::Stream stream(0);
  auto encoded = pdef::proto::encode::packet_available_commands(stream, commands_packet);
  if (!encoded) printf("Failed to encode packet\n");
  stream.dumpToStdout();
  if (!pdef::proto::decode::packet_available_commands(stream, commands_packet)) {
    printf("Failed to decode packet\n");
  }

  printf("Text Packet\n");

  pdef::proto::packet_text textPacket {
    .type = pdef::proto::packet_text::Type::Chat,
    .needs_translation = false,
    .xuid = "",
    .platform_chat_id = "",
    .source_name = "test",
    .message = "Hello world",
    .parameters = {}
  };
  pdef::Stream stream2(0);
  auto encoded2 = pdef::proto::encode::packet_text(stream2, textPacket);
  if (!encoded2) printf("Failed to encode packet\n");
  stream2.dumpToStdout();
  if (!pdef::proto::decode::packet_text(stream2, textPacket)) {
    printf("Failed to decode packet\n");
  }

  printf("Set Score Packet\n");
  pdef::proto::packet_set_score setScorePacket {
    .action = pdef::proto::packet_set_score::Action::Change,
    .entries = {
      {
        .scoreboard_id = 1,
        .objective_name = "test",
        .score = 0,
        .entry_type = pdef::proto::packet_set_score::Entries::EntryType::Player,
        .entity_unique_id = 0,
        .custom_name = "test",
      }
    }
  };
  pdef::Stream stream3(0);
  auto encoded3 = pdef::proto::encode::packet_set_score(stream3, setScorePacket);
  if (!encoded3) printf("Failed to encode packet\n");
  stream3.dumpToStdout();
  if (!pdef::proto::decode::packet_set_score(stream3, setScorePacket)) {
    printf("Failed to decode packet\n");
  }

  printf("MCPE packet\n");

  pdef::proto::packet_disconnect disconnectPacket {
    .hide_disconnect_reason = false,
    .message = "test",
  };

  pdef::proto::mcpe_packet mcpe_packet {
    .name = pdef::proto::mcpe_packet::Name::Disconnect,
    .params_packet_disconnect = disconnectPacket
  };
  pdef::Stream stream4(0);
  auto encoded4 = pdef::proto::encode::mcpe_packet(stream4, mcpe_packet);
  if (!encoded4) printf("Failed to encode packet\n");
  stream4.dumpToStdout();
  if (!pdef::proto::decode::mcpe_packet(stream4, mcpe_packet)) {
    printf("Failed to decode packet\n");
  }

  return 0;
}