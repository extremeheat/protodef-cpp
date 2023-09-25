
#include <string>
#include <vector>
#include <optional>
#include "stream.h"
#define DBG_PRINT printf
#define WRITE_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: write FAIL\n", __func__, __LINE__, #fn); return false; }; DBG_PRINT("%s:%d: %s: written, stream now at %d\n", __func__, __LINE__, #fn, stream.writeIndex);
#define READ_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: read FAIL\n", __func__, __LINE__, #fn); return false; } DBG_PRINT("%s:%d: %s: read, stream now at %d\n", __func__, __LINE__, #fn, stream.readIndex);
#define EXPECT_OR_BAIL(val) if (!val) { DBG_PRINT("%s:%d: bad assert %s\n", __func__, __LINE__, #val); return false; }
namespace pdef::pc1_18_play_toServer {

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
struct packet_teleport_confirm;
struct packet_query_block_nbt;
struct packet_set_difficulty;
struct packet_edit_book;
struct Title;
struct packet_query_entity_nbt;
struct packet_pick_item;
struct packet_name_item;
struct packet_select_trade;
struct packet_set_beacon_effect;
struct packet_update_command_block;
struct packet_update_command_block_minecart;
struct packet_update_structure_block;
struct packet_tab_complete;
struct packet_chat;
struct packet_client_command;
struct packet_settings;
struct packet_enchant_item;
struct packet_window_click;
struct ChangedSlots;
struct packet_close_window;
struct packet_custom_payload;
struct packet_use_entity;
struct packet_generate_structure;
struct packet_keep_alive;
struct packet_lock_difficulty;
struct packet_position;
struct packet_position_look;
struct packet_look;
struct packet_flying;
struct packet_vehicle_move;
struct packet_steer_boat;
struct packet_craft_recipe_request;
struct packet_abilities;
struct packet_block_dig;
struct packet_entity_action;
struct packet_steer_vehicle;
struct packet_displayed_recipe;
struct packet_recipe_book;
struct packet_resource_pack_receive;
struct packet_held_item_slot;
struct packet_set_creative_slot;
struct packet_update_jigsaw_block;
struct packet_update_sign;
struct packet_arm_animation;
struct packet_spectate;
struct packet_block_place;
struct packet_use_item;
struct packet_advancement_tab;
struct packet_pong;
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
  struct packet_teleport_confirm {
    int teleportId; /*0.0*/
  };
  struct packet_query_block_nbt {
    int transactionId; /*0.0*/
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
  };
  struct packet_set_difficulty {
    uint8_t newDifficulty; /*0.0*/
  };
  struct packet_edit_book {
    int hand; /*0.0*/
    std::vector<std::string /*6.0*/> pages; /*3.0*/
    struct Title {
      bool has; /*0.0*/
      std::string value; /*6.0*/
    };
    Title title; /*3.2*/
  };
  struct packet_query_entity_nbt {
    int transactionId; /*0.0*/
    int entityId; /*0.0*/
  };
  struct packet_pick_item {
    int slot; /*0.0*/
  };
  struct packet_name_item {
    std::string name; /*6.0*/
  };
  struct packet_select_trade {
    int slot; /*0.0*/
  };
  struct packet_set_beacon_effect {
    int primary_effect; /*0.0*/
    int secondary_effect; /*0.0*/
  };
  struct packet_update_command_block {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    std::string command; /*6.0*/
    int mode; /*0.0*/
    uint8_t flags; /*0.0*/
  };
  struct packet_update_command_block_minecart {
    int entityId; /*0.0*/
    std::string command; /*6.0*/
    bool track_output; /*0.0*/
  };
  struct packet_update_structure_block {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int action; /*0.0*/
    int mode; /*0.0*/
    std::string name; /*6.0*/
    int8_t offset_x; /*0.0*/
    int8_t offset_y; /*0.0*/
    int8_t offset_z; /*0.0*/
    int8_t size_x; /*0.0*/
    int8_t size_y; /*0.0*/
    int8_t size_z; /*0.0*/
    int mirror; /*0.0*/
    int rotation; /*0.0*/
    std::string metadata; /*6.0*/
    float integrity; /*0.0*/
    int seed; /*0.0*/
    uint8_t flags; /*0.0*/
  };
  struct packet_tab_complete {
    int transactionId; /*0.0*/
    std::string text; /*6.0*/
  };
  struct packet_chat {
    std::string message; /*6.0*/
  };
  struct packet_client_command {
    int actionId; /*0.0*/
  };
  struct packet_settings {
    std::string locale; /*6.0*/
    int8_t viewDistance; /*0.0*/
    int chatFlags; /*0.0*/
    bool chatColors; /*0.0*/
    uint8_t skinParts; /*0.0*/
    int mainHand; /*0.0*/
    bool enableTextFiltering; /*0.0*/
    bool enableServerListing; /*0.0*/
  };
  struct packet_enchant_item {
    int8_t windowId; /*0.0*/
    int8_t enchantment; /*0.0*/
  };
  struct packet_window_click {
    uint8_t windowId; /*0.0*/
    int stateId; /*0.0*/
    int16_t slot; /*0.0*/
    int8_t mouseButton; /*0.0*/
    int mode; /*0.0*/
    struct ChangedSlots {
      int16_t location; /*0.0*/
      int8_t item; /*0.0*/
    };
    std::vector<ChangedSlots /*3.2*/> changedSlots; /*3.0*/
    int8_t cursorItem; /*0.0*/
  };
  struct packet_close_window {
    uint8_t windowId; /*0.0*/
  };
  struct packet_custom_payload {
    std::string channel; /*6.0*/
    int8_t data; /*0.0*/
  };
  struct packet_use_entity {
    int target; /*0.0*/
    int mouse; /*0.0*/
    bool sneaking; /*0.0*/
    float x; /*0.0*/
    float y; /*0.0*/
    float z; /*0.0*/
    int hand; /*0.0*/
  };
  struct packet_generate_structure {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int levels; /*0.0*/
    bool keepJigsaws; /*0.0*/
  };
  struct packet_keep_alive {
    int64_t keepAliveId; /*0.0*/
  };
  struct packet_lock_difficulty {
    bool locked; /*0.0*/
  };
  struct packet_position {
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    bool onGround; /*0.0*/
  };
  struct packet_position_look {
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    float yaw; /*0.0*/
    float pitch; /*0.0*/
    bool onGround; /*0.0*/
  };
  struct packet_look {
    float yaw; /*0.0*/
    float pitch; /*0.0*/
    bool onGround; /*0.0*/
  };
  struct packet_flying {
    bool onGround; /*0.0*/
  };
  struct packet_vehicle_move {
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    float yaw; /*0.0*/
    float pitch; /*0.0*/
  };
  struct packet_steer_boat {
    bool leftPaddle; /*0.0*/
    bool rightPaddle; /*0.0*/
  };
  struct packet_craft_recipe_request {
    int8_t windowId; /*0.0*/
    std::string recipe; /*6.0*/
    bool makeAll; /*0.0*/
  };
  struct packet_abilities {
    int8_t flags; /*0.0*/
  };
  struct packet_block_dig {
    int status; /*0.0*/
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int8_t face; /*0.0*/
  };
  struct packet_entity_action {
    int entityId; /*0.0*/
    int actionId; /*0.0*/
    int jumpBoost; /*0.0*/
  };
  struct packet_steer_vehicle {
    float sideways; /*0.0*/
    float forward; /*0.0*/
    uint8_t jump; /*0.0*/
  };
  struct packet_displayed_recipe {
    std::string recipeId; /*6.0*/
  };
  struct packet_recipe_book {
    int bookId; /*0.0*/
    bool bookOpen; /*0.0*/
    bool filterActive; /*0.0*/
  };
  struct packet_resource_pack_receive {
    int result; /*0.0*/
  };
  struct packet_held_item_slot {
    int16_t slotId; /*0.0*/
  };
  struct packet_set_creative_slot {
    int16_t slot; /*0.0*/
    int8_t item; /*0.0*/
  };
  struct packet_update_jigsaw_block {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    std::string name; /*6.0*/
    std::string target; /*6.0*/
    std::string pool; /*6.0*/
    std::string finalState; /*6.0*/
    std::string jointType; /*6.0*/
  };
  struct packet_update_sign {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    std::string text1; /*6.0*/
    std::string text2; /*6.0*/
    std::string text3; /*6.0*/
    std::string text4; /*6.0*/
  };
  struct packet_arm_animation {
    int hand; /*0.0*/
  };
  struct packet_spectate {
    uint64_t target; /*0.0*/
  };
  struct packet_block_place {
    int hand; /*0.0*/
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int direction; /*0.0*/
    float cursorX; /*0.0*/
    float cursorY; /*0.0*/
    float cursorZ; /*0.0*/
    bool insideBlock; /*0.0*/
  };
  struct packet_use_item {
    int hand; /*0.0*/
  };
  struct packet_advancement_tab {
    int action; /*0.0*/
    std::string tabId; /*6.0*/
  };
  struct packet_pong {
    int32_t id; /*0.0*/
  };
  struct packet {
    enum class Name : int {
      TeleportConfirm = 0x00,
      QueryBlockNbt = 0x01,
      SetDifficulty = 0x02,
      Chat = 0x03,
      ClientCommand = 0x04,
      Settings = 0x05,
      TabComplete = 0x06,
      EnchantItem = 0x07,
      WindowClick = 0x08,
      CloseWindow = 0x09,
      CustomPayload = 0x0a,
      EditBook = 0x0b,
      QueryEntityNbt = 0x0c,
      UseEntity = 0x0d,
      GenerateStructure = 0x0e,
      KeepAlive = 0x0f,
      LockDifficulty = 0x10,
      Position = 0x11,
      PositionLook = 0x12,
      Look = 0x13,
      Flying = 0x14,
      VehicleMove = 0x15,
      SteerBoat = 0x16,
      PickItem = 0x17,
      CraftRecipeRequest = 0x18,
      Abilities = 0x19,
      BlockDig = 0x1a,
      EntityAction = 0x1b,
      SteerVehicle = 0x1c,
      Pong = 0x1d,
      RecipeBook = 0x1e,
      DisplayedRecipe = 0x1f,
      NameItem = 0x20,
      ResourcePackReceive = 0x21,
      AdvancementTab = 0x22,
      SelectTrade = 0x23,
      SetBeaconEffect = 0x24,
      HeldItemSlot = 0x25,
      UpdateCommandBlock = 0x26,
      UpdateCommandBlockMinecart = 0x27,
      SetCreativeSlot = 0x28,
      UpdateJigsawBlock = 0x29,
      UpdateStructureBlock = 0x2a,
      UpdateSign = 0x2b,
      ArmAnimation = 0x2c,
      Spectate = 0x2d,
      BlockPlace = 0x2e,
      UseItem = 0x2f,
    };
    Name name; /*3.2*/
    std::optional<pdef::pc1_18_play_toServer::packet_teleport_confirm> params_packet_teleport_confirm; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_query_block_nbt> params_packet_query_block_nbt; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_set_difficulty> params_packet_set_difficulty; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_edit_book> params_packet_edit_book; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_query_entity_nbt> params_packet_query_entity_nbt; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_pick_item> params_packet_pick_item; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_name_item> params_packet_name_item; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_select_trade> params_packet_select_trade; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_set_beacon_effect> params_packet_set_beacon_effect; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_update_command_block> params_packet_update_command_block; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_update_command_block_minecart> params_packet_update_command_block_minecart; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_update_structure_block> params_packet_update_structure_block; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_tab_complete> params_packet_tab_complete; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_chat> params_packet_chat; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_client_command> params_packet_client_command; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_settings> params_packet_settings; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_enchant_item> params_packet_enchant_item; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_window_click> params_packet_window_click; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_close_window> params_packet_close_window; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_custom_payload> params_packet_custom_payload; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_use_entity> params_packet_use_entity; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_generate_structure> params_packet_generate_structure; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_keep_alive> params_packet_keep_alive; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_lock_difficulty> params_packet_lock_difficulty; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_position> params_packet_position; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_position_look> params_packet_position_look; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_look> params_packet_look; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_flying> params_packet_flying; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_vehicle_move> params_packet_vehicle_move; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_steer_boat> params_packet_steer_boat; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_craft_recipe_request> params_packet_craft_recipe_request; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_abilities> params_packet_abilities; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_block_dig> params_packet_block_dig; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_entity_action> params_packet_entity_action; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_steer_vehicle> params_packet_steer_vehicle; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_displayed_recipe> params_packet_displayed_recipe; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_recipe_book> params_packet_recipe_book; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_resource_pack_receive> params_packet_resource_pack_receive; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_held_item_slot> params_packet_held_item_slot; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_set_creative_slot> params_packet_set_creative_slot; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_update_jigsaw_block> params_packet_update_jigsaw_block; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_update_sign> params_packet_update_sign; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_arm_animation> params_packet_arm_animation; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_spectate> params_packet_spectate; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_block_place> params_packet_block_place; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_use_item> params_packet_use_item; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_advancement_tab> params_packet_advancement_tab; /*4.0*/
    std::optional<pdef::pc1_18_play_toServer::packet_pong> params_packet_pong; /*4.0*/
  };
}

namespace pdef::pc1_18_play_toServer::size {
size_t slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::slot &obj);
size_t particle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::particle &obj);
size_t minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toServer::minecraft_smelting_format &obj);
size_t tags(pdef::Stream &stream, const pdef::pc1_18_play_toServer::tags &obj);
size_t chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::chunkBlockEntity &obj);
size_t command_node(pdef::Stream &stream, const pdef::pc1_18_play_toServer::command_node &obj);
size_t packet_teleport_confirm(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_teleport_confirm &obj);
size_t packet_query_block_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_block_nbt &obj);
size_t packet_set_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_difficulty &obj);
size_t packet_edit_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_edit_book &obj);
size_t packet_query_entity_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_entity_nbt &obj);
size_t packet_pick_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pick_item &obj);
size_t packet_name_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_name_item &obj);
size_t packet_select_trade(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_select_trade &obj);
size_t packet_set_beacon_effect(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_beacon_effect &obj);
size_t packet_update_command_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block &obj);
size_t packet_update_command_block_minecart(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block_minecart &obj);
size_t packet_update_structure_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_structure_block &obj);
size_t packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_tab_complete &obj);
size_t packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_chat &obj);
size_t packet_client_command(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_client_command &obj);
size_t packet_settings(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_settings &obj);
size_t packet_enchant_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_enchant_item &obj);
size_t packet_window_click(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_window_click &obj);
size_t packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_close_window &obj);
size_t packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_custom_payload &obj);
size_t packet_use_entity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_entity &obj);
size_t packet_generate_structure(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_generate_structure &obj);
size_t packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_keep_alive &obj);
size_t packet_lock_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_lock_difficulty &obj);
size_t packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position &obj);
size_t packet_position_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position_look &obj);
size_t packet_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_look &obj);
size_t packet_flying(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_flying &obj);
size_t packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_vehicle_move &obj);
size_t packet_steer_boat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_boat &obj);
size_t packet_craft_recipe_request(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_craft_recipe_request &obj);
size_t packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_abilities &obj);
size_t packet_block_dig(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_dig &obj);
size_t packet_entity_action(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_entity_action &obj);
size_t packet_steer_vehicle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_vehicle &obj);
size_t packet_displayed_recipe(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_displayed_recipe &obj);
size_t packet_recipe_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_recipe_book &obj);
size_t packet_resource_pack_receive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_resource_pack_receive &obj);
size_t packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_held_item_slot &obj);
size_t packet_set_creative_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_creative_slot &obj);
size_t packet_update_jigsaw_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_jigsaw_block &obj);
size_t packet_update_sign(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_sign &obj);
size_t packet_arm_animation(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_arm_animation &obj);
size_t packet_spectate(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_spectate &obj);
size_t packet_block_place(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_place &obj);
size_t packet_use_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_item &obj);
size_t packet_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_advancement_tab &obj);
size_t packet_pong(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pong &obj);
size_t packet(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet &obj);
  size_t slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::slot &obj) {
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
  size_t particle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::particle &obj) {
    size_t len = 0;
    const int &particleId = obj.particleId; /*0.1*/
    if (particleId == 2) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 3) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 14) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_14); const pdef::pc1_18_play_toServer::particle::Data14 &v = *obj.data_14; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 15) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_15); const pdef::pc1_18_play_toServer::particle::Data15 &v = *obj.data_15; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 24) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 35) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_35); const pdef::pc1_18_play_toServer::particle::Data35 &v = *obj.data_35; /*8.6*/
        len += 1; /*0.2*/
    }
    else if (particleId == 36) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_36); const pdef::pc1_18_play_toServer::particle::Data36 &v = *obj.data_36; /*8.6*/
        len += 1; /*origin: bitfield*/ /*4.1*/
        len += stream.sizeOfVarInt(v.positionType.length());
        len += v.positionType.length(); /*positionType^: pstring*/ /*4.1*/
        const pdef::pc1_18_play_toServer::particle::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_play_toServer::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          len += 1; /*destination: bitfield*/ /*4.1*/
        }
        else if (positionType == pdef::pc1_18_play_toServer::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          len += stream.sizeOfVarInt(v.destination_varint); /*0.2*/
        }
        len += stream.sizeOfVarInt(v.ticks); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toServer::minecraft_smelting_format &obj) {
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
size_t tags(pdef::Stream &stream, const pdef::pc1_18_play_toServer::tags &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.tagName.length());
    len += obj.tagName.length(); /*tagName: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.entries.size()); /*1.3*/
    for (const auto &v2 : obj.entries) {
      len += stream.sizeOfVarInt(v2); /*0.2*/
    }
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::chunkBlockEntity &obj) {
    size_t len = 0;
    len += 1; /*_3: bitfield*/ /*4.1*/
    len += 2; /*0.2*/
    len += stream.sizeOfVarInt(obj.type); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t command_node(pdef::Stream &stream, const pdef::pc1_18_play_toServer::command_node &obj) {
    size_t len = 0;
    len += 1; /*flags^: bitfield*/ /*4.1*/
    const pdef::pc1_18_play_toServer::command_node::bitfield &flags = obj.flags; /*0.1*/
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
        EXPECT_OR_BAIL(obj.extraNodeData_1); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.6*/
        len += stream.sizeOfVarInt(v.name.length());
        len += v.name.length(); /*name: pstring*/ /*4.1*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
        EXPECT_OR_BAIL(obj.extraNodeData_2); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.6*/
        len += stream.sizeOfVarInt(v.name.length());
        len += v.name.length(); /*name: pstring*/ /*4.1*/
        len += stream.sizeOfVarInt(v.parser.length());
        len += v.parser.length(); /*parser^: pstring*/ /*4.1*/
        const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.1*/
        if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_float); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_double); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_integer); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_long); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          len += 1; /*properties: bitfield*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          len += 1; /*properties: bitfield*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_range); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.6*/
            len += 1; /*0.2*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_resource_or_tag_or_minecraft_resource); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.6*/
            len += stream.sizeOfVarInt(v.registry.length());
            len += v.registry.length(); /*registry: pstring*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_resource_or_tag_or_minecraft_resource); const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.6*/
            len += stream.sizeOfVarInt(v.registry.length());
            len += v.registry.length(); /*registry: pstring*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          len += stream.sizeOfVarInt(v.suggestionType.length());
          len += v.suggestionType.length(); /*suggestionType: pstring*/ /*4.1*/
        }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_teleport_confirm(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_teleport_confirm &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.teleportId); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_query_block_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_block_nbt &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.transactionId); /*0.2*/
    len += 1; /*location: bitfield*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_difficulty &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_edit_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_edit_book &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.hand); /*0.2*/
    len += stream.sizeOfVarInt(obj.pages.size()); /*1.3*/
    for (const auto &v2 : obj.pages) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    const pdef::pc1_18_play_toServer::packet_edit_book::Title &v = obj.title; /*["packet_edit_book"]*/ /*7.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_query_entity_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_entity_nbt &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.transactionId); /*0.2*/
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_pick_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pick_item &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.slot); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_name_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_name_item &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_select_trade(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_select_trade &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.slot); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_beacon_effect(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_beacon_effect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.primary_effect); /*0.2*/
    len += stream.sizeOfVarInt(obj.secondary_effect); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_command_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.command.length());
    len += obj.command.length(); /*command: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.mode); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_command_block_minecart(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block_minecart &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += stream.sizeOfVarInt(obj.command.length());
    len += obj.command.length(); /*command: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_structure_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_structure_block &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.action); /*0.2*/
    len += stream.sizeOfVarInt(obj.mode); /*0.2*/
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.mirror); /*0.2*/
    len += stream.sizeOfVarInt(obj.rotation); /*0.2*/
    len += stream.sizeOfVarInt(obj.metadata.length());
    len += obj.metadata.length(); /*metadata: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.seed); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_tab_complete &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.transactionId); /*0.2*/
    len += stream.sizeOfVarInt(obj.text.length());
    len += obj.text.length(); /*text: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_chat &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.message.length());
    len += obj.message.length(); /*message: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_client_command(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_client_command &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.actionId); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_settings(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_settings &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.locale.length());
    len += obj.locale.length(); /*locale: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.chatFlags); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.mainHand); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_enchant_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_enchant_item &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_window_click(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_window_click &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.stateId); /*0.2*/
    len += 2; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.mode); /*0.2*/
    len += stream.sizeOfVarInt(obj.changedSlots.size()); /*1.3*/
    for (const auto &v2 : obj.changedSlots) { /*5.20*/
      len += 2; /*0.2*/
      len += 1; /*0.2*/
    }
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_close_window &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_custom_payload &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.channel.length());
    len += obj.channel.length(); /*channel: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_use_entity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.target); /*0.2*/
    const int &mouse = obj.mouse; /*0.1*/
    if (mouse == 2) { /*8.2*/
      len += 4; /*0.2*/
    }
    if (mouse == 2) { /*8.2*/
      len += 4; /*0.2*/
    }
    if (mouse == 2) { /*8.2*/
      len += 4; /*0.2*/
    }
    if (mouse == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.hand); /*0.2*/
    }
    else if (mouse == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.hand); /*0.2*/
    }
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_generate_structure(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_generate_structure &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.levels); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_keep_alive &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_lock_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_lock_difficulty &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_position_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position_look &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_look &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_flying(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_flying &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_vehicle_move &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_steer_boat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_boat &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_craft_recipe_request(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_craft_recipe_request &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.recipe.length());
    len += obj.recipe.length(); /*recipe: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_abilities &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_dig(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_dig &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.status); /*0.2*/
    len += 1; /*location: bitfield*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_action(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_entity_action &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += stream.sizeOfVarInt(obj.actionId); /*0.2*/
    len += stream.sizeOfVarInt(obj.jumpBoost); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_steer_vehicle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_vehicle &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_displayed_recipe(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_displayed_recipe &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.recipeId.length());
    len += obj.recipeId.length(); /*recipeId: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_recipe_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_recipe_book &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.bookId); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_pack_receive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_resource_pack_receive &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.result); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_held_item_slot &obj) {
    size_t len = 0;
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_creative_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_creative_slot &obj) {
    size_t len = 0;
    len += 2; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_jigsaw_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_jigsaw_block &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.target.length());
    len += obj.target.length(); /*target: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.pool.length());
    len += obj.pool.length(); /*pool: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.finalState.length());
    len += obj.finalState.length(); /*finalState: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.jointType.length());
    len += obj.jointType.length(); /*jointType: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_sign(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_sign &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.text1.length());
    len += obj.text1.length(); /*text1: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.text2.length());
    len += obj.text2.length(); /*text2: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.text3.length());
    len += obj.text3.length(); /*text3: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.text4.length());
    len += obj.text4.length(); /*text4: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_arm_animation(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_arm_animation &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.hand); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spectate(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_spectate &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_place(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_place &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.hand); /*0.2*/
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.direction); /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_use_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_item &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.hand); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_advancement_tab &obj) {
    size_t len = 0;
    const int &action = obj.action; /*0.1*/
    if (action == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.tabId.length());
      len += obj.tabId.length(); /*tabId: pstring*/ /*4.1*/
    }
    else if (action == 1) { /*8.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_pong(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pong &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet &obj) {
    size_t len = 0;
    const pdef::pc1_18_play_toServer::packet::Name &name = obj.name; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.name); /*name^: varint*/ /*7.0*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_play_toServer::packet::Name::TeleportConfirm: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_teleport_confirm); size_t len_0 = pdef::pc1_18_play_toServer::size::packet_teleport_confirm(stream, *obj.params_packet_teleport_confirm); EXPECT_OR_BAIL(len_0); len += len_0; /*params_packet_teleport_confirm*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::QueryBlockNbt: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_query_block_nbt); size_t len_1 = pdef::pc1_18_play_toServer::size::packet_query_block_nbt(stream, *obj.params_packet_query_block_nbt); EXPECT_OR_BAIL(len_1); len += len_1; /*params_packet_query_block_nbt*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetDifficulty: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_difficulty); size_t len_2 = pdef::pc1_18_play_toServer::size::packet_set_difficulty(stream, *obj.params_packet_set_difficulty); EXPECT_OR_BAIL(len_2); len += len_2; /*params_packet_set_difficulty*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EditBook: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_edit_book); size_t len_3 = pdef::pc1_18_play_toServer::size::packet_edit_book(stream, *obj.params_packet_edit_book); EXPECT_OR_BAIL(len_3); len += len_3; /*params_packet_edit_book*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::QueryEntityNbt: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_query_entity_nbt); size_t len_4 = pdef::pc1_18_play_toServer::size::packet_query_entity_nbt(stream, *obj.params_packet_query_entity_nbt); EXPECT_OR_BAIL(len_4); len += len_4; /*params_packet_query_entity_nbt*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::PickItem: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_pick_item); size_t len_5 = pdef::pc1_18_play_toServer::size::packet_pick_item(stream, *obj.params_packet_pick_item); EXPECT_OR_BAIL(len_5); len += len_5; /*params_packet_pick_item*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::NameItem: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_name_item); size_t len_6 = pdef::pc1_18_play_toServer::size::packet_name_item(stream, *obj.params_packet_name_item); EXPECT_OR_BAIL(len_6); len += len_6; /*params_packet_name_item*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SelectTrade: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_select_trade); size_t len_7 = pdef::pc1_18_play_toServer::size::packet_select_trade(stream, *obj.params_packet_select_trade); EXPECT_OR_BAIL(len_7); len += len_7; /*params_packet_select_trade*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetBeaconEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_beacon_effect); size_t len_8 = pdef::pc1_18_play_toServer::size::packet_set_beacon_effect(stream, *obj.params_packet_set_beacon_effect); EXPECT_OR_BAIL(len_8); len += len_8; /*params_packet_set_beacon_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateCommandBlock: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_command_block); size_t len_9 = pdef::pc1_18_play_toServer::size::packet_update_command_block(stream, *obj.params_packet_update_command_block); EXPECT_OR_BAIL(len_9); len += len_9; /*params_packet_update_command_block*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateCommandBlockMinecart: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_command_block_minecart); size_t len_10 = pdef::pc1_18_play_toServer::size::packet_update_command_block_minecart(stream, *obj.params_packet_update_command_block_minecart); EXPECT_OR_BAIL(len_10); len += len_10; /*params_packet_update_command_block_minecart*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateStructureBlock: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_structure_block); size_t len_11 = pdef::pc1_18_play_toServer::size::packet_update_structure_block(stream, *obj.params_packet_update_structure_block); EXPECT_OR_BAIL(len_11); len += len_11; /*params_packet_update_structure_block*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::TabComplete: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_tab_complete); size_t len_12 = pdef::pc1_18_play_toServer::size::packet_tab_complete(stream, *obj.params_packet_tab_complete); EXPECT_OR_BAIL(len_12); len += len_12; /*params_packet_tab_complete*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Chat: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_chat); size_t len_13 = pdef::pc1_18_play_toServer::size::packet_chat(stream, *obj.params_packet_chat); EXPECT_OR_BAIL(len_13); len += len_13; /*params_packet_chat*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ClientCommand: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_client_command); size_t len_14 = pdef::pc1_18_play_toServer::size::packet_client_command(stream, *obj.params_packet_client_command); EXPECT_OR_BAIL(len_14); len += len_14; /*params_packet_client_command*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Settings: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_settings); size_t len_15 = pdef::pc1_18_play_toServer::size::packet_settings(stream, *obj.params_packet_settings); EXPECT_OR_BAIL(len_15); len += len_15; /*params_packet_settings*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EnchantItem: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_enchant_item); size_t len_16 = pdef::pc1_18_play_toServer::size::packet_enchant_item(stream, *obj.params_packet_enchant_item); EXPECT_OR_BAIL(len_16); len += len_16; /*params_packet_enchant_item*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::WindowClick: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_window_click); size_t len_17 = pdef::pc1_18_play_toServer::size::packet_window_click(stream, *obj.params_packet_window_click); EXPECT_OR_BAIL(len_17); len += len_17; /*params_packet_window_click*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CloseWindow: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_close_window); size_t len_18 = pdef::pc1_18_play_toServer::size::packet_close_window(stream, *obj.params_packet_close_window); EXPECT_OR_BAIL(len_18); len += len_18; /*params_packet_close_window*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CustomPayload: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_custom_payload); size_t len_19 = pdef::pc1_18_play_toServer::size::packet_custom_payload(stream, *obj.params_packet_custom_payload); EXPECT_OR_BAIL(len_19); len += len_19; /*params_packet_custom_payload*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UseEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_use_entity); size_t len_20 = pdef::pc1_18_play_toServer::size::packet_use_entity(stream, *obj.params_packet_use_entity); EXPECT_OR_BAIL(len_20); len += len_20; /*params_packet_use_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::GenerateStructure: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_generate_structure); size_t len_21 = pdef::pc1_18_play_toServer::size::packet_generate_structure(stream, *obj.params_packet_generate_structure); EXPECT_OR_BAIL(len_21); len += len_21; /*params_packet_generate_structure*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::KeepAlive: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_keep_alive); size_t len_22 = pdef::pc1_18_play_toServer::size::packet_keep_alive(stream, *obj.params_packet_keep_alive); EXPECT_OR_BAIL(len_22); len += len_22; /*params_packet_keep_alive*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::LockDifficulty: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_lock_difficulty); size_t len_23 = pdef::pc1_18_play_toServer::size::packet_lock_difficulty(stream, *obj.params_packet_lock_difficulty); EXPECT_OR_BAIL(len_23); len += len_23; /*params_packet_lock_difficulty*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Position: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_position); size_t len_24 = pdef::pc1_18_play_toServer::size::packet_position(stream, *obj.params_packet_position); EXPECT_OR_BAIL(len_24); len += len_24; /*params_packet_position*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::PositionLook: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_position_look); size_t len_25 = pdef::pc1_18_play_toServer::size::packet_position_look(stream, *obj.params_packet_position_look); EXPECT_OR_BAIL(len_25); len += len_25; /*params_packet_position_look*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Look: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_look); size_t len_26 = pdef::pc1_18_play_toServer::size::packet_look(stream, *obj.params_packet_look); EXPECT_OR_BAIL(len_26); len += len_26; /*params_packet_look*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Flying: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_flying); size_t len_27 = pdef::pc1_18_play_toServer::size::packet_flying(stream, *obj.params_packet_flying); EXPECT_OR_BAIL(len_27); len += len_27; /*params_packet_flying*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::VehicleMove: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_vehicle_move); size_t len_28 = pdef::pc1_18_play_toServer::size::packet_vehicle_move(stream, *obj.params_packet_vehicle_move); EXPECT_OR_BAIL(len_28); len += len_28; /*params_packet_vehicle_move*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SteerBoat: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_steer_boat); size_t len_29 = pdef::pc1_18_play_toServer::size::packet_steer_boat(stream, *obj.params_packet_steer_boat); EXPECT_OR_BAIL(len_29); len += len_29; /*params_packet_steer_boat*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CraftRecipeRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_craft_recipe_request); size_t len_30 = pdef::pc1_18_play_toServer::size::packet_craft_recipe_request(stream, *obj.params_packet_craft_recipe_request); EXPECT_OR_BAIL(len_30); len += len_30; /*params_packet_craft_recipe_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Abilities: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_abilities); size_t len_31 = pdef::pc1_18_play_toServer::size::packet_abilities(stream, *obj.params_packet_abilities); EXPECT_OR_BAIL(len_31); len += len_31; /*params_packet_abilities*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::BlockDig: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_dig); size_t len_32 = pdef::pc1_18_play_toServer::size::packet_block_dig(stream, *obj.params_packet_block_dig); EXPECT_OR_BAIL(len_32); len += len_32; /*params_packet_block_dig*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EntityAction: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_action); size_t len_33 = pdef::pc1_18_play_toServer::size::packet_entity_action(stream, *obj.params_packet_entity_action); EXPECT_OR_BAIL(len_33); len += len_33; /*params_packet_entity_action*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SteerVehicle: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_steer_vehicle); size_t len_34 = pdef::pc1_18_play_toServer::size::packet_steer_vehicle(stream, *obj.params_packet_steer_vehicle); EXPECT_OR_BAIL(len_34); len += len_34; /*params_packet_steer_vehicle*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::DisplayedRecipe: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_displayed_recipe); size_t len_35 = pdef::pc1_18_play_toServer::size::packet_displayed_recipe(stream, *obj.params_packet_displayed_recipe); EXPECT_OR_BAIL(len_35); len += len_35; /*params_packet_displayed_recipe*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::RecipeBook: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_recipe_book); size_t len_36 = pdef::pc1_18_play_toServer::size::packet_recipe_book(stream, *obj.params_packet_recipe_book); EXPECT_OR_BAIL(len_36); len += len_36; /*params_packet_recipe_book*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ResourcePackReceive: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_pack_receive); size_t len_37 = pdef::pc1_18_play_toServer::size::packet_resource_pack_receive(stream, *obj.params_packet_resource_pack_receive); EXPECT_OR_BAIL(len_37); len += len_37; /*params_packet_resource_pack_receive*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::HeldItemSlot: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_held_item_slot); size_t len_38 = pdef::pc1_18_play_toServer::size::packet_held_item_slot(stream, *obj.params_packet_held_item_slot); EXPECT_OR_BAIL(len_38); len += len_38; /*params_packet_held_item_slot*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetCreativeSlot: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_creative_slot); size_t len_39 = pdef::pc1_18_play_toServer::size::packet_set_creative_slot(stream, *obj.params_packet_set_creative_slot); EXPECT_OR_BAIL(len_39); len += len_39; /*params_packet_set_creative_slot*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateJigsawBlock: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_jigsaw_block); size_t len_40 = pdef::pc1_18_play_toServer::size::packet_update_jigsaw_block(stream, *obj.params_packet_update_jigsaw_block); EXPECT_OR_BAIL(len_40); len += len_40; /*params_packet_update_jigsaw_block*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateSign: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_sign); size_t len_41 = pdef::pc1_18_play_toServer::size::packet_update_sign(stream, *obj.params_packet_update_sign); EXPECT_OR_BAIL(len_41); len += len_41; /*params_packet_update_sign*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ArmAnimation: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_arm_animation); size_t len_42 = pdef::pc1_18_play_toServer::size::packet_arm_animation(stream, *obj.params_packet_arm_animation); EXPECT_OR_BAIL(len_42); len += len_42; /*params_packet_arm_animation*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Spectate: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spectate); size_t len_43 = pdef::pc1_18_play_toServer::size::packet_spectate(stream, *obj.params_packet_spectate); EXPECT_OR_BAIL(len_43); len += len_43; /*params_packet_spectate*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::BlockPlace: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_place); size_t len_44 = pdef::pc1_18_play_toServer::size::packet_block_place(stream, *obj.params_packet_block_place); EXPECT_OR_BAIL(len_44); len += len_44; /*params_packet_block_place*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UseItem: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_use_item); size_t len_45 = pdef::pc1_18_play_toServer::size::packet_use_item(stream, *obj.params_packet_use_item); EXPECT_OR_BAIL(len_45); len += len_45; /*params_packet_use_item*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::AdvancementTab: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_advancement_tab); size_t len_46 = pdef::pc1_18_play_toServer::size::packet_advancement_tab(stream, *obj.params_packet_advancement_tab); EXPECT_OR_BAIL(len_46); len += len_46; /*params_packet_advancement_tab*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Pong: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_pong); size_t len_47 = pdef::pc1_18_play_toServer::size::packet_pong(stream, *obj.params_packet_pong); EXPECT_OR_BAIL(len_47); len += len_47; /*params_packet_pong*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
}

namespace pdef::pc1_18_play_toServer::encode {
bool slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::slot &obj, bool allocate);
bool particle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::particle &obj, bool allocate);
bool minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toServer::minecraft_smelting_format &obj, bool allocate);
bool tags(pdef::Stream &stream, const pdef::pc1_18_play_toServer::tags &obj, bool allocate);
bool chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::chunkBlockEntity &obj, bool allocate);
bool command_node(pdef::Stream &stream, const pdef::pc1_18_play_toServer::command_node &obj, bool allocate);
bool packet_teleport_confirm(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_teleport_confirm &obj, bool allocate);
bool packet_query_block_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_block_nbt &obj, bool allocate);
bool packet_set_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_difficulty &obj, bool allocate);
bool packet_edit_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_edit_book &obj, bool allocate);
bool packet_query_entity_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_entity_nbt &obj, bool allocate);
bool packet_pick_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pick_item &obj, bool allocate);
bool packet_name_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_name_item &obj, bool allocate);
bool packet_select_trade(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_select_trade &obj, bool allocate);
bool packet_set_beacon_effect(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_beacon_effect &obj, bool allocate);
bool packet_update_command_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block &obj, bool allocate);
bool packet_update_command_block_minecart(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block_minecart &obj, bool allocate);
bool packet_update_structure_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_structure_block &obj, bool allocate);
bool packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_tab_complete &obj, bool allocate);
bool packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_chat &obj, bool allocate);
bool packet_client_command(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_client_command &obj, bool allocate);
bool packet_settings(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_settings &obj, bool allocate);
bool packet_enchant_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_enchant_item &obj, bool allocate);
bool packet_window_click(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_window_click &obj, bool allocate);
bool packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_close_window &obj, bool allocate);
bool packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_custom_payload &obj, bool allocate);
bool packet_use_entity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_entity &obj, bool allocate);
bool packet_generate_structure(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_generate_structure &obj, bool allocate);
bool packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_keep_alive &obj, bool allocate);
bool packet_lock_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_lock_difficulty &obj, bool allocate);
bool packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position &obj, bool allocate);
bool packet_position_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position_look &obj, bool allocate);
bool packet_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_look &obj, bool allocate);
bool packet_flying(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_flying &obj, bool allocate);
bool packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_vehicle_move &obj, bool allocate);
bool packet_steer_boat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_boat &obj, bool allocate);
bool packet_craft_recipe_request(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_craft_recipe_request &obj, bool allocate);
bool packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_abilities &obj, bool allocate);
bool packet_block_dig(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_dig &obj, bool allocate);
bool packet_entity_action(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_entity_action &obj, bool allocate);
bool packet_steer_vehicle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_vehicle &obj, bool allocate);
bool packet_displayed_recipe(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_displayed_recipe &obj, bool allocate);
bool packet_recipe_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_recipe_book &obj, bool allocate);
bool packet_resource_pack_receive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_resource_pack_receive &obj, bool allocate);
bool packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_held_item_slot &obj, bool allocate);
bool packet_set_creative_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_creative_slot &obj, bool allocate);
bool packet_update_jigsaw_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_jigsaw_block &obj, bool allocate);
bool packet_update_sign(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_sign &obj, bool allocate);
bool packet_arm_animation(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_arm_animation &obj, bool allocate);
bool packet_spectate(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_spectate &obj, bool allocate);
bool packet_block_place(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_place &obj, bool allocate);
bool packet_use_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_item &obj, bool allocate);
bool packet_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_advancement_tab &obj, bool allocate);
bool packet_pong(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pong &obj, bool allocate);
bool packet(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet &obj, bool allocate);
  bool slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
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
  bool particle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::particle &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::particle(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &particleId = obj.particleId; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.particleId); /*0.4*/
    if (particleId == 2) { /*8.2*/
        const pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 3) { /*8.2*/
        const pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 14) { /*8.2*/
        const pdef::pc1_18_play_toServer::particle::Data14 &v = *obj.data_14; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.red); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.green); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.blue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
    }
    else if (particleId == 15) { /*8.2*/
        const pdef::pc1_18_play_toServer::particle::Data15 &v = *obj.data_15; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromBlue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toBlue); /*0.4*/
    }
    else if (particleId == 24) { /*8.2*/
        const pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 35) { /*8.2*/
        const pdef::pc1_18_play_toServer::particle::Data35 &v = *obj.data_35; /*8.5*/
        WRITE_OR_BAIL(writeByte, (int8_t)v.item); /*0.4*/
    }
    else if (particleId == 36) { /*8.2*/
        const pdef::pc1_18_play_toServer::particle::Data36 &v = *obj.data_36; /*8.5*/
        uint8_t origin_val = 0;
        origin_val |= v.origin.x << 0;
        origin_val |= v.origin.z << 26;
        origin_val |= v.origin.y << 52;
        WRITE_OR_BAIL(writeUByte, origin_val); /*origin: bitfield*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.positionType.length());
        WRITE_OR_BAIL(writeString, v.positionType); /*positionType: pstring*/ /*4.2*/
        const pdef::pc1_18_play_toServer::particle::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_play_toServer::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val = 0;
          destination_position_val |= v.destination_position.x << 0;
          destination_position_val |= v.destination_position.z << 26;
          destination_position_val |= v.destination_position.y << 52;
          WRITE_OR_BAIL(writeUByte, destination_position_val); /*destination_position: bitfield*/ /*4.2*/
        }
        else if (positionType == pdef::pc1_18_play_toServer::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.destination_varint); /*0.4*/
        }
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.ticks); /*0.4*/
    }
    return true;
  }
  bool minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toServer::minecraft_smelting_format &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::minecraft_smelting_format(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
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
bool tags(pdef::Stream &stream, const pdef::pc1_18_play_toServer::tags &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::tags(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.tagName.length());
    WRITE_OR_BAIL(writeString, obj.tagName); /*tagName: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entries.size()); /*1.4*/
    for (const auto &v2 : obj.entries) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2); /*0.4*/
    }
  return true;
}
  bool chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::chunkBlockEntity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::chunkBlockEntity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t _3_val = 0;
    _3_val |= obj._3.x << 0;
    _3_val |= obj._3.z << 4;
    WRITE_OR_BAIL(writeUByte, _3_val); /*_3: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbtData); /*0.4*/
    return true;
  }
  bool command_node(pdef::Stream &stream, const pdef::pc1_18_play_toServer::command_node &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::command_node(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t flags_val = 0;
    flags_val |= obj.flags.unused << 0;
    flags_val |= obj.flags.has_custom_suggestions << 3;
    flags_val |= obj.flags.has_redirect_node << 4;
    flags_val |= obj.flags.has_command << 5;
    flags_val |= obj.flags.command_node_type << 6;
    WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
    const pdef::pc1_18_play_toServer::command_node::bitfield &flags = obj.flags; /*0.1*/
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
        const pdef::pc1_18_play_toServer::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.name.length());
        WRITE_OR_BAIL(writeString, v.name); /*name: pstring*/ /*4.2*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
        const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.name.length());
        WRITE_OR_BAIL(writeString, v.name); /*name: pstring*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.parser.length());
        WRITE_OR_BAIL(writeString, v.parser); /*parser: pstring*/ /*4.2*/
        const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.1*/
        if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeFloatBE, (float)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeFloatBE, (float)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeDoubleBE, (double)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeDoubleBE, (double)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeIntBE, (int32_t)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeIntBE, (int32_t)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeLongBE, (int64_t)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeLongBE, (int64_t)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          uint8_t properties_minecraft_entity_val = 0;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.unused << 0;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.onlyAllowPlayers << 6;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.onlyAllowEntities << 7;
          WRITE_OR_BAIL(writeUByte, properties_minecraft_entity_val); /*properties_minecraft_entity: bitfield*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          uint8_t properties_minecraft_score_holder_val = 0;
          properties_minecraft_score_holder_val |= v.properties_minecraft_score_holder.unused << 0;
          properties_minecraft_score_holder_val |= v.properties_minecraft_score_holder.allowMultiple << 7;
          WRITE_OR_BAIL(writeUByte, properties_minecraft_score_holder_val); /*properties_minecraft_score_holder: bitfield*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.5*/
            WRITE_OR_BAIL(writeBool, (bool)v.allowDecimals); /*0.4*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.registry.length());
            WRITE_OR_BAIL(writeString, v.registry); /*registry: pstring*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
            const pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.registry.length());
            WRITE_OR_BAIL(writeString, v.registry); /*registry: pstring*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.suggestionType.length());
          WRITE_OR_BAIL(writeString, v.suggestionType); /*suggestionType: pstring*/ /*4.2*/
        }
    }
    return true;
  }
  bool packet_teleport_confirm(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_teleport_confirm &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_teleport_confirm(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.teleportId); /*0.4*/
    return true;
  }
  bool packet_query_block_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_block_nbt &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_query_block_nbt(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.transactionId); /*0.4*/
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    return true;
  }
  bool packet_set_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_difficulty &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_set_difficulty(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.newDifficulty); /*0.4*/
    return true;
  }
  bool packet_edit_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_edit_book &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_edit_book(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hand); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.pages.size()); /*1.4*/
    for (const auto &v2 : obj.pages) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    const pdef::pc1_18_play_toServer::packet_edit_book::Title &v = obj.title; /*["packet_edit_book"]*/ /*7.4*/
    return true;
  }
  bool packet_query_entity_nbt(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_query_entity_nbt &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_query_entity_nbt(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.transactionId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    return true;
  }
  bool packet_pick_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pick_item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_pick_item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.slot); /*0.4*/
    return true;
  }
  bool packet_name_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_name_item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_name_item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    return true;
  }
  bool packet_select_trade(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_select_trade &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_select_trade(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.slot); /*0.4*/
    return true;
  }
  bool packet_set_beacon_effect(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_beacon_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_set_beacon_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.primary_effect); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.secondary_effect); /*0.4*/
    return true;
  }
  bool packet_update_command_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_update_command_block(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command.length());
    WRITE_OR_BAIL(writeString, obj.command); /*command: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.mode); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.flags); /*0.4*/
    return true;
  }
  bool packet_update_command_block_minecart(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_command_block_minecart &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_update_command_block_minecart(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command.length());
    WRITE_OR_BAIL(writeString, obj.command); /*command: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.track_output); /*0.4*/
    return true;
  }
  bool packet_update_structure_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_structure_block &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_update_structure_block(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.mode); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.offset_x); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.offset_y); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.offset_z); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.size_x); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.size_y); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.size_z); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.mirror); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.rotation); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.metadata.length());
    WRITE_OR_BAIL(writeString, obj.metadata); /*metadata: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.integrity); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.seed); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.flags); /*0.4*/
    return true;
  }
  bool packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_tab_complete &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_tab_complete(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.transactionId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
    WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
    return true;
  }
  bool packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_chat &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_chat(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
    WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
    return true;
  }
  bool packet_client_command(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_client_command &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_client_command(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.actionId); /*0.4*/
    return true;
  }
  bool packet_settings(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_settings &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_settings(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.locale.length());
    WRITE_OR_BAIL(writeString, obj.locale); /*locale: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.viewDistance); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.chatFlags); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.chatColors); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.skinParts); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.mainHand); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.enableTextFiltering); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.enableServerListing); /*0.4*/
    return true;
  }
  bool packet_enchant_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_enchant_item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_enchant_item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.enchantment); /*0.4*/
    return true;
  }
  bool packet_window_click(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_window_click &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_window_click(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.stateId); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.slot); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.mouseButton); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.mode); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.changedSlots.size()); /*1.4*/
    for (const auto &v2 : obj.changedSlots) { /*5.20*/
      WRITE_OR_BAIL(writeShortBE, (int16_t)v2.location); /*0.4*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.item); /*0.4*/
    }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.cursorItem); /*0.4*/
    return true;
  }
  bool packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_close_window &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_close_window(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.windowId); /*0.4*/
    return true;
  }
  bool packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_custom_payload &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_custom_payload(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.channel.length());
    WRITE_OR_BAIL(writeString, obj.channel); /*channel: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.data); /*0.4*/
    return true;
  }
  bool packet_use_entity(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_use_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.target); /*0.4*/
    const int &mouse = obj.mouse; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.mouse); /*0.4*/
    if (mouse == 2) { /*8.2*/
      WRITE_OR_BAIL(writeFloatBE, (float)obj.x); /*0.4*/
    }
    if (mouse == 2) { /*8.2*/
      WRITE_OR_BAIL(writeFloatBE, (float)obj.y); /*0.4*/
    }
    if (mouse == 2) { /*8.2*/
      WRITE_OR_BAIL(writeFloatBE, (float)obj.z); /*0.4*/
    }
    if (mouse == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hand); /*0.4*/
    }
    else if (mouse == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hand); /*0.4*/
    }
    WRITE_OR_BAIL(writeBool, (bool)obj.sneaking); /*0.4*/
    return true;
  }
  bool packet_generate_structure(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_generate_structure &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_generate_structure(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.levels); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.keepJigsaws); /*0.4*/
    return true;
  }
  bool packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_keep_alive &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_keep_alive(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeLongBE, (int64_t)obj.keepAliveId); /*0.4*/
    return true;
  }
  bool packet_lock_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_lock_difficulty &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_lock_difficulty(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.locked); /*0.4*/
    return true;
  }
  bool packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_position(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_position_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_position_look &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_position_look(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_look(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_look &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_look(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatBE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_flying(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_flying &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_flying(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_vehicle_move &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_vehicle_move(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    return true;
  }
  bool packet_steer_boat(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_boat &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_steer_boat(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.leftPaddle); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.rightPaddle); /*0.4*/
    return true;
  }
  bool packet_craft_recipe_request(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_craft_recipe_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_craft_recipe_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.recipe.length());
    WRITE_OR_BAIL(writeString, obj.recipe); /*recipe: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.makeAll); /*0.4*/
    return true;
  }
  bool packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_abilities &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_abilities(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.flags); /*0.4*/
    return true;
  }
  bool packet_block_dig(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_dig &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_block_dig(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.status); /*0.4*/
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.face); /*0.4*/
    return true;
  }
  bool packet_entity_action(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_entity_action &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_entity_action(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.actionId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.jumpBoost); /*0.4*/
    return true;
  }
  bool packet_steer_vehicle(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_steer_vehicle &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_steer_vehicle(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatBE, (float)obj.sideways); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.forward); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.jump); /*0.4*/
    return true;
  }
  bool packet_displayed_recipe(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_displayed_recipe &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_displayed_recipe(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.recipeId.length());
    WRITE_OR_BAIL(writeString, obj.recipeId); /*recipeId: pstring*/ /*4.2*/
    return true;
  }
  bool packet_recipe_book(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_recipe_book &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_recipe_book(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.bookId); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.bookOpen); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.filterActive); /*0.4*/
    return true;
  }
  bool packet_resource_pack_receive(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_resource_pack_receive &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_resource_pack_receive(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.result); /*0.4*/
    return true;
  }
  bool packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_held_item_slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_held_item_slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.slotId); /*0.4*/
    return true;
  }
  bool packet_set_creative_slot(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_set_creative_slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_set_creative_slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.slot); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.item); /*0.4*/
    return true;
  }
  bool packet_update_jigsaw_block(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_jigsaw_block &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_update_jigsaw_block(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.target.length());
    WRITE_OR_BAIL(writeString, obj.target); /*target: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.pool.length());
    WRITE_OR_BAIL(writeString, obj.pool); /*pool: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.finalState.length());
    WRITE_OR_BAIL(writeString, obj.finalState); /*finalState: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.jointType.length());
    WRITE_OR_BAIL(writeString, obj.jointType); /*jointType: pstring*/ /*4.2*/
    return true;
  }
  bool packet_update_sign(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_update_sign &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_update_sign(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text1.length());
    WRITE_OR_BAIL(writeString, obj.text1); /*text1: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text2.length());
    WRITE_OR_BAIL(writeString, obj.text2); /*text2: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text3.length());
    WRITE_OR_BAIL(writeString, obj.text3); /*text3: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text4.length());
    WRITE_OR_BAIL(writeString, obj.text4); /*text4: pstring*/ /*4.2*/
    return true;
  }
  bool packet_arm_animation(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_arm_animation &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_arm_animation(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hand); /*0.4*/
    return true;
  }
  bool packet_spectate(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_spectate &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_spectate(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.target); /*0.4*/
    return true;
  }
  bool packet_block_place(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_block_place &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_block_place(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hand); /*0.4*/
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.direction); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.cursorX); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.cursorY); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.cursorZ); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.insideBlock); /*0.4*/
    return true;
  }
  bool packet_use_item(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_use_item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_use_item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hand); /*0.4*/
    return true;
  }
  bool packet_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_advancement_tab &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_advancement_tab(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &action = obj.action; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.tabId.length());
      WRITE_OR_BAIL(writeString, obj.tabId); /*tabId: pstring*/ /*4.2*/
    }
    else if (action == 1) { /*8.2*/
    }
    return true;
  }
  bool packet_pong(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet_pong &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet_pong(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.id); /*0.4*/
    return true;
  }
  bool packet(pdef::Stream &stream, const pdef::pc1_18_play_toServer::packet &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toServer::size::packet(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::pc1_18_play_toServer::packet::Name &name = obj.name; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.name); /*7.1*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_play_toServer::packet::Name::TeleportConfirm: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_teleport_confirm(stream, *obj.params_packet_teleport_confirm); /*packet_teleport_confirm*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::QueryBlockNbt: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_query_block_nbt(stream, *obj.params_packet_query_block_nbt); /*packet_query_block_nbt*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetDifficulty: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_set_difficulty(stream, *obj.params_packet_set_difficulty); /*packet_set_difficulty*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EditBook: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_edit_book(stream, *obj.params_packet_edit_book); /*packet_edit_book*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::QueryEntityNbt: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_query_entity_nbt(stream, *obj.params_packet_query_entity_nbt); /*packet_query_entity_nbt*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::PickItem: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_pick_item(stream, *obj.params_packet_pick_item); /*packet_pick_item*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::NameItem: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_name_item(stream, *obj.params_packet_name_item); /*packet_name_item*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SelectTrade: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_select_trade(stream, *obj.params_packet_select_trade); /*packet_select_trade*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetBeaconEffect: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_set_beacon_effect(stream, *obj.params_packet_set_beacon_effect); /*packet_set_beacon_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateCommandBlock: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_update_command_block(stream, *obj.params_packet_update_command_block); /*packet_update_command_block*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateCommandBlockMinecart: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_update_command_block_minecart(stream, *obj.params_packet_update_command_block_minecart); /*packet_update_command_block_minecart*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateStructureBlock: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_update_structure_block(stream, *obj.params_packet_update_structure_block); /*packet_update_structure_block*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::TabComplete: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_tab_complete(stream, *obj.params_packet_tab_complete); /*packet_tab_complete*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Chat: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_chat(stream, *obj.params_packet_chat); /*packet_chat*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ClientCommand: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_client_command(stream, *obj.params_packet_client_command); /*packet_client_command*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Settings: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_settings(stream, *obj.params_packet_settings); /*packet_settings*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EnchantItem: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_enchant_item(stream, *obj.params_packet_enchant_item); /*packet_enchant_item*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::WindowClick: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_window_click(stream, *obj.params_packet_window_click); /*packet_window_click*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CloseWindow: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_close_window(stream, *obj.params_packet_close_window); /*packet_close_window*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CustomPayload: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_custom_payload(stream, *obj.params_packet_custom_payload); /*packet_custom_payload*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UseEntity: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_use_entity(stream, *obj.params_packet_use_entity); /*packet_use_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::GenerateStructure: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_generate_structure(stream, *obj.params_packet_generate_structure); /*packet_generate_structure*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::KeepAlive: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_keep_alive(stream, *obj.params_packet_keep_alive); /*packet_keep_alive*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::LockDifficulty: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_lock_difficulty(stream, *obj.params_packet_lock_difficulty); /*packet_lock_difficulty*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Position: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_position(stream, *obj.params_packet_position); /*packet_position*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::PositionLook: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_position_look(stream, *obj.params_packet_position_look); /*packet_position_look*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Look: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_look(stream, *obj.params_packet_look); /*packet_look*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Flying: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_flying(stream, *obj.params_packet_flying); /*packet_flying*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::VehicleMove: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_vehicle_move(stream, *obj.params_packet_vehicle_move); /*packet_vehicle_move*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SteerBoat: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_steer_boat(stream, *obj.params_packet_steer_boat); /*packet_steer_boat*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CraftRecipeRequest: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_craft_recipe_request(stream, *obj.params_packet_craft_recipe_request); /*packet_craft_recipe_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Abilities: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_abilities(stream, *obj.params_packet_abilities); /*packet_abilities*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::BlockDig: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_block_dig(stream, *obj.params_packet_block_dig); /*packet_block_dig*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EntityAction: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_entity_action(stream, *obj.params_packet_entity_action); /*packet_entity_action*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SteerVehicle: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_steer_vehicle(stream, *obj.params_packet_steer_vehicle); /*packet_steer_vehicle*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::DisplayedRecipe: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_displayed_recipe(stream, *obj.params_packet_displayed_recipe); /*packet_displayed_recipe*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::RecipeBook: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_recipe_book(stream, *obj.params_packet_recipe_book); /*packet_recipe_book*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ResourcePackReceive: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_resource_pack_receive(stream, *obj.params_packet_resource_pack_receive); /*packet_resource_pack_receive*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::HeldItemSlot: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_held_item_slot(stream, *obj.params_packet_held_item_slot); /*packet_held_item_slot*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetCreativeSlot: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_set_creative_slot(stream, *obj.params_packet_set_creative_slot); /*packet_set_creative_slot*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateJigsawBlock: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_update_jigsaw_block(stream, *obj.params_packet_update_jigsaw_block); /*packet_update_jigsaw_block*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateSign: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_update_sign(stream, *obj.params_packet_update_sign); /*packet_update_sign*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ArmAnimation: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_arm_animation(stream, *obj.params_packet_arm_animation); /*packet_arm_animation*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Spectate: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_spectate(stream, *obj.params_packet_spectate); /*packet_spectate*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::BlockPlace: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_block_place(stream, *obj.params_packet_block_place); /*packet_block_place*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UseItem: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_use_item(stream, *obj.params_packet_use_item); /*packet_use_item*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::AdvancementTab: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_advancement_tab(stream, *obj.params_packet_advancement_tab); /*packet_advancement_tab*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Pong: { /*8.5*/
        pdef::pc1_18_play_toServer::encode::packet_pong(stream, *obj.params_packet_pong); /*packet_pong*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

namespace pdef::pc1_18_play_toServer::decode {
bool slot(pdef::Stream &stream, pdef::pc1_18_play_toServer::slot &obj);
bool particle(pdef::Stream &stream, pdef::pc1_18_play_toServer::particle &obj);
bool minecraft_smelting_format(pdef::Stream &stream, pdef::pc1_18_play_toServer::minecraft_smelting_format &obj);
bool tags(pdef::Stream &stream, pdef::pc1_18_play_toServer::tags &obj);
bool chunkBlockEntity(pdef::Stream &stream, pdef::pc1_18_play_toServer::chunkBlockEntity &obj);
bool command_node(pdef::Stream &stream, pdef::pc1_18_play_toServer::command_node &obj);
bool packet_teleport_confirm(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_teleport_confirm &obj);
bool packet_query_block_nbt(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_query_block_nbt &obj);
bool packet_set_difficulty(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_set_difficulty &obj);
bool packet_edit_book(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_edit_book &obj);
bool packet_query_entity_nbt(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_query_entity_nbt &obj);
bool packet_pick_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_pick_item &obj);
bool packet_name_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_name_item &obj);
bool packet_select_trade(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_select_trade &obj);
bool packet_set_beacon_effect(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_set_beacon_effect &obj);
bool packet_update_command_block(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_command_block &obj);
bool packet_update_command_block_minecart(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_command_block_minecart &obj);
bool packet_update_structure_block(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_structure_block &obj);
bool packet_tab_complete(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_tab_complete &obj);
bool packet_chat(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_chat &obj);
bool packet_client_command(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_client_command &obj);
bool packet_settings(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_settings &obj);
bool packet_enchant_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_enchant_item &obj);
bool packet_window_click(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_window_click &obj);
bool packet_close_window(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_close_window &obj);
bool packet_custom_payload(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_custom_payload &obj);
bool packet_use_entity(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_use_entity &obj);
bool packet_generate_structure(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_generate_structure &obj);
bool packet_keep_alive(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_keep_alive &obj);
bool packet_lock_difficulty(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_lock_difficulty &obj);
bool packet_position(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_position &obj);
bool packet_position_look(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_position_look &obj);
bool packet_look(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_look &obj);
bool packet_flying(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_flying &obj);
bool packet_vehicle_move(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_vehicle_move &obj);
bool packet_steer_boat(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_steer_boat &obj);
bool packet_craft_recipe_request(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_craft_recipe_request &obj);
bool packet_abilities(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_abilities &obj);
bool packet_block_dig(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_block_dig &obj);
bool packet_entity_action(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_entity_action &obj);
bool packet_steer_vehicle(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_steer_vehicle &obj);
bool packet_displayed_recipe(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_displayed_recipe &obj);
bool packet_recipe_book(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_recipe_book &obj);
bool packet_resource_pack_receive(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_resource_pack_receive &obj);
bool packet_held_item_slot(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_held_item_slot &obj);
bool packet_set_creative_slot(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_set_creative_slot &obj);
bool packet_update_jigsaw_block(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_jigsaw_block &obj);
bool packet_update_sign(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_sign &obj);
bool packet_arm_animation(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_arm_animation &obj);
bool packet_spectate(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_spectate &obj);
bool packet_block_place(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_block_place &obj);
bool packet_use_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_use_item &obj);
bool packet_advancement_tab(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_advancement_tab &obj);
bool packet_pong(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_pong &obj);
bool packet(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet &obj);
  bool slot(pdef::Stream &stream, pdef::pc1_18_play_toServer::slot &obj) {
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
  bool particle(pdef::Stream &stream, pdef::pc1_18_play_toServer::particle &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.particleId); /*0.5*/
    int &particleId = obj.particleId; /*0.6*/
    if (particleId == 2) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 3) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 14) { /*8.2*/
         obj.data_14 = {}; pdef::pc1_18_play_toServer::particle::Data14 &v = *obj.data_14; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.red); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.green); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.blue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
    }
    else if (particleId == 15) { /*8.2*/
         obj.data_15 = {}; pdef::pc1_18_play_toServer::particle::Data15 &v = *obj.data_15; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.fromRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromBlue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toBlue); /*0.5*/
    }
    else if (particleId == 24) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toServer::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 35) { /*8.2*/
         obj.data_35 = {}; pdef::pc1_18_play_toServer::particle::Data35 &v = *obj.data_35; /*8.4*/
        READ_OR_BAIL(readByte, v.item); /*0.5*/
    }
    else if (particleId == 36) { /*8.2*/
         obj.data_36 = {}; pdef::pc1_18_play_toServer::particle::Data36 &v = *obj.data_36; /*8.4*/
        uint8_t origin_val;
        READ_OR_BAIL(readUByte, origin_val);
        v.origin.x = origin_val >> 0 & 26;
        v.origin.z = origin_val >> 26 & 26;
        v.origin.y = origin_val >> 52 & 12; /*origin: bitfield*/ /*4.3*/
        int positionType_strlen; READ_OR_BAIL(readUnsignedVarInt, positionType_strlen);
        if (!stream.readString(v.positionType, positionType_strlen)) return false; /*positionType: pstring*/ /*4.3*/
        pdef::pc1_18_play_toServer::particle::Data36::pstring &positionType = v.positionType; /*0.7*/
        if (positionType == pdef::pc1_18_play_toServer::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val;
          READ_OR_BAIL(readUByte, destination_position_val);
          v.destination_position.x = destination_position_val >> 0 & 26;
          v.destination_position.z = destination_position_val >> 26 & 26;
          v.destination_position.y = destination_position_val >> 52 & 12; /*destination_position: bitfield*/ /*4.3*/
        }
        else if (positionType == pdef::pc1_18_play_toServer::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.destination_varint); /*0.5*/
        }
        READ_OR_BAIL(readUnsignedVarInt, v.ticks); /*0.5*/
    }
    return true;
  }
  bool minecraft_smelting_format(pdef::Stream &stream, pdef::pc1_18_play_toServer::minecraft_smelting_format &obj) {
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
bool tags(pdef::Stream &stream, pdef::pc1_18_play_toServer::tags &obj) {
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
  bool chunkBlockEntity(pdef::Stream &stream, pdef::pc1_18_play_toServer::chunkBlockEntity &obj) {
    uint8_t _3_val;
    READ_OR_BAIL(readUByte, _3_val);
    obj._3.x = _3_val >> 0 & 4;
    obj._3.z = _3_val >> 4 & 4; /*_3: bitfield*/ /*4.3*/
    READ_OR_BAIL(readShortBE, obj.y); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbtData); /*0.5*/
    return true;
  }
  bool command_node(pdef::Stream &stream, pdef::pc1_18_play_toServer::command_node &obj) {
    uint8_t flags_val;
    READ_OR_BAIL(readUByte, flags_val);
    obj.flags.unused = flags_val >> 0 & 3;
    obj.flags.has_custom_suggestions = flags_val >> 3 & 1;
    obj.flags.has_redirect_node = flags_val >> 4 & 1;
    obj.flags.has_command = flags_val >> 5 & 1;
    obj.flags.command_node_type = flags_val >> 6 & 2; /*flags: bitfield*/ /*4.3*/
    pdef::pc1_18_play_toServer::command_node::bitfield &flags = obj.flags; /*0.7*/
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
         obj.extraNodeData_1 = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.4*/
        int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
        if (!stream.readString(v.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
         obj.extraNodeData_2 = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.4*/
        int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
        if (!stream.readString(v.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
        int parser_strlen; READ_OR_BAIL(readUnsignedVarInt, parser_strlen);
        if (!stream.readString(v.parser, parser_strlen)) return false; /*parser: pstring*/ /*4.3*/
        pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.7*/
        if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
             v.properties_brigadier_float = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readFloatBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readFloatBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
             v.properties_brigadier_double = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readDoubleBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readDoubleBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
             v.properties_brigadier_integer = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readIntBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readIntBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
             v.properties_brigadier_long = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readLongBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readLongBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          uint8_t properties_minecraft_entity_val;
          READ_OR_BAIL(readUByte, properties_minecraft_entity_val);
          v.properties_minecraft_entity.unused = properties_minecraft_entity_val >> 0 & 6;
          v.properties_minecraft_entity.onlyAllowPlayers = properties_minecraft_entity_val >> 6 & 1;
          v.properties_minecraft_entity.onlyAllowEntities = properties_minecraft_entity_val >> 7 & 1; /*properties_minecraft_entity: bitfield*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          uint8_t properties_minecraft_score_holder_val;
          READ_OR_BAIL(readUByte, properties_minecraft_score_holder_val);
          v.properties_minecraft_score_holder.unused = properties_minecraft_score_holder_val >> 0 & 7;
          v.properties_minecraft_score_holder.allowMultiple = properties_minecraft_score_holder_val >> 7 & 1; /*properties_minecraft_score_holder: bitfield*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
             v.properties_minecraft_range = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.4*/
            READ_OR_BAIL(readBool, (bool&)v.allowDecimals); /*0.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
             v.properties_minecraft_resource_or_tag_or_minecraft_resource = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.4*/
            int registry_strlen; READ_OR_BAIL(readUnsignedVarInt, registry_strlen);
            if (!stream.readString(v.registry, registry_strlen)) return false; /*registry: pstring*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
             v.properties_minecraft_resource_or_tag_or_minecraft_resource = {}; pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.4*/
            int registry_strlen; READ_OR_BAIL(readUnsignedVarInt, registry_strlen);
            if (!stream.readString(v.registry, registry_strlen)) return false; /*registry: pstring*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toServer::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          int suggestionType_strlen; READ_OR_BAIL(readUnsignedVarInt, suggestionType_strlen);
          if (!stream.readString(v.suggestionType, suggestionType_strlen)) return false; /*suggestionType: pstring*/ /*4.3*/
        }
    }
    return true;
  }
  bool packet_teleport_confirm(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_teleport_confirm &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.teleportId); /*0.5*/
    return true;
  }
  bool packet_query_block_nbt(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_query_block_nbt &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.transactionId); /*0.5*/
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    return true;
  }
  bool packet_set_difficulty(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_set_difficulty &obj) {
    READ_OR_BAIL(readUByte, obj.newDifficulty); /*0.5*/
    return true;
  }
  bool packet_edit_book(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_edit_book &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.hand); /*0.5*/
    int pages_len; READ_OR_BAIL(readUnsignedVarInt, pages_len); /*1.5*/
    obj.pages.resize(pages_len); /*1.6*/
    for (int i = 0; i < pages_len; i++) {
      auto &v2 = obj.pages[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    const pdef::pc1_18_play_toServer::packet_edit_book::Title &v = obj.title = {}; /*["packet_edit_book"]*/ /*7.3*/
    return true;
  }
  bool packet_query_entity_nbt(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_query_entity_nbt &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.transactionId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    return true;
  }
  bool packet_pick_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_pick_item &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.slot); /*0.5*/
    return true;
  }
  bool packet_name_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_name_item &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    return true;
  }
  bool packet_select_trade(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_select_trade &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.slot); /*0.5*/
    return true;
  }
  bool packet_set_beacon_effect(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_set_beacon_effect &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.primary_effect); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.secondary_effect); /*0.5*/
    return true;
  }
  bool packet_update_command_block(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_command_block &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    int command_strlen; READ_OR_BAIL(readUnsignedVarInt, command_strlen);
    if (!stream.readString(obj.command, command_strlen)) return false; /*command: pstring*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.mode); /*0.5*/
    READ_OR_BAIL(readUByte, obj.flags); /*0.5*/
    return true;
  }
  bool packet_update_command_block_minecart(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_command_block_minecart &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    int command_strlen; READ_OR_BAIL(readUnsignedVarInt, command_strlen);
    if (!stream.readString(obj.command, command_strlen)) return false; /*command: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.track_output); /*0.5*/
    return true;
  }
  bool packet_update_structure_block(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_structure_block &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.mode); /*0.5*/
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.offset_x); /*0.5*/
    READ_OR_BAIL(readByte, obj.offset_y); /*0.5*/
    READ_OR_BAIL(readByte, obj.offset_z); /*0.5*/
    READ_OR_BAIL(readByte, obj.size_x); /*0.5*/
    READ_OR_BAIL(readByte, obj.size_y); /*0.5*/
    READ_OR_BAIL(readByte, obj.size_z); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.mirror); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.rotation); /*0.5*/
    int metadata_strlen; READ_OR_BAIL(readUnsignedVarInt, metadata_strlen);
    if (!stream.readString(obj.metadata, metadata_strlen)) return false; /*metadata: pstring*/ /*4.3*/
    READ_OR_BAIL(readFloatBE, obj.integrity); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.seed); /*0.5*/
    READ_OR_BAIL(readUByte, obj.flags); /*0.5*/
    return true;
  }
  bool packet_tab_complete(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_tab_complete &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.transactionId); /*0.5*/
    int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
    if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
    return true;
  }
  bool packet_chat(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_chat &obj) {
    int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
    if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
    return true;
  }
  bool packet_client_command(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_client_command &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.actionId); /*0.5*/
    return true;
  }
  bool packet_settings(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_settings &obj) {
    int locale_strlen; READ_OR_BAIL(readUnsignedVarInt, locale_strlen);
    if (!stream.readString(obj.locale, locale_strlen)) return false; /*locale: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.viewDistance); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.chatFlags); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.chatColors); /*0.5*/
    READ_OR_BAIL(readUByte, obj.skinParts); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.mainHand); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.enableTextFiltering); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.enableServerListing); /*0.5*/
    return true;
  }
  bool packet_enchant_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_enchant_item &obj) {
    READ_OR_BAIL(readByte, obj.windowId); /*0.5*/
    READ_OR_BAIL(readByte, obj.enchantment); /*0.5*/
    return true;
  }
  bool packet_window_click(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_window_click &obj) {
    READ_OR_BAIL(readUByte, obj.windowId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.stateId); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.slot); /*0.5*/
    READ_OR_BAIL(readByte, obj.mouseButton); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.mode); /*0.5*/
    int changedSlots_len; READ_OR_BAIL(readUnsignedVarInt, changedSlots_len); /*1.5*/
    obj.changedSlots.resize(changedSlots_len); /*1.6*/
    for (int i = 0; i < changedSlots_len; i++) { /*5*/
      pdef::pc1_18_play_toServer::packet_window_click::ChangedSlots &v2 = obj.changedSlots[i]; /*5.23*/
      READ_OR_BAIL(readShortBE, v2.location); /*0.5*/
      READ_OR_BAIL(readByte, v2.item); /*0.5*/
    }
    READ_OR_BAIL(readByte, obj.cursorItem); /*0.5*/
    return true;
  }
  bool packet_close_window(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_close_window &obj) {
    READ_OR_BAIL(readUByte, obj.windowId); /*0.5*/
    return true;
  }
  bool packet_custom_payload(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_custom_payload &obj) {
    int channel_strlen; READ_OR_BAIL(readUnsignedVarInt, channel_strlen);
    if (!stream.readString(obj.channel, channel_strlen)) return false; /*channel: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.data); /*0.5*/
    return true;
  }
  bool packet_use_entity(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_use_entity &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.target); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.mouse); /*0.5*/
    int &mouse = obj.mouse; /*0.6*/
    if (mouse == 2) { /*8.2*/
      READ_OR_BAIL(readFloatBE, obj.x); /*0.5*/
    }
    if (mouse == 2) { /*8.2*/
      READ_OR_BAIL(readFloatBE, obj.y); /*0.5*/
    }
    if (mouse == 2) { /*8.2*/
      READ_OR_BAIL(readFloatBE, obj.z); /*0.5*/
    }
    if (mouse == 0) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.hand); /*0.5*/
    }
    else if (mouse == 2) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.hand); /*0.5*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.sneaking); /*0.5*/
    return true;
  }
  bool packet_generate_structure(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_generate_structure &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.levels); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.keepJigsaws); /*0.5*/
    return true;
  }
  bool packet_keep_alive(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_keep_alive &obj) {
    READ_OR_BAIL(readLongBE, obj.keepAliveId); /*0.5*/
    return true;
  }
  bool packet_lock_difficulty(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_lock_difficulty &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.locked); /*0.5*/
    return true;
  }
  bool packet_position(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_position &obj) {
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_position_look(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_position_look &obj) {
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_look(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_look &obj) {
    READ_OR_BAIL(readFloatBE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_flying(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_flying &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_vehicle_move(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_vehicle_move &obj) {
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    return true;
  }
  bool packet_steer_boat(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_steer_boat &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.leftPaddle); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.rightPaddle); /*0.5*/
    return true;
  }
  bool packet_craft_recipe_request(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_craft_recipe_request &obj) {
    READ_OR_BAIL(readByte, obj.windowId); /*0.5*/
    int recipe_strlen; READ_OR_BAIL(readUnsignedVarInt, recipe_strlen);
    if (!stream.readString(obj.recipe, recipe_strlen)) return false; /*recipe: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.makeAll); /*0.5*/
    return true;
  }
  bool packet_abilities(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_abilities &obj) {
    READ_OR_BAIL(readByte, obj.flags); /*0.5*/
    return true;
  }
  bool packet_block_dig(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_block_dig &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.status); /*0.5*/
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.face); /*0.5*/
    return true;
  }
  bool packet_entity_action(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_entity_action &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.actionId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.jumpBoost); /*0.5*/
    return true;
  }
  bool packet_steer_vehicle(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_steer_vehicle &obj) {
    READ_OR_BAIL(readFloatBE, obj.sideways); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.forward); /*0.5*/
    READ_OR_BAIL(readUByte, obj.jump); /*0.5*/
    return true;
  }
  bool packet_displayed_recipe(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_displayed_recipe &obj) {
    int recipeId_strlen; READ_OR_BAIL(readUnsignedVarInt, recipeId_strlen);
    if (!stream.readString(obj.recipeId, recipeId_strlen)) return false; /*recipeId: pstring*/ /*4.3*/
    return true;
  }
  bool packet_recipe_book(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_recipe_book &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.bookId); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.bookOpen); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.filterActive); /*0.5*/
    return true;
  }
  bool packet_resource_pack_receive(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_resource_pack_receive &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.result); /*0.5*/
    return true;
  }
  bool packet_held_item_slot(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_held_item_slot &obj) {
    READ_OR_BAIL(readShortBE, obj.slotId); /*0.5*/
    return true;
  }
  bool packet_set_creative_slot(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_set_creative_slot &obj) {
    READ_OR_BAIL(readShortBE, obj.slot); /*0.5*/
    READ_OR_BAIL(readByte, obj.item); /*0.5*/
    return true;
  }
  bool packet_update_jigsaw_block(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_jigsaw_block &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    int target_strlen; READ_OR_BAIL(readUnsignedVarInt, target_strlen);
    if (!stream.readString(obj.target, target_strlen)) return false; /*target: pstring*/ /*4.3*/
    int pool_strlen; READ_OR_BAIL(readUnsignedVarInt, pool_strlen);
    if (!stream.readString(obj.pool, pool_strlen)) return false; /*pool: pstring*/ /*4.3*/
    int finalState_strlen; READ_OR_BAIL(readUnsignedVarInt, finalState_strlen);
    if (!stream.readString(obj.finalState, finalState_strlen)) return false; /*finalState: pstring*/ /*4.3*/
    int jointType_strlen; READ_OR_BAIL(readUnsignedVarInt, jointType_strlen);
    if (!stream.readString(obj.jointType, jointType_strlen)) return false; /*jointType: pstring*/ /*4.3*/
    return true;
  }
  bool packet_update_sign(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_update_sign &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    int text1_strlen; READ_OR_BAIL(readUnsignedVarInt, text1_strlen);
    if (!stream.readString(obj.text1, text1_strlen)) return false; /*text1: pstring*/ /*4.3*/
    int text2_strlen; READ_OR_BAIL(readUnsignedVarInt, text2_strlen);
    if (!stream.readString(obj.text2, text2_strlen)) return false; /*text2: pstring*/ /*4.3*/
    int text3_strlen; READ_OR_BAIL(readUnsignedVarInt, text3_strlen);
    if (!stream.readString(obj.text3, text3_strlen)) return false; /*text3: pstring*/ /*4.3*/
    int text4_strlen; READ_OR_BAIL(readUnsignedVarInt, text4_strlen);
    if (!stream.readString(obj.text4, text4_strlen)) return false; /*text4: pstring*/ /*4.3*/
    return true;
  }
  bool packet_arm_animation(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_arm_animation &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.hand); /*0.5*/
    return true;
  }
  bool packet_spectate(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_spectate &obj) {
    READ_OR_BAIL(readULongBE, obj.target); /*0.5*/
    return true;
  }
  bool packet_block_place(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_block_place &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.hand); /*0.5*/
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.direction); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.cursorX); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.cursorY); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.cursorZ); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.insideBlock); /*0.5*/
    return true;
  }
  bool packet_use_item(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_use_item &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.hand); /*0.5*/
    return true;
  }
  bool packet_advancement_tab(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_advancement_tab &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
    int &action = obj.action; /*0.6*/
    if (action == 0) { /*8.2*/
      int tabId_strlen; READ_OR_BAIL(readUnsignedVarInt, tabId_strlen);
      if (!stream.readString(obj.tabId, tabId_strlen)) return false; /*tabId: pstring*/ /*4.3*/
    }
    else if (action == 1) { /*8.2*/
    }
    return true;
  }
  bool packet_pong(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet_pong &obj) {
    READ_OR_BAIL(readIntBE, obj.id); /*0.5*/
    return true;
  }
  bool packet(pdef::Stream &stream, pdef::pc1_18_play_toServer::packet &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.name); /*7.2*/
    const pdef::pc1_18_play_toServer::packet::Name &name = obj.name; /*0.7*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_play_toServer::packet::Name::TeleportConfirm: { /*8.5*/
        obj.params_packet_teleport_confirm = {}; pdef::pc1_18_play_toServer::decode::packet_teleport_confirm(stream, *obj.params_packet_teleport_confirm); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::QueryBlockNbt: { /*8.5*/
        obj.params_packet_query_block_nbt = {}; pdef::pc1_18_play_toServer::decode::packet_query_block_nbt(stream, *obj.params_packet_query_block_nbt); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetDifficulty: { /*8.5*/
        obj.params_packet_set_difficulty = {}; pdef::pc1_18_play_toServer::decode::packet_set_difficulty(stream, *obj.params_packet_set_difficulty); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EditBook: { /*8.5*/
        obj.params_packet_edit_book = {}; pdef::pc1_18_play_toServer::decode::packet_edit_book(stream, *obj.params_packet_edit_book); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::QueryEntityNbt: { /*8.5*/
        obj.params_packet_query_entity_nbt = {}; pdef::pc1_18_play_toServer::decode::packet_query_entity_nbt(stream, *obj.params_packet_query_entity_nbt); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::PickItem: { /*8.5*/
        obj.params_packet_pick_item = {}; pdef::pc1_18_play_toServer::decode::packet_pick_item(stream, *obj.params_packet_pick_item); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::NameItem: { /*8.5*/
        obj.params_packet_name_item = {}; pdef::pc1_18_play_toServer::decode::packet_name_item(stream, *obj.params_packet_name_item); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SelectTrade: { /*8.5*/
        obj.params_packet_select_trade = {}; pdef::pc1_18_play_toServer::decode::packet_select_trade(stream, *obj.params_packet_select_trade); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetBeaconEffect: { /*8.5*/
        obj.params_packet_set_beacon_effect = {}; pdef::pc1_18_play_toServer::decode::packet_set_beacon_effect(stream, *obj.params_packet_set_beacon_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateCommandBlock: { /*8.5*/
        obj.params_packet_update_command_block = {}; pdef::pc1_18_play_toServer::decode::packet_update_command_block(stream, *obj.params_packet_update_command_block); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateCommandBlockMinecart: { /*8.5*/
        obj.params_packet_update_command_block_minecart = {}; pdef::pc1_18_play_toServer::decode::packet_update_command_block_minecart(stream, *obj.params_packet_update_command_block_minecart); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateStructureBlock: { /*8.5*/
        obj.params_packet_update_structure_block = {}; pdef::pc1_18_play_toServer::decode::packet_update_structure_block(stream, *obj.params_packet_update_structure_block); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::TabComplete: { /*8.5*/
        obj.params_packet_tab_complete = {}; pdef::pc1_18_play_toServer::decode::packet_tab_complete(stream, *obj.params_packet_tab_complete); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Chat: { /*8.5*/
        obj.params_packet_chat = {}; pdef::pc1_18_play_toServer::decode::packet_chat(stream, *obj.params_packet_chat); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ClientCommand: { /*8.5*/
        obj.params_packet_client_command = {}; pdef::pc1_18_play_toServer::decode::packet_client_command(stream, *obj.params_packet_client_command); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Settings: { /*8.5*/
        obj.params_packet_settings = {}; pdef::pc1_18_play_toServer::decode::packet_settings(stream, *obj.params_packet_settings); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EnchantItem: { /*8.5*/
        obj.params_packet_enchant_item = {}; pdef::pc1_18_play_toServer::decode::packet_enchant_item(stream, *obj.params_packet_enchant_item); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::WindowClick: { /*8.5*/
        obj.params_packet_window_click = {}; pdef::pc1_18_play_toServer::decode::packet_window_click(stream, *obj.params_packet_window_click); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CloseWindow: { /*8.5*/
        obj.params_packet_close_window = {}; pdef::pc1_18_play_toServer::decode::packet_close_window(stream, *obj.params_packet_close_window); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CustomPayload: { /*8.5*/
        obj.params_packet_custom_payload = {}; pdef::pc1_18_play_toServer::decode::packet_custom_payload(stream, *obj.params_packet_custom_payload); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UseEntity: { /*8.5*/
        obj.params_packet_use_entity = {}; pdef::pc1_18_play_toServer::decode::packet_use_entity(stream, *obj.params_packet_use_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::GenerateStructure: { /*8.5*/
        obj.params_packet_generate_structure = {}; pdef::pc1_18_play_toServer::decode::packet_generate_structure(stream, *obj.params_packet_generate_structure); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::KeepAlive: { /*8.5*/
        obj.params_packet_keep_alive = {}; pdef::pc1_18_play_toServer::decode::packet_keep_alive(stream, *obj.params_packet_keep_alive); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::LockDifficulty: { /*8.5*/
        obj.params_packet_lock_difficulty = {}; pdef::pc1_18_play_toServer::decode::packet_lock_difficulty(stream, *obj.params_packet_lock_difficulty); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Position: { /*8.5*/
        obj.params_packet_position = {}; pdef::pc1_18_play_toServer::decode::packet_position(stream, *obj.params_packet_position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::PositionLook: { /*8.5*/
        obj.params_packet_position_look = {}; pdef::pc1_18_play_toServer::decode::packet_position_look(stream, *obj.params_packet_position_look); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Look: { /*8.5*/
        obj.params_packet_look = {}; pdef::pc1_18_play_toServer::decode::packet_look(stream, *obj.params_packet_look); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Flying: { /*8.5*/
        obj.params_packet_flying = {}; pdef::pc1_18_play_toServer::decode::packet_flying(stream, *obj.params_packet_flying); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::VehicleMove: { /*8.5*/
        obj.params_packet_vehicle_move = {}; pdef::pc1_18_play_toServer::decode::packet_vehicle_move(stream, *obj.params_packet_vehicle_move); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SteerBoat: { /*8.5*/
        obj.params_packet_steer_boat = {}; pdef::pc1_18_play_toServer::decode::packet_steer_boat(stream, *obj.params_packet_steer_boat); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::CraftRecipeRequest: { /*8.5*/
        obj.params_packet_craft_recipe_request = {}; pdef::pc1_18_play_toServer::decode::packet_craft_recipe_request(stream, *obj.params_packet_craft_recipe_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Abilities: { /*8.5*/
        obj.params_packet_abilities = {}; pdef::pc1_18_play_toServer::decode::packet_abilities(stream, *obj.params_packet_abilities); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::BlockDig: { /*8.5*/
        obj.params_packet_block_dig = {}; pdef::pc1_18_play_toServer::decode::packet_block_dig(stream, *obj.params_packet_block_dig); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::EntityAction: { /*8.5*/
        obj.params_packet_entity_action = {}; pdef::pc1_18_play_toServer::decode::packet_entity_action(stream, *obj.params_packet_entity_action); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SteerVehicle: { /*8.5*/
        obj.params_packet_steer_vehicle = {}; pdef::pc1_18_play_toServer::decode::packet_steer_vehicle(stream, *obj.params_packet_steer_vehicle); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::DisplayedRecipe: { /*8.5*/
        obj.params_packet_displayed_recipe = {}; pdef::pc1_18_play_toServer::decode::packet_displayed_recipe(stream, *obj.params_packet_displayed_recipe); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::RecipeBook: { /*8.5*/
        obj.params_packet_recipe_book = {}; pdef::pc1_18_play_toServer::decode::packet_recipe_book(stream, *obj.params_packet_recipe_book); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ResourcePackReceive: { /*8.5*/
        obj.params_packet_resource_pack_receive = {}; pdef::pc1_18_play_toServer::decode::packet_resource_pack_receive(stream, *obj.params_packet_resource_pack_receive); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::HeldItemSlot: { /*8.5*/
        obj.params_packet_held_item_slot = {}; pdef::pc1_18_play_toServer::decode::packet_held_item_slot(stream, *obj.params_packet_held_item_slot); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::SetCreativeSlot: { /*8.5*/
        obj.params_packet_set_creative_slot = {}; pdef::pc1_18_play_toServer::decode::packet_set_creative_slot(stream, *obj.params_packet_set_creative_slot); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateJigsawBlock: { /*8.5*/
        obj.params_packet_update_jigsaw_block = {}; pdef::pc1_18_play_toServer::decode::packet_update_jigsaw_block(stream, *obj.params_packet_update_jigsaw_block); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UpdateSign: { /*8.5*/
        obj.params_packet_update_sign = {}; pdef::pc1_18_play_toServer::decode::packet_update_sign(stream, *obj.params_packet_update_sign); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::ArmAnimation: { /*8.5*/
        obj.params_packet_arm_animation = {}; pdef::pc1_18_play_toServer::decode::packet_arm_animation(stream, *obj.params_packet_arm_animation); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Spectate: { /*8.5*/
        obj.params_packet_spectate = {}; pdef::pc1_18_play_toServer::decode::packet_spectate(stream, *obj.params_packet_spectate); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::BlockPlace: { /*8.5*/
        obj.params_packet_block_place = {}; pdef::pc1_18_play_toServer::decode::packet_block_place(stream, *obj.params_packet_block_place); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::UseItem: { /*8.5*/
        obj.params_packet_use_item = {}; pdef::pc1_18_play_toServer::decode::packet_use_item(stream, *obj.params_packet_use_item); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::AdvancementTab: { /*8.5*/
        obj.params_packet_advancement_tab = {}; pdef::pc1_18_play_toServer::decode::packet_advancement_tab(stream, *obj.params_packet_advancement_tab); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toServer::packet::Name::Pong: { /*8.5*/
        obj.params_packet_pong = {}; pdef::pc1_18_play_toServer::decode::packet_pong(stream, *obj.params_packet_pong); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

#undef WRITE_OR_BAIL
#undef READ_OR_BAIL
