
#include <string>
#include <vector>
#include <optional>
#include "stream.h"
#define DBG_PRINT printf
#define WRITE_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: write FAIL\n", __func__, __LINE__, #fn); return false; }; DBG_PRINT("%s:%d: %s: written, stream now at %d\n", __func__, __LINE__, #fn, stream.writeIndex);
#define READ_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: read FAIL\n", __func__, __LINE__, #fn); return false; } DBG_PRINT("%s:%d: %s: read, stream now at %d\n", __func__, __LINE__, #fn, stream.readIndex);
#define EXPECT_OR_BAIL(val) if (!val) { DBG_PRINT("%s:%d: bad assert %s\n", __func__, __LINE__, #val); return false; }
namespace pdef::pc1_18_handshaking_toServer {

struct slot;
struct particle;
struct Data14;
struct Data15;
struct Data35;
struct Data36;
struct Data2Or3Or24;
struct minecraft_smelting_format;
struct tags;
struct chunkBlockEntity;
struct command_node;
struct ExtraNodeData1;
struct ExtraNodeData2;
struct PropertiesBrigadierFloat;
struct PropertiesBrigadierDouble;
struct PropertiesBrigadierInteger;
struct PropertiesBrigadierLong;
struct PropertiesMinecraftRange;
struct PropertiesMinecraftResourceOrTagOrMinecraftResource;
struct packet_set_protocol;
struct packet_legacy_server_list_ping;
struct packet;
// varint is built in
// varlong is built in
// pstring is built in
// buffer is built in
// u8 is built in
// u16 is built in
// u32 is built in
// u64 is built in
// i8 is built in
// i16 is built in
// i32 is built in
// i64 is built in
// bool is built in
// f32 is built in
// f64 is built in
// UUID is built in
// option is built in
// entityMetadataLoop is built in
// topBitSetTerminatedArray is built in
// bitfield is built in
// container is built in
// switch is built in
// void is built in
// array is built in
// restBuffer is built in
// nbt is built in
// optionalNbt is built in
  struct slot {
    bool present; /*0.0*/
    int itemId; /*0.0*/
    int8_t itemCount; /*0.0*/
    int8_t nbtData; /*0.0*/
  };
  struct particle {
    int particleId; /*0.0*/
    struct Data14 {
      float red; /*0.0*/
      float green; /*0.0*/
      float blue; /*0.0*/
      float scale; /*0.0*/
    };
    std::optional<Data14> data_14; /*3.2*/
    struct Data15 {
      float fromRed; /*0.0*/
      float fromGreen; /*0.0*/
      float fromBlue; /*0.0*/
      float scale; /*0.0*/
      float toRed; /*0.0*/
      float toGreen; /*0.0*/
      float toBlue; /*0.0*/
    };
    std::optional<Data15> data_15; /*3.2*/
    struct Data35 {
      int8_t item; /*0.0*/
    };
    std::optional<Data35> data_35; /*3.2*/
    struct Data36 {
      struct { /*6.0*/
        int x = 0; /*6.0*/
        int z = 0; /*6.0*/
        int y = 0; /*6.0*/
      } origin; /*6.0*/
      std::string positionType; /*6.0*/
      int ticks; /*0.0*/
      struct { /*6.0*/
        int x = 0; /*6.0*/
        int z = 0; /*6.0*/
        int y = 0; /*6.0*/
      } destination_position; /*6.0*/
      int destination_varint; /*0.0*/
    };
    std::optional<Data36> data_36; /*3.2*/
    struct Data2Or3Or24 {
      int blockState; /*0.0*/
    };
    std::optional<Data2Or3Or24> data_2_or_3_or_24; /*3.2*/
  };
  struct minecraft_smelting_format {
    std::string group; /*6.0*/
    std::vector<int8_t /*0.0*/> ingredient; /*3.0*/
    int8_t result; /*0.0*/
    float experience; /*0.0*/
    int cookTime; /*0.0*/
  };
  struct tags {
    std::string tagName; /*6.0*/
    std::vector<int /*0.0*/> entries; /*3.0*/
  };
  struct chunkBlockEntity {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
    } _3; /*6.0*/
    int16_t y; /*0.0*/
    int type; /*0.0*/
    int8_t nbtData; /*0.0*/
  };
  struct command_node {
    struct { /*6.0*/
      int unused = 0; /*6.0*/
      int has_custom_suggestions = 0; /*6.0*/
      int has_redirect_node = 0; /*6.0*/
      int has_command = 0; /*6.0*/
      int command_node_type = 0; /*6.0*/
    } flags; /*6.0*/
    std::vector<int /*0.0*/> children; /*3.0*/
    struct ExtraNodeData1 {
      std::string name; /*6.0*/
    };
    std::optional<ExtraNodeData1> extraNodeData_1; /*3.2*/
    struct ExtraNodeData2 {
      std::string name; /*6.0*/
      std::string parser; /*6.0*/
      struct PropertiesBrigadierFloat {
        struct { /*6.0*/
          int unused = 0; /*6.0*/
          int max_present = 0; /*6.0*/
          int min_present = 0; /*6.0*/
        } flags; /*6.0*/
        float min; /*0.0*/
        float max; /*0.0*/
      };
      std::optional<PropertiesBrigadierFloat> properties_brigadier_float; /*3.2*/
      struct PropertiesBrigadierDouble {
        struct { /*6.0*/
          int unused = 0; /*6.0*/
          int max_present = 0; /*6.0*/
          int min_present = 0; /*6.0*/
        } flags; /*6.0*/
        double min; /*0.0*/
        double max; /*0.0*/
      };
      std::optional<PropertiesBrigadierDouble> properties_brigadier_double; /*3.2*/
      struct PropertiesBrigadierInteger {
        struct { /*6.0*/
          int unused = 0; /*6.0*/
          int max_present = 0; /*6.0*/
          int min_present = 0; /*6.0*/
        } flags; /*6.0*/
        int32_t min; /*0.0*/
        int32_t max; /*0.0*/
      };
      std::optional<PropertiesBrigadierInteger> properties_brigadier_integer; /*3.2*/
      struct PropertiesBrigadierLong {
        struct { /*6.0*/
          int unused = 0; /*6.0*/
          int max_present = 0; /*6.0*/
          int min_present = 0; /*6.0*/
        } flags; /*6.0*/
        int64_t min; /*0.0*/
        int64_t max; /*0.0*/
      };
      std::optional<PropertiesBrigadierLong> properties_brigadier_long; /*3.2*/
      enum class PropertiesMapper : int {
        SINGLE_WORD = 0,
        QUOTABLE_PHRASE = 1,
        GREEDY_PHRASE = 2,
      };
      PropertiesMapper properties_mapper; /*3.2*/
      struct { /*6.0*/
        int unused = 0; /*6.0*/
        int onlyAllowPlayers = 0; /*6.0*/
        int onlyAllowEntities = 0; /*6.0*/
      } properties_minecraft_entity; /*6.0*/
      struct { /*6.0*/
        int unused = 0; /*6.0*/
        int allowMultiple = 0; /*6.0*/
      } properties_minecraft_score_holder; /*6.0*/
      struct PropertiesMinecraftRange {
        bool allowDecimals; /*0.0*/
      };
      std::optional<PropertiesMinecraftRange> properties_minecraft_range; /*3.2*/
      struct PropertiesMinecraftResourceOrTagOrMinecraftResource {
        std::string registry; /*6.0*/
      };
      std::optional<PropertiesMinecraftResourceOrTagOrMinecraftResource> properties_minecraft_resource_or_tag_or_minecraft_resource; /*3.2*/
      std::string suggestionType; /*6.0*/
    };
    std::optional<ExtraNodeData2> extraNodeData_2; /*3.2*/
    int redirectNode; /*0.0*/
  };
  struct packet_set_protocol {
    int protocolVersion; /*0.0*/
    std::string serverHost; /*6.0*/
    uint16_t serverPort; /*0.0*/
    int nextState; /*0.0*/
  };
  struct packet_legacy_server_list_ping {
    uint8_t payload; /*0.0*/
  };
  struct packet {
    enum class Name : int {
      SetProtocol = 0x00,
      LegacyServerListPing = 0xfe,
    };
    Name name; /*3.2*/
    std::optional<pdef::pc1_18_handshaking_toServer::packet_set_protocol> params_packet_set_protocol; /*4.0*/
    std::optional<pdef::pc1_18_handshaking_toServer::packet_legacy_server_list_ping> params_packet_legacy_server_list_ping; /*4.0*/
  };
}

namespace pdef::pc1_18_handshaking_toServer::size {
size_t slot(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::slot &obj);
size_t particle(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::particle &obj);
size_t minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::minecraft_smelting_format &obj);
size_t tags(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::tags &obj);
size_t chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::chunkBlockEntity &obj);
size_t command_node(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::command_node &obj);
size_t packet_set_protocol(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_set_protocol &obj);
size_t packet_legacy_server_list_ping(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_legacy_server_list_ping &obj);
size_t packet(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet &obj);
  size_t slot(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::slot &obj) {
    size_t len = 0;
    const bool &present = obj.present; /*0.1*/
    if (present == false) { /*8.1*/
    }
    else if (present == true) { /*8.1*/
        len += stream.sizeOfVarInt(obj.itemId); /*0.2*/
        len += 1; /*0.2*/
        len += 1; /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t particle(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::particle &obj) {
    size_t len = 0;
    const int &particleId = obj.particleId; /*0.1*/
    if (particleId == 2) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 3) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 14) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_14); const pdef::pc1_18_handshaking_toServer::particle::Data14 &v = *obj.data_14; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 15) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_15); const pdef::pc1_18_handshaking_toServer::particle::Data15 &v = *obj.data_15; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 24) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 35) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_35); const pdef::pc1_18_handshaking_toServer::particle::Data35 &v = *obj.data_35; /*8.6*/
        len += 1; /*0.2*/
    }
    else if (particleId == 36) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_36); const pdef::pc1_18_handshaking_toServer::particle::Data36 &v = *obj.data_36; /*8.6*/
        len += 1; /*origin: bitfield*/ /*4.1*/
        len += stream.sizeOfVarInt(v.positionType.length());
        len += v.positionType.length(); /*positionType^: pstring*/ /*4.1*/
        const pdef::pc1_18_handshaking_toServer::particle::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_handshaking_toServer::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          len += 1; /*destination: bitfield*/ /*4.1*/
        }
        else if (positionType == pdef::pc1_18_handshaking_toServer::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          len += stream.sizeOfVarInt(v.destination_varint); /*0.2*/
        }
        len += stream.sizeOfVarInt(v.ticks); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::minecraft_smelting_format &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.group.length());
    len += obj.group.length(); /*group: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.ingredient.size()); /*1.3*/
    for (const auto &v2 : obj.ingredient) {
      len += 1; /*0.2*/
    }
    len += 1; /*0.2*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.cookTime); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t tags(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::tags &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.tagName.length());
    len += obj.tagName.length(); /*tagName: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.entries.size()); /*1.3*/
    for (const auto &v2 : obj.entries) {
      len += stream.sizeOfVarInt(v2); /*0.2*/
    }
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::chunkBlockEntity &obj) {
    size_t len = 0;
    len += 1; /*_3: bitfield*/ /*4.1*/
    len += 2; /*0.2*/
    len += stream.sizeOfVarInt(obj.type); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t command_node(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::command_node &obj) {
    size_t len = 0;
    len += 1; /*flags^: bitfield*/ /*4.1*/
    const pdef::pc1_18_handshaking_toServer::command_node::bitfield &flags = obj.flags; /*0.1*/
    len += stream.sizeOfVarInt(obj.children.size()); /*1.3*/
    for (const auto &v2 : obj.children) {
      len += stream.sizeOfVarInt(v2); /*0.2*/
    }
    if (flags.has_redirect_node == 1) { /*8.2*/
      len += stream.sizeOfVarInt(obj.redirectNode); /*0.2*/
    }
    if (flags.command_node_type == 0) { /*8.2*/
    }
    else if (flags.command_node_type == 1) { /*8.2*/
        EXPECT_OR_BAIL(obj.extraNodeData_1); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.6*/
        len += stream.sizeOfVarInt(v.name.length());
        len += v.name.length(); /*name: pstring*/ /*4.1*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
        EXPECT_OR_BAIL(obj.extraNodeData_2); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.6*/
        len += stream.sizeOfVarInt(v.name.length());
        len += v.name.length(); /*name: pstring*/ /*4.1*/
        len += stream.sizeOfVarInt(v.parser.length());
        len += v.parser.length(); /*parser^: pstring*/ /*4.1*/
        const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.1*/
        if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_float); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_double); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_integer); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_long); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          len += 1; /*properties: bitfield*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          len += 1; /*properties: bitfield*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_range); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.6*/
            len += 1; /*0.2*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_resource_or_tag_or_minecraft_resource); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.6*/
            len += stream.sizeOfVarInt(v.registry.length());
            len += v.registry.length(); /*registry: pstring*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_resource_or_tag_or_minecraft_resource); const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.6*/
            len += stream.sizeOfVarInt(v.registry.length());
            len += v.registry.length(); /*registry: pstring*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          len += stream.sizeOfVarInt(v.suggestionType.length());
          len += v.suggestionType.length(); /*suggestionType: pstring*/ /*4.1*/
        }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_protocol(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_set_protocol &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.protocolVersion); /*0.2*/
    len += stream.sizeOfVarInt(obj.serverHost.length());
    len += obj.serverHost.length(); /*serverHost: pstring*/ /*4.1*/
    len += 2; /*0.2*/
    len += stream.sizeOfVarInt(obj.nextState); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_legacy_server_list_ping(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_legacy_server_list_ping &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet &obj) {
    size_t len = 0;
    const pdef::pc1_18_handshaking_toServer::packet::Name &name = obj.name; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.name); /*name^: varint*/ /*7.0*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_handshaking_toServer::packet::Name::SetProtocol: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_protocol); size_t len_0 = pdef::pc1_18_handshaking_toServer::size::packet_set_protocol(stream, *obj.params_packet_set_protocol); EXPECT_OR_BAIL(len_0); len += len_0; /*params_packet_set_protocol*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_handshaking_toServer::packet::Name::LegacyServerListPing: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_legacy_server_list_ping); size_t len_1 = pdef::pc1_18_handshaking_toServer::size::packet_legacy_server_list_ping(stream, *obj.params_packet_legacy_server_list_ping); EXPECT_OR_BAIL(len_1); len += len_1; /*params_packet_legacy_server_list_ping*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
}

namespace pdef::pc1_18_handshaking_toServer::encode {
bool slot(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::slot &obj, bool allocate);
bool particle(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::particle &obj, bool allocate);
bool minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::minecraft_smelting_format &obj, bool allocate);
bool tags(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::tags &obj, bool allocate);
bool chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::chunkBlockEntity &obj, bool allocate);
bool command_node(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::command_node &obj, bool allocate);
bool packet_set_protocol(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_set_protocol &obj, bool allocate);
bool packet_legacy_server_list_ping(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_legacy_server_list_ping &obj, bool allocate);
bool packet(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet &obj, bool allocate);
  bool slot(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const bool &present = obj.present; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.present); /*0.4*/
    if (present == false) { /*8.1*/
    }
    else if (present == true) { /*8.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.itemId); /*0.4*/
        WRITE_OR_BAIL(writeByte, (int8_t)obj.itemCount); /*0.4*/
        WRITE_OR_BAIL(writeByte, (int8_t)obj.nbtData); /*0.4*/
    }
    return true;
  }
  bool particle(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::particle &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::particle(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &particleId = obj.particleId; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.particleId); /*0.4*/
    if (particleId == 2) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 3) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 14) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data14 &v = *obj.data_14; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.red); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.green); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.blue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
    }
    else if (particleId == 15) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data15 &v = *obj.data_15; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromBlue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toBlue); /*0.4*/
    }
    else if (particleId == 24) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 35) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data35 &v = *obj.data_35; /*8.5*/
        WRITE_OR_BAIL(writeByte, (int8_t)v.item); /*0.4*/
    }
    else if (particleId == 36) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data36 &v = *obj.data_36; /*8.5*/
        uint8_t origin_val = 0;
        origin_val |= v.origin.x << 0;
        origin_val |= v.origin.z << 26;
        origin_val |= v.origin.y << 52;
        WRITE_OR_BAIL(writeUByte, origin_val); /*origin: bitfield*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.positionType.length());
        WRITE_OR_BAIL(writeString, v.positionType); /*positionType: pstring*/ /*4.2*/
        const pdef::pc1_18_handshaking_toServer::particle::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_handshaking_toServer::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val = 0;
          destination_position_val |= v.destination_position.x << 0;
          destination_position_val |= v.destination_position.z << 26;
          destination_position_val |= v.destination_position.y << 52;
          WRITE_OR_BAIL(writeUByte, destination_position_val); /*destination_position: bitfield*/ /*4.2*/
        }
        else if (positionType == pdef::pc1_18_handshaking_toServer::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.destination_varint); /*0.4*/
        }
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.ticks); /*0.4*/
    }
    return true;
  }
  bool minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::minecraft_smelting_format &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::minecraft_smelting_format(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.group.length());
    WRITE_OR_BAIL(writeString, obj.group); /*group: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.ingredient.size()); /*1.4*/
    for (const auto &v2 : obj.ingredient) { /*3.1*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.result); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.experience); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.cookTime); /*0.4*/
    return true;
  }
bool tags(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::tags &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::tags(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.tagName.length());
    WRITE_OR_BAIL(writeString, obj.tagName); /*tagName: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entries.size()); /*1.4*/
    for (const auto &v2 : obj.entries) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2); /*0.4*/
    }
  return true;
}
  bool chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::chunkBlockEntity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::chunkBlockEntity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t _3_val = 0;
    _3_val |= obj._3.x << 0;
    _3_val |= obj._3.z << 4;
    WRITE_OR_BAIL(writeUByte, _3_val); /*_3: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbtData); /*0.4*/
    return true;
  }
  bool command_node(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::command_node &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::command_node(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t flags_val = 0;
    flags_val |= obj.flags.unused << 0;
    flags_val |= obj.flags.has_custom_suggestions << 3;
    flags_val |= obj.flags.has_redirect_node << 4;
    flags_val |= obj.flags.has_command << 5;
    flags_val |= obj.flags.command_node_type << 6;
    WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
    const pdef::pc1_18_handshaking_toServer::command_node::bitfield &flags = obj.flags; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.children.size()); /*1.4*/
    for (const auto &v2 : obj.children) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2); /*0.4*/
    }
    if (flags.has_redirect_node == 1) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.redirectNode); /*0.4*/
    }
    if (flags.command_node_type == 0) { /*8.2*/
    }
    else if (flags.command_node_type == 1) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.name.length());
        WRITE_OR_BAIL(writeString, v.name); /*name: pstring*/ /*4.2*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
        const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.name.length());
        WRITE_OR_BAIL(writeString, v.name); /*name: pstring*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.parser.length());
        WRITE_OR_BAIL(writeString, v.parser); /*parser: pstring*/ /*4.2*/
        const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.1*/
        if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeFloatBE, (float)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeFloatBE, (float)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeDoubleBE, (double)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeDoubleBE, (double)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeIntBE, (int32_t)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeIntBE, (int32_t)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeLongBE, (int64_t)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeLongBE, (int64_t)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          uint8_t properties_minecraft_entity_val = 0;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.unused << 0;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.onlyAllowPlayers << 6;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.onlyAllowEntities << 7;
          WRITE_OR_BAIL(writeUByte, properties_minecraft_entity_val); /*properties_minecraft_entity: bitfield*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          uint8_t properties_minecraft_score_holder_val = 0;
          properties_minecraft_score_holder_val |= v.properties_minecraft_score_holder.unused << 0;
          properties_minecraft_score_holder_val |= v.properties_minecraft_score_holder.allowMultiple << 7;
          WRITE_OR_BAIL(writeUByte, properties_minecraft_score_holder_val); /*properties_minecraft_score_holder: bitfield*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.5*/
            WRITE_OR_BAIL(writeBool, (bool)v.allowDecimals); /*0.4*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.registry.length());
            WRITE_OR_BAIL(writeString, v.registry); /*registry: pstring*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
            const pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.registry.length());
            WRITE_OR_BAIL(writeString, v.registry); /*registry: pstring*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.suggestionType.length());
          WRITE_OR_BAIL(writeString, v.suggestionType); /*suggestionType: pstring*/ /*4.2*/
        }
    }
    return true;
  }
  bool packet_set_protocol(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_set_protocol &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::packet_set_protocol(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.protocolVersion); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.serverHost.length());
    WRITE_OR_BAIL(writeString, obj.serverHost); /*serverHost: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUShortBE, (uint16_t)obj.serverPort); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.nextState); /*0.4*/
    return true;
  }
  bool packet_legacy_server_list_ping(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet_legacy_server_list_ping &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::packet_legacy_server_list_ping(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.payload); /*0.4*/
    return true;
  }
  bool packet(pdef::Stream &stream, const pdef::pc1_18_handshaking_toServer::packet &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_handshaking_toServer::size::packet(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::pc1_18_handshaking_toServer::packet::Name &name = obj.name; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.name); /*7.1*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_handshaking_toServer::packet::Name::SetProtocol: { /*8.5*/
        pdef::pc1_18_handshaking_toServer::encode::packet_set_protocol(stream, *obj.params_packet_set_protocol); /*packet_set_protocol*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_handshaking_toServer::packet::Name::LegacyServerListPing: { /*8.5*/
        pdef::pc1_18_handshaking_toServer::encode::packet_legacy_server_list_ping(stream, *obj.params_packet_legacy_server_list_ping); /*packet_legacy_server_list_ping*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

namespace pdef::pc1_18_handshaking_toServer::decode {
bool slot(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::slot &obj);
bool particle(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::particle &obj);
bool minecraft_smelting_format(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::minecraft_smelting_format &obj);
bool tags(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::tags &obj);
bool chunkBlockEntity(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::chunkBlockEntity &obj);
bool command_node(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::command_node &obj);
bool packet_set_protocol(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::packet_set_protocol &obj);
bool packet_legacy_server_list_ping(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::packet_legacy_server_list_ping &obj);
bool packet(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::packet &obj);
  bool slot(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::slot &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.present); /*0.5*/
    bool &present = obj.present; /*0.6*/
    if (present == false) { /*8.1*/
    }
    else if (present == true) { /*8.1*/
        READ_OR_BAIL(readUnsignedVarInt, obj.itemId); /*0.5*/
        READ_OR_BAIL(readByte, obj.itemCount); /*0.5*/
        READ_OR_BAIL(readByte, obj.nbtData); /*0.5*/
    }
    return true;
  }
  bool particle(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::particle &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.particleId); /*0.5*/
    int &particleId = obj.particleId; /*0.6*/
    if (particleId == 2) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 3) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 14) { /*8.2*/
         obj.data_14 = {}; pdef::pc1_18_handshaking_toServer::particle::Data14 &v = *obj.data_14; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.red); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.green); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.blue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
    }
    else if (particleId == 15) { /*8.2*/
         obj.data_15 = {}; pdef::pc1_18_handshaking_toServer::particle::Data15 &v = *obj.data_15; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.fromRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromBlue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toBlue); /*0.5*/
    }
    else if (particleId == 24) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_handshaking_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 35) { /*8.2*/
         obj.data_35 = {}; pdef::pc1_18_handshaking_toServer::particle::Data35 &v = *obj.data_35; /*8.4*/
        READ_OR_BAIL(readByte, v.item); /*0.5*/
    }
    else if (particleId == 36) { /*8.2*/
         obj.data_36 = {}; pdef::pc1_18_handshaking_toServer::particle::Data36 &v = *obj.data_36; /*8.4*/
        uint8_t origin_val;
        READ_OR_BAIL(readUByte, origin_val);
        v.origin.x = origin_val >> 0 & 26;
        v.origin.z = origin_val >> 26 & 26;
        v.origin.y = origin_val >> 52 & 12; /*origin: bitfield*/ /*4.3*/
        int positionType_strlen; READ_OR_BAIL(readUnsignedVarInt, positionType_strlen);
        if (!stream.readString(v.positionType, positionType_strlen)) return false; /*positionType: pstring*/ /*4.3*/
        pdef::pc1_18_handshaking_toServer::particle::Data36::pstring &positionType = v.positionType; /*0.7*/
        if (positionType == pdef::pc1_18_handshaking_toServer::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val;
          READ_OR_BAIL(readUByte, destination_position_val);
          v.destination_position.x = destination_position_val >> 0 & 26;
          v.destination_position.z = destination_position_val >> 26 & 26;
          v.destination_position.y = destination_position_val >> 52 & 12; /*destination_position: bitfield*/ /*4.3*/
        }
        else if (positionType == pdef::pc1_18_handshaking_toServer::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.destination_varint); /*0.5*/
        }
        READ_OR_BAIL(readUnsignedVarInt, v.ticks); /*0.5*/
    }
    return true;
  }
  bool minecraft_smelting_format(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::minecraft_smelting_format &obj) {
    int group_strlen; READ_OR_BAIL(readUnsignedVarInt, group_strlen);
    if (!stream.readString(obj.group, group_strlen)) return false; /*group: pstring*/ /*4.3*/
    int ingredient_len; READ_OR_BAIL(readUnsignedVarInt, ingredient_len); /*1.5*/
    obj.ingredient.resize(ingredient_len); /*1.6*/
    for (int i = 0; i < ingredient_len; i++) {
      auto &v2 = obj.ingredient[i]; /*3.4*/
      READ_OR_BAIL(readByte, v2); /*0.5*/
    }
    READ_OR_BAIL(readByte, obj.result); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.experience); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.cookTime); /*0.5*/
    return true;
  }
bool tags(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::tags &obj) {
    int tagName_strlen; READ_OR_BAIL(readUnsignedVarInt, tagName_strlen);
    if (!stream.readString(obj.tagName, tagName_strlen)) return false; /*tagName: pstring*/ /*4.3*/
    int entries_len; READ_OR_BAIL(readUnsignedVarInt, entries_len); /*1.5*/
    obj.entries.resize(entries_len); /*1.6*/
    for (int i = 0; i < entries_len; i++) {
      auto &v2 = obj.entries[i]; /*3.4*/
      READ_OR_BAIL(readUnsignedVarInt, v2); /*0.5*/
    }
  return true;
}
  bool chunkBlockEntity(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::chunkBlockEntity &obj) {
    uint8_t _3_val;
    READ_OR_BAIL(readUByte, _3_val);
    obj._3.x = _3_val >> 0 & 4;
    obj._3.z = _3_val >> 4 & 4; /*_3: bitfield*/ /*4.3*/
    READ_OR_BAIL(readShortBE, obj.y); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbtData); /*0.5*/
    return true;
  }
  bool command_node(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::command_node &obj) {
    uint8_t flags_val;
    READ_OR_BAIL(readUByte, flags_val);
    obj.flags.unused = flags_val >> 0 & 3;
    obj.flags.has_custom_suggestions = flags_val >> 3 & 1;
    obj.flags.has_redirect_node = flags_val >> 4 & 1;
    obj.flags.has_command = flags_val >> 5 & 1;
    obj.flags.command_node_type = flags_val >> 6 & 2; /*flags: bitfield*/ /*4.3*/
    pdef::pc1_18_handshaking_toServer::command_node::bitfield &flags = obj.flags; /*0.7*/
    int children_len; READ_OR_BAIL(readUnsignedVarInt, children_len); /*1.5*/
    obj.children.resize(children_len); /*1.6*/
    for (int i = 0; i < children_len; i++) {
      auto &v2 = obj.children[i]; /*3.4*/
      READ_OR_BAIL(readUnsignedVarInt, v2); /*0.5*/
    }
    if (flags.has_redirect_node == 1) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.redirectNode); /*0.5*/
    }
    if (flags.command_node_type == 0) { /*8.2*/
    }
    else if (flags.command_node_type == 1) { /*8.2*/
         obj.extraNodeData_1 = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.4*/
        int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
        if (!stream.readString(v.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
         obj.extraNodeData_2 = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.4*/
        int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
        if (!stream.readString(v.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
        int parser_strlen; READ_OR_BAIL(readUnsignedVarInt, parser_strlen);
        if (!stream.readString(v.parser, parser_strlen)) return false; /*parser: pstring*/ /*4.3*/
        pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.7*/
        if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
             v.properties_brigadier_float = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readFloatBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readFloatBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
             v.properties_brigadier_double = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readDoubleBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readDoubleBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
             v.properties_brigadier_integer = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readIntBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readIntBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
             v.properties_brigadier_long = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readLongBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readLongBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          uint8_t properties_minecraft_entity_val;
          READ_OR_BAIL(readUByte, properties_minecraft_entity_val);
          v.properties_minecraft_entity.unused = properties_minecraft_entity_val >> 0 & 6;
          v.properties_minecraft_entity.onlyAllowPlayers = properties_minecraft_entity_val >> 6 & 1;
          v.properties_minecraft_entity.onlyAllowEntities = properties_minecraft_entity_val >> 7 & 1; /*properties_minecraft_entity: bitfield*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          uint8_t properties_minecraft_score_holder_val;
          READ_OR_BAIL(readUByte, properties_minecraft_score_holder_val);
          v.properties_minecraft_score_holder.unused = properties_minecraft_score_holder_val >> 0 & 7;
          v.properties_minecraft_score_holder.allowMultiple = properties_minecraft_score_holder_val >> 7 & 1; /*properties_minecraft_score_holder: bitfield*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
             v.properties_minecraft_range = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.4*/
            READ_OR_BAIL(readBool, (bool&)v.allowDecimals); /*0.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
             v.properties_minecraft_resource_or_tag_or_minecraft_resource = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.4*/
            int registry_strlen; READ_OR_BAIL(readUnsignedVarInt, registry_strlen);
            if (!stream.readString(v.registry, registry_strlen)) return false; /*registry: pstring*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
             v.properties_minecraft_resource_or_tag_or_minecraft_resource = {}; pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.4*/
            int registry_strlen; READ_OR_BAIL(readUnsignedVarInt, registry_strlen);
            if (!stream.readString(v.registry, registry_strlen)) return false; /*registry: pstring*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_handshaking_toServer::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          int suggestionType_strlen; READ_OR_BAIL(readUnsignedVarInt, suggestionType_strlen);
          if (!stream.readString(v.suggestionType, suggestionType_strlen)) return false; /*suggestionType: pstring*/ /*4.3*/
        }
    }
    return true;
  }
  bool packet_set_protocol(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::packet_set_protocol &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.protocolVersion); /*0.5*/
    int serverHost_strlen; READ_OR_BAIL(readUnsignedVarInt, serverHost_strlen);
    if (!stream.readString(obj.serverHost, serverHost_strlen)) return false; /*serverHost: pstring*/ /*4.3*/
    READ_OR_BAIL(readUShortBE, obj.serverPort); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.nextState); /*0.5*/
    return true;
  }
  bool packet_legacy_server_list_ping(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::packet_legacy_server_list_ping &obj) {
    READ_OR_BAIL(readUByte, obj.payload); /*0.5*/
    return true;
  }
  bool packet(pdef::Stream &stream, pdef::pc1_18_handshaking_toServer::packet &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.name); /*7.2*/
    const pdef::pc1_18_handshaking_toServer::packet::Name &name = obj.name; /*0.7*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_handshaking_toServer::packet::Name::SetProtocol: { /*8.5*/
        obj.params_packet_set_protocol = {}; pdef::pc1_18_handshaking_toServer::decode::packet_set_protocol(stream, *obj.params_packet_set_protocol); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_handshaking_toServer::packet::Name::LegacyServerListPing: { /*8.5*/
        obj.params_packet_legacy_server_list_ping = {}; pdef::pc1_18_handshaking_toServer::decode::packet_legacy_server_list_ping(stream, *obj.params_packet_legacy_server_list_ping); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

#undef WRITE_OR_BAIL
#undef READ_OR_BAIL
