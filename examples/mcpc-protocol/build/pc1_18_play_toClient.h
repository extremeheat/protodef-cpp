
#include <string>
#include <vector>
#include <optional>
#include "stream.h"
#define DBG_PRINT printf
#define WRITE_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: write FAIL\n", __func__, __LINE__, #fn); return false; }; DBG_PRINT("%s:%d: %s: written, stream now at %d\n", __func__, __LINE__, #fn, stream.writeIndex);
#define READ_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: read FAIL\n", __func__, __LINE__, #fn); return false; } DBG_PRINT("%s:%d: %s: read, stream now at %d\n", __func__, __LINE__, #fn, stream.readIndex);
#define EXPECT_OR_BAIL(val) if (!val) { DBG_PRINT("%s:%d: bad assert %s\n", __func__, __LINE__, #val); return false; }
namespace pdef::pc1_18_play_toClient {

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
struct packet_spawn_entity;
struct packet_spawn_entity_experience_orb;
struct packet_spawn_entity_living;
struct packet_spawn_entity_painting;
struct packet_named_entity_spawn;
struct packet_animation;
struct packet_statistics;
struct Entries;
struct packet_advancements;
struct AdvancementMapping;
struct Value;
struct ParentId;
struct DisplayData;
struct Value;
struct Criteria;
struct ProgressMapping;
struct Value;
struct CriterionProgress;
struct packet_block_break_animation;
struct packet_tile_entity_data;
struct packet_block_action;
struct packet_block_change;
struct packet_boss_bar;
struct packet_difficulty;
struct packet_tab_complete;
struct Matches;
struct Tooltip;
struct packet_declare_commands;
struct packet_face_player;
struct packet_nbt_query_response;
struct packet_chat;
struct packet_multi_block_change;
struct packet_close_window;
struct packet_open_window;
struct packet_window_items;
struct packet_craft_progress_bar;
struct packet_set_slot;
struct packet_set_cooldown;
struct packet_custom_payload;
struct packet_named_sound_effect;
struct packet_kick_disconnect;
struct packet_entity_status;
struct packet_explosion;
struct AffectedBlockOffsets;
struct packet_unload_chunk;
struct packet_game_state_change;
struct packet_open_horse_window;
struct packet_keep_alive;
struct packet_map_chunk;
struct packet_world_event;
struct packet_world_particles;
struct Data14;
struct Data15;
struct Data35;
struct Data36;
struct Data2Or3Or24;
struct packet_update_light;
struct packet_login;
struct packet_map;
struct Icons;
struct Value;
struct DisplayName;
struct packet_trade_list;
struct Trades;
struct InputItem2;
struct packet_rel_entity_move;
struct packet_entity_move_look;
struct packet_entity_look;
struct packet_vehicle_move;
struct packet_open_book;
struct packet_open_sign_entity;
struct packet_craft_recipe_response;
struct packet_abilities;
struct packet_end_combat_event;
struct packet_enter_combat_event;
struct packet_death_combat_event;
struct packet_player_info;
struct Data;
struct Properties;
struct Signature;
struct DisplayName;
struct packet_position;
struct packet_unlock_recipes;
struct packet_entity_destroy;
struct packet_remove_entity_effect;
struct packet_resource_pack_send;
struct PromptMessage;
struct packet_respawn;
struct packet_entity_head_rotation;
struct packet_camera;
struct packet_held_item_slot;
struct packet_update_view_position;
struct packet_update_view_distance;
struct packet_scoreboard_display_objective;
struct packet_entity_metadata;
struct packet_attach_entity;
struct packet_entity_velocity;
struct packet_entity_equipment;
struct packet_experience;
struct packet_update_health;
struct packet_scoreboard_objective;
struct packet_set_passengers;
struct packet_teams;
struct packet_scoreboard_score;
struct packet_spawn_position;
struct packet_update_time;
struct packet_entity_sound_effect;
struct packet_stop_sound;
struct packet_sound_effect;
struct packet_playerlist_header;
struct packet_collect;
struct packet_entity_teleport;
struct packet_entity_update_attributes;
struct Properties;
struct Modifiers;
struct packet_entity_effect;
struct packet_select_advancement_tab;
struct Id;
struct packet_declare_recipes;
struct Recipes;
struct DataMinecraftCraftingShapeless;
struct DataMinecraftCraftingShaped;
struct DataMinecraftStonecutting;
struct DataMinecraftSmithing;
struct packet_tags;
struct Tags;
struct packet_acknowledge_player_digging;
struct packet_sculk_vibration_signal;
struct packet_clear_titles;
struct packet_initialize_world_border;
struct packet_action_bar;
struct packet_world_border_center;
struct packet_world_border_lerp_size;
struct packet_world_border_size;
struct packet_world_border_warning_delay;
struct packet_world_border_warning_reach;
struct packet_ping;
struct packet_set_title_subtitle;
struct packet_set_title_text;
struct packet_set_title_time;
struct packet_simulation_distance;
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
  struct packet_spawn_entity {
    int entityId; /*0.0*/
    uint64_t objectUUID; /*0.0*/
    int type; /*0.0*/
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    int8_t pitch; /*0.0*/
    int8_t yaw; /*0.0*/
    int32_t objectData; /*0.0*/
    int16_t velocityX; /*0.0*/
    int16_t velocityY; /*0.0*/
    int16_t velocityZ; /*0.0*/
  };
  struct packet_spawn_entity_experience_orb {
    int entityId; /*0.0*/
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    int16_t count; /*0.0*/
  };
  struct packet_spawn_entity_living {
    int entityId; /*0.0*/
    uint64_t entityUUID; /*0.0*/
    int type; /*0.0*/
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    int8_t yaw; /*0.0*/
    int8_t pitch; /*0.0*/
    int8_t headPitch; /*0.0*/
    int16_t velocityX; /*0.0*/
    int16_t velocityY; /*0.0*/
    int16_t velocityZ; /*0.0*/
  };
  struct packet_spawn_entity_painting {
    int entityId; /*0.0*/
    uint64_t entityUUID; /*0.0*/
    int title; /*0.0*/
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    uint8_t direction; /*0.0*/
  };
  struct packet_named_entity_spawn {
    int entityId; /*0.0*/
    uint64_t playerUUID; /*0.0*/
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    int8_t yaw; /*0.0*/
    int8_t pitch; /*0.0*/
  };
  struct packet_animation {
    int entityId; /*0.0*/
    uint8_t animation; /*0.0*/
  };
  struct packet_statistics {
    struct Entries {
      int categoryId; /*0.0*/
      int statisticId; /*0.0*/
      int value; /*0.0*/
    };
    std::vector<Entries /*3.2*/> entries; /*3.0*/
  };
  struct packet_advancements {
    bool reset; /*0.0*/
    struct AdvancementMapping {
      std::string key; /*6.0*/
      struct Value {
        struct ParentId {
          bool has; /*0.0*/
          std::string value; /*6.0*/
        };
        ParentId parentId; /*3.2*/
        struct DisplayData {
          bool has; /*0.0*/
          struct Value {
            std::string title; /*6.0*/
            std::string description; /*6.0*/
            int8_t icon; /*0.0*/
            int frameType; /*0.0*/
            struct { /*6.0*/
              int _unused = 0; /*6.0*/
              int hidden = 0; /*6.0*/
              int show_toast = 0; /*6.0*/
              int has_background_texture = 0; /*6.0*/
            } flags; /*6.0*/
            float xCord; /*0.0*/
            float yCord; /*0.0*/
            std::string backgroundTexture; /*6.0*/
          };
          std::optional<Value> value; /*3.2*/
        };
        DisplayData displayData; /*3.2*/
        struct Criteria {
          std::string key; /*6.0*/
        };
        std::vector<Criteria /*3.2*/> criteria; /*3.0*/
        std::vector<std::vector<std::string /*6.0*/>> requirements; /*3.0*/
      };
      Value value; /*3.2*/
    };
    std::vector<AdvancementMapping /*3.2*/> advancementMapping; /*3.0*/
    std::vector<std::string /*6.0*/> identifiers; /*3.0*/
    struct ProgressMapping {
      std::string key; /*6.0*/
      struct Value {
        std::string criterionIdentifier; /*6.0*/
        struct CriterionProgress {
          bool has; /*0.0*/
          int64_t value; /*0.0*/
        };
        CriterionProgress criterionProgress; /*3.2*/
      };
      std::vector<Value /*3.2*/> value; /*3.0*/
    };
    std::vector<ProgressMapping /*3.2*/> progressMapping; /*3.0*/
  };
  struct packet_block_break_animation {
    int entityId; /*0.0*/
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int8_t destroyStage; /*0.0*/
  };
  struct packet_tile_entity_data {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int action; /*0.0*/
    int8_t nbtData; /*0.0*/
  };
  struct packet_block_action {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    uint8_t byte1; /*0.0*/
    uint8_t byte2; /*0.0*/
    int blockId; /*0.0*/
  };
  struct packet_block_change {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int type; /*0.0*/
  };
  struct packet_boss_bar {
    uint64_t entityUUID; /*0.0*/
    int action; /*0.0*/
    std::string title; /*6.0*/
    float health; /*0.0*/
    int color; /*0.0*/
    int dividers; /*0.0*/
    uint8_t flags; /*0.0*/
  };
  struct packet_difficulty {
    uint8_t difficulty; /*0.0*/
    bool difficultyLocked; /*0.0*/
  };
  struct packet_tab_complete {
    int transactionId; /*0.0*/
    int start; /*0.0*/
    int length; /*0.0*/
    struct Matches {
      std::string match; /*6.0*/
      struct Tooltip {
        bool has; /*0.0*/
        std::string value; /*6.0*/
      };
      Tooltip tooltip; /*3.2*/
    };
    std::vector<Matches /*3.2*/> matches; /*3.0*/
  };
  struct packet_declare_commands {
    std::vector<pdef::pc1_18_play_toClient::command_node /*4.0*/> nodes; /*3.0*/
    int rootIndex; /*0.0*/
  };
  struct packet_face_player {
    int feet_eyes; /*0.0*/
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    bool isEntity; /*0.0*/
    int entityId; /*0.0*/
    std::string entity_feet_eyes; /*6.0*/
  };
  struct packet_nbt_query_response {
    int transactionId; /*0.0*/
    int8_t nbt; /*0.0*/
  };
  struct packet_chat {
    std::string message; /*6.0*/
    int8_t position; /*0.0*/
    uint64_t sender; /*0.0*/
  };
  struct packet_multi_block_change {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } chunkCoordinates; /*6.0*/
    bool notTrustEdges; /*0.0*/
    std::vector<int /*0.0*/> records; /*3.0*/
  };
  struct packet_close_window {
    uint8_t windowId; /*0.0*/
  };
  struct packet_open_window {
    int windowId; /*0.0*/
    int inventoryType; /*0.0*/
    std::string windowTitle; /*6.0*/
  };
  struct packet_window_items {
    uint8_t windowId; /*0.0*/
    int stateId; /*0.0*/
    std::vector<int8_t /*0.0*/> items; /*3.0*/
    int8_t carriedItem; /*0.0*/
  };
  struct packet_craft_progress_bar {
    uint8_t windowId; /*0.0*/
    int16_t property; /*0.0*/
    int16_t value; /*0.0*/
  };
  struct packet_set_slot {
    int8_t windowId; /*0.0*/
    int stateId; /*0.0*/
    int16_t slot; /*0.0*/
    int8_t item; /*0.0*/
  };
  struct packet_set_cooldown {
    int itemID; /*0.0*/
    int cooldownTicks; /*0.0*/
  };
  struct packet_custom_payload {
    std::string channel; /*6.0*/
    int8_t data; /*0.0*/
  };
  struct packet_named_sound_effect {
    std::string soundName; /*6.0*/
    int soundCategory; /*0.0*/
    int32_t x; /*0.0*/
    int32_t y; /*0.0*/
    int32_t z; /*0.0*/
    float volume; /*0.0*/
    float pitch; /*0.0*/
  };
  struct packet_kick_disconnect {
    std::string reason; /*6.0*/
  };
  struct packet_entity_status {
    int32_t entityId; /*0.0*/
    int8_t entityStatus; /*0.0*/
  };
  struct packet_explosion {
    float x; /*0.0*/
    float y; /*0.0*/
    float z; /*0.0*/
    float radius; /*0.0*/
    struct AffectedBlockOffsets {
      int8_t x; /*0.0*/
      int8_t y; /*0.0*/
      int8_t z; /*0.0*/
    };
    std::vector<AffectedBlockOffsets /*3.2*/> affectedBlockOffsets; /*3.0*/
    float playerMotionX; /*0.0*/
    float playerMotionY; /*0.0*/
    float playerMotionZ; /*0.0*/
  };
  struct packet_unload_chunk {
    int32_t chunkX; /*0.0*/
    int32_t chunkZ; /*0.0*/
  };
  struct packet_game_state_change {
    uint8_t reason; /*0.0*/
    float gameMode; /*0.0*/
  };
  struct packet_open_horse_window {
    uint8_t windowId; /*0.0*/
    int nbSlots; /*0.0*/
    int32_t entityId; /*0.0*/
  };
  struct packet_keep_alive {
    int64_t keepAliveId; /*0.0*/
  };
  struct packet_map_chunk {
    int32_t x; /*0.0*/
    int32_t z; /*0.0*/
    int8_t heightmaps; /*0.0*/
    std::vector<uint8_t> chunkData; /*6.0*/
    std::vector<pdef::pc1_18_play_toClient::chunkBlockEntity /*4.0*/> blockEntities; /*3.0*/
    bool trustEdges; /*0.0*/
    std::vector<int64_t /*0.0*/> skyLightMask; /*3.0*/
    std::vector<int64_t /*0.0*/> blockLightMask; /*3.0*/
    std::vector<int64_t /*0.0*/> emptySkyLightMask; /*3.0*/
    std::vector<int64_t /*0.0*/> emptyBlockLightMask; /*3.0*/
    std::vector<std::vector<uint8_t /*0.0*/>> skyLight; /*3.0*/
    std::vector<std::vector<uint8_t /*0.0*/>> blockLight; /*3.0*/
  };
  struct packet_world_event {
    int32_t effectId; /*0.0*/
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int32_t data; /*0.0*/
    bool global; /*0.0*/
  };
  struct packet_world_particles {
    int32_t particleId; /*0.0*/
    bool longDistance; /*0.0*/
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    float offsetX; /*0.0*/
    float offsetY; /*0.0*/
    float offsetZ; /*0.0*/
    float particleData; /*0.0*/
    int32_t particles; /*0.0*/
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
  struct packet_update_light {
    int chunkX; /*0.0*/
    int chunkZ; /*0.0*/
    bool trustEdges; /*0.0*/
    std::vector<int64_t /*0.0*/> skyLightMask; /*3.0*/
    std::vector<int64_t /*0.0*/> blockLightMask; /*3.0*/
    std::vector<int64_t /*0.0*/> emptySkyLightMask; /*3.0*/
    std::vector<int64_t /*0.0*/> emptyBlockLightMask; /*3.0*/
    std::vector<std::vector<uint8_t /*0.0*/>> skyLight; /*3.0*/
    std::vector<std::vector<uint8_t /*0.0*/>> blockLight; /*3.0*/
  };
  struct packet_login {
    int32_t entityId; /*0.0*/
    bool isHardcore; /*0.0*/
    uint8_t gameMode; /*0.0*/
    int8_t previousGameMode; /*0.0*/
    std::vector<std::string /*6.0*/> worldNames; /*3.0*/
    int8_t dimensionCodec; /*0.0*/
    int8_t dimension; /*0.0*/
    std::string worldName; /*6.0*/
    int64_t hashedSeed; /*0.0*/
    int maxPlayers; /*0.0*/
    int viewDistance; /*0.0*/
    int simulationDistance; /*0.0*/
    bool reducedDebugInfo; /*0.0*/
    bool enableRespawnScreen; /*0.0*/
    bool isDebug; /*0.0*/
    bool isFlat; /*0.0*/
  };
  struct packet_map {
    int itemDamage; /*0.0*/
    int8_t scale; /*0.0*/
    bool locked; /*0.0*/
    struct Icons {
      bool has; /*0.0*/
      struct Value {
        int type; /*0.0*/
        int8_t x; /*0.0*/
        int8_t z; /*0.0*/
        uint8_t direction; /*0.0*/
        struct DisplayName {
          bool has; /*0.0*/
          std::string value; /*6.0*/
        };
        DisplayName displayName; /*3.2*/
      };
      std::vector<Value /*3.2*/> value; /*3.0*/
    };
    Icons icons; /*3.2*/
    uint8_t columns; /*0.0*/
    uint8_t rows; /*0.0*/
    uint8_t x; /*0.0*/
    uint8_t y; /*0.0*/
    std::vector<uint8_t> data; /*6.0*/
  };
  struct packet_trade_list {
    int windowId; /*0.0*/
    struct Trades {
      int8_t inputItem1; /*0.0*/
      int8_t outputItem; /*0.0*/
      struct InputItem2 {
        bool has; /*0.0*/
        int8_t value; /*0.0*/
      };
      InputItem2 inputItem2; /*3.2*/
      bool tradeDisabled; /*0.0*/
      int32_t nbTradeUses; /*0.0*/
      int32_t maximumNbTradeUses; /*0.0*/
      int32_t xp; /*0.0*/
      int32_t specialPrice; /*0.0*/
      float priceMultiplier; /*0.0*/
      int32_t demand; /*0.0*/
    };
    std::vector<Trades /*3.2*/> trades; /*3.0*/
    int villagerLevel; /*0.0*/
    int experience; /*0.0*/
    bool isRegularVillager; /*0.0*/
    bool canRestock; /*0.0*/
  };
  struct packet_rel_entity_move {
    int entityId; /*0.0*/
    int16_t dX; /*0.0*/
    int16_t dY; /*0.0*/
    int16_t dZ; /*0.0*/
    bool onGround; /*0.0*/
  };
  struct packet_entity_move_look {
    int entityId; /*0.0*/
    int16_t dX; /*0.0*/
    int16_t dY; /*0.0*/
    int16_t dZ; /*0.0*/
    int8_t yaw; /*0.0*/
    int8_t pitch; /*0.0*/
    bool onGround; /*0.0*/
  };
  struct packet_entity_look {
    int entityId; /*0.0*/
    int8_t yaw; /*0.0*/
    int8_t pitch; /*0.0*/
    bool onGround; /*0.0*/
  };
  struct packet_vehicle_move {
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    float yaw; /*0.0*/
    float pitch; /*0.0*/
  };
  struct packet_open_book {
    int hand; /*0.0*/
  };
  struct packet_open_sign_entity {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
  };
  struct packet_craft_recipe_response {
    int8_t windowId; /*0.0*/
    std::string recipe; /*6.0*/
  };
  struct packet_abilities {
    int8_t flags; /*0.0*/
    float flyingSpeed; /*0.0*/
    float walkingSpeed; /*0.0*/
  };
  struct packet_end_combat_event {
    int duration; /*0.0*/
    int32_t entityId; /*0.0*/
  };
  struct packet_enter_combat_event {
  };
  struct packet_death_combat_event {
    int playerId; /*0.0*/
    int32_t entityId; /*0.0*/
    std::string message; /*6.0*/
  };
  struct packet_player_info {
    int action; /*0.0*/
    struct Data {
      uint64_t UUID; /*0.0*/
      std::string name; /*6.0*/
      struct Properties {
        std::string name; /*6.0*/
        std::string value; /*6.0*/
        struct Signature {
          bool has; /*0.0*/
          std::string value; /*6.0*/
        };
        Signature signature; /*3.2*/
      };
      std::vector<Properties /*3.2*/> properties; /*3.0*/
      int gamemode; /*0.0*/
      int ping; /*0.0*/
      struct DisplayName {
        bool has; /*0.0*/
        std::string value; /*6.0*/
      };
      std::optional<DisplayName> displayName; /*3.2*/
    };
    std::vector<Data /*3.2*/> data; /*3.0*/
  };
  struct packet_position {
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    float yaw; /*0.0*/
    float pitch; /*0.0*/
    int8_t flags; /*0.0*/
    int teleportId; /*0.0*/
    bool dismountVehicle; /*0.0*/
  };
  struct packet_unlock_recipes {
    int action; /*0.0*/
    bool craftingBookOpen; /*0.0*/
    bool filteringCraftable; /*0.0*/
    bool smeltingBookOpen; /*0.0*/
    bool filteringSmeltable; /*0.0*/
    bool blastFurnaceOpen; /*0.0*/
    bool filteringBlastFurnace; /*0.0*/
    bool smokerBookOpen; /*0.0*/
    bool filteringSmoker; /*0.0*/
    std::vector<std::string /*6.0*/> recipes1; /*3.0*/
    std::vector<std::string /*6.0*/> recipes2; /*3.0*/
  };
  struct packet_entity_destroy {
    std::vector<int /*0.0*/> entityIds; /*3.0*/
  };
  struct packet_remove_entity_effect {
    int entityId; /*0.0*/
    int8_t effectId; /*0.0*/
  };
  struct packet_resource_pack_send {
    std::string url; /*6.0*/
    std::string hash; /*6.0*/
    bool forced; /*0.0*/
    struct PromptMessage {
      bool has; /*0.0*/
      std::string value; /*6.0*/
    };
    PromptMessage promptMessage; /*3.2*/
  };
  struct packet_respawn {
    int8_t dimension; /*0.0*/
    std::string worldName; /*6.0*/
    int64_t hashedSeed; /*0.0*/
    uint8_t gamemode; /*0.0*/
    uint8_t previousGamemode; /*0.0*/
    bool isDebug; /*0.0*/
    bool isFlat; /*0.0*/
    bool copyMetadata; /*0.0*/
  };
  struct packet_entity_head_rotation {
    int entityId; /*0.0*/
    int8_t headYaw; /*0.0*/
  };
  struct packet_camera {
    int cameraId; /*0.0*/
  };
  struct packet_held_item_slot {
    int8_t slot; /*0.0*/
  };
  struct packet_update_view_position {
    int chunkX; /*0.0*/
    int chunkZ; /*0.0*/
  };
  struct packet_update_view_distance {
    int viewDistance; /*0.0*/
  };
  struct packet_scoreboard_display_objective {
    int8_t position; /*0.0*/
    std::string name; /*6.0*/
  };
  struct packet_entity_metadata {
    int entityId; /*0.0*/
    int8_t metadata; /*0.0*/
  };
  struct packet_attach_entity {
    int32_t entityId; /*0.0*/
    int32_t vehicleId; /*0.0*/
  };
  struct packet_entity_velocity {
    int entityId; /*0.0*/
    int16_t velocityX; /*0.0*/
    int16_t velocityY; /*0.0*/
    int16_t velocityZ; /*0.0*/
  };
  struct packet_entity_equipment {
    int entityId; /*0.0*/
    int8_t equipments; /*0.0*/
  };
  struct packet_experience {
    float experienceBar; /*0.0*/
    int level; /*0.0*/
    int totalExperience; /*0.0*/
  };
  struct packet_update_health {
    float health; /*0.0*/
    int food; /*0.0*/
    float foodSaturation; /*0.0*/
  };
  struct packet_scoreboard_objective {
    std::string name; /*6.0*/
    int8_t action; /*0.0*/
    std::string displayText; /*6.0*/
    int type; /*0.0*/
  };
  struct packet_set_passengers {
    int entityId; /*0.0*/
    std::vector<int /*0.0*/> passengers; /*3.0*/
  };
  struct packet_teams {
    std::string team; /*6.0*/
    int8_t mode; /*0.0*/
    std::string name; /*6.0*/
    int8_t friendlyFire; /*0.0*/
    std::string nameTagVisibility; /*6.0*/
    std::string collisionRule; /*6.0*/
    int formatting; /*0.0*/
    std::string prefix; /*6.0*/
    std::string suffix; /*6.0*/
    std::vector<std::string /*6.0*/> players; /*3.0*/
  };
  struct packet_scoreboard_score {
    std::string itemName; /*6.0*/
    int action; /*0.0*/
    std::string scoreName; /*6.0*/
    int value; /*0.0*/
  };
  struct packet_spawn_position {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    float angle; /*0.0*/
  };
  struct packet_update_time {
    int64_t age; /*0.0*/
    int64_t time; /*0.0*/
  };
  struct packet_entity_sound_effect {
    int soundId; /*0.0*/
    int soundCategory; /*0.0*/
    int entityId; /*0.0*/
    float volume; /*0.0*/
    float pitch; /*0.0*/
  };
  struct packet_stop_sound {
    int8_t flags; /*0.0*/
    int source; /*0.0*/
    std::string sound; /*6.0*/
  };
  struct packet_sound_effect {
    int soundId; /*0.0*/
    int soundCategory; /*0.0*/
    int32_t x; /*0.0*/
    int32_t y; /*0.0*/
    int32_t z; /*0.0*/
    float volume; /*0.0*/
    float pitch; /*0.0*/
  };
  struct packet_playerlist_header {
    std::string header; /*6.0*/
    std::string footer; /*6.0*/
  };
  struct packet_collect {
    int collectedEntityId; /*0.0*/
    int collectorEntityId; /*0.0*/
    int pickupItemCount; /*0.0*/
  };
  struct packet_entity_teleport {
    int entityId; /*0.0*/
    double x; /*0.0*/
    double y; /*0.0*/
    double z; /*0.0*/
    int8_t yaw; /*0.0*/
    int8_t pitch; /*0.0*/
    bool onGround; /*0.0*/
  };
  struct packet_entity_update_attributes {
    int entityId; /*0.0*/
    struct Properties {
      std::string key; /*6.0*/
      double value; /*0.0*/
      struct Modifiers {
        uint64_t uuid; /*0.0*/
        double amount; /*0.0*/
        int8_t operation; /*0.0*/
      };
      std::vector<Modifiers /*3.2*/> modifiers; /*3.0*/
    };
    std::vector<Properties /*3.2*/> properties; /*3.0*/
  };
  struct packet_entity_effect {
    int entityId; /*0.0*/
    int8_t effectId; /*0.0*/
    int8_t amplifier; /*0.0*/
    int duration; /*0.0*/
    int8_t hideParticles; /*0.0*/
  };
  struct packet_select_advancement_tab {
    struct Id {
      bool has; /*0.0*/
      std::string value; /*6.0*/
    };
    Id id; /*3.2*/
  };
  struct packet_declare_recipes {
    struct Recipes {
      std::string type; /*6.0*/
      std::string recipeId; /*6.0*/
      struct DataMinecraftCraftingShapeless {
        std::string group; /*6.0*/
        std::vector<std::vector<int8_t /*0.0*/> /*3.0*/> ingredients; /*3.0*/
        int8_t result; /*0.0*/
      };
      std::optional<DataMinecraftCraftingShapeless> data_minecraft_crafting_shapeless; /*3.2*/
      struct DataMinecraftCraftingShaped {
        int width; /*0.0*/
        int height; /*0.0*/
        std::string group; /*6.0*/
        std::vector<std::vector<std::vector<int8_t /*0.0*/> /*3.0*/>> ingredients; /*3.0*/
        int8_t result; /*0.0*/
      };
      std::optional<DataMinecraftCraftingShaped> data_minecraft_crafting_shaped; /*3.2*/
      struct DataMinecraftStonecutting {
        std::string group; /*6.0*/
        std::vector<int8_t /*0.0*/> ingredient; /*3.0*/
        int8_t result; /*0.0*/
      };
      std::optional<DataMinecraftStonecutting> data_minecraft_stonecutting; /*3.2*/
      struct DataMinecraftSmithing {
        std::vector<int8_t /*0.0*/> base; /*3.0*/
        std::vector<int8_t /*0.0*/> addition; /*3.0*/
        int8_t result; /*0.0*/
      };
      std::optional<DataMinecraftSmithing> data_minecraft_smithing; /*3.2*/
      std::optional<pdef::pc1_18_play_toClient::minecraft_smelting_format> data_minecraft_smelting_format; /*4.0*/
    };
    std::vector<Recipes /*3.2*/> recipes; /*3.0*/
  };
  struct packet_tags {
    struct Tags {
      std::string tagType; /*6.0*/
      std::vector<pdef::pc1_18_play_toClient::tags> tags; /*1.0*/
    };
    std::vector<Tags /*3.2*/> tags; /*3.0*/
  };
  struct packet_acknowledge_player_digging {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } location; /*6.0*/
    int block; /*0.0*/
    int status; /*0.0*/
    bool successful; /*0.0*/
  };
  struct packet_sculk_vibration_signal {
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } sourcePosition; /*6.0*/
    std::string destinationIdentifier; /*6.0*/
    int arrivalTicks; /*0.0*/
    struct { /*6.0*/
      int x = 0; /*6.0*/
      int z = 0; /*6.0*/
      int y = 0; /*6.0*/
    } destination_position; /*6.0*/
    int destination_varint; /*0.0*/
  };
  struct packet_clear_titles {
    bool reset; /*0.0*/
  };
  struct packet_initialize_world_border {
    double x; /*0.0*/
    double z; /*0.0*/
    double oldDiameter; /*0.0*/
    double newDiameter; /*0.0*/
    int speed; /*0.0*/
    int portalTeleportBoundary; /*0.0*/
    int warningBlocks; /*0.0*/
    int warningTime; /*0.0*/
  };
  struct packet_action_bar {
    std::string text; /*6.0*/
  };
  struct packet_world_border_center {
    double x; /*0.0*/
    double z; /*0.0*/
  };
  struct packet_world_border_lerp_size {
    double oldDiameter; /*0.0*/
    double newDiameter; /*0.0*/
    int speed; /*0.0*/
  };
  struct packet_world_border_size {
    double diameter; /*0.0*/
  };
  struct packet_world_border_warning_delay {
    int warningTime; /*0.0*/
  };
  struct packet_world_border_warning_reach {
    int warningBlocks; /*0.0*/
  };
  struct packet_ping {
    int32_t id; /*0.0*/
  };
  struct packet_set_title_subtitle {
    std::string text; /*6.0*/
  };
  struct packet_set_title_text {
    std::string text; /*6.0*/
  };
  struct packet_set_title_time {
    int32_t fadeIn; /*0.0*/
    int32_t stay; /*0.0*/
    int32_t fadeOut; /*0.0*/
  };
  struct packet_simulation_distance {
    int distance; /*0.0*/
  };
  struct packet {
    enum class Name : int {
      SpawnEntity = 0x00,
      SpawnEntityExperienceOrb = 0x01,
      SpawnEntityLiving = 0x02,
      SpawnEntityPainting = 0x03,
      NamedEntitySpawn = 0x04,
      SculkVibrationSignal = 0x05,
      Animation = 0x06,
      Statistics = 0x07,
      AcknowledgePlayerDigging = 0x08,
      BlockBreakAnimation = 0x09,
      TileEntityData = 0x0a,
      BlockAction = 0x0b,
      BlockChange = 0x0c,
      BossBar = 0x0d,
      Difficulty = 0x0e,
      Chat = 0x0f,
      ClearTitles = 0x10,
      TabComplete = 0x11,
      DeclareCommands = 0x12,
      CloseWindow = 0x13,
      WindowItems = 0x14,
      CraftProgressBar = 0x15,
      SetSlot = 0x16,
      SetCooldown = 0x17,
      CustomPayload = 0x18,
      NamedSoundEffect = 0x19,
      KickDisconnect = 0x1a,
      EntityStatus = 0x1b,
      Explosion = 0x1c,
      UnloadChunk = 0x1d,
      GameStateChange = 0x1e,
      OpenHorseWindow = 0x1f,
      InitializeWorldBorder = 0x20,
      KeepAlive = 0x21,
      MapChunk = 0x22,
      WorldEvent = 0x23,
      WorldParticles = 0x24,
      UpdateLight = 0x25,
      Login = 0x26,
      Map = 0x27,
      TradeList = 0x28,
      RelEntityMove = 0x29,
      EntityMoveLook = 0x2a,
      EntityLook = 0x2b,
      VehicleMove = 0x2c,
      OpenBook = 0x2d,
      OpenWindow = 0x2e,
      OpenSignEntity = 0x2f,
      Ping = 0x30,
      CraftRecipeResponse = 0x31,
      Abilities = 0x32,
      EndCombatEvent = 0x33,
      EnterCombatEvent = 0x34,
      DeathCombatEvent = 0x35,
      PlayerInfo = 0x36,
      FacePlayer = 0x37,
      Position = 0x38,
      UnlockRecipes = 0x39,
      EntityDestroy = 0x3a,
      RemoveEntityEffect = 0x3b,
      ResourcePackSend = 0x3c,
      Respawn = 0x3d,
      EntityHeadRotation = 0x3e,
      MultiBlockChange = 0x3f,
      SelectAdvancementTab = 0x40,
      ActionBar = 0x41,
      WorldBorderCenter = 0x42,
      WorldBorderLerpSize = 0x43,
      WorldBorderSize = 0x44,
      WorldBorderWarningDelay = 0x45,
      WorldBorderWarningReach = 0x46,
      Camera = 0x47,
      HeldItemSlot = 0x48,
      UpdateViewPosition = 0x49,
      UpdateViewDistance = 0x4a,
      SpawnPosition = 0x4b,
      ScoreboardDisplayObjective = 0x4c,
      EntityMetadata = 0x4d,
      AttachEntity = 0x4e,
      EntityVelocity = 0x4f,
      EntityEquipment = 0x50,
      Experience = 0x51,
      UpdateHealth = 0x52,
      ScoreboardObjective = 0x53,
      SetPassengers = 0x54,
      Teams = 0x55,
      ScoreboardScore = 0x56,
      SimulationDistance = 0x57,
      SetTitleSubtitle = 0x58,
      UpdateTime = 0x59,
      SetTitleText = 0x5a,
      SetTitleTime = 0x5b,
      EntitySoundEffect = 0x5c,
      SoundEffect = 0x5d,
      StopSound = 0x5e,
      PlayerlistHeader = 0x5f,
      NbtQueryResponse = 0x60,
      Collect = 0x61,
      EntityTeleport = 0x62,
      Advancements = 0x63,
      EntityUpdateAttributes = 0x64,
      EntityEffect = 0x65,
      DeclareRecipes = 0x66,
      Tags = 0x67,
    };
    Name name; /*3.2*/
    std::optional<pdef::pc1_18_play_toClient::packet_spawn_entity> params_packet_spawn_entity; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_spawn_entity_experience_orb> params_packet_spawn_entity_experience_orb; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_spawn_entity_living> params_packet_spawn_entity_living; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_spawn_entity_painting> params_packet_spawn_entity_painting; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_named_entity_spawn> params_packet_named_entity_spawn; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_animation> params_packet_animation; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_statistics> params_packet_statistics; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_advancements> params_packet_advancements; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_block_break_animation> params_packet_block_break_animation; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_tile_entity_data> params_packet_tile_entity_data; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_block_action> params_packet_block_action; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_block_change> params_packet_block_change; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_boss_bar> params_packet_boss_bar; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_difficulty> params_packet_difficulty; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_tab_complete> params_packet_tab_complete; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_declare_commands> params_packet_declare_commands; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_face_player> params_packet_face_player; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_nbt_query_response> params_packet_nbt_query_response; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_chat> params_packet_chat; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_multi_block_change> params_packet_multi_block_change; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_close_window> params_packet_close_window; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_open_window> params_packet_open_window; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_window_items> params_packet_window_items; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_craft_progress_bar> params_packet_craft_progress_bar; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_set_slot> params_packet_set_slot; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_set_cooldown> params_packet_set_cooldown; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_custom_payload> params_packet_custom_payload; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_named_sound_effect> params_packet_named_sound_effect; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_kick_disconnect> params_packet_kick_disconnect; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_status> params_packet_entity_status; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_explosion> params_packet_explosion; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_unload_chunk> params_packet_unload_chunk; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_game_state_change> params_packet_game_state_change; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_open_horse_window> params_packet_open_horse_window; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_keep_alive> params_packet_keep_alive; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_map_chunk> params_packet_map_chunk; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_world_event> params_packet_world_event; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_world_particles> params_packet_world_particles; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_update_light> params_packet_update_light; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_login> params_packet_login; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_map> params_packet_map; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_trade_list> params_packet_trade_list; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_rel_entity_move> params_packet_rel_entity_move; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_move_look> params_packet_entity_move_look; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_look> params_packet_entity_look; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_vehicle_move> params_packet_vehicle_move; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_open_book> params_packet_open_book; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_open_sign_entity> params_packet_open_sign_entity; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_craft_recipe_response> params_packet_craft_recipe_response; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_abilities> params_packet_abilities; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_end_combat_event> params_packet_end_combat_event; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_enter_combat_event> params_packet_enter_combat_event; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_death_combat_event> params_packet_death_combat_event; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_player_info> params_packet_player_info; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_position> params_packet_position; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_unlock_recipes> params_packet_unlock_recipes; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_destroy> params_packet_entity_destroy; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_remove_entity_effect> params_packet_remove_entity_effect; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_resource_pack_send> params_packet_resource_pack_send; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_respawn> params_packet_respawn; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_update_attributes> params_packet_entity_update_attributes; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_camera> params_packet_camera; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_held_item_slot> params_packet_held_item_slot; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_update_view_position> params_packet_update_view_position; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_update_view_distance> params_packet_update_view_distance; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_scoreboard_display_objective> params_packet_scoreboard_display_objective; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_metadata> params_packet_entity_metadata; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_attach_entity> params_packet_attach_entity; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_velocity> params_packet_entity_velocity; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_equipment> params_packet_entity_equipment; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_experience> params_packet_experience; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_update_health> params_packet_update_health; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_scoreboard_objective> params_packet_scoreboard_objective; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_set_passengers> params_packet_set_passengers; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_teams> params_packet_teams; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_scoreboard_score> params_packet_scoreboard_score; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_simulation_distance> params_packet_simulation_distance; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_spawn_position> params_packet_spawn_position; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_update_time> params_packet_update_time; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_sound_effect> params_packet_entity_sound_effect; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_stop_sound> params_packet_stop_sound; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_sound_effect> params_packet_sound_effect; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_playerlist_header> params_packet_playerlist_header; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_collect> params_packet_collect; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_teleport> params_packet_entity_teleport; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_head_rotation> params_packet_entity_head_rotation; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_entity_effect> params_packet_entity_effect; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_select_advancement_tab> params_packet_select_advancement_tab; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_declare_recipes> params_packet_declare_recipes; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_tags> params_packet_tags; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_acknowledge_player_digging> params_packet_acknowledge_player_digging; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_sculk_vibration_signal> params_packet_sculk_vibration_signal; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_clear_titles> params_packet_clear_titles; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_initialize_world_border> params_packet_initialize_world_border; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_action_bar> params_packet_action_bar; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_world_border_center> params_packet_world_border_center; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_world_border_lerp_size> params_packet_world_border_lerp_size; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_world_border_size> params_packet_world_border_size; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_world_border_warning_delay> params_packet_world_border_warning_delay; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_world_border_warning_reach> params_packet_world_border_warning_reach; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_ping> params_packet_ping; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_set_title_subtitle> params_packet_set_title_subtitle; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_set_title_text> params_packet_set_title_text; /*4.0*/
    std::optional<pdef::pc1_18_play_toClient::packet_set_title_time> params_packet_set_title_time; /*4.0*/
  };
}

namespace pdef::pc1_18_play_toClient::size {
size_t slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::slot &obj);
size_t particle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::particle &obj);
size_t minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toClient::minecraft_smelting_format &obj);
size_t tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::tags &obj);
size_t chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::chunkBlockEntity &obj);
size_t command_node(pdef::Stream &stream, const pdef::pc1_18_play_toClient::command_node &obj);
size_t packet_spawn_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity &obj);
size_t packet_spawn_entity_experience_orb(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_experience_orb &obj);
size_t packet_spawn_entity_living(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_living &obj);
size_t packet_spawn_entity_painting(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_painting &obj);
size_t packet_named_entity_spawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_entity_spawn &obj);
size_t packet_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_animation &obj);
size_t packet_statistics(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_statistics &obj);
size_t packet_advancements(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_advancements &obj);
size_t packet_block_break_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_break_animation &obj);
size_t packet_tile_entity_data(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tile_entity_data &obj);
size_t packet_block_action(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_action &obj);
size_t packet_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_change &obj);
size_t packet_boss_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_boss_bar &obj);
size_t packet_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_difficulty &obj);
size_t packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tab_complete &obj);
size_t packet_declare_commands(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_commands &obj);
size_t packet_face_player(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_face_player &obj);
size_t packet_nbt_query_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_nbt_query_response &obj);
size_t packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_chat &obj);
size_t packet_multi_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_multi_block_change &obj);
size_t packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_close_window &obj);
size_t packet_open_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_window &obj);
size_t packet_window_items(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_window_items &obj);
size_t packet_craft_progress_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_progress_bar &obj);
size_t packet_set_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_slot &obj);
size_t packet_set_cooldown(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_cooldown &obj);
size_t packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_custom_payload &obj);
size_t packet_named_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_sound_effect &obj);
size_t packet_kick_disconnect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_kick_disconnect &obj);
size_t packet_entity_status(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_status &obj);
size_t packet_explosion(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_explosion &obj);
size_t packet_unload_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unload_chunk &obj);
size_t packet_game_state_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_game_state_change &obj);
size_t packet_open_horse_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_horse_window &obj);
size_t packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_keep_alive &obj);
size_t packet_map_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map_chunk &obj);
size_t packet_world_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_event &obj);
size_t packet_world_particles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_particles &obj);
size_t packet_update_light(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_light &obj);
size_t packet_login(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_login &obj);
size_t packet_map(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map &obj);
size_t packet_trade_list(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_trade_list &obj);
size_t packet_rel_entity_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_rel_entity_move &obj);
size_t packet_entity_move_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_move_look &obj);
size_t packet_entity_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_look &obj);
size_t packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_vehicle_move &obj);
size_t packet_open_book(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_book &obj);
size_t packet_open_sign_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_sign_entity &obj);
size_t packet_craft_recipe_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_recipe_response &obj);
size_t packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_abilities &obj);
size_t packet_end_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_end_combat_event &obj);
size_t packet_enter_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_enter_combat_event &obj);
size_t packet_death_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_death_combat_event &obj);
size_t packet_player_info(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_player_info &obj);
size_t packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_position &obj);
size_t packet_unlock_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unlock_recipes &obj);
size_t packet_entity_destroy(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_destroy &obj);
size_t packet_remove_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_remove_entity_effect &obj);
size_t packet_resource_pack_send(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_resource_pack_send &obj);
size_t packet_respawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_respawn &obj);
size_t packet_entity_head_rotation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_head_rotation &obj);
size_t packet_camera(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_camera &obj);
size_t packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_held_item_slot &obj);
size_t packet_update_view_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_position &obj);
size_t packet_update_view_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_distance &obj);
size_t packet_scoreboard_display_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_display_objective &obj);
size_t packet_entity_metadata(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_metadata &obj);
size_t packet_attach_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_attach_entity &obj);
size_t packet_entity_velocity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_velocity &obj);
size_t packet_entity_equipment(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_equipment &obj);
size_t packet_experience(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_experience &obj);
size_t packet_update_health(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_health &obj);
size_t packet_scoreboard_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_objective &obj);
size_t packet_set_passengers(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_passengers &obj);
size_t packet_teams(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_teams &obj);
size_t packet_scoreboard_score(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_score &obj);
size_t packet_spawn_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_position &obj);
size_t packet_update_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_time &obj);
size_t packet_entity_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_sound_effect &obj);
size_t packet_stop_sound(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_stop_sound &obj);
size_t packet_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sound_effect &obj);
size_t packet_playerlist_header(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_playerlist_header &obj);
size_t packet_collect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_collect &obj);
size_t packet_entity_teleport(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_teleport &obj);
size_t packet_entity_update_attributes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_update_attributes &obj);
size_t packet_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_effect &obj);
size_t packet_select_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_select_advancement_tab &obj);
size_t packet_declare_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_recipes &obj);
size_t packet_tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tags &obj);
size_t packet_acknowledge_player_digging(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_acknowledge_player_digging &obj);
size_t packet_sculk_vibration_signal(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sculk_vibration_signal &obj);
size_t packet_clear_titles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_clear_titles &obj);
size_t packet_initialize_world_border(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_initialize_world_border &obj);
size_t packet_action_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_action_bar &obj);
size_t packet_world_border_center(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_center &obj);
size_t packet_world_border_lerp_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_lerp_size &obj);
size_t packet_world_border_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_size &obj);
size_t packet_world_border_warning_delay(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_delay &obj);
size_t packet_world_border_warning_reach(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_reach &obj);
size_t packet_ping(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_ping &obj);
size_t packet_set_title_subtitle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_subtitle &obj);
size_t packet_set_title_text(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_text &obj);
size_t packet_set_title_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_time &obj);
size_t packet_simulation_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_simulation_distance &obj);
size_t packet(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet &obj);
  size_t slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::slot &obj) {
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
  size_t particle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::particle &obj) {
    size_t len = 0;
    const int &particleId = obj.particleId; /*0.1*/
    if (particleId == 2) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 3) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 14) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_14); const pdef::pc1_18_play_toClient::particle::Data14 &v = *obj.data_14; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 15) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_15); const pdef::pc1_18_play_toClient::particle::Data15 &v = *obj.data_15; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 24) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 35) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_35); const pdef::pc1_18_play_toClient::particle::Data35 &v = *obj.data_35; /*8.6*/
        len += 1; /*0.2*/
    }
    else if (particleId == 36) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_36); const pdef::pc1_18_play_toClient::particle::Data36 &v = *obj.data_36; /*8.6*/
        len += 1; /*origin: bitfield*/ /*4.1*/
        len += stream.sizeOfVarInt(v.positionType.length());
        len += v.positionType.length(); /*positionType^: pstring*/ /*4.1*/
        const pdef::pc1_18_play_toClient::particle::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_play_toClient::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          len += 1; /*destination: bitfield*/ /*4.1*/
        }
        else if (positionType == pdef::pc1_18_play_toClient::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          len += stream.sizeOfVarInt(v.destination_varint); /*0.2*/
        }
        len += stream.sizeOfVarInt(v.ticks); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toClient::minecraft_smelting_format &obj) {
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
size_t tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::tags &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.tagName.length());
    len += obj.tagName.length(); /*tagName: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.entries.size()); /*1.3*/
    for (const auto &v2 : obj.entries) {
      len += stream.sizeOfVarInt(v2); /*0.2*/
    }
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::chunkBlockEntity &obj) {
    size_t len = 0;
    len += 1; /*_3: bitfield*/ /*4.1*/
    len += 2; /*0.2*/
    len += stream.sizeOfVarInt(obj.type); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t command_node(pdef::Stream &stream, const pdef::pc1_18_play_toClient::command_node &obj) {
    size_t len = 0;
    len += 1; /*flags^: bitfield*/ /*4.1*/
    const pdef::pc1_18_play_toClient::command_node::bitfield &flags = obj.flags; /*0.1*/
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
        EXPECT_OR_BAIL(obj.extraNodeData_1); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.6*/
        len += stream.sizeOfVarInt(v.name.length());
        len += v.name.length(); /*name: pstring*/ /*4.1*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
        EXPECT_OR_BAIL(obj.extraNodeData_2); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.6*/
        len += stream.sizeOfVarInt(v.name.length());
        len += v.name.length(); /*name: pstring*/ /*4.1*/
        len += stream.sizeOfVarInt(v.parser.length());
        len += v.parser.length(); /*parser^: pstring*/ /*4.1*/
        const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.1*/
        if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_float); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_double); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_integer); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 4; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_brigadier_long); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.6*/
            len += 1; /*flags^: bitfield*/ /*4.1*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
            if (flags.max_present == 1) { /*8.2*/
              len += 8; /*0.2*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          len += 1; /*properties: bitfield*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          len += 1; /*properties: bitfield*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_range); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.6*/
            len += 1; /*0.2*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_resource_or_tag_or_minecraft_resource); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.6*/
            len += stream.sizeOfVarInt(v.registry.length());
            len += v.registry.length(); /*registry: pstring*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
            EXPECT_OR_BAIL(v.properties_minecraft_resource_or_tag_or_minecraft_resource); const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.6*/
            len += stream.sizeOfVarInt(v.registry.length());
            len += v.registry.length(); /*registry: pstring*/ /*4.1*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          len += stream.sizeOfVarInt(v.suggestionType.length());
          len += v.suggestionType.length(); /*suggestionType: pstring*/ /*4.1*/
        }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spawn_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.type); /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 4; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spawn_entity_experience_orb(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_experience_orb &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spawn_entity_living(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_living &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.type); /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spawn_entity_painting(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_painting &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.title); /*0.2*/
    len += 1; /*location: bitfield*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_named_entity_spawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_entity_spawn &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_animation &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_statistics(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_statistics &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entries.size()); /*1.3*/
    for (const auto &v2 : obj.entries) { /*5.20*/
      len += stream.sizeOfVarInt(v2.categoryId); /*0.2*/
      len += stream.sizeOfVarInt(v2.statisticId); /*0.2*/
      len += stream.sizeOfVarInt(v2.value); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_advancements(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_advancements &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.advancementMapping.size()); /*1.3*/
    for (const auto &v2 : obj.advancementMapping) { /*5.20*/
      len += stream.sizeOfVarInt(v2.key.length());
      len += v2.key.length(); /*key: pstring*/ /*4.1*/
      const pdef::pc1_18_play_toClient::packet_advancements::AdvancementMapping::Value &v = v2.value; /*["packet_advancements","AdvancementMapping"]*/ /*7.4*/
    }
    len += stream.sizeOfVarInt(obj.identifiers.size()); /*1.3*/
    for (const auto &v2 : obj.identifiers) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += stream.sizeOfVarInt(obj.progressMapping.size()); /*1.3*/
    for (const auto &v2 : obj.progressMapping) { /*5.20*/
      len += stream.sizeOfVarInt(v2.key.length());
      len += v2.key.length(); /*key: pstring*/ /*4.1*/
      len += stream.sizeOfVarInt(v2.value.size()); /*1.3*/
      for (const auto &v3 : v2.value) { /*5.20*/
        len += stream.sizeOfVarInt(v3.criterionIdentifier.length());
        len += v3.criterionIdentifier.length(); /*criterionIdentifier: pstring*/ /*4.1*/
        const pdef::pc1_18_play_toClient::packet_advancements::ProgressMapping::Value::CriterionProgress &v = v3.criterionProgress; /*["packet_advancements","ProgressMapping","Value"]*/ /*7.4*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_break_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_break_animation &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*location: bitfield*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_tile_entity_data(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tile_entity_data &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.action); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_action(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_action &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.blockId); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_change &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.type); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_boss_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_boss_bar &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    const int &action = obj.action; /*0.1*/
    if (action == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.title.length());
      len += obj.title.length(); /*title: pstring*/ /*4.1*/
    }
    else if (action == 3) { /*8.2*/
      len += stream.sizeOfVarInt(obj.title.length());
      len += obj.title.length(); /*title: pstring*/ /*4.1*/
    }
    if (action == 0) { /*8.2*/
      len += 4; /*0.2*/
    }
    else if (action == 2) { /*8.2*/
      len += 4; /*0.2*/
    }
    if (action == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.color); /*0.2*/
    }
    else if (action == 4) { /*8.2*/
      len += stream.sizeOfVarInt(obj.color); /*0.2*/
    }
    if (action == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.dividers); /*0.2*/
    }
    else if (action == 4) { /*8.2*/
      len += stream.sizeOfVarInt(obj.dividers); /*0.2*/
    }
    if (action == 0) { /*8.2*/
      len += 1; /*0.2*/
    }
    else if (action == 5) { /*8.2*/
      len += 1; /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_difficulty &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tab_complete &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.transactionId); /*0.2*/
    len += stream.sizeOfVarInt(obj.start); /*0.2*/
    len += stream.sizeOfVarInt(obj.length); /*0.2*/
    len += stream.sizeOfVarInt(obj.matches.size()); /*1.3*/
    for (const auto &v2 : obj.matches) { /*5.20*/
      len += stream.sizeOfVarInt(v2.match.length());
      len += v2.match.length(); /*match: pstring*/ /*4.1*/
      const pdef::pc1_18_play_toClient::packet_tab_complete::Matches::Tooltip &v = v2.tooltip; /*["packet_tab_complete","Matches"]*/ /*7.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_declare_commands(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_commands &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.nodes.size()); /*1.3*/
    for (const auto &v2 : obj.nodes) {
      size_t len_0 = pdef::pc1_18_play_toClient::size::command_node(stream, v2); EXPECT_OR_BAIL(len_0); len += len_0; /**/ /*4.4*/
    }
    len += stream.sizeOfVarInt(obj.rootIndex); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_face_player(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_face_player &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.feet_eyes); /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    const bool &isEntity = obj.isEntity; /*0.1*/
    if (isEntity == true) { /*8.1*/
      len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    }
    if (isEntity == true) { /*8.1*/
      len += stream.sizeOfVarInt(obj.entity_feet_eyes.length());
      len += obj.entity_feet_eyes.length(); /*entity_feet_eyes: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_nbt_query_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_nbt_query_response &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.transactionId); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_chat &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.message.length());
    len += obj.message.length(); /*message: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_multi_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_multi_block_change &obj) {
    size_t len = 0;
    len += 1; /*chunkCoordinates: bitfield*/ /*4.1*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.records.size()); /*1.3*/
    for (const auto &v2 : obj.records) {
      len += stream.sizeOfVarInt(v2); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_close_window &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_open_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_window &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.windowId); /*0.2*/
    len += stream.sizeOfVarInt(obj.inventoryType); /*0.2*/
    len += stream.sizeOfVarInt(obj.windowTitle.length());
    len += obj.windowTitle.length(); /*windowTitle: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_window_items(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_window_items &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.stateId); /*0.2*/
    len += stream.sizeOfVarInt(obj.items.size()); /*1.3*/
    for (const auto &v2 : obj.items) {
      len += 1; /*0.2*/
    }
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_craft_progress_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_progress_bar &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_slot &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.stateId); /*0.2*/
    len += 2; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_cooldown(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_cooldown &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.itemID); /*0.2*/
    len += stream.sizeOfVarInt(obj.cooldownTicks); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_custom_payload &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.channel.length());
    len += obj.channel.length(); /*channel: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_named_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_sound_effect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.soundName.length());
    len += obj.soundName.length(); /*soundName: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.soundCategory); /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_kick_disconnect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_kick_disconnect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.reason.length());
    len += obj.reason.length(); /*reason: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_status(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_status &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_explosion(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_explosion &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.affectedBlockOffsets.size()); /*1.3*/
    for (const auto &v2 : obj.affectedBlockOffsets) { /*5.20*/
      len += 1; /*0.2*/
      len += 1; /*0.2*/
      len += 1; /*0.2*/
    }
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_unload_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unload_chunk &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_game_state_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_game_state_change &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_open_horse_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_horse_window &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.nbSlots); /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_keep_alive &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_map_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map_chunk &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.chunkData.size());
    len += obj.chunkData.size(); /*chunkData: buffer*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.blockEntities.size()); /*1.3*/
    for (const auto &v2 : obj.blockEntities) {
      size_t len_1 = pdef::pc1_18_play_toClient::size::chunkBlockEntity(stream, v2); EXPECT_OR_BAIL(len_1); len += len_1; /**/ /*4.4*/
    }
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.skyLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.skyLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.blockLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.blockLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.emptySkyLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.emptySkyLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.emptyBlockLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.emptyBlockLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.skyLight.size()); /*1.3*/
    for (const auto &v : obj.skyLight) { /*5.1*/
      len += stream.sizeOfVarInt(obj.skyLight.size()); /*5.6*/
      for (const auto &v : v) { /*5.10*/
        len += 1; /*5.12*/
      }
    }
    len += stream.sizeOfVarInt(obj.blockLight.size()); /*1.3*/
    for (const auto &v : obj.blockLight) { /*5.1*/
      len += stream.sizeOfVarInt(obj.blockLight.size()); /*5.6*/
      for (const auto &v : v) { /*5.10*/
        len += 1; /*5.12*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_world_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_event &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 1; /*location: bitfield*/ /*4.1*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_world_particles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_particles &obj) {
    size_t len = 0;
    const int32_t &particleId = obj.particleId; /*0.1*/
    len += 1; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    if (particleId == 2) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 3) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 14) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_14); const pdef::pc1_18_play_toClient::packet_world_particles::Data14 &v = *obj.data_14; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 15) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_15); const pdef::pc1_18_play_toClient::packet_world_particles::Data15 &v = *obj.data_15; /*8.6*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
        len += 4; /*0.2*/
    }
    else if (particleId == 24) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_2_or_3_or_24); const pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.6*/
        len += stream.sizeOfVarInt(v.blockState); /*0.2*/
    }
    else if (particleId == 35) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_35); const pdef::pc1_18_play_toClient::packet_world_particles::Data35 &v = *obj.data_35; /*8.6*/
        len += 1; /*0.2*/
    }
    else if (particleId == 36) { /*8.2*/
        EXPECT_OR_BAIL(obj.data_36); const pdef::pc1_18_play_toClient::packet_world_particles::Data36 &v = *obj.data_36; /*8.6*/
        len += 1; /*origin: bitfield*/ /*4.1*/
        len += stream.sizeOfVarInt(v.positionType.length());
        len += v.positionType.length(); /*positionType^: pstring*/ /*4.1*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_play_toClient::packet_world_particles::Data36::PositionType::MinecraftBlock) { /*8.5*/
          len += 1; /*destination: bitfield*/ /*4.1*/
        }
        else if (positionType == pdef::pc1_18_play_toClient::packet_world_particles::Data36::PositionType::MinecraftEntity) { /*8.5*/
          len += stream.sizeOfVarInt(v.destination_varint); /*0.2*/
        }
        len += stream.sizeOfVarInt(v.ticks); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_light(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_light &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.chunkX); /*0.2*/
    len += stream.sizeOfVarInt(obj.chunkZ); /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.skyLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.skyLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.blockLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.blockLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.emptySkyLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.emptySkyLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.emptyBlockLightMask.size()); /*1.3*/
    for (const auto &v2 : obj.emptyBlockLightMask) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.skyLight.size()); /*1.3*/
    for (const auto &v : obj.skyLight) { /*5.1*/
      len += stream.sizeOfVarInt(obj.skyLight.size()); /*5.6*/
      for (const auto &v : v) { /*5.10*/
        len += 1; /*5.12*/
      }
    }
    len += stream.sizeOfVarInt(obj.blockLight.size()); /*1.3*/
    for (const auto &v : obj.blockLight) { /*5.1*/
      len += stream.sizeOfVarInt(obj.blockLight.size()); /*5.6*/
      for (const auto &v : v) { /*5.10*/
        len += 1; /*5.12*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_login(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_login &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.worldNames.size()); /*1.3*/
    for (const auto &v2 : obj.worldNames) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.worldName.length());
    len += obj.worldName.length(); /*worldName: pstring*/ /*4.1*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.maxPlayers); /*0.2*/
    len += stream.sizeOfVarInt(obj.viewDistance); /*0.2*/
    len += stream.sizeOfVarInt(obj.simulationDistance); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_map(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.itemDamage); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    const pdef::pc1_18_play_toClient::packet_map::Icons &v = obj.icons; /*["packet_map"]*/ /*7.4*/
    const uint8_t &columns = obj.columns; /*0.1*/
    if (columns == 0) { /*8.2*/
    }
    else {
      len += 1; /*0.2*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      len += 1; /*0.2*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      len += 1; /*0.2*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      len += stream.sizeOfVarInt(obj.data.size());
      len += obj.data.size(); /*data: buffer*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_trade_list(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_trade_list &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.windowId); /*0.2*/
    len += 1; /*1.3*/
    for (const auto &v2 : obj.trades) { /*5.20*/
      len += 1; /*0.2*/
      len += 1; /*0.2*/
      const pdef::pc1_18_play_toClient::packet_trade_list::Trades::InputItem2 &v = v2.inputItem2; /*["packet_trade_list","Trades"]*/ /*7.4*/
      len += 1; /*0.2*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.villagerLevel); /*0.2*/
    len += stream.sizeOfVarInt(obj.experience); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_rel_entity_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_rel_entity_move &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_move_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_move_look &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_look &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_vehicle_move &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_open_book(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_book &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.hand); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_open_sign_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_sign_entity &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_craft_recipe_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_recipe_response &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.recipe.length());
    len += obj.recipe.length(); /*recipe: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_abilities &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_end_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_end_combat_event &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.duration); /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_enter_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_enter_combat_event &obj) {
    size_t len = 0;
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_death_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_death_combat_event &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.playerId); /*0.2*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.message.length());
    len += obj.message.length(); /*message: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_info(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_player_info &obj) {
    size_t len = 0;
    const int &action = obj.action; /*0.1*/
    len += stream.sizeOfVarInt(obj.data.size()); /*1.3*/
    for (const auto &v2 : obj.data) { /*5.20*/
      len += 8; /*0.2*/
      if (action == 0) { /*8.2*/
        len += stream.sizeOfVarInt(v2.name.length());
        len += v2.name.length(); /*name: pstring*/ /*4.1*/
      }
      if (action == 0) { /*8.2*/
        len += stream.sizeOfVarInt(v2.properties.size()); /*1.3*/
        for (const auto &v4 : v2.properties) { /*5.20*/
          len += stream.sizeOfVarInt(v4.name.length());
          len += v4.name.length(); /*name: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v4.value.length());
          len += v4.value.length(); /*value: pstring*/ /*4.1*/
          const pdef::pc1_18_play_toClient::packet_player_info::Data::Properties::Signature &v = v4.signature; /*["packet_player_info","Data","Properties"]*/ /*7.4*/
        }
      }
      if (action == 0) { /*8.2*/
        len += stream.sizeOfVarInt(v2.gamemode); /*0.2*/
      }
      else if (action == 1) { /*8.2*/
        len += stream.sizeOfVarInt(v2.gamemode); /*0.2*/
      }
      if (action == 0) { /*8.2*/
        len += stream.sizeOfVarInt(v2.ping); /*0.2*/
      }
      else if (action == 2) { /*8.2*/
        len += stream.sizeOfVarInt(v2.ping); /*0.2*/
      }
      if (action == 0) { /*8.2*/
          EXPECT_OR_BAIL(v2.displayName); const pdef::pc1_18_play_toClient::packet_player_info::Data::DisplayName &v = *v2.displayName; /*8.6*/
          const bool &has = v2.has; /*0.1*/
          if (has == true) { /*8.1*/
            len += stream.sizeOfVarInt(v2.value.length());
            len += v2.value.length(); /*value: pstring*/ /*4.1*/
          }
      }
      else if (action == 3) { /*8.2*/
          EXPECT_OR_BAIL(v2.displayName); const pdef::pc1_18_play_toClient::packet_player_info::Data::DisplayName &v = *v2.displayName; /*8.6*/
          const bool &has = v2.has; /*0.1*/
          if (has == true) { /*8.1*/
            len += stream.sizeOfVarInt(v2.value.length());
            len += v2.value.length(); /*value: pstring*/ /*4.1*/
          }
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_position &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.teleportId); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_unlock_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unlock_recipes &obj) {
    size_t len = 0;
    const int &action = obj.action; /*0.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.recipes1.size()); /*1.3*/
    for (const auto &v2 : obj.recipes1) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    if (action == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.recipes2.size()); /*1.3*/
      for (const auto &v3 : obj.recipes2) {
        len += stream.sizeOfVarInt(v3.length());
        len += v3.length(); /*: pstring*/ /*4.1*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_destroy(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_destroy &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityIds.size()); /*1.3*/
    for (const auto &v2 : obj.entityIds) {
      len += stream.sizeOfVarInt(v2); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_remove_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_remove_entity_effect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_pack_send(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_resource_pack_send &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.url.length());
    len += obj.url.length(); /*url: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.hash.length());
    len += obj.hash.length(); /*hash: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    const pdef::pc1_18_play_toClient::packet_resource_pack_send::PromptMessage &v = obj.promptMessage; /*["packet_resource_pack_send"]*/ /*7.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_respawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_respawn &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.worldName.length());
    len += obj.worldName.length(); /*worldName: pstring*/ /*4.1*/
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_head_rotation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_head_rotation &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_camera(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_camera &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.cameraId); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_held_item_slot &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_view_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_position &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.chunkX); /*0.2*/
    len += stream.sizeOfVarInt(obj.chunkZ); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_view_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_distance &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.viewDistance); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_scoreboard_display_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_display_objective &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_metadata(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_metadata &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_attach_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_attach_entity &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_velocity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_velocity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_equipment(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_equipment &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_experience(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_experience &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.level); /*0.2*/
    len += stream.sizeOfVarInt(obj.totalExperience); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_health(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_health &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.food); /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_scoreboard_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_objective &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    const int8_t &action = obj.action; /*0.1*/
    if (action == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.displayText.length());
      len += obj.displayText.length(); /*displayText: pstring*/ /*4.1*/
    }
    else if (action == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.displayText.length());
      len += obj.displayText.length(); /*displayText: pstring*/ /*4.1*/
    }
    if (action == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.type); /*0.2*/
    }
    else if (action == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.type); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_passengers(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_passengers &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += stream.sizeOfVarInt(obj.passengers.size()); /*1.3*/
    for (const auto &v2 : obj.passengers) {
      len += stream.sizeOfVarInt(v2); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_teams(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_teams &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.team.length());
    len += obj.team.length(); /*team: pstring*/ /*4.1*/
    const int8_t &mode = obj.mode; /*0.1*/
    if (mode == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.name.length());
      len += obj.name.length(); /*name: pstring*/ /*4.1*/
    }
    else if (mode == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.name.length());
      len += obj.name.length(); /*name: pstring*/ /*4.1*/
    }
    if (mode == 0) { /*8.2*/
      len += 1; /*0.2*/
    }
    else if (mode == 2) { /*8.2*/
      len += 1; /*0.2*/
    }
    if (mode == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.nameTagVisibility.length());
      len += obj.nameTagVisibility.length(); /*nameTagVisibility: pstring*/ /*4.1*/
    }
    else if (mode == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.nameTagVisibility.length());
      len += obj.nameTagVisibility.length(); /*nameTagVisibility: pstring*/ /*4.1*/
    }
    if (mode == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.collisionRule.length());
      len += obj.collisionRule.length(); /*collisionRule: pstring*/ /*4.1*/
    }
    else if (mode == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.collisionRule.length());
      len += obj.collisionRule.length(); /*collisionRule: pstring*/ /*4.1*/
    }
    if (mode == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.formatting); /*0.2*/
    }
    else if (mode == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.formatting); /*0.2*/
    }
    if (mode == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.prefix.length());
      len += obj.prefix.length(); /*prefix: pstring*/ /*4.1*/
    }
    else if (mode == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.prefix.length());
      len += obj.prefix.length(); /*prefix: pstring*/ /*4.1*/
    }
    if (mode == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.suffix.length());
      len += obj.suffix.length(); /*suffix: pstring*/ /*4.1*/
    }
    else if (mode == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.suffix.length());
      len += obj.suffix.length(); /*suffix: pstring*/ /*4.1*/
    }
    if (mode == 0) { /*8.2*/
      len += stream.sizeOfVarInt(obj.players.size()); /*1.3*/
      for (const auto &v3 : obj.players) {
        len += stream.sizeOfVarInt(v3.length());
        len += v3.length(); /*: pstring*/ /*4.1*/
      }
    }
    else if (mode == 3) { /*8.2*/
      len += stream.sizeOfVarInt(obj.players.size()); /*1.3*/
      for (const auto &v3 : obj.players) {
        len += stream.sizeOfVarInt(v3.length());
        len += v3.length(); /*: pstring*/ /*4.1*/
      }
    }
    else if (mode == 4) { /*8.2*/
      len += stream.sizeOfVarInt(obj.players.size()); /*1.3*/
      for (const auto &v3 : obj.players) {
        len += stream.sizeOfVarInt(v3.length());
        len += v3.length(); /*: pstring*/ /*4.1*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_scoreboard_score(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_score &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.itemName.length());
    len += obj.itemName.length(); /*itemName: pstring*/ /*4.1*/
    const int &action = obj.action; /*0.1*/
    len += stream.sizeOfVarInt(obj.scoreName.length());
    len += obj.scoreName.length(); /*scoreName: pstring*/ /*4.1*/
    if (action == 1) { /*8.2*/
    }
    else {
      len += stream.sizeOfVarInt(obj.value); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spawn_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_position &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_time &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_sound_effect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.soundId); /*0.2*/
    len += stream.sizeOfVarInt(obj.soundCategory); /*0.2*/
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_stop_sound(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_stop_sound &obj) {
    size_t len = 0;
    const int8_t &flags = obj.flags; /*0.1*/
    if (flags == 1) { /*8.2*/
      len += stream.sizeOfVarInt(obj.source); /*0.2*/
    }
    else if (flags == 3) { /*8.2*/
      len += stream.sizeOfVarInt(obj.source); /*0.2*/
    }
    if (flags == 2) { /*8.2*/
      len += stream.sizeOfVarInt(obj.sound.length());
      len += obj.sound.length(); /*sound: pstring*/ /*4.1*/
    }
    else if (flags == 3) { /*8.2*/
      len += stream.sizeOfVarInt(obj.sound.length());
      len += obj.sound.length(); /*sound: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sound_effect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.soundId); /*0.2*/
    len += stream.sizeOfVarInt(obj.soundCategory); /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_playerlist_header(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_playerlist_header &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.header.length());
    len += obj.header.length(); /*header: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.footer.length());
    len += obj.footer.length(); /*footer: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_collect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_collect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.collectedEntityId); /*0.2*/
    len += stream.sizeOfVarInt(obj.collectorEntityId); /*0.2*/
    len += stream.sizeOfVarInt(obj.pickupItemCount); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_teleport(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_teleport &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_update_attributes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_update_attributes &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += stream.sizeOfVarInt(obj.properties.size()); /*1.3*/
    for (const auto &v2 : obj.properties) { /*5.20*/
      len += stream.sizeOfVarInt(v2.key.length());
      len += v2.key.length(); /*key: pstring*/ /*4.1*/
      len += 8; /*0.2*/
      len += stream.sizeOfVarInt(v2.modifiers.size()); /*1.3*/
      for (const auto &v3 : v2.modifiers) { /*5.20*/
        len += 8; /*0.2*/
        len += 8; /*0.2*/
        len += 1; /*0.2*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_effect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entityId); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.duration); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_select_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_select_advancement_tab &obj) {
    size_t len = 0;
    const pdef::pc1_18_play_toClient::packet_select_advancement_tab::Id &v = obj.id; /*["packet_select_advancement_tab"]*/ /*7.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_declare_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_recipes &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.recipes.size()); /*1.3*/
    for (const auto &v2 : obj.recipes) { /*5.20*/
      len += stream.sizeOfVarInt(v2.type.length());
      len += v2.type.length(); /*type^: pstring*/ /*4.1*/
      const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::pstring &type = v2.type; /*0.1*/
      len += stream.sizeOfVarInt(v2.recipeId.length());
      len += v2.recipeId.length(); /*recipeId: pstring*/ /*4.1*/
      if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingShapeless) { /*8.5*/
          EXPECT_OR_BAIL(v2.data_minecraft_crafting_shapeless); const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftCraftingShapeless &v = *v2.data_minecraft_crafting_shapeless; /*8.6*/
          len += stream.sizeOfVarInt(v2.group.length());
          len += v2.group.length(); /*group: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v2.ingredients.size()); /*1.3*/
          for (const auto &v5 : v2.ingredients) {
            len += stream.sizeOfVarInt(v5.size()); /*1.3*/
            for (const auto &v6 : v5) {
              len += 1; /*0.2*/
            }
          }
          len += 1; /*0.2*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingShaped) { /*8.5*/
          EXPECT_OR_BAIL(v2.data_minecraft_crafting_shaped); const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftCraftingShaped &v = *v2.data_minecraft_crafting_shaped; /*8.6*/
          const int &width = v2.width; /*0.1*/
          const int &height = v2.height; /*0.1*/
          len += stream.sizeOfVarInt(v2.group.length());
          len += v2.group.length(); /*group: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(width); /*1.1*/
          for (const auto &v : v2.ingredients) { /*5.1*/
            len += stream.sizeOfVarInt(height); /*5.3*/
            for (const auto &v : v) { /*5.10*/
              size_t len_2 = pdef::pc1_18_play_toClient::size::ingredient(stream, v); EXPECT_OR_BAIL(len_2); len += len_2; /*5.12*/
            }
          }
          len += 1; /*0.2*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialArmordye) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBookcloning) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialMapcloning) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialMapextending) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkRocket) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkStar) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkStarFade) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialRepairitem) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialTippedarrow) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBannerduplicate) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBanneraddpattern) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialShielddecoration) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialShulkerboxcoloring) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialSuspiciousstew) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmelting) { /*8.5*/
        EXPECT_OR_BAIL(v2.data_minecraft_smelting_format); size_t len_3 = pdef::pc1_18_play_toClient::size::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); EXPECT_OR_BAIL(len_3); len += len_3; /*data_minecraft_smelting_format*/ /*4.4*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftBlasting) { /*8.5*/
        EXPECT_OR_BAIL(v2.data_minecraft_smelting_format); size_t len_4 = pdef::pc1_18_play_toClient::size::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); EXPECT_OR_BAIL(len_4); len += len_4; /*data_minecraft_smelting_format*/ /*4.4*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmoking) { /*8.5*/
        EXPECT_OR_BAIL(v2.data_minecraft_smelting_format); size_t len_5 = pdef::pc1_18_play_toClient::size::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); EXPECT_OR_BAIL(len_5); len += len_5; /*data_minecraft_smelting_format*/ /*4.4*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCampfireCooking) { /*8.5*/
        EXPECT_OR_BAIL(v2.data_minecraft_smelting_format); size_t len_6 = pdef::pc1_18_play_toClient::size::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); EXPECT_OR_BAIL(len_6); len += len_6; /*data_minecraft_smelting_format*/ /*4.4*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftStonecutting) { /*8.5*/
          EXPECT_OR_BAIL(v2.data_minecraft_stonecutting); const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftStonecutting &v = *v2.data_minecraft_stonecutting; /*8.6*/
          len += stream.sizeOfVarInt(v2.group.length());
          len += v2.group.length(); /*group: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v2.ingredient.size()); /*1.3*/
          for (const auto &v5 : v2.ingredient) {
            len += 1; /*0.2*/
          }
          len += 1; /*0.2*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmithing) { /*8.5*/
          EXPECT_OR_BAIL(v2.data_minecraft_smithing); const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftSmithing &v = *v2.data_minecraft_smithing; /*8.6*/
          len += stream.sizeOfVarInt(v2.base.size()); /*1.3*/
          for (const auto &v5 : v2.base) {
            len += 1; /*0.2*/
          }
          len += stream.sizeOfVarInt(v2.addition.size()); /*1.3*/
          for (const auto &v5 : v2.addition) {
            len += 1; /*0.2*/
          }
          len += 1; /*0.2*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tags &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.tags.size()); /*1.3*/
    for (const auto &v2 : obj.tags) { /*5.20*/
      len += stream.sizeOfVarInt(v2.tagType.length());
      len += v2.tagType.length(); /*tagType: pstring*/ /*4.1*/
      len += stream.sizeOfVarInt(v2.tags.size()); /*2.4*/
      for (const auto &v : v2.tags) { size_t len_7 = pdef::pc1_18_play_toClient::size::tags(stream, v); EXPECT_OR_BAIL(len_7); len += len_7; } /*2.5*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_acknowledge_player_digging(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_acknowledge_player_digging &obj) {
    size_t len = 0;
    len += 1; /*location: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.block); /*0.2*/
    len += stream.sizeOfVarInt(obj.status); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_sculk_vibration_signal(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sculk_vibration_signal &obj) {
    size_t len = 0;
    len += 1; /*sourcePosition: bitfield*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.destinationIdentifier.length());
    len += obj.destinationIdentifier.length(); /*destinationIdentifier^: pstring*/ /*4.1*/
    const pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::pstring &destinationIdentifier = obj.destinationIdentifier; /*0.1*/
    if (destinationIdentifier == pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::DestinationIdentifier::Block) { /*8.5*/
      len += 1; /*destination: bitfield*/ /*4.1*/
    }
    else if (destinationIdentifier == pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::DestinationIdentifier::EntityId) { /*8.5*/
      len += stream.sizeOfVarInt(obj.destination_varint); /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.arrivalTicks); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_clear_titles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_clear_titles &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_initialize_world_border(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_initialize_world_border &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.speed); /*0.2*/
    len += stream.sizeOfVarInt(obj.portalTeleportBoundary); /*0.2*/
    len += stream.sizeOfVarInt(obj.warningBlocks); /*0.2*/
    len += stream.sizeOfVarInt(obj.warningTime); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_action_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_action_bar &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.text.length());
    len += obj.text.length(); /*text: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_world_border_center(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_center &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_world_border_lerp_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_lerp_size &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.speed); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_world_border_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_size &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_world_border_warning_delay(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_delay &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.warningTime); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_world_border_warning_reach(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_reach &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.warningBlocks); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_ping(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_ping &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_title_subtitle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_subtitle &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.text.length());
    len += obj.text.length(); /*text: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_title_text(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_text &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.text.length());
    len += obj.text.length(); /*text: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_title_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_time &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_simulation_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_simulation_distance &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.distance); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet &obj) {
    size_t len = 0;
    const pdef::pc1_18_play_toClient::packet::Name &name = obj.name; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.name); /*name^: varint*/ /*7.0*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spawn_entity); size_t len_8 = pdef::pc1_18_play_toClient::size::packet_spawn_entity(stream, *obj.params_packet_spawn_entity); EXPECT_OR_BAIL(len_8); len += len_8; /*params_packet_spawn_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityExperienceOrb: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spawn_entity_experience_orb); size_t len_9 = pdef::pc1_18_play_toClient::size::packet_spawn_entity_experience_orb(stream, *obj.params_packet_spawn_entity_experience_orb); EXPECT_OR_BAIL(len_9); len += len_9; /*params_packet_spawn_entity_experience_orb*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityLiving: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spawn_entity_living); size_t len_10 = pdef::pc1_18_play_toClient::size::packet_spawn_entity_living(stream, *obj.params_packet_spawn_entity_living); EXPECT_OR_BAIL(len_10); len += len_10; /*params_packet_spawn_entity_living*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityPainting: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spawn_entity_painting); size_t len_11 = pdef::pc1_18_play_toClient::size::packet_spawn_entity_painting(stream, *obj.params_packet_spawn_entity_painting); EXPECT_OR_BAIL(len_11); len += len_11; /*params_packet_spawn_entity_painting*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NamedEntitySpawn: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_named_entity_spawn); size_t len_12 = pdef::pc1_18_play_toClient::size::packet_named_entity_spawn(stream, *obj.params_packet_named_entity_spawn); EXPECT_OR_BAIL(len_12); len += len_12; /*params_packet_named_entity_spawn*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Animation: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_animation); size_t len_13 = pdef::pc1_18_play_toClient::size::packet_animation(stream, *obj.params_packet_animation); EXPECT_OR_BAIL(len_13); len += len_13; /*params_packet_animation*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Statistics: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_statistics); size_t len_14 = pdef::pc1_18_play_toClient::size::packet_statistics(stream, *obj.params_packet_statistics); EXPECT_OR_BAIL(len_14); len += len_14; /*params_packet_statistics*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Advancements: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_advancements); size_t len_15 = pdef::pc1_18_play_toClient::size::packet_advancements(stream, *obj.params_packet_advancements); EXPECT_OR_BAIL(len_15); len += len_15; /*params_packet_advancements*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockBreakAnimation: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_break_animation); size_t len_16 = pdef::pc1_18_play_toClient::size::packet_block_break_animation(stream, *obj.params_packet_block_break_animation); EXPECT_OR_BAIL(len_16); len += len_16; /*params_packet_block_break_animation*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TileEntityData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_tile_entity_data); size_t len_17 = pdef::pc1_18_play_toClient::size::packet_tile_entity_data(stream, *obj.params_packet_tile_entity_data); EXPECT_OR_BAIL(len_17); len += len_17; /*params_packet_tile_entity_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockAction: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_action); size_t len_18 = pdef::pc1_18_play_toClient::size::packet_block_action(stream, *obj.params_packet_block_action); EXPECT_OR_BAIL(len_18); len += len_18; /*params_packet_block_action*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockChange: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_change); size_t len_19 = pdef::pc1_18_play_toClient::size::packet_block_change(stream, *obj.params_packet_block_change); EXPECT_OR_BAIL(len_19); len += len_19; /*params_packet_block_change*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BossBar: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_boss_bar); size_t len_20 = pdef::pc1_18_play_toClient::size::packet_boss_bar(stream, *obj.params_packet_boss_bar); EXPECT_OR_BAIL(len_20); len += len_20; /*params_packet_boss_bar*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Difficulty: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_difficulty); size_t len_21 = pdef::pc1_18_play_toClient::size::packet_difficulty(stream, *obj.params_packet_difficulty); EXPECT_OR_BAIL(len_21); len += len_21; /*params_packet_difficulty*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TabComplete: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_tab_complete); size_t len_22 = pdef::pc1_18_play_toClient::size::packet_tab_complete(stream, *obj.params_packet_tab_complete); EXPECT_OR_BAIL(len_22); len += len_22; /*params_packet_tab_complete*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeclareCommands: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_declare_commands); size_t len_23 = pdef::pc1_18_play_toClient::size::packet_declare_commands(stream, *obj.params_packet_declare_commands); EXPECT_OR_BAIL(len_23); len += len_23; /*params_packet_declare_commands*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::FacePlayer: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_face_player); size_t len_24 = pdef::pc1_18_play_toClient::size::packet_face_player(stream, *obj.params_packet_face_player); EXPECT_OR_BAIL(len_24); len += len_24; /*params_packet_face_player*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NbtQueryResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_nbt_query_response); size_t len_25 = pdef::pc1_18_play_toClient::size::packet_nbt_query_response(stream, *obj.params_packet_nbt_query_response); EXPECT_OR_BAIL(len_25); len += len_25; /*params_packet_nbt_query_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Chat: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_chat); size_t len_26 = pdef::pc1_18_play_toClient::size::packet_chat(stream, *obj.params_packet_chat); EXPECT_OR_BAIL(len_26); len += len_26; /*params_packet_chat*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::MultiBlockChange: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_multi_block_change); size_t len_27 = pdef::pc1_18_play_toClient::size::packet_multi_block_change(stream, *obj.params_packet_multi_block_change); EXPECT_OR_BAIL(len_27); len += len_27; /*params_packet_multi_block_change*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CloseWindow: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_close_window); size_t len_28 = pdef::pc1_18_play_toClient::size::packet_close_window(stream, *obj.params_packet_close_window); EXPECT_OR_BAIL(len_28); len += len_28; /*params_packet_close_window*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenWindow: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_open_window); size_t len_29 = pdef::pc1_18_play_toClient::size::packet_open_window(stream, *obj.params_packet_open_window); EXPECT_OR_BAIL(len_29); len += len_29; /*params_packet_open_window*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WindowItems: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_window_items); size_t len_30 = pdef::pc1_18_play_toClient::size::packet_window_items(stream, *obj.params_packet_window_items); EXPECT_OR_BAIL(len_30); len += len_30; /*params_packet_window_items*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CraftProgressBar: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_craft_progress_bar); size_t len_31 = pdef::pc1_18_play_toClient::size::packet_craft_progress_bar(stream, *obj.params_packet_craft_progress_bar); EXPECT_OR_BAIL(len_31); len += len_31; /*params_packet_craft_progress_bar*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetSlot: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_slot); size_t len_32 = pdef::pc1_18_play_toClient::size::packet_set_slot(stream, *obj.params_packet_set_slot); EXPECT_OR_BAIL(len_32); len += len_32; /*params_packet_set_slot*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetCooldown: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_cooldown); size_t len_33 = pdef::pc1_18_play_toClient::size::packet_set_cooldown(stream, *obj.params_packet_set_cooldown); EXPECT_OR_BAIL(len_33); len += len_33; /*params_packet_set_cooldown*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CustomPayload: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_custom_payload); size_t len_34 = pdef::pc1_18_play_toClient::size::packet_custom_payload(stream, *obj.params_packet_custom_payload); EXPECT_OR_BAIL(len_34); len += len_34; /*params_packet_custom_payload*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NamedSoundEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_named_sound_effect); size_t len_35 = pdef::pc1_18_play_toClient::size::packet_named_sound_effect(stream, *obj.params_packet_named_sound_effect); EXPECT_OR_BAIL(len_35); len += len_35; /*params_packet_named_sound_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::KickDisconnect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_kick_disconnect); size_t len_36 = pdef::pc1_18_play_toClient::size::packet_kick_disconnect(stream, *obj.params_packet_kick_disconnect); EXPECT_OR_BAIL(len_36); len += len_36; /*params_packet_kick_disconnect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityStatus: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_status); size_t len_37 = pdef::pc1_18_play_toClient::size::packet_entity_status(stream, *obj.params_packet_entity_status); EXPECT_OR_BAIL(len_37); len += len_37; /*params_packet_entity_status*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Explosion: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_explosion); size_t len_38 = pdef::pc1_18_play_toClient::size::packet_explosion(stream, *obj.params_packet_explosion); EXPECT_OR_BAIL(len_38); len += len_38; /*params_packet_explosion*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UnloadChunk: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_unload_chunk); size_t len_39 = pdef::pc1_18_play_toClient::size::packet_unload_chunk(stream, *obj.params_packet_unload_chunk); EXPECT_OR_BAIL(len_39); len += len_39; /*params_packet_unload_chunk*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::GameStateChange: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_game_state_change); size_t len_40 = pdef::pc1_18_play_toClient::size::packet_game_state_change(stream, *obj.params_packet_game_state_change); EXPECT_OR_BAIL(len_40); len += len_40; /*params_packet_game_state_change*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenHorseWindow: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_open_horse_window); size_t len_41 = pdef::pc1_18_play_toClient::size::packet_open_horse_window(stream, *obj.params_packet_open_horse_window); EXPECT_OR_BAIL(len_41); len += len_41; /*params_packet_open_horse_window*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::KeepAlive: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_keep_alive); size_t len_42 = pdef::pc1_18_play_toClient::size::packet_keep_alive(stream, *obj.params_packet_keep_alive); EXPECT_OR_BAIL(len_42); len += len_42; /*params_packet_keep_alive*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::MapChunk: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_map_chunk); size_t len_43 = pdef::pc1_18_play_toClient::size::packet_map_chunk(stream, *obj.params_packet_map_chunk); EXPECT_OR_BAIL(len_43); len += len_43; /*params_packet_map_chunk*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_world_event); size_t len_44 = pdef::pc1_18_play_toClient::size::packet_world_event(stream, *obj.params_packet_world_event); EXPECT_OR_BAIL(len_44); len += len_44; /*params_packet_world_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldParticles: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_world_particles); size_t len_45 = pdef::pc1_18_play_toClient::size::packet_world_particles(stream, *obj.params_packet_world_particles); EXPECT_OR_BAIL(len_45); len += len_45; /*params_packet_world_particles*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateLight: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_light); size_t len_46 = pdef::pc1_18_play_toClient::size::packet_update_light(stream, *obj.params_packet_update_light); EXPECT_OR_BAIL(len_46); len += len_46; /*params_packet_update_light*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Login: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_login); size_t len_47 = pdef::pc1_18_play_toClient::size::packet_login(stream, *obj.params_packet_login); EXPECT_OR_BAIL(len_47); len += len_47; /*params_packet_login*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Map: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_map); size_t len_48 = pdef::pc1_18_play_toClient::size::packet_map(stream, *obj.params_packet_map); EXPECT_OR_BAIL(len_48); len += len_48; /*params_packet_map*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TradeList: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_trade_list); size_t len_49 = pdef::pc1_18_play_toClient::size::packet_trade_list(stream, *obj.params_packet_trade_list); EXPECT_OR_BAIL(len_49); len += len_49; /*params_packet_trade_list*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::RelEntityMove: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_rel_entity_move); size_t len_50 = pdef::pc1_18_play_toClient::size::packet_rel_entity_move(stream, *obj.params_packet_rel_entity_move); EXPECT_OR_BAIL(len_50); len += len_50; /*params_packet_rel_entity_move*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityMoveLook: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_move_look); size_t len_51 = pdef::pc1_18_play_toClient::size::packet_entity_move_look(stream, *obj.params_packet_entity_move_look); EXPECT_OR_BAIL(len_51); len += len_51; /*params_packet_entity_move_look*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityLook: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_look); size_t len_52 = pdef::pc1_18_play_toClient::size::packet_entity_look(stream, *obj.params_packet_entity_look); EXPECT_OR_BAIL(len_52); len += len_52; /*params_packet_entity_look*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::VehicleMove: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_vehicle_move); size_t len_53 = pdef::pc1_18_play_toClient::size::packet_vehicle_move(stream, *obj.params_packet_vehicle_move); EXPECT_OR_BAIL(len_53); len += len_53; /*params_packet_vehicle_move*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenBook: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_open_book); size_t len_54 = pdef::pc1_18_play_toClient::size::packet_open_book(stream, *obj.params_packet_open_book); EXPECT_OR_BAIL(len_54); len += len_54; /*params_packet_open_book*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenSignEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_open_sign_entity); size_t len_55 = pdef::pc1_18_play_toClient::size::packet_open_sign_entity(stream, *obj.params_packet_open_sign_entity); EXPECT_OR_BAIL(len_55); len += len_55; /*params_packet_open_sign_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CraftRecipeResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_craft_recipe_response); size_t len_56 = pdef::pc1_18_play_toClient::size::packet_craft_recipe_response(stream, *obj.params_packet_craft_recipe_response); EXPECT_OR_BAIL(len_56); len += len_56; /*params_packet_craft_recipe_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Abilities: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_abilities); size_t len_57 = pdef::pc1_18_play_toClient::size::packet_abilities(stream, *obj.params_packet_abilities); EXPECT_OR_BAIL(len_57); len += len_57; /*params_packet_abilities*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EndCombatEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_end_combat_event); size_t len_58 = pdef::pc1_18_play_toClient::size::packet_end_combat_event(stream, *obj.params_packet_end_combat_event); EXPECT_OR_BAIL(len_58); len += len_58; /*params_packet_end_combat_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EnterCombatEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_enter_combat_event); size_t len_59 = pdef::pc1_18_play_toClient::size::packet_enter_combat_event(stream, *obj.params_packet_enter_combat_event); EXPECT_OR_BAIL(len_59); len += len_59; /*params_packet_enter_combat_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeathCombatEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_death_combat_event); size_t len_60 = pdef::pc1_18_play_toClient::size::packet_death_combat_event(stream, *obj.params_packet_death_combat_event); EXPECT_OR_BAIL(len_60); len += len_60; /*params_packet_death_combat_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::PlayerInfo: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_info); size_t len_61 = pdef::pc1_18_play_toClient::size::packet_player_info(stream, *obj.params_packet_player_info); EXPECT_OR_BAIL(len_61); len += len_61; /*params_packet_player_info*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Position: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_position); size_t len_62 = pdef::pc1_18_play_toClient::size::packet_position(stream, *obj.params_packet_position); EXPECT_OR_BAIL(len_62); len += len_62; /*params_packet_position*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UnlockRecipes: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_unlock_recipes); size_t len_63 = pdef::pc1_18_play_toClient::size::packet_unlock_recipes(stream, *obj.params_packet_unlock_recipes); EXPECT_OR_BAIL(len_63); len += len_63; /*params_packet_unlock_recipes*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityDestroy: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_destroy); size_t len_64 = pdef::pc1_18_play_toClient::size::packet_entity_destroy(stream, *obj.params_packet_entity_destroy); EXPECT_OR_BAIL(len_64); len += len_64; /*params_packet_entity_destroy*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::RemoveEntityEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_remove_entity_effect); size_t len_65 = pdef::pc1_18_play_toClient::size::packet_remove_entity_effect(stream, *obj.params_packet_remove_entity_effect); EXPECT_OR_BAIL(len_65); len += len_65; /*params_packet_remove_entity_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ResourcePackSend: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_pack_send); size_t len_66 = pdef::pc1_18_play_toClient::size::packet_resource_pack_send(stream, *obj.params_packet_resource_pack_send); EXPECT_OR_BAIL(len_66); len += len_66; /*params_packet_resource_pack_send*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Respawn: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_respawn); size_t len_67 = pdef::pc1_18_play_toClient::size::packet_respawn(stream, *obj.params_packet_respawn); EXPECT_OR_BAIL(len_67); len += len_67; /*params_packet_respawn*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityUpdateAttributes: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_update_attributes); size_t len_68 = pdef::pc1_18_play_toClient::size::packet_entity_update_attributes(stream, *obj.params_packet_entity_update_attributes); EXPECT_OR_BAIL(len_68); len += len_68; /*params_packet_entity_update_attributes*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Camera: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_camera); size_t len_69 = pdef::pc1_18_play_toClient::size::packet_camera(stream, *obj.params_packet_camera); EXPECT_OR_BAIL(len_69); len += len_69; /*params_packet_camera*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::HeldItemSlot: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_held_item_slot); size_t len_70 = pdef::pc1_18_play_toClient::size::packet_held_item_slot(stream, *obj.params_packet_held_item_slot); EXPECT_OR_BAIL(len_70); len += len_70; /*params_packet_held_item_slot*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateViewPosition: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_view_position); size_t len_71 = pdef::pc1_18_play_toClient::size::packet_update_view_position(stream, *obj.params_packet_update_view_position); EXPECT_OR_BAIL(len_71); len += len_71; /*params_packet_update_view_position*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateViewDistance: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_view_distance); size_t len_72 = pdef::pc1_18_play_toClient::size::packet_update_view_distance(stream, *obj.params_packet_update_view_distance); EXPECT_OR_BAIL(len_72); len += len_72; /*params_packet_update_view_distance*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardDisplayObjective: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_scoreboard_display_objective); size_t len_73 = pdef::pc1_18_play_toClient::size::packet_scoreboard_display_objective(stream, *obj.params_packet_scoreboard_display_objective); EXPECT_OR_BAIL(len_73); len += len_73; /*params_packet_scoreboard_display_objective*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityMetadata: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_metadata); size_t len_74 = pdef::pc1_18_play_toClient::size::packet_entity_metadata(stream, *obj.params_packet_entity_metadata); EXPECT_OR_BAIL(len_74); len += len_74; /*params_packet_entity_metadata*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::AttachEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_attach_entity); size_t len_75 = pdef::pc1_18_play_toClient::size::packet_attach_entity(stream, *obj.params_packet_attach_entity); EXPECT_OR_BAIL(len_75); len += len_75; /*params_packet_attach_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityVelocity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_velocity); size_t len_76 = pdef::pc1_18_play_toClient::size::packet_entity_velocity(stream, *obj.params_packet_entity_velocity); EXPECT_OR_BAIL(len_76); len += len_76; /*params_packet_entity_velocity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityEquipment: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_equipment); size_t len_77 = pdef::pc1_18_play_toClient::size::packet_entity_equipment(stream, *obj.params_packet_entity_equipment); EXPECT_OR_BAIL(len_77); len += len_77; /*params_packet_entity_equipment*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Experience: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_experience); size_t len_78 = pdef::pc1_18_play_toClient::size::packet_experience(stream, *obj.params_packet_experience); EXPECT_OR_BAIL(len_78); len += len_78; /*params_packet_experience*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateHealth: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_health); size_t len_79 = pdef::pc1_18_play_toClient::size::packet_update_health(stream, *obj.params_packet_update_health); EXPECT_OR_BAIL(len_79); len += len_79; /*params_packet_update_health*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardObjective: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_scoreboard_objective); size_t len_80 = pdef::pc1_18_play_toClient::size::packet_scoreboard_objective(stream, *obj.params_packet_scoreboard_objective); EXPECT_OR_BAIL(len_80); len += len_80; /*params_packet_scoreboard_objective*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetPassengers: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_passengers); size_t len_81 = pdef::pc1_18_play_toClient::size::packet_set_passengers(stream, *obj.params_packet_set_passengers); EXPECT_OR_BAIL(len_81); len += len_81; /*params_packet_set_passengers*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Teams: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_teams); size_t len_82 = pdef::pc1_18_play_toClient::size::packet_teams(stream, *obj.params_packet_teams); EXPECT_OR_BAIL(len_82); len += len_82; /*params_packet_teams*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardScore: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_scoreboard_score); size_t len_83 = pdef::pc1_18_play_toClient::size::packet_scoreboard_score(stream, *obj.params_packet_scoreboard_score); EXPECT_OR_BAIL(len_83); len += len_83; /*params_packet_scoreboard_score*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SimulationDistance: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_simulation_distance); size_t len_84 = pdef::pc1_18_play_toClient::size::packet_simulation_distance(stream, *obj.params_packet_simulation_distance); EXPECT_OR_BAIL(len_84); len += len_84; /*params_packet_simulation_distance*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnPosition: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spawn_position); size_t len_85 = pdef::pc1_18_play_toClient::size::packet_spawn_position(stream, *obj.params_packet_spawn_position); EXPECT_OR_BAIL(len_85); len += len_85; /*params_packet_spawn_position*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateTime: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_time); size_t len_86 = pdef::pc1_18_play_toClient::size::packet_update_time(stream, *obj.params_packet_update_time); EXPECT_OR_BAIL(len_86); len += len_86; /*params_packet_update_time*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntitySoundEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_sound_effect); size_t len_87 = pdef::pc1_18_play_toClient::size::packet_entity_sound_effect(stream, *obj.params_packet_entity_sound_effect); EXPECT_OR_BAIL(len_87); len += len_87; /*params_packet_entity_sound_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::StopSound: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_stop_sound); size_t len_88 = pdef::pc1_18_play_toClient::size::packet_stop_sound(stream, *obj.params_packet_stop_sound); EXPECT_OR_BAIL(len_88); len += len_88; /*params_packet_stop_sound*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SoundEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_sound_effect); size_t len_89 = pdef::pc1_18_play_toClient::size::packet_sound_effect(stream, *obj.params_packet_sound_effect); EXPECT_OR_BAIL(len_89); len += len_89; /*params_packet_sound_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::PlayerlistHeader: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_playerlist_header); size_t len_90 = pdef::pc1_18_play_toClient::size::packet_playerlist_header(stream, *obj.params_packet_playerlist_header); EXPECT_OR_BAIL(len_90); len += len_90; /*params_packet_playerlist_header*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Collect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_collect); size_t len_91 = pdef::pc1_18_play_toClient::size::packet_collect(stream, *obj.params_packet_collect); EXPECT_OR_BAIL(len_91); len += len_91; /*params_packet_collect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityTeleport: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_teleport); size_t len_92 = pdef::pc1_18_play_toClient::size::packet_entity_teleport(stream, *obj.params_packet_entity_teleport); EXPECT_OR_BAIL(len_92); len += len_92; /*params_packet_entity_teleport*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityHeadRotation: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_head_rotation); size_t len_93 = pdef::pc1_18_play_toClient::size::packet_entity_head_rotation(stream, *obj.params_packet_entity_head_rotation); EXPECT_OR_BAIL(len_93); len += len_93; /*params_packet_entity_head_rotation*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_effect); size_t len_94 = pdef::pc1_18_play_toClient::size::packet_entity_effect(stream, *obj.params_packet_entity_effect); EXPECT_OR_BAIL(len_94); len += len_94; /*params_packet_entity_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SelectAdvancementTab: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_select_advancement_tab); size_t len_95 = pdef::pc1_18_play_toClient::size::packet_select_advancement_tab(stream, *obj.params_packet_select_advancement_tab); EXPECT_OR_BAIL(len_95); len += len_95; /*params_packet_select_advancement_tab*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeclareRecipes: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_declare_recipes); size_t len_96 = pdef::pc1_18_play_toClient::size::packet_declare_recipes(stream, *obj.params_packet_declare_recipes); EXPECT_OR_BAIL(len_96); len += len_96; /*params_packet_declare_recipes*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Tags: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_tags); size_t len_97 = pdef::pc1_18_play_toClient::size::packet_tags(stream, *obj.params_packet_tags); EXPECT_OR_BAIL(len_97); len += len_97; /*params_packet_tags*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::AcknowledgePlayerDigging: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_acknowledge_player_digging); size_t len_98 = pdef::pc1_18_play_toClient::size::packet_acknowledge_player_digging(stream, *obj.params_packet_acknowledge_player_digging); EXPECT_OR_BAIL(len_98); len += len_98; /*params_packet_acknowledge_player_digging*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SculkVibrationSignal: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_sculk_vibration_signal); size_t len_99 = pdef::pc1_18_play_toClient::size::packet_sculk_vibration_signal(stream, *obj.params_packet_sculk_vibration_signal); EXPECT_OR_BAIL(len_99); len += len_99; /*params_packet_sculk_vibration_signal*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ClearTitles: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_clear_titles); size_t len_100 = pdef::pc1_18_play_toClient::size::packet_clear_titles(stream, *obj.params_packet_clear_titles); EXPECT_OR_BAIL(len_100); len += len_100; /*params_packet_clear_titles*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::InitializeWorldBorder: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_initialize_world_border); size_t len_101 = pdef::pc1_18_play_toClient::size::packet_initialize_world_border(stream, *obj.params_packet_initialize_world_border); EXPECT_OR_BAIL(len_101); len += len_101; /*params_packet_initialize_world_border*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ActionBar: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_action_bar); size_t len_102 = pdef::pc1_18_play_toClient::size::packet_action_bar(stream, *obj.params_packet_action_bar); EXPECT_OR_BAIL(len_102); len += len_102; /*params_packet_action_bar*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderCenter: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_world_border_center); size_t len_103 = pdef::pc1_18_play_toClient::size::packet_world_border_center(stream, *obj.params_packet_world_border_center); EXPECT_OR_BAIL(len_103); len += len_103; /*params_packet_world_border_center*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderLerpSize: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_world_border_lerp_size); size_t len_104 = pdef::pc1_18_play_toClient::size::packet_world_border_lerp_size(stream, *obj.params_packet_world_border_lerp_size); EXPECT_OR_BAIL(len_104); len += len_104; /*params_packet_world_border_lerp_size*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderSize: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_world_border_size); size_t len_105 = pdef::pc1_18_play_toClient::size::packet_world_border_size(stream, *obj.params_packet_world_border_size); EXPECT_OR_BAIL(len_105); len += len_105; /*params_packet_world_border_size*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderWarningDelay: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_world_border_warning_delay); size_t len_106 = pdef::pc1_18_play_toClient::size::packet_world_border_warning_delay(stream, *obj.params_packet_world_border_warning_delay); EXPECT_OR_BAIL(len_106); len += len_106; /*params_packet_world_border_warning_delay*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderWarningReach: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_world_border_warning_reach); size_t len_107 = pdef::pc1_18_play_toClient::size::packet_world_border_warning_reach(stream, *obj.params_packet_world_border_warning_reach); EXPECT_OR_BAIL(len_107); len += len_107; /*params_packet_world_border_warning_reach*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Ping: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_ping); size_t len_108 = pdef::pc1_18_play_toClient::size::packet_ping(stream, *obj.params_packet_ping); EXPECT_OR_BAIL(len_108); len += len_108; /*params_packet_ping*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleSubtitle: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_title_subtitle); size_t len_109 = pdef::pc1_18_play_toClient::size::packet_set_title_subtitle(stream, *obj.params_packet_set_title_subtitle); EXPECT_OR_BAIL(len_109); len += len_109; /*params_packet_set_title_subtitle*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleText: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_title_text); size_t len_110 = pdef::pc1_18_play_toClient::size::packet_set_title_text(stream, *obj.params_packet_set_title_text); EXPECT_OR_BAIL(len_110); len += len_110; /*params_packet_set_title_text*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleTime: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_title_time); size_t len_111 = pdef::pc1_18_play_toClient::size::packet_set_title_time(stream, *obj.params_packet_set_title_time); EXPECT_OR_BAIL(len_111); len += len_111; /*params_packet_set_title_time*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
}

namespace pdef::pc1_18_play_toClient::encode {
bool slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::slot &obj, bool allocate);
bool particle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::particle &obj, bool allocate);
bool minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toClient::minecraft_smelting_format &obj, bool allocate);
bool tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::tags &obj, bool allocate);
bool chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::chunkBlockEntity &obj, bool allocate);
bool command_node(pdef::Stream &stream, const pdef::pc1_18_play_toClient::command_node &obj, bool allocate);
bool packet_spawn_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity &obj, bool allocate);
bool packet_spawn_entity_experience_orb(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_experience_orb &obj, bool allocate);
bool packet_spawn_entity_living(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_living &obj, bool allocate);
bool packet_spawn_entity_painting(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_painting &obj, bool allocate);
bool packet_named_entity_spawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_entity_spawn &obj, bool allocate);
bool packet_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_animation &obj, bool allocate);
bool packet_statistics(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_statistics &obj, bool allocate);
bool packet_advancements(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_advancements &obj, bool allocate);
bool packet_block_break_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_break_animation &obj, bool allocate);
bool packet_tile_entity_data(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tile_entity_data &obj, bool allocate);
bool packet_block_action(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_action &obj, bool allocate);
bool packet_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_change &obj, bool allocate);
bool packet_boss_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_boss_bar &obj, bool allocate);
bool packet_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_difficulty &obj, bool allocate);
bool packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tab_complete &obj, bool allocate);
bool packet_declare_commands(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_commands &obj, bool allocate);
bool packet_face_player(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_face_player &obj, bool allocate);
bool packet_nbt_query_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_nbt_query_response &obj, bool allocate);
bool packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_chat &obj, bool allocate);
bool packet_multi_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_multi_block_change &obj, bool allocate);
bool packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_close_window &obj, bool allocate);
bool packet_open_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_window &obj, bool allocate);
bool packet_window_items(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_window_items &obj, bool allocate);
bool packet_craft_progress_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_progress_bar &obj, bool allocate);
bool packet_set_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_slot &obj, bool allocate);
bool packet_set_cooldown(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_cooldown &obj, bool allocate);
bool packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_custom_payload &obj, bool allocate);
bool packet_named_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_sound_effect &obj, bool allocate);
bool packet_kick_disconnect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_kick_disconnect &obj, bool allocate);
bool packet_entity_status(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_status &obj, bool allocate);
bool packet_explosion(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_explosion &obj, bool allocate);
bool packet_unload_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unload_chunk &obj, bool allocate);
bool packet_game_state_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_game_state_change &obj, bool allocate);
bool packet_open_horse_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_horse_window &obj, bool allocate);
bool packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_keep_alive &obj, bool allocate);
bool packet_map_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map_chunk &obj, bool allocate);
bool packet_world_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_event &obj, bool allocate);
bool packet_world_particles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_particles &obj, bool allocate);
bool packet_update_light(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_light &obj, bool allocate);
bool packet_login(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_login &obj, bool allocate);
bool packet_map(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map &obj, bool allocate);
bool packet_trade_list(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_trade_list &obj, bool allocate);
bool packet_rel_entity_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_rel_entity_move &obj, bool allocate);
bool packet_entity_move_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_move_look &obj, bool allocate);
bool packet_entity_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_look &obj, bool allocate);
bool packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_vehicle_move &obj, bool allocate);
bool packet_open_book(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_book &obj, bool allocate);
bool packet_open_sign_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_sign_entity &obj, bool allocate);
bool packet_craft_recipe_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_recipe_response &obj, bool allocate);
bool packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_abilities &obj, bool allocate);
bool packet_end_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_end_combat_event &obj, bool allocate);
bool packet_enter_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_enter_combat_event &obj, bool allocate);
bool packet_death_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_death_combat_event &obj, bool allocate);
bool packet_player_info(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_player_info &obj, bool allocate);
bool packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_position &obj, bool allocate);
bool packet_unlock_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unlock_recipes &obj, bool allocate);
bool packet_entity_destroy(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_destroy &obj, bool allocate);
bool packet_remove_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_remove_entity_effect &obj, bool allocate);
bool packet_resource_pack_send(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_resource_pack_send &obj, bool allocate);
bool packet_respawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_respawn &obj, bool allocate);
bool packet_entity_head_rotation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_head_rotation &obj, bool allocate);
bool packet_camera(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_camera &obj, bool allocate);
bool packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_held_item_slot &obj, bool allocate);
bool packet_update_view_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_position &obj, bool allocate);
bool packet_update_view_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_distance &obj, bool allocate);
bool packet_scoreboard_display_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_display_objective &obj, bool allocate);
bool packet_entity_metadata(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_metadata &obj, bool allocate);
bool packet_attach_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_attach_entity &obj, bool allocate);
bool packet_entity_velocity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_velocity &obj, bool allocate);
bool packet_entity_equipment(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_equipment &obj, bool allocate);
bool packet_experience(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_experience &obj, bool allocate);
bool packet_update_health(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_health &obj, bool allocate);
bool packet_scoreboard_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_objective &obj, bool allocate);
bool packet_set_passengers(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_passengers &obj, bool allocate);
bool packet_teams(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_teams &obj, bool allocate);
bool packet_scoreboard_score(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_score &obj, bool allocate);
bool packet_spawn_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_position &obj, bool allocate);
bool packet_update_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_time &obj, bool allocate);
bool packet_entity_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_sound_effect &obj, bool allocate);
bool packet_stop_sound(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_stop_sound &obj, bool allocate);
bool packet_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sound_effect &obj, bool allocate);
bool packet_playerlist_header(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_playerlist_header &obj, bool allocate);
bool packet_collect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_collect &obj, bool allocate);
bool packet_entity_teleport(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_teleport &obj, bool allocate);
bool packet_entity_update_attributes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_update_attributes &obj, bool allocate);
bool packet_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_effect &obj, bool allocate);
bool packet_select_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_select_advancement_tab &obj, bool allocate);
bool packet_declare_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_recipes &obj, bool allocate);
bool packet_tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tags &obj, bool allocate);
bool packet_acknowledge_player_digging(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_acknowledge_player_digging &obj, bool allocate);
bool packet_sculk_vibration_signal(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sculk_vibration_signal &obj, bool allocate);
bool packet_clear_titles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_clear_titles &obj, bool allocate);
bool packet_initialize_world_border(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_initialize_world_border &obj, bool allocate);
bool packet_action_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_action_bar &obj, bool allocate);
bool packet_world_border_center(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_center &obj, bool allocate);
bool packet_world_border_lerp_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_lerp_size &obj, bool allocate);
bool packet_world_border_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_size &obj, bool allocate);
bool packet_world_border_warning_delay(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_delay &obj, bool allocate);
bool packet_world_border_warning_reach(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_reach &obj, bool allocate);
bool packet_ping(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_ping &obj, bool allocate);
bool packet_set_title_subtitle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_subtitle &obj, bool allocate);
bool packet_set_title_text(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_text &obj, bool allocate);
bool packet_set_title_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_time &obj, bool allocate);
bool packet_simulation_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_simulation_distance &obj, bool allocate);
bool packet(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet &obj, bool allocate);
  bool slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
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
  bool particle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::particle &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::particle(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &particleId = obj.particleId; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.particleId); /*0.4*/
    if (particleId == 2) { /*8.2*/
        const pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 3) { /*8.2*/
        const pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 14) { /*8.2*/
        const pdef::pc1_18_play_toClient::particle::Data14 &v = *obj.data_14; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.red); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.green); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.blue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
    }
    else if (particleId == 15) { /*8.2*/
        const pdef::pc1_18_play_toClient::particle::Data15 &v = *obj.data_15; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromBlue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toBlue); /*0.4*/
    }
    else if (particleId == 24) { /*8.2*/
        const pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 35) { /*8.2*/
        const pdef::pc1_18_play_toClient::particle::Data35 &v = *obj.data_35; /*8.5*/
        WRITE_OR_BAIL(writeByte, (int8_t)v.item); /*0.4*/
    }
    else if (particleId == 36) { /*8.2*/
        const pdef::pc1_18_play_toClient::particle::Data36 &v = *obj.data_36; /*8.5*/
        uint8_t origin_val = 0;
        origin_val |= v.origin.x << 0;
        origin_val |= v.origin.z << 26;
        origin_val |= v.origin.y << 52;
        WRITE_OR_BAIL(writeUByte, origin_val); /*origin: bitfield*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.positionType.length());
        WRITE_OR_BAIL(writeString, v.positionType); /*positionType: pstring*/ /*4.2*/
        const pdef::pc1_18_play_toClient::particle::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_play_toClient::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val = 0;
          destination_position_val |= v.destination_position.x << 0;
          destination_position_val |= v.destination_position.z << 26;
          destination_position_val |= v.destination_position.y << 52;
          WRITE_OR_BAIL(writeUByte, destination_position_val); /*destination_position: bitfield*/ /*4.2*/
        }
        else if (positionType == pdef::pc1_18_play_toClient::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.destination_varint); /*0.4*/
        }
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.ticks); /*0.4*/
    }
    return true;
  }
  bool minecraft_smelting_format(pdef::Stream &stream, const pdef::pc1_18_play_toClient::minecraft_smelting_format &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::minecraft_smelting_format(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
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
bool tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::tags &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::tags(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.tagName.length());
    WRITE_OR_BAIL(writeString, obj.tagName); /*tagName: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entries.size()); /*1.4*/
    for (const auto &v2 : obj.entries) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2); /*0.4*/
    }
  return true;
}
  bool chunkBlockEntity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::chunkBlockEntity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::chunkBlockEntity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t _3_val = 0;
    _3_val |= obj._3.x << 0;
    _3_val |= obj._3.z << 4;
    WRITE_OR_BAIL(writeUByte, _3_val); /*_3: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbtData); /*0.4*/
    return true;
  }
  bool command_node(pdef::Stream &stream, const pdef::pc1_18_play_toClient::command_node &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::command_node(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t flags_val = 0;
    flags_val |= obj.flags.unused << 0;
    flags_val |= obj.flags.has_custom_suggestions << 3;
    flags_val |= obj.flags.has_redirect_node << 4;
    flags_val |= obj.flags.has_command << 5;
    flags_val |= obj.flags.command_node_type << 6;
    WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
    const pdef::pc1_18_play_toClient::command_node::bitfield &flags = obj.flags; /*0.1*/
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
        const pdef::pc1_18_play_toClient::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.name.length());
        WRITE_OR_BAIL(writeString, v.name); /*name: pstring*/ /*4.2*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
        const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.name.length());
        WRITE_OR_BAIL(writeString, v.name); /*name: pstring*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.parser.length());
        WRITE_OR_BAIL(writeString, v.parser); /*parser: pstring*/ /*4.2*/
        const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.1*/
        if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeFloatBE, (float)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeFloatBE, (float)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeDoubleBE, (double)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeDoubleBE, (double)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeIntBE, (int32_t)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeIntBE, (int32_t)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.5*/
            uint8_t flags_val = 0;
            flags_val |= v.flags.unused << 0;
            flags_val |= v.flags.max_present << 6;
            flags_val |= v.flags.min_present << 7;
            WRITE_OR_BAIL(writeUByte, flags_val); /*flags: bitfield*/ /*4.2*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.1*/
            if (flags.min_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeLongBE, (int64_t)v.min); /*0.4*/
            }
            if (flags.max_present == 1) { /*8.2*/
              WRITE_OR_BAIL(writeLongBE, (int64_t)v.max); /*0.4*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          uint8_t properties_minecraft_entity_val = 0;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.unused << 0;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.onlyAllowPlayers << 6;
          properties_minecraft_entity_val |= v.properties_minecraft_entity.onlyAllowEntities << 7;
          WRITE_OR_BAIL(writeUByte, properties_minecraft_entity_val); /*properties_minecraft_entity: bitfield*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          uint8_t properties_minecraft_score_holder_val = 0;
          properties_minecraft_score_holder_val |= v.properties_minecraft_score_holder.unused << 0;
          properties_minecraft_score_holder_val |= v.properties_minecraft_score_holder.allowMultiple << 7;
          WRITE_OR_BAIL(writeUByte, properties_minecraft_score_holder_val); /*properties_minecraft_score_holder: bitfield*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.5*/
            WRITE_OR_BAIL(writeBool, (bool)v.allowDecimals); /*0.4*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.registry.length());
            WRITE_OR_BAIL(writeString, v.registry); /*registry: pstring*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
            const pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.registry.length());
            WRITE_OR_BAIL(writeString, v.registry); /*registry: pstring*/ /*4.2*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.suggestionType.length());
          WRITE_OR_BAIL(writeString, v.suggestionType); /*suggestionType: pstring*/ /*4.2*/
        }
    }
    return true;
  }
  bool packet_spawn_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_spawn_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.objectUUID); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.objectData); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityX); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityY); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityZ); /*0.4*/
    return true;
  }
  bool packet_spawn_entity_experience_orb(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_experience_orb &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_spawn_entity_experience_orb(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.count); /*0.4*/
    return true;
  }
  bool packet_spawn_entity_living(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_living &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_spawn_entity_living(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.entityUUID); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.headPitch); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityX); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityY); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityZ); /*0.4*/
    return true;
  }
  bool packet_spawn_entity_painting(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_entity_painting &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_spawn_entity_painting(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.entityUUID); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title); /*0.4*/
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.direction); /*0.4*/
    return true;
  }
  bool packet_named_entity_spawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_entity_spawn &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_named_entity_spawn(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.playerUUID); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.pitch); /*0.4*/
    return true;
  }
  bool packet_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_animation &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_animation(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.animation); /*0.4*/
    return true;
  }
  bool packet_statistics(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_statistics &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_statistics(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entries.size()); /*1.4*/
    for (const auto &v2 : obj.entries) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.categoryId); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.statisticId); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.value); /*0.4*/
    }
    return true;
  }
  bool packet_advancements(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_advancements &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_advancements(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.reset); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.advancementMapping.size()); /*1.4*/
    for (const auto &v2 : obj.advancementMapping) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.key.length());
      WRITE_OR_BAIL(writeString, v2.key); /*key: pstring*/ /*4.2*/
      const pdef::pc1_18_play_toClient::packet_advancements::AdvancementMapping::Value &v = v2.value; /*["packet_advancements","AdvancementMapping"]*/ /*7.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.identifiers.size()); /*1.4*/
    for (const auto &v2 : obj.identifiers) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.progressMapping.size()); /*1.4*/
    for (const auto &v2 : obj.progressMapping) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.key.length());
      WRITE_OR_BAIL(writeString, v2.key); /*key: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.value.size()); /*1.4*/
      for (const auto &v3 : v2.value) { /*5.20*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.criterionIdentifier.length());
        WRITE_OR_BAIL(writeString, v3.criterionIdentifier); /*criterionIdentifier: pstring*/ /*4.2*/
        const pdef::pc1_18_play_toClient::packet_advancements::ProgressMapping::Value::CriterionProgress &v = v3.criterionProgress; /*["packet_advancements","ProgressMapping","Value"]*/ /*7.4*/
      }
    }
    return true;
  }
  bool packet_block_break_animation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_break_animation &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_block_break_animation(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.destroyStage); /*0.4*/
    return true;
  }
  bool packet_tile_entity_data(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tile_entity_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_tile_entity_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbtData); /*0.4*/
    return true;
  }
  bool packet_block_action(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_action &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_block_action(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.byte1); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.byte2); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockId); /*0.4*/
    return true;
  }
  bool packet_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_block_change &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_block_change(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    return true;
  }
  bool packet_boss_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_boss_bar &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_boss_bar(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.entityUUID); /*0.4*/
    const int &action = obj.action; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title.length());
      WRITE_OR_BAIL(writeString, obj.title); /*title: pstring*/ /*4.2*/
    }
    else if (action == 3) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title.length());
      WRITE_OR_BAIL(writeString, obj.title); /*title: pstring*/ /*4.2*/
    }
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeFloatBE, (float)obj.health); /*0.4*/
    }
    else if (action == 2) { /*8.2*/
      WRITE_OR_BAIL(writeFloatBE, (float)obj.health); /*0.4*/
    }
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.color); /*0.4*/
    }
    else if (action == 4) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.color); /*0.4*/
    }
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.dividers); /*0.4*/
    }
    else if (action == 4) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.dividers); /*0.4*/
    }
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.flags); /*0.4*/
    }
    else if (action == 5) { /*8.2*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.flags); /*0.4*/
    }
    return true;
  }
  bool packet_difficulty(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_difficulty &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_difficulty(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.difficulty); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.difficultyLocked); /*0.4*/
    return true;
  }
  bool packet_tab_complete(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tab_complete &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_tab_complete(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.transactionId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.start); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.length); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.matches.size()); /*1.4*/
    for (const auto &v2 : obj.matches) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.match.length());
      WRITE_OR_BAIL(writeString, v2.match); /*match: pstring*/ /*4.2*/
      const pdef::pc1_18_play_toClient::packet_tab_complete::Matches::Tooltip &v = v2.tooltip; /*["packet_tab_complete","Matches"]*/ /*7.4*/
    }
    return true;
  }
  bool packet_declare_commands(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_commands &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_declare_commands(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.nodes.size()); /*1.4*/
    for (const auto &v2 : obj.nodes) { /*3.1*/
      pdef::pc1_18_play_toClient::encode::command_node(stream, v2); /*command_node*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.rootIndex); /*0.4*/
    return true;
  }
  bool packet_face_player(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_face_player &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_face_player(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.feet_eyes); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    const bool &isEntity = obj.isEntity; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.isEntity); /*0.4*/
    if (isEntity == true) { /*8.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    }
    if (isEntity == true) { /*8.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entity_feet_eyes.length());
      WRITE_OR_BAIL(writeString, obj.entity_feet_eyes); /*entity_feet_eyes: pstring*/ /*4.2*/
    }
    return true;
  }
  bool packet_nbt_query_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_nbt_query_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_nbt_query_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.transactionId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_chat(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_chat &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_chat(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
    WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.position); /*0.4*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.sender); /*0.4*/
    return true;
  }
  bool packet_multi_block_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_multi_block_change &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_multi_block_change(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t chunkCoordinates_val = 0;
    chunkCoordinates_val |= obj.chunkCoordinates.x << 0;
    chunkCoordinates_val |= obj.chunkCoordinates.z << 22;
    chunkCoordinates_val |= obj.chunkCoordinates.y << 44;
    WRITE_OR_BAIL(writeUByte, chunkCoordinates_val); /*chunkCoordinates: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.notTrustEdges); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.records.size()); /*1.4*/
    for (const auto &v2 : obj.records) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2); /*0.4*/
    }
    return true;
  }
  bool packet_close_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_close_window &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_close_window(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.windowId); /*0.4*/
    return true;
  }
  bool packet_open_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_window &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_open_window(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.inventoryType); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.windowTitle.length());
    WRITE_OR_BAIL(writeString, obj.windowTitle); /*windowTitle: pstring*/ /*4.2*/
    return true;
  }
  bool packet_window_items(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_window_items &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_window_items(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.stateId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.items.size()); /*1.4*/
    for (const auto &v2 : obj.items) { /*3.1*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.carriedItem); /*0.4*/
    return true;
  }
  bool packet_craft_progress_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_progress_bar &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_craft_progress_bar(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.property); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.value); /*0.4*/
    return true;
  }
  bool packet_set_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_set_slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.stateId); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.slot); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.item); /*0.4*/
    return true;
  }
  bool packet_set_cooldown(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_cooldown &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_set_cooldown(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.itemID); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.cooldownTicks); /*0.4*/
    return true;
  }
  bool packet_custom_payload(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_custom_payload &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_custom_payload(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.channel.length());
    WRITE_OR_BAIL(writeString, obj.channel); /*channel: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.data); /*0.4*/
    return true;
  }
  bool packet_named_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_named_sound_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_named_sound_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.soundName.length());
    WRITE_OR_BAIL(writeString, obj.soundName); /*soundName: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.soundCategory); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.volume); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    return true;
  }
  bool packet_kick_disconnect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_kick_disconnect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_kick_disconnect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.reason.length());
    WRITE_OR_BAIL(writeString, obj.reason); /*reason: pstring*/ /*4.2*/
    return true;
  }
  bool packet_entity_status(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_status &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_status(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.entityStatus); /*0.4*/
    return true;
  }
  bool packet_explosion(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_explosion &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_explosion(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatBE, (float)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.radius); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.affectedBlockOffsets.size()); /*1.4*/
    for (const auto &v2 : obj.affectedBlockOffsets) { /*5.20*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.x); /*0.4*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.y); /*0.4*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.z); /*0.4*/
    }
    WRITE_OR_BAIL(writeFloatBE, (float)obj.playerMotionX); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.playerMotionY); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.playerMotionZ); /*0.4*/
    return true;
  }
  bool packet_unload_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unload_chunk &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_unload_chunk(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.chunkX); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.chunkZ); /*0.4*/
    return true;
  }
  bool packet_game_state_change(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_game_state_change &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_game_state_change(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.reason); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.gameMode); /*0.4*/
    return true;
  }
  bool packet_open_horse_window(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_horse_window &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_open_horse_window(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.nbSlots); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.entityId); /*0.4*/
    return true;
  }
  bool packet_keep_alive(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_keep_alive &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_keep_alive(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeLongBE, (int64_t)obj.keepAliveId); /*0.4*/
    return true;
  }
  bool packet_map_chunk(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map_chunk &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_map_chunk(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.heightmaps); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.chunkData.size());
    WRITE_OR_BAIL(writeBuffer, obj.chunkData); /*chunkData: buffer*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockEntities.size()); /*1.4*/
    for (const auto &v2 : obj.blockEntities) { /*3.1*/
      pdef::pc1_18_play_toClient::encode::chunkBlockEntity(stream, v2); /*chunkBlockEntity*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeBool, (bool)obj.trustEdges); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skyLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.skyLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.blockLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.emptySkyLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.emptySkyLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.emptyBlockLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.emptyBlockLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skyLight.size()); /*1.4*/
    for (const auto &v : obj.skyLight) { /*5.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skyLight.size()); /*5.7*/
      for (const auto &v : v) { /*5.10*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)v); /*5.13*/
      }
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockLight.size()); /*1.4*/
    for (const auto &v : obj.blockLight) { /*5.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockLight.size()); /*5.7*/
      for (const auto &v : v) { /*5.10*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)v); /*5.13*/
      }
    }
    return true;
  }
  bool packet_world_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_world_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.effectId); /*0.4*/
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.data); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.global); /*0.4*/
    return true;
  }
  bool packet_world_particles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_particles &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_world_particles(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int32_t &particleId = obj.particleId; /*0.1*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.particleId); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.longDistance); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.offsetX); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.offsetY); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.offsetZ); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.particleData); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.particles); /*0.4*/
    if (particleId == 2) { /*8.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 3) { /*8.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 14) { /*8.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data14 &v = *obj.data_14; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.red); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.green); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.blue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
    }
    else if (particleId == 15) { /*8.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data15 &v = *obj.data_15; /*8.5*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.fromBlue); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.scale); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toRed); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toGreen); /*0.4*/
        WRITE_OR_BAIL(writeFloatBE, (float)v.toBlue); /*0.4*/
    }
    else if (particleId == 24) { /*8.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.blockState); /*0.4*/
    }
    else if (particleId == 35) { /*8.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data35 &v = *obj.data_35; /*8.5*/
        WRITE_OR_BAIL(writeByte, (int8_t)v.item); /*0.4*/
    }
    else if (particleId == 36) { /*8.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data36 &v = *obj.data_36; /*8.5*/
        uint8_t origin_val = 0;
        origin_val |= v.origin.x << 0;
        origin_val |= v.origin.z << 26;
        origin_val |= v.origin.y << 52;
        WRITE_OR_BAIL(writeUByte, origin_val); /*origin: bitfield*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.positionType.length());
        WRITE_OR_BAIL(writeString, v.positionType); /*positionType: pstring*/ /*4.2*/
        const pdef::pc1_18_play_toClient::packet_world_particles::Data36::pstring &positionType = v.positionType; /*0.1*/
        if (positionType == pdef::pc1_18_play_toClient::packet_world_particles::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val = 0;
          destination_position_val |= v.destination_position.x << 0;
          destination_position_val |= v.destination_position.z << 26;
          destination_position_val |= v.destination_position.y << 52;
          WRITE_OR_BAIL(writeUByte, destination_position_val); /*destination_position: bitfield*/ /*4.2*/
        }
        else if (positionType == pdef::pc1_18_play_toClient::packet_world_particles::Data36::PositionType::MinecraftEntity) { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.destination_varint); /*0.4*/
        }
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.ticks); /*0.4*/
    }
    return true;
  }
  bool packet_update_light(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_light &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_update_light(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.chunkX); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.chunkZ); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.trustEdges); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skyLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.skyLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.blockLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.emptySkyLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.emptySkyLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.emptyBlockLightMask.size()); /*1.4*/
    for (const auto &v2 : obj.emptyBlockLightMask) { /*3.1*/
      WRITE_OR_BAIL(writeLongBE, (int64_t)v2); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skyLight.size()); /*1.4*/
    for (const auto &v : obj.skyLight) { /*5.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skyLight.size()); /*5.7*/
      for (const auto &v : v) { /*5.10*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)v); /*5.13*/
      }
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockLight.size()); /*1.4*/
    for (const auto &v : obj.blockLight) { /*5.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blockLight.size()); /*5.7*/
      for (const auto &v : v) { /*5.10*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)v); /*5.13*/
      }
    }
    return true;
  }
  bool packet_login(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_login &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_login(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.isHardcore); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.gameMode); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.previousGameMode); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.worldNames.size()); /*1.4*/
    for (const auto &v2 : obj.worldNames) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dimensionCodec); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dimension); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.worldName.length());
    WRITE_OR_BAIL(writeString, obj.worldName); /*worldName: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeLongBE, (int64_t)obj.hashedSeed); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.maxPlayers); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.viewDistance); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.simulationDistance); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.reducedDebugInfo); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.enableRespawnScreen); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.isDebug); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.isFlat); /*0.4*/
    return true;
  }
  bool packet_map(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_map &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_map(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.itemDamage); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.scale); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.locked); /*0.4*/
    const pdef::pc1_18_play_toClient::packet_map::Icons &v = obj.icons; /*["packet_map"]*/ /*7.4*/
    const uint8_t &columns = obj.columns; /*0.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.columns); /*0.4*/
    if (columns == 0) { /*8.2*/
    }
    else {
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.rows); /*0.4*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.x); /*0.4*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.y); /*0.4*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data.size());
      WRITE_OR_BAIL(writeBuffer, obj.data); /*data: buffer*/ /*4.2*/
    }
    return true;
  }
  bool packet_trade_list(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_trade_list &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_trade_list(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.trades.size()); /*1.4*/
    for (const auto &v2 : obj.trades) { /*5.20*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.inputItem1); /*0.4*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.outputItem); /*0.4*/
      const pdef::pc1_18_play_toClient::packet_trade_list::Trades::InputItem2 &v = v2.inputItem2; /*["packet_trade_list","Trades"]*/ /*7.4*/
      WRITE_OR_BAIL(writeBool, (bool)v2.tradeDisabled); /*0.4*/
      WRITE_OR_BAIL(writeIntBE, (int32_t)v2.nbTradeUses); /*0.4*/
      WRITE_OR_BAIL(writeIntBE, (int32_t)v2.maximumNbTradeUses); /*0.4*/
      WRITE_OR_BAIL(writeIntBE, (int32_t)v2.xp); /*0.4*/
      WRITE_OR_BAIL(writeIntBE, (int32_t)v2.specialPrice); /*0.4*/
      WRITE_OR_BAIL(writeFloatBE, (float)v2.priceMultiplier); /*0.4*/
      WRITE_OR_BAIL(writeIntBE, (int32_t)v2.demand); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.villagerLevel); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.experience); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.isRegularVillager); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.canRestock); /*0.4*/
    return true;
  }
  bool packet_rel_entity_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_rel_entity_move &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_rel_entity_move(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.dX); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.dY); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.dZ); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_entity_move_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_move_look &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_move_look(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.dX); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.dY); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.dZ); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_entity_look(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_look &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_look(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_vehicle_move(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_vehicle_move &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_vehicle_move(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    return true;
  }
  bool packet_open_book(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_book &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_open_book(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hand); /*0.4*/
    return true;
  }
  bool packet_open_sign_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_open_sign_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_open_sign_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    return true;
  }
  bool packet_craft_recipe_response(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_craft_recipe_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_craft_recipe_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.windowId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.recipe.length());
    WRITE_OR_BAIL(writeString, obj.recipe); /*recipe: pstring*/ /*4.2*/
    return true;
  }
  bool packet_abilities(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_abilities &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_abilities(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.flags); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.flyingSpeed); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.walkingSpeed); /*0.4*/
    return true;
  }
  bool packet_end_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_end_combat_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_end_combat_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.duration); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.entityId); /*0.4*/
    return true;
  }
  bool packet_enter_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_enter_combat_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_enter_combat_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    return true;
  }
  bool packet_death_combat_event(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_death_combat_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_death_combat_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.playerId); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
    WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
    return true;
  }
  bool packet_player_info(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_player_info &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_player_info(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &action = obj.action; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data.size()); /*1.4*/
    for (const auto &v2 : obj.data) { /*5.20*/
      WRITE_OR_BAIL(writeULongBE, (uint64_t)v2.UUID); /*0.4*/
      if (action == 0) { /*8.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.name.length());
        WRITE_OR_BAIL(writeString, v2.name); /*name: pstring*/ /*4.2*/
      }
      if (action == 0) { /*8.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.properties.size()); /*1.4*/
        for (const auto &v4 : v2.properties) { /*5.20*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v4.name.length());
          WRITE_OR_BAIL(writeString, v4.name); /*name: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v4.value.length());
          WRITE_OR_BAIL(writeString, v4.value); /*value: pstring*/ /*4.2*/
          const pdef::pc1_18_play_toClient::packet_player_info::Data::Properties::Signature &v = v4.signature; /*["packet_player_info","Data","Properties"]*/ /*7.4*/
        }
      }
      if (action == 0) { /*8.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.gamemode); /*0.4*/
      }
      else if (action == 1) { /*8.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.gamemode); /*0.4*/
      }
      if (action == 0) { /*8.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.ping); /*0.4*/
      }
      else if (action == 2) { /*8.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.ping); /*0.4*/
      }
      if (action == 0) { /*8.2*/
          const pdef::pc1_18_play_toClient::packet_player_info::Data::DisplayName &v = *v2.displayName; /*8.5*/
          const bool &has = v2.has; /*0.1*/
          WRITE_OR_BAIL(writeBool, (bool)v2.has); /*0.4*/
          if (has == true) { /*8.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.value.length());
            WRITE_OR_BAIL(writeString, v2.value); /*value: pstring*/ /*4.2*/
          }
      }
      else if (action == 3) { /*8.2*/
          const pdef::pc1_18_play_toClient::packet_player_info::Data::DisplayName &v = *v2.displayName; /*8.5*/
          const bool &has = v2.has; /*0.1*/
          WRITE_OR_BAIL(writeBool, (bool)v2.has); /*0.4*/
          if (has == true) { /*8.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.value.length());
            WRITE_OR_BAIL(writeString, v2.value); /*value: pstring*/ /*4.2*/
          }
      }
    }
    return true;
  }
  bool packet_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_position &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_position(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.flags); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.teleportId); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.dismountVehicle); /*0.4*/
    return true;
  }
  bool packet_unlock_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_unlock_recipes &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_unlock_recipes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &action = obj.action; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.craftingBookOpen); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.filteringCraftable); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.smeltingBookOpen); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.filteringSmeltable); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.blastFurnaceOpen); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.filteringBlastFurnace); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.smokerBookOpen); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.filteringSmoker); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.recipes1.size()); /*1.4*/
    for (const auto &v2 : obj.recipes1) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.recipes2.size()); /*1.4*/
      for (const auto &v3 : obj.recipes2) { /*3.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.length());
        WRITE_OR_BAIL(writeString, v3); /*: pstring*/ /*4.2*/
      }
    }
    return true;
  }
  bool packet_entity_destroy(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_destroy &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_destroy(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityIds.size()); /*1.4*/
    for (const auto &v2 : obj.entityIds) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2); /*0.4*/
    }
    return true;
  }
  bool packet_remove_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_remove_entity_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_remove_entity_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.effectId); /*0.4*/
    return true;
  }
  bool packet_resource_pack_send(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_resource_pack_send &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_resource_pack_send(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.url.length());
    WRITE_OR_BAIL(writeString, obj.url); /*url: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hash.length());
    WRITE_OR_BAIL(writeString, obj.hash); /*hash: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.forced); /*0.4*/
    const pdef::pc1_18_play_toClient::packet_resource_pack_send::PromptMessage &v = obj.promptMessage; /*["packet_resource_pack_send"]*/ /*7.4*/
    return true;
  }
  bool packet_respawn(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_respawn &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_respawn(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dimension); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.worldName.length());
    WRITE_OR_BAIL(writeString, obj.worldName); /*worldName: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeLongBE, (int64_t)obj.hashedSeed); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.gamemode); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.previousGamemode); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.isDebug); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.isFlat); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.copyMetadata); /*0.4*/
    return true;
  }
  bool packet_entity_head_rotation(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_head_rotation &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_head_rotation(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.headYaw); /*0.4*/
    return true;
  }
  bool packet_camera(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_camera &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_camera(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.cameraId); /*0.4*/
    return true;
  }
  bool packet_held_item_slot(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_held_item_slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_held_item_slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.slot); /*0.4*/
    return true;
  }
  bool packet_update_view_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_position &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_update_view_position(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.chunkX); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.chunkZ); /*0.4*/
    return true;
  }
  bool packet_update_view_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_view_distance &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_update_view_distance(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.viewDistance); /*0.4*/
    return true;
  }
  bool packet_scoreboard_display_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_display_objective &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_scoreboard_display_objective(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.position); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    return true;
  }
  bool packet_entity_metadata(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_metadata &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_metadata(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.metadata); /*0.4*/
    return true;
  }
  bool packet_attach_entity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_attach_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_attach_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.vehicleId); /*0.4*/
    return true;
  }
  bool packet_entity_velocity(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_velocity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_velocity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityX); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityY); /*0.4*/
    WRITE_OR_BAIL(writeShortBE, (int16_t)obj.velocityZ); /*0.4*/
    return true;
  }
  bool packet_entity_equipment(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_equipment &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_equipment(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.equipments); /*0.4*/
    return true;
  }
  bool packet_experience(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_experience &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_experience(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatBE, (float)obj.experienceBar); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.level); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.totalExperience); /*0.4*/
    return true;
  }
  bool packet_update_health(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_health &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_update_health(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatBE, (float)obj.health); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.food); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.foodSaturation); /*0.4*/
    return true;
  }
  bool packet_scoreboard_objective(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_objective &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_scoreboard_objective(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    const int8_t &action = obj.action; /*0.1*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.action); /*0.4*/
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.displayText.length());
      WRITE_OR_BAIL(writeString, obj.displayText); /*displayText: pstring*/ /*4.2*/
    }
    else if (action == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.displayText.length());
      WRITE_OR_BAIL(writeString, obj.displayText); /*displayText: pstring*/ /*4.2*/
    }
    if (action == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    }
    else if (action == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.type); /*0.4*/
    }
    return true;
  }
  bool packet_set_passengers(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_passengers &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_set_passengers(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.passengers.size()); /*1.4*/
    for (const auto &v2 : obj.passengers) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2); /*0.4*/
    }
    return true;
  }
  bool packet_teams(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_teams &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_teams(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.team.length());
    WRITE_OR_BAIL(writeString, obj.team); /*team: pstring*/ /*4.2*/
    const int8_t &mode = obj.mode; /*0.1*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.mode); /*0.4*/
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
      WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    }
    else if (mode == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
      WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    }
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeByte, (int8_t)obj.friendlyFire); /*0.4*/
    }
    else if (mode == 2) { /*8.2*/
      WRITE_OR_BAIL(writeByte, (int8_t)obj.friendlyFire); /*0.4*/
    }
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.nameTagVisibility.length());
      WRITE_OR_BAIL(writeString, obj.nameTagVisibility); /*nameTagVisibility: pstring*/ /*4.2*/
    }
    else if (mode == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.nameTagVisibility.length());
      WRITE_OR_BAIL(writeString, obj.nameTagVisibility); /*nameTagVisibility: pstring*/ /*4.2*/
    }
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.collisionRule.length());
      WRITE_OR_BAIL(writeString, obj.collisionRule); /*collisionRule: pstring*/ /*4.2*/
    }
    else if (mode == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.collisionRule.length());
      WRITE_OR_BAIL(writeString, obj.collisionRule); /*collisionRule: pstring*/ /*4.2*/
    }
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.formatting); /*0.4*/
    }
    else if (mode == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.formatting); /*0.4*/
    }
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.prefix.length());
      WRITE_OR_BAIL(writeString, obj.prefix); /*prefix: pstring*/ /*4.2*/
    }
    else if (mode == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.prefix.length());
      WRITE_OR_BAIL(writeString, obj.prefix); /*prefix: pstring*/ /*4.2*/
    }
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.suffix.length());
      WRITE_OR_BAIL(writeString, obj.suffix); /*suffix: pstring*/ /*4.2*/
    }
    else if (mode == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.suffix.length());
      WRITE_OR_BAIL(writeString, obj.suffix); /*suffix: pstring*/ /*4.2*/
    }
    if (mode == 0) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.players.size()); /*1.4*/
      for (const auto &v3 : obj.players) { /*3.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.length());
        WRITE_OR_BAIL(writeString, v3); /*: pstring*/ /*4.2*/
      }
    }
    else if (mode == 3) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.players.size()); /*1.4*/
      for (const auto &v3 : obj.players) { /*3.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.length());
        WRITE_OR_BAIL(writeString, v3); /*: pstring*/ /*4.2*/
      }
    }
    else if (mode == 4) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.players.size()); /*1.4*/
      for (const auto &v3 : obj.players) { /*3.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.length());
        WRITE_OR_BAIL(writeString, v3); /*: pstring*/ /*4.2*/
      }
    }
    return true;
  }
  bool packet_scoreboard_score(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_scoreboard_score &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_scoreboard_score(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.itemName.length());
    WRITE_OR_BAIL(writeString, obj.itemName); /*itemName: pstring*/ /*4.2*/
    const int &action = obj.action; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.scoreName.length());
    WRITE_OR_BAIL(writeString, obj.scoreName); /*scoreName: pstring*/ /*4.2*/
    if (action == 1) { /*8.2*/
    }
    else {
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.value); /*0.4*/
    }
    return true;
  }
  bool packet_spawn_position(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_spawn_position &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_spawn_position(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.angle); /*0.4*/
    return true;
  }
  bool packet_update_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_update_time &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_update_time(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeLongBE, (int64_t)obj.age); /*0.4*/
    WRITE_OR_BAIL(writeLongBE, (int64_t)obj.time); /*0.4*/
    return true;
  }
  bool packet_entity_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_sound_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_sound_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.soundId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.soundCategory); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.volume); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    return true;
  }
  bool packet_stop_sound(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_stop_sound &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_stop_sound(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int8_t &flags = obj.flags; /*0.1*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.flags); /*0.4*/
    if (flags == 1) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.source); /*0.4*/
    }
    else if (flags == 3) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.source); /*0.4*/
    }
    if (flags == 2) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.sound.length());
      WRITE_OR_BAIL(writeString, obj.sound); /*sound: pstring*/ /*4.2*/
    }
    else if (flags == 3) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.sound.length());
      WRITE_OR_BAIL(writeString, obj.sound); /*sound: pstring*/ /*4.2*/
    }
    return true;
  }
  bool packet_sound_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sound_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_sound_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.soundId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.soundCategory); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.volume); /*0.4*/
    WRITE_OR_BAIL(writeFloatBE, (float)obj.pitch); /*0.4*/
    return true;
  }
  bool packet_playerlist_header(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_playerlist_header &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_playerlist_header(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.header.length());
    WRITE_OR_BAIL(writeString, obj.header); /*header: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.footer.length());
    WRITE_OR_BAIL(writeString, obj.footer); /*footer: pstring*/ /*4.2*/
    return true;
  }
  bool packet_collect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_collect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_collect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.collectedEntityId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.collectorEntityId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.pickupItemCount); /*0.4*/
    return true;
  }
  bool packet_entity_teleport(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_teleport &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_teleport(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.onGround); /*0.4*/
    return true;
  }
  bool packet_entity_update_attributes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_update_attributes &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_update_attributes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.properties.size()); /*1.4*/
    for (const auto &v2 : obj.properties) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.key.length());
      WRITE_OR_BAIL(writeString, v2.key); /*key: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeDoubleBE, (double)v2.value); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.modifiers.size()); /*1.4*/
      for (const auto &v3 : v2.modifiers) { /*5.20*/
        WRITE_OR_BAIL(writeULongBE, (uint64_t)v3.uuid); /*0.4*/
        WRITE_OR_BAIL(writeDoubleBE, (double)v3.amount); /*0.4*/
        WRITE_OR_BAIL(writeByte, (int8_t)v3.operation); /*0.4*/
      }
    }
    return true;
  }
  bool packet_entity_effect(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_entity_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_entity_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entityId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.effectId); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.amplifier); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.duration); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.hideParticles); /*0.4*/
    return true;
  }
  bool packet_select_advancement_tab(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_select_advancement_tab &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_select_advancement_tab(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::pc1_18_play_toClient::packet_select_advancement_tab::Id &v = obj.id; /*["packet_select_advancement_tab"]*/ /*7.4*/
    return true;
  }
  bool packet_declare_recipes(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_declare_recipes &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_declare_recipes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.recipes.size()); /*1.4*/
    for (const auto &v2 : obj.recipes) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.type.length());
      WRITE_OR_BAIL(writeString, v2.type); /*type: pstring*/ /*4.2*/
      const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::pstring &type = v2.type; /*0.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.recipeId.length());
      WRITE_OR_BAIL(writeString, v2.recipeId); /*recipeId: pstring*/ /*4.2*/
      if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingShapeless) { /*8.5*/
          const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftCraftingShapeless &v = *v2.data_minecraft_crafting_shapeless; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.group.length());
          WRITE_OR_BAIL(writeString, v2.group); /*group: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.ingredients.size()); /*1.4*/
          for (const auto &v5 : v2.ingredients) { /*3.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v5.size()); /*1.4*/
            for (const auto &v6 : v5) { /*3.1*/
              WRITE_OR_BAIL(writeByte, (int8_t)v6); /*0.4*/
            }
          }
          WRITE_OR_BAIL(writeByte, (int8_t)v2.result); /*0.4*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingShaped) { /*8.5*/
          const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftCraftingShaped &v = *v2.data_minecraft_crafting_shaped; /*8.5*/
          const int &width = v2.width; /*0.1*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.width); /*0.4*/
          const int &height = v2.height; /*0.1*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.height); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.group.length());
          WRITE_OR_BAIL(writeString, v2.group); /*group: pstring*/ /*4.2*/
          for (const auto &v : v2.ingredients) { /*5.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)height); /*5.4*/
            for (const auto &v : v) { /*5.10*/
              pdef::pc1_18_play_toClient::encode::ingredient(stream, v); /*5.13*/
            }
          }
          WRITE_OR_BAIL(writeByte, (int8_t)v2.result); /*0.4*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialArmordye) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBookcloning) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialMapcloning) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialMapextending) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkRocket) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkStar) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkStarFade) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialRepairitem) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialTippedarrow) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBannerduplicate) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBanneraddpattern) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialShielddecoration) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialShulkerboxcoloring) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialSuspiciousstew) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmelting) { /*8.5*/
        pdef::pc1_18_play_toClient::encode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*minecraft_smelting_format*/ /*4.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftBlasting) { /*8.5*/
        pdef::pc1_18_play_toClient::encode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*minecraft_smelting_format*/ /*4.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmoking) { /*8.5*/
        pdef::pc1_18_play_toClient::encode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*minecraft_smelting_format*/ /*4.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCampfireCooking) { /*8.5*/
        pdef::pc1_18_play_toClient::encode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*minecraft_smelting_format*/ /*4.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftStonecutting) { /*8.5*/
          const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftStonecutting &v = *v2.data_minecraft_stonecutting; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.group.length());
          WRITE_OR_BAIL(writeString, v2.group); /*group: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.ingredient.size()); /*1.4*/
          for (const auto &v5 : v2.ingredient) { /*3.1*/
            WRITE_OR_BAIL(writeByte, (int8_t)v5); /*0.4*/
          }
          WRITE_OR_BAIL(writeByte, (int8_t)v2.result); /*0.4*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmithing) { /*8.5*/
          const pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftSmithing &v = *v2.data_minecraft_smithing; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.base.size()); /*1.4*/
          for (const auto &v5 : v2.base) { /*3.1*/
            WRITE_OR_BAIL(writeByte, (int8_t)v5); /*0.4*/
          }
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.addition.size()); /*1.4*/
          for (const auto &v5 : v2.addition) { /*3.1*/
            WRITE_OR_BAIL(writeByte, (int8_t)v5); /*0.4*/
          }
          WRITE_OR_BAIL(writeByte, (int8_t)v2.result); /*0.4*/
      }
    }
    return true;
  }
  bool packet_tags(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_tags &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_tags(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.tags.size()); /*1.4*/
    for (const auto &v2 : obj.tags) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.tagType.length());
      WRITE_OR_BAIL(writeString, v2.tagType); /*tagType: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.tags.size()); /*2.1*/
      for (const auto &v : v2.tags) { pdef::pc1_18_play_toClient::encode::tags(stream, v); } /*2.2*/
    }
    return true;
  }
  bool packet_acknowledge_player_digging(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_acknowledge_player_digging &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_acknowledge_player_digging(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t location_val = 0;
    location_val |= obj.location.x << 0;
    location_val |= obj.location.z << 26;
    location_val |= obj.location.y << 52;
    WRITE_OR_BAIL(writeUByte, location_val); /*location: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.block); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.status); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.successful); /*0.4*/
    return true;
  }
  bool packet_sculk_vibration_signal(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_sculk_vibration_signal &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_sculk_vibration_signal(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t sourcePosition_val = 0;
    sourcePosition_val |= obj.sourcePosition.x << 0;
    sourcePosition_val |= obj.sourcePosition.z << 26;
    sourcePosition_val |= obj.sourcePosition.y << 52;
    WRITE_OR_BAIL(writeUByte, sourcePosition_val); /*sourcePosition: bitfield*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.destinationIdentifier.length());
    WRITE_OR_BAIL(writeString, obj.destinationIdentifier); /*destinationIdentifier: pstring*/ /*4.2*/
    const pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::pstring &destinationIdentifier = obj.destinationIdentifier; /*0.1*/
    if (destinationIdentifier == pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::DestinationIdentifier::Block) { /*8.5*/
      uint8_t destination_position_val = 0;
      destination_position_val |= obj.destination_position.x << 0;
      destination_position_val |= obj.destination_position.z << 26;
      destination_position_val |= obj.destination_position.y << 52;
      WRITE_OR_BAIL(writeUByte, destination_position_val); /*destination_position: bitfield*/ /*4.2*/
    }
    else if (destinationIdentifier == pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::DestinationIdentifier::EntityId) { /*8.5*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.destination_varint); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.arrivalTicks); /*0.4*/
    return true;
  }
  bool packet_clear_titles(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_clear_titles &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_clear_titles(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.reset); /*0.4*/
    return true;
  }
  bool packet_initialize_world_border(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_initialize_world_border &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_initialize_world_border(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.oldDiameter); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.newDiameter); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.speed); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.portalTeleportBoundary); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.warningBlocks); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.warningTime); /*0.4*/
    return true;
  }
  bool packet_action_bar(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_action_bar &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_action_bar(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
    WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
    return true;
  }
  bool packet_world_border_center(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_center &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_world_border_center(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.z); /*0.4*/
    return true;
  }
  bool packet_world_border_lerp_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_lerp_size &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_world_border_lerp_size(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.oldDiameter); /*0.4*/
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.newDiameter); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.speed); /*0.4*/
    return true;
  }
  bool packet_world_border_size(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_size &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_world_border_size(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeDoubleBE, (double)obj.diameter); /*0.4*/
    return true;
  }
  bool packet_world_border_warning_delay(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_delay &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_world_border_warning_delay(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.warningTime); /*0.4*/
    return true;
  }
  bool packet_world_border_warning_reach(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_world_border_warning_reach &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_world_border_warning_reach(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.warningBlocks); /*0.4*/
    return true;
  }
  bool packet_ping(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_ping &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_ping(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.id); /*0.4*/
    return true;
  }
  bool packet_set_title_subtitle(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_subtitle &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_set_title_subtitle(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
    WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
    return true;
  }
  bool packet_set_title_text(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_text &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_set_title_text(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
    WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
    return true;
  }
  bool packet_set_title_time(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_set_title_time &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_set_title_time(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.fadeIn); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.stay); /*0.4*/
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.fadeOut); /*0.4*/
    return true;
  }
  bool packet_simulation_distance(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet_simulation_distance &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet_simulation_distance(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.distance); /*0.4*/
    return true;
  }
  bool packet(pdef::Stream &stream, const pdef::pc1_18_play_toClient::packet &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::pc1_18_play_toClient::size::packet(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::pc1_18_play_toClient::packet::Name &name = obj.name; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.name); /*7.1*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntity: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_spawn_entity(stream, *obj.params_packet_spawn_entity); /*packet_spawn_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityExperienceOrb: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_spawn_entity_experience_orb(stream, *obj.params_packet_spawn_entity_experience_orb); /*packet_spawn_entity_experience_orb*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityLiving: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_spawn_entity_living(stream, *obj.params_packet_spawn_entity_living); /*packet_spawn_entity_living*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityPainting: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_spawn_entity_painting(stream, *obj.params_packet_spawn_entity_painting); /*packet_spawn_entity_painting*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NamedEntitySpawn: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_named_entity_spawn(stream, *obj.params_packet_named_entity_spawn); /*packet_named_entity_spawn*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Animation: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_animation(stream, *obj.params_packet_animation); /*packet_animation*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Statistics: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_statistics(stream, *obj.params_packet_statistics); /*packet_statistics*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Advancements: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_advancements(stream, *obj.params_packet_advancements); /*packet_advancements*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockBreakAnimation: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_block_break_animation(stream, *obj.params_packet_block_break_animation); /*packet_block_break_animation*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TileEntityData: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_tile_entity_data(stream, *obj.params_packet_tile_entity_data); /*packet_tile_entity_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockAction: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_block_action(stream, *obj.params_packet_block_action); /*packet_block_action*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockChange: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_block_change(stream, *obj.params_packet_block_change); /*packet_block_change*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BossBar: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_boss_bar(stream, *obj.params_packet_boss_bar); /*packet_boss_bar*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Difficulty: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_difficulty(stream, *obj.params_packet_difficulty); /*packet_difficulty*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TabComplete: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_tab_complete(stream, *obj.params_packet_tab_complete); /*packet_tab_complete*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeclareCommands: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_declare_commands(stream, *obj.params_packet_declare_commands); /*packet_declare_commands*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::FacePlayer: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_face_player(stream, *obj.params_packet_face_player); /*packet_face_player*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NbtQueryResponse: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_nbt_query_response(stream, *obj.params_packet_nbt_query_response); /*packet_nbt_query_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Chat: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_chat(stream, *obj.params_packet_chat); /*packet_chat*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::MultiBlockChange: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_multi_block_change(stream, *obj.params_packet_multi_block_change); /*packet_multi_block_change*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CloseWindow: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_close_window(stream, *obj.params_packet_close_window); /*packet_close_window*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenWindow: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_open_window(stream, *obj.params_packet_open_window); /*packet_open_window*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WindowItems: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_window_items(stream, *obj.params_packet_window_items); /*packet_window_items*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CraftProgressBar: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_craft_progress_bar(stream, *obj.params_packet_craft_progress_bar); /*packet_craft_progress_bar*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetSlot: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_set_slot(stream, *obj.params_packet_set_slot); /*packet_set_slot*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetCooldown: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_set_cooldown(stream, *obj.params_packet_set_cooldown); /*packet_set_cooldown*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CustomPayload: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_custom_payload(stream, *obj.params_packet_custom_payload); /*packet_custom_payload*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NamedSoundEffect: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_named_sound_effect(stream, *obj.params_packet_named_sound_effect); /*packet_named_sound_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::KickDisconnect: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_kick_disconnect(stream, *obj.params_packet_kick_disconnect); /*packet_kick_disconnect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityStatus: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_status(stream, *obj.params_packet_entity_status); /*packet_entity_status*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Explosion: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_explosion(stream, *obj.params_packet_explosion); /*packet_explosion*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UnloadChunk: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_unload_chunk(stream, *obj.params_packet_unload_chunk); /*packet_unload_chunk*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::GameStateChange: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_game_state_change(stream, *obj.params_packet_game_state_change); /*packet_game_state_change*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenHorseWindow: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_open_horse_window(stream, *obj.params_packet_open_horse_window); /*packet_open_horse_window*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::KeepAlive: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_keep_alive(stream, *obj.params_packet_keep_alive); /*packet_keep_alive*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::MapChunk: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_map_chunk(stream, *obj.params_packet_map_chunk); /*packet_map_chunk*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldEvent: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_world_event(stream, *obj.params_packet_world_event); /*packet_world_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldParticles: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_world_particles(stream, *obj.params_packet_world_particles); /*packet_world_particles*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateLight: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_update_light(stream, *obj.params_packet_update_light); /*packet_update_light*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Login: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_login(stream, *obj.params_packet_login); /*packet_login*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Map: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_map(stream, *obj.params_packet_map); /*packet_map*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TradeList: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_trade_list(stream, *obj.params_packet_trade_list); /*packet_trade_list*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::RelEntityMove: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_rel_entity_move(stream, *obj.params_packet_rel_entity_move); /*packet_rel_entity_move*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityMoveLook: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_move_look(stream, *obj.params_packet_entity_move_look); /*packet_entity_move_look*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityLook: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_look(stream, *obj.params_packet_entity_look); /*packet_entity_look*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::VehicleMove: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_vehicle_move(stream, *obj.params_packet_vehicle_move); /*packet_vehicle_move*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenBook: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_open_book(stream, *obj.params_packet_open_book); /*packet_open_book*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenSignEntity: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_open_sign_entity(stream, *obj.params_packet_open_sign_entity); /*packet_open_sign_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CraftRecipeResponse: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_craft_recipe_response(stream, *obj.params_packet_craft_recipe_response); /*packet_craft_recipe_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Abilities: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_abilities(stream, *obj.params_packet_abilities); /*packet_abilities*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EndCombatEvent: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_end_combat_event(stream, *obj.params_packet_end_combat_event); /*packet_end_combat_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EnterCombatEvent: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_enter_combat_event(stream, *obj.params_packet_enter_combat_event); /*packet_enter_combat_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeathCombatEvent: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_death_combat_event(stream, *obj.params_packet_death_combat_event); /*packet_death_combat_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::PlayerInfo: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_player_info(stream, *obj.params_packet_player_info); /*packet_player_info*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Position: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_position(stream, *obj.params_packet_position); /*packet_position*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UnlockRecipes: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_unlock_recipes(stream, *obj.params_packet_unlock_recipes); /*packet_unlock_recipes*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityDestroy: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_destroy(stream, *obj.params_packet_entity_destroy); /*packet_entity_destroy*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::RemoveEntityEffect: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_remove_entity_effect(stream, *obj.params_packet_remove_entity_effect); /*packet_remove_entity_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ResourcePackSend: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_resource_pack_send(stream, *obj.params_packet_resource_pack_send); /*packet_resource_pack_send*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Respawn: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_respawn(stream, *obj.params_packet_respawn); /*packet_respawn*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityUpdateAttributes: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_update_attributes(stream, *obj.params_packet_entity_update_attributes); /*packet_entity_update_attributes*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Camera: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_camera(stream, *obj.params_packet_camera); /*packet_camera*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::HeldItemSlot: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_held_item_slot(stream, *obj.params_packet_held_item_slot); /*packet_held_item_slot*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateViewPosition: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_update_view_position(stream, *obj.params_packet_update_view_position); /*packet_update_view_position*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateViewDistance: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_update_view_distance(stream, *obj.params_packet_update_view_distance); /*packet_update_view_distance*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardDisplayObjective: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_scoreboard_display_objective(stream, *obj.params_packet_scoreboard_display_objective); /*packet_scoreboard_display_objective*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityMetadata: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_metadata(stream, *obj.params_packet_entity_metadata); /*packet_entity_metadata*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::AttachEntity: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_attach_entity(stream, *obj.params_packet_attach_entity); /*packet_attach_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityVelocity: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_velocity(stream, *obj.params_packet_entity_velocity); /*packet_entity_velocity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityEquipment: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_equipment(stream, *obj.params_packet_entity_equipment); /*packet_entity_equipment*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Experience: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_experience(stream, *obj.params_packet_experience); /*packet_experience*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateHealth: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_update_health(stream, *obj.params_packet_update_health); /*packet_update_health*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardObjective: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_scoreboard_objective(stream, *obj.params_packet_scoreboard_objective); /*packet_scoreboard_objective*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetPassengers: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_set_passengers(stream, *obj.params_packet_set_passengers); /*packet_set_passengers*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Teams: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_teams(stream, *obj.params_packet_teams); /*packet_teams*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardScore: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_scoreboard_score(stream, *obj.params_packet_scoreboard_score); /*packet_scoreboard_score*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SimulationDistance: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_simulation_distance(stream, *obj.params_packet_simulation_distance); /*packet_simulation_distance*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnPosition: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_spawn_position(stream, *obj.params_packet_spawn_position); /*packet_spawn_position*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateTime: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_update_time(stream, *obj.params_packet_update_time); /*packet_update_time*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntitySoundEffect: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_sound_effect(stream, *obj.params_packet_entity_sound_effect); /*packet_entity_sound_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::StopSound: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_stop_sound(stream, *obj.params_packet_stop_sound); /*packet_stop_sound*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SoundEffect: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_sound_effect(stream, *obj.params_packet_sound_effect); /*packet_sound_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::PlayerlistHeader: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_playerlist_header(stream, *obj.params_packet_playerlist_header); /*packet_playerlist_header*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Collect: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_collect(stream, *obj.params_packet_collect); /*packet_collect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityTeleport: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_teleport(stream, *obj.params_packet_entity_teleport); /*packet_entity_teleport*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityHeadRotation: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_head_rotation(stream, *obj.params_packet_entity_head_rotation); /*packet_entity_head_rotation*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityEffect: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_entity_effect(stream, *obj.params_packet_entity_effect); /*packet_entity_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SelectAdvancementTab: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_select_advancement_tab(stream, *obj.params_packet_select_advancement_tab); /*packet_select_advancement_tab*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeclareRecipes: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_declare_recipes(stream, *obj.params_packet_declare_recipes); /*packet_declare_recipes*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Tags: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_tags(stream, *obj.params_packet_tags); /*packet_tags*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::AcknowledgePlayerDigging: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_acknowledge_player_digging(stream, *obj.params_packet_acknowledge_player_digging); /*packet_acknowledge_player_digging*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SculkVibrationSignal: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_sculk_vibration_signal(stream, *obj.params_packet_sculk_vibration_signal); /*packet_sculk_vibration_signal*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ClearTitles: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_clear_titles(stream, *obj.params_packet_clear_titles); /*packet_clear_titles*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::InitializeWorldBorder: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_initialize_world_border(stream, *obj.params_packet_initialize_world_border); /*packet_initialize_world_border*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ActionBar: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_action_bar(stream, *obj.params_packet_action_bar); /*packet_action_bar*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderCenter: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_world_border_center(stream, *obj.params_packet_world_border_center); /*packet_world_border_center*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderLerpSize: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_world_border_lerp_size(stream, *obj.params_packet_world_border_lerp_size); /*packet_world_border_lerp_size*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderSize: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_world_border_size(stream, *obj.params_packet_world_border_size); /*packet_world_border_size*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderWarningDelay: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_world_border_warning_delay(stream, *obj.params_packet_world_border_warning_delay); /*packet_world_border_warning_delay*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderWarningReach: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_world_border_warning_reach(stream, *obj.params_packet_world_border_warning_reach); /*packet_world_border_warning_reach*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Ping: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_ping(stream, *obj.params_packet_ping); /*packet_ping*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleSubtitle: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_set_title_subtitle(stream, *obj.params_packet_set_title_subtitle); /*packet_set_title_subtitle*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleText: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_set_title_text(stream, *obj.params_packet_set_title_text); /*packet_set_title_text*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleTime: { /*8.5*/
        pdef::pc1_18_play_toClient::encode::packet_set_title_time(stream, *obj.params_packet_set_title_time); /*packet_set_title_time*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

namespace pdef::pc1_18_play_toClient::decode {
bool slot(pdef::Stream &stream, pdef::pc1_18_play_toClient::slot &obj);
bool particle(pdef::Stream &stream, pdef::pc1_18_play_toClient::particle &obj);
bool minecraft_smelting_format(pdef::Stream &stream, pdef::pc1_18_play_toClient::minecraft_smelting_format &obj);
bool tags(pdef::Stream &stream, pdef::pc1_18_play_toClient::tags &obj);
bool chunkBlockEntity(pdef::Stream &stream, pdef::pc1_18_play_toClient::chunkBlockEntity &obj);
bool command_node(pdef::Stream &stream, pdef::pc1_18_play_toClient::command_node &obj);
bool packet_spawn_entity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity &obj);
bool packet_spawn_entity_experience_orb(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity_experience_orb &obj);
bool packet_spawn_entity_living(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity_living &obj);
bool packet_spawn_entity_painting(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity_painting &obj);
bool packet_named_entity_spawn(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_named_entity_spawn &obj);
bool packet_animation(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_animation &obj);
bool packet_statistics(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_statistics &obj);
bool packet_advancements(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_advancements &obj);
bool packet_block_break_animation(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_block_break_animation &obj);
bool packet_tile_entity_data(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_tile_entity_data &obj);
bool packet_block_action(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_block_action &obj);
bool packet_block_change(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_block_change &obj);
bool packet_boss_bar(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_boss_bar &obj);
bool packet_difficulty(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_difficulty &obj);
bool packet_tab_complete(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_tab_complete &obj);
bool packet_declare_commands(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_declare_commands &obj);
bool packet_face_player(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_face_player &obj);
bool packet_nbt_query_response(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_nbt_query_response &obj);
bool packet_chat(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_chat &obj);
bool packet_multi_block_change(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_multi_block_change &obj);
bool packet_close_window(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_close_window &obj);
bool packet_open_window(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_window &obj);
bool packet_window_items(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_window_items &obj);
bool packet_craft_progress_bar(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_craft_progress_bar &obj);
bool packet_set_slot(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_slot &obj);
bool packet_set_cooldown(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_cooldown &obj);
bool packet_custom_payload(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_custom_payload &obj);
bool packet_named_sound_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_named_sound_effect &obj);
bool packet_kick_disconnect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_kick_disconnect &obj);
bool packet_entity_status(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_status &obj);
bool packet_explosion(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_explosion &obj);
bool packet_unload_chunk(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_unload_chunk &obj);
bool packet_game_state_change(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_game_state_change &obj);
bool packet_open_horse_window(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_horse_window &obj);
bool packet_keep_alive(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_keep_alive &obj);
bool packet_map_chunk(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_map_chunk &obj);
bool packet_world_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_event &obj);
bool packet_world_particles(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_particles &obj);
bool packet_update_light(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_light &obj);
bool packet_login(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_login &obj);
bool packet_map(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_map &obj);
bool packet_trade_list(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_trade_list &obj);
bool packet_rel_entity_move(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_rel_entity_move &obj);
bool packet_entity_move_look(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_move_look &obj);
bool packet_entity_look(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_look &obj);
bool packet_vehicle_move(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_vehicle_move &obj);
bool packet_open_book(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_book &obj);
bool packet_open_sign_entity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_sign_entity &obj);
bool packet_craft_recipe_response(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_craft_recipe_response &obj);
bool packet_abilities(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_abilities &obj);
bool packet_end_combat_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_end_combat_event &obj);
bool packet_enter_combat_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_enter_combat_event &obj);
bool packet_death_combat_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_death_combat_event &obj);
bool packet_player_info(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_player_info &obj);
bool packet_position(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_position &obj);
bool packet_unlock_recipes(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_unlock_recipes &obj);
bool packet_entity_destroy(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_destroy &obj);
bool packet_remove_entity_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_remove_entity_effect &obj);
bool packet_resource_pack_send(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_resource_pack_send &obj);
bool packet_respawn(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_respawn &obj);
bool packet_entity_head_rotation(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_head_rotation &obj);
bool packet_camera(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_camera &obj);
bool packet_held_item_slot(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_held_item_slot &obj);
bool packet_update_view_position(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_view_position &obj);
bool packet_update_view_distance(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_view_distance &obj);
bool packet_scoreboard_display_objective(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_scoreboard_display_objective &obj);
bool packet_entity_metadata(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_metadata &obj);
bool packet_attach_entity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_attach_entity &obj);
bool packet_entity_velocity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_velocity &obj);
bool packet_entity_equipment(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_equipment &obj);
bool packet_experience(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_experience &obj);
bool packet_update_health(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_health &obj);
bool packet_scoreboard_objective(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_scoreboard_objective &obj);
bool packet_set_passengers(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_passengers &obj);
bool packet_teams(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_teams &obj);
bool packet_scoreboard_score(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_scoreboard_score &obj);
bool packet_spawn_position(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_position &obj);
bool packet_update_time(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_time &obj);
bool packet_entity_sound_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_sound_effect &obj);
bool packet_stop_sound(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_stop_sound &obj);
bool packet_sound_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_sound_effect &obj);
bool packet_playerlist_header(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_playerlist_header &obj);
bool packet_collect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_collect &obj);
bool packet_entity_teleport(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_teleport &obj);
bool packet_entity_update_attributes(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_update_attributes &obj);
bool packet_entity_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_effect &obj);
bool packet_select_advancement_tab(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_select_advancement_tab &obj);
bool packet_declare_recipes(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_declare_recipes &obj);
bool packet_tags(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_tags &obj);
bool packet_acknowledge_player_digging(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_acknowledge_player_digging &obj);
bool packet_sculk_vibration_signal(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_sculk_vibration_signal &obj);
bool packet_clear_titles(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_clear_titles &obj);
bool packet_initialize_world_border(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_initialize_world_border &obj);
bool packet_action_bar(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_action_bar &obj);
bool packet_world_border_center(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_center &obj);
bool packet_world_border_lerp_size(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_lerp_size &obj);
bool packet_world_border_size(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_size &obj);
bool packet_world_border_warning_delay(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_warning_delay &obj);
bool packet_world_border_warning_reach(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_warning_reach &obj);
bool packet_ping(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_ping &obj);
bool packet_set_title_subtitle(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_title_subtitle &obj);
bool packet_set_title_text(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_title_text &obj);
bool packet_set_title_time(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_title_time &obj);
bool packet_simulation_distance(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_simulation_distance &obj);
bool packet(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet &obj);
  bool slot(pdef::Stream &stream, pdef::pc1_18_play_toClient::slot &obj) {
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
  bool particle(pdef::Stream &stream, pdef::pc1_18_play_toClient::particle &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.particleId); /*0.5*/
    int &particleId = obj.particleId; /*0.6*/
    if (particleId == 2) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 3) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 14) { /*8.2*/
         obj.data_14 = {}; pdef::pc1_18_play_toClient::particle::Data14 &v = *obj.data_14; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.red); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.green); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.blue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
    }
    else if (particleId == 15) { /*8.2*/
         obj.data_15 = {}; pdef::pc1_18_play_toClient::particle::Data15 &v = *obj.data_15; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.fromRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromBlue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toBlue); /*0.5*/
    }
    else if (particleId == 24) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toClient::particle::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 35) { /*8.2*/
         obj.data_35 = {}; pdef::pc1_18_play_toClient::particle::Data35 &v = *obj.data_35; /*8.4*/
        READ_OR_BAIL(readByte, v.item); /*0.5*/
    }
    else if (particleId == 36) { /*8.2*/
         obj.data_36 = {}; pdef::pc1_18_play_toClient::particle::Data36 &v = *obj.data_36; /*8.4*/
        uint8_t origin_val;
        READ_OR_BAIL(readUByte, origin_val);
        v.origin.x = origin_val >> 0 & 26;
        v.origin.z = origin_val >> 26 & 26;
        v.origin.y = origin_val >> 52 & 12; /*origin: bitfield*/ /*4.3*/
        int positionType_strlen; READ_OR_BAIL(readUnsignedVarInt, positionType_strlen);
        if (!stream.readString(v.positionType, positionType_strlen)) return false; /*positionType: pstring*/ /*4.3*/
        pdef::pc1_18_play_toClient::particle::Data36::pstring &positionType = v.positionType; /*0.7*/
        if (positionType == pdef::pc1_18_play_toClient::particle::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val;
          READ_OR_BAIL(readUByte, destination_position_val);
          v.destination_position.x = destination_position_val >> 0 & 26;
          v.destination_position.z = destination_position_val >> 26 & 26;
          v.destination_position.y = destination_position_val >> 52 & 12; /*destination_position: bitfield*/ /*4.3*/
        }
        else if (positionType == pdef::pc1_18_play_toClient::particle::Data36::PositionType::MinecraftEntity) { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.destination_varint); /*0.5*/
        }
        READ_OR_BAIL(readUnsignedVarInt, v.ticks); /*0.5*/
    }
    return true;
  }
  bool minecraft_smelting_format(pdef::Stream &stream, pdef::pc1_18_play_toClient::minecraft_smelting_format &obj) {
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
bool tags(pdef::Stream &stream, pdef::pc1_18_play_toClient::tags &obj) {
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
  bool chunkBlockEntity(pdef::Stream &stream, pdef::pc1_18_play_toClient::chunkBlockEntity &obj) {
    uint8_t _3_val;
    READ_OR_BAIL(readUByte, _3_val);
    obj._3.x = _3_val >> 0 & 4;
    obj._3.z = _3_val >> 4 & 4; /*_3: bitfield*/ /*4.3*/
    READ_OR_BAIL(readShortBE, obj.y); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbtData); /*0.5*/
    return true;
  }
  bool command_node(pdef::Stream &stream, pdef::pc1_18_play_toClient::command_node &obj) {
    uint8_t flags_val;
    READ_OR_BAIL(readUByte, flags_val);
    obj.flags.unused = flags_val >> 0 & 3;
    obj.flags.has_custom_suggestions = flags_val >> 3 & 1;
    obj.flags.has_redirect_node = flags_val >> 4 & 1;
    obj.flags.has_command = flags_val >> 5 & 1;
    obj.flags.command_node_type = flags_val >> 6 & 2; /*flags: bitfield*/ /*4.3*/
    pdef::pc1_18_play_toClient::command_node::bitfield &flags = obj.flags; /*0.7*/
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
         obj.extraNodeData_1 = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData1 &v = *obj.extraNodeData_1; /*8.4*/
        int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
        if (!stream.readString(v.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    }
    else if (flags.command_node_type == 2) { /*8.2*/
         obj.extraNodeData_2 = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2 &v = *obj.extraNodeData_2; /*8.4*/
        int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
        if (!stream.readString(v.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
        int parser_strlen; READ_OR_BAIL(readUnsignedVarInt, parser_strlen);
        if (!stream.readString(v.parser, parser_strlen)) return false; /*parser: pstring*/ /*4.3*/
        pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::pstring &parser = v.parser; /*0.7*/
        if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierBool) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierFloat) { /*8.5*/
             v.properties_brigadier_float = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierFloat &v = *v.properties_brigadier_float; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierFloat::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readFloatBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readFloatBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierDouble) { /*8.5*/
             v.properties_brigadier_double = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierDouble &v = *v.properties_brigadier_double; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierDouble::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readDoubleBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readDoubleBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierInteger) { /*8.5*/
             v.properties_brigadier_integer = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierInteger &v = *v.properties_brigadier_integer; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierInteger::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readIntBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readIntBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierLong) { /*8.5*/
             v.properties_brigadier_long = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierLong &v = *v.properties_brigadier_long; /*8.4*/
            uint8_t flags_val;
            READ_OR_BAIL(readUByte, flags_val);
            v.flags.unused = flags_val >> 0 & 6;
            v.flags.max_present = flags_val >> 6 & 1;
            v.flags.min_present = flags_val >> 7 & 1; /*flags: bitfield*/ /*4.3*/
            pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesBrigadierLong::bitfield &flags = v.flags; /*0.7*/
            if (flags.min_present == 1) { /*8.2*/
              READ_OR_BAIL(readLongBE, v.min); /*0.5*/
            }
            if (flags.max_present == 1) { /*8.2*/
              READ_OR_BAIL(readLongBE, v.max); /*0.5*/
            }
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::BrigadierString) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntity) { /*8.5*/
          uint8_t properties_minecraft_entity_val;
          READ_OR_BAIL(readUByte, properties_minecraft_entity_val);
          v.properties_minecraft_entity.unused = properties_minecraft_entity_val >> 0 & 6;
          v.properties_minecraft_entity.onlyAllowPlayers = properties_minecraft_entity_val >> 6 & 1;
          v.properties_minecraft_entity.onlyAllowEntities = properties_minecraft_entity_val >> 7 & 1; /*properties_minecraft_entity: bitfield*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftGameProfile) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftColumnPos) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftVec3) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftVec2) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockState) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftBlockPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemStack) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemPredicate) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftColor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftComponent) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftMessage) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbt) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbtPath) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftObjective) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftObjectiveCriteria) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftOperation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftParticle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftAngle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftRotation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftScoreboardSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftScoreHolder) { /*8.5*/
          uint8_t properties_minecraft_score_holder_val;
          READ_OR_BAIL(readUByte, properties_minecraft_score_holder_val);
          v.properties_minecraft_score_holder.unused = properties_minecraft_score_holder_val >> 0 & 7;
          v.properties_minecraft_score_holder.allowMultiple = properties_minecraft_score_holder_val >> 7 & 1; /*properties_minecraft_score_holder: bitfield*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftSwizzle) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftTeam) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemSlot) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResourceLocation) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftMobEffect) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftFunction) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntityAnchor) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftRange) { /*8.5*/
             v.properties_minecraft_range = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftRange &v = *v.properties_minecraft_range; /*8.4*/
            READ_OR_BAIL(readBool, (bool&)v.allowDecimals); /*0.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftIntRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftFloatRange) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftItemEnchantment) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftEntitySummon) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftDimension) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftNbtCompoundTag) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftTime) { /*8.5*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResourceOrTag) { /*8.5*/
             v.properties_minecraft_resource_or_tag_or_minecraft_resource = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.4*/
            int registry_strlen; READ_OR_BAIL(readUnsignedVarInt, registry_strlen);
            if (!stream.readString(v.registry, registry_strlen)) return false; /*registry: pstring*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftResource) { /*8.5*/
             v.properties_minecraft_resource_or_tag_or_minecraft_resource = {}; pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::PropertiesMinecraftResourceOrTagOrMinecraftResource &v = *v.properties_minecraft_resource_or_tag_or_minecraft_resource; /*8.4*/
            int registry_strlen; READ_OR_BAIL(readUnsignedVarInt, registry_strlen);
            if (!stream.readString(v.registry, registry_strlen)) return false; /*registry: pstring*/ /*4.3*/
        }
        else if (parser == pdef::pc1_18_play_toClient::command_node::ExtraNodeData2::Parser::MinecraftUuid) { /*8.5*/
        }
        if (flags.has_custom_suggestions == 1) { /*8.2*/
          int suggestionType_strlen; READ_OR_BAIL(readUnsignedVarInt, suggestionType_strlen);
          if (!stream.readString(v.suggestionType, suggestionType_strlen)) return false; /*suggestionType: pstring*/ /*4.3*/
        }
    }
    return true;
  }
  bool packet_spawn_entity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readULongBE, obj.objectUUID); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readByte, obj.pitch); /*0.5*/
    READ_OR_BAIL(readByte, obj.yaw); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.objectData); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityX); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityY); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityZ); /*0.5*/
    return true;
  }
  bool packet_spawn_entity_experience_orb(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity_experience_orb &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.count); /*0.5*/
    return true;
  }
  bool packet_spawn_entity_living(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity_living &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readULongBE, obj.entityUUID); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readByte, obj.yaw); /*0.5*/
    READ_OR_BAIL(readByte, obj.pitch); /*0.5*/
    READ_OR_BAIL(readByte, obj.headPitch); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityX); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityY); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityZ); /*0.5*/
    return true;
  }
  bool packet_spawn_entity_painting(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_entity_painting &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readULongBE, obj.entityUUID); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.title); /*0.5*/
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUByte, obj.direction); /*0.5*/
    return true;
  }
  bool packet_named_entity_spawn(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_named_entity_spawn &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readULongBE, obj.playerUUID); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readByte, obj.yaw); /*0.5*/
    READ_OR_BAIL(readByte, obj.pitch); /*0.5*/
    return true;
  }
  bool packet_animation(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_animation &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readUByte, obj.animation); /*0.5*/
    return true;
  }
  bool packet_statistics(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_statistics &obj) {
    int entries_len; READ_OR_BAIL(readUnsignedVarInt, entries_len); /*1.5*/
    obj.entries.resize(entries_len); /*1.6*/
    for (int i = 0; i < entries_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_statistics::Entries &v2 = obj.entries[i]; /*5.23*/
      READ_OR_BAIL(readUnsignedVarInt, v2.categoryId); /*0.5*/
      READ_OR_BAIL(readUnsignedVarInt, v2.statisticId); /*0.5*/
      READ_OR_BAIL(readUnsignedVarInt, v2.value); /*0.5*/
    }
    return true;
  }
  bool packet_advancements(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_advancements &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.reset); /*0.5*/
    int advancementMapping_len; READ_OR_BAIL(readUnsignedVarInt, advancementMapping_len); /*1.5*/
    obj.advancementMapping.resize(advancementMapping_len); /*1.6*/
    for (int i = 0; i < advancementMapping_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_advancements::AdvancementMapping &v2 = obj.advancementMapping[i]; /*5.23*/
      int key_strlen; READ_OR_BAIL(readUnsignedVarInt, key_strlen);
      if (!stream.readString(v2.key, key_strlen)) return false; /*key: pstring*/ /*4.3*/
      const pdef::pc1_18_play_toClient::packet_advancements::AdvancementMapping::Value &v = v2.value = {}; /*["packet_advancements","AdvancementMapping"]*/ /*7.3*/
    }
    int identifiers_len; READ_OR_BAIL(readUnsignedVarInt, identifiers_len); /*1.5*/
    obj.identifiers.resize(identifiers_len); /*1.6*/
    for (int i = 0; i < identifiers_len; i++) {
      auto &v2 = obj.identifiers[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    int progressMapping_len; READ_OR_BAIL(readUnsignedVarInt, progressMapping_len); /*1.5*/
    obj.progressMapping.resize(progressMapping_len); /*1.6*/
    for (int i = 0; i < progressMapping_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_advancements::ProgressMapping &v2 = obj.progressMapping[i]; /*5.23*/
      int key_strlen; READ_OR_BAIL(readUnsignedVarInt, key_strlen);
      if (!stream.readString(v2.key, key_strlen)) return false; /*key: pstring*/ /*4.3*/
      int value_len; READ_OR_BAIL(readUnsignedVarInt, value_len); /*1.5*/
      v2.value.resize(value_len); /*1.6*/
      for (int i = 0; i < value_len; i++) { /*5*/
        pdef::pc1_18_play_toClient::packet_advancements::ProgressMapping::Value &v3 = v2.value[i]; /*5.23*/
        int criterionIdentifier_strlen; READ_OR_BAIL(readUnsignedVarInt, criterionIdentifier_strlen);
        if (!stream.readString(v3.criterionIdentifier, criterionIdentifier_strlen)) return false; /*criterionIdentifier: pstring*/ /*4.3*/
        const pdef::pc1_18_play_toClient::packet_advancements::ProgressMapping::Value::CriterionProgress &v = v3.criterionProgress = {}; /*["packet_advancements","ProgressMapping","Value"]*/ /*7.3*/
      }
    }
    return true;
  }
  bool packet_block_break_animation(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_block_break_animation &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.destroyStage); /*0.5*/
    return true;
  }
  bool packet_tile_entity_data(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_tile_entity_data &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbtData); /*0.5*/
    return true;
  }
  bool packet_block_action(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_block_action &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUByte, obj.byte1); /*0.5*/
    READ_OR_BAIL(readUByte, obj.byte2); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.blockId); /*0.5*/
    return true;
  }
  bool packet_block_change(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_block_change &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    return true;
  }
  bool packet_boss_bar(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_boss_bar &obj) {
    READ_OR_BAIL(readULongBE, obj.entityUUID); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
    int &action = obj.action; /*0.6*/
    if (action == 0) { /*8.2*/
      int title_strlen; READ_OR_BAIL(readUnsignedVarInt, title_strlen);
      if (!stream.readString(obj.title, title_strlen)) return false; /*title: pstring*/ /*4.3*/
    }
    else if (action == 3) { /*8.2*/
      int title_strlen; READ_OR_BAIL(readUnsignedVarInt, title_strlen);
      if (!stream.readString(obj.title, title_strlen)) return false; /*title: pstring*/ /*4.3*/
    }
    if (action == 0) { /*8.2*/
      READ_OR_BAIL(readFloatBE, obj.health); /*0.5*/
    }
    else if (action == 2) { /*8.2*/
      READ_OR_BAIL(readFloatBE, obj.health); /*0.5*/
    }
    if (action == 0) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.color); /*0.5*/
    }
    else if (action == 4) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.color); /*0.5*/
    }
    if (action == 0) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.dividers); /*0.5*/
    }
    else if (action == 4) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.dividers); /*0.5*/
    }
    if (action == 0) { /*8.2*/
      READ_OR_BAIL(readUByte, obj.flags); /*0.5*/
    }
    else if (action == 5) { /*8.2*/
      READ_OR_BAIL(readUByte, obj.flags); /*0.5*/
    }
    return true;
  }
  bool packet_difficulty(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_difficulty &obj) {
    READ_OR_BAIL(readUByte, obj.difficulty); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.difficultyLocked); /*0.5*/
    return true;
  }
  bool packet_tab_complete(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_tab_complete &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.transactionId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.start); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.length); /*0.5*/
    int matches_len; READ_OR_BAIL(readUnsignedVarInt, matches_len); /*1.5*/
    obj.matches.resize(matches_len); /*1.6*/
    for (int i = 0; i < matches_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_tab_complete::Matches &v2 = obj.matches[i]; /*5.23*/
      int match_strlen; READ_OR_BAIL(readUnsignedVarInt, match_strlen);
      if (!stream.readString(v2.match, match_strlen)) return false; /*match: pstring*/ /*4.3*/
      const pdef::pc1_18_play_toClient::packet_tab_complete::Matches::Tooltip &v = v2.tooltip = {}; /*["packet_tab_complete","Matches"]*/ /*7.3*/
    }
    return true;
  }
  bool packet_declare_commands(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_declare_commands &obj) {
    int nodes_len; READ_OR_BAIL(readUnsignedVarInt, nodes_len); /*1.5*/
    obj.nodes.resize(nodes_len); /*1.6*/
    for (int i = 0; i < nodes_len; i++) {
      auto &v2 = obj.nodes[i]; /*3.4*/
      pdef::pc1_18_play_toClient::decode::command_node(stream, v2); /*v2*/ /*4.6*/
    }
    READ_OR_BAIL(readUnsignedVarInt, obj.rootIndex); /*0.5*/
    return true;
  }
  bool packet_face_player(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_face_player &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.feet_eyes); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.isEntity); /*0.5*/
    bool &isEntity = obj.isEntity; /*0.6*/
    if (isEntity == true) { /*8.1*/
      READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    }
    if (isEntity == true) { /*8.1*/
      int entity_feet_eyes_strlen; READ_OR_BAIL(readUnsignedVarInt, entity_feet_eyes_strlen);
      if (!stream.readString(obj.entity_feet_eyes, entity_feet_eyes_strlen)) return false; /*entity_feet_eyes: pstring*/ /*4.3*/
    }
    return true;
  }
  bool packet_nbt_query_response(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_nbt_query_response &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.transactionId); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_chat(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_chat &obj) {
    int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
    if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.position); /*0.5*/
    READ_OR_BAIL(readULongBE, obj.sender); /*0.5*/
    return true;
  }
  bool packet_multi_block_change(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_multi_block_change &obj) {
    uint8_t chunkCoordinates_val;
    READ_OR_BAIL(readUByte, chunkCoordinates_val);
    obj.chunkCoordinates.x = chunkCoordinates_val >> 0 & 22;
    obj.chunkCoordinates.z = chunkCoordinates_val >> 22 & 22;
    obj.chunkCoordinates.y = chunkCoordinates_val >> 44 & 20; /*chunkCoordinates: bitfield*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.notTrustEdges); /*0.5*/
    int records_len; READ_OR_BAIL(readUnsignedVarInt, records_len); /*1.5*/
    obj.records.resize(records_len); /*1.6*/
    for (int i = 0; i < records_len; i++) {
      auto &v2 = obj.records[i]; /*3.4*/
      READ_OR_BAIL(readUnsignedVarInt, v2); /*0.5*/
    }
    return true;
  }
  bool packet_close_window(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_close_window &obj) {
    READ_OR_BAIL(readUByte, obj.windowId); /*0.5*/
    return true;
  }
  bool packet_open_window(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_window &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.windowId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.inventoryType); /*0.5*/
    int windowTitle_strlen; READ_OR_BAIL(readUnsignedVarInt, windowTitle_strlen);
    if (!stream.readString(obj.windowTitle, windowTitle_strlen)) return false; /*windowTitle: pstring*/ /*4.3*/
    return true;
  }
  bool packet_window_items(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_window_items &obj) {
    READ_OR_BAIL(readUByte, obj.windowId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.stateId); /*0.5*/
    int items_len; READ_OR_BAIL(readUnsignedVarInt, items_len); /*1.5*/
    obj.items.resize(items_len); /*1.6*/
    for (int i = 0; i < items_len; i++) {
      auto &v2 = obj.items[i]; /*3.4*/
      READ_OR_BAIL(readByte, v2); /*0.5*/
    }
    READ_OR_BAIL(readByte, obj.carriedItem); /*0.5*/
    return true;
  }
  bool packet_craft_progress_bar(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_craft_progress_bar &obj) {
    READ_OR_BAIL(readUByte, obj.windowId); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.property); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.value); /*0.5*/
    return true;
  }
  bool packet_set_slot(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_slot &obj) {
    READ_OR_BAIL(readByte, obj.windowId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.stateId); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.slot); /*0.5*/
    READ_OR_BAIL(readByte, obj.item); /*0.5*/
    return true;
  }
  bool packet_set_cooldown(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_cooldown &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.itemID); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.cooldownTicks); /*0.5*/
    return true;
  }
  bool packet_custom_payload(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_custom_payload &obj) {
    int channel_strlen; READ_OR_BAIL(readUnsignedVarInt, channel_strlen);
    if (!stream.readString(obj.channel, channel_strlen)) return false; /*channel: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.data); /*0.5*/
    return true;
  }
  bool packet_named_sound_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_named_sound_effect &obj) {
    int soundName_strlen; READ_OR_BAIL(readUnsignedVarInt, soundName_strlen);
    if (!stream.readString(obj.soundName, soundName_strlen)) return false; /*soundName: pstring*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.soundCategory); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.x); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.y); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.volume); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    return true;
  }
  bool packet_kick_disconnect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_kick_disconnect &obj) {
    int reason_strlen; READ_OR_BAIL(readUnsignedVarInt, reason_strlen);
    if (!stream.readString(obj.reason, reason_strlen)) return false; /*reason: pstring*/ /*4.3*/
    return true;
  }
  bool packet_entity_status(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_status &obj) {
    READ_OR_BAIL(readIntBE, obj.entityId); /*0.5*/
    READ_OR_BAIL(readByte, obj.entityStatus); /*0.5*/
    return true;
  }
  bool packet_explosion(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_explosion &obj) {
    READ_OR_BAIL(readFloatBE, obj.x); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.y); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.radius); /*0.5*/
    int affectedBlockOffsets_len; READ_OR_BAIL(readUnsignedVarInt, affectedBlockOffsets_len); /*1.5*/
    obj.affectedBlockOffsets.resize(affectedBlockOffsets_len); /*1.6*/
    for (int i = 0; i < affectedBlockOffsets_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_explosion::AffectedBlockOffsets &v2 = obj.affectedBlockOffsets[i]; /*5.23*/
      READ_OR_BAIL(readByte, v2.x); /*0.5*/
      READ_OR_BAIL(readByte, v2.y); /*0.5*/
      READ_OR_BAIL(readByte, v2.z); /*0.5*/
    }
    READ_OR_BAIL(readFloatBE, obj.playerMotionX); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.playerMotionY); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.playerMotionZ); /*0.5*/
    return true;
  }
  bool packet_unload_chunk(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_unload_chunk &obj) {
    READ_OR_BAIL(readIntBE, obj.chunkX); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.chunkZ); /*0.5*/
    return true;
  }
  bool packet_game_state_change(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_game_state_change &obj) {
    READ_OR_BAIL(readUByte, obj.reason); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.gameMode); /*0.5*/
    return true;
  }
  bool packet_open_horse_window(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_horse_window &obj) {
    READ_OR_BAIL(readUByte, obj.windowId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.nbSlots); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.entityId); /*0.5*/
    return true;
  }
  bool packet_keep_alive(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_keep_alive &obj) {
    READ_OR_BAIL(readLongBE, obj.keepAliveId); /*0.5*/
    return true;
  }
  bool packet_map_chunk(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_map_chunk &obj) {
    READ_OR_BAIL(readIntBE, obj.x); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.z); /*0.5*/
    READ_OR_BAIL(readByte, obj.heightmaps); /*0.5*/
    int chunkData_len; READ_OR_BAIL(readUnsignedVarInt, chunkData_len);if (!stream.readBuffer(obj.chunkData, chunkData_len)) return false; /*chunkData: buffer*/ /*4.3*/
    int blockEntities_len; READ_OR_BAIL(readUnsignedVarInt, blockEntities_len); /*1.5*/
    obj.blockEntities.resize(blockEntities_len); /*1.6*/
    for (int i = 0; i < blockEntities_len; i++) {
      auto &v2 = obj.blockEntities[i]; /*3.4*/
      pdef::pc1_18_play_toClient::decode::chunkBlockEntity(stream, v2); /*v2*/ /*4.6*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.trustEdges); /*0.5*/
    int skyLightMask_len; READ_OR_BAIL(readUnsignedVarInt, skyLightMask_len); /*1.5*/
    obj.skyLightMask.resize(skyLightMask_len); /*1.6*/
    for (int i = 0; i < skyLightMask_len; i++) {
      auto &v2 = obj.skyLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int blockLightMask_len; READ_OR_BAIL(readUnsignedVarInt, blockLightMask_len); /*1.5*/
    obj.blockLightMask.resize(blockLightMask_len); /*1.6*/
    for (int i = 0; i < blockLightMask_len; i++) {
      auto &v2 = obj.blockLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int emptySkyLightMask_len; READ_OR_BAIL(readUnsignedVarInt, emptySkyLightMask_len); /*1.5*/
    obj.emptySkyLightMask.resize(emptySkyLightMask_len); /*1.6*/
    for (int i = 0; i < emptySkyLightMask_len; i++) {
      auto &v2 = obj.emptySkyLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int emptyBlockLightMask_len; READ_OR_BAIL(readUnsignedVarInt, emptyBlockLightMask_len); /*1.5*/
    obj.emptyBlockLightMask.resize(emptyBlockLightMask_len); /*1.6*/
    for (int i = 0; i < emptyBlockLightMask_len; i++) {
      auto &v2 = obj.emptyBlockLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int skyLight_len; READ_OR_BAIL(readUnsignedVarInt, skyLight_len); /*1.5*/
    obj.skyLight.resize(skyLight_len); /*1.6*/
    for (int i = 0; i < skyLight_len; i++) { /*5.2*/
      int skyLight_len2; READ_OR_BAIL(readUnsignedVarInt, skyLight_len2); /*5.8*/
      obj.skyLight[i].resize(skyLight_len2); /*5.9*/
      for (int j = 0; j < skyLight_len2; j++) { /*5.11*/
        READ_OR_BAIL(readUByte, obj.skyLight[i][j]); /*5.14*/
      }
    }
    int blockLight_len; READ_OR_BAIL(readUnsignedVarInt, blockLight_len); /*1.5*/
    obj.blockLight.resize(blockLight_len); /*1.6*/
    for (int i = 0; i < blockLight_len; i++) { /*5.2*/
      int blockLight_len2; READ_OR_BAIL(readUnsignedVarInt, blockLight_len2); /*5.8*/
      obj.blockLight[i].resize(blockLight_len2); /*5.9*/
      for (int j = 0; j < blockLight_len2; j++) { /*5.11*/
        READ_OR_BAIL(readUByte, obj.blockLight[i][j]); /*5.14*/
      }
    }
    return true;
  }
  bool packet_world_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_event &obj) {
    READ_OR_BAIL(readIntBE, obj.effectId); /*0.5*/
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readIntBE, obj.data); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.global); /*0.5*/
    return true;
  }
  bool packet_world_particles(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_particles &obj) {
    READ_OR_BAIL(readIntBE, obj.particleId); /*0.5*/
    int32_t &particleId = obj.particleId; /*0.6*/
    READ_OR_BAIL(readBool, (bool&)obj.longDistance); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.offsetX); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.offsetY); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.offsetZ); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.particleData); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.particles); /*0.5*/
    if (particleId == 2) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 3) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 14) { /*8.2*/
         obj.data_14 = {}; pdef::pc1_18_play_toClient::packet_world_particles::Data14 &v = *obj.data_14; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.red); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.green); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.blue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
    }
    else if (particleId == 15) { /*8.2*/
         obj.data_15 = {}; pdef::pc1_18_play_toClient::packet_world_particles::Data15 &v = *obj.data_15; /*8.4*/
        READ_OR_BAIL(readFloatBE, v.fromRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.fromBlue); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.scale); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toRed); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toGreen); /*0.5*/
        READ_OR_BAIL(readFloatBE, v.toBlue); /*0.5*/
    }
    else if (particleId == 24) { /*8.2*/
         obj.data_2_or_3_or_24 = {}; pdef::pc1_18_play_toClient::packet_world_particles::Data2Or3Or24 &v = *obj.data_2_or_3_or_24; /*8.4*/
        READ_OR_BAIL(readUnsignedVarInt, v.blockState); /*0.5*/
    }
    else if (particleId == 35) { /*8.2*/
         obj.data_35 = {}; pdef::pc1_18_play_toClient::packet_world_particles::Data35 &v = *obj.data_35; /*8.4*/
        READ_OR_BAIL(readByte, v.item); /*0.5*/
    }
    else if (particleId == 36) { /*8.2*/
         obj.data_36 = {}; pdef::pc1_18_play_toClient::packet_world_particles::Data36 &v = *obj.data_36; /*8.4*/
        uint8_t origin_val;
        READ_OR_BAIL(readUByte, origin_val);
        v.origin.x = origin_val >> 0 & 26;
        v.origin.z = origin_val >> 26 & 26;
        v.origin.y = origin_val >> 52 & 12; /*origin: bitfield*/ /*4.3*/
        int positionType_strlen; READ_OR_BAIL(readUnsignedVarInt, positionType_strlen);
        if (!stream.readString(v.positionType, positionType_strlen)) return false; /*positionType: pstring*/ /*4.3*/
        pdef::pc1_18_play_toClient::packet_world_particles::Data36::pstring &positionType = v.positionType; /*0.7*/
        if (positionType == pdef::pc1_18_play_toClient::packet_world_particles::Data36::PositionType::MinecraftBlock) { /*8.5*/
          uint8_t destination_position_val;
          READ_OR_BAIL(readUByte, destination_position_val);
          v.destination_position.x = destination_position_val >> 0 & 26;
          v.destination_position.z = destination_position_val >> 26 & 26;
          v.destination_position.y = destination_position_val >> 52 & 12; /*destination_position: bitfield*/ /*4.3*/
        }
        else if (positionType == pdef::pc1_18_play_toClient::packet_world_particles::Data36::PositionType::MinecraftEntity) { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.destination_varint); /*0.5*/
        }
        READ_OR_BAIL(readUnsignedVarInt, v.ticks); /*0.5*/
    }
    return true;
  }
  bool packet_update_light(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_light &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.chunkX); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.chunkZ); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.trustEdges); /*0.5*/
    int skyLightMask_len; READ_OR_BAIL(readUnsignedVarInt, skyLightMask_len); /*1.5*/
    obj.skyLightMask.resize(skyLightMask_len); /*1.6*/
    for (int i = 0; i < skyLightMask_len; i++) {
      auto &v2 = obj.skyLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int blockLightMask_len; READ_OR_BAIL(readUnsignedVarInt, blockLightMask_len); /*1.5*/
    obj.blockLightMask.resize(blockLightMask_len); /*1.6*/
    for (int i = 0; i < blockLightMask_len; i++) {
      auto &v2 = obj.blockLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int emptySkyLightMask_len; READ_OR_BAIL(readUnsignedVarInt, emptySkyLightMask_len); /*1.5*/
    obj.emptySkyLightMask.resize(emptySkyLightMask_len); /*1.6*/
    for (int i = 0; i < emptySkyLightMask_len; i++) {
      auto &v2 = obj.emptySkyLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int emptyBlockLightMask_len; READ_OR_BAIL(readUnsignedVarInt, emptyBlockLightMask_len); /*1.5*/
    obj.emptyBlockLightMask.resize(emptyBlockLightMask_len); /*1.6*/
    for (int i = 0; i < emptyBlockLightMask_len; i++) {
      auto &v2 = obj.emptyBlockLightMask[i]; /*3.4*/
      READ_OR_BAIL(readLongBE, v2); /*0.5*/
    }
    int skyLight_len; READ_OR_BAIL(readUnsignedVarInt, skyLight_len); /*1.5*/
    obj.skyLight.resize(skyLight_len); /*1.6*/
    for (int i = 0; i < skyLight_len; i++) { /*5.2*/
      int skyLight_len2; READ_OR_BAIL(readUnsignedVarInt, skyLight_len2); /*5.8*/
      obj.skyLight[i].resize(skyLight_len2); /*5.9*/
      for (int j = 0; j < skyLight_len2; j++) { /*5.11*/
        READ_OR_BAIL(readUByte, obj.skyLight[i][j]); /*5.14*/
      }
    }
    int blockLight_len; READ_OR_BAIL(readUnsignedVarInt, blockLight_len); /*1.5*/
    obj.blockLight.resize(blockLight_len); /*1.6*/
    for (int i = 0; i < blockLight_len; i++) { /*5.2*/
      int blockLight_len2; READ_OR_BAIL(readUnsignedVarInt, blockLight_len2); /*5.8*/
      obj.blockLight[i].resize(blockLight_len2); /*5.9*/
      for (int j = 0; j < blockLight_len2; j++) { /*5.11*/
        READ_OR_BAIL(readUByte, obj.blockLight[i][j]); /*5.14*/
      }
    }
    return true;
  }
  bool packet_login(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_login &obj) {
    READ_OR_BAIL(readIntBE, obj.entityId); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.isHardcore); /*0.5*/
    READ_OR_BAIL(readUByte, obj.gameMode); /*0.5*/
    READ_OR_BAIL(readByte, obj.previousGameMode); /*0.5*/
    int worldNames_len; READ_OR_BAIL(readUnsignedVarInt, worldNames_len); /*1.5*/
    obj.worldNames.resize(worldNames_len); /*1.6*/
    for (int i = 0; i < worldNames_len; i++) {
      auto &v2 = obj.worldNames[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    READ_OR_BAIL(readByte, obj.dimensionCodec); /*0.5*/
    READ_OR_BAIL(readByte, obj.dimension); /*0.5*/
    int worldName_strlen; READ_OR_BAIL(readUnsignedVarInt, worldName_strlen);
    if (!stream.readString(obj.worldName, worldName_strlen)) return false; /*worldName: pstring*/ /*4.3*/
    READ_OR_BAIL(readLongBE, obj.hashedSeed); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.maxPlayers); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.viewDistance); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.simulationDistance); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.reducedDebugInfo); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.enableRespawnScreen); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.isDebug); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.isFlat); /*0.5*/
    return true;
  }
  bool packet_map(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_map &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.itemDamage); /*0.5*/
    READ_OR_BAIL(readByte, obj.scale); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.locked); /*0.5*/
    const pdef::pc1_18_play_toClient::packet_map::Icons &v = obj.icons = {}; /*["packet_map"]*/ /*7.3*/
    READ_OR_BAIL(readUByte, obj.columns); /*0.5*/
    uint8_t &columns = obj.columns; /*0.6*/
    if (columns == 0) { /*8.2*/
    }
    else {
      READ_OR_BAIL(readUByte, obj.rows); /*0.5*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      READ_OR_BAIL(readUByte, obj.x); /*0.5*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      READ_OR_BAIL(readUByte, obj.y); /*0.5*/
    }
    if (columns == 0) { /*8.2*/
    }
    else {
      int data_len; READ_OR_BAIL(readUnsignedVarInt, data_len);if (!stream.readBuffer(obj.data, data_len)) return false; /*data: buffer*/ /*4.3*/
    }
    return true;
  }
  bool packet_trade_list(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_trade_list &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.windowId); /*0.5*/
    uint8_t trades_len; READ_OR_BAIL(readUByte, trades_len); /*1.5*/
    obj.trades.resize(trades_len); /*1.6*/
    for (int i = 0; i < trades_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_trade_list::Trades &v2 = obj.trades[i]; /*5.23*/
      READ_OR_BAIL(readByte, v2.inputItem1); /*0.5*/
      READ_OR_BAIL(readByte, v2.outputItem); /*0.5*/
      const pdef::pc1_18_play_toClient::packet_trade_list::Trades::InputItem2 &v = v2.inputItem2 = {}; /*["packet_trade_list","Trades"]*/ /*7.3*/
      READ_OR_BAIL(readBool, (bool&)v2.tradeDisabled); /*0.5*/
      READ_OR_BAIL(readIntBE, v2.nbTradeUses); /*0.5*/
      READ_OR_BAIL(readIntBE, v2.maximumNbTradeUses); /*0.5*/
      READ_OR_BAIL(readIntBE, v2.xp); /*0.5*/
      READ_OR_BAIL(readIntBE, v2.specialPrice); /*0.5*/
      READ_OR_BAIL(readFloatBE, v2.priceMultiplier); /*0.5*/
      READ_OR_BAIL(readIntBE, v2.demand); /*0.5*/
    }
    READ_OR_BAIL(readUnsignedVarInt, obj.villagerLevel); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.experience); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.isRegularVillager); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.canRestock); /*0.5*/
    return true;
  }
  bool packet_rel_entity_move(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_rel_entity_move &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.dX); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.dY); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.dZ); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_entity_move_look(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_move_look &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.dX); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.dY); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.dZ); /*0.5*/
    READ_OR_BAIL(readByte, obj.yaw); /*0.5*/
    READ_OR_BAIL(readByte, obj.pitch); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_entity_look(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_look &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readByte, obj.yaw); /*0.5*/
    READ_OR_BAIL(readByte, obj.pitch); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_vehicle_move(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_vehicle_move &obj) {
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    return true;
  }
  bool packet_open_book(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_book &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.hand); /*0.5*/
    return true;
  }
  bool packet_open_sign_entity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_open_sign_entity &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    return true;
  }
  bool packet_craft_recipe_response(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_craft_recipe_response &obj) {
    READ_OR_BAIL(readByte, obj.windowId); /*0.5*/
    int recipe_strlen; READ_OR_BAIL(readUnsignedVarInt, recipe_strlen);
    if (!stream.readString(obj.recipe, recipe_strlen)) return false; /*recipe: pstring*/ /*4.3*/
    return true;
  }
  bool packet_abilities(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_abilities &obj) {
    READ_OR_BAIL(readByte, obj.flags); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.flyingSpeed); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.walkingSpeed); /*0.5*/
    return true;
  }
  bool packet_end_combat_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_end_combat_event &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.duration); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.entityId); /*0.5*/
    return true;
  }
  bool packet_enter_combat_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_enter_combat_event &obj) {
    return true;
  }
  bool packet_death_combat_event(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_death_combat_event &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.playerId); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.entityId); /*0.5*/
    int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
    if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
    return true;
  }
  bool packet_player_info(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_player_info &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
    int &action = obj.action; /*0.6*/
    int data_len; READ_OR_BAIL(readUnsignedVarInt, data_len); /*1.5*/
    obj.data.resize(data_len); /*1.6*/
    for (int i = 0; i < data_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_player_info::Data &v2 = obj.data[i]; /*5.23*/
      READ_OR_BAIL(readULongBE, v2.UUID); /*0.5*/
      if (action == 0) { /*8.2*/
        int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
        if (!stream.readString(v2.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
      }
      if (action == 0) { /*8.2*/
        int properties_len; READ_OR_BAIL(readUnsignedVarInt, properties_len); /*1.5*/
        v2.properties.resize(properties_len); /*1.6*/
        for (int i = 0; i < properties_len; i++) { /*5*/
          pdef::pc1_18_play_toClient::packet_player_info::Data::Properties &v4 = v2.properties[i]; /*5.23*/
          int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
          if (!stream.readString(v4.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
          int value_strlen; READ_OR_BAIL(readUnsignedVarInt, value_strlen);
          if (!stream.readString(v4.value, value_strlen)) return false; /*value: pstring*/ /*4.3*/
          const pdef::pc1_18_play_toClient::packet_player_info::Data::Properties::Signature &v = v4.signature = {}; /*["packet_player_info","Data","Properties"]*/ /*7.3*/
        }
      }
      if (action == 0) { /*8.2*/
        READ_OR_BAIL(readUnsignedVarInt, v2.gamemode); /*0.5*/
      }
      else if (action == 1) { /*8.2*/
        READ_OR_BAIL(readUnsignedVarInt, v2.gamemode); /*0.5*/
      }
      if (action == 0) { /*8.2*/
        READ_OR_BAIL(readUnsignedVarInt, v2.ping); /*0.5*/
      }
      else if (action == 2) { /*8.2*/
        READ_OR_BAIL(readUnsignedVarInt, v2.ping); /*0.5*/
      }
      if (action == 0) { /*8.2*/
           v2.displayName = {}; pdef::pc1_18_play_toClient::packet_player_info::Data::DisplayName &v = *v2.displayName; /*8.4*/
          READ_OR_BAIL(readBool, (bool&)v2.has); /*0.5*/
          bool &has = v2.has; /*0.6*/
          if (has == true) { /*8.1*/
            int value_strlen; READ_OR_BAIL(readUnsignedVarInt, value_strlen);
            if (!stream.readString(v2.value, value_strlen)) return false; /*value: pstring*/ /*4.3*/
          }
      }
      else if (action == 3) { /*8.2*/
           v2.displayName = {}; pdef::pc1_18_play_toClient::packet_player_info::Data::DisplayName &v = *v2.displayName; /*8.4*/
          READ_OR_BAIL(readBool, (bool&)v2.has); /*0.5*/
          bool &has = v2.has; /*0.6*/
          if (has == true) { /*8.1*/
            int value_strlen; READ_OR_BAIL(readUnsignedVarInt, value_strlen);
            if (!stream.readString(v2.value, value_strlen)) return false; /*value: pstring*/ /*4.3*/
          }
      }
    }
    return true;
  }
  bool packet_position(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_position &obj) {
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    READ_OR_BAIL(readByte, obj.flags); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.teleportId); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.dismountVehicle); /*0.5*/
    return true;
  }
  bool packet_unlock_recipes(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_unlock_recipes &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
    int &action = obj.action; /*0.6*/
    READ_OR_BAIL(readBool, (bool&)obj.craftingBookOpen); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.filteringCraftable); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.smeltingBookOpen); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.filteringSmeltable); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.blastFurnaceOpen); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.filteringBlastFurnace); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.smokerBookOpen); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.filteringSmoker); /*0.5*/
    int recipes1_len; READ_OR_BAIL(readUnsignedVarInt, recipes1_len); /*1.5*/
    obj.recipes1.resize(recipes1_len); /*1.6*/
    for (int i = 0; i < recipes1_len; i++) {
      auto &v2 = obj.recipes1[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    if (action == 0) { /*8.2*/
      int recipes2_len; READ_OR_BAIL(readUnsignedVarInt, recipes2_len); /*1.5*/
      obj.recipes2.resize(recipes2_len); /*1.6*/
      for (int i = 0; i < recipes2_len; i++) {
        auto &v3 = obj.recipes2[i]; /*3.4*/
        int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
        if (!stream.readString(v3, _strlen)) return false; /*: pstring*/ /*4.3*/
      }
    }
    return true;
  }
  bool packet_entity_destroy(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_destroy &obj) {
    int entityIds_len; READ_OR_BAIL(readUnsignedVarInt, entityIds_len); /*1.5*/
    obj.entityIds.resize(entityIds_len); /*1.6*/
    for (int i = 0; i < entityIds_len; i++) {
      auto &v2 = obj.entityIds[i]; /*3.4*/
      READ_OR_BAIL(readUnsignedVarInt, v2); /*0.5*/
    }
    return true;
  }
  bool packet_remove_entity_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_remove_entity_effect &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readByte, obj.effectId); /*0.5*/
    return true;
  }
  bool packet_resource_pack_send(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_resource_pack_send &obj) {
    int url_strlen; READ_OR_BAIL(readUnsignedVarInt, url_strlen);
    if (!stream.readString(obj.url, url_strlen)) return false; /*url: pstring*/ /*4.3*/
    int hash_strlen; READ_OR_BAIL(readUnsignedVarInt, hash_strlen);
    if (!stream.readString(obj.hash, hash_strlen)) return false; /*hash: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.forced); /*0.5*/
    const pdef::pc1_18_play_toClient::packet_resource_pack_send::PromptMessage &v = obj.promptMessage = {}; /*["packet_resource_pack_send"]*/ /*7.3*/
    return true;
  }
  bool packet_respawn(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_respawn &obj) {
    READ_OR_BAIL(readByte, obj.dimension); /*0.5*/
    int worldName_strlen; READ_OR_BAIL(readUnsignedVarInt, worldName_strlen);
    if (!stream.readString(obj.worldName, worldName_strlen)) return false; /*worldName: pstring*/ /*4.3*/
    READ_OR_BAIL(readLongBE, obj.hashedSeed); /*0.5*/
    READ_OR_BAIL(readUByte, obj.gamemode); /*0.5*/
    READ_OR_BAIL(readUByte, obj.previousGamemode); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.isDebug); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.isFlat); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.copyMetadata); /*0.5*/
    return true;
  }
  bool packet_entity_head_rotation(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_head_rotation &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readByte, obj.headYaw); /*0.5*/
    return true;
  }
  bool packet_camera(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_camera &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.cameraId); /*0.5*/
    return true;
  }
  bool packet_held_item_slot(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_held_item_slot &obj) {
    READ_OR_BAIL(readByte, obj.slot); /*0.5*/
    return true;
  }
  bool packet_update_view_position(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_view_position &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.chunkX); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.chunkZ); /*0.5*/
    return true;
  }
  bool packet_update_view_distance(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_view_distance &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.viewDistance); /*0.5*/
    return true;
  }
  bool packet_scoreboard_display_objective(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_scoreboard_display_objective &obj) {
    READ_OR_BAIL(readByte, obj.position); /*0.5*/
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    return true;
  }
  bool packet_entity_metadata(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_metadata &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readByte, obj.metadata); /*0.5*/
    return true;
  }
  bool packet_attach_entity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_attach_entity &obj) {
    READ_OR_BAIL(readIntBE, obj.entityId); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.vehicleId); /*0.5*/
    return true;
  }
  bool packet_entity_velocity(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_velocity &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityX); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityY); /*0.5*/
    READ_OR_BAIL(readShortBE, obj.velocityZ); /*0.5*/
    return true;
  }
  bool packet_entity_equipment(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_equipment &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readByte, obj.equipments); /*0.5*/
    return true;
  }
  bool packet_experience(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_experience &obj) {
    READ_OR_BAIL(readFloatBE, obj.experienceBar); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.level); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.totalExperience); /*0.5*/
    return true;
  }
  bool packet_update_health(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_health &obj) {
    READ_OR_BAIL(readFloatBE, obj.health); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.food); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.foodSaturation); /*0.5*/
    return true;
  }
  bool packet_scoreboard_objective(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_scoreboard_objective &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.action); /*0.5*/
    int8_t &action = obj.action; /*0.6*/
    if (action == 0) { /*8.2*/
      int displayText_strlen; READ_OR_BAIL(readUnsignedVarInt, displayText_strlen);
      if (!stream.readString(obj.displayText, displayText_strlen)) return false; /*displayText: pstring*/ /*4.3*/
    }
    else if (action == 2) { /*8.2*/
      int displayText_strlen; READ_OR_BAIL(readUnsignedVarInt, displayText_strlen);
      if (!stream.readString(obj.displayText, displayText_strlen)) return false; /*displayText: pstring*/ /*4.3*/
    }
    if (action == 0) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    }
    else if (action == 2) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.type); /*0.5*/
    }
    return true;
  }
  bool packet_set_passengers(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_passengers &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    int passengers_len; READ_OR_BAIL(readUnsignedVarInt, passengers_len); /*1.5*/
    obj.passengers.resize(passengers_len); /*1.6*/
    for (int i = 0; i < passengers_len; i++) {
      auto &v2 = obj.passengers[i]; /*3.4*/
      READ_OR_BAIL(readUnsignedVarInt, v2); /*0.5*/
    }
    return true;
  }
  bool packet_teams(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_teams &obj) {
    int team_strlen; READ_OR_BAIL(readUnsignedVarInt, team_strlen);
    if (!stream.readString(obj.team, team_strlen)) return false; /*team: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.mode); /*0.5*/
    int8_t &mode = obj.mode; /*0.6*/
    if (mode == 0) { /*8.2*/
      int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
      if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    }
    else if (mode == 2) { /*8.2*/
      int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
      if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    }
    if (mode == 0) { /*8.2*/
      READ_OR_BAIL(readByte, obj.friendlyFire); /*0.5*/
    }
    else if (mode == 2) { /*8.2*/
      READ_OR_BAIL(readByte, obj.friendlyFire); /*0.5*/
    }
    if (mode == 0) { /*8.2*/
      int nameTagVisibility_strlen; READ_OR_BAIL(readUnsignedVarInt, nameTagVisibility_strlen);
      if (!stream.readString(obj.nameTagVisibility, nameTagVisibility_strlen)) return false; /*nameTagVisibility: pstring*/ /*4.3*/
    }
    else if (mode == 2) { /*8.2*/
      int nameTagVisibility_strlen; READ_OR_BAIL(readUnsignedVarInt, nameTagVisibility_strlen);
      if (!stream.readString(obj.nameTagVisibility, nameTagVisibility_strlen)) return false; /*nameTagVisibility: pstring*/ /*4.3*/
    }
    if (mode == 0) { /*8.2*/
      int collisionRule_strlen; READ_OR_BAIL(readUnsignedVarInt, collisionRule_strlen);
      if (!stream.readString(obj.collisionRule, collisionRule_strlen)) return false; /*collisionRule: pstring*/ /*4.3*/
    }
    else if (mode == 2) { /*8.2*/
      int collisionRule_strlen; READ_OR_BAIL(readUnsignedVarInt, collisionRule_strlen);
      if (!stream.readString(obj.collisionRule, collisionRule_strlen)) return false; /*collisionRule: pstring*/ /*4.3*/
    }
    if (mode == 0) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.formatting); /*0.5*/
    }
    else if (mode == 2) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.formatting); /*0.5*/
    }
    if (mode == 0) { /*8.2*/
      int prefix_strlen; READ_OR_BAIL(readUnsignedVarInt, prefix_strlen);
      if (!stream.readString(obj.prefix, prefix_strlen)) return false; /*prefix: pstring*/ /*4.3*/
    }
    else if (mode == 2) { /*8.2*/
      int prefix_strlen; READ_OR_BAIL(readUnsignedVarInt, prefix_strlen);
      if (!stream.readString(obj.prefix, prefix_strlen)) return false; /*prefix: pstring*/ /*4.3*/
    }
    if (mode == 0) { /*8.2*/
      int suffix_strlen; READ_OR_BAIL(readUnsignedVarInt, suffix_strlen);
      if (!stream.readString(obj.suffix, suffix_strlen)) return false; /*suffix: pstring*/ /*4.3*/
    }
    else if (mode == 2) { /*8.2*/
      int suffix_strlen; READ_OR_BAIL(readUnsignedVarInt, suffix_strlen);
      if (!stream.readString(obj.suffix, suffix_strlen)) return false; /*suffix: pstring*/ /*4.3*/
    }
    if (mode == 0) { /*8.2*/
      int players_len; READ_OR_BAIL(readUnsignedVarInt, players_len); /*1.5*/
      obj.players.resize(players_len); /*1.6*/
      for (int i = 0; i < players_len; i++) {
        auto &v3 = obj.players[i]; /*3.4*/
        int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
        if (!stream.readString(v3, _strlen)) return false; /*: pstring*/ /*4.3*/
      }
    }
    else if (mode == 3) { /*8.2*/
      int players_len; READ_OR_BAIL(readUnsignedVarInt, players_len); /*1.5*/
      obj.players.resize(players_len); /*1.6*/
      for (int i = 0; i < players_len; i++) {
        auto &v3 = obj.players[i]; /*3.4*/
        int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
        if (!stream.readString(v3, _strlen)) return false; /*: pstring*/ /*4.3*/
      }
    }
    else if (mode == 4) { /*8.2*/
      int players_len; READ_OR_BAIL(readUnsignedVarInt, players_len); /*1.5*/
      obj.players.resize(players_len); /*1.6*/
      for (int i = 0; i < players_len; i++) {
        auto &v3 = obj.players[i]; /*3.4*/
        int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
        if (!stream.readString(v3, _strlen)) return false; /*: pstring*/ /*4.3*/
      }
    }
    return true;
  }
  bool packet_scoreboard_score(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_scoreboard_score &obj) {
    int itemName_strlen; READ_OR_BAIL(readUnsignedVarInt, itemName_strlen);
    if (!stream.readString(obj.itemName, itemName_strlen)) return false; /*itemName: pstring*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
    int &action = obj.action; /*0.6*/
    int scoreName_strlen; READ_OR_BAIL(readUnsignedVarInt, scoreName_strlen);
    if (!stream.readString(obj.scoreName, scoreName_strlen)) return false; /*scoreName: pstring*/ /*4.3*/
    if (action == 1) { /*8.2*/
    }
    else {
      READ_OR_BAIL(readUnsignedVarInt, obj.value); /*0.5*/
    }
    return true;
  }
  bool packet_spawn_position(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_spawn_position &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readFloatBE, obj.angle); /*0.5*/
    return true;
  }
  bool packet_update_time(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_update_time &obj) {
    READ_OR_BAIL(readLongBE, obj.age); /*0.5*/
    READ_OR_BAIL(readLongBE, obj.time); /*0.5*/
    return true;
  }
  bool packet_entity_sound_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_sound_effect &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.soundId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.soundCategory); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.volume); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    return true;
  }
  bool packet_stop_sound(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_stop_sound &obj) {
    READ_OR_BAIL(readByte, obj.flags); /*0.5*/
    int8_t &flags = obj.flags; /*0.6*/
    if (flags == 1) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.source); /*0.5*/
    }
    else if (flags == 3) { /*8.2*/
      READ_OR_BAIL(readUnsignedVarInt, obj.source); /*0.5*/
    }
    if (flags == 2) { /*8.2*/
      int sound_strlen; READ_OR_BAIL(readUnsignedVarInt, sound_strlen);
      if (!stream.readString(obj.sound, sound_strlen)) return false; /*sound: pstring*/ /*4.3*/
    }
    else if (flags == 3) { /*8.2*/
      int sound_strlen; READ_OR_BAIL(readUnsignedVarInt, sound_strlen);
      if (!stream.readString(obj.sound, sound_strlen)) return false; /*sound: pstring*/ /*4.3*/
    }
    return true;
  }
  bool packet_sound_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_sound_effect &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.soundId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.soundCategory); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.x); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.y); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.z); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.volume); /*0.5*/
    READ_OR_BAIL(readFloatBE, obj.pitch); /*0.5*/
    return true;
  }
  bool packet_playerlist_header(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_playerlist_header &obj) {
    int header_strlen; READ_OR_BAIL(readUnsignedVarInt, header_strlen);
    if (!stream.readString(obj.header, header_strlen)) return false; /*header: pstring*/ /*4.3*/
    int footer_strlen; READ_OR_BAIL(readUnsignedVarInt, footer_strlen);
    if (!stream.readString(obj.footer, footer_strlen)) return false; /*footer: pstring*/ /*4.3*/
    return true;
  }
  bool packet_collect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_collect &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.collectedEntityId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.collectorEntityId); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.pickupItemCount); /*0.5*/
    return true;
  }
  bool packet_entity_teleport(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_teleport &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.y); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readByte, obj.yaw); /*0.5*/
    READ_OR_BAIL(readByte, obj.pitch); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.onGround); /*0.5*/
    return true;
  }
  bool packet_entity_update_attributes(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_update_attributes &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    int properties_len; READ_OR_BAIL(readUnsignedVarInt, properties_len); /*1.5*/
    obj.properties.resize(properties_len); /*1.6*/
    for (int i = 0; i < properties_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_entity_update_attributes::Properties &v2 = obj.properties[i]; /*5.23*/
      int key_strlen; READ_OR_BAIL(readUnsignedVarInt, key_strlen);
      if (!stream.readString(v2.key, key_strlen)) return false; /*key: pstring*/ /*4.3*/
      READ_OR_BAIL(readDoubleBE, v2.value); /*0.5*/
      int modifiers_len; READ_OR_BAIL(readUnsignedVarInt, modifiers_len); /*1.5*/
      v2.modifiers.resize(modifiers_len); /*1.6*/
      for (int i = 0; i < modifiers_len; i++) { /*5*/
        pdef::pc1_18_play_toClient::packet_entity_update_attributes::Properties::Modifiers &v3 = v2.modifiers[i]; /*5.23*/
        READ_OR_BAIL(readULongBE, v3.uuid); /*0.5*/
        READ_OR_BAIL(readDoubleBE, v3.amount); /*0.5*/
        READ_OR_BAIL(readByte, v3.operation); /*0.5*/
      }
    }
    return true;
  }
  bool packet_entity_effect(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_entity_effect &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entityId); /*0.5*/
    READ_OR_BAIL(readByte, obj.effectId); /*0.5*/
    READ_OR_BAIL(readByte, obj.amplifier); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.duration); /*0.5*/
    READ_OR_BAIL(readByte, obj.hideParticles); /*0.5*/
    return true;
  }
  bool packet_select_advancement_tab(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_select_advancement_tab &obj) {
    const pdef::pc1_18_play_toClient::packet_select_advancement_tab::Id &v = obj.id = {}; /*["packet_select_advancement_tab"]*/ /*7.3*/
    return true;
  }
  bool packet_declare_recipes(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_declare_recipes &obj) {
    int recipes_len; READ_OR_BAIL(readUnsignedVarInt, recipes_len); /*1.5*/
    obj.recipes.resize(recipes_len); /*1.6*/
    for (int i = 0; i < recipes_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes &v2 = obj.recipes[i]; /*5.23*/
      int type_strlen; READ_OR_BAIL(readUnsignedVarInt, type_strlen);
      if (!stream.readString(v2.type, type_strlen)) return false; /*type: pstring*/ /*4.3*/
      pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::pstring &type = v2.type; /*0.7*/
      int recipeId_strlen; READ_OR_BAIL(readUnsignedVarInt, recipeId_strlen);
      if (!stream.readString(v2.recipeId, recipeId_strlen)) return false; /*recipeId: pstring*/ /*4.3*/
      if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingShapeless) { /*8.5*/
           v2.data_minecraft_crafting_shapeless = {}; pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftCraftingShapeless &v = *v2.data_minecraft_crafting_shapeless; /*8.4*/
          int group_strlen; READ_OR_BAIL(readUnsignedVarInt, group_strlen);
          if (!stream.readString(v2.group, group_strlen)) return false; /*group: pstring*/ /*4.3*/
          int ingredients_len; READ_OR_BAIL(readUnsignedVarInt, ingredients_len); /*1.5*/
          v2.ingredients.resize(ingredients_len); /*1.6*/
          for (int i = 0; i < ingredients_len; i++) {
            auto &v5 = v2.ingredients[i]; /*3.4*/
            int _len; READ_OR_BAIL(readUnsignedVarInt, _len); /*1.5*/
            v5.resize(_len); /*1.6*/
            for (int i = 0; i < _len; i++) {
              auto &v6 = v5[i]; /*3.4*/
              READ_OR_BAIL(readByte, v6); /*0.5*/
            }
          }
          READ_OR_BAIL(readByte, v2.result); /*0.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingShaped) { /*8.5*/
           v2.data_minecraft_crafting_shaped = {}; pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftCraftingShaped &v = *v2.data_minecraft_crafting_shaped; /*8.4*/
          READ_OR_BAIL(readUnsignedVarInt, v2.width); /*0.5*/
          int &width = v2.width; /*0.6*/
          READ_OR_BAIL(readUnsignedVarInt, v2.height); /*0.5*/
          int &height = v2.height; /*0.6*/
          int group_strlen; READ_OR_BAIL(readUnsignedVarInt, group_strlen);
          if (!stream.readString(v2.group, group_strlen)) return false; /*group: pstring*/ /*4.3*/
          v2.ingredients.resize(width); /*1.6*/
          for (int i = 0; i < width; i++) { /*5.2*/
            int ingredients_len2; READ_OR_BAIL(readUnsignedVarInt, ingredients_len2); /*5.5*/
            v2.ingredients[i].resize(ingredients_len2); /*5.10*/
            for (int j = 0; j < height; j++) { /*5.11*/
              pdef::pc1_18_play_toClient::decode::ingredient(stream, v2.ingredients[i][j]); /*5.14*/
            }
          }
          READ_OR_BAIL(readByte, v2.result); /*0.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialArmordye) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBookcloning) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialMapcloning) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialMapextending) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkRocket) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkStar) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialFireworkStarFade) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialRepairitem) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialTippedarrow) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBannerduplicate) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialBanneraddpattern) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialShielddecoration) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialShulkerboxcoloring) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCraftingSpecialSuspiciousstew) { /*8.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmelting) { /*8.5*/
        v2.data_minecraft_smelting_format = {}; pdef::pc1_18_play_toClient::decode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*v2*/ /*4.6*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftBlasting) { /*8.5*/
        v2.data_minecraft_smelting_format = {}; pdef::pc1_18_play_toClient::decode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*v2*/ /*4.6*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmoking) { /*8.5*/
        v2.data_minecraft_smelting_format = {}; pdef::pc1_18_play_toClient::decode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*v2*/ /*4.6*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftCampfireCooking) { /*8.5*/
        v2.data_minecraft_smelting_format = {}; pdef::pc1_18_play_toClient::decode::minecraft_smelting_format(stream, *v2.data_minecraft_smelting_format); /*v2*/ /*4.6*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftStonecutting) { /*8.5*/
           v2.data_minecraft_stonecutting = {}; pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftStonecutting &v = *v2.data_minecraft_stonecutting; /*8.4*/
          int group_strlen; READ_OR_BAIL(readUnsignedVarInt, group_strlen);
          if (!stream.readString(v2.group, group_strlen)) return false; /*group: pstring*/ /*4.3*/
          int ingredient_len; READ_OR_BAIL(readUnsignedVarInt, ingredient_len); /*1.5*/
          v2.ingredient.resize(ingredient_len); /*1.6*/
          for (int i = 0; i < ingredient_len; i++) {
            auto &v5 = v2.ingredient[i]; /*3.4*/
            READ_OR_BAIL(readByte, v5); /*0.5*/
          }
          READ_OR_BAIL(readByte, v2.result); /*0.5*/
      }
      else if (type == pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::Type::MinecraftSmithing) { /*8.5*/
           v2.data_minecraft_smithing = {}; pdef::pc1_18_play_toClient::packet_declare_recipes::Recipes::DataMinecraftSmithing &v = *v2.data_minecraft_smithing; /*8.4*/
          int base_len; READ_OR_BAIL(readUnsignedVarInt, base_len); /*1.5*/
          v2.base.resize(base_len); /*1.6*/
          for (int i = 0; i < base_len; i++) {
            auto &v5 = v2.base[i]; /*3.4*/
            READ_OR_BAIL(readByte, v5); /*0.5*/
          }
          int addition_len; READ_OR_BAIL(readUnsignedVarInt, addition_len); /*1.5*/
          v2.addition.resize(addition_len); /*1.6*/
          for (int i = 0; i < addition_len; i++) {
            auto &v5 = v2.addition[i]; /*3.4*/
            READ_OR_BAIL(readByte, v5); /*0.5*/
          }
          READ_OR_BAIL(readByte, v2.result); /*0.5*/
      }
    }
    return true;
  }
  bool packet_tags(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_tags &obj) {
    int tags_len; READ_OR_BAIL(readUnsignedVarInt, tags_len); /*1.5*/
    obj.tags.resize(tags_len); /*1.6*/
    for (int i = 0; i < tags_len; i++) { /*5*/
      pdef::pc1_18_play_toClient::packet_tags::Tags &v2 = obj.tags[i]; /*5.23*/
      int tagType_strlen; READ_OR_BAIL(readUnsignedVarInt, tagType_strlen);
      if (!stream.readString(v2.tagType, tagType_strlen)) return false; /*tagType: pstring*/ /*4.3*/
      int tags_len; /*2.3*/
      READ_OR_BAIL(readUnsignedVarInt, tags_len); /*2.6*/
      v2.tags.resize(tags_len); /*2.7*/
      for (int i = 0; i < tags_len; i++) { pdef::pc1_18_play_toClient::decode::tags(stream, v2.tags[i]); } /*2.8*/
    }
    return true;
  }
  bool packet_acknowledge_player_digging(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_acknowledge_player_digging &obj) {
    uint8_t location_val;
    READ_OR_BAIL(readUByte, location_val);
    obj.location.x = location_val >> 0 & 26;
    obj.location.z = location_val >> 26 & 26;
    obj.location.y = location_val >> 52 & 12; /*location: bitfield*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.block); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.status); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.successful); /*0.5*/
    return true;
  }
  bool packet_sculk_vibration_signal(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_sculk_vibration_signal &obj) {
    uint8_t sourcePosition_val;
    READ_OR_BAIL(readUByte, sourcePosition_val);
    obj.sourcePosition.x = sourcePosition_val >> 0 & 26;
    obj.sourcePosition.z = sourcePosition_val >> 26 & 26;
    obj.sourcePosition.y = sourcePosition_val >> 52 & 12; /*sourcePosition: bitfield*/ /*4.3*/
    int destinationIdentifier_strlen; READ_OR_BAIL(readUnsignedVarInt, destinationIdentifier_strlen);
    if (!stream.readString(obj.destinationIdentifier, destinationIdentifier_strlen)) return false; /*destinationIdentifier: pstring*/ /*4.3*/
    pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::pstring &destinationIdentifier = obj.destinationIdentifier; /*0.7*/
    if (destinationIdentifier == pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::DestinationIdentifier::Block) { /*8.5*/
      uint8_t destination_position_val;
      READ_OR_BAIL(readUByte, destination_position_val);
      obj.destination_position.x = destination_position_val >> 0 & 26;
      obj.destination_position.z = destination_position_val >> 26 & 26;
      obj.destination_position.y = destination_position_val >> 52 & 12; /*destination_position: bitfield*/ /*4.3*/
    }
    else if (destinationIdentifier == pdef::pc1_18_play_toClient::packet_sculk_vibration_signal::DestinationIdentifier::EntityId) { /*8.5*/
      READ_OR_BAIL(readUnsignedVarInt, obj.destination_varint); /*0.5*/
    }
    READ_OR_BAIL(readUnsignedVarInt, obj.arrivalTicks); /*0.5*/
    return true;
  }
  bool packet_clear_titles(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_clear_titles &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.reset); /*0.5*/
    return true;
  }
  bool packet_initialize_world_border(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_initialize_world_border &obj) {
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.oldDiameter); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.newDiameter); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.speed); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.portalTeleportBoundary); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.warningBlocks); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.warningTime); /*0.5*/
    return true;
  }
  bool packet_action_bar(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_action_bar &obj) {
    int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
    if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
    return true;
  }
  bool packet_world_border_center(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_center &obj) {
    READ_OR_BAIL(readDoubleBE, obj.x); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.z); /*0.5*/
    return true;
  }
  bool packet_world_border_lerp_size(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_lerp_size &obj) {
    READ_OR_BAIL(readDoubleBE, obj.oldDiameter); /*0.5*/
    READ_OR_BAIL(readDoubleBE, obj.newDiameter); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.speed); /*0.5*/
    return true;
  }
  bool packet_world_border_size(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_size &obj) {
    READ_OR_BAIL(readDoubleBE, obj.diameter); /*0.5*/
    return true;
  }
  bool packet_world_border_warning_delay(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_warning_delay &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.warningTime); /*0.5*/
    return true;
  }
  bool packet_world_border_warning_reach(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_world_border_warning_reach &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.warningBlocks); /*0.5*/
    return true;
  }
  bool packet_ping(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_ping &obj) {
    READ_OR_BAIL(readIntBE, obj.id); /*0.5*/
    return true;
  }
  bool packet_set_title_subtitle(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_title_subtitle &obj) {
    int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
    if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
    return true;
  }
  bool packet_set_title_text(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_title_text &obj) {
    int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
    if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
    return true;
  }
  bool packet_set_title_time(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_set_title_time &obj) {
    READ_OR_BAIL(readIntBE, obj.fadeIn); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.stay); /*0.5*/
    READ_OR_BAIL(readIntBE, obj.fadeOut); /*0.5*/
    return true;
  }
  bool packet_simulation_distance(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet_simulation_distance &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.distance); /*0.5*/
    return true;
  }
  bool packet(pdef::Stream &stream, pdef::pc1_18_play_toClient::packet &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.name); /*7.2*/
    const pdef::pc1_18_play_toClient::packet::Name &name = obj.name; /*0.7*/
    switch (name) { /*8.0*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntity: { /*8.5*/
        obj.params_packet_spawn_entity = {}; pdef::pc1_18_play_toClient::decode::packet_spawn_entity(stream, *obj.params_packet_spawn_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityExperienceOrb: { /*8.5*/
        obj.params_packet_spawn_entity_experience_orb = {}; pdef::pc1_18_play_toClient::decode::packet_spawn_entity_experience_orb(stream, *obj.params_packet_spawn_entity_experience_orb); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityLiving: { /*8.5*/
        obj.params_packet_spawn_entity_living = {}; pdef::pc1_18_play_toClient::decode::packet_spawn_entity_living(stream, *obj.params_packet_spawn_entity_living); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnEntityPainting: { /*8.5*/
        obj.params_packet_spawn_entity_painting = {}; pdef::pc1_18_play_toClient::decode::packet_spawn_entity_painting(stream, *obj.params_packet_spawn_entity_painting); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NamedEntitySpawn: { /*8.5*/
        obj.params_packet_named_entity_spawn = {}; pdef::pc1_18_play_toClient::decode::packet_named_entity_spawn(stream, *obj.params_packet_named_entity_spawn); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Animation: { /*8.5*/
        obj.params_packet_animation = {}; pdef::pc1_18_play_toClient::decode::packet_animation(stream, *obj.params_packet_animation); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Statistics: { /*8.5*/
        obj.params_packet_statistics = {}; pdef::pc1_18_play_toClient::decode::packet_statistics(stream, *obj.params_packet_statistics); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Advancements: { /*8.5*/
        obj.params_packet_advancements = {}; pdef::pc1_18_play_toClient::decode::packet_advancements(stream, *obj.params_packet_advancements); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockBreakAnimation: { /*8.5*/
        obj.params_packet_block_break_animation = {}; pdef::pc1_18_play_toClient::decode::packet_block_break_animation(stream, *obj.params_packet_block_break_animation); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TileEntityData: { /*8.5*/
        obj.params_packet_tile_entity_data = {}; pdef::pc1_18_play_toClient::decode::packet_tile_entity_data(stream, *obj.params_packet_tile_entity_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockAction: { /*8.5*/
        obj.params_packet_block_action = {}; pdef::pc1_18_play_toClient::decode::packet_block_action(stream, *obj.params_packet_block_action); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BlockChange: { /*8.5*/
        obj.params_packet_block_change = {}; pdef::pc1_18_play_toClient::decode::packet_block_change(stream, *obj.params_packet_block_change); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::BossBar: { /*8.5*/
        obj.params_packet_boss_bar = {}; pdef::pc1_18_play_toClient::decode::packet_boss_bar(stream, *obj.params_packet_boss_bar); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Difficulty: { /*8.5*/
        obj.params_packet_difficulty = {}; pdef::pc1_18_play_toClient::decode::packet_difficulty(stream, *obj.params_packet_difficulty); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TabComplete: { /*8.5*/
        obj.params_packet_tab_complete = {}; pdef::pc1_18_play_toClient::decode::packet_tab_complete(stream, *obj.params_packet_tab_complete); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeclareCommands: { /*8.5*/
        obj.params_packet_declare_commands = {}; pdef::pc1_18_play_toClient::decode::packet_declare_commands(stream, *obj.params_packet_declare_commands); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::FacePlayer: { /*8.5*/
        obj.params_packet_face_player = {}; pdef::pc1_18_play_toClient::decode::packet_face_player(stream, *obj.params_packet_face_player); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NbtQueryResponse: { /*8.5*/
        obj.params_packet_nbt_query_response = {}; pdef::pc1_18_play_toClient::decode::packet_nbt_query_response(stream, *obj.params_packet_nbt_query_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Chat: { /*8.5*/
        obj.params_packet_chat = {}; pdef::pc1_18_play_toClient::decode::packet_chat(stream, *obj.params_packet_chat); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::MultiBlockChange: { /*8.5*/
        obj.params_packet_multi_block_change = {}; pdef::pc1_18_play_toClient::decode::packet_multi_block_change(stream, *obj.params_packet_multi_block_change); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CloseWindow: { /*8.5*/
        obj.params_packet_close_window = {}; pdef::pc1_18_play_toClient::decode::packet_close_window(stream, *obj.params_packet_close_window); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenWindow: { /*8.5*/
        obj.params_packet_open_window = {}; pdef::pc1_18_play_toClient::decode::packet_open_window(stream, *obj.params_packet_open_window); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WindowItems: { /*8.5*/
        obj.params_packet_window_items = {}; pdef::pc1_18_play_toClient::decode::packet_window_items(stream, *obj.params_packet_window_items); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CraftProgressBar: { /*8.5*/
        obj.params_packet_craft_progress_bar = {}; pdef::pc1_18_play_toClient::decode::packet_craft_progress_bar(stream, *obj.params_packet_craft_progress_bar); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetSlot: { /*8.5*/
        obj.params_packet_set_slot = {}; pdef::pc1_18_play_toClient::decode::packet_set_slot(stream, *obj.params_packet_set_slot); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetCooldown: { /*8.5*/
        obj.params_packet_set_cooldown = {}; pdef::pc1_18_play_toClient::decode::packet_set_cooldown(stream, *obj.params_packet_set_cooldown); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CustomPayload: { /*8.5*/
        obj.params_packet_custom_payload = {}; pdef::pc1_18_play_toClient::decode::packet_custom_payload(stream, *obj.params_packet_custom_payload); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::NamedSoundEffect: { /*8.5*/
        obj.params_packet_named_sound_effect = {}; pdef::pc1_18_play_toClient::decode::packet_named_sound_effect(stream, *obj.params_packet_named_sound_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::KickDisconnect: { /*8.5*/
        obj.params_packet_kick_disconnect = {}; pdef::pc1_18_play_toClient::decode::packet_kick_disconnect(stream, *obj.params_packet_kick_disconnect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityStatus: { /*8.5*/
        obj.params_packet_entity_status = {}; pdef::pc1_18_play_toClient::decode::packet_entity_status(stream, *obj.params_packet_entity_status); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Explosion: { /*8.5*/
        obj.params_packet_explosion = {}; pdef::pc1_18_play_toClient::decode::packet_explosion(stream, *obj.params_packet_explosion); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UnloadChunk: { /*8.5*/
        obj.params_packet_unload_chunk = {}; pdef::pc1_18_play_toClient::decode::packet_unload_chunk(stream, *obj.params_packet_unload_chunk); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::GameStateChange: { /*8.5*/
        obj.params_packet_game_state_change = {}; pdef::pc1_18_play_toClient::decode::packet_game_state_change(stream, *obj.params_packet_game_state_change); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenHorseWindow: { /*8.5*/
        obj.params_packet_open_horse_window = {}; pdef::pc1_18_play_toClient::decode::packet_open_horse_window(stream, *obj.params_packet_open_horse_window); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::KeepAlive: { /*8.5*/
        obj.params_packet_keep_alive = {}; pdef::pc1_18_play_toClient::decode::packet_keep_alive(stream, *obj.params_packet_keep_alive); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::MapChunk: { /*8.5*/
        obj.params_packet_map_chunk = {}; pdef::pc1_18_play_toClient::decode::packet_map_chunk(stream, *obj.params_packet_map_chunk); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldEvent: { /*8.5*/
        obj.params_packet_world_event = {}; pdef::pc1_18_play_toClient::decode::packet_world_event(stream, *obj.params_packet_world_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldParticles: { /*8.5*/
        obj.params_packet_world_particles = {}; pdef::pc1_18_play_toClient::decode::packet_world_particles(stream, *obj.params_packet_world_particles); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateLight: { /*8.5*/
        obj.params_packet_update_light = {}; pdef::pc1_18_play_toClient::decode::packet_update_light(stream, *obj.params_packet_update_light); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Login: { /*8.5*/
        obj.params_packet_login = {}; pdef::pc1_18_play_toClient::decode::packet_login(stream, *obj.params_packet_login); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Map: { /*8.5*/
        obj.params_packet_map = {}; pdef::pc1_18_play_toClient::decode::packet_map(stream, *obj.params_packet_map); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::TradeList: { /*8.5*/
        obj.params_packet_trade_list = {}; pdef::pc1_18_play_toClient::decode::packet_trade_list(stream, *obj.params_packet_trade_list); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::RelEntityMove: { /*8.5*/
        obj.params_packet_rel_entity_move = {}; pdef::pc1_18_play_toClient::decode::packet_rel_entity_move(stream, *obj.params_packet_rel_entity_move); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityMoveLook: { /*8.5*/
        obj.params_packet_entity_move_look = {}; pdef::pc1_18_play_toClient::decode::packet_entity_move_look(stream, *obj.params_packet_entity_move_look); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityLook: { /*8.5*/
        obj.params_packet_entity_look = {}; pdef::pc1_18_play_toClient::decode::packet_entity_look(stream, *obj.params_packet_entity_look); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::VehicleMove: { /*8.5*/
        obj.params_packet_vehicle_move = {}; pdef::pc1_18_play_toClient::decode::packet_vehicle_move(stream, *obj.params_packet_vehicle_move); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenBook: { /*8.5*/
        obj.params_packet_open_book = {}; pdef::pc1_18_play_toClient::decode::packet_open_book(stream, *obj.params_packet_open_book); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::OpenSignEntity: { /*8.5*/
        obj.params_packet_open_sign_entity = {}; pdef::pc1_18_play_toClient::decode::packet_open_sign_entity(stream, *obj.params_packet_open_sign_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::CraftRecipeResponse: { /*8.5*/
        obj.params_packet_craft_recipe_response = {}; pdef::pc1_18_play_toClient::decode::packet_craft_recipe_response(stream, *obj.params_packet_craft_recipe_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Abilities: { /*8.5*/
        obj.params_packet_abilities = {}; pdef::pc1_18_play_toClient::decode::packet_abilities(stream, *obj.params_packet_abilities); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EndCombatEvent: { /*8.5*/
        obj.params_packet_end_combat_event = {}; pdef::pc1_18_play_toClient::decode::packet_end_combat_event(stream, *obj.params_packet_end_combat_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EnterCombatEvent: { /*8.5*/
        obj.params_packet_enter_combat_event = {}; pdef::pc1_18_play_toClient::decode::packet_enter_combat_event(stream, *obj.params_packet_enter_combat_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeathCombatEvent: { /*8.5*/
        obj.params_packet_death_combat_event = {}; pdef::pc1_18_play_toClient::decode::packet_death_combat_event(stream, *obj.params_packet_death_combat_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::PlayerInfo: { /*8.5*/
        obj.params_packet_player_info = {}; pdef::pc1_18_play_toClient::decode::packet_player_info(stream, *obj.params_packet_player_info); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Position: { /*8.5*/
        obj.params_packet_position = {}; pdef::pc1_18_play_toClient::decode::packet_position(stream, *obj.params_packet_position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UnlockRecipes: { /*8.5*/
        obj.params_packet_unlock_recipes = {}; pdef::pc1_18_play_toClient::decode::packet_unlock_recipes(stream, *obj.params_packet_unlock_recipes); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityDestroy: { /*8.5*/
        obj.params_packet_entity_destroy = {}; pdef::pc1_18_play_toClient::decode::packet_entity_destroy(stream, *obj.params_packet_entity_destroy); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::RemoveEntityEffect: { /*8.5*/
        obj.params_packet_remove_entity_effect = {}; pdef::pc1_18_play_toClient::decode::packet_remove_entity_effect(stream, *obj.params_packet_remove_entity_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ResourcePackSend: { /*8.5*/
        obj.params_packet_resource_pack_send = {}; pdef::pc1_18_play_toClient::decode::packet_resource_pack_send(stream, *obj.params_packet_resource_pack_send); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Respawn: { /*8.5*/
        obj.params_packet_respawn = {}; pdef::pc1_18_play_toClient::decode::packet_respawn(stream, *obj.params_packet_respawn); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityUpdateAttributes: { /*8.5*/
        obj.params_packet_entity_update_attributes = {}; pdef::pc1_18_play_toClient::decode::packet_entity_update_attributes(stream, *obj.params_packet_entity_update_attributes); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Camera: { /*8.5*/
        obj.params_packet_camera = {}; pdef::pc1_18_play_toClient::decode::packet_camera(stream, *obj.params_packet_camera); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::HeldItemSlot: { /*8.5*/
        obj.params_packet_held_item_slot = {}; pdef::pc1_18_play_toClient::decode::packet_held_item_slot(stream, *obj.params_packet_held_item_slot); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateViewPosition: { /*8.5*/
        obj.params_packet_update_view_position = {}; pdef::pc1_18_play_toClient::decode::packet_update_view_position(stream, *obj.params_packet_update_view_position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateViewDistance: { /*8.5*/
        obj.params_packet_update_view_distance = {}; pdef::pc1_18_play_toClient::decode::packet_update_view_distance(stream, *obj.params_packet_update_view_distance); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardDisplayObjective: { /*8.5*/
        obj.params_packet_scoreboard_display_objective = {}; pdef::pc1_18_play_toClient::decode::packet_scoreboard_display_objective(stream, *obj.params_packet_scoreboard_display_objective); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityMetadata: { /*8.5*/
        obj.params_packet_entity_metadata = {}; pdef::pc1_18_play_toClient::decode::packet_entity_metadata(stream, *obj.params_packet_entity_metadata); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::AttachEntity: { /*8.5*/
        obj.params_packet_attach_entity = {}; pdef::pc1_18_play_toClient::decode::packet_attach_entity(stream, *obj.params_packet_attach_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityVelocity: { /*8.5*/
        obj.params_packet_entity_velocity = {}; pdef::pc1_18_play_toClient::decode::packet_entity_velocity(stream, *obj.params_packet_entity_velocity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityEquipment: { /*8.5*/
        obj.params_packet_entity_equipment = {}; pdef::pc1_18_play_toClient::decode::packet_entity_equipment(stream, *obj.params_packet_entity_equipment); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Experience: { /*8.5*/
        obj.params_packet_experience = {}; pdef::pc1_18_play_toClient::decode::packet_experience(stream, *obj.params_packet_experience); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateHealth: { /*8.5*/
        obj.params_packet_update_health = {}; pdef::pc1_18_play_toClient::decode::packet_update_health(stream, *obj.params_packet_update_health); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardObjective: { /*8.5*/
        obj.params_packet_scoreboard_objective = {}; pdef::pc1_18_play_toClient::decode::packet_scoreboard_objective(stream, *obj.params_packet_scoreboard_objective); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetPassengers: { /*8.5*/
        obj.params_packet_set_passengers = {}; pdef::pc1_18_play_toClient::decode::packet_set_passengers(stream, *obj.params_packet_set_passengers); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Teams: { /*8.5*/
        obj.params_packet_teams = {}; pdef::pc1_18_play_toClient::decode::packet_teams(stream, *obj.params_packet_teams); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ScoreboardScore: { /*8.5*/
        obj.params_packet_scoreboard_score = {}; pdef::pc1_18_play_toClient::decode::packet_scoreboard_score(stream, *obj.params_packet_scoreboard_score); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SimulationDistance: { /*8.5*/
        obj.params_packet_simulation_distance = {}; pdef::pc1_18_play_toClient::decode::packet_simulation_distance(stream, *obj.params_packet_simulation_distance); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SpawnPosition: { /*8.5*/
        obj.params_packet_spawn_position = {}; pdef::pc1_18_play_toClient::decode::packet_spawn_position(stream, *obj.params_packet_spawn_position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::UpdateTime: { /*8.5*/
        obj.params_packet_update_time = {}; pdef::pc1_18_play_toClient::decode::packet_update_time(stream, *obj.params_packet_update_time); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntitySoundEffect: { /*8.5*/
        obj.params_packet_entity_sound_effect = {}; pdef::pc1_18_play_toClient::decode::packet_entity_sound_effect(stream, *obj.params_packet_entity_sound_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::StopSound: { /*8.5*/
        obj.params_packet_stop_sound = {}; pdef::pc1_18_play_toClient::decode::packet_stop_sound(stream, *obj.params_packet_stop_sound); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SoundEffect: { /*8.5*/
        obj.params_packet_sound_effect = {}; pdef::pc1_18_play_toClient::decode::packet_sound_effect(stream, *obj.params_packet_sound_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::PlayerlistHeader: { /*8.5*/
        obj.params_packet_playerlist_header = {}; pdef::pc1_18_play_toClient::decode::packet_playerlist_header(stream, *obj.params_packet_playerlist_header); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Collect: { /*8.5*/
        obj.params_packet_collect = {}; pdef::pc1_18_play_toClient::decode::packet_collect(stream, *obj.params_packet_collect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityTeleport: { /*8.5*/
        obj.params_packet_entity_teleport = {}; pdef::pc1_18_play_toClient::decode::packet_entity_teleport(stream, *obj.params_packet_entity_teleport); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityHeadRotation: { /*8.5*/
        obj.params_packet_entity_head_rotation = {}; pdef::pc1_18_play_toClient::decode::packet_entity_head_rotation(stream, *obj.params_packet_entity_head_rotation); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::EntityEffect: { /*8.5*/
        obj.params_packet_entity_effect = {}; pdef::pc1_18_play_toClient::decode::packet_entity_effect(stream, *obj.params_packet_entity_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SelectAdvancementTab: { /*8.5*/
        obj.params_packet_select_advancement_tab = {}; pdef::pc1_18_play_toClient::decode::packet_select_advancement_tab(stream, *obj.params_packet_select_advancement_tab); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::DeclareRecipes: { /*8.5*/
        obj.params_packet_declare_recipes = {}; pdef::pc1_18_play_toClient::decode::packet_declare_recipes(stream, *obj.params_packet_declare_recipes); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Tags: { /*8.5*/
        obj.params_packet_tags = {}; pdef::pc1_18_play_toClient::decode::packet_tags(stream, *obj.params_packet_tags); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::AcknowledgePlayerDigging: { /*8.5*/
        obj.params_packet_acknowledge_player_digging = {}; pdef::pc1_18_play_toClient::decode::packet_acknowledge_player_digging(stream, *obj.params_packet_acknowledge_player_digging); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SculkVibrationSignal: { /*8.5*/
        obj.params_packet_sculk_vibration_signal = {}; pdef::pc1_18_play_toClient::decode::packet_sculk_vibration_signal(stream, *obj.params_packet_sculk_vibration_signal); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ClearTitles: { /*8.5*/
        obj.params_packet_clear_titles = {}; pdef::pc1_18_play_toClient::decode::packet_clear_titles(stream, *obj.params_packet_clear_titles); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::InitializeWorldBorder: { /*8.5*/
        obj.params_packet_initialize_world_border = {}; pdef::pc1_18_play_toClient::decode::packet_initialize_world_border(stream, *obj.params_packet_initialize_world_border); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::ActionBar: { /*8.5*/
        obj.params_packet_action_bar = {}; pdef::pc1_18_play_toClient::decode::packet_action_bar(stream, *obj.params_packet_action_bar); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderCenter: { /*8.5*/
        obj.params_packet_world_border_center = {}; pdef::pc1_18_play_toClient::decode::packet_world_border_center(stream, *obj.params_packet_world_border_center); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderLerpSize: { /*8.5*/
        obj.params_packet_world_border_lerp_size = {}; pdef::pc1_18_play_toClient::decode::packet_world_border_lerp_size(stream, *obj.params_packet_world_border_lerp_size); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderSize: { /*8.5*/
        obj.params_packet_world_border_size = {}; pdef::pc1_18_play_toClient::decode::packet_world_border_size(stream, *obj.params_packet_world_border_size); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderWarningDelay: { /*8.5*/
        obj.params_packet_world_border_warning_delay = {}; pdef::pc1_18_play_toClient::decode::packet_world_border_warning_delay(stream, *obj.params_packet_world_border_warning_delay); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::WorldBorderWarningReach: { /*8.5*/
        obj.params_packet_world_border_warning_reach = {}; pdef::pc1_18_play_toClient::decode::packet_world_border_warning_reach(stream, *obj.params_packet_world_border_warning_reach); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::Ping: { /*8.5*/
        obj.params_packet_ping = {}; pdef::pc1_18_play_toClient::decode::packet_ping(stream, *obj.params_packet_ping); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleSubtitle: { /*8.5*/
        obj.params_packet_set_title_subtitle = {}; pdef::pc1_18_play_toClient::decode::packet_set_title_subtitle(stream, *obj.params_packet_set_title_subtitle); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleText: { /*8.5*/
        obj.params_packet_set_title_text = {}; pdef::pc1_18_play_toClient::decode::packet_set_title_text(stream, *obj.params_packet_set_title_text); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::pc1_18_play_toClient::packet::Name::SetTitleTime: { /*8.5*/
        obj.params_packet_set_title_time = {}; pdef::pc1_18_play_toClient::decode::packet_set_title_time(stream, *obj.params_packet_set_title_time); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

#undef WRITE_OR_BAIL
#undef READ_OR_BAIL