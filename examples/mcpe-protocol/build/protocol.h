
#include <string>
#include <vector>
#include <optional>
#include "stream.h"
#define DBG_PRINT(...)
#define WRITE_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: write FAIL\n", __func__, __LINE__, #fn); return false; }; DBG_PRINT("%s:%d: %s: written, stream now at %d\n", __func__, __LINE__, #fn, stream.writeIndex);
#define READ_OR_BAIL(fn, val) if (!stream.fn(val)) { DBG_PRINT("%s:%d: %s: read FAIL\n", __func__, __LINE__, #fn); return false; } DBG_PRINT("%s:%d: %s: read, stream now at %d\n", __func__, __LINE__, #fn, stream.readIndex);
#define EXPECT_OR_BAIL(val) if (!val) { DBG_PRINT("%s:%d: bad assert %s\n", __func__, __LINE__, #val); return false; }
namespace pdef::proto {
uint32_t ShieldItemID = 0;

struct BehaviourPackInfos;
struct TexturePackInfos;
struct ResourcePackIdVersions;
struct Experiment;
struct GameRule;
struct Blob;
struct BlockProperties;
struct Itemstates;
struct ItemExtraDataWithBlockingTick;
struct Nbt;
struct ItemExtraDataWithoutBlockingTick;
struct Nbt;
struct ItemLegacy;
struct Item;
struct vec3i;
struct vec3u;
struct vec3f;
struct vec2f;
struct MetadataDictionary;
struct Link;
struct EntityAttributes;
struct Rotation;
struct BlockCoordinates;
struct PlayerAttributes;
struct TransactionUseItem;
struct TransactionActions;
struct TransactionLegacy;
struct LegacyTransactions;
struct ChangedSlots;
struct Transaction;
struct TransactionDataItemUseOnEntity;
struct TransactionDataItemRelease;
struct RecipeIngredient;
struct PotionTypeRecipes;
struct PotionContainerChangeRecipes;
struct Recipes;
struct RecipeFurnace;
struct RecipeFurnaceWithMetadata;
struct RecipeMulti;
struct RecipeShapelessOrShulkerBoxOrShapelessChemistry;
struct RecipeShapedOrShapedChemistry;
struct SkinImage;
struct Skin;
struct Animations;
struct PersonalPieces;
struct PieceTintColors;
struct PlayerRecords;
struct RecordsAdd;
struct RecordsRemove;
struct Enchant;
struct EnchantOption;
struct StackRequestSlotInfo;
struct ItemStackRequest;
struct Actions;
struct ItemStackResponses;
struct Containers;
struct Slots;
struct ItemComponentList;
struct CommandOrigin;
struct PlayerEntityId;
struct TrackedObject;
struct MapDecoration;
struct StructureBlockSettings;
struct EducationSharedResourceURI;
struct EducationExternalLinkSettings;
struct BlockUpdate;
struct MaterialReducer;
struct Items;
struct packet_login;
struct LoginTokens;
struct packet_play_status;
struct packet_server_to_client_handshake;
struct packet_client_to_server_handshake;
struct packet_disconnect;
struct packet_resource_packs_info;
struct packet_resource_pack_stack;
struct packet_resource_pack_client_response;
struct packet_text;
struct packet_set_time;
struct packet_start_game;
struct packet_add_player;
struct packet_add_entity;
struct packet_remove_entity;
struct packet_add_item_entity;
struct packet_take_item_entity;
struct packet_move_entity;
struct packet_move_player;
struct Teleport;
struct packet_rider_jump;
struct packet_update_block;
struct packet_add_painting;
struct packet_tick_sync;
struct packet_level_sound_event_old;
struct packet_level_event;
struct packet_block_event;
struct packet_entity_event;
struct packet_mob_effect;
struct packet_update_attributes;
struct packet_inventory_transaction;
struct packet_mob_equipment;
struct packet_mob_armor_equipment;
struct packet_interact;
struct packet_block_pick_request;
struct packet_entity_pick_request;
struct packet_player_action;
struct packet_hurt_armor;
struct packet_set_entity_data;
struct packet_set_entity_motion;
struct packet_set_entity_link;
struct packet_set_health;
struct packet_set_spawn_position;
struct packet_animate;
struct packet_respawn;
struct packet_container_open;
struct packet_container_close;
struct packet_player_hotbar;
struct packet_inventory_content;
struct packet_inventory_slot;
struct packet_container_set_data;
struct packet_crafting_data;
struct packet_crafting_event;
struct packet_gui_data_pick_item;
struct packet_adventure_settings;
struct packet_block_entity_data;
struct packet_player_input;
struct packet_level_chunk;
struct Blobs;
struct packet_set_commands_enabled;
struct packet_set_difficulty;
struct packet_change_dimension;
struct packet_set_player_game_type;
struct packet_player_list;
struct packet_simple_event;
struct packet_event;
struct packet_spawn_experience_orb;
struct packet_clientbound_map_item_data;
struct Tracked;
struct Texture;
struct packet_map_info_request;
struct packet_request_chunk_radius;
struct packet_chunk_radius_update;
struct packet_item_frame_drop_item;
struct packet_game_rules_changed;
struct packet_camera;
struct packet_boss_event;
struct packet_show_credits;
struct packet_available_commands;
struct Enums;
struct CommandData;
struct Overloads;
struct Parameters;
struct DynamicEnums;
struct EnumConstraints;
struct Constraints;
struct packet_command_request;
struct packet_command_block_update;
struct packet_command_output;
struct Output;
struct packet_update_trade;
struct packet_update_equipment;
struct packet_resource_pack_data_info;
struct packet_resource_pack_chunk_data;
struct packet_resource_pack_chunk_request;
struct packet_transfer;
struct packet_play_sound;
struct packet_stop_sound;
struct packet_set_title;
struct packet_add_behavior_tree;
struct packet_structure_block_update;
struct packet_show_store_offer;
struct packet_purchase_receipt;
struct packet_player_skin;
struct packet_sub_client_login;
struct packet_initiate_web_socket_connection;
struct packet_set_last_hurt_by;
struct packet_book_edit;
struct packet_npc_request;
struct packet_photo_transfer;
struct packet_modal_form_request;
struct packet_modal_form_response;
struct packet_server_settings_request;
struct packet_server_settings_response;
struct packet_show_profile;
struct packet_set_default_game_type;
struct packet_remove_objective;
struct packet_set_display_objective;
struct packet_set_score;
struct Entries;
struct packet_lab_table;
struct packet_update_block_synced;
struct packet_move_entity_delta;
struct packet_set_scoreboard_identity;
struct Entries;
struct packet_set_local_player_as_initialized;
struct packet_update_soft_enum;
struct packet_network_stack_latency;
struct packet_script_custom_event;
struct packet_spawn_particle_effect;
struct packet_available_entity_identifiers;
struct packet_level_sound_event_v2;
struct packet_network_chunk_publisher_update;
struct packet_biome_definition_list;
struct packet_level_sound_event;
struct packet_level_event_generic;
struct packet_lectern_update;
struct packet_video_stream_connect;
struct packet_add_ecs_entity;
struct packet_remove_ecs_entity;
struct packet_client_cache_status;
struct packet_on_screen_texture_animation;
struct packet_map_create_locked_copy;
struct packet_structure_template_data_export_request;
struct packet_structure_template_data_export_response;
struct packet_update_block_properties;
struct packet_client_cache_blob_status;
struct packet_client_cache_miss_response;
struct packet_education_settings;
struct AgentCapabilities;
struct ExternalLinkSettings;
struct packet_emote;
struct packet_multiplayer_settings;
struct packet_settings_command;
struct packet_anvil_damage;
struct packet_completed_using_item;
struct packet_network_settings;
struct packet_player_auth_input;
struct Transaction;
struct BlockAction;
struct packet_creative_content;
struct Items;
struct packet_player_enchant_options;
struct packet_item_stack_request;
struct packet_item_stack_response;
struct packet_player_armor_damage;
struct packet_update_player_game_type;
struct packet_emote_list;
struct packet_position_tracking_db_request;
struct packet_position_tracking_db_broadcast;
struct packet_packet_violation_warning;
struct packet_motion_prediction_hints;
struct packet_animate_entity;
struct packet_camera_shake;
struct packet_player_fog;
struct packet_correct_player_move_prediction;
struct packet_item_component;
struct packet_filter_text_packet;
struct packet_debug_renderer;
struct packet_sync_entity_property;
struct packet_add_volume_entity;
struct Bounds;
struct packet_remove_volume_entity;
struct packet_simulation_type;
struct packet_npc_dialogue;
struct packet_edu_uri_resource_packet;
struct packet_create_photo;
struct packet_update_subchunk_blocks;
struct packet_photo_info_request;
struct SubChunkEntryWithoutCaching;
struct SubChunkEntryWithCaching;
struct packet_subchunk;
struct packet_subchunk_request;
struct Requests;
struct packet_client_start_item_cooldown;
struct packet_script_message;
struct packet_code_builder_source;
struct packet_ticking_areas_load_status;
struct packet_dimension_data;
struct Definitions;
struct packet_agent_action;
struct packet_change_mob_property;
struct packet_lesson_progress;
struct packet_request_ability;
struct packet_request_permissions;
struct packet_toast_request;
struct mcpe_packet;
// varint64 is built in
// zigzag32 is built in
// zigzag64 is built in
// uuid is built in
// byterot is built in
// bitflags is built in
// restBuffer is built in
// encapsulated is built in
// nbt is built in
// lnbt is built in
// nbtLoop is built in
// enum_size_based_on_values_len is built in
// MapInfo is built in
  struct BehaviourPackInfos {
    std::string uuid; /*6.0*/
    std::string version; /*6.0*/
    uint64_t size; /*0.0*/
    std::string content_key; /*6.0*/
    std::string sub_pack_name; /*6.0*/
    std::string content_identity; /*6.0*/
    bool has_scripts; /*0.0*/
  };
  struct TexturePackInfos {
    std::string uuid; /*6.0*/
    std::string version; /*6.0*/
    uint64_t size; /*0.0*/
    std::string content_key; /*6.0*/
    std::string sub_pack_name; /*6.0*/
    std::string content_identity; /*6.0*/
    bool has_scripts; /*0.0*/
    bool rtx_enabled; /*0.0*/
  };
  struct ResourcePackIdVersions {
    std::string uuid; /*6.0*/
    std::string version; /*6.0*/
    std::string name; /*6.0*/
  };
  struct Experiment {
    std::string name; /*6.0*/
    bool enabled; /*0.0*/
  };
  enum class GameMode : int {
    Survival = 0,
    Creative = 1,
    Adventure = 2,
    SurvivalSpectator = 3,
    CreativeSpectator = 4,
    Fallback = 5,
    Spectator = 6,
  };
  struct GameRule {
    std::string name; /*6.0*/
    bool editable; /*0.0*/
    enum class Type : int {
      Bool = 1,
      Int = 2,
      Float = 3,
    };
    Type type; /*3.2*/
    bool value_bool; /*0.0*/
    int value_zigzag32; /*0.0*/
    float value_lf32; /*0.0*/
  };
  struct Blob {
    uint64_t hash; /*0.0*/
    std::vector<uint8_t> payload; /*6.0*/
  };
  struct BlockProperties {
    std::string name; /*6.0*/
    int8_t state; /*0.0*/
  };
  struct Itemstates {
    std::string name; /*6.0*/
    int16_t runtime_id; /*0.0*/
    bool component_based; /*0.0*/
  };
  struct ItemExtraDataWithBlockingTick {
    enum class HasNbt : uint16_t {
      False = 0,
      True = 65535,
    };
    HasNbt has_nbt; /*3.2*/
    std::vector<std::string /*6.0*/> can_place_on; /*3.0*/
    std::vector<std::string /*6.0*/> can_destroy; /*3.0*/
    int64_t blocking_tick; /*0.0*/
    struct Nbt {
      uint8_t version; /*0.0*/
      int8_t nbt; /*0.0*/
    };
    std::optional<Nbt> nbt; /*3.2*/
  };
  struct ItemExtraDataWithoutBlockingTick {
    enum class HasNbt : uint16_t {
      False = 0,
      True = 65535,
    };
    HasNbt has_nbt; /*3.2*/
    std::vector<std::string /*6.0*/> can_place_on; /*3.0*/
    std::vector<std::string /*6.0*/> can_destroy; /*3.0*/
    struct Nbt {
      uint8_t version; /*0.0*/
      int8_t nbt; /*0.0*/
    };
    std::optional<Nbt> nbt; /*3.2*/
  };
  struct ItemLegacy {
    int network_id; /*0.0*/
    int8_t extra__ShieldItemID; /*0.0*/
    int8_t extra_default; /*0.0*/
    uint16_t count; /*0.0*/
    int metadata; /*0.0*/
    int block_runtime_id; /*0.0*/
  };
  struct Item {
    int network_id; /*0.0*/
    int8_t extra__ShieldItemID; /*0.0*/
    int8_t extra_default; /*0.0*/
    uint16_t count; /*0.0*/
    int metadata; /*0.0*/
    uint8_t has_stack_id; /*0.0*/
    int stack_id; /*0.0*/
    int block_runtime_id; /*0.0*/
  };
  struct vec3i {
    int x; /*0.0*/
    int y; /*0.0*/
    int z; /*0.0*/
  };
  struct vec3u {
    int x; /*0.0*/
    int y; /*0.0*/
    int z; /*0.0*/
  };
  struct vec3f {
    float x; /*0.0*/
    float y; /*0.0*/
    float z; /*0.0*/
  };
  struct vec2f {
    float x; /*0.0*/
    float z; /*0.0*/
  };
  struct MetadataDictionary {
    enum class Key : int {
      Flags = 0,
      Health = 1,
      Variant = 2,
      Color = 3,
      Nametag = 4,
      OwnerEid = 5,
      TargetEid = 6,
      Air = 7,
      PotionColor = 8,
      PotionAmbient = 9,
      JumpDuration = 10,
      HurtTime = 11,
      HurtDirection = 12,
      PaddleTimeLeft = 13,
      PaddleTimeRight = 14,
      ExperienceValue = 15,
      MinecartDisplayBlock = 16,
      MinecartDisplayOffset = 17,
      MinecartHasDisplay = 18,
      OldSwell = 20,
      SwellDir = 21,
      ChargeAmount = 22,
      EndermanHeldRuntimeId = 23,
      EntityAge = 24,
      PlayerFlags = 26,
      PlayerIndex = 27,
      PlayerBedPosition = 28,
      FireballPowerX = 29,
      FireballPowerY = 30,
      FireballPowerZ = 31,
      AuxPower = 32,
      FishX = 33,
      FishZ = 34,
      FishAngle = 35,
      PotionAuxValue = 36,
      LeadHolderEid = 37,
      Scale = 38,
      InteractiveTag = 39,
      NpcSkinId = 40,
      UrlTag = 41,
      MaxAirdataMaxAir = 42,
      MarkVariant = 43,
      ContainerType = 44,
      ContainerBaseSize = 45,
      ContainerExtraSlotsPerStrength = 46,
      BlockTarget = 47,
      WitherInvulnerableTicks = 48,
      WitherTarget1 = 49,
      WitherTarget2 = 50,
      WitherTarget3 = 51,
      AerialAttack = 52,
      BoundingboxWidth = 53,
      BoundingboxHeight = 54,
      FuseLength = 55,
      RiderSeatPosition = 56,
      RiderRotationLocked = 57,
      RiderMaxRotation = 58,
      RiderMinRotation = 59,
      RiderRotationOffset = 60,
      AreaEffectCloudRadius = 61,
      AreaEffectCloudWaiting = 62,
      AreaEffectCloudParticleId = 63,
      ShulkerPeekId = 64,
      ShulkerAttachFace = 65,
      ShulkerAttached = 66,
      ShulkerAttachPos = 67,
      TradingPlayerEid = 68,
      TradingCareer = 69,
      HasCommandBlock = 70,
      CommandBlockCommand = 71,
      CommandBlockLastOutput = 72,
      CommandBlockTrackOutput = 73,
      ControllingRiderSeatNumber = 74,
      Strength = 75,
      MaxStrength = 76,
      SpellCastingColor = 77,
      LimitedLife = 78,
      ArmorStandPoseIndex = 79,
      EnderCrystalTimeOffset = 80,
      AlwaysShowNametag = 81,
      Color2 = 82,
      NameAuthor = 83,
      ScoreTag = 84,
      BalloonAttachedEntity = 85,
      PufferfishSize = 86,
      BubbleTime = 87,
      Agent = 88,
      SittingAmount = 89,
      SittingAmountPrevious = 90,
      EatingCounter = 91,
      FlagsExtended = 92,
      LayingAmount = 93,
      LayingAmountPrevious = 94,
      Duration = 95,
      SpawnTime = 96,
      ChangeRate = 97,
      ChangeOnPickup = 98,
      PickupCount = 99,
      InteractText = 100,
      TradeTier = 101,
      MaxTradeTier = 102,
      TradeExperience = 103,
      SkinId = 104,
      SpawningFrames = 105,
      CommandBlockTickDelay = 106,
      CommandBlockExecuteOnFirstTick = 107,
      AmbientSoundInterval = 108,
      AmbientSoundIntervalRange = 109,
      AmbientSoundEventName = 110,
      FallDamageMultiplier = 111,
      NameRawText = 112,
      CanRideTarget = 113,
      LowTierCuredDiscount = 114,
      HighTierCuredDiscount = 115,
      NearbyCuredDiscount = 116,
      NearbyCuredDiscountTimestamp = 117,
      Hitbox = 118,
      IsBuoyant = 119,
      BaseRuntimeId = 120,
      FreezingEffectStrength = 121,
      BuoyancyData = 122,
      GoatHornCount = 123,
      UpdateProperties = 124,
      MovementSoundDistanceOffset = 125,
      HeartbeatIntervalTicks = 126,
      HeartbeatSoundEvent = 127,
    };
    Key key; /*3.2*/
    enum class Type : int {
      Byte = 0,
      Short = 1,
      Int = 2,
      Float = 3,
      String = 4,
      Compound = 5,
      Vec3i = 6,
      Long = 7,
      Vec3f = 8,
    };
    Type type; /*3.2*/
    struct value_MetadataFlags1_t { /*6.0*/
      bool onfire = false; /*6.0*/
      bool sneaking = false; /*6.0*/
      bool riding = false; /*6.0*/
      bool sprinting = false; /*6.0*/
      bool action = false; /*6.0*/
      bool invisible = false; /*6.0*/
      bool tempted = false; /*6.0*/
      bool inlove = false; /*6.0*/
      bool saddled = false; /*6.0*/
      bool powered = false; /*6.0*/
      bool ignited = false; /*6.0*/
      bool baby = false; /*6.0*/
      bool converting = false; /*6.0*/
      bool critical = false; /*6.0*/
      bool can_show_nametag = false; /*6.0*/
      bool always_show_nametag = false; /*6.0*/
      bool no_ai = false; /*6.0*/
      bool silent = false; /*6.0*/
      bool wallclimbing = false; /*6.0*/
      bool can_climb = false; /*6.0*/
      bool swimmer = false; /*6.0*/
      bool can_fly = false; /*6.0*/
      bool walker = false; /*6.0*/
      bool resting = false; /*6.0*/
      bool sitting = false; /*6.0*/
      bool angry = false; /*6.0*/
      bool interested = false; /*6.0*/
      bool charged = false; /*6.0*/
      bool tamed = false; /*6.0*/
      bool orphaned = false; /*6.0*/
      bool leashed = false; /*6.0*/
      bool sheared = false; /*6.0*/
      bool gliding = false; /*6.0*/
      bool elder = false; /*6.0*/
      bool moving = false; /*6.0*/
      bool breathing = false; /*6.0*/
      bool chested = false; /*6.0*/
      bool stackable = false; /*6.0*/
      bool showbase = false; /*6.0*/
      bool rearing = false; /*6.0*/
      bool vibrating = false; /*6.0*/
      bool idling = false; /*6.0*/
      bool evoker_spell = false; /*6.0*/
      bool charge_attack = false; /*6.0*/
      bool wasd_controlled = false; /*6.0*/
      bool can_power_jump = false; /*6.0*/
      bool linger = false; /*6.0*/
      bool has_collision = false; /*6.0*/
      bool affected_by_gravity = false; /*6.0*/
      bool fire_immune = false; /*6.0*/
      bool dancing = false; /*6.0*/
      bool enchanted = false; /*6.0*/
      bool show_trident_rope = false; /*6.0*/
      bool container_private = false; /*6.0*/
      bool transforming = false; /*6.0*/
      bool spin_attack = false; /*6.0*/
      bool swimming = false; /*6.0*/
      bool bribed = false; /*6.0*/
      bool pregnant = false; /*6.0*/
      bool laying_egg = false; /*6.0*/
      bool rider_can_pick = false; /*6.0*/
      bool transition_sitting = false; /*6.0*/
      bool eating = false; /*6.0*/
      bool laying_down = false; /*6.0*/
    } value_MetadataFlags1; /*6.0*/
    struct value_MetadataFlags2_t { /*6.0*/
      bool sneezing = false; /*6.0*/
      bool trusting = false; /*6.0*/
      bool rolling = false; /*6.0*/
      bool scared = false; /*6.0*/
      bool in_scaffolding = false; /*6.0*/
      bool over_scaffolding = false; /*6.0*/
      bool fall_through_scaffolding = false; /*6.0*/
      bool blocking = false; /*6.0*/
      bool transition_blocking = false; /*6.0*/
      bool blocked_using_shield = false; /*6.0*/
      bool blocked_using_damaged_shield = false; /*6.0*/
      bool sleeping = false; /*6.0*/
      bool wants_to_wake = false; /*6.0*/
      bool trade_interest = false; /*6.0*/
      bool door_breaker = false; /*6.0*/
      bool breaking_obstruction = false; /*6.0*/
      bool door_opener = false; /*6.0*/
      bool illager_captain = false; /*6.0*/
      bool stunned = false; /*6.0*/
      bool roaring = false; /*6.0*/
      bool delayed_attacking = false; /*6.0*/
      bool avoiding_mobs = false; /*6.0*/
      bool avoiding_block = false; /*6.0*/
      bool facing_target_to_range_attack = false; /*6.0*/
      bool hidden_when_invisible = false; /*6.0*/
      bool is_in_ui = false; /*6.0*/
      bool stalking = false; /*6.0*/
      bool emoting = false; /*6.0*/
      bool celebrating = false; /*6.0*/
      bool admiring = false; /*6.0*/
      bool celebrating_special = false; /*6.0*/
      bool unknown95 = false; /*6.0*/
      bool ram_attack = false; /*6.0*/
      bool playing_dead = false; /*6.0*/
      bool in_ascendable_block = false; /*6.0*/
      bool over_descendable_block = false; /*6.0*/
      bool croaking = false; /*6.0*/
      bool eat_mob = false; /*6.0*/
      bool jump_goal_jump = false; /*6.0*/
      bool emerging = false; /*6.0*/
      bool sniffing = false; /*6.0*/
      bool digging = false; /*6.0*/
    } value_MetadataFlags2; /*6.0*/
    int8_t value_i8; /*0.0*/
    int16_t value_li16; /*0.0*/
    int value_zigzag32; /*0.0*/
    float value_lf32; /*0.0*/
    std::string value_string; /*6.0*/
    int8_t value_nbt; /*0.0*/
    std::optional<pdef::proto::vec3i> value_vec3i; /*4.0*/
    int64_t value_zigzag64; /*0.0*/
    std::optional<pdef::proto::vec3f> value_vec3f; /*4.0*/
  };
  struct Link {
    int64_t ridden_entity_id; /*0.0*/
    int64_t rider_entity_id; /*0.0*/
    uint8_t type; /*0.0*/
    bool immediate; /*0.0*/
    bool rider_initiated; /*0.0*/
  };
  struct EntityAttributes {
    std::string name; /*6.0*/
    float min; /*0.0*/
    float value; /*0.0*/
    float max; /*0.0*/
  };
  struct Rotation {
    int8_t yaw; /*0.0*/
    int8_t pitch; /*0.0*/
    int8_t head_yaw; /*0.0*/
  };
  struct BlockCoordinates {
    int x; /*0.0*/
    int y; /*0.0*/
    int z; /*0.0*/
  };
  struct PlayerAttributes {
    float min; /*0.0*/
    float max; /*0.0*/
    float current; /*0.0*/
    float default_; /*0.0*/
    std::string name; /*6.0*/
  };
  struct TransactionUseItem {
    enum class ActionType : int {
      ClickBlock = 0,
      ClickAir = 1,
      BreakBlock = 2,
    };
    ActionType action_type; /*3.2*/
    pdef::proto::BlockCoordinates block_position; /*4.0*/
    int face; /*0.0*/
    int hotbar_slot; /*0.0*/
    pdef::proto::Item held_item; /*4.0*/
    pdef::proto::vec3f player_pos; /*4.0*/
    pdef::proto::vec3f click_pos; /*4.0*/
    int block_runtime_id; /*0.0*/
  };
  struct TransactionActions {
    enum class SourceType : int {
      Container = 0,
      Global = 1,
      WorldInteraction = 2,
      Creative = 3,
      CraftSlot = 100,
      Craft = 99999,
    };
    SourceType source_type; /*3.2*/
    int slot; /*0.0*/
    pdef::proto::Item old_item; /*4.0*/
    pdef::proto::Item new_item; /*4.0*/
    enum class InventoryId : int {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    InventoryId inventory_id; /*3.2*/
    int flags; /*0.0*/
    int action; /*0.0*/
  };
  struct TransactionLegacy {
    int legacy_request_id; /*0.0*/
    struct LegacyTransactions {
      uint8_t container_id; /*0.0*/
      struct ChangedSlots {
        uint8_t slot_id; /*0.0*/
      };
      std::vector<ChangedSlots /*3.2*/> changed_slots; /*3.0*/
    };
    std::vector<LegacyTransactions /*3.2*/> legacy_transactions; /*3.0*/
  };
  struct Transaction {
    pdef::proto::TransactionLegacy legacy; /*4.0*/
    enum class TransactionType : int {
      Normal = 0,
      InventoryMismatch = 1,
      ItemUse = 2,
      ItemUseOnEntity = 3,
      ItemRelease = 4,
    };
    TransactionType transaction_type; /*3.2*/
    std::vector<pdef::proto::TransactionActions> actions; /*1.0*/
    struct TransactionDataItemUseOnEntity {
      int64_t entity_runtime_id; /*0.0*/
      enum class ActionType : int {
        Interact = 0,
        Attack = 1,
      };
      ActionType action_type; /*3.2*/
      int hotbar_slot; /*0.0*/
      pdef::proto::Item held_item; /*4.0*/
      pdef::proto::vec3f player_pos; /*4.0*/
      pdef::proto::vec3f click_pos; /*4.0*/
    };
    std::optional<TransactionDataItemUseOnEntity> transaction_data_item_use_on_entity; /*3.2*/
    struct TransactionDataItemRelease {
      enum class ActionType : int {
        Release = 0,
        Consume = 1,
      };
      ActionType action_type; /*3.2*/
      int hotbar_slot; /*0.0*/
      pdef::proto::Item held_item; /*4.0*/
      pdef::proto::vec3f head_pos; /*4.0*/
    };
    std::optional<TransactionDataItemRelease> transaction_data_item_release; /*3.2*/
    std::optional<pdef::proto::TransactionUseItem> transaction_data_TransactionUseItem; /*4.0*/
  };
  struct RecipeIngredient {
    int network_id; /*0.0*/
    int network_data; /*0.0*/
    int count; /*0.0*/
  };
  struct PotionTypeRecipes {
    int input_item_id; /*0.0*/
    int input_item_meta; /*0.0*/
    int ingredient_id; /*0.0*/
    int ingredient_meta; /*0.0*/
    int output_item_id; /*0.0*/
    int output_item_meta; /*0.0*/
  };
  struct PotionContainerChangeRecipes {
    int input_item_id; /*0.0*/
    int ingredient_id; /*0.0*/
    int output_item_id; /*0.0*/
  };
  struct Recipes {
    enum class Type : int {
      Shapeless = 0,
      Shaped = 1,
      Furnace = 2,
      FurnaceWithMetadata = 3,
      Multi = 4,
      ShulkerBox = 5,
      ShapelessChemistry = 6,
      ShapedChemistry = 7,
    };
    Type type; /*3.2*/
    struct RecipeFurnace {
      int input_id; /*0.0*/
      pdef::proto::ItemLegacy output; /*4.0*/
      std::string block; /*6.0*/
    };
    std::optional<RecipeFurnace> recipe_furnace; /*3.2*/
    struct RecipeFurnaceWithMetadata {
      int input_id; /*0.0*/
      int input_meta; /*0.0*/
      pdef::proto::ItemLegacy output; /*4.0*/
      std::string block; /*6.0*/
    };
    std::optional<RecipeFurnaceWithMetadata> recipe_furnace_with_metadata; /*3.2*/
    struct RecipeMulti {
      uint64_t uuid; /*0.0*/
      int network_id; /*0.0*/
    };
    std::optional<RecipeMulti> recipe_multi; /*3.2*/
    struct RecipeShapelessOrShulkerBoxOrShapelessChemistry {
      std::string recipe_id; /*6.0*/
      std::vector<pdef::proto::RecipeIngredient /*4.0*/> input; /*3.0*/
      std::vector<pdef::proto::ItemLegacy /*4.0*/> output; /*3.0*/
      uint64_t uuid; /*0.0*/
      std::string block; /*6.0*/
      int priority; /*0.0*/
      int network_id; /*0.0*/
    };
    std::optional<RecipeShapelessOrShulkerBoxOrShapelessChemistry> recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*3.2*/
    struct RecipeShapedOrShapedChemistry {
      std::string recipe_id; /*6.0*/
      int width; /*0.0*/
      int height; /*0.0*/
      std::vector<std::vector<pdef::proto::RecipeIngredient /*4.0*/>> input; /*3.0*/
      std::vector<pdef::proto::ItemLegacy /*4.0*/> output; /*3.0*/
      uint64_t uuid; /*0.0*/
      std::string block; /*6.0*/
      int priority; /*0.0*/
      int network_id; /*0.0*/
    };
    std::optional<RecipeShapedOrShapedChemistry> recipe_shaped_or_shaped_chemistry; /*3.2*/
  };
  struct SkinImage {
    int32_t width; /*0.0*/
    int32_t height; /*0.0*/
    std::vector<uint8_t> data; /*6.0*/
  };
  struct Skin {
    std::string skin_id; /*6.0*/
    std::string play_fab_id; /*6.0*/
    std::string skin_resource_pack; /*6.0*/
    pdef::proto::SkinImage skin_data; /*4.0*/
    struct Animations {
      pdef::proto::SkinImage skin_image; /*4.0*/
      int32_t animation_type; /*0.0*/
      float animation_frames; /*0.0*/
      float expression_type; /*0.0*/
    };
    std::vector<Animations /*3.2*/> animations; /*3.0*/
    pdef::proto::SkinImage cape_data; /*4.0*/
    std::string geometry_data; /*6.0*/
    std::string geometry_data_version; /*6.0*/
    std::string animation_data; /*6.0*/
    std::string cape_id; /*6.0*/
    std::string full_skin_id; /*6.0*/
    std::string arm_size; /*6.0*/
    std::string skin_color; /*6.0*/
    struct PersonalPieces {
      std::string piece_id; /*6.0*/
      std::string piece_type; /*6.0*/
      std::string pack_id; /*6.0*/
      bool is_default_piece; /*0.0*/
      std::string product_id; /*6.0*/
    };
    std::vector<PersonalPieces /*3.2*/> personal_pieces; /*3.0*/
    struct PieceTintColors {
      std::string piece_type; /*6.0*/
      std::vector<std::string /*6.0*/> colors; /*3.0*/
    };
    std::vector<PieceTintColors /*3.2*/> piece_tint_colors; /*3.0*/
    bool premium; /*0.0*/
    bool persona; /*0.0*/
    bool cape_on_classic; /*0.0*/
    bool primary_user; /*0.0*/
  };
  struct PlayerRecords {
    enum class Type : uint8_t {
      Add = 0,
      Remove = 1,
    };
    Type type; /*3.2*/
    int records_count; /*0.0*/
    struct RecordsAdd {
      uint64_t uuid; /*0.0*/
      int64_t entity_unique_id; /*0.0*/
      std::string username; /*6.0*/
      std::string xbox_user_id; /*6.0*/
      std::string platform_chat_id; /*6.0*/
      int32_t build_platform; /*0.0*/
      pdef::proto::Skin skin_data; /*4.0*/
      bool is_teacher; /*0.0*/
      bool is_host; /*0.0*/
    };
    std::optional<RecordsAdd> records_add; /*3.2*/
    struct RecordsRemove {
      uint64_t uuid; /*0.0*/
    };
    std::optional<RecordsRemove> records_remove; /*3.2*/
    std::vector<char> verified; /*3.0*/
  };
  struct Enchant {
    uint8_t id; /*0.0*/
    uint8_t level; /*0.0*/
  };
  struct EnchantOption {
    int cost; /*0.0*/
    int32_t slot_flags; /*0.0*/
    std::vector<pdef::proto::Enchant /*4.0*/> equip_enchants; /*3.0*/
    std::vector<pdef::proto::Enchant /*4.0*/> held_enchants; /*3.0*/
    std::vector<pdef::proto::Enchant /*4.0*/> self_enchants; /*3.0*/
    std::string name; /*6.0*/
    int option_id; /*0.0*/
  };
  enum class Action : int {
    StartBreak = 0,
    AbortBreak = 1,
    StopBreak = 2,
    GetUpdatedBlock = 3,
    DropItem = 4,
    StartSleeping = 5,
    StopSleeping = 6,
    Respawn = 7,
    Jump = 8,
    StartSprint = 9,
    StopSprint = 10,
    StartSneak = 11,
    StopSneak = 12,
    CreativePlayerDestroyBlock = 13,
    DimensionChangeAck = 14,
    StartGlide = 15,
    StopGlide = 16,
    BuildDenied = 17,
    CrackBreak = 18,
    ChangeSkin = 19,
    SetEnchatnmentSeed = 20,
    Swimming = 21,
    StopSwimming = 22,
    StartSpinAttack = 23,
    StopSpinAttack = 24,
    InteractBlock = 25,
    PredictBreak = 26,
    ContinueBreak = 27,
    StartItemUseOn = 28,
    StopItemUseOn = 29,
  };
  struct StackRequestSlotInfo {
    enum class SlotType : uint8_t {
      AnvilInput = 0,
      AnvilMaterial = 1,
      AnvilResult = 2,
      SmithingTableInput = 3,
      SmithingTableMaterial = 4,
      SmithingTableResult = 5,
      Armor = 6,
      Container = 7,
      BeaconPayment = 8,
      BrewingInput = 9,
      BrewingResult = 10,
      BrewingFuel = 11,
      HotbarAndInventory = 12,
      CraftingInput = 13,
      CraftingOutput = 14,
      RecipeConstruction = 15,
      RecipeNature = 16,
      RecipeItems = 17,
      RecipeSearch = 18,
      RecipeSearchBar = 19,
      RecipeEquipment = 20,
      EnchantingInput = 21,
      EnchantingLapis = 22,
      FurnaceFuel = 23,
      FurnaceIngredient = 24,
      FurnaceOutput = 25,
      HorseEquip = 26,
      Hotbar = 27,
      Inventory = 28,
      Shulker = 29,
      TradeIngredient1 = 30,
      TradeIngredient2 = 31,
      TradeResult = 32,
      Offhand = 33,
      CompcreateInput = 34,
      CompcreateOutput = 35,
      ElemconstructOutput = 36,
      MatreduceInput = 37,
      MatreduceOutput = 38,
      LabtableInput = 39,
      LoomInput = 40,
      LoomDye = 41,
      LoomMaterial = 42,
      LoomResult = 43,
      BlastFurnaceIngredient = 44,
      SmokerIngredient = 45,
      Trade2Ingredient1 = 46,
      Trade2Ingredient2 = 47,
      Trade2Result = 48,
      GrindstoneInput = 49,
      GrindstoneAdditional = 50,
      GrindstoneResult = 51,
      StonecutterInput = 52,
      StonecutterResult = 53,
      CartographyInput = 54,
      CartographyAdditional = 55,
      CartographyResult = 56,
      Barrel = 57,
      Cursor = 58,
      CreativeOutput = 59,
    };
    SlotType slot_type; /*3.2*/
    uint8_t slot; /*0.0*/
    int stack_id; /*0.0*/
  };
  struct ItemStackRequest {
    int request_id; /*0.0*/
    struct Actions {
      enum class TypeId : uint8_t {
        Take = 0,
        Place = 1,
        Swap = 2,
        Drop = 3,
        Destroy = 4,
        Consume = 5,
        Create = 6,
        PlaceInContainer = 7,
        TakeOutContainer = 8,
        LabTableCombine = 9,
        BeaconPayment = 10,
        MineBlock = 11,
        CraftRecipe = 12,
        CraftRecipeAuto = 13,
        CraftCreative = 14,
        Optional = 15,
        CraftGrindstoneRequest = 16,
        CraftLoomRequest = 17,
        NonImplemented = 18,
        ResultsDeprecated = 19,
      };
      TypeId type_id; /*3.2*/
      uint8_t count; /*0.0*/
      std::optional<pdef::proto::StackRequestSlotInfo> source; /*4.0*/
      std::optional<pdef::proto::StackRequestSlotInfo> destination; /*4.0*/
      bool randomly; /*0.0*/
      uint8_t result_slot_id; /*0.0*/
      int primary_effect; /*0.0*/
      int secondary_effect; /*0.0*/
      int unknown1; /*0.0*/
      int predicted_durability; /*0.0*/
      int network_id; /*0.0*/
      int recipe_network_id; /*0.0*/
      int item_id; /*0.0*/
      int32_t filtered_string_index; /*0.0*/
      int cost; /*0.0*/
      std::string pattern; /*6.0*/
      std::vector<pdef::proto::ItemLegacy /*4.0*/> result_items; /*3.0*/
      uint8_t times_crafted; /*0.0*/
    };
    std::vector<Actions /*3.2*/> actions; /*3.0*/
    std::vector<std::string /*6.0*/> custom_names; /*3.0*/
  };
  struct ItemStackResponses {
    enum class Status : uint8_t {
      Ok = 0,
      Error = 1,
    };
    Status status; /*3.2*/
    int request_id; /*0.0*/
    struct Containers {
      enum class SlotType : uint8_t {
        AnvilInput = 0,
        AnvilMaterial = 1,
        AnvilResult = 2,
        SmithingTableInput = 3,
        SmithingTableMaterial = 4,
        SmithingTableResult = 5,
        Armor = 6,
        Container = 7,
        BeaconPayment = 8,
        BrewingInput = 9,
        BrewingResult = 10,
        BrewingFuel = 11,
        HotbarAndInventory = 12,
        CraftingInput = 13,
        CraftingOutput = 14,
        RecipeConstruction = 15,
        RecipeNature = 16,
        RecipeItems = 17,
        RecipeSearch = 18,
        RecipeSearchBar = 19,
        RecipeEquipment = 20,
        EnchantingInput = 21,
        EnchantingLapis = 22,
        FurnaceFuel = 23,
        FurnaceIngredient = 24,
        FurnaceOutput = 25,
        HorseEquip = 26,
        Hotbar = 27,
        Inventory = 28,
        Shulker = 29,
        TradeIngredient1 = 30,
        TradeIngredient2 = 31,
        TradeResult = 32,
        Offhand = 33,
        CompcreateInput = 34,
        CompcreateOutput = 35,
        ElemconstructOutput = 36,
        MatreduceInput = 37,
        MatreduceOutput = 38,
        LabtableInput = 39,
        LoomInput = 40,
        LoomDye = 41,
        LoomMaterial = 42,
        LoomResult = 43,
        BlastFurnaceIngredient = 44,
        SmokerIngredient = 45,
        Trade2Ingredient1 = 46,
        Trade2Ingredient2 = 47,
        Trade2Result = 48,
        GrindstoneInput = 49,
        GrindstoneAdditional = 50,
        GrindstoneResult = 51,
        StonecutterInput = 52,
        StonecutterResult = 53,
        CartographyInput = 54,
        CartographyAdditional = 55,
        CartographyResult = 56,
        Barrel = 57,
        Cursor = 58,
        CreativeOutput = 59,
      };
      SlotType slot_type; /*3.2*/
      struct Slots {
        uint8_t slot; /*0.0*/
        uint8_t hotbar_slot; /*0.0*/
        uint8_t count; /*0.0*/
        int item_stack_id; /*0.0*/
        std::string custom_name; /*6.0*/
        int durability_correction; /*0.0*/
      };
      std::vector<Slots /*3.2*/> slots; /*3.0*/
    };
    std::vector<Containers /*3.2*/> containers; /*3.0*/
  };
  struct ItemComponentList {
    std::string name; /*6.0*/
    int8_t nbt; /*0.0*/
  };
  struct CommandOrigin {
    enum class Type : int {
      Player = 0,
      Block = 1,
      MinecartBlock = 2,
      DevConsole = 3,
      Test = 4,
      AutomationPlayer = 5,
      ClientAutomation = 6,
      DedicatedServer = 7,
      Entity = 8,
      Virtual = 9,
      GameArgument = 10,
      EntityServer = 11,
      Precompiled = 12,
      GameDirectorEntityServer = 13,
      Script = 14,
      Executor = 15,
    };
    Type type; /*3.2*/
    uint64_t uuid; /*0.0*/
    std::string request_id; /*6.0*/
    struct PlayerEntityId {
      int64_t player_entity_id; /*0.0*/
    };
    std::optional<PlayerEntityId> player_entity_id; /*3.2*/
  };
  struct TrackedObject {
    enum class Type : int32_t {
      Entity = 0,
      Block = 1,
    };
    Type type; /*3.2*/
    int64_t entity_unique_id; /*0.0*/
    std::optional<pdef::proto::BlockCoordinates> block_position; /*4.0*/
  };
  struct MapDecoration {
    uint8_t type; /*0.0*/
    uint8_t rotation; /*0.0*/
    uint8_t x; /*0.0*/
    uint8_t y; /*0.0*/
    std::string label; /*6.0*/
    int color_abgr; /*0.0*/
  };
  struct StructureBlockSettings {
    std::string palette_name; /*6.0*/
    bool ignore_entities; /*0.0*/
    bool ignore_blocks; /*0.0*/
    bool non_ticking_players_and_ticking_areas; /*0.0*/
    pdef::proto::BlockCoordinates size; /*4.0*/
    pdef::proto::BlockCoordinates structure_offset; /*4.0*/
    int64_t last_editing_player_unique_id; /*0.0*/
    enum class Rotation : uint8_t {
      None = 0,
      _90Deg = 1,
      _180Deg = 2,
      _270Deg = 3,
    };
    Rotation rotation; /*3.2*/
    enum class Mirror : uint8_t {
      None = 0,
      XAxis = 1,
      ZAxis = 2,
      BothAxes = 3,
    };
    Mirror mirror; /*3.2*/
    enum class AnimationMode : uint8_t {
      None = 0,
      Layers = 1,
      Blocks = 2,
    };
    AnimationMode animation_mode; /*3.2*/
    float animation_duration; /*0.0*/
    float integrity; /*0.0*/
    uint32_t seed; /*0.0*/
    pdef::proto::vec3f pivot; /*4.0*/
  };
  struct EducationSharedResourceURI {
    std::string button_name; /*6.0*/
    std::string link_uri; /*6.0*/
  };
  struct EducationExternalLinkSettings {
    std::string url; /*6.0*/
    std::string display_name; /*6.0*/
  };
  struct BlockUpdate {
    pdef::proto::BlockCoordinates position; /*4.0*/
    int runtime_id; /*0.0*/
    int flags; /*0.0*/
    int64_t entity_unique_id; /*0.0*/
    enum class TransitionType : int {
      Entity = 0,
      Create = 1,
      Destroy = 2,
    };
    TransitionType transition_type; /*3.2*/
  };
  struct MaterialReducer {
    int mix; /*0.0*/
    struct Items {
      int network_id; /*0.0*/
      int count; /*0.0*/
    };
    Items items; /*3.2*/
  };
  enum class PermissionLevel : int {
    Visitor = 0,
    Member = 1,
    Operator = 2,
    Custom = 3,
  };
  enum class WindowID : int8_t {
    Inventory = 0,
    First = 1,
    Last = 100,
    Offhand = 119,
    Armor = 120,
    Creative = 121,
    Hotbar = 122,
    FixedInventory = 123,
    Ui = 124,
    DropContents = -100,
    Beacon = -24,
    TradingOutput = -23,
    TradingUseInputs = -22,
    TradingInput2 = -21,
    TradingInput1 = -20,
    EnchantOutput = -17,
    EnchantMaterial = -16,
    EnchantInput = -15,
    AnvilOutput = -13,
    AnvilResult = -12,
    AnvilMaterial = -11,
    ContainerInput = -10,
    CraftingUseIngredient = -5,
    CraftingResult = -4,
    CraftingRemoveIngredient = -3,
    CraftingAddIngredient = -2,
    None = -1,
  };
  enum class WindowIDVarint : int {
    Inventory = 0,
    First = 1,
    Last = 100,
    Offhand = 119,
    Armor = 120,
    Creative = 121,
    Hotbar = 122,
    FixedInventory = 123,
    Ui = 124,
    DropContents = -100,
    Beacon = -24,
    TradingOutput = -23,
    TradingUseInputs = -22,
    TradingInput2 = -21,
    TradingInput1 = -20,
    EnchantOutput = -17,
    EnchantMaterial = -16,
    EnchantInput = -15,
    AnvilOutput = -13,
    AnvilResult = -12,
    AnvilMaterial = -11,
    ContainerInput = -10,
    CraftingUseIngredient = -5,
    CraftingResult = -4,
    CraftingRemoveIngredient = -3,
    CraftingAddIngredient = -2,
    None = -1,
  };
  enum class WindowType : int8_t {
    Container = 0,
    Workbench = 1,
    Furnace = 2,
    Enchantment = 3,
    BrewingStand = 4,
    Anvil = 5,
    Dispenser = 6,
    Dropper = 7,
    Hopper = 8,
    Cauldron = 9,
    MinecartChest = 10,
    MinecartHopper = 11,
    Horse = 12,
    Beacon = 13,
    StructureEditor = 14,
    Trading = 15,
    CommandBlock = 16,
    Jukebox = 17,
    Armor = 18,
    Hand = 19,
    CompoundCreator = 20,
    ElementConstructor = 21,
    MaterialReducer = 22,
    LabTable = 23,
    Loom = 24,
    Lectern = 25,
    Grindstone = 26,
    BlastFurnace = 27,
    Smoker = 28,
    Stonecutter = 29,
    Cartography = 30,
    Hud = 31,
    JigsawEditor = 32,
    SmithingTable = 33,
    None = -9,
    Inventory = -1,
  };
  enum class ContainerSlotType : uint8_t {
    AnvilInput = 0,
    AnvilMaterial = 1,
    AnvilResult = 2,
    SmithingTableInput = 3,
    SmithingTableMaterial = 4,
    SmithingTableResult = 5,
    Armor = 6,
    Container = 7,
    BeaconPayment = 8,
    BrewingInput = 9,
    BrewingResult = 10,
    BrewingFuel = 11,
    HotbarAndInventory = 12,
    CraftingInput = 13,
    CraftingOutput = 14,
    RecipeConstruction = 15,
    RecipeNature = 16,
    RecipeItems = 17,
    RecipeSearch = 18,
    RecipeSearchBar = 19,
    RecipeEquipment = 20,
    EnchantingInput = 21,
    EnchantingLapis = 22,
    FurnaceFuel = 23,
    FurnaceIngredient = 24,
    FurnaceOutput = 25,
    HorseEquip = 26,
    Hotbar = 27,
    Inventory = 28,
    Shulker = 29,
    TradeIngredient1 = 30,
    TradeIngredient2 = 31,
    TradeResult = 32,
    Offhand = 33,
    CompcreateInput = 34,
    CompcreateOutput = 35,
    ElemconstructOutput = 36,
    MatreduceInput = 37,
    MatreduceOutput = 38,
    LabtableInput = 39,
    LoomInput = 40,
    LoomDye = 41,
    LoomMaterial = 42,
    LoomResult = 43,
    BlastFurnaceIngredient = 44,
    SmokerIngredient = 45,
    Trade2Ingredient1 = 46,
    Trade2Ingredient2 = 47,
    Trade2Result = 48,
    GrindstoneInput = 49,
    GrindstoneAdditional = 50,
    GrindstoneResult = 51,
    StonecutterInput = 52,
    StonecutterResult = 53,
    CartographyInput = 54,
    CartographyAdditional = 55,
    CartographyResult = 56,
    Barrel = 57,
    Cursor = 58,
    CreativeOutput = 59,
  };
  enum class SoundType : int {
    ItemUseOn = 0,
    Hit = 1,
    Step = 2,
    Fly = 3,
    Jump = 4,
    Break = 5,
    Place = 6,
    HeavyStep = 7,
    Gallop = 8,
    Fall = 9,
    Ambient = 10,
    AmbientBaby = 11,
    AmbientInWater = 12,
    Breathe = 13,
    Death = 14,
    DeathInWater = 15,
    DeathToZombie = 16,
    Hurt = 17,
    HurtInWater = 18,
    Mad = 19,
    Boost = 20,
    Bow = 21,
    SquishBig = 22,
    SquishSmall = 23,
    FallBig = 24,
    FallSmall = 25,
    Splash = 26,
    Fizz = 27,
    Flap = 28,
    Swim = 29,
    Drink = 30,
    Eat = 31,
    Takeoff = 32,
    Shake = 33,
    Plop = 34,
    Land = 35,
    Saddle = 36,
    Armor = 37,
    MobArmorStandPlace = 38,
    AddChest = 39,
    Throw = 40,
    Attack = 41,
    AttackNoDamage = 42,
    AttackStrong = 43,
    Warn = 44,
    Shear = 45,
    Milk = 46,
    Thunder = 47,
    Explode = 48,
    Fire = 49,
    Ignite = 50,
    Fuse = 51,
    Stare = 52,
    Spawn = 53,
    Shoot = 54,
    BreakBlock = 55,
    Launch = 56,
    Blast = 57,
    LargeBlast = 58,
    Twinkle = 59,
    Remedy = 60,
    Infect = 61,
    LevelUp = 62,
    BowHit = 63,
    BulletHit = 64,
    ExtinguishFire = 65,
    ItemFizz = 66,
    ChestOpen = 67,
    ChestClosed = 68,
    ShulkerBoxOpen = 69,
    ShulkerBoxClosed = 70,
    EnderChestOpen = 71,
    EnderChestClosed = 72,
    PowerOn = 73,
    PowerOff = 74,
    Attach = 75,
    Detach = 76,
    Deny = 77,
    Tripod = 78,
    Pop = 79,
    DropSlot = 80,
    Note = 81,
    Thorns = 82,
    PistonIn = 83,
    PistonOut = 84,
    Portal = 85,
    Water = 86,
    LavaPop = 87,
    Lava = 88,
    Burp = 89,
    BucketFillWater = 90,
    BucketFillLava = 91,
    BucketEmptyWater = 92,
    BucketEmptyLava = 93,
    ArmorEquipChain = 94,
    ArmorEquipDiamond = 95,
    ArmorEquipGeneric = 96,
    ArmorEquipGold = 97,
    ArmorEquipIron = 98,
    ArmorEquipLeather = 99,
    ArmorEquipElytra = 100,
    Record13 = 101,
    RecordCat = 102,
    RecordBlocks = 103,
    RecordChirp = 104,
    RecordFar = 105,
    RecordMall = 106,
    RecordMellohi = 107,
    RecordStal = 108,
    RecordStrad = 109,
    RecordWard = 110,
    Record11 = 111,
    RecordWait = 112,
    StopRecord = 113,
    Flop = 114,
    GuardianCurse = 115,
    MobWarning = 116,
    MobWarningBaby = 117,
    Teleport = 118,
    ShulkerOpen = 119,
    ShulkerClose = 120,
    Haggle = 121,
    HaggleYes = 122,
    HaggleNo = 123,
    HaggleIdle = 124,
    ChorusGrow = 125,
    ChorusDeath = 126,
    Glass = 127,
    PotionBrewed = 128,
    CastSpell = 129,
    PrepareAttackSpell = 130,
    PrepareSummon = 131,
    PrepareWololo = 132,
    Fang = 133,
    Charge = 134,
    CameraTakePicture = 135,
    LeashKnotPlace = 136,
    LeashKnotBreak = 137,
    AmbientGrowl = 138,
    AmbientWhine = 139,
    AmbientPant = 140,
    AmbientPurr = 141,
    AmbientPurreow = 142,
    DeathMinVolume = 143,
    DeathMidVolume = 144,
    ImitateBlaze = 145,
    ImitateCaveSpider = 146,
    ImitateCreeper = 147,
    ImitateElderGuardian = 148,
    ImitateEnderDragon = 149,
    ImitateEnderman = 150,
    ImitateEndermite = 151,
    ImitateEvocationIllager = 152,
    ImitateGhast = 153,
    ImitateHusk = 154,
    ImitateIllusionIllager = 155,
    ImitateMagmaCube = 156,
    ImitatePolarBear = 157,
    ImitateShulker = 158,
    ImitateSilverfish = 159,
    ImitateSkeleton = 160,
    ImitateSlime = 161,
    ImitateSpider = 162,
    ImitateStray = 163,
    ImitateVex = 164,
    ImitateVindicationIllager = 165,
    ImitateWitch = 166,
    ImitateWither = 167,
    ImitateWitherSkeleton = 168,
    ImitateWolf = 169,
    ImitateZombie = 170,
    ImitateZombiePigman = 171,
    ImitateZombieVillager = 172,
    EnderEyePlaced = 173,
    EndPortalCreated = 174,
    AnvilUse = 175,
    BottleDragonBreath = 176,
    PortalTravel = 177,
    TridentHit = 178,
    TridentReturn = 179,
    TridentRiptide1 = 180,
    TridentRiptide2 = 181,
    TridentRiptide3 = 182,
    TridentThrow = 183,
    TridentThunder = 184,
    TridentHitGround = 185,
    Default = 186,
    FletchingTableUse = 187,
    ElemConstructOpen = 188,
    IceBombHit = 189,
    BalloonPop = 190,
    LtReactionIceBomb = 191,
    LtReactionBleach = 192,
    LtReactionElephantToothpaste = 193,
    LtReactionElephantToothpaste2 = 194,
    LtReactionGlowStick = 195,
    LtReactionGlowStick2 = 196,
    LtReactionLuminol = 197,
    LtReactionSalt = 198,
    LtReactionFertilizer = 199,
    LtReactionFireball = 200,
    LtReactionMagnesiumSalt = 201,
    LtReactionMiscFire = 202,
    LtReactionFire = 203,
    LtReactionMiscExplosion = 204,
    LtReactionMiscMystical = 205,
    LtReactionMiscMystical2 = 206,
    LtReactionProduct = 207,
    SparklerUse = 208,
    GlowStickUse = 209,
    SparklerActive = 210,
    ConvertToDrowned = 211,
    BucketFillFish = 212,
    BucketEmptyFish = 213,
    BubbleColumnUpwards = 214,
    BubbleColumnDownwards = 215,
    BubblePop = 216,
    BubbleUpInside = 217,
    BubbleDownInside = 218,
    HurtBaby = 219,
    DeathBaby = 220,
    StepBaby = 221,
    SpawnBaby = 222,
    Born = 223,
    TurtleEggBreak = 224,
    TurtleEggCrack = 225,
    TurtleEggHatched = 226,
    LayEgg = 227,
    TurtleEggAttacked = 228,
    BeaconActivate = 229,
    BeaconAmbient = 230,
    BeaconDeactivate = 231,
    BeaconPower = 232,
    ConduitActivate = 233,
    ConduitAmbient = 234,
    ConduitAttack = 235,
    ConduitDeactivate = 236,
    ConduitShort = 237,
    Swoop = 238,
    BambooSaplingPlace = 239,
    PreSneeze = 240,
    Sneeze = 241,
    AmbientTame = 242,
    Scared = 243,
    ScaffoldingClimb = 244,
    CrossbowLoadingStart = 245,
    CrossbowLoadingMiddle = 246,
    CrossbowLoadingEnd = 247,
    CrossbowShoot = 248,
    CrossbowQuickChargeStart = 249,
    CrossbowQuickChargeMiddle = 250,
    CrossbowQuickChargeEnd = 251,
    AmbientAggressive = 252,
    AmbientWorried = 253,
    CantBreed = 254,
    ShieldBlock = 255,
    LecternBookPlace = 256,
    GrindstoneUse = 257,
    Bell = 258,
    CampfireCrackle = 259,
    Roar = 260,
    Stun = 261,
    SweetBerryBushHurt = 262,
    SweetBerryBushPick = 263,
    CartographyTableUse = 264,
    StonecutterUse = 265,
    ComposterEmpty = 266,
    ComposterFill = 267,
    ComposterFillLayer = 268,
    ComposterReady = 269,
    BarrelOpen = 270,
    BarrelClose = 271,
    RaidHorn = 272,
    LoomUse = 273,
    AmbientInRaid = 274,
    UicartographyTableUse = 275,
    UistonecutterUse = 276,
    UiloomUse = 277,
    SmokerUse = 278,
    BlastFurnaceUse = 279,
    SmithingTableUse = 280,
    Screech = 281,
    Sleep = 282,
    FurnaceUse = 283,
    MooshroomConvert = 284,
    MilkSuspiciously = 285,
    Celebrate = 286,
    JumpPrevent = 287,
    AmbientPollinate = 288,
    BeehiveDrip = 289,
    BeehiveEnter = 290,
    BeehiveExit = 291,
    BeehiveWork = 292,
    BeehiveShear = 293,
    HoneybottleDrink = 294,
    AmbientCave = 295,
    Retreat = 296,
    ConvertToZombified = 297,
    Admire = 298,
    StepLava = 299,
    Tempt = 300,
    Panic = 301,
    Angry = 302,
    AmbientMoodWarpedForest = 303,
    AmbientMoodSoulsandValley = 304,
    AmbientMoodNetherWastes = 305,
    AmbientMoodBasaltDeltas = 306,
    AmbientMoodCrimsonForest = 307,
    RespawnAnchorCharge = 308,
    RespawnAnchorDeplete = 309,
    RespawnAnchorSetSpawn = 310,
    RespawnAnchorAmbient = 311,
    SoulEscapeQuiet = 312,
    SoulEscapeLoud = 313,
    RecordPigstep = 314,
    LinkCompassToLodestone = 315,
    UseSmithingTable = 316,
    EquipNetherite = 317,
    AmbientLoopWarpedForest = 318,
    AmbientLoopSoulsandValley = 319,
    AmbientLoopNetherWastes = 320,
    AmbientLoopBasaltDeltas = 321,
    AmbientLoopCrimsonForest = 322,
    AmbientAdditionWarpedForest = 323,
    AmbientAdditionSoulsandValley = 324,
    AmbientAdditionNetherWastes = 325,
    AmbientAdditionBasaltDeltas = 326,
    AmbientAdditionCrimsonForest = 327,
    SculkSensorPowerOn = 328,
    SculkSensorPowerOff = 329,
    BucketFillPowderSnow = 330,
    BucketEmptyPowderSnow = 331,
    PointedDripstoneCauldronDripWater = 332,
    PointedDripstoneCauldronDripLava = 333,
    PointedDripstoneDripWater = 334,
    PointedDripstoneDripLava = 335,
    CaveVinesPickBerries = 336,
    BigDripleafTiltDown = 337,
    BigDripleafTiltUp = 338,
    CopperWaxOn = 339,
    CopperWaxOff = 340,
    Scrape = 341,
    PlayerHurtDrown = 342,
    PlayerHurtOnFire = 343,
    PlayerHurtFreeze = 344,
    UseSpyglass = 345,
    StopUsingSpyglass = 346,
    AmethystBlockChime = 347,
    AmbientScreamer = 348,
    HurtScreamer = 349,
    DeathScreamer = 350,
    MilkScreamer = 351,
    JumpToBlock = 352,
    PreRam = 353,
    PreRamScreamer = 354,
    RamImpact = 355,
    RamImpactScreamer = 356,
    SquidInkSquirt = 357,
    GlowSquidInkSquirt = 358,
    ConvertToStray = 359,
    CakeAddCandle = 360,
    ExtinguishCandle = 361,
    AmbientCandle = 362,
    BlockClick = 363,
    BlockClickFail = 364,
    SculkCatalystBloom = 365,
    SculkShriekerShriek = 366,
    WardenNearbyClose = 367,
    WardenNearbyCloser = 368,
    WardenNearbyClosest = 369,
    WardenSlightlyAngry = 370,
    RecordOtherside = 371,
    Tongue = 372,
    CrackIronGolem = 373,
    RepairIronGolem = 374,
    Listening = 375,
    Heartbeat = 376,
    HornBreak = 377,
    SculkPlace = 378,
    SculkSpread = 379,
    SculkCharge = 380,
    SculkSensorPlace = 381,
    SculkShriekerPlace = 382,
    GoatCall0 = 383,
    GoatCall1 = 384,
    GoatCall2 = 385,
    GoatCall3 = 386,
    GoatCall4 = 387,
    GoatCall5 = 388,
    GoatCall6 = 389,
    GoatCall7 = 390,
    GoatCall8 = 391,
    GoatCall9 = 392,
    GoatHarmony0 = 393,
    GoatHarmony1 = 394,
    GoatHarmony2 = 395,
    GoatHarmony3 = 396,
    GoatHarmony4 = 397,
    GoatHarmony5 = 398,
    GoatHarmony6 = 399,
    GoatHarmony7 = 400,
    GoatHarmony8 = 401,
    GoatHarmony9 = 402,
    GoatMelody0 = 403,
    GoatMelody1 = 404,
    GoatMelody2 = 405,
    GoatMelody3 = 406,
    GoatMelody4 = 407,
    GoatMelody5 = 408,
    GoatMelody6 = 409,
    GoatMelody7 = 410,
    GoatMelody8 = 411,
    GoatMelody9 = 412,
    GoatBass0 = 413,
    GoatBass1 = 414,
    GoatBass2 = 415,
    GoatBass3 = 416,
    GoatBass4 = 417,
    GoatBass5 = 418,
    GoatBass6 = 419,
    GoatBass7 = 420,
    GoatBass8 = 421,
    GoatBass9 = 422,
    __ = 423,
    __0 = 424,
    __1 = 425,
    ImitateWarden = 426,
    ListeningAngry = 427,
    ItemGiven = 428,
    ItemTaken = 429,
    Disappeared = 430,
    Reappeared = 431,
    __2 = 432,
    FrogspawnHatched = 433,
    LaySpawn = 434,
    FrogspawnBreak = 435,
    SonicBoom = 436,
    SonicCharge = 437,
    SoundeventItemThrown = 438,
    Record5 = 439,
    ConvertToFrog = 440,
    Undefined = 441,
  };
  enum class LegacyEntityType : int32_t {
    Chicken = 10,
    Cow = 11,
    Pig = 12,
    Sheep = 13,
    Wolf = 14,
    Villager = 15,
    Mooshroom = 16,
    Squid = 17,
    Rabbit = 18,
    Bat = 19,
    IronGolem = 20,
    SnowGolem = 21,
    Ocelot = 22,
    Horse = 23,
    Donkey = 24,
    Mule = 25,
    SkeletonHorse = 26,
    ZombieHorse = 27,
    PolarBear = 28,
    Llama = 29,
    Parrot = 30,
    Dolphin = 31,
    Zombie = 32,
    Creeper = 33,
    Skeleton = 34,
    Spider = 35,
    ZombiePigman = 36,
    Slime = 37,
    Enderman = 38,
    Silverfish = 39,
    CaveSpider = 40,
    Ghast = 41,
    MagmaCube = 42,
    Blaze = 43,
    ZombieVillager = 44,
    Witch = 45,
    Stray = 46,
    Husk = 47,
    WitherSkeleton = 48,
    Guardian = 49,
    ElderGuardian = 50,
    Npc = 51,
    Wither = 52,
    EnderDragon = 53,
    Shulker = 54,
    Endermite = 55,
    Agent = 56,
    Vindicator = 57,
    Phantom = 58,
    ArmorStand = 61,
    TripodCamera = 62,
    Player = 63,
    Item = 64,
    Tnt = 65,
    FallingBlock = 66,
    MovingBlock = 67,
    XpBottle = 68,
    XpOrb = 69,
    EyeOfEnderSignal = 70,
    EnderCrystal = 71,
    FireworksRocket = 72,
    ThrownTrident = 73,
    Turtle = 74,
    Cat = 75,
    ShulkerBullet = 76,
    FishingHook = 77,
    Chalkboard = 78,
    DragonFireball = 79,
    Arrow = 80,
    Snowball = 81,
    Egg = 82,
    Painting = 83,
    Minecart = 84,
    Fireball = 85,
    SplashPotion = 86,
    EnderPearl = 87,
    LeashKnot = 88,
    WitherSkull = 89,
    Boat = 90,
    WitherSkullDangerous = 91,
    LightningBolt = 93,
    SmallFireball = 94,
    AreaEffectCloud = 95,
    HopperMinecart = 96,
    TntMinecart = 97,
    ChestMinecart = 98,
    CommandBlockMinecart = 100,
    LingeringPotion = 101,
    LlamaSpit = 102,
    EvocationFang = 103,
    EvocationIllager = 104,
    Vex = 105,
    IceBomb = 106,
    Balloon = 107,
    Pufferfish = 108,
    Salmon = 109,
    Drowned = 110,
    Tropicalfish = 111,
    Cod = 112,
    Panda = 113,
  };
  enum class DeviceOS : int32_t {
    Undefined = 0,
    Android = 1,
    IOS = 2,
    OSX = 3,
    FireOS = 4,
    GearVR = 5,
    Hololens = 6,
    Win10 = 7,
    Win32 = 8,
    Dedicated = 9,
    TVOS = 10,
    Orbis = 11,
    NintendoSwitch = 12,
    Xbox = 13,
    WindowsPhone = 14,
    Linux = 15,
  };
  struct packet_login {
    int32_t protocol_version; /*0.0*/
    int8_t tokens; /*0.0*/
  };
  struct LoginTokens {
    std::string identity; /*6.0*/
    std::string client; /*6.0*/
  };
  struct packet_play_status {
    enum class Status : int32_t {
      LoginSuccess = 0,
      FailedClient = 1,
      FailedSpawn = 2,
      PlayerSpawn = 3,
      FailedInvalidTenant = 4,
      FailedVanillaEdu = 5,
      FailedEduVanilla = 6,
      FailedServerFull = 7,
    };
    Status status; /*3.2*/
  };
  struct packet_server_to_client_handshake {
    std::string token; /*6.0*/
  };
  struct packet_client_to_server_handshake {
  };
  struct packet_disconnect {
    bool hide_disconnect_reason; /*0.0*/
    std::string message; /*6.0*/
  };
  struct packet_resource_packs_info {
    bool must_accept; /*0.0*/
    bool has_scripts; /*0.0*/
    bool force_server_packs; /*0.0*/
    std::vector<pdef::proto::BehaviourPackInfos> behaviour_packs; /*1.0*/
    std::vector<pdef::proto::TexturePackInfos> texture_packs; /*1.0*/
  };
  struct packet_resource_pack_stack {
    bool must_accept; /*0.0*/
    std::vector<pdef::proto::ResourcePackIdVersions> behavior_packs; /*1.0*/
    std::vector<pdef::proto::ResourcePackIdVersions> resource_packs; /*1.0*/
    std::string game_version; /*6.0*/
    std::vector<pdef::proto::Experiment /*4.0*/> experiments; /*3.0*/
    bool experiments_previously_used; /*0.0*/
  };
  struct packet_resource_pack_client_response {
    enum class ResponseStatus : uint8_t {
      None = 0,
      Refused = 1,
      SendPacks = 2,
      HaveAllPacks = 3,
      Completed = 4,
    };
    ResponseStatus response_status; /*3.2*/
    std::vector<std::string /*6.0*/> resourcepackids; /*3.0*/
  };
  struct packet_text {
    enum class Type : uint8_t {
      Raw = 0,
      Chat = 1,
      Translation = 2,
      Popup = 3,
      JukeboxPopup = 4,
      Tip = 5,
      System = 6,
      Whisper = 7,
      Announcement = 8,
      JsonWhisper = 9,
      Json = 10,
    };
    Type type; /*3.2*/
    bool needs_translation; /*0.0*/
    std::string xuid; /*6.0*/
    std::string platform_chat_id; /*6.0*/
    std::string source_name; /*6.0*/
    std::string message; /*6.0*/
    std::vector<std::string /*6.0*/> parameters; /*3.0*/
  };
  struct packet_set_time {
    int time; /*0.0*/
  };
  struct packet_start_game {
    int64_t entity_id; /*0.0*/
    int64_t runtime_entity_id; /*0.0*/
    enum class PlayerGamemode : int {
      Survival = 0,
      Creative = 1,
      Adventure = 2,
      SurvivalSpectator = 3,
      CreativeSpectator = 4,
      Fallback = 5,
      Spectator = 6,
    };
    PlayerGamemode player_gamemode; /*3.2*/
    pdef::proto::vec3f player_position; /*4.0*/
    pdef::proto::vec2f rotation; /*4.0*/
    uint64_t seed; /*0.0*/
    int16_t biome_type; /*0.0*/
    std::string biome_name; /*6.0*/
    enum class Dimension : int {
      Overworld = 0,
      Nether = 1,
      End = 2,
    };
    Dimension dimension; /*3.2*/
    int generator; /*0.0*/
    enum class WorldGamemode : int {
      Survival = 0,
      Creative = 1,
      Adventure = 2,
      SurvivalSpectator = 3,
      CreativeSpectator = 4,
      Fallback = 5,
      Spectator = 6,
    };
    WorldGamemode world_gamemode; /*3.2*/
    int difficulty; /*0.0*/
    pdef::proto::BlockCoordinates spawn_position; /*4.0*/
    bool achievements_disabled; /*0.0*/
    int day_cycle_stop_time; /*0.0*/
    int edu_offer; /*0.0*/
    bool edu_features_enabled; /*0.0*/
    std::string edu_product_uuid; /*6.0*/
    float rain_level; /*0.0*/
    float lightning_level; /*0.0*/
    bool has_confirmed_platform_locked_content; /*0.0*/
    bool is_multiplayer; /*0.0*/
    bool broadcast_to_lan; /*0.0*/
    int xbox_live_broadcast_mode; /*0.0*/
    int platform_broadcast_mode; /*0.0*/
    bool enable_commands; /*0.0*/
    bool is_texturepacks_required; /*0.0*/
    std::vector<pdef::proto::GameRule /*4.0*/> gamerules; /*3.0*/
    std::vector<pdef::proto::Experiment /*4.0*/> experiments; /*3.0*/
    bool experiments_previously_used; /*0.0*/
    bool bonus_chest; /*0.0*/
    bool map_enabled; /*0.0*/
    int permission_level; /*0.0*/
    int32_t server_chunk_tick_range; /*0.0*/
    bool has_locked_behavior_pack; /*0.0*/
    bool has_locked_resource_pack; /*0.0*/
    bool is_from_locked_world_template; /*0.0*/
    bool msa_gamertags_only; /*0.0*/
    bool is_from_world_template; /*0.0*/
    bool is_world_template_option_locked; /*0.0*/
    bool only_spawn_v1_villagers; /*0.0*/
    std::string game_version; /*6.0*/
    int32_t limited_world_width; /*0.0*/
    int32_t limited_world_length; /*0.0*/
    bool is_new_nether; /*0.0*/
    pdef::proto::EducationSharedResourceURI edu_resource_uri; /*4.0*/
    bool experimental_gameplay_override; /*0.0*/
    std::string level_id; /*6.0*/
    std::string world_name; /*6.0*/
    std::string premium_world_template_id; /*6.0*/
    bool is_trial; /*0.0*/
    enum class MovementAuthority : int {
      Client = 0,
      Server = 1,
      ServerWithRewind = 2,
    };
    MovementAuthority movement_authority; /*3.2*/
    int rewind_history_size; /*0.0*/
    bool server_authoritative_block_breaking; /*0.0*/
    int64_t current_tick; /*0.0*/
    int enchantment_seed; /*0.0*/
    std::vector<pdef::proto::BlockProperties> block_properties; /*1.0*/
    std::vector<pdef::proto::Itemstates> itemstates; /*1.0*/
    std::string multiplayer_correlation_id; /*6.0*/
    bool server_authoritative_inventory; /*0.0*/
    std::string engine; /*6.0*/
    int8_t property_data; /*0.0*/
    uint64_t block_pallette_checksum; /*0.0*/
    uint64_t world_template_id; /*0.0*/
  };
  struct packet_add_player {
    uint64_t uuid; /*0.0*/
    std::string username; /*6.0*/
    int64_t unique_entity_id; /*0.0*/
    int64_t runtime_entity_id; /*0.0*/
    std::string platform_chat_id; /*6.0*/
    pdef::proto::vec3f position; /*4.0*/
    pdef::proto::vec3f velocity; /*4.0*/
    float pitch; /*0.0*/
    float yaw; /*0.0*/
    float head_yaw; /*0.0*/
    pdef::proto::Item held_item; /*4.0*/
    enum class Gamemode : int {
      Survival = 0,
      Creative = 1,
      Adventure = 2,
      SurvivalSpectator = 3,
      CreativeSpectator = 4,
      Fallback = 5,
      Spectator = 6,
    };
    Gamemode gamemode; /*3.2*/
    std::vector<pdef::proto::MetadataDictionary> metadata; /*1.0*/
    int flags; /*0.0*/
    int command_permission; /*0.0*/
    int action_permissions; /*0.0*/
    int permission_level; /*0.0*/
    int custom_stored_permissions; /*0.0*/
    int64_t user_id; /*0.0*/
    std::vector<pdef::proto::Link /*4.0*/> links; /*3.0*/
    std::string device_id; /*6.0*/
    enum class DeviceOs : int32_t {
      Undefined = 0,
      Android = 1,
      IOS = 2,
      OSX = 3,
      FireOS = 4,
      GearVR = 5,
      Hololens = 6,
      Win10 = 7,
      Win32 = 8,
      Dedicated = 9,
      TVOS = 10,
      Orbis = 11,
      NintendoSwitch = 12,
      Xbox = 13,
      WindowsPhone = 14,
      Linux = 15,
    };
    DeviceOs device_os; /*3.2*/
  };
  struct packet_add_entity {
    int64_t entity_id_self; /*0.0*/
    int64_t runtime_entity_id; /*0.0*/
    std::string entity_type; /*6.0*/
    pdef::proto::vec3f position; /*4.0*/
    pdef::proto::vec3f velocity; /*4.0*/
    float pitch; /*0.0*/
    float yaw; /*0.0*/
    float head_yaw; /*0.0*/
    std::vector<pdef::proto::EntityAttributes> attributes; /*1.0*/
    std::vector<pdef::proto::MetadataDictionary> metadata; /*1.0*/
    std::vector<pdef::proto::Link /*4.0*/> links; /*3.0*/
  };
  struct packet_remove_entity {
    int64_t entity_id_self; /*0.0*/
  };
  struct packet_add_item_entity {
    int64_t entity_id_self; /*0.0*/
    int64_t runtime_entity_id; /*0.0*/
    pdef::proto::Item item; /*4.0*/
    pdef::proto::vec3f position; /*4.0*/
    pdef::proto::vec3f velocity; /*4.0*/
    std::vector<pdef::proto::MetadataDictionary> metadata; /*1.0*/
    bool is_from_fishing; /*0.0*/
  };
  struct packet_take_item_entity {
    int64_t runtime_entity_id; /*0.0*/
    int target; /*0.0*/
  };
  struct packet_move_entity {
    int64_t runtime_entity_id; /*0.0*/
    uint8_t flags; /*0.0*/
    pdef::proto::vec3f position; /*4.0*/
    pdef::proto::Rotation rotation; /*4.0*/
  };
  struct packet_move_player {
    int runtime_id; /*0.0*/
    pdef::proto::vec3f position; /*4.0*/
    float pitch; /*0.0*/
    float yaw; /*0.0*/
    float head_yaw; /*0.0*/
    enum class Mode : uint8_t {
      Normal = 0,
      Reset = 1,
      Teleport = 2,
      Rotation = 3,
    };
    Mode mode; /*3.2*/
    bool on_ground; /*0.0*/
    int ridden_runtime_id; /*0.0*/
    int64_t tick; /*0.0*/
    struct Teleport {
      enum class Cause : int32_t {
        Unknown = 0,
        Projectile = 1,
        ChorusFruit = 2,
        Command = 3,
        Behavior = 4,
      };
      Cause cause; /*3.2*/
      enum class SourceEntityType : int32_t {
        Chicken = 10,
        Cow = 11,
        Pig = 12,
        Sheep = 13,
        Wolf = 14,
        Villager = 15,
        Mooshroom = 16,
        Squid = 17,
        Rabbit = 18,
        Bat = 19,
        IronGolem = 20,
        SnowGolem = 21,
        Ocelot = 22,
        Horse = 23,
        Donkey = 24,
        Mule = 25,
        SkeletonHorse = 26,
        ZombieHorse = 27,
        PolarBear = 28,
        Llama = 29,
        Parrot = 30,
        Dolphin = 31,
        Zombie = 32,
        Creeper = 33,
        Skeleton = 34,
        Spider = 35,
        ZombiePigman = 36,
        Slime = 37,
        Enderman = 38,
        Silverfish = 39,
        CaveSpider = 40,
        Ghast = 41,
        MagmaCube = 42,
        Blaze = 43,
        ZombieVillager = 44,
        Witch = 45,
        Stray = 46,
        Husk = 47,
        WitherSkeleton = 48,
        Guardian = 49,
        ElderGuardian = 50,
        Npc = 51,
        Wither = 52,
        EnderDragon = 53,
        Shulker = 54,
        Endermite = 55,
        Agent = 56,
        Vindicator = 57,
        Phantom = 58,
        ArmorStand = 61,
        TripodCamera = 62,
        Player = 63,
        Item = 64,
        Tnt = 65,
        FallingBlock = 66,
        MovingBlock = 67,
        XpBottle = 68,
        XpOrb = 69,
        EyeOfEnderSignal = 70,
        EnderCrystal = 71,
        FireworksRocket = 72,
        ThrownTrident = 73,
        Turtle = 74,
        Cat = 75,
        ShulkerBullet = 76,
        FishingHook = 77,
        Chalkboard = 78,
        DragonFireball = 79,
        Arrow = 80,
        Snowball = 81,
        Egg = 82,
        Painting = 83,
        Minecart = 84,
        Fireball = 85,
        SplashPotion = 86,
        EnderPearl = 87,
        LeashKnot = 88,
        WitherSkull = 89,
        Boat = 90,
        WitherSkullDangerous = 91,
        LightningBolt = 93,
        SmallFireball = 94,
        AreaEffectCloud = 95,
        HopperMinecart = 96,
        TntMinecart = 97,
        ChestMinecart = 98,
        CommandBlockMinecart = 100,
        LingeringPotion = 101,
        LlamaSpit = 102,
        EvocationFang = 103,
        EvocationIllager = 104,
        Vex = 105,
        IceBomb = 106,
        Balloon = 107,
        Pufferfish = 108,
        Salmon = 109,
        Drowned = 110,
        Tropicalfish = 111,
        Cod = 112,
        Panda = 113,
      };
      SourceEntityType source_entity_type; /*3.2*/
    };
    std::optional<Teleport> teleport; /*3.2*/
  };
  struct packet_rider_jump {
    int jump_strength; /*0.0*/
  };
  struct packet_update_block {
    pdef::proto::BlockCoordinates position; /*4.0*/
    int block_runtime_id; /*0.0*/
    struct flags_t { /*6.0*/
      bool neighbors = false; /*6.0*/
      bool network = false; /*6.0*/
      bool no_graphic = false; /*6.0*/
      bool unused = false; /*6.0*/
      bool priority = false; /*6.0*/
    } flags; /*6.0*/
    int layer; /*0.0*/
  };
  struct packet_add_painting {
    int64_t entity_id_self; /*0.0*/
    int64_t runtime_entity_id; /*0.0*/
    pdef::proto::vec3f coordinates; /*4.0*/
    int direction; /*0.0*/
    std::string title; /*6.0*/
  };
  struct packet_tick_sync {
    int64_t request_time; /*0.0*/
    int64_t response_time; /*0.0*/
  };
  struct packet_level_sound_event_old {
    uint8_t sound_id; /*0.0*/
    pdef::proto::vec3f position; /*4.0*/
    int block_id; /*0.0*/
    int entity_type; /*0.0*/
    bool is_baby_mob; /*0.0*/
    bool is_global; /*0.0*/
  };
  struct packet_level_event {
    enum class Event : int {
      SoundClick = 1000,
      SoundClickFail = 1001,
      SoundShoot = 1002,
      SoundDoor = 1003,
      SoundFizz = 1004,
      SoundIgnite = 1005,
      SoundGhast = 1007,
      SoundGhastShoot = 1008,
      SoundBlazeShoot = 1009,
      SoundDoorBump = 1010,
      SoundDoorCrash = 1012,
      SoundEndermanTeleport = 1018,
      SoundAnvilBreak = 1020,
      SoundAnvilUse = 1021,
      SoundAnvilFall = 1022,
      SoundPop = 1030,
      SoundPortal = 1032,
      SoundItemframeAddItem = 1040,
      SoundItemframeRemove = 1041,
      SoundItemframePlace = 1042,
      SoundItemframeRemoveItem = 1043,
      SoundItemframeRotateItem = 1044,
      SoundCamera = 1050,
      SoundOrb = 1051,
      SoundTotem = 1052,
      SoundArmorStandBreak = 1060,
      SoundArmorStandHit = 1061,
      SoundArmorStandFall = 1062,
      SoundArmorStandPlace = 1063,
      PointedDripstoneLand = 1064,
      DyeUsed = 1065,
      InkSackUsed = 1066,
      ParticleShoot = 2000,
      ParticleDestroy = 2001,
      ParticleSplash = 2002,
      ParticleEyeDespawn = 2003,
      ParticleSpawn = 2004,
      ParticleCropGrowth = 2005,
      ParticleGuardianCurse = 2006,
      ParticleDeathSmoke = 2007,
      ParticleBlockForceField = 2008,
      ParticleProjectileHit = 2009,
      ParticleDragonEggTeleport = 2010,
      ParticleCropEaten = 2011,
      ParticleCritical = 2012,
      ParticleEndermanTeleport = 2013,
      ParticlePunchBlock = 2014,
      ParticleBubble = 2015,
      ParticleEvaporate = 2016,
      ParticleDestroyArmorStand = 2017,
      ParticleBreakingEgg = 2018,
      ParticleDestroyEgg = 2019,
      ParticleEvaporateWater = 2020,
      ParticleDestroyBlockNoSound = 2021,
      ParticleKnockbackRoar = 2022,
      ParticleTeleportTrail = 2023,
      ParticlePointCloud = 2024,
      ParticleExplosion = 2025,
      ParticleBlockExplosion = 2026,
      ParticleVibrationSignal = 2027,
      ParticleDripstoneDrip = 2028,
      ParticleFizzEffect = 2029,
      ParticleWaxOn = 2030,
      ParticleWaxOff = 2031,
      ParticleScrape = 2032,
      ParticleElectricSpark = 2033,
      ParticleTurtleEgg = 2034,
      ParticleSculkShriek = 2035,
      SculkCatalystBloom = 2036,
      SculkCharge = 2037,
      SculkChargePop = 2038,
      SonicExplosion = 2039,
      StartRain = 3001,
      StartThunder = 3002,
      StopRain = 3003,
      StopThunder = 3004,
      PauseGame = 3005,
      PauseGameNoScreen = 3006,
      SetGameSpeed = 3007,
      RedstoneTrigger = 3500,
      CauldronExplode = 3501,
      CauldronDyeArmor = 3502,
      CauldronCleanArmor = 3503,
      CauldronFillPotion = 3504,
      CauldronTakePotion = 3505,
      CauldronFillWater = 3506,
      CauldronTakeWater = 3507,
      CauldronAddDye = 3508,
      CauldronCleanBanner = 3509,
      BlockStartBreak = 3600,
      BlockStopBreak = 3601,
      SetData = 4000,
      PlayersSleeping = 9800,
      SleepingPlayers = 9801,
      AddParticleMask = 16384,
      AddParticleBubble = 16385,
      AddParticleBubbleManual = 16386,
      AddParticleCritical = 16387,
      AddParticleBlockForceField = 16388,
      AddParticleSmoke = 16389,
      AddParticleExplode = 16390,
      AddParticleEvaporation = 16391,
      AddParticleFlame = 16392,
      AddParticleCandleFlame = 16393,
      AddParticleLava = 16394,
      AddParticleLargeSmoke = 16395,
      AddParticleRedstone = 16396,
      AddParticleRisingRedDust = 16397,
      AddParticleItemBreak = 16398,
      AddParticleSnowballPoof = 16399,
      AddParticleHugeExplode = 16400,
      AddParticleHugeExplodeSeed = 16401,
      AddParticleMobFlame = 16402,
      AddParticleHeart = 16403,
      AddParticleTerrain = 16404,
      AddParticleTownAura = 16405,
      AddParticlePortal = 16406,
      AddParticleWaterSplash = 16408,
      AddParticleWaterSplashManual = 16409,
      AddParticleWaterWake = 16410,
      AddParticleDripWater = 16411,
      AddParticleDripLava = 16412,
      AddParticleDripHoney = 16413,
      AddParticleStalactiteDripWater = 16414,
      AddParticleStalactiteDripLava = 16415,
      AddParticleFallingDust = 16416,
      AddParticleMobSpell = 16417,
      AddParticleMobSpellAmbient = 16418,
      AddParticleMobSpellInstantaneous = 16419,
      AddParticleInk = 16420,
      AddParticleSlime = 16421,
      AddParticleRainSplash = 16422,
      AddParticleVillagerAngry = 16423,
      AddParticleVillagerHappy = 16424,
      AddParticleEnchantmentTable = 16425,
      AddParticleTrackingEmitter = 16426,
      AddParticleNote = 16427,
      AddParticleWitchSpell = 16428,
      AddParticleCarrot = 16429,
      AddParticleMobAppearance = 16430,
      AddParticleEndRod = 16431,
      AddParticleDragonsBreath = 16432,
      AddParticleSpit = 16433,
      AddParticleTotem = 16434,
      AddParticleFood = 16435,
      AddParticleFireworksStarter = 16436,
      AddParticleFireworksSpark = 16437,
      AddParticleFireworksOverlay = 16438,
      AddParticleBalloonGas = 16439,
      AddParticleColoredFlame = 16440,
      AddParticleSparkler = 16441,
      AddParticleConduit = 16442,
      AddParticleBubbleColumnUp = 16443,
      AddParticleBubbleColumnDown = 16444,
      AddParticleSneeze = 16445,
      AddParticleShulkerBullet = 16446,
      AddParticleBleach = 16447,
      AddParticleDragonDestroyBlock = 16448,
      AddParticleMyceliumDust = 16449,
      AddParticleFallingRedDust = 16450,
      AddParticleCampfireSmoke = 16451,
      AddParticleTallCampfireSmoke = 16452,
      AddParticleDragonBreathFire = 16453,
      AddParticleDragonBreathTrail = 16454,
      AddParticleBlueFlame = 16455,
      AddParticleSoul = 16456,
      AddParticleObsidianTear = 16457,
      AddParticlePortalReverse = 16458,
      AddParticleSnowflake = 16459,
      AddParticleVibrationSignal = 16460,
      AddParticleSculkSensorRedstone = 16461,
      AddParticleSporeBlossomShower = 16462,
      AddParticleSporeBlossomAmbient = 16463,
      AddParticleWax = 16464,
      AddParticleElectricSpark = 16465,
    };
    Event event; /*3.2*/
    pdef::proto::vec3f position; /*4.0*/
    int data; /*0.0*/
  };
  struct packet_block_event {
    pdef::proto::BlockCoordinates position; /*4.0*/
    enum class Type : int {
      Sound = 0,
      ChangeState = 1,
    };
    Type type; /*3.2*/
    int data; /*0.0*/
  };
  struct packet_entity_event {
    int64_t runtime_entity_id; /*0.0*/
    enum class EventId : uint8_t {
      Jump = 1,
      HurtAnimation = 2,
      DeathAnimation = 3,
      ArmSwing = 4,
      StopAttack = 5,
      TameFail = 6,
      TameSuccess = 7,
      ShakeWet = 8,
      UseItem = 9,
      EatGrassAnimation = 10,
      FishHookBubble = 11,
      FishHookPosition = 12,
      FishHookHook = 13,
      FishHookTease = 14,
      SquidInkCloud = 15,
      ZombieVillagerCure = 16,
      Respawn = 18,
      IronGolemOfferFlower = 19,
      IronGolemWithdrawFlower = 20,
      LoveParticles = 21,
      VillagerAngry = 22,
      VillagerHappy = 23,
      WitchSpellParticles = 24,
      FireworkParticles = 25,
      InLoveParticles = 26,
      SilverfishSpawnAnimation = 27,
      GuardianAttack = 28,
      WitchDrinkPotion = 29,
      WitchThrowPotion = 30,
      MinecartTntPrimeFuse = 31,
      CreeperPrimeFuse = 32,
      AirSupplyExpired = 33,
      PlayerAddXpLevels = 34,
      ElderGuardianCurse = 35,
      AgentArmSwing = 36,
      EnderDragonDeath = 37,
      DustParticles = 38,
      ArrowShake = 39,
      EatingItem = 57,
      BabyAnimalFeed = 60,
      DeathSmokeCloud = 61,
      CompleteTrade = 62,
      RemoveLeash = 63,
      Caravan = 64,
      ConsumeTotem = 65,
      PlayerCheckTreasureHunterAchievement = 66,
      EntitySpawn = 67,
      DragonPuke = 68,
      ItemEntityMerge = 69,
      StartSwim = 70,
      BalloonPop = 71,
      TreasureHunt = 72,
      AgentSummon = 73,
      ChargedItem = 74,
      Fall = 75,
      GrowUp = 76,
      VibrationDetected = 77,
    };
    EventId event_id; /*3.2*/
    int data; /*0.0*/
  };
  struct packet_mob_effect {
    int64_t runtime_entity_id; /*0.0*/
    enum class EventId : uint8_t {
      Add = 1,
      Update = 2,
      Remove = 3,
    };
    EventId event_id; /*3.2*/
    int effect_id; /*0.0*/
    int amplifier; /*0.0*/
    bool particles; /*0.0*/
    int duration; /*0.0*/
  };
  struct packet_update_attributes {
    int64_t runtime_entity_id; /*0.0*/
    std::vector<pdef::proto::PlayerAttributes> attributes; /*1.0*/
    int64_t tick; /*0.0*/
  };
  struct packet_inventory_transaction {
    pdef::proto::Transaction transaction; /*4.0*/
  };
  struct packet_mob_equipment {
    int64_t runtime_entity_id; /*0.0*/
    pdef::proto::Item item; /*4.0*/
    uint8_t slot; /*0.0*/
    uint8_t selected_slot; /*0.0*/
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
  };
  struct packet_mob_armor_equipment {
    int64_t runtime_entity_id; /*0.0*/
    pdef::proto::Item helmet; /*4.0*/
    pdef::proto::Item chestplate; /*4.0*/
    pdef::proto::Item leggings; /*4.0*/
    pdef::proto::Item boots; /*4.0*/
  };
  struct packet_interact {
    enum class ActionId : uint8_t {
      LeaveVehicle = 3,
      MouseOverEntity = 4,
      NpcOpen = 5,
      OpenInventory = 6,
    };
    ActionId action_id; /*3.2*/
    int64_t target_entity_id; /*0.0*/
    std::optional<pdef::proto::vec3f> position; /*4.0*/
  };
  struct packet_block_pick_request {
    int x; /*0.0*/
    int y; /*0.0*/
    int z; /*0.0*/
    bool add_user_data; /*0.0*/
    uint8_t selected_slot; /*0.0*/
  };
  struct packet_entity_pick_request {
    uint64_t runtime_entity_id; /*0.0*/
    uint8_t selected_slot; /*0.0*/
    bool with_data; /*0.0*/
  };
  struct packet_player_action {
    int64_t runtime_entity_id; /*0.0*/
    enum class Action : int {
      StartBreak = 0,
      AbortBreak = 1,
      StopBreak = 2,
      GetUpdatedBlock = 3,
      DropItem = 4,
      StartSleeping = 5,
      StopSleeping = 6,
      Respawn = 7,
      Jump = 8,
      StartSprint = 9,
      StopSprint = 10,
      StartSneak = 11,
      StopSneak = 12,
      CreativePlayerDestroyBlock = 13,
      DimensionChangeAck = 14,
      StartGlide = 15,
      StopGlide = 16,
      BuildDenied = 17,
      CrackBreak = 18,
      ChangeSkin = 19,
      SetEnchatnmentSeed = 20,
      Swimming = 21,
      StopSwimming = 22,
      StartSpinAttack = 23,
      StopSpinAttack = 24,
      InteractBlock = 25,
      PredictBreak = 26,
      ContinueBreak = 27,
      StartItemUseOn = 28,
      StopItemUseOn = 29,
    };
    Action action; /*3.2*/
    pdef::proto::BlockCoordinates position; /*4.0*/
    pdef::proto::BlockCoordinates result_position; /*4.0*/
    int face; /*0.0*/
  };
  struct packet_hurt_armor {
    int cause; /*0.0*/
    int damage; /*0.0*/
    int64_t armor_slots; /*0.0*/
  };
  struct packet_set_entity_data {
    int64_t runtime_entity_id; /*0.0*/
    std::vector<pdef::proto::MetadataDictionary> metadata; /*1.0*/
    int64_t tick; /*0.0*/
  };
  struct packet_set_entity_motion {
    int64_t runtime_entity_id; /*0.0*/
    pdef::proto::vec3f velocity; /*4.0*/
  };
  struct packet_set_entity_link {
    pdef::proto::Link link; /*4.0*/
  };
  struct packet_set_health {
    int health; /*0.0*/
  };
  struct packet_set_spawn_position {
    enum class SpawnType : int {
      Player = 0,
      World = 1,
    };
    SpawnType spawn_type; /*3.2*/
    pdef::proto::BlockCoordinates player_position; /*4.0*/
    int dimension; /*0.0*/
    pdef::proto::BlockCoordinates world_position; /*4.0*/
  };
  struct packet_animate {
    enum class ActionId : int {
      None = 0,
      SwingArm = 1,
      Unknown = 2,
      WakeUp = 3,
      CriticalHit = 4,
      MagicCriticalHit = 5,
      RowRight = 128,
      RowLeft = 129,
    };
    ActionId action_id; /*3.2*/
    int64_t runtime_entity_id; /*0.0*/
    float boat_rowing_time; /*0.0*/
  };
  struct packet_respawn {
    pdef::proto::vec3f position; /*4.0*/
    uint8_t state; /*0.0*/
    int64_t runtime_entity_id; /*0.0*/
  };
  struct packet_container_open {
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    enum class WindowType : int8_t {
      Container = 0,
      Workbench = 1,
      Furnace = 2,
      Enchantment = 3,
      BrewingStand = 4,
      Anvil = 5,
      Dispenser = 6,
      Dropper = 7,
      Hopper = 8,
      Cauldron = 9,
      MinecartChest = 10,
      MinecartHopper = 11,
      Horse = 12,
      Beacon = 13,
      StructureEditor = 14,
      Trading = 15,
      CommandBlock = 16,
      Jukebox = 17,
      Armor = 18,
      Hand = 19,
      CompoundCreator = 20,
      ElementConstructor = 21,
      MaterialReducer = 22,
      LabTable = 23,
      Loom = 24,
      Lectern = 25,
      Grindstone = 26,
      BlastFurnace = 27,
      Smoker = 28,
      Stonecutter = 29,
      Cartography = 30,
      Hud = 31,
      JigsawEditor = 32,
      SmithingTable = 33,
      None = -9,
      Inventory = -1,
    };
    WindowType window_type; /*3.2*/
    pdef::proto::BlockCoordinates coordinates; /*4.0*/
    int64_t runtime_entity_id; /*0.0*/
  };
  struct packet_container_close {
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    bool server; /*0.0*/
  };
  struct packet_player_hotbar {
    int selected_slot; /*0.0*/
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    bool select_slot; /*0.0*/
  };
  struct packet_inventory_content {
    enum class WindowId : int {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    std::vector<pdef::proto::Item /*4.0*/> input; /*3.0*/
  };
  struct packet_inventory_slot {
    enum class WindowId : int {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    int slot; /*0.0*/
    pdef::proto::Item item; /*4.0*/
  };
  struct packet_container_set_data {
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    int property; /*0.0*/
    int value; /*0.0*/
  };
  struct packet_crafting_data {
    std::vector<pdef::proto::Recipes> recipes; /*1.0*/
    std::vector<pdef::proto::PotionTypeRecipes> potion_type_recipes; /*1.0*/
    std::vector<pdef::proto::PotionContainerChangeRecipes> potion_container_recipes; /*1.0*/
    std::vector<pdef::proto::MaterialReducer /*4.0*/> material_reducers; /*3.0*/
    bool clear_recipes; /*0.0*/
  };
  struct packet_crafting_event {
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    enum class RecipeType : int {
      Inventory = 0,
      Crafting = 1,
      Workbench = 2,
    };
    RecipeType recipe_type; /*3.2*/
    uint64_t recipe_id; /*0.0*/
    std::vector<pdef::proto::Item /*4.0*/> input; /*3.0*/
    std::vector<pdef::proto::Item /*4.0*/> result; /*3.0*/
  };
  struct packet_gui_data_pick_item {
    std::string item_name; /*6.0*/
    std::string item_effects; /*6.0*/
    int32_t hotbar_slot; /*0.0*/
  };
  struct packet_adventure_settings {
    struct flags_t { /*6.0*/
      bool world_immutable = false; /*6.0*/
      bool no_pvp = false; /*6.0*/
      bool auto_jump = false; /*6.0*/
      bool allow_flight = false; /*6.0*/
      bool no_clip = false; /*6.0*/
      bool world_builder = false; /*6.0*/
      bool flying = false; /*6.0*/
      bool muted = false; /*6.0*/
    } flags; /*6.0*/
    enum class CommandPermission : int {
      Normal = 0,
      Operator = 1,
      Host = 2,
      Automation = 3,
      Admin = 4,
    };
    CommandPermission command_permission; /*3.2*/
    struct action_permissions_t { /*6.0*/
      bool mine = false; /*6.0*/
      bool doors_and_switches = false; /*6.0*/
      bool open_containers = false; /*6.0*/
      bool attack_players = false; /*6.0*/
      bool attack_mobs = false; /*6.0*/
      bool operator_ = false; /*6.0*/
      bool teleport = false; /*6.0*/
      bool build = false; /*6.0*/
      bool default_ = false; /*6.0*/
    } action_permissions; /*6.0*/
    enum class PermissionLevel : int {
      Visitor = 0,
      Member = 1,
      Operator = 2,
      Custom = 3,
    };
    PermissionLevel permission_level; /*3.2*/
    int custom_stored_permissions; /*0.0*/
    int64_t user_id; /*0.0*/
  };
  struct packet_block_entity_data {
    pdef::proto::BlockCoordinates position; /*4.0*/
    int8_t nbt; /*0.0*/
  };
  struct packet_player_input {
    float motion_x; /*0.0*/
    float motion_z; /*0.0*/
    bool jumping; /*0.0*/
    bool sneaking; /*0.0*/
  };
  struct packet_level_chunk {
    int x; /*0.0*/
    int z; /*0.0*/
    int sub_chunk_count; /*0.0*/
    bool cache_enabled; /*0.0*/
    std::vector<uint8_t> payload; /*6.0*/
    uint16_t highest_subchunk_count; /*0.0*/
    struct Blobs {
      std::vector<uint64_t /*0.0*/> hashes; /*3.0*/
    };
    std::optional<Blobs> blobs; /*3.2*/
  };
  struct packet_set_commands_enabled {
    bool enabled; /*0.0*/
  };
  struct packet_set_difficulty {
    int difficulty; /*0.0*/
  };
  struct packet_change_dimension {
    int dimension; /*0.0*/
    pdef::proto::vec3f position; /*4.0*/
    bool respawn; /*0.0*/
  };
  struct packet_set_player_game_type {
    enum class Gamemode : int {
      Survival = 0,
      Creative = 1,
      Adventure = 2,
      SurvivalSpectator = 3,
      CreativeSpectator = 4,
      Fallback = 5,
      Spectator = 6,
    };
    Gamemode gamemode; /*3.2*/
  };
  struct packet_player_list {
    pdef::proto::PlayerRecords records; /*4.0*/
  };
  struct packet_simple_event {
    enum class EventType : uint16_t {
      UninitializedSubtype = 0,
      EnableCommands = 1,
      DisableCommands = 2,
      UnlockWorldTemplateSettings = 3,
    };
    EventType event_type; /*3.2*/
  };
  struct packet_event {
    int64_t runtime_id; /*0.0*/
    enum class EventType : int {
      AchievementAwarded = 0,
      EntityInteract = 1,
      PortalBuilt = 2,
      PortalUsed = 3,
      MobKilled = 4,
      CauldronUsed = 5,
      PlayerDeath = 6,
      BossKilled = 7,
      AgentCommand = 8,
      AgentCreated = 9,
      BannerPatternRemoved = 10,
      CommanedExecuted = 11,
      FishBucketed = 12,
      MobBorn = 13,
      PetDied = 14,
      CauldronBlockUsed = 15,
      ComposterBlockUsed = 16,
      BellBlockUsed = 17,
      ActorDefinition = 18,
      RaidUpdate = 19,
      PlayerMovementAnomaly = 20,
      PlayerMoementCorrected = 21,
      HoneyHarvested = 22,
      TargetBlockHit = 23,
      PiglinBarter = 24,
      WaxedOrUnwaxedCopper = 25,
      CodeBuilderRuntimeAction = 26,
      CodeBuilderScoreboard = 27,
      StriderRiddenInLavaInOverworld = 28,
      SneakCloseToSculkSensor = 29,
    };
    EventType event_type; /*3.2*/
    uint8_t use_player_id; /*0.0*/
    int8_t event_data; /*0.0*/
  };
  struct packet_spawn_experience_orb {
    pdef::proto::vec3f position; /*4.0*/
    int count; /*0.0*/
  };
  struct packet_clientbound_map_item_data {
    int64_t map_id; /*0.0*/
    struct update_flags_t { /*6.0*/
      bool void_ = false; /*6.0*/
      bool texture = false; /*6.0*/
      bool decoration = false; /*6.0*/
      bool initialisation = false; /*6.0*/
    } update_flags; /*6.0*/
    uint8_t dimension; /*0.0*/
    bool locked; /*0.0*/
    std::vector<int64_t /*0.0*/> included_in; /*3.0*/
    uint8_t scale; /*0.0*/
    struct Tracked {
      std::vector<pdef::proto::TrackedObject /*4.0*/> objects; /*3.0*/
      std::vector<pdef::proto::MapDecoration /*4.0*/> decorations; /*3.0*/
    };
    std::optional<Tracked> tracked; /*3.2*/
    struct Texture {
      int width; /*0.0*/
      int height; /*0.0*/
      int x_offset; /*0.0*/
      int y_offset; /*0.0*/
      std::vector<int /*0.0*/> pixels; /*3.0*/
    };
    std::optional<Texture> texture; /*3.2*/
  };
  struct packet_map_info_request {
    int64_t map_id; /*0.0*/
  };
  struct packet_request_chunk_radius {
    int chunk_radius; /*0.0*/
  };
  struct packet_chunk_radius_update {
    int chunk_radius; /*0.0*/
  };
  struct packet_item_frame_drop_item {
    pdef::proto::BlockCoordinates coordinates; /*4.0*/
  };
  struct packet_game_rules_changed {
    std::vector<pdef::proto::GameRule /*4.0*/> rules; /*3.0*/
  };
  struct packet_camera {
    int64_t camera_entity_unique_id; /*0.0*/
    int64_t target_player_unique_id; /*0.0*/
  };
  struct packet_boss_event {
    int64_t boss_entity_id; /*0.0*/
    enum class Type : int {
      ShowBar = 0,
      RegisterPlayer = 1,
      HideBar = 2,
      UnregisterPlayer = 3,
      SetBarProgress = 4,
      SetBarTitle = 5,
      UpdateProperties = 6,
      Texture = 7,
      Query = 8,
    };
    Type type; /*3.2*/
    int64_t player_id; /*0.0*/
    float progress; /*0.0*/
    std::string title; /*6.0*/
    int16_t screen_darkening; /*0.0*/
    int color; /*0.0*/
    int overlay; /*0.0*/
  };
  struct packet_show_credits {
    int64_t runtime_entity_id; /*0.0*/
    int status; /*0.0*/
  };
  struct packet_available_commands {
    int values_len; /*0.0*/
    enum class _EnumType { Byte, Short, Int }; _EnumType _enum_type; /*6.0*/
    std::vector<std::string /*6.0*/> enum_values; /*3.0*/
    std::vector<std::string /*6.0*/> suffixes; /*3.0*/
    struct Enums {
      std::string name; /*6.0*/
      uint8_t values_u8; /*0.0*/
      uint16_t values_lu16; /*0.0*/
      uint32_t values_lu32; /*0.0*/
    };
    std::vector<Enums /*3.2*/> enums; /*3.0*/
    struct CommandData {
      std::string name; /*6.0*/
      std::string description; /*6.0*/
      uint16_t flags; /*0.0*/
      uint8_t permission_level; /*0.0*/
      int32_t alias; /*0.0*/
      struct Overloads {
        struct Parameters {
          std::string parameter_name; /*6.0*/
          enum class ValueType : uint16_t {
            Int = 1,
            Float = 3,
            Value = 4,
            WildcardInt = 5,
            Operator = 6,
            CommandOperator = 7,
            Target = 8,
            WildcardTarget = 10,
            FilePath = 17,
            IntegerRange = 23,
            EquipmentSlots = 38,
            String = 39,
            BlockPosition = 47,
            Position = 48,
            Message = 51,
            RawText = 53,
            Json = 57,
            BlockStates = 67,
            Command = 70,
          };
          ValueType value_type; /*3.2*/
          enum class EnumType : uint16_t {
            Valid = 16,
            Enum = 48,
            Suffixed = 256,
            SoftEnum = 1040,
          };
          EnumType enum_type; /*3.2*/
          bool optional; /*0.0*/
          struct { /*6.0*/
            int unused = 0; /*6.0*/
            int collapse_enum = 0; /*6.0*/
            int has_semantic_constraint = 0; /*6.0*/
            int as_chained_command = 0; /*6.0*/
            int unknown2 = 0; /*6.0*/
          } options; /*6.0*/
        };
        std::vector<Parameters /*3.2*/> parameters; /*3.0*/
      };
      std::vector<Overloads /*3.2*/> overloads; /*3.0*/
    };
    std::vector<CommandData /*3.2*/> command_data; /*3.0*/
    struct DynamicEnums {
      std::string name; /*6.0*/
      std::vector<std::string /*6.0*/> values; /*3.0*/
    };
    std::vector<DynamicEnums /*3.2*/> dynamic_enums; /*3.0*/
    struct EnumConstraints {
      int32_t value_index; /*0.0*/
      int32_t enum_index; /*0.0*/
      struct Constraints {
        enum class Constraint : uint8_t {
          CheatsEnabled = 0,
          OperatorPermissions = 1,
          HostPermissions = 2,
        };
        Constraint constraint; /*3.2*/
      };
      std::vector<Constraints /*3.2*/> constraints; /*3.0*/
    };
    std::vector<EnumConstraints /*3.2*/> enum_constraints; /*3.0*/
  };
  struct packet_command_request {
    std::string command; /*6.0*/
    pdef::proto::CommandOrigin origin; /*4.0*/
    bool internal; /*0.0*/
  };
  struct packet_command_block_update {
    bool is_block; /*0.0*/
    std::string command; /*6.0*/
    std::string last_output; /*6.0*/
    std::string name; /*6.0*/
    bool should_track_output; /*0.0*/
    int32_t tick_delay; /*0.0*/
    bool execute_on_first_tick; /*0.0*/
    std::optional<pdef::proto::BlockCoordinates> position; /*4.0*/
    enum class Mode : int {
      Impulse = 0,
      Repeat = 1,
      Chain = 2,
    };
    Mode mode; /*3.2*/
    bool needs_redstone; /*0.0*/
    bool conditional; /*0.0*/
    int64_t minecart_entity_runtime_id; /*0.0*/
  };
  struct packet_command_output {
    pdef::proto::CommandOrigin origin; /*4.0*/
    enum class OutputType : int8_t {
      Last = 1,
      Silent = 2,
      All = 3,
      DataSet = 4,
    };
    OutputType output_type; /*3.2*/
    int success_count; /*0.0*/
    struct Output {
      bool success; /*0.0*/
      std::string message_id; /*6.0*/
      std::vector<std::string /*6.0*/> parameters; /*3.0*/
    };
    std::vector<Output /*3.2*/> output; /*3.0*/
    std::string data_set; /*6.0*/
  };
  struct packet_update_trade {
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    enum class WindowType : int8_t {
      Container = 0,
      Workbench = 1,
      Furnace = 2,
      Enchantment = 3,
      BrewingStand = 4,
      Anvil = 5,
      Dispenser = 6,
      Dropper = 7,
      Hopper = 8,
      Cauldron = 9,
      MinecartChest = 10,
      MinecartHopper = 11,
      Horse = 12,
      Beacon = 13,
      StructureEditor = 14,
      Trading = 15,
      CommandBlock = 16,
      Jukebox = 17,
      Armor = 18,
      Hand = 19,
      CompoundCreator = 20,
      ElementConstructor = 21,
      MaterialReducer = 22,
      LabTable = 23,
      Loom = 24,
      Lectern = 25,
      Grindstone = 26,
      BlastFurnace = 27,
      Smoker = 28,
      Stonecutter = 29,
      Cartography = 30,
      Hud = 31,
      JigsawEditor = 32,
      SmithingTable = 33,
      None = -9,
      Inventory = -1,
    };
    WindowType window_type; /*3.2*/
    int size; /*0.0*/
    int trade_tier; /*0.0*/
    int64_t villager_unique_id; /*0.0*/
    int64_t entity_unique_id; /*0.0*/
    std::string display_name; /*6.0*/
    bool new_trading_ui; /*0.0*/
    bool economic_trades; /*0.0*/
    int8_t offers; /*0.0*/
  };
  struct packet_update_equipment {
    enum class WindowId : int8_t {
      Inventory = 0,
      First = 1,
      Last = 100,
      Offhand = 119,
      Armor = 120,
      Creative = 121,
      Hotbar = 122,
      FixedInventory = 123,
      Ui = 124,
      DropContents = -100,
      Beacon = -24,
      TradingOutput = -23,
      TradingUseInputs = -22,
      TradingInput2 = -21,
      TradingInput1 = -20,
      EnchantOutput = -17,
      EnchantMaterial = -16,
      EnchantInput = -15,
      AnvilOutput = -13,
      AnvilResult = -12,
      AnvilMaterial = -11,
      ContainerInput = -10,
      CraftingUseIngredient = -5,
      CraftingResult = -4,
      CraftingRemoveIngredient = -3,
      CraftingAddIngredient = -2,
      None = -1,
    };
    WindowId window_id; /*3.2*/
    enum class WindowType : int8_t {
      Container = 0,
      Workbench = 1,
      Furnace = 2,
      Enchantment = 3,
      BrewingStand = 4,
      Anvil = 5,
      Dispenser = 6,
      Dropper = 7,
      Hopper = 8,
      Cauldron = 9,
      MinecartChest = 10,
      MinecartHopper = 11,
      Horse = 12,
      Beacon = 13,
      StructureEditor = 14,
      Trading = 15,
      CommandBlock = 16,
      Jukebox = 17,
      Armor = 18,
      Hand = 19,
      CompoundCreator = 20,
      ElementConstructor = 21,
      MaterialReducer = 22,
      LabTable = 23,
      Loom = 24,
      Lectern = 25,
      Grindstone = 26,
      BlastFurnace = 27,
      Smoker = 28,
      Stonecutter = 29,
      Cartography = 30,
      Hud = 31,
      JigsawEditor = 32,
      SmithingTable = 33,
      None = -9,
      Inventory = -1,
    };
    WindowType window_type; /*3.2*/
    uint8_t size; /*0.0*/
    int64_t entity_id; /*0.0*/
    int8_t inventory; /*0.0*/
  };
  struct packet_resource_pack_data_info {
    std::string pack_id; /*6.0*/
    uint32_t max_chunk_size; /*0.0*/
    uint32_t chunk_count; /*0.0*/
    uint64_t size; /*0.0*/
    std::vector<uint8_t> hash; /*6.0*/
    bool is_premium; /*0.0*/
    enum class PackType : uint8_t {
      Addon = 1,
      Cached = 2,
      CopyProtected = 3,
      Behavior = 4,
      PersonaPiece = 5,
      Resources = 6,
      Skins = 7,
      WorldTemplate = 8,
    };
    PackType pack_type; /*3.2*/
  };
  struct packet_resource_pack_chunk_data {
    std::string pack_id; /*6.0*/
    uint32_t chunk_index; /*0.0*/
    uint64_t progress; /*0.0*/
    std::vector<uint8_t> payload; /*6.0*/
  };
  struct packet_resource_pack_chunk_request {
    std::string pack_id; /*6.0*/
    uint32_t chunk_index; /*0.0*/
  };
  struct packet_transfer {
    std::string server_address; /*6.0*/
    uint16_t port; /*0.0*/
  };
  struct packet_play_sound {
    std::string name; /*6.0*/
    pdef::proto::BlockCoordinates coordinates; /*4.0*/
    float volume; /*0.0*/
    float pitch; /*0.0*/
  };
  struct packet_stop_sound {
    std::string name; /*6.0*/
    bool stop_all; /*0.0*/
  };
  struct packet_set_title {
    enum class Type : int {
      Clear = 0,
      Reset = 1,
      SetTitle = 2,
      SetSubtitle = 3,
      ActionBarMessage = 4,
      SetDurations = 5,
      SetTitleJson = 6,
      SetSubtitleJson = 7,
      ActionBarMessageJson = 8,
    };
    Type type; /*3.2*/
    std::string text; /*6.0*/
    int fade_in_time; /*0.0*/
    int stay_time; /*0.0*/
    int fade_out_time; /*0.0*/
    std::string xuid; /*6.0*/
    std::string platform_online_id; /*6.0*/
  };
  struct packet_add_behavior_tree {
    std::string behaviortree; /*6.0*/
  };
  struct packet_structure_block_update {
    pdef::proto::BlockCoordinates position; /*4.0*/
    std::string structure_name; /*6.0*/
    std::string data_field; /*6.0*/
    bool include_players; /*0.0*/
    bool show_bounding_box; /*0.0*/
    int structure_block_type; /*0.0*/
    pdef::proto::StructureBlockSettings settings; /*4.0*/
    int redstone_save_mode; /*0.0*/
    bool should_trigger; /*0.0*/
  };
  struct packet_show_store_offer {
    std::string offer_id; /*6.0*/
    bool show_all; /*0.0*/
  };
  struct packet_purchase_receipt {
    std::vector<std::string /*6.0*/> receipts; /*3.0*/
  };
  struct packet_player_skin {
    uint64_t uuid; /*0.0*/
    pdef::proto::Skin skin; /*4.0*/
    std::string skin_name; /*6.0*/
    std::string old_skin_name; /*6.0*/
    bool is_verified; /*0.0*/
  };
  struct packet_sub_client_login {
    int8_t tokens; /*0.0*/
  };
  struct packet_initiate_web_socket_connection {
    std::string server; /*6.0*/
  };
  struct packet_set_last_hurt_by {
    int entity_type; /*0.0*/
  };
  struct packet_book_edit {
    enum class Type : uint8_t {
      ReplacePage = 0,
      AddPage = 1,
      DeletePage = 2,
      SwapPages = 3,
      Sign = 4,
    };
    Type type; /*3.2*/
    uint8_t slot; /*0.0*/
    uint8_t page_number; /*0.0*/
    std::string text; /*6.0*/
    std::string photo_name; /*6.0*/
    uint8_t page1; /*0.0*/
    uint8_t page2; /*0.0*/
    std::string title; /*6.0*/
    std::string author; /*6.0*/
    std::string xuid; /*6.0*/
  };
  struct packet_npc_request {
    int64_t runtime_entity_id; /*0.0*/
    enum class RequestType : uint8_t {
      SetActions = 0,
      ExecuteAction = 1,
      ExecuteClosingCommands = 2,
      SetName = 3,
      SetSkin = 4,
      SetInteractionText = 5,
      ExecuteOpeningCommands = 6,
    };
    RequestType request_type; /*3.2*/
    std::string command; /*6.0*/
    enum class ActionType : uint8_t {
      SetActions = 0,
      ExecuteAction = 1,
      ExecuteClosingCommands = 2,
      SetName = 3,
      SetSkin = 4,
      SetInteractText = 5,
      ExecuteOpeningCommands = 6,
    };
    ActionType action_type; /*3.2*/
    std::string scene_name; /*6.0*/
  };
  struct packet_photo_transfer {
    std::string image_name; /*6.0*/
    std::string image_data; /*6.0*/
    std::string book_id; /*6.0*/
    uint8_t photo_type; /*0.0*/
    uint8_t source_type; /*0.0*/
    int64_t owner_entity_unique_id; /*0.0*/
    std::string new_photo_name; /*6.0*/
  };
  struct packet_modal_form_request {
    int form_id; /*0.0*/
    std::string data; /*6.0*/
  };
  struct packet_modal_form_response {
    int form_id; /*0.0*/
    std::string data; /*6.0*/
  };
  struct packet_server_settings_request {
  };
  struct packet_server_settings_response {
    int form_id; /*0.0*/
    std::string data; /*6.0*/
  };
  struct packet_show_profile {
    std::string xuid; /*6.0*/
  };
  struct packet_set_default_game_type {
    enum class Gamemode : int {
      Survival = 0,
      Creative = 1,
      Adventure = 2,
      SurvivalSpectator = 3,
      CreativeSpectator = 4,
      Fallback = 5,
      Spectator = 6,
    };
    Gamemode gamemode; /*3.2*/
  };
  struct packet_remove_objective {
    std::string objective_name; /*6.0*/
  };
  struct packet_set_display_objective {
    std::string display_slot; /*6.0*/
    std::string objective_name; /*6.0*/
    std::string display_name; /*6.0*/
    std::string criteria_name; /*6.0*/
    int sort_order; /*0.0*/
  };
  struct packet_set_score {
    enum class Action : uint8_t {
      Change = 0,
      Remove = 1,
    };
    Action action; /*3.2*/
    struct Entries {
      int64_t scoreboard_id; /*0.0*/
      std::string objective_name; /*6.0*/
      int32_t score; /*0.0*/
      enum class EntryType : int8_t {
        Player = 1,
        Entity = 2,
        FakePlayer = 3,
      };
      EntryType entry_type; /*3.2*/
      int64_t entity_unique_id; /*0.0*/
      std::string custom_name; /*6.0*/
    };
    std::vector<Entries /*3.2*/> entries; /*3.0*/
  };
  struct packet_lab_table {
    enum class ActionType : uint8_t {
      Combine = 0,
      React = 1,
      Reset = 2,
    };
    ActionType action_type; /*3.2*/
    pdef::proto::vec3i position; /*4.0*/
    uint8_t reaction_type; /*0.0*/
  };
  struct packet_update_block_synced {
    pdef::proto::BlockCoordinates position; /*4.0*/
    int block_runtime_id; /*0.0*/
    struct flags_t { /*6.0*/
      bool neighbors = false; /*6.0*/
      bool network = false; /*6.0*/
      bool no_graphic = false; /*6.0*/
      bool unused = false; /*6.0*/
      bool priority = false; /*6.0*/
    } flags; /*6.0*/
    int layer; /*0.0*/
    int64_t entity_unique_id; /*0.0*/
    enum class TransitionType : int {
      Entity = 0,
      Create = 1,
      Destroy = 2,
    };
    TransitionType transition_type; /*3.2*/
  };
  struct packet_move_entity_delta {
    int64_t runtime_entity_id; /*0.0*/
    struct flags_t { /*6.0*/
      bool has_x = false; /*6.0*/
      bool has_y = false; /*6.0*/
      bool has_z = false; /*6.0*/
      bool has_rot_x = false; /*6.0*/
      bool has_rot_y = false; /*6.0*/
      bool has_rot_z = false; /*6.0*/
      bool on_ground = false; /*6.0*/
      bool teleport = false; /*6.0*/
      bool force_move = false; /*6.0*/
    } flags; /*6.0*/
    float x; /*0.0*/
    float y; /*0.0*/
    float z; /*0.0*/
    uint8_t rot_x; /*0.0*/
    uint8_t rot_y; /*0.0*/
    uint8_t rot_z; /*0.0*/
  };
  struct packet_set_scoreboard_identity {
    enum class Action : int8_t {
      RegisterIdentity = 0,
      ClearIdentity = 1,
    };
    Action action; /*3.2*/
    struct Entries {
      int64_t scoreboard_id; /*0.0*/
      int64_t entity_unique_id; /*0.0*/
    };
    std::vector<Entries /*3.2*/> entries; /*3.0*/
  };
  struct packet_set_local_player_as_initialized {
    int64_t runtime_entity_id; /*0.0*/
  };
  struct packet_update_soft_enum {
    std::string enum_type; /*6.0*/
    std::vector<std::string /*6.0*/> options; /*3.0*/
    enum class ActionType : uint8_t {
      Add = 0,
      Remove = 1,
      Update = 2,
    };
    ActionType action_type; /*3.2*/
  };
  struct packet_network_stack_latency {
    uint64_t timestamp; /*0.0*/
    uint8_t needs_response; /*0.0*/
  };
  struct packet_script_custom_event {
    std::string event_name; /*6.0*/
    std::string event_data; /*6.0*/
  };
  struct packet_spawn_particle_effect {
    uint8_t dimension; /*0.0*/
    int64_t entity_id; /*0.0*/
    pdef::proto::vec3f position; /*4.0*/
    std::string particle_name; /*6.0*/
    std::vector<uint8_t> molang_variables; /*6.0*/
  };
  struct packet_available_entity_identifiers {
    int8_t nbt; /*0.0*/
  };
  struct packet_level_sound_event_v2 {
    uint8_t sound_id; /*0.0*/
    pdef::proto::vec3f position; /*4.0*/
    int block_id; /*0.0*/
    std::string entity_type; /*6.0*/
    bool is_baby_mob; /*0.0*/
    bool is_global; /*0.0*/
  };
  struct packet_network_chunk_publisher_update {
    pdef::proto::BlockCoordinates coordinates; /*4.0*/
    int radius; /*0.0*/
  };
  struct packet_biome_definition_list {
    int8_t nbt; /*0.0*/
  };
  struct packet_level_sound_event {
    enum class SoundId : int {
      ItemUseOn = 0,
      Hit = 1,
      Step = 2,
      Fly = 3,
      Jump = 4,
      Break = 5,
      Place = 6,
      HeavyStep = 7,
      Gallop = 8,
      Fall = 9,
      Ambient = 10,
      AmbientBaby = 11,
      AmbientInWater = 12,
      Breathe = 13,
      Death = 14,
      DeathInWater = 15,
      DeathToZombie = 16,
      Hurt = 17,
      HurtInWater = 18,
      Mad = 19,
      Boost = 20,
      Bow = 21,
      SquishBig = 22,
      SquishSmall = 23,
      FallBig = 24,
      FallSmall = 25,
      Splash = 26,
      Fizz = 27,
      Flap = 28,
      Swim = 29,
      Drink = 30,
      Eat = 31,
      Takeoff = 32,
      Shake = 33,
      Plop = 34,
      Land = 35,
      Saddle = 36,
      Armor = 37,
      MobArmorStandPlace = 38,
      AddChest = 39,
      Throw = 40,
      Attack = 41,
      AttackNoDamage = 42,
      AttackStrong = 43,
      Warn = 44,
      Shear = 45,
      Milk = 46,
      Thunder = 47,
      Explode = 48,
      Fire = 49,
      Ignite = 50,
      Fuse = 51,
      Stare = 52,
      Spawn = 53,
      Shoot = 54,
      BreakBlock = 55,
      Launch = 56,
      Blast = 57,
      LargeBlast = 58,
      Twinkle = 59,
      Remedy = 60,
      Infect = 61,
      LevelUp = 62,
      BowHit = 63,
      BulletHit = 64,
      ExtinguishFire = 65,
      ItemFizz = 66,
      ChestOpen = 67,
      ChestClosed = 68,
      ShulkerBoxOpen = 69,
      ShulkerBoxClosed = 70,
      EnderChestOpen = 71,
      EnderChestClosed = 72,
      PowerOn = 73,
      PowerOff = 74,
      Attach = 75,
      Detach = 76,
      Deny = 77,
      Tripod = 78,
      Pop = 79,
      DropSlot = 80,
      Note = 81,
      Thorns = 82,
      PistonIn = 83,
      PistonOut = 84,
      Portal = 85,
      Water = 86,
      LavaPop = 87,
      Lava = 88,
      Burp = 89,
      BucketFillWater = 90,
      BucketFillLava = 91,
      BucketEmptyWater = 92,
      BucketEmptyLava = 93,
      ArmorEquipChain = 94,
      ArmorEquipDiamond = 95,
      ArmorEquipGeneric = 96,
      ArmorEquipGold = 97,
      ArmorEquipIron = 98,
      ArmorEquipLeather = 99,
      ArmorEquipElytra = 100,
      Record13 = 101,
      RecordCat = 102,
      RecordBlocks = 103,
      RecordChirp = 104,
      RecordFar = 105,
      RecordMall = 106,
      RecordMellohi = 107,
      RecordStal = 108,
      RecordStrad = 109,
      RecordWard = 110,
      Record11 = 111,
      RecordWait = 112,
      StopRecord = 113,
      Flop = 114,
      GuardianCurse = 115,
      MobWarning = 116,
      MobWarningBaby = 117,
      Teleport = 118,
      ShulkerOpen = 119,
      ShulkerClose = 120,
      Haggle = 121,
      HaggleYes = 122,
      HaggleNo = 123,
      HaggleIdle = 124,
      ChorusGrow = 125,
      ChorusDeath = 126,
      Glass = 127,
      PotionBrewed = 128,
      CastSpell = 129,
      PrepareAttackSpell = 130,
      PrepareSummon = 131,
      PrepareWololo = 132,
      Fang = 133,
      Charge = 134,
      CameraTakePicture = 135,
      LeashKnotPlace = 136,
      LeashKnotBreak = 137,
      AmbientGrowl = 138,
      AmbientWhine = 139,
      AmbientPant = 140,
      AmbientPurr = 141,
      AmbientPurreow = 142,
      DeathMinVolume = 143,
      DeathMidVolume = 144,
      ImitateBlaze = 145,
      ImitateCaveSpider = 146,
      ImitateCreeper = 147,
      ImitateElderGuardian = 148,
      ImitateEnderDragon = 149,
      ImitateEnderman = 150,
      ImitateEndermite = 151,
      ImitateEvocationIllager = 152,
      ImitateGhast = 153,
      ImitateHusk = 154,
      ImitateIllusionIllager = 155,
      ImitateMagmaCube = 156,
      ImitatePolarBear = 157,
      ImitateShulker = 158,
      ImitateSilverfish = 159,
      ImitateSkeleton = 160,
      ImitateSlime = 161,
      ImitateSpider = 162,
      ImitateStray = 163,
      ImitateVex = 164,
      ImitateVindicationIllager = 165,
      ImitateWitch = 166,
      ImitateWither = 167,
      ImitateWitherSkeleton = 168,
      ImitateWolf = 169,
      ImitateZombie = 170,
      ImitateZombiePigman = 171,
      ImitateZombieVillager = 172,
      EnderEyePlaced = 173,
      EndPortalCreated = 174,
      AnvilUse = 175,
      BottleDragonBreath = 176,
      PortalTravel = 177,
      TridentHit = 178,
      TridentReturn = 179,
      TridentRiptide1 = 180,
      TridentRiptide2 = 181,
      TridentRiptide3 = 182,
      TridentThrow = 183,
      TridentThunder = 184,
      TridentHitGround = 185,
      Default = 186,
      FletchingTableUse = 187,
      ElemConstructOpen = 188,
      IceBombHit = 189,
      BalloonPop = 190,
      LtReactionIceBomb = 191,
      LtReactionBleach = 192,
      LtReactionElephantToothpaste = 193,
      LtReactionElephantToothpaste2 = 194,
      LtReactionGlowStick = 195,
      LtReactionGlowStick2 = 196,
      LtReactionLuminol = 197,
      LtReactionSalt = 198,
      LtReactionFertilizer = 199,
      LtReactionFireball = 200,
      LtReactionMagnesiumSalt = 201,
      LtReactionMiscFire = 202,
      LtReactionFire = 203,
      LtReactionMiscExplosion = 204,
      LtReactionMiscMystical = 205,
      LtReactionMiscMystical2 = 206,
      LtReactionProduct = 207,
      SparklerUse = 208,
      GlowStickUse = 209,
      SparklerActive = 210,
      ConvertToDrowned = 211,
      BucketFillFish = 212,
      BucketEmptyFish = 213,
      BubbleColumnUpwards = 214,
      BubbleColumnDownwards = 215,
      BubblePop = 216,
      BubbleUpInside = 217,
      BubbleDownInside = 218,
      HurtBaby = 219,
      DeathBaby = 220,
      StepBaby = 221,
      SpawnBaby = 222,
      Born = 223,
      TurtleEggBreak = 224,
      TurtleEggCrack = 225,
      TurtleEggHatched = 226,
      LayEgg = 227,
      TurtleEggAttacked = 228,
      BeaconActivate = 229,
      BeaconAmbient = 230,
      BeaconDeactivate = 231,
      BeaconPower = 232,
      ConduitActivate = 233,
      ConduitAmbient = 234,
      ConduitAttack = 235,
      ConduitDeactivate = 236,
      ConduitShort = 237,
      Swoop = 238,
      BambooSaplingPlace = 239,
      PreSneeze = 240,
      Sneeze = 241,
      AmbientTame = 242,
      Scared = 243,
      ScaffoldingClimb = 244,
      CrossbowLoadingStart = 245,
      CrossbowLoadingMiddle = 246,
      CrossbowLoadingEnd = 247,
      CrossbowShoot = 248,
      CrossbowQuickChargeStart = 249,
      CrossbowQuickChargeMiddle = 250,
      CrossbowQuickChargeEnd = 251,
      AmbientAggressive = 252,
      AmbientWorried = 253,
      CantBreed = 254,
      ShieldBlock = 255,
      LecternBookPlace = 256,
      GrindstoneUse = 257,
      Bell = 258,
      CampfireCrackle = 259,
      Roar = 260,
      Stun = 261,
      SweetBerryBushHurt = 262,
      SweetBerryBushPick = 263,
      CartographyTableUse = 264,
      StonecutterUse = 265,
      ComposterEmpty = 266,
      ComposterFill = 267,
      ComposterFillLayer = 268,
      ComposterReady = 269,
      BarrelOpen = 270,
      BarrelClose = 271,
      RaidHorn = 272,
      LoomUse = 273,
      AmbientInRaid = 274,
      UicartographyTableUse = 275,
      UistonecutterUse = 276,
      UiloomUse = 277,
      SmokerUse = 278,
      BlastFurnaceUse = 279,
      SmithingTableUse = 280,
      Screech = 281,
      Sleep = 282,
      FurnaceUse = 283,
      MooshroomConvert = 284,
      MilkSuspiciously = 285,
      Celebrate = 286,
      JumpPrevent = 287,
      AmbientPollinate = 288,
      BeehiveDrip = 289,
      BeehiveEnter = 290,
      BeehiveExit = 291,
      BeehiveWork = 292,
      BeehiveShear = 293,
      HoneybottleDrink = 294,
      AmbientCave = 295,
      Retreat = 296,
      ConvertToZombified = 297,
      Admire = 298,
      StepLava = 299,
      Tempt = 300,
      Panic = 301,
      Angry = 302,
      AmbientMoodWarpedForest = 303,
      AmbientMoodSoulsandValley = 304,
      AmbientMoodNetherWastes = 305,
      AmbientMoodBasaltDeltas = 306,
      AmbientMoodCrimsonForest = 307,
      RespawnAnchorCharge = 308,
      RespawnAnchorDeplete = 309,
      RespawnAnchorSetSpawn = 310,
      RespawnAnchorAmbient = 311,
      SoulEscapeQuiet = 312,
      SoulEscapeLoud = 313,
      RecordPigstep = 314,
      LinkCompassToLodestone = 315,
      UseSmithingTable = 316,
      EquipNetherite = 317,
      AmbientLoopWarpedForest = 318,
      AmbientLoopSoulsandValley = 319,
      AmbientLoopNetherWastes = 320,
      AmbientLoopBasaltDeltas = 321,
      AmbientLoopCrimsonForest = 322,
      AmbientAdditionWarpedForest = 323,
      AmbientAdditionSoulsandValley = 324,
      AmbientAdditionNetherWastes = 325,
      AmbientAdditionBasaltDeltas = 326,
      AmbientAdditionCrimsonForest = 327,
      SculkSensorPowerOn = 328,
      SculkSensorPowerOff = 329,
      BucketFillPowderSnow = 330,
      BucketEmptyPowderSnow = 331,
      PointedDripstoneCauldronDripWater = 332,
      PointedDripstoneCauldronDripLava = 333,
      PointedDripstoneDripWater = 334,
      PointedDripstoneDripLava = 335,
      CaveVinesPickBerries = 336,
      BigDripleafTiltDown = 337,
      BigDripleafTiltUp = 338,
      CopperWaxOn = 339,
      CopperWaxOff = 340,
      Scrape = 341,
      PlayerHurtDrown = 342,
      PlayerHurtOnFire = 343,
      PlayerHurtFreeze = 344,
      UseSpyglass = 345,
      StopUsingSpyglass = 346,
      AmethystBlockChime = 347,
      AmbientScreamer = 348,
      HurtScreamer = 349,
      DeathScreamer = 350,
      MilkScreamer = 351,
      JumpToBlock = 352,
      PreRam = 353,
      PreRamScreamer = 354,
      RamImpact = 355,
      RamImpactScreamer = 356,
      SquidInkSquirt = 357,
      GlowSquidInkSquirt = 358,
      ConvertToStray = 359,
      CakeAddCandle = 360,
      ExtinguishCandle = 361,
      AmbientCandle = 362,
      BlockClick = 363,
      BlockClickFail = 364,
      SculkCatalystBloom = 365,
      SculkShriekerShriek = 366,
      WardenNearbyClose = 367,
      WardenNearbyCloser = 368,
      WardenNearbyClosest = 369,
      WardenSlightlyAngry = 370,
      RecordOtherside = 371,
      Tongue = 372,
      CrackIronGolem = 373,
      RepairIronGolem = 374,
      Listening = 375,
      Heartbeat = 376,
      HornBreak = 377,
      SculkPlace = 378,
      SculkSpread = 379,
      SculkCharge = 380,
      SculkSensorPlace = 381,
      SculkShriekerPlace = 382,
      GoatCall0 = 383,
      GoatCall1 = 384,
      GoatCall2 = 385,
      GoatCall3 = 386,
      GoatCall4 = 387,
      GoatCall5 = 388,
      GoatCall6 = 389,
      GoatCall7 = 390,
      GoatCall8 = 391,
      GoatCall9 = 392,
      GoatHarmony0 = 393,
      GoatHarmony1 = 394,
      GoatHarmony2 = 395,
      GoatHarmony3 = 396,
      GoatHarmony4 = 397,
      GoatHarmony5 = 398,
      GoatHarmony6 = 399,
      GoatHarmony7 = 400,
      GoatHarmony8 = 401,
      GoatHarmony9 = 402,
      GoatMelody0 = 403,
      GoatMelody1 = 404,
      GoatMelody2 = 405,
      GoatMelody3 = 406,
      GoatMelody4 = 407,
      GoatMelody5 = 408,
      GoatMelody6 = 409,
      GoatMelody7 = 410,
      GoatMelody8 = 411,
      GoatMelody9 = 412,
      GoatBass0 = 413,
      GoatBass1 = 414,
      GoatBass2 = 415,
      GoatBass3 = 416,
      GoatBass4 = 417,
      GoatBass5 = 418,
      GoatBass6 = 419,
      GoatBass7 = 420,
      GoatBass8 = 421,
      GoatBass9 = 422,
      __ = 423,
      __0 = 424,
      __1 = 425,
      ImitateWarden = 426,
      ListeningAngry = 427,
      ItemGiven = 428,
      ItemTaken = 429,
      Disappeared = 430,
      Reappeared = 431,
      __2 = 432,
      FrogspawnHatched = 433,
      LaySpawn = 434,
      FrogspawnBreak = 435,
      SonicBoom = 436,
      SonicCharge = 437,
      SoundeventItemThrown = 438,
      Record5 = 439,
      ConvertToFrog = 440,
      Undefined = 441,
    };
    SoundId sound_id; /*3.2*/
    pdef::proto::vec3f position; /*4.0*/
    int extra_data; /*0.0*/
    std::string entity_type; /*6.0*/
    bool is_baby_mob; /*0.0*/
    bool is_global; /*0.0*/
  };
  struct packet_level_event_generic {
    int event_id; /*0.0*/
    int8_t nbt; /*0.0*/
  };
  struct packet_lectern_update {
    uint8_t page; /*0.0*/
    uint8_t page_count; /*0.0*/
    pdef::proto::vec3i position; /*4.0*/
    bool drop_book; /*0.0*/
  };
  struct packet_video_stream_connect {
    std::string server_uri; /*6.0*/
    float frame_send_frequency; /*0.0*/
    enum class Action : uint8_t {
      None = 1,
      Close = 2,
    };
    Action action; /*3.2*/
    int32_t resolution_x; /*0.0*/
    int32_t resolution_y; /*0.0*/
  };
  struct packet_add_ecs_entity {
    int64_t network_id; /*0.0*/
  };
  struct packet_remove_ecs_entity {
    int64_t network_id; /*0.0*/
  };
  struct packet_client_cache_status {
    bool enabled; /*0.0*/
  };
  struct packet_on_screen_texture_animation {
    uint32_t animation_type; /*0.0*/
  };
  struct packet_map_create_locked_copy {
    int64_t original_map_id; /*0.0*/
    int64_t new_map_id; /*0.0*/
  };
  struct packet_structure_template_data_export_request {
    std::string name; /*6.0*/
    pdef::proto::BlockCoordinates position; /*4.0*/
    pdef::proto::StructureBlockSettings settings; /*4.0*/
    enum class RequestType : uint8_t {
      ExportFromSave = 1,
      ExportFromLoad = 2,
      QuerySavedStructure = 3,
    };
    RequestType request_type; /*3.2*/
  };
  struct packet_structure_template_data_export_response {
    std::string name; /*6.0*/
    bool success; /*0.0*/
    enum class ResponseType : uint8_t {
      Export = 1,
      Query = 2,
    };
    ResponseType response_type; /*3.2*/
    int8_t nbt; /*0.0*/
  };
  struct packet_update_block_properties {
    int8_t nbt; /*0.0*/
  };
  struct packet_client_cache_blob_status {
    int misses; /*0.0*/
    int haves; /*0.0*/
    std::vector<uint64_t /*0.0*/> missing; /*3.0*/
    std::vector<uint64_t /*0.0*/> have; /*3.0*/
  };
  struct packet_client_cache_miss_response {
    std::vector<pdef::proto::Blob /*4.0*/> blobs; /*3.0*/
  };
  struct packet_education_settings {
    std::string CodeBuilderDefaultURI; /*6.0*/
    std::string CodeBuilderTitle; /*6.0*/
    bool CanResizeCodeBuilder; /*0.0*/
    bool disable_legacy_title_bar; /*0.0*/
    std::string post_process_filter; /*6.0*/
    std::string screenshot_border_path; /*6.0*/
    bool has_agent_capabilities; /*0.0*/
    bool HasOverrideURI; /*0.0*/
    bool HasQuiz; /*0.0*/
    bool has_external_link_settings; /*0.0*/
    struct AgentCapabilities {
      bool has; /*0.0*/
      bool can_modify_blocks; /*0.0*/
    };
    std::optional<AgentCapabilities> agent_capabilities; /*3.2*/
    std::string OverrideURI; /*6.0*/
    struct ExternalLinkSettings {
      bool has; /*0.0*/
      std::string url; /*6.0*/
      std::string display_name; /*6.0*/
    };
    std::optional<ExternalLinkSettings> external_link_settings; /*3.2*/
  };
  struct packet_emote {
    int64_t entity_id; /*0.0*/
    std::string emote_id; /*6.0*/
    uint8_t flags; /*0.0*/
  };
  struct packet_multiplayer_settings {
    enum class ActionType : int {
      EnableMultiplayer = 0,
      DisableMultiplayer = 1,
      RefreshJoinCode = 2,
    };
    ActionType action_type; /*3.2*/
  };
  struct packet_settings_command {
    std::string command_line; /*6.0*/
    bool suppress_output; /*0.0*/
  };
  struct packet_anvil_damage {
    uint8_t damage; /*0.0*/
    pdef::proto::BlockCoordinates position; /*4.0*/
  };
  struct packet_completed_using_item {
    int16_t used_item_id; /*0.0*/
    enum class UseMethod : int32_t {
      EquipArmor = 0,
      Eat = 1,
      Attack = 2,
      Consume = 3,
      Throw = 4,
      Shoot = 5,
      Place = 6,
      FillBottle = 7,
      FillBucket = 8,
      PourBucket = 9,
      UseTool = 10,
      Interact = 11,
      Retrieved = 12,
      Dyed = 13,
      Traded = 14,
    };
    UseMethod use_method; /*3.2*/
  };
  struct packet_network_settings {
    uint16_t compression_threshold; /*0.0*/
  };
  struct packet_player_auth_input {
    float pitch; /*0.0*/
    float yaw; /*0.0*/
    pdef::proto::vec3f position; /*4.0*/
    pdef::proto::vec2f move_vector; /*4.0*/
    float head_yaw; /*0.0*/
    struct input_data_t { /*6.0*/
      bool ascend = false; /*6.0*/
      bool descend = false; /*6.0*/
      bool north_jump = false; /*6.0*/
      bool jump_down = false; /*6.0*/
      bool sprint_down = false; /*6.0*/
      bool change_height = false; /*6.0*/
      bool jumping = false; /*6.0*/
      bool auto_jumping_in_water = false; /*6.0*/
      bool sneaking = false; /*6.0*/
      bool sneak_down = false; /*6.0*/
      bool up = false; /*6.0*/
      bool down = false; /*6.0*/
      bool left = false; /*6.0*/
      bool right = false; /*6.0*/
      bool up_left = false; /*6.0*/
      bool up_right = false; /*6.0*/
      bool want_up = false; /*6.0*/
      bool want_down = false; /*6.0*/
      bool want_down_slow = false; /*6.0*/
      bool want_up_slow = false; /*6.0*/
      bool sprinting = false; /*6.0*/
      bool ascend_block = false; /*6.0*/
      bool descend_block = false; /*6.0*/
      bool sneak_toggle_down = false; /*6.0*/
      bool persist_sneak = false; /*6.0*/
      bool start_sprinting = false; /*6.0*/
      bool stop_sprinting = false; /*6.0*/
      bool start_sneaking = false; /*6.0*/
      bool stop_sneaking = false; /*6.0*/
      bool start_swimming = false; /*6.0*/
      bool stop_swimming = false; /*6.0*/
      bool start_jumping = false; /*6.0*/
      bool start_gliding = false; /*6.0*/
      bool stop_gliding = false; /*6.0*/
      bool item_interact = false; /*6.0*/
      bool block_action = false; /*6.0*/
      bool item_stack_request = false; /*6.0*/
    } input_data; /*6.0*/
    enum class InputMode : int {
      Unknown = 0,
      Mouse = 1,
      Touch = 2,
      GamePad = 3,
      MotionController = 4,
    };
    InputMode input_mode; /*3.2*/
    enum class PlayMode : int {
      Normal = 0,
      Teaser = 1,
      Screen = 2,
      Viewer = 3,
      Reality = 4,
      Placement = 5,
      LivingRoom = 6,
      ExitLevel = 7,
      ExitLevelLivingRoom = 8,
      NumModes = 9,
    };
    PlayMode play_mode; /*3.2*/
    enum class InteractionModel : int {
      Touch = 0,
      Crosshair = 1,
      Classic = 2,
    };
    InteractionModel interaction_model; /*3.2*/
    int64_t tick; /*0.0*/
    pdef::proto::vec3f delta; /*4.0*/
    std::optional<pdef::proto::vec3f> gaze_direction; /*4.0*/
    struct Transaction {
      pdef::proto::TransactionLegacy legacy; /*4.0*/
      std::vector<pdef::proto::TransactionActions> actions; /*1.0*/
      pdef::proto::TransactionUseItem data; /*4.0*/
    };
    std::optional<Transaction> transaction; /*3.2*/
    std::optional<pdef::proto::ItemStackRequest> item_stack_request; /*4.0*/
    struct BlockAction {
      enum class Action : int {
        StartBreak = 0,
        AbortBreak = 1,
        StopBreak = 2,
        GetUpdatedBlock = 3,
        DropItem = 4,
        StartSleeping = 5,
        StopSleeping = 6,
        Respawn = 7,
        Jump = 8,
        StartSprint = 9,
        StopSprint = 10,
        StartSneak = 11,
        StopSneak = 12,
        CreativePlayerDestroyBlock = 13,
        DimensionChangeAck = 14,
        StartGlide = 15,
        StopGlide = 16,
        BuildDenied = 17,
        CrackBreak = 18,
        ChangeSkin = 19,
        SetEnchatnmentSeed = 20,
        Swimming = 21,
        StopSwimming = 22,
        StartSpinAttack = 23,
        StopSpinAttack = 24,
        InteractBlock = 25,
        PredictBreak = 26,
        ContinueBreak = 27,
        StartItemUseOn = 28,
        StopItemUseOn = 29,
      };
      Action action; /*3.2*/
      std::optional<pdef::proto::vec3i> position; /*4.0*/
      int face; /*0.0*/
    };
    std::vector<BlockAction /*3.2*/> block_action; /*3.0*/
  };
  struct packet_creative_content {
    struct Items {
      int entry_id; /*0.0*/
      pdef::proto::ItemLegacy item; /*4.0*/
    };
    std::vector<Items /*3.2*/> items; /*3.0*/
  };
  struct packet_player_enchant_options {
    std::vector<pdef::proto::EnchantOption /*4.0*/> options; /*3.0*/
  };
  struct packet_item_stack_request {
    std::vector<pdef::proto::ItemStackRequest /*4.0*/> requests; /*3.0*/
  };
  struct packet_item_stack_response {
    std::vector<pdef::proto::ItemStackResponses> responses; /*1.0*/
  };
  struct packet_player_armor_damage {
    struct type_t { /*6.0*/
      bool head = false; /*6.0*/
      bool chest = false; /*6.0*/
      bool legs = false; /*6.0*/
      bool feet = false; /*6.0*/
    } type; /*6.0*/
    int helmet_damage; /*0.0*/
    int chestplate_damage; /*0.0*/
    int leggings_damage; /*0.0*/
    int boots_damage; /*0.0*/
  };
  struct packet_update_player_game_type {
    enum class Gamemode : int {
      Survival = 0,
      Creative = 1,
      Adventure = 2,
      SurvivalSpectator = 3,
      CreativeSpectator = 4,
      Fallback = 5,
      Spectator = 6,
    };
    Gamemode gamemode; /*3.2*/
    int64_t player_unique_id; /*0.0*/
  };
  struct packet_emote_list {
    int64_t player_id; /*0.0*/
    std::vector<uint64_t /*0.0*/> emote_pieces; /*3.0*/
  };
  struct packet_position_tracking_db_request {
    enum class Action : uint8_t {
      Query = 0,
    };
    Action action; /*3.2*/
    int tracking_id; /*0.0*/
  };
  struct packet_position_tracking_db_broadcast {
    enum class BroadcastAction : uint8_t {
      Update = 0,
      Destory = 1,
      NotFound = 2,
    };
    BroadcastAction broadcast_action; /*3.2*/
    int tracking_id; /*0.0*/
    int8_t nbt; /*0.0*/
  };
  struct packet_packet_violation_warning {
    enum class ViolationType : int {
      Malformed = 0,
    };
    ViolationType violation_type; /*3.2*/
    enum class Severity : int {
      Warning = 0,
      FinalWarning = 1,
      Terminating = 2,
    };
    Severity severity; /*3.2*/
    int packet_id; /*0.0*/
    std::string reason; /*6.0*/
  };
  struct packet_motion_prediction_hints {
    int64_t entity_runtime_id; /*0.0*/
    pdef::proto::vec3f velocity; /*4.0*/
    bool on_ground; /*0.0*/
  };
  struct packet_animate_entity {
    std::string animation; /*6.0*/
    std::string next_state; /*6.0*/
    std::string stop_condition; /*6.0*/
    int32_t stop_condition_version; /*0.0*/
    std::string controller; /*6.0*/
    float blend_out_time; /*0.0*/
    std::vector<int64_t /*0.0*/> runtime_entity_ids; /*3.0*/
  };
  struct packet_camera_shake {
    float intensity; /*0.0*/
    float duration; /*0.0*/
    uint8_t type; /*0.0*/
    enum class Action : uint8_t {
      Add = 0,
      Stop = 1,
    };
    Action action; /*3.2*/
  };
  struct packet_player_fog {
    std::vector<std::string /*6.0*/> stack; /*3.0*/
  };
  struct packet_correct_player_move_prediction {
    pdef::proto::vec3f position; /*4.0*/
    pdef::proto::vec3f delta; /*4.0*/
    bool on_ground; /*0.0*/
    int64_t tick; /*0.0*/
  };
  struct packet_item_component {
    std::vector<pdef::proto::ItemComponentList> entries; /*1.0*/
  };
  struct packet_filter_text_packet {
    std::string text; /*6.0*/
    bool from_server; /*0.0*/
  };
  struct packet_debug_renderer {
    enum class Type : int32_t {
      Clear = 1,
      AddCube = 2,
    };
    Type type; /*3.2*/
    std::string text; /*6.0*/
    std::optional<pdef::proto::vec3f> position; /*4.0*/
    float red; /*0.0*/
    float green; /*0.0*/
    float blue; /*0.0*/
    float alpha; /*0.0*/
    int64_t duration; /*0.0*/
  };
  struct packet_sync_entity_property {
    int8_t nbt; /*0.0*/
  };
  struct packet_add_volume_entity {
    int64_t runtime_id; /*0.0*/
    int8_t nbt; /*0.0*/
    std::string encoding_identifier; /*6.0*/
    std::string instance_name; /*6.0*/
    struct Bounds {
      pdef::proto::BlockCoordinates min; /*4.0*/
      pdef::proto::BlockCoordinates max; /*4.0*/
    };
    Bounds bounds; /*3.2*/
    int dimension; /*0.0*/
    std::string engine_version; /*6.0*/
  };
  struct packet_remove_volume_entity {
    int64_t entity_id; /*0.0*/
  };
  struct packet_simulation_type {
    enum class Type : uint8_t {
      Game = 0,
      Editor = 1,
      Test = 2,
      Invalid = 3,
    };
    Type type; /*3.2*/
  };
  struct packet_npc_dialogue {
    uint64_t entity_id; /*0.0*/
    enum class ActionType : int {
      Open = 0,
      Close = 1,
    };
    ActionType action_type; /*3.2*/
    std::string dialogue; /*6.0*/
    std::string screen_name; /*6.0*/
    std::string npc_name; /*6.0*/
    std::string action_json; /*6.0*/
  };
  struct packet_edu_uri_resource_packet {
    pdef::proto::EducationSharedResourceURI resource; /*4.0*/
  };
  struct packet_create_photo {
    int64_t entity_unique_id; /*0.0*/
    std::string photo_name; /*6.0*/
    std::string item_name; /*6.0*/
  };
  struct packet_update_subchunk_blocks {
    int x; /*0.0*/
    int y; /*0.0*/
    int z; /*0.0*/
    std::vector<pdef::proto::BlockUpdate /*4.0*/> blocks; /*3.0*/
    std::vector<pdef::proto::BlockUpdate /*4.0*/> extra; /*3.0*/
  };
  struct packet_photo_info_request {
    int64_t photo_id; /*0.0*/
  };
  struct SubChunkEntryWithoutCaching {
    int8_t dx; /*0.0*/
    int8_t dy; /*0.0*/
    int8_t dz; /*0.0*/
    enum class Result : uint8_t {
      Undefined = 0,
      Success = 1,
      ChunkNotFound = 2,
      InvalidDimension = 3,
      PlayerNotFound = 4,
      YIndexOutOfBounds = 5,
      SuccessAllAir = 6,
    };
    Result result; /*3.2*/
    std::vector<uint8_t> payload; /*6.0*/
    enum class HeightmapType : uint8_t {
      NoData = 0,
      HasData = 1,
      TooHigh = 2,
      TooLow = 3,
    };
    HeightmapType heightmap_type; /*3.2*/
    std::vector<uint8_t> heightmap; /*6.0*/
  };
  struct SubChunkEntryWithCaching {
    int8_t dx; /*0.0*/
    int8_t dy; /*0.0*/
    int8_t dz; /*0.0*/
    enum class Result : uint8_t {
      Undefined = 0,
      Success = 1,
      ChunkNotFound = 2,
      InvalidDimension = 3,
      PlayerNotFound = 4,
      YIndexOutOfBounds = 5,
      SuccessAllAir = 6,
    };
    Result result; /*3.2*/
    enum class HeightmapType : uint8_t {
      NoData = 0,
      HasData = 1,
      TooHigh = 2,
      TooLow = 3,
    };
    HeightmapType heightmap_type; /*3.2*/
    uint64_t blob_id; /*0.0*/
    std::vector<uint8_t> payload; /*6.0*/
    std::vector<uint8_t> heightmap; /*6.0*/
  };
  struct packet_subchunk {
    bool cache_enabled; /*0.0*/
    int dimension; /*0.0*/
    pdef::proto::vec3i origin; /*4.0*/
    std::vector<pdef::proto::SubChunkEntryWithCaching> entries_SubChunkEntryWithCaching; /*1.0*/
    std::vector<pdef::proto::SubChunkEntryWithoutCaching> entries_SubChunkEntryWithoutCaching; /*1.0*/
  };
  struct packet_subchunk_request {
    int dimension; /*0.0*/
    pdef::proto::vec3i origin; /*4.0*/
    struct Requests {
      int8_t dx; /*0.0*/
      int8_t dy; /*0.0*/
      int8_t dz; /*0.0*/
    };
    std::vector<Requests /*3.2*/> requests; /*3.0*/
  };
  struct packet_client_start_item_cooldown {
    std::string category; /*6.0*/
    int duration; /*0.0*/
  };
  struct packet_script_message {
    std::string message_id; /*6.0*/
    std::string data; /*6.0*/
  };
  struct packet_code_builder_source {
    enum class Operation : uint8_t {
      None = 0,
      Get = 1,
      Set = 2,
      Reset = 3,
    };
    Operation operation; /*3.2*/
    enum class Category : uint8_t {
      None = 0,
      CodeStatus = 1,
      Instantiation = 2,
    };
    Category category; /*3.2*/
    std::string value; /*6.0*/
  };
  struct packet_ticking_areas_load_status {
    bool preload; /*0.0*/
  };
  struct packet_dimension_data {
    struct Definitions {
      std::string id; /*6.0*/
      int max_height; /*0.0*/
      int min_height; /*0.0*/
      enum class Generator : int {
        Legacy = 0,
        Overworld = 1,
        Flat = 2,
        Nether = 3,
        End = 4,
        Void = 5,
      };
      Generator generator; /*3.2*/
    };
    std::vector<Definitions /*3.2*/> definitions; /*3.0*/
  };
  struct packet_agent_action {
    std::string request_id; /*6.0*/
    enum class ActionType : int {
      None = 0,
      Attack = 1,
      Collect = 2,
      Destroy = 3,
      DetectRedstone = 4,
      DetectObstacle = 5,
      Drop = 6,
      DropAll = 7,
      Inspect = 8,
      InspectData = 9,
      InspectItemCount = 10,
      InspectItemDetail = 11,
      InspectItemSpace = 12,
      Interact = 13,
      Move = 14,
      PlaceBlock = 15,
      Till = 16,
      TransferItemTo = 17,
      Turn = 18,
    };
    ActionType action_type; /*3.2*/
    std::string body; /*6.0*/
  };
  struct packet_change_mob_property {
    int64_t entity_unique_id; /*0.0*/
    std::string property; /*6.0*/
    bool bool_value; /*0.0*/
    std::string string_value; /*6.0*/
    int int_value; /*0.0*/
    float float_value; /*0.0*/
  };
  struct packet_lesson_progress {
    uint8_t action; /*0.0*/
    int score; /*0.0*/
    std::string identifier; /*6.0*/
  };
  struct packet_request_ability {
    enum class Ability : int {
      Build = 0,
      Mine = 1,
      DoorsAndSwitches = 2,
      OpenContainers = 3,
      AttackPlayers = 4,
      AttackMobs = 5,
      OperatorCommands = 6,
      Teleport = 7,
      Invulnerable = 8,
      Flying = 9,
      MayFly = 10,
      InstantBuild = 11,
      Lightning = 12,
      FlySpeed = 13,
      WalkSpeed = 14,
      Muted = 15,
      WorldBuilder = 16,
      NoClip = 17,
      AbilityCount = 18,
    };
    Ability ability; /*3.2*/
    enum class ValueType : uint8_t {
      Bool = 1,
      Float = 2,
    };
    ValueType value_type; /*3.2*/
    bool bool_value; /*0.0*/
    float float_val; /*0.0*/
  };
  struct packet_request_permissions {
    int64_t entity_unique_id; /*0.0*/
    enum class PermissionLevel : int {
      Visitor = 0,
      Member = 1,
      Operator = 2,
      Custom = 3,
    };
    PermissionLevel permission_level; /*3.2*/
    struct requested_permissions_t { /*6.0*/
      bool build = false; /*6.0*/
      bool mine = false; /*6.0*/
      bool doors_and_switches = false; /*6.0*/
      bool open_containers = false; /*6.0*/
      bool attack_players = false; /*6.0*/
      bool attack_mobs = false; /*6.0*/
      bool operator_ = false; /*6.0*/
      bool teleport = false; /*6.0*/
    } requested_permissions; /*6.0*/
  };
  struct packet_toast_request {
    std::string title; /*6.0*/
    std::string message; /*6.0*/
  };
  struct mcpe_packet {
    enum class Name : int {
      Login = 1,
      PlayStatus = 2,
      ServerToClientHandshake = 3,
      ClientToServerHandshake = 4,
      Disconnect = 5,
      ResourcePacksInfo = 6,
      ResourcePackStack = 7,
      ResourcePackClientResponse = 8,
      Text = 9,
      SetTime = 10,
      StartGame = 11,
      AddPlayer = 12,
      AddEntity = 13,
      RemoveEntity = 14,
      AddItemEntity = 15,
      TakeItemEntity = 17,
      MoveEntity = 18,
      MovePlayer = 19,
      RiderJump = 20,
      UpdateBlock = 21,
      AddPainting = 22,
      TickSync = 23,
      LevelSoundEventOld = 24,
      LevelEvent = 25,
      BlockEvent = 26,
      EntityEvent = 27,
      MobEffect = 28,
      UpdateAttributes = 29,
      InventoryTransaction = 30,
      MobEquipment = 31,
      MobArmorEquipment = 32,
      Interact = 33,
      BlockPickRequest = 34,
      EntityPickRequest = 35,
      PlayerAction = 36,
      HurtArmor = 38,
      SetEntityData = 39,
      SetEntityMotion = 40,
      SetEntityLink = 41,
      SetHealth = 42,
      SetSpawnPosition = 43,
      Animate = 44,
      Respawn = 45,
      ContainerOpen = 46,
      ContainerClose = 47,
      PlayerHotbar = 48,
      InventoryContent = 49,
      InventorySlot = 50,
      ContainerSetData = 51,
      CraftingData = 52,
      CraftingEvent = 53,
      GuiDataPickItem = 54,
      AdventureSettings = 55,
      BlockEntityData = 56,
      PlayerInput = 57,
      LevelChunk = 58,
      SetCommandsEnabled = 59,
      SetDifficulty = 60,
      ChangeDimension = 61,
      SetPlayerGameType = 62,
      PlayerList = 63,
      SimpleEvent = 64,
      Event = 65,
      SpawnExperienceOrb = 66,
      ClientboundMapItemData = 67,
      MapInfoRequest = 68,
      RequestChunkRadius = 69,
      ChunkRadiusUpdate = 70,
      ItemFrameDropItem = 71,
      GameRulesChanged = 72,
      Camera = 73,
      BossEvent = 74,
      ShowCredits = 75,
      AvailableCommands = 76,
      CommandRequest = 77,
      CommandBlockUpdate = 78,
      CommandOutput = 79,
      UpdateTrade = 80,
      UpdateEquipment = 81,
      ResourcePackDataInfo = 82,
      ResourcePackChunkData = 83,
      ResourcePackChunkRequest = 84,
      Transfer = 85,
      PlaySound = 86,
      StopSound = 87,
      SetTitle = 88,
      AddBehaviorTree = 89,
      StructureBlockUpdate = 90,
      ShowStoreOffer = 91,
      PurchaseReceipt = 92,
      PlayerSkin = 93,
      SubClientLogin = 94,
      InitiateWebSocketConnection = 95,
      SetLastHurtBy = 96,
      BookEdit = 97,
      NpcRequest = 98,
      PhotoTransfer = 99,
      ModalFormRequest = 100,
      ModalFormResponse = 101,
      ServerSettingsRequest = 102,
      ServerSettingsResponse = 103,
      ShowProfile = 104,
      SetDefaultGameType = 105,
      RemoveObjective = 106,
      SetDisplayObjective = 107,
      SetScore = 108,
      LabTable = 109,
      UpdateBlockSynced = 110,
      MoveEntityDelta = 111,
      SetScoreboardIdentity = 112,
      SetLocalPlayerAsInitialized = 113,
      UpdateSoftEnum = 114,
      NetworkStackLatency = 115,
      ScriptCustomEvent = 117,
      SpawnParticleEffect = 118,
      AvailableEntityIdentifiers = 119,
      LevelSoundEventV2 = 120,
      NetworkChunkPublisherUpdate = 121,
      BiomeDefinitionList = 122,
      LevelSoundEvent = 123,
      LevelEventGeneric = 124,
      LecternUpdate = 125,
      VideoStreamConnect = 126,
      AddEcsEntity = 127,
      RemoveEcsEntity = 128,
      ClientCacheStatus = 129,
      OnScreenTextureAnimation = 130,
      MapCreateLockedCopy = 131,
      StructureTemplateDataExportRequest = 132,
      StructureTemplateDataExportResponse = 133,
      UpdateBlockProperties = 134,
      ClientCacheBlobStatus = 135,
      ClientCacheMissResponse = 136,
      EducationSettings = 137,
      Emote = 138,
      MultiplayerSettings = 139,
      SettingsCommand = 140,
      AnvilDamage = 141,
      CompletedUsingItem = 142,
      NetworkSettings = 143,
      PlayerAuthInput = 144,
      CreativeContent = 145,
      PlayerEnchantOptions = 146,
      ItemStackRequest = 147,
      ItemStackResponse = 148,
      PlayerArmorDamage = 149,
      UpdatePlayerGameType = 151,
      EmoteList = 152,
      PositionTrackingDbBroadcast = 153,
      PositionTrackingDbRequest = 154,
      PacketViolationWarning = 156,
      MotionPredictionHints = 157,
      AnimateEntity = 158,
      CameraShake = 159,
      PlayerFog = 160,
      CorrectPlayerMovePrediction = 161,
      ItemComponent = 162,
      FilterTextPacket = 163,
      DebugRenderer = 164,
      SyncEntityProperty = 165,
      AddVolumeEntity = 166,
      RemoveVolumeEntity = 167,
      SimulationType = 168,
      NpcDialogue = 169,
      EduUriResourcePacket = 170,
      CreatePhoto = 171,
      UpdateSubchunkBlocks = 172,
      PhotoInfoRequest = 173,
      Subchunk = 174,
      SubchunkRequest = 175,
      ClientStartItemCooldown = 176,
      ScriptMessage = 177,
      CodeBuilderSource = 178,
      TickingAreasLoadStatus = 179,
      DimensionData = 180,
      AgentAction = 181,
      ChangeMobProperty = 182,
      LessonProgress = 183,
      RequestAbility = 184,
      RequestPermissions = 185,
      ToastRequest = 186,
    };
    Name name; /*3.2*/
    std::optional<pdef::proto::packet_login> params_packet_login; /*4.0*/
    std::optional<pdef::proto::packet_play_status> params_packet_play_status; /*4.0*/
    std::optional<pdef::proto::packet_server_to_client_handshake> params_packet_server_to_client_handshake; /*4.0*/
    std::optional<pdef::proto::packet_client_to_server_handshake> params_packet_client_to_server_handshake; /*4.0*/
    std::optional<pdef::proto::packet_disconnect> params_packet_disconnect; /*4.0*/
    std::optional<pdef::proto::packet_resource_packs_info> params_packet_resource_packs_info; /*4.0*/
    std::optional<pdef::proto::packet_resource_pack_stack> params_packet_resource_pack_stack; /*4.0*/
    std::optional<pdef::proto::packet_resource_pack_client_response> params_packet_resource_pack_client_response; /*4.0*/
    std::optional<pdef::proto::packet_text> params_packet_text; /*4.0*/
    std::optional<pdef::proto::packet_set_time> params_packet_set_time; /*4.0*/
    std::optional<pdef::proto::packet_start_game> params_packet_start_game; /*4.0*/
    std::optional<pdef::proto::packet_add_player> params_packet_add_player; /*4.0*/
    std::optional<pdef::proto::packet_add_entity> params_packet_add_entity; /*4.0*/
    std::optional<pdef::proto::packet_remove_entity> params_packet_remove_entity; /*4.0*/
    std::optional<pdef::proto::packet_add_item_entity> params_packet_add_item_entity; /*4.0*/
    std::optional<pdef::proto::packet_take_item_entity> params_packet_take_item_entity; /*4.0*/
    std::optional<pdef::proto::packet_move_entity> params_packet_move_entity; /*4.0*/
    std::optional<pdef::proto::packet_move_player> params_packet_move_player; /*4.0*/
    std::optional<pdef::proto::packet_rider_jump> params_packet_rider_jump; /*4.0*/
    std::optional<pdef::proto::packet_update_block> params_packet_update_block; /*4.0*/
    std::optional<pdef::proto::packet_add_painting> params_packet_add_painting; /*4.0*/
    std::optional<pdef::proto::packet_tick_sync> params_packet_tick_sync; /*4.0*/
    std::optional<pdef::proto::packet_level_sound_event_old> params_packet_level_sound_event_old; /*4.0*/
    std::optional<pdef::proto::packet_level_event> params_packet_level_event; /*4.0*/
    std::optional<pdef::proto::packet_block_event> params_packet_block_event; /*4.0*/
    std::optional<pdef::proto::packet_entity_event> params_packet_entity_event; /*4.0*/
    std::optional<pdef::proto::packet_mob_effect> params_packet_mob_effect; /*4.0*/
    std::optional<pdef::proto::packet_update_attributes> params_packet_update_attributes; /*4.0*/
    std::optional<pdef::proto::packet_inventory_transaction> params_packet_inventory_transaction; /*4.0*/
    std::optional<pdef::proto::packet_mob_equipment> params_packet_mob_equipment; /*4.0*/
    std::optional<pdef::proto::packet_mob_armor_equipment> params_packet_mob_armor_equipment; /*4.0*/
    std::optional<pdef::proto::packet_interact> params_packet_interact; /*4.0*/
    std::optional<pdef::proto::packet_block_pick_request> params_packet_block_pick_request; /*4.0*/
    std::optional<pdef::proto::packet_entity_pick_request> params_packet_entity_pick_request; /*4.0*/
    std::optional<pdef::proto::packet_player_action> params_packet_player_action; /*4.0*/
    std::optional<pdef::proto::packet_hurt_armor> params_packet_hurt_armor; /*4.0*/
    std::optional<pdef::proto::packet_set_entity_data> params_packet_set_entity_data; /*4.0*/
    std::optional<pdef::proto::packet_set_entity_motion> params_packet_set_entity_motion; /*4.0*/
    std::optional<pdef::proto::packet_set_entity_link> params_packet_set_entity_link; /*4.0*/
    std::optional<pdef::proto::packet_set_health> params_packet_set_health; /*4.0*/
    std::optional<pdef::proto::packet_set_spawn_position> params_packet_set_spawn_position; /*4.0*/
    std::optional<pdef::proto::packet_animate> params_packet_animate; /*4.0*/
    std::optional<pdef::proto::packet_respawn> params_packet_respawn; /*4.0*/
    std::optional<pdef::proto::packet_container_open> params_packet_container_open; /*4.0*/
    std::optional<pdef::proto::packet_container_close> params_packet_container_close; /*4.0*/
    std::optional<pdef::proto::packet_player_hotbar> params_packet_player_hotbar; /*4.0*/
    std::optional<pdef::proto::packet_inventory_content> params_packet_inventory_content; /*4.0*/
    std::optional<pdef::proto::packet_inventory_slot> params_packet_inventory_slot; /*4.0*/
    std::optional<pdef::proto::packet_container_set_data> params_packet_container_set_data; /*4.0*/
    std::optional<pdef::proto::packet_crafting_data> params_packet_crafting_data; /*4.0*/
    std::optional<pdef::proto::packet_crafting_event> params_packet_crafting_event; /*4.0*/
    std::optional<pdef::proto::packet_gui_data_pick_item> params_packet_gui_data_pick_item; /*4.0*/
    std::optional<pdef::proto::packet_adventure_settings> params_packet_adventure_settings; /*4.0*/
    std::optional<pdef::proto::packet_block_entity_data> params_packet_block_entity_data; /*4.0*/
    std::optional<pdef::proto::packet_player_input> params_packet_player_input; /*4.0*/
    std::optional<pdef::proto::packet_level_chunk> params_packet_level_chunk; /*4.0*/
    std::optional<pdef::proto::packet_set_commands_enabled> params_packet_set_commands_enabled; /*4.0*/
    std::optional<pdef::proto::packet_set_difficulty> params_packet_set_difficulty; /*4.0*/
    std::optional<pdef::proto::packet_change_dimension> params_packet_change_dimension; /*4.0*/
    std::optional<pdef::proto::packet_set_player_game_type> params_packet_set_player_game_type; /*4.0*/
    std::optional<pdef::proto::packet_player_list> params_packet_player_list; /*4.0*/
    std::optional<pdef::proto::packet_simple_event> params_packet_simple_event; /*4.0*/
    std::optional<pdef::proto::packet_event> params_packet_event; /*4.0*/
    std::optional<pdef::proto::packet_spawn_experience_orb> params_packet_spawn_experience_orb; /*4.0*/
    std::optional<pdef::proto::packet_clientbound_map_item_data> params_packet_clientbound_map_item_data; /*4.0*/
    std::optional<pdef::proto::packet_map_info_request> params_packet_map_info_request; /*4.0*/
    std::optional<pdef::proto::packet_request_chunk_radius> params_packet_request_chunk_radius; /*4.0*/
    std::optional<pdef::proto::packet_chunk_radius_update> params_packet_chunk_radius_update; /*4.0*/
    std::optional<pdef::proto::packet_item_frame_drop_item> params_packet_item_frame_drop_item; /*4.0*/
    std::optional<pdef::proto::packet_game_rules_changed> params_packet_game_rules_changed; /*4.0*/
    std::optional<pdef::proto::packet_camera> params_packet_camera; /*4.0*/
    std::optional<pdef::proto::packet_boss_event> params_packet_boss_event; /*4.0*/
    std::optional<pdef::proto::packet_show_credits> params_packet_show_credits; /*4.0*/
    std::optional<pdef::proto::packet_available_commands> params_packet_available_commands; /*4.0*/
    std::optional<pdef::proto::packet_command_request> params_packet_command_request; /*4.0*/
    std::optional<pdef::proto::packet_command_block_update> params_packet_command_block_update; /*4.0*/
    std::optional<pdef::proto::packet_command_output> params_packet_command_output; /*4.0*/
    std::optional<pdef::proto::packet_update_trade> params_packet_update_trade; /*4.0*/
    std::optional<pdef::proto::packet_update_equipment> params_packet_update_equipment; /*4.0*/
    std::optional<pdef::proto::packet_resource_pack_data_info> params_packet_resource_pack_data_info; /*4.0*/
    std::optional<pdef::proto::packet_resource_pack_chunk_data> params_packet_resource_pack_chunk_data; /*4.0*/
    std::optional<pdef::proto::packet_resource_pack_chunk_request> params_packet_resource_pack_chunk_request; /*4.0*/
    std::optional<pdef::proto::packet_transfer> params_packet_transfer; /*4.0*/
    std::optional<pdef::proto::packet_play_sound> params_packet_play_sound; /*4.0*/
    std::optional<pdef::proto::packet_stop_sound> params_packet_stop_sound; /*4.0*/
    std::optional<pdef::proto::packet_set_title> params_packet_set_title; /*4.0*/
    std::optional<pdef::proto::packet_add_behavior_tree> params_packet_add_behavior_tree; /*4.0*/
    std::optional<pdef::proto::packet_structure_block_update> params_packet_structure_block_update; /*4.0*/
    std::optional<pdef::proto::packet_show_store_offer> params_packet_show_store_offer; /*4.0*/
    std::optional<pdef::proto::packet_purchase_receipt> params_packet_purchase_receipt; /*4.0*/
    std::optional<pdef::proto::packet_player_skin> params_packet_player_skin; /*4.0*/
    std::optional<pdef::proto::packet_sub_client_login> params_packet_sub_client_login; /*4.0*/
    std::optional<pdef::proto::packet_initiate_web_socket_connection> params_packet_initiate_web_socket_connection; /*4.0*/
    std::optional<pdef::proto::packet_set_last_hurt_by> params_packet_set_last_hurt_by; /*4.0*/
    std::optional<pdef::proto::packet_book_edit> params_packet_book_edit; /*4.0*/
    std::optional<pdef::proto::packet_npc_request> params_packet_npc_request; /*4.0*/
    std::optional<pdef::proto::packet_photo_transfer> params_packet_photo_transfer; /*4.0*/
    std::optional<pdef::proto::packet_modal_form_request> params_packet_modal_form_request; /*4.0*/
    std::optional<pdef::proto::packet_modal_form_response> params_packet_modal_form_response; /*4.0*/
    std::optional<pdef::proto::packet_server_settings_request> params_packet_server_settings_request; /*4.0*/
    std::optional<pdef::proto::packet_server_settings_response> params_packet_server_settings_response; /*4.0*/
    std::optional<pdef::proto::packet_show_profile> params_packet_show_profile; /*4.0*/
    std::optional<pdef::proto::packet_set_default_game_type> params_packet_set_default_game_type; /*4.0*/
    std::optional<pdef::proto::packet_remove_objective> params_packet_remove_objective; /*4.0*/
    std::optional<pdef::proto::packet_set_display_objective> params_packet_set_display_objective; /*4.0*/
    std::optional<pdef::proto::packet_set_score> params_packet_set_score; /*4.0*/
    std::optional<pdef::proto::packet_lab_table> params_packet_lab_table; /*4.0*/
    std::optional<pdef::proto::packet_update_block_synced> params_packet_update_block_synced; /*4.0*/
    std::optional<pdef::proto::packet_move_entity_delta> params_packet_move_entity_delta; /*4.0*/
    std::optional<pdef::proto::packet_set_scoreboard_identity> params_packet_set_scoreboard_identity; /*4.0*/
    std::optional<pdef::proto::packet_set_local_player_as_initialized> params_packet_set_local_player_as_initialized; /*4.0*/
    std::optional<pdef::proto::packet_update_soft_enum> params_packet_update_soft_enum; /*4.0*/
    std::optional<pdef::proto::packet_network_stack_latency> params_packet_network_stack_latency; /*4.0*/
    std::optional<pdef::proto::packet_script_custom_event> params_packet_script_custom_event; /*4.0*/
    std::optional<pdef::proto::packet_spawn_particle_effect> params_packet_spawn_particle_effect; /*4.0*/
    std::optional<pdef::proto::packet_available_entity_identifiers> params_packet_available_entity_identifiers; /*4.0*/
    std::optional<pdef::proto::packet_level_sound_event_v2> params_packet_level_sound_event_v2; /*4.0*/
    std::optional<pdef::proto::packet_network_chunk_publisher_update> params_packet_network_chunk_publisher_update; /*4.0*/
    std::optional<pdef::proto::packet_biome_definition_list> params_packet_biome_definition_list; /*4.0*/
    std::optional<pdef::proto::packet_level_sound_event> params_packet_level_sound_event; /*4.0*/
    std::optional<pdef::proto::packet_level_event_generic> params_packet_level_event_generic; /*4.0*/
    std::optional<pdef::proto::packet_lectern_update> params_packet_lectern_update; /*4.0*/
    std::optional<pdef::proto::packet_video_stream_connect> params_packet_video_stream_connect; /*4.0*/
    std::optional<pdef::proto::packet_add_ecs_entity> params_packet_add_ecs_entity; /*4.0*/
    std::optional<pdef::proto::packet_remove_ecs_entity> params_packet_remove_ecs_entity; /*4.0*/
    std::optional<pdef::proto::packet_client_cache_status> params_packet_client_cache_status; /*4.0*/
    std::optional<pdef::proto::packet_on_screen_texture_animation> params_packet_on_screen_texture_animation; /*4.0*/
    std::optional<pdef::proto::packet_map_create_locked_copy> params_packet_map_create_locked_copy; /*4.0*/
    std::optional<pdef::proto::packet_structure_template_data_export_request> params_packet_structure_template_data_export_request; /*4.0*/
    std::optional<pdef::proto::packet_structure_template_data_export_response> params_packet_structure_template_data_export_response; /*4.0*/
    std::optional<pdef::proto::packet_update_block_properties> params_packet_update_block_properties; /*4.0*/
    std::optional<pdef::proto::packet_client_cache_blob_status> params_packet_client_cache_blob_status; /*4.0*/
    std::optional<pdef::proto::packet_client_cache_miss_response> params_packet_client_cache_miss_response; /*4.0*/
    std::optional<pdef::proto::packet_education_settings> params_packet_education_settings; /*4.0*/
    std::optional<pdef::proto::packet_emote> params_packet_emote; /*4.0*/
    std::optional<pdef::proto::packet_multiplayer_settings> params_packet_multiplayer_settings; /*4.0*/
    std::optional<pdef::proto::packet_settings_command> params_packet_settings_command; /*4.0*/
    std::optional<pdef::proto::packet_anvil_damage> params_packet_anvil_damage; /*4.0*/
    std::optional<pdef::proto::packet_completed_using_item> params_packet_completed_using_item; /*4.0*/
    std::optional<pdef::proto::packet_network_settings> params_packet_network_settings; /*4.0*/
    std::optional<pdef::proto::packet_player_auth_input> params_packet_player_auth_input; /*4.0*/
    std::optional<pdef::proto::packet_creative_content> params_packet_creative_content; /*4.0*/
    std::optional<pdef::proto::packet_player_enchant_options> params_packet_player_enchant_options; /*4.0*/
    std::optional<pdef::proto::packet_item_stack_request> params_packet_item_stack_request; /*4.0*/
    std::optional<pdef::proto::packet_item_stack_response> params_packet_item_stack_response; /*4.0*/
    std::optional<pdef::proto::packet_player_armor_damage> params_packet_player_armor_damage; /*4.0*/
    std::optional<pdef::proto::packet_update_player_game_type> params_packet_update_player_game_type; /*4.0*/
    std::optional<pdef::proto::packet_emote_list> params_packet_emote_list; /*4.0*/
    std::optional<pdef::proto::packet_position_tracking_db_request> params_packet_position_tracking_db_request; /*4.0*/
    std::optional<pdef::proto::packet_position_tracking_db_broadcast> params_packet_position_tracking_db_broadcast; /*4.0*/
    std::optional<pdef::proto::packet_packet_violation_warning> params_packet_packet_violation_warning; /*4.0*/
    std::optional<pdef::proto::packet_motion_prediction_hints> params_packet_motion_prediction_hints; /*4.0*/
    std::optional<pdef::proto::packet_animate_entity> params_packet_animate_entity; /*4.0*/
    std::optional<pdef::proto::packet_camera_shake> params_packet_camera_shake; /*4.0*/
    std::optional<pdef::proto::packet_player_fog> params_packet_player_fog; /*4.0*/
    std::optional<pdef::proto::packet_correct_player_move_prediction> params_packet_correct_player_move_prediction; /*4.0*/
    std::optional<pdef::proto::packet_item_component> params_packet_item_component; /*4.0*/
    std::optional<pdef::proto::packet_filter_text_packet> params_packet_filter_text_packet; /*4.0*/
    std::optional<pdef::proto::packet_debug_renderer> params_packet_debug_renderer; /*4.0*/
    std::optional<pdef::proto::packet_sync_entity_property> params_packet_sync_entity_property; /*4.0*/
    std::optional<pdef::proto::packet_add_volume_entity> params_packet_add_volume_entity; /*4.0*/
    std::optional<pdef::proto::packet_remove_volume_entity> params_packet_remove_volume_entity; /*4.0*/
    std::optional<pdef::proto::packet_simulation_type> params_packet_simulation_type; /*4.0*/
    std::optional<pdef::proto::packet_npc_dialogue> params_packet_npc_dialogue; /*4.0*/
    std::optional<pdef::proto::packet_edu_uri_resource_packet> params_packet_edu_uri_resource_packet; /*4.0*/
    std::optional<pdef::proto::packet_create_photo> params_packet_create_photo; /*4.0*/
    std::optional<pdef::proto::packet_update_subchunk_blocks> params_packet_update_subchunk_blocks; /*4.0*/
    std::optional<pdef::proto::packet_photo_info_request> params_packet_photo_info_request; /*4.0*/
    std::optional<pdef::proto::packet_subchunk> params_packet_subchunk; /*4.0*/
    std::optional<pdef::proto::packet_subchunk_request> params_packet_subchunk_request; /*4.0*/
    std::optional<pdef::proto::packet_client_start_item_cooldown> params_packet_client_start_item_cooldown; /*4.0*/
    std::optional<pdef::proto::packet_script_message> params_packet_script_message; /*4.0*/
    std::optional<pdef::proto::packet_code_builder_source> params_packet_code_builder_source; /*4.0*/
    std::optional<pdef::proto::packet_ticking_areas_load_status> params_packet_ticking_areas_load_status; /*4.0*/
    std::optional<pdef::proto::packet_dimension_data> params_packet_dimension_data; /*4.0*/
    std::optional<pdef::proto::packet_agent_action> params_packet_agent_action; /*4.0*/
    std::optional<pdef::proto::packet_change_mob_property> params_packet_change_mob_property; /*4.0*/
    std::optional<pdef::proto::packet_lesson_progress> params_packet_lesson_progress; /*4.0*/
    std::optional<pdef::proto::packet_request_ability> params_packet_request_ability; /*4.0*/
    std::optional<pdef::proto::packet_request_permissions> params_packet_request_permissions; /*4.0*/
    std::optional<pdef::proto::packet_toast_request> params_packet_toast_request; /*4.0*/
  };
}

namespace pdef::proto::size {
size_t BehaviourPackInfos(pdef::Stream &stream, const pdef::proto::BehaviourPackInfos &obj);
size_t TexturePackInfos(pdef::Stream &stream, const pdef::proto::TexturePackInfos &obj);
size_t ResourcePackIdVersions(pdef::Stream &stream, const pdef::proto::ResourcePackIdVersions &obj);
size_t Experiment(pdef::Stream &stream, const pdef::proto::Experiment &obj);
size_t GameRule(pdef::Stream &stream, const pdef::proto::GameRule &obj);
size_t Blob(pdef::Stream &stream, const pdef::proto::Blob &obj);
size_t BlockProperties(pdef::Stream &stream, const pdef::proto::BlockProperties &obj);
size_t Itemstates(pdef::Stream &stream, const pdef::proto::Itemstates &obj);
size_t ItemExtraDataWithBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithBlockingTick &obj);
size_t ItemExtraDataWithoutBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithoutBlockingTick &obj);
size_t ItemLegacy(pdef::Stream &stream, const pdef::proto::ItemLegacy &obj);
size_t Item(pdef::Stream &stream, const pdef::proto::Item &obj);
size_t vec3i(pdef::Stream &stream, const pdef::proto::vec3i &obj);
size_t vec3u(pdef::Stream &stream, const pdef::proto::vec3u &obj);
size_t vec3f(pdef::Stream &stream, const pdef::proto::vec3f &obj);
size_t vec2f(pdef::Stream &stream, const pdef::proto::vec2f &obj);
size_t MetadataDictionary(pdef::Stream &stream, const pdef::proto::MetadataDictionary &obj);
size_t Link(pdef::Stream &stream, const pdef::proto::Link &obj);
size_t EntityAttributes(pdef::Stream &stream, const pdef::proto::EntityAttributes &obj);
size_t Rotation(pdef::Stream &stream, const pdef::proto::Rotation &obj);
size_t BlockCoordinates(pdef::Stream &stream, const pdef::proto::BlockCoordinates &obj);
size_t PlayerAttributes(pdef::Stream &stream, const pdef::proto::PlayerAttributes &obj);
size_t TransactionUseItem(pdef::Stream &stream, const pdef::proto::TransactionUseItem &obj);
size_t TransactionActions(pdef::Stream &stream, const pdef::proto::TransactionActions &obj);
size_t TransactionLegacy(pdef::Stream &stream, const pdef::proto::TransactionLegacy &obj);
size_t Transaction(pdef::Stream &stream, const pdef::proto::Transaction &obj);
size_t RecipeIngredient(pdef::Stream &stream, const pdef::proto::RecipeIngredient &obj);
size_t PotionTypeRecipes(pdef::Stream &stream, const pdef::proto::PotionTypeRecipes &obj);
size_t PotionContainerChangeRecipes(pdef::Stream &stream, const pdef::proto::PotionContainerChangeRecipes &obj);
size_t Recipes(pdef::Stream &stream, const pdef::proto::Recipes &obj);
size_t SkinImage(pdef::Stream &stream, const pdef::proto::SkinImage &obj);
size_t Skin(pdef::Stream &stream, const pdef::proto::Skin &obj);
size_t PlayerRecords(pdef::Stream &stream, const pdef::proto::PlayerRecords &obj);
size_t Enchant(pdef::Stream &stream, const pdef::proto::Enchant &obj);
size_t EnchantOption(pdef::Stream &stream, const pdef::proto::EnchantOption &obj);
size_t StackRequestSlotInfo(pdef::Stream &stream, const pdef::proto::StackRequestSlotInfo &obj);
size_t ItemStackRequest(pdef::Stream &stream, const pdef::proto::ItemStackRequest &obj);
size_t ItemStackResponses(pdef::Stream &stream, const pdef::proto::ItemStackResponses &obj);
size_t ItemComponentList(pdef::Stream &stream, const pdef::proto::ItemComponentList &obj);
size_t CommandOrigin(pdef::Stream &stream, const pdef::proto::CommandOrigin &obj);
size_t TrackedObject(pdef::Stream &stream, const pdef::proto::TrackedObject &obj);
size_t MapDecoration(pdef::Stream &stream, const pdef::proto::MapDecoration &obj);
size_t StructureBlockSettings(pdef::Stream &stream, const pdef::proto::StructureBlockSettings &obj);
size_t EducationSharedResourceURI(pdef::Stream &stream, const pdef::proto::EducationSharedResourceURI &obj);
size_t EducationExternalLinkSettings(pdef::Stream &stream, const pdef::proto::EducationExternalLinkSettings &obj);
size_t BlockUpdate(pdef::Stream &stream, const pdef::proto::BlockUpdate &obj);
size_t MaterialReducer(pdef::Stream &stream, const pdef::proto::MaterialReducer &obj);
size_t packet_login(pdef::Stream &stream, const pdef::proto::packet_login &obj);
size_t LoginTokens(pdef::Stream &stream, const pdef::proto::LoginTokens &obj);
size_t packet_play_status(pdef::Stream &stream, const pdef::proto::packet_play_status &obj);
size_t packet_server_to_client_handshake(pdef::Stream &stream, const pdef::proto::packet_server_to_client_handshake &obj);
size_t packet_client_to_server_handshake(pdef::Stream &stream, const pdef::proto::packet_client_to_server_handshake &obj);
size_t packet_disconnect(pdef::Stream &stream, const pdef::proto::packet_disconnect &obj);
size_t packet_resource_packs_info(pdef::Stream &stream, const pdef::proto::packet_resource_packs_info &obj);
size_t packet_resource_pack_stack(pdef::Stream &stream, const pdef::proto::packet_resource_pack_stack &obj);
size_t packet_resource_pack_client_response(pdef::Stream &stream, const pdef::proto::packet_resource_pack_client_response &obj);
size_t packet_text(pdef::Stream &stream, const pdef::proto::packet_text &obj);
size_t packet_set_time(pdef::Stream &stream, const pdef::proto::packet_set_time &obj);
size_t packet_start_game(pdef::Stream &stream, const pdef::proto::packet_start_game &obj);
size_t packet_add_player(pdef::Stream &stream, const pdef::proto::packet_add_player &obj);
size_t packet_add_entity(pdef::Stream &stream, const pdef::proto::packet_add_entity &obj);
size_t packet_remove_entity(pdef::Stream &stream, const pdef::proto::packet_remove_entity &obj);
size_t packet_add_item_entity(pdef::Stream &stream, const pdef::proto::packet_add_item_entity &obj);
size_t packet_take_item_entity(pdef::Stream &stream, const pdef::proto::packet_take_item_entity &obj);
size_t packet_move_entity(pdef::Stream &stream, const pdef::proto::packet_move_entity &obj);
size_t packet_move_player(pdef::Stream &stream, const pdef::proto::packet_move_player &obj);
size_t packet_rider_jump(pdef::Stream &stream, const pdef::proto::packet_rider_jump &obj);
size_t packet_update_block(pdef::Stream &stream, const pdef::proto::packet_update_block &obj);
size_t packet_add_painting(pdef::Stream &stream, const pdef::proto::packet_add_painting &obj);
size_t packet_tick_sync(pdef::Stream &stream, const pdef::proto::packet_tick_sync &obj);
size_t packet_level_sound_event_old(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_old &obj);
size_t packet_level_event(pdef::Stream &stream, const pdef::proto::packet_level_event &obj);
size_t packet_block_event(pdef::Stream &stream, const pdef::proto::packet_block_event &obj);
size_t packet_entity_event(pdef::Stream &stream, const pdef::proto::packet_entity_event &obj);
size_t packet_mob_effect(pdef::Stream &stream, const pdef::proto::packet_mob_effect &obj);
size_t packet_update_attributes(pdef::Stream &stream, const pdef::proto::packet_update_attributes &obj);
size_t packet_inventory_transaction(pdef::Stream &stream, const pdef::proto::packet_inventory_transaction &obj);
size_t packet_mob_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_equipment &obj);
size_t packet_mob_armor_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_armor_equipment &obj);
size_t packet_interact(pdef::Stream &stream, const pdef::proto::packet_interact &obj);
size_t packet_block_pick_request(pdef::Stream &stream, const pdef::proto::packet_block_pick_request &obj);
size_t packet_entity_pick_request(pdef::Stream &stream, const pdef::proto::packet_entity_pick_request &obj);
size_t packet_player_action(pdef::Stream &stream, const pdef::proto::packet_player_action &obj);
size_t packet_hurt_armor(pdef::Stream &stream, const pdef::proto::packet_hurt_armor &obj);
size_t packet_set_entity_data(pdef::Stream &stream, const pdef::proto::packet_set_entity_data &obj);
size_t packet_set_entity_motion(pdef::Stream &stream, const pdef::proto::packet_set_entity_motion &obj);
size_t packet_set_entity_link(pdef::Stream &stream, const pdef::proto::packet_set_entity_link &obj);
size_t packet_set_health(pdef::Stream &stream, const pdef::proto::packet_set_health &obj);
size_t packet_set_spawn_position(pdef::Stream &stream, const pdef::proto::packet_set_spawn_position &obj);
size_t packet_animate(pdef::Stream &stream, const pdef::proto::packet_animate &obj);
size_t packet_respawn(pdef::Stream &stream, const pdef::proto::packet_respawn &obj);
size_t packet_container_open(pdef::Stream &stream, const pdef::proto::packet_container_open &obj);
size_t packet_container_close(pdef::Stream &stream, const pdef::proto::packet_container_close &obj);
size_t packet_player_hotbar(pdef::Stream &stream, const pdef::proto::packet_player_hotbar &obj);
size_t packet_inventory_content(pdef::Stream &stream, const pdef::proto::packet_inventory_content &obj);
size_t packet_inventory_slot(pdef::Stream &stream, const pdef::proto::packet_inventory_slot &obj);
size_t packet_container_set_data(pdef::Stream &stream, const pdef::proto::packet_container_set_data &obj);
size_t packet_crafting_data(pdef::Stream &stream, const pdef::proto::packet_crafting_data &obj);
size_t packet_crafting_event(pdef::Stream &stream, const pdef::proto::packet_crafting_event &obj);
size_t packet_gui_data_pick_item(pdef::Stream &stream, const pdef::proto::packet_gui_data_pick_item &obj);
size_t packet_adventure_settings(pdef::Stream &stream, const pdef::proto::packet_adventure_settings &obj);
size_t packet_block_entity_data(pdef::Stream &stream, const pdef::proto::packet_block_entity_data &obj);
size_t packet_player_input(pdef::Stream &stream, const pdef::proto::packet_player_input &obj);
size_t packet_level_chunk(pdef::Stream &stream, const pdef::proto::packet_level_chunk &obj);
size_t packet_set_commands_enabled(pdef::Stream &stream, const pdef::proto::packet_set_commands_enabled &obj);
size_t packet_set_difficulty(pdef::Stream &stream, const pdef::proto::packet_set_difficulty &obj);
size_t packet_change_dimension(pdef::Stream &stream, const pdef::proto::packet_change_dimension &obj);
size_t packet_set_player_game_type(pdef::Stream &stream, const pdef::proto::packet_set_player_game_type &obj);
size_t packet_player_list(pdef::Stream &stream, const pdef::proto::packet_player_list &obj);
size_t packet_simple_event(pdef::Stream &stream, const pdef::proto::packet_simple_event &obj);
size_t packet_event(pdef::Stream &stream, const pdef::proto::packet_event &obj);
size_t packet_spawn_experience_orb(pdef::Stream &stream, const pdef::proto::packet_spawn_experience_orb &obj);
size_t packet_clientbound_map_item_data(pdef::Stream &stream, const pdef::proto::packet_clientbound_map_item_data &obj);
size_t packet_map_info_request(pdef::Stream &stream, const pdef::proto::packet_map_info_request &obj);
size_t packet_request_chunk_radius(pdef::Stream &stream, const pdef::proto::packet_request_chunk_radius &obj);
size_t packet_chunk_radius_update(pdef::Stream &stream, const pdef::proto::packet_chunk_radius_update &obj);
size_t packet_item_frame_drop_item(pdef::Stream &stream, const pdef::proto::packet_item_frame_drop_item &obj);
size_t packet_game_rules_changed(pdef::Stream &stream, const pdef::proto::packet_game_rules_changed &obj);
size_t packet_camera(pdef::Stream &stream, const pdef::proto::packet_camera &obj);
size_t packet_boss_event(pdef::Stream &stream, const pdef::proto::packet_boss_event &obj);
size_t packet_show_credits(pdef::Stream &stream, const pdef::proto::packet_show_credits &obj);
size_t packet_available_commands(pdef::Stream &stream, const pdef::proto::packet_available_commands &obj);
size_t packet_command_request(pdef::Stream &stream, const pdef::proto::packet_command_request &obj);
size_t packet_command_block_update(pdef::Stream &stream, const pdef::proto::packet_command_block_update &obj);
size_t packet_command_output(pdef::Stream &stream, const pdef::proto::packet_command_output &obj);
size_t packet_update_trade(pdef::Stream &stream, const pdef::proto::packet_update_trade &obj);
size_t packet_update_equipment(pdef::Stream &stream, const pdef::proto::packet_update_equipment &obj);
size_t packet_resource_pack_data_info(pdef::Stream &stream, const pdef::proto::packet_resource_pack_data_info &obj);
size_t packet_resource_pack_chunk_data(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_data &obj);
size_t packet_resource_pack_chunk_request(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_request &obj);
size_t packet_transfer(pdef::Stream &stream, const pdef::proto::packet_transfer &obj);
size_t packet_play_sound(pdef::Stream &stream, const pdef::proto::packet_play_sound &obj);
size_t packet_stop_sound(pdef::Stream &stream, const pdef::proto::packet_stop_sound &obj);
size_t packet_set_title(pdef::Stream &stream, const pdef::proto::packet_set_title &obj);
size_t packet_add_behavior_tree(pdef::Stream &stream, const pdef::proto::packet_add_behavior_tree &obj);
size_t packet_structure_block_update(pdef::Stream &stream, const pdef::proto::packet_structure_block_update &obj);
size_t packet_show_store_offer(pdef::Stream &stream, const pdef::proto::packet_show_store_offer &obj);
size_t packet_purchase_receipt(pdef::Stream &stream, const pdef::proto::packet_purchase_receipt &obj);
size_t packet_player_skin(pdef::Stream &stream, const pdef::proto::packet_player_skin &obj);
size_t packet_sub_client_login(pdef::Stream &stream, const pdef::proto::packet_sub_client_login &obj);
size_t packet_initiate_web_socket_connection(pdef::Stream &stream, const pdef::proto::packet_initiate_web_socket_connection &obj);
size_t packet_set_last_hurt_by(pdef::Stream &stream, const pdef::proto::packet_set_last_hurt_by &obj);
size_t packet_book_edit(pdef::Stream &stream, const pdef::proto::packet_book_edit &obj);
size_t packet_npc_request(pdef::Stream &stream, const pdef::proto::packet_npc_request &obj);
size_t packet_photo_transfer(pdef::Stream &stream, const pdef::proto::packet_photo_transfer &obj);
size_t packet_modal_form_request(pdef::Stream &stream, const pdef::proto::packet_modal_form_request &obj);
size_t packet_modal_form_response(pdef::Stream &stream, const pdef::proto::packet_modal_form_response &obj);
size_t packet_server_settings_request(pdef::Stream &stream, const pdef::proto::packet_server_settings_request &obj);
size_t packet_server_settings_response(pdef::Stream &stream, const pdef::proto::packet_server_settings_response &obj);
size_t packet_show_profile(pdef::Stream &stream, const pdef::proto::packet_show_profile &obj);
size_t packet_set_default_game_type(pdef::Stream &stream, const pdef::proto::packet_set_default_game_type &obj);
size_t packet_remove_objective(pdef::Stream &stream, const pdef::proto::packet_remove_objective &obj);
size_t packet_set_display_objective(pdef::Stream &stream, const pdef::proto::packet_set_display_objective &obj);
size_t packet_set_score(pdef::Stream &stream, const pdef::proto::packet_set_score &obj);
size_t packet_lab_table(pdef::Stream &stream, const pdef::proto::packet_lab_table &obj);
size_t packet_update_block_synced(pdef::Stream &stream, const pdef::proto::packet_update_block_synced &obj);
size_t packet_move_entity_delta(pdef::Stream &stream, const pdef::proto::packet_move_entity_delta &obj);
size_t packet_set_scoreboard_identity(pdef::Stream &stream, const pdef::proto::packet_set_scoreboard_identity &obj);
size_t packet_set_local_player_as_initialized(pdef::Stream &stream, const pdef::proto::packet_set_local_player_as_initialized &obj);
size_t packet_update_soft_enum(pdef::Stream &stream, const pdef::proto::packet_update_soft_enum &obj);
size_t packet_network_stack_latency(pdef::Stream &stream, const pdef::proto::packet_network_stack_latency &obj);
size_t packet_script_custom_event(pdef::Stream &stream, const pdef::proto::packet_script_custom_event &obj);
size_t packet_spawn_particle_effect(pdef::Stream &stream, const pdef::proto::packet_spawn_particle_effect &obj);
size_t packet_available_entity_identifiers(pdef::Stream &stream, const pdef::proto::packet_available_entity_identifiers &obj);
size_t packet_level_sound_event_v2(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_v2 &obj);
size_t packet_network_chunk_publisher_update(pdef::Stream &stream, const pdef::proto::packet_network_chunk_publisher_update &obj);
size_t packet_biome_definition_list(pdef::Stream &stream, const pdef::proto::packet_biome_definition_list &obj);
size_t packet_level_sound_event(pdef::Stream &stream, const pdef::proto::packet_level_sound_event &obj);
size_t packet_level_event_generic(pdef::Stream &stream, const pdef::proto::packet_level_event_generic &obj);
size_t packet_lectern_update(pdef::Stream &stream, const pdef::proto::packet_lectern_update &obj);
size_t packet_video_stream_connect(pdef::Stream &stream, const pdef::proto::packet_video_stream_connect &obj);
size_t packet_add_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_add_ecs_entity &obj);
size_t packet_remove_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_remove_ecs_entity &obj);
size_t packet_client_cache_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_status &obj);
size_t packet_on_screen_texture_animation(pdef::Stream &stream, const pdef::proto::packet_on_screen_texture_animation &obj);
size_t packet_map_create_locked_copy(pdef::Stream &stream, const pdef::proto::packet_map_create_locked_copy &obj);
size_t packet_structure_template_data_export_request(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_request &obj);
size_t packet_structure_template_data_export_response(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_response &obj);
size_t packet_update_block_properties(pdef::Stream &stream, const pdef::proto::packet_update_block_properties &obj);
size_t packet_client_cache_blob_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_blob_status &obj);
size_t packet_client_cache_miss_response(pdef::Stream &stream, const pdef::proto::packet_client_cache_miss_response &obj);
size_t packet_education_settings(pdef::Stream &stream, const pdef::proto::packet_education_settings &obj);
size_t packet_emote(pdef::Stream &stream, const pdef::proto::packet_emote &obj);
size_t packet_multiplayer_settings(pdef::Stream &stream, const pdef::proto::packet_multiplayer_settings &obj);
size_t packet_settings_command(pdef::Stream &stream, const pdef::proto::packet_settings_command &obj);
size_t packet_anvil_damage(pdef::Stream &stream, const pdef::proto::packet_anvil_damage &obj);
size_t packet_completed_using_item(pdef::Stream &stream, const pdef::proto::packet_completed_using_item &obj);
size_t packet_network_settings(pdef::Stream &stream, const pdef::proto::packet_network_settings &obj);
size_t packet_player_auth_input(pdef::Stream &stream, const pdef::proto::packet_player_auth_input &obj);
size_t packet_creative_content(pdef::Stream &stream, const pdef::proto::packet_creative_content &obj);
size_t packet_player_enchant_options(pdef::Stream &stream, const pdef::proto::packet_player_enchant_options &obj);
size_t packet_item_stack_request(pdef::Stream &stream, const pdef::proto::packet_item_stack_request &obj);
size_t packet_item_stack_response(pdef::Stream &stream, const pdef::proto::packet_item_stack_response &obj);
size_t packet_player_armor_damage(pdef::Stream &stream, const pdef::proto::packet_player_armor_damage &obj);
size_t packet_update_player_game_type(pdef::Stream &stream, const pdef::proto::packet_update_player_game_type &obj);
size_t packet_emote_list(pdef::Stream &stream, const pdef::proto::packet_emote_list &obj);
size_t packet_position_tracking_db_request(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_request &obj);
size_t packet_position_tracking_db_broadcast(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_broadcast &obj);
size_t packet_packet_violation_warning(pdef::Stream &stream, const pdef::proto::packet_packet_violation_warning &obj);
size_t packet_motion_prediction_hints(pdef::Stream &stream, const pdef::proto::packet_motion_prediction_hints &obj);
size_t packet_animate_entity(pdef::Stream &stream, const pdef::proto::packet_animate_entity &obj);
size_t packet_camera_shake(pdef::Stream &stream, const pdef::proto::packet_camera_shake &obj);
size_t packet_player_fog(pdef::Stream &stream, const pdef::proto::packet_player_fog &obj);
size_t packet_correct_player_move_prediction(pdef::Stream &stream, const pdef::proto::packet_correct_player_move_prediction &obj);
size_t packet_item_component(pdef::Stream &stream, const pdef::proto::packet_item_component &obj);
size_t packet_filter_text_packet(pdef::Stream &stream, const pdef::proto::packet_filter_text_packet &obj);
size_t packet_debug_renderer(pdef::Stream &stream, const pdef::proto::packet_debug_renderer &obj);
size_t packet_sync_entity_property(pdef::Stream &stream, const pdef::proto::packet_sync_entity_property &obj);
size_t packet_add_volume_entity(pdef::Stream &stream, const pdef::proto::packet_add_volume_entity &obj);
size_t packet_remove_volume_entity(pdef::Stream &stream, const pdef::proto::packet_remove_volume_entity &obj);
size_t packet_simulation_type(pdef::Stream &stream, const pdef::proto::packet_simulation_type &obj);
size_t packet_npc_dialogue(pdef::Stream &stream, const pdef::proto::packet_npc_dialogue &obj);
size_t packet_edu_uri_resource_packet(pdef::Stream &stream, const pdef::proto::packet_edu_uri_resource_packet &obj);
size_t packet_create_photo(pdef::Stream &stream, const pdef::proto::packet_create_photo &obj);
size_t packet_update_subchunk_blocks(pdef::Stream &stream, const pdef::proto::packet_update_subchunk_blocks &obj);
size_t packet_photo_info_request(pdef::Stream &stream, const pdef::proto::packet_photo_info_request &obj);
size_t SubChunkEntryWithoutCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithoutCaching &obj);
size_t SubChunkEntryWithCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithCaching &obj);
size_t packet_subchunk(pdef::Stream &stream, const pdef::proto::packet_subchunk &obj);
size_t packet_subchunk_request(pdef::Stream &stream, const pdef::proto::packet_subchunk_request &obj);
size_t packet_client_start_item_cooldown(pdef::Stream &stream, const pdef::proto::packet_client_start_item_cooldown &obj);
size_t packet_script_message(pdef::Stream &stream, const pdef::proto::packet_script_message &obj);
size_t packet_code_builder_source(pdef::Stream &stream, const pdef::proto::packet_code_builder_source &obj);
size_t packet_ticking_areas_load_status(pdef::Stream &stream, const pdef::proto::packet_ticking_areas_load_status &obj);
size_t packet_dimension_data(pdef::Stream &stream, const pdef::proto::packet_dimension_data &obj);
size_t packet_agent_action(pdef::Stream &stream, const pdef::proto::packet_agent_action &obj);
size_t packet_change_mob_property(pdef::Stream &stream, const pdef::proto::packet_change_mob_property &obj);
size_t packet_lesson_progress(pdef::Stream &stream, const pdef::proto::packet_lesson_progress &obj);
size_t packet_request_ability(pdef::Stream &stream, const pdef::proto::packet_request_ability &obj);
size_t packet_request_permissions(pdef::Stream &stream, const pdef::proto::packet_request_permissions &obj);
size_t packet_toast_request(pdef::Stream &stream, const pdef::proto::packet_toast_request &obj);
size_t mcpe_packet(pdef::Stream &stream, const pdef::proto::mcpe_packet &obj);
size_t BehaviourPackInfos(pdef::Stream &stream, const pdef::proto::BehaviourPackInfos &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.uuid.length());
    len += obj.uuid.length(); /*uuid: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.version.length());
    len += obj.version.length(); /*version: pstring*/ /*4.1*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.content_key.length());
    len += obj.content_key.length(); /*content_key: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.sub_pack_name.length());
    len += obj.sub_pack_name.length(); /*sub_pack_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.content_identity.length());
    len += obj.content_identity.length(); /*content_identity: pstring*/ /*4.1*/
    len += 1; /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
size_t TexturePackInfos(pdef::Stream &stream, const pdef::proto::TexturePackInfos &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.uuid.length());
    len += obj.uuid.length(); /*uuid: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.version.length());
    len += obj.version.length(); /*version: pstring*/ /*4.1*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.content_key.length());
    len += obj.content_key.length(); /*content_key: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.sub_pack_name.length());
    len += obj.sub_pack_name.length(); /*sub_pack_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.content_identity.length());
    len += obj.content_identity.length(); /*content_identity: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
size_t ResourcePackIdVersions(pdef::Stream &stream, const pdef::proto::ResourcePackIdVersions &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.uuid.length());
    len += obj.uuid.length(); /*uuid: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.version.length());
    len += obj.version.length(); /*version: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t Experiment(pdef::Stream &stream, const pdef::proto::Experiment &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t GameRule(pdef::Stream &stream, const pdef::proto::GameRule &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    const pdef::proto::GameRule::Type &type = obj.type; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.type); /*type^: varint*/ /*7.0*/
    switch (type) { /*8.0*/
      case pdef::proto::GameRule::Type::Bool: { /*8.5*/
        len += 1; /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::GameRule::Type::Int: { /*8.5*/
        len += stream.sizeOfZigZagVarInt(obj.value_zigzag32); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::GameRule::Type::Float: { /*8.5*/
        len += 4; /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t Blob(pdef::Stream &stream, const pdef::proto::Blob &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.payload.size());
    len += obj.payload.size(); /*payload: buffer*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t BlockProperties(pdef::Stream &stream, const pdef::proto::BlockProperties &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
size_t Itemstates(pdef::Stream &stream, const pdef::proto::Itemstates &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 2; /*0.2*/
    len += 1; /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t ItemExtraDataWithBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithBlockingTick &obj) {
    size_t len = 0;
    const pdef::proto::ItemExtraDataWithBlockingTick::HasNbt &has_nbt = obj.has_nbt; /*0.3*/
    len += 2; /*has_nbt^: lu16*/ /*7.0*/
    switch (has_nbt) { /*8.0*/
      case pdef::proto::ItemExtraDataWithBlockingTick::HasNbt::True: { /*8.5*/
        EXPECT_OR_BAIL(obj.nbt); const pdef::proto::ItemExtraDataWithBlockingTick::Nbt &v = *obj.nbt; /*8.6*/
          len += 1; /*0.2*/
          len += 1; /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    len += 4; /*1.3*/
    for (const auto &v2 : obj.can_place_on) {
      len += 2;
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += 4; /*1.3*/
    for (const auto &v2 : obj.can_destroy) {
      len += 2;
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t ItemExtraDataWithoutBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithoutBlockingTick &obj) {
    size_t len = 0;
    const pdef::proto::ItemExtraDataWithoutBlockingTick::HasNbt &has_nbt = obj.has_nbt; /*0.3*/
    len += 2; /*has_nbt^: lu16*/ /*7.0*/
    switch (has_nbt) { /*8.0*/
      case pdef::proto::ItemExtraDataWithoutBlockingTick::HasNbt::True: { /*8.5*/
        EXPECT_OR_BAIL(obj.nbt); const pdef::proto::ItemExtraDataWithoutBlockingTick::Nbt &v = *obj.nbt; /*8.6*/
          len += 1; /*0.2*/
          len += 1; /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    len += 4; /*1.3*/
    for (const auto &v2 : obj.can_place_on) {
      len += 2;
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += 4; /*1.3*/
    for (const auto &v2 : obj.can_destroy) {
      len += 2;
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t ItemLegacy(pdef::Stream &stream, const pdef::proto::ItemLegacy &obj) {
    size_t len = 0;
    const int &network_id = obj.network_id; /*0.1*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        len += 2; /*0.2*/
        len += stream.sizeOfVarInt(obj.metadata); /*0.2*/
        len += stream.sizeOfZigZagVarInt(obj.block_runtime_id); /*0.2*/
        if (network_id == pdef::proto::ShieldItemID) { /*8.4*/
          len += 1; /*0.2*/
        }
        else {
          len += 1; /*0.2*/
        }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t Item(pdef::Stream &stream, const pdef::proto::Item &obj) {
    size_t len = 0;
    const int &network_id = obj.network_id; /*0.1*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        len += 2; /*0.2*/
        len += stream.sizeOfVarInt(obj.metadata); /*0.2*/
        const uint8_t &has_stack_id = obj.has_stack_id; /*0.1*/
        if (has_stack_id == 0) { /*8.2*/
        }
        else {
          len += stream.sizeOfZigZagVarInt(obj.stack_id); /*0.2*/
        }
        len += stream.sizeOfZigZagVarInt(obj.block_runtime_id); /*0.2*/
        if (network_id == pdef::proto::ShieldItemID) { /*8.4*/
          len += 1; /*0.2*/
        }
        else {
          len += 1; /*0.2*/
        }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t vec3i(pdef::Stream &stream, const pdef::proto::vec3i &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.x); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.y); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.z); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t vec3u(pdef::Stream &stream, const pdef::proto::vec3u &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.x); /*0.2*/
    len += stream.sizeOfVarInt(obj.y); /*0.2*/
    len += stream.sizeOfVarInt(obj.z); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t vec3f(pdef::Stream &stream, const pdef::proto::vec3f &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t vec2f(pdef::Stream &stream, const pdef::proto::vec2f &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t MetadataDictionary(pdef::Stream &stream, const pdef::proto::MetadataDictionary &obj) {
  size_t len = 0;
    const pdef::proto::MetadataDictionary::Key &key = obj.key; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.key); /*key^: varint*/ /*7.0*/
    const pdef::proto::MetadataDictionary::Type &type = obj.type; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.type); /*type^: varint*/ /*7.0*/
    switch (key) { /*8.0*/
      case pdef::proto::MetadataDictionary::Key::Flags: { /*8.5*/
        int64_t value_MetadataFlags1_val = 0; /*X*/
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.onfire << 0;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sneaking << 1;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.riding << 2;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sprinting << 3;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.action << 4;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.invisible << 5;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.tempted << 6;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.inlove << 7;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.saddled << 8;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.powered << 9;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.ignited << 10;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.baby << 11;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.converting << 12;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.critical << 13;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_show_nametag << 14;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.always_show_nametag << 15;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.no_ai << 16;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.silent << 17;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.wallclimbing << 18;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_climb << 19;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.swimmer << 20;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_fly << 21;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.walker << 22;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.resting << 23;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sitting << 24;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.angry << 25;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.interested << 26;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.charged << 27;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.tamed << 28;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.orphaned << 29;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.leashed << 30;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sheared << 31;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.gliding << 32;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.elder << 33;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.moving << 34;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.breathing << 35;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.chested << 36;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.stackable << 37;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.showbase << 38;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.rearing << 39;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.vibrating << 40;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.idling << 41;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.evoker_spell << 42;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.charge_attack << 43;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.wasd_controlled << 44;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_power_jump << 45;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.linger << 46;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.has_collision << 47;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.affected_by_gravity << 48;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.fire_immune << 49;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.dancing << 50;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.enchanted << 51;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.show_trident_rope << 52;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.container_private << 53;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.transforming << 54;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.spin_attack << 55;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.swimming << 56;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.bribed << 57;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.pregnant << 58;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.laying_egg << 59;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.rider_can_pick << 60;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.transition_sitting << 61;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.eating << 62;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.laying_down << 63;
        len += stream.sizeOfZigZagVarLong(value_MetadataFlags1_val); /*value: bitflags*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::MetadataDictionary::Key::FlagsExtended: { /*8.5*/
        int64_t value_MetadataFlags2_val = 0; /*X*/
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.sneezing << 0;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.trusting << 1;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.rolling << 2;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.scared << 3;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.in_scaffolding << 4;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.over_scaffolding << 5;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.fall_through_scaffolding << 6;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.blocking << 7;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.transition_blocking << 8;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.blocked_using_shield << 9;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.blocked_using_damaged_shield << 10;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.sleeping << 11;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.wants_to_wake << 12;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.trade_interest << 13;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.door_breaker << 14;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.breaking_obstruction << 15;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.door_opener << 16;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.illager_captain << 17;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.stunned << 18;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.roaring << 19;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.delayed_attacking << 20;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.avoiding_mobs << 21;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.avoiding_block << 22;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.facing_target_to_range_attack << 23;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.hidden_when_invisible << 24;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.is_in_ui << 25;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.stalking << 26;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.emoting << 27;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.celebrating << 28;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.admiring << 29;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.celebrating_special << 30;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.unknown95 << 31;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.ram_attack << 32;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.playing_dead << 33;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.in_ascendable_block << 34;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.over_descendable_block << 35;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.croaking << 36;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.eat_mob << 37;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.jump_goal_jump << 38;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.emerging << 39;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.sniffing << 40;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.digging << 41;
        len += stream.sizeOfZigZagVarLong(value_MetadataFlags2_val); /*value: bitflags*/ /*4.1*/
        break;
      } /*8.7*/
      default: { /*8.3*/
        switch (type) { /*8.0*/
          case pdef::proto::MetadataDictionary::Type::Byte: { /*8.5*/
            len += 1; /*0.2*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Short: { /*8.5*/
            len += 2; /*0.2*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Int: { /*8.5*/
            len += stream.sizeOfZigZagVarInt(obj.value_zigzag32); /*0.2*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Float: { /*8.5*/
            len += 4; /*0.2*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::String: { /*8.5*/
            len += stream.sizeOfVarInt(obj.value_string.length());
            len += obj.value_string.length(); /*value: pstring*/ /*4.1*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Compound: { /*8.5*/
            len += 1; /*0.2*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Vec3i: { /*8.5*/
            EXPECT_OR_BAIL(obj.value_vec3i); size_t len_0 = pdef::proto::size::vec3i(stream, *obj.value_vec3i); EXPECT_OR_BAIL(len_0); len += len_0; /*value_vec3i*/ /*4.4*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Long: { /*8.5*/
            len += stream.sizeOfZigZagVarLong(obj.value_zigzag64); /*0.2*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Vec3f: { /*8.5*/
            EXPECT_OR_BAIL(obj.value_vec3f); size_t len_1 = pdef::proto::size::vec3f(stream, *obj.value_vec3f); EXPECT_OR_BAIL(len_1); len += len_1; /*value_vec3f*/ /*4.4*/
            break;
          } /*8.7*/
          default: break; /*avoid unhandled case warning*/
        } /*8.8*/
        break;
      } /*8.7*/
    } /*8.8*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t Link(pdef::Stream &stream, const pdef::proto::Link &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.ridden_entity_id); /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.rider_entity_id); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t EntityAttributes(pdef::Stream &stream, const pdef::proto::EntityAttributes &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t Rotation(pdef::Stream &stream, const pdef::proto::Rotation &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t BlockCoordinates(pdef::Stream &stream, const pdef::proto::BlockCoordinates &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.x); /*0.2*/
    len += stream.sizeOfVarInt(obj.y); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.z); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t PlayerAttributes(pdef::Stream &stream, const pdef::proto::PlayerAttributes &obj) {
  size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t TransactionUseItem(pdef::Stream &stream, const pdef::proto::TransactionUseItem &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt((int&)obj.action_type); /*action_type: varint*/ /*7.0*/
    size_t len_2 = pdef::proto::size::BlockCoordinates(stream, obj.block_position); EXPECT_OR_BAIL(len_2); len += len_2; /*block_position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.face); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.hotbar_slot); /*0.2*/
    size_t len_3 = pdef::proto::size::Item(stream, obj.held_item); EXPECT_OR_BAIL(len_3); len += len_3; /*held_item*/ /*4.4*/
    size_t len_4 = pdef::proto::size::vec3f(stream, obj.player_pos); EXPECT_OR_BAIL(len_4); len += len_4; /*player_pos*/ /*4.4*/
    size_t len_5 = pdef::proto::size::vec3f(stream, obj.click_pos); EXPECT_OR_BAIL(len_5); len += len_5; /*click_pos*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.block_runtime_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t TransactionActions(pdef::Stream &stream, const pdef::proto::TransactionActions &obj) {
  size_t len = 0;
    const pdef::proto::TransactionActions::SourceType &source_type = obj.source_type; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.source_type); /*source_type^: varint*/ /*7.0*/
    switch (source_type) { /*8.0*/
      case pdef::proto::TransactionActions::SourceType::Container: { /*8.5*/
          len += stream.sizeOfVarInt((int&)obj.inventory_id); /*inventory_id: varint*/ /*7.0*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::Craft: { /*8.5*/
          len += stream.sizeOfVarInt(obj.action); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::WorldInteraction: { /*8.5*/
          len += stream.sizeOfVarInt(obj.flags); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::CraftSlot: { /*8.5*/
          len += stream.sizeOfVarInt(obj.action); /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    len += stream.sizeOfVarInt(obj.slot); /*0.2*/
    size_t len_6 = pdef::proto::size::Item(stream, obj.old_item); EXPECT_OR_BAIL(len_6); len += len_6; /*old_item*/ /*4.4*/
    size_t len_7 = pdef::proto::size::Item(stream, obj.new_item); EXPECT_OR_BAIL(len_7); len += len_7; /*new_item*/ /*4.4*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t TransactionLegacy(pdef::Stream &stream, const pdef::proto::TransactionLegacy &obj) {
    size_t len = 0;
    const int &legacy_request_id = obj.legacy_request_id; /*0.1*/
    if (legacy_request_id == 0) { /*8.2*/
    }
    else {
      len += stream.sizeOfVarInt(obj.legacy_transactions.size()); /*1.3*/
      for (const auto &v3 : obj.legacy_transactions) { /*5.20*/
        len += 1; /*0.2*/
        len += stream.sizeOfVarInt(v3.changed_slots.size()); /*1.3*/
        for (const auto &v4 : v3.changed_slots) { /*5.20*/
          len += 1; /*0.2*/
        }
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t Transaction(pdef::Stream &stream, const pdef::proto::Transaction &obj) {
    size_t len = 0;
    size_t len_8 = pdef::proto::size::TransactionLegacy(stream, obj.legacy); EXPECT_OR_BAIL(len_8); len += len_8; /*legacy*/ /*4.4*/
    const pdef::proto::Transaction::TransactionType &transaction_type = obj.transaction_type; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.transaction_type); /*transaction_type^: varint*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.actions.size()); /*2.4*/
    for (const auto &v : obj.actions) { size_t len_9 = pdef::proto::size::TransactionActions(stream, v); EXPECT_OR_BAIL(len_9); len += len_9; } /*2.5*/
    switch (transaction_type) { /*8.0*/
      case pdef::proto::Transaction::TransactionType::Normal: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::InventoryMismatch: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemUse: { /*8.5*/
        EXPECT_OR_BAIL(obj.transaction_data_TransactionUseItem); size_t len_10 = pdef::proto::size::TransactionUseItem(stream, *obj.transaction_data_TransactionUseItem); EXPECT_OR_BAIL(len_10); len += len_10; /*transaction_data_TransactionUseItem*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemUseOnEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.transaction_data_item_use_on_entity); const pdef::proto::Transaction::TransactionDataItemUseOnEntity &v = *obj.transaction_data_item_use_on_entity; /*8.6*/
          len += stream.sizeOfVarInt64(v.entity_runtime_id); /*0.2*/
          len += stream.sizeOfVarInt((int&)v.action_type); /*action_type: varint*/ /*7.0*/
          len += stream.sizeOfZigZagVarInt(v.hotbar_slot); /*0.2*/
          size_t len_11 = pdef::proto::size::Item(stream, v.held_item); EXPECT_OR_BAIL(len_11); len += len_11; /*held_item*/ /*4.4*/
          size_t len_12 = pdef::proto::size::vec3f(stream, v.player_pos); EXPECT_OR_BAIL(len_12); len += len_12; /*player_pos*/ /*4.4*/
          size_t len_13 = pdef::proto::size::vec3f(stream, v.click_pos); EXPECT_OR_BAIL(len_13); len += len_13; /*click_pos*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemRelease: { /*8.5*/
        EXPECT_OR_BAIL(obj.transaction_data_item_release); const pdef::proto::Transaction::TransactionDataItemRelease &v = *obj.transaction_data_item_release; /*8.6*/
          len += stream.sizeOfVarInt((int&)v.action_type); /*action_type: varint*/ /*7.0*/
          len += stream.sizeOfZigZagVarInt(v.hotbar_slot); /*0.2*/
          size_t len_14 = pdef::proto::size::Item(stream, v.held_item); EXPECT_OR_BAIL(len_14); len += len_14; /*held_item*/ /*4.4*/
          size_t len_15 = pdef::proto::size::vec3f(stream, v.head_pos); EXPECT_OR_BAIL(len_15); len += len_15; /*head_pos*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t RecipeIngredient(pdef::Stream &stream, const pdef::proto::RecipeIngredient &obj) {
    size_t len = 0;
    const int &network_id = obj.network_id; /*0.1*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        len += stream.sizeOfZigZagVarInt(obj.network_data); /*0.2*/
        len += stream.sizeOfZigZagVarInt(obj.count); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t PotionTypeRecipes(pdef::Stream &stream, const pdef::proto::PotionTypeRecipes &obj) {
  size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.input_item_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.input_item_meta); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.ingredient_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.ingredient_meta); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.output_item_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.output_item_meta); /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
size_t PotionContainerChangeRecipes(pdef::Stream &stream, const pdef::proto::PotionContainerChangeRecipes &obj) {
  size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.input_item_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.ingredient_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.output_item_id); /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
size_t Recipes(pdef::Stream &stream, const pdef::proto::Recipes &obj) {
  size_t len = 0;
    const pdef::proto::Recipes::Type &type = obj.type; /*0.3*/
    len += stream.sizeOfZigZagVarInt((int&)obj.type); /*type^: zigzag32*/ /*7.0*/
    switch (type) { /*8.0*/
      case pdef::proto::Recipes::Type::Shapeless: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry); const pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.6*/
          len += stream.sizeOfVarInt(v.recipe_id.length());
          len += v.recipe_id.length(); /*recipe_id: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v.input.size()); /*1.3*/
          for (const auto &v5 : v.input) {
            size_t len_16 = pdef::proto::size::RecipeIngredient(stream, v5); EXPECT_OR_BAIL(len_16); len += len_16; /**/ /*4.4*/
          }
          len += stream.sizeOfVarInt(v.output.size()); /*1.3*/
          for (const auto &v5 : v.output) {
            size_t len_17 = pdef::proto::size::ItemLegacy(stream, v5); EXPECT_OR_BAIL(len_17); len += len_17; /**/ /*4.4*/
          }
          len += 8; /*0.2*/
          len += stream.sizeOfVarInt(v.block.length());
          len += v.block.length(); /*block: pstring*/ /*4.1*/
          len += stream.sizeOfZigZagVarInt(v.priority); /*0.2*/
          len += stream.sizeOfVarInt(v.network_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShulkerBox: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry); const pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.6*/
          len += stream.sizeOfVarInt(v.recipe_id.length());
          len += v.recipe_id.length(); /*recipe_id: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v.input.size()); /*1.3*/
          for (const auto &v5 : v.input) {
            size_t len_18 = pdef::proto::size::RecipeIngredient(stream, v5); EXPECT_OR_BAIL(len_18); len += len_18; /**/ /*4.4*/
          }
          len += stream.sizeOfVarInt(v.output.size()); /*1.3*/
          for (const auto &v5 : v.output) {
            size_t len_19 = pdef::proto::size::ItemLegacy(stream, v5); EXPECT_OR_BAIL(len_19); len += len_19; /**/ /*4.4*/
          }
          len += 8; /*0.2*/
          len += stream.sizeOfVarInt(v.block.length());
          len += v.block.length(); /*block: pstring*/ /*4.1*/
          len += stream.sizeOfZigZagVarInt(v.priority); /*0.2*/
          len += stream.sizeOfVarInt(v.network_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShapelessChemistry: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry); const pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.6*/
          len += stream.sizeOfVarInt(v.recipe_id.length());
          len += v.recipe_id.length(); /*recipe_id: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v.input.size()); /*1.3*/
          for (const auto &v5 : v.input) {
            size_t len_20 = pdef::proto::size::RecipeIngredient(stream, v5); EXPECT_OR_BAIL(len_20); len += len_20; /**/ /*4.4*/
          }
          len += stream.sizeOfVarInt(v.output.size()); /*1.3*/
          for (const auto &v5 : v.output) {
            size_t len_21 = pdef::proto::size::ItemLegacy(stream, v5); EXPECT_OR_BAIL(len_21); len += len_21; /**/ /*4.4*/
          }
          len += 8; /*0.2*/
          len += stream.sizeOfVarInt(v.block.length());
          len += v.block.length(); /*block: pstring*/ /*4.1*/
          len += stream.sizeOfZigZagVarInt(v.priority); /*0.2*/
          len += stream.sizeOfVarInt(v.network_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Shaped: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_shaped_or_shaped_chemistry); const pdef::proto::Recipes::RecipeShapedOrShapedChemistry &v = *obj.recipe_shaped_or_shaped_chemistry; /*8.6*/
          len += stream.sizeOfVarInt(v.recipe_id.length());
          len += v.recipe_id.length(); /*recipe_id: pstring*/ /*4.1*/
          const int &width = v.width; /*0.1*/
          const int &height = v.height; /*0.1*/
          len += stream.sizeOfZigZagVarInt(width); /*1.1*/
          for (const auto &v : v.input) { /*5.1*/
            len += stream.sizeOfZigZagVarInt(height); /*5.3*/
            for (const auto &v : v) { /*5.10*/
              size_t len_22 = pdef::proto::size::RecipeIngredient(stream, v); EXPECT_OR_BAIL(len_22); len += len_22; /*5.12*/
            }
          }
          len += stream.sizeOfVarInt(v.output.size()); /*1.3*/
          for (const auto &v5 : v.output) {
            size_t len_23 = pdef::proto::size::ItemLegacy(stream, v5); EXPECT_OR_BAIL(len_23); len += len_23; /**/ /*4.4*/
          }
          len += 8; /*0.2*/
          len += stream.sizeOfVarInt(v.block.length());
          len += v.block.length(); /*block: pstring*/ /*4.1*/
          len += stream.sizeOfZigZagVarInt(v.priority); /*0.2*/
          len += stream.sizeOfVarInt(v.network_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShapedChemistry: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_shaped_or_shaped_chemistry); const pdef::proto::Recipes::RecipeShapedOrShapedChemistry &v = *obj.recipe_shaped_or_shaped_chemistry; /*8.6*/
          len += stream.sizeOfVarInt(v.recipe_id.length());
          len += v.recipe_id.length(); /*recipe_id: pstring*/ /*4.1*/
          const int &width = v.width; /*0.1*/
          const int &height = v.height; /*0.1*/
          len += stream.sizeOfZigZagVarInt(width); /*1.1*/
          for (const auto &v : v.input) { /*5.1*/
            len += stream.sizeOfZigZagVarInt(height); /*5.3*/
            for (const auto &v : v) { /*5.10*/
              size_t len_24 = pdef::proto::size::RecipeIngredient(stream, v); EXPECT_OR_BAIL(len_24); len += len_24; /*5.12*/
            }
          }
          len += stream.sizeOfVarInt(v.output.size()); /*1.3*/
          for (const auto &v5 : v.output) {
            size_t len_25 = pdef::proto::size::ItemLegacy(stream, v5); EXPECT_OR_BAIL(len_25); len += len_25; /**/ /*4.4*/
          }
          len += 8; /*0.2*/
          len += stream.sizeOfVarInt(v.block.length());
          len += v.block.length(); /*block: pstring*/ /*4.1*/
          len += stream.sizeOfZigZagVarInt(v.priority); /*0.2*/
          len += stream.sizeOfVarInt(v.network_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Furnace: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_furnace); const pdef::proto::Recipes::RecipeFurnace &v = *obj.recipe_furnace; /*8.6*/
          len += stream.sizeOfZigZagVarInt(v.input_id); /*0.2*/
          size_t len_26 = pdef::proto::size::ItemLegacy(stream, v.output); EXPECT_OR_BAIL(len_26); len += len_26; /*output*/ /*4.4*/
          len += stream.sizeOfVarInt(v.block.length());
          len += v.block.length(); /*block: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::FurnaceWithMetadata: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_furnace_with_metadata); const pdef::proto::Recipes::RecipeFurnaceWithMetadata &v = *obj.recipe_furnace_with_metadata; /*8.6*/
          len += stream.sizeOfZigZagVarInt(v.input_id); /*0.2*/
          len += stream.sizeOfZigZagVarInt(v.input_meta); /*0.2*/
          size_t len_27 = pdef::proto::size::ItemLegacy(stream, v.output); EXPECT_OR_BAIL(len_27); len += len_27; /*output*/ /*4.4*/
          len += stream.sizeOfVarInt(v.block.length());
          len += v.block.length(); /*block: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Multi: { /*8.5*/
        EXPECT_OR_BAIL(obj.recipe_multi); const pdef::proto::Recipes::RecipeMulti &v = *obj.recipe_multi; /*8.6*/
          len += 8; /*0.2*/
          len += stream.sizeOfVarInt(v.network_id); /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t SkinImage(pdef::Stream &stream, const pdef::proto::SkinImage &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.data.size());
    len += obj.data.size(); /*data: buffer*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t Skin(pdef::Stream &stream, const pdef::proto::Skin &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.skin_id.length());
    len += obj.skin_id.length(); /*skin_id: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.play_fab_id.length());
    len += obj.play_fab_id.length(); /*play_fab_id: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.skin_resource_pack.length());
    len += obj.skin_resource_pack.length(); /*skin_resource_pack: pstring*/ /*4.1*/
    size_t len_28 = pdef::proto::size::SkinImage(stream, obj.skin_data); EXPECT_OR_BAIL(len_28); len += len_28; /*skin_data*/ /*4.4*/
    len += 4; /*1.3*/
    for (const auto &v2 : obj.animations) { /*5.20*/
      size_t len_29 = pdef::proto::size::SkinImage(stream, v2.skin_image); EXPECT_OR_BAIL(len_29); len += len_29; /*skin_image*/ /*4.4*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
    }
    size_t len_30 = pdef::proto::size::SkinImage(stream, obj.cape_data); EXPECT_OR_BAIL(len_30); len += len_30; /*cape_data*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.geometry_data.length());
    len += obj.geometry_data.length(); /*geometry_data: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.geometry_data_version.length());
    len += obj.geometry_data_version.length(); /*geometry_data_version: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.animation_data.length());
    len += obj.animation_data.length(); /*animation_data: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.cape_id.length());
    len += obj.cape_id.length(); /*cape_id: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.full_skin_id.length());
    len += obj.full_skin_id.length(); /*full_skin_id: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.arm_size.length());
    len += obj.arm_size.length(); /*arm_size: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.skin_color.length());
    len += obj.skin_color.length(); /*skin_color: pstring*/ /*4.1*/
    len += 4; /*1.3*/
    for (const auto &v2 : obj.personal_pieces) { /*5.20*/
      len += stream.sizeOfVarInt(v2.piece_id.length());
      len += v2.piece_id.length(); /*piece_id: pstring*/ /*4.1*/
      len += stream.sizeOfVarInt(v2.piece_type.length());
      len += v2.piece_type.length(); /*piece_type: pstring*/ /*4.1*/
      len += stream.sizeOfVarInt(v2.pack_id.length());
      len += v2.pack_id.length(); /*pack_id: pstring*/ /*4.1*/
      len += 1; /*0.2*/
      len += stream.sizeOfVarInt(v2.product_id.length());
      len += v2.product_id.length(); /*product_id: pstring*/ /*4.1*/
    }
    len += 4; /*1.3*/
    for (const auto &v2 : obj.piece_tint_colors) { /*5.20*/
      len += stream.sizeOfVarInt(v2.piece_type.length());
      len += v2.piece_type.length(); /*piece_type: pstring*/ /*4.1*/
      len += 4; /*1.3*/
      for (const auto &v3 : v2.colors) {
        len += stream.sizeOfVarInt(v3.length());
        len += v3.length(); /*: pstring*/ /*4.1*/
      }
    }
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t PlayerRecords(pdef::Stream &stream, const pdef::proto::PlayerRecords &obj) {
    size_t len = 0;
    const pdef::proto::PlayerRecords::Type &type = obj.type; /*0.3*/
    len += 1; /*type^: u8*/ /*7.0*/
    const int &records_count = obj.records_count; /*0.1*/
    switch (type) { /*8.0*/
      case pdef::proto::PlayerRecords::Type::Add: { /*8.5*/
        EXPECT_OR_BAIL(obj.records_add); const pdef::proto::PlayerRecords::RecordsAdd &v = *obj.records_add; /*8.6*/
          len += 8; /*0.2*/
          len += stream.sizeOfZigZagVarLong(v.entity_unique_id); /*0.2*/
          len += stream.sizeOfVarInt(v.username.length());
          len += v.username.length(); /*username: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v.xbox_user_id.length());
          len += v.xbox_user_id.length(); /*xbox_user_id: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(v.platform_chat_id.length());
          len += v.platform_chat_id.length(); /*platform_chat_id: pstring*/ /*4.1*/
          len += 4; /*0.2*/
          size_t len_31 = pdef::proto::size::Skin(stream, v.skin_data); EXPECT_OR_BAIL(len_31); len += len_31; /*skin_data*/ /*4.4*/
          len += 1; /*0.2*/
          len += 1; /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::PlayerRecords::Type::Remove: { /*8.5*/
        EXPECT_OR_BAIL(obj.records_remove); const pdef::proto::PlayerRecords::RecordsRemove &v = *obj.records_remove; /*8.6*/
          len += 8; /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    switch (type) { /*8.0*/
      case pdef::proto::PlayerRecords::Type::Add: { /*8.5*/
        len += stream.sizeOfVarInt(records_count); /*1.1*/
        for (const auto &v4 : obj.verified) {
          len += 1; /*0.2*/
        }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t Enchant(pdef::Stream &stream, const pdef::proto::Enchant &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t EnchantOption(pdef::Stream &stream, const pdef::proto::EnchantOption &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.cost); /*0.2*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.equip_enchants.size()); /*1.3*/
    for (const auto &v2 : obj.equip_enchants) {
      size_t len_32 = pdef::proto::size::Enchant(stream, v2); EXPECT_OR_BAIL(len_32); len += len_32; /**/ /*4.4*/
    }
    len += stream.sizeOfVarInt(obj.held_enchants.size()); /*1.3*/
    for (const auto &v2 : obj.held_enchants) {
      size_t len_33 = pdef::proto::size::Enchant(stream, v2); EXPECT_OR_BAIL(len_33); len += len_33; /**/ /*4.4*/
    }
    len += stream.sizeOfVarInt(obj.self_enchants.size()); /*1.3*/
    for (const auto &v2 : obj.self_enchants) {
      size_t len_34 = pdef::proto::size::Enchant(stream, v2); EXPECT_OR_BAIL(len_34); len += len_34; /**/ /*4.4*/
    }
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarInt(obj.option_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t StackRequestSlotInfo(pdef::Stream &stream, const pdef::proto::StackRequestSlotInfo &obj) {
    size_t len = 0;
    len += 1; /*slot_type: u8*/ /*7.0*/
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.stack_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t ItemStackRequest(pdef::Stream &stream, const pdef::proto::ItemStackRequest &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.request_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.actions.size()); /*1.3*/
    for (const auto &v2 : obj.actions) { /*5.20*/
      const pdef::proto::ItemStackRequest::Actions::TypeId &type_id = v2.type_id; /*0.3*/
      len += 1; /*type_id^: u8*/ /*7.0*/
      switch (type_id) { /*8.0*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Take: { /*8.5*/
            len += 1; /*0.2*/
            EXPECT_OR_BAIL(v2.source); size_t len_35 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.source); EXPECT_OR_BAIL(len_35); len += len_35; /*source*/ /*4.4*/
            EXPECT_OR_BAIL(v2.destination); size_t len_36 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.destination); EXPECT_OR_BAIL(len_36); len += len_36; /*destination*/ /*4.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Place: { /*8.5*/
            len += 1; /*0.2*/
            EXPECT_OR_BAIL(v2.source); size_t len_37 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.source); EXPECT_OR_BAIL(len_37); len += len_37; /*source*/ /*4.4*/
            EXPECT_OR_BAIL(v2.destination); size_t len_38 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.destination); EXPECT_OR_BAIL(len_38); len += len_38; /*destination*/ /*4.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Swap: { /*8.5*/
            EXPECT_OR_BAIL(v2.source); size_t len_39 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.source); EXPECT_OR_BAIL(len_39); len += len_39; /*source*/ /*4.4*/
            EXPECT_OR_BAIL(v2.destination); size_t len_40 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.destination); EXPECT_OR_BAIL(len_40); len += len_40; /*destination*/ /*4.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Drop: { /*8.5*/
            len += 1; /*0.2*/
            EXPECT_OR_BAIL(v2.source); size_t len_41 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.source); EXPECT_OR_BAIL(len_41); len += len_41; /*source*/ /*4.4*/
            len += 1; /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Destroy: { /*8.5*/
            len += 1; /*0.2*/
            EXPECT_OR_BAIL(v2.source); size_t len_42 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.source); EXPECT_OR_BAIL(len_42); len += len_42; /*source*/ /*4.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Consume: { /*8.5*/
            len += 1; /*0.2*/
            EXPECT_OR_BAIL(v2.source); size_t len_43 = pdef::proto::size::StackRequestSlotInfo(stream, *v2.source); EXPECT_OR_BAIL(len_43); len += len_43; /*source*/ /*4.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Create: { /*8.5*/
            len += 1; /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::BeaconPayment: { /*8.5*/
            len += stream.sizeOfZigZagVarInt(v2.primary_effect); /*0.2*/
            len += stream.sizeOfZigZagVarInt(v2.secondary_effect); /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::MineBlock: { /*8.5*/
            len += stream.sizeOfZigZagVarInt(v2.unknown1); /*0.2*/
            len += stream.sizeOfZigZagVarInt(v2.predicted_durability); /*0.2*/
            len += stream.sizeOfZigZagVarInt(v2.network_id); /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftRecipe: { /*8.5*/
            len += stream.sizeOfVarInt(v2.recipe_network_id); /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftRecipeAuto: { /*8.5*/
            len += stream.sizeOfVarInt(v2.recipe_network_id); /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftCreative: { /*8.5*/
            len += stream.sizeOfVarInt(v2.item_id); /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Optional: { /*8.5*/
            len += stream.sizeOfVarInt(v2.recipe_network_id); /*0.2*/
            len += 4; /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftGrindstoneRequest: { /*8.5*/
            len += stream.sizeOfVarInt(v2.recipe_network_id); /*0.2*/
            len += stream.sizeOfVarInt(v2.cost); /*0.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftLoomRequest: { /*8.5*/
            len += stream.sizeOfVarInt(v2.pattern.length());
            len += v2.pattern.length(); /*pattern: pstring*/ /*4.1*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::NonImplemented: { /*8.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::ResultsDeprecated: { /*8.5*/
            len += stream.sizeOfVarInt(v2.result_items.size()); /*1.3*/
            for (const auto &v6 : v2.result_items) {
              size_t len_44 = pdef::proto::size::ItemLegacy(stream, v6); EXPECT_OR_BAIL(len_44); len += len_44; /**/ /*4.4*/
            }
            len += 1; /*0.2*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    len += stream.sizeOfVarInt(obj.custom_names.size()); /*1.3*/
    for (const auto &v2 : obj.custom_names) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t ItemStackResponses(pdef::Stream &stream, const pdef::proto::ItemStackResponses &obj) {
  size_t len = 0;
    const pdef::proto::ItemStackResponses::Status &status = obj.status; /*0.3*/
    len += 1; /*status^: u8*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.request_id); /*0.2*/
    switch (status) { /*8.0*/
      case pdef::proto::ItemStackResponses::Status::Ok: { /*8.5*/
          len += stream.sizeOfVarInt(obj.containers.size()); /*1.3*/
          for (const auto &v5 : obj.containers) { /*5.20*/
            len += 1; /*slot_type: u8*/ /*7.0*/
            len += stream.sizeOfVarInt(v5.slots.size()); /*1.3*/
            for (const auto &v6 : v5.slots) { /*5.20*/
              len += 1; /*0.2*/
              len += 1; /*0.2*/
              len += 1; /*0.2*/
              len += stream.sizeOfZigZagVarInt(v6.item_stack_id); /*0.2*/
              len += stream.sizeOfVarInt(v6.custom_name.length());
              len += v6.custom_name.length(); /*custom_name: pstring*/ /*4.1*/
              len += stream.sizeOfZigZagVarInt(v6.durability_correction); /*0.2*/
            }
          }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
size_t ItemComponentList(pdef::Stream &stream, const pdef::proto::ItemComponentList &obj) {
  size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t CommandOrigin(pdef::Stream &stream, const pdef::proto::CommandOrigin &obj) {
    size_t len = 0;
    const pdef::proto::CommandOrigin::Type &type = obj.type; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.type); /*type^: varint*/ /*7.0*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.request_id.length());
    len += obj.request_id.length(); /*request_id: pstring*/ /*4.1*/
    switch (type) { /*8.0*/
      case pdef::proto::CommandOrigin::Type::DevConsole: { /*8.5*/
        EXPECT_OR_BAIL(obj.player_entity_id); const pdef::proto::CommandOrigin::PlayerEntityId &v = *obj.player_entity_id; /*8.6*/
          len += stream.sizeOfZigZagVarLong(v.player_entity_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::CommandOrigin::Type::Test: { /*8.5*/
        EXPECT_OR_BAIL(obj.player_entity_id); const pdef::proto::CommandOrigin::PlayerEntityId &v = *obj.player_entity_id; /*8.6*/
          len += stream.sizeOfZigZagVarLong(v.player_entity_id); /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t TrackedObject(pdef::Stream &stream, const pdef::proto::TrackedObject &obj) {
    size_t len = 0;
    const pdef::proto::TrackedObject::Type &type = obj.type; /*0.3*/
    len += 4; /*type^: li32*/ /*7.0*/
    switch (type) { /*8.0*/
      case pdef::proto::TrackedObject::Type::Entity: { /*8.5*/
        len += stream.sizeOfZigZagVarLong(obj.entity_unique_id); /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    switch (type) { /*8.0*/
      case pdef::proto::TrackedObject::Type::Block: { /*8.5*/
        EXPECT_OR_BAIL(obj.block_position); size_t len_45 = pdef::proto::size::BlockCoordinates(stream, *obj.block_position); EXPECT_OR_BAIL(len_45); len += len_45; /*block_position*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t MapDecoration(pdef::Stream &stream, const pdef::proto::MapDecoration &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.label.length());
    len += obj.label.length(); /*label: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.color_abgr); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t StructureBlockSettings(pdef::Stream &stream, const pdef::proto::StructureBlockSettings &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.palette_name.length());
    len += obj.palette_name.length(); /*palette_name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    size_t len_46 = pdef::proto::size::BlockCoordinates(stream, obj.size); EXPECT_OR_BAIL(len_46); len += len_46; /*size*/ /*4.4*/
    size_t len_47 = pdef::proto::size::BlockCoordinates(stream, obj.structure_offset); EXPECT_OR_BAIL(len_47); len += len_47; /*structure_offset*/ /*4.4*/
    len += stream.sizeOfZigZagVarLong(obj.last_editing_player_unique_id); /*0.2*/
    len += 1; /*rotation: u8*/ /*7.0*/
    len += 1; /*mirror: u8*/ /*7.0*/
    len += 1; /*animation_mode: u8*/ /*7.0*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    size_t len_48 = pdef::proto::size::vec3f(stream, obj.pivot); EXPECT_OR_BAIL(len_48); len += len_48; /*pivot*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t EducationSharedResourceURI(pdef::Stream &stream, const pdef::proto::EducationSharedResourceURI &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.button_name.length());
    len += obj.button_name.length(); /*button_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.link_uri.length());
    len += obj.link_uri.length(); /*link_uri: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t EducationExternalLinkSettings(pdef::Stream &stream, const pdef::proto::EducationExternalLinkSettings &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.url.length());
    len += obj.url.length(); /*url: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.display_name.length());
    len += obj.display_name.length(); /*display_name: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t BlockUpdate(pdef::Stream &stream, const pdef::proto::BlockUpdate &obj) {
    size_t len = 0;
    size_t len_49 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_49); len += len_49; /*position*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.runtime_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.flags); /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.entity_unique_id); /*0.2*/
    len += stream.sizeOfVarInt((int&)obj.transition_type); /*transition_type: varint*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t MaterialReducer(pdef::Stream &stream, const pdef::proto::MaterialReducer &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.mix); /*0.2*/
    const pdef::proto::MaterialReducer::Items &v = obj.items; /*["MaterialReducer"]*/ /*7.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_login(pdef::Stream &stream, const pdef::proto::packet_login &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t LoginTokens(pdef::Stream &stream, const pdef::proto::LoginTokens &obj) {
    size_t len = 0;
    len += 4;
    len += obj.identity.length(); /*identity: pstring*/ /*4.1*/
    len += 4;
    len += obj.client.length(); /*client: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_play_status(pdef::Stream &stream, const pdef::proto::packet_play_status &obj) {
    size_t len = 0;
    len += 4; /*status: i32*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_server_to_client_handshake(pdef::Stream &stream, const pdef::proto::packet_server_to_client_handshake &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.token.length());
    len += obj.token.length(); /*token: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_client_to_server_handshake(pdef::Stream &stream, const pdef::proto::packet_client_to_server_handshake &obj) {
    size_t len = 0;
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_disconnect(pdef::Stream &stream, const pdef::proto::packet_disconnect &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.message.length());
    len += obj.message.length(); /*message: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_packs_info(pdef::Stream &stream, const pdef::proto::packet_resource_packs_info &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 2; /*2.4*/
    for (const auto &v : obj.behaviour_packs) { size_t len_50 = pdef::proto::size::BehaviourPackInfos(stream, v); EXPECT_OR_BAIL(len_50); len += len_50; } /*2.5*/
    len += 2; /*2.4*/
    for (const auto &v : obj.texture_packs) { size_t len_51 = pdef::proto::size::TexturePackInfos(stream, v); EXPECT_OR_BAIL(len_51); len += len_51; } /*2.5*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_pack_stack(pdef::Stream &stream, const pdef::proto::packet_resource_pack_stack &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.behavior_packs.size()); /*2.4*/
    for (const auto &v : obj.behavior_packs) { size_t len_52 = pdef::proto::size::ResourcePackIdVersions(stream, v); EXPECT_OR_BAIL(len_52); len += len_52; } /*2.5*/
    len += stream.sizeOfVarInt(obj.resource_packs.size()); /*2.4*/
    for (const auto &v : obj.resource_packs) { size_t len_53 = pdef::proto::size::ResourcePackIdVersions(stream, v); EXPECT_OR_BAIL(len_53); len += len_53; } /*2.5*/
    len += stream.sizeOfVarInt(obj.game_version.length());
    len += obj.game_version.length(); /*game_version: pstring*/ /*4.1*/
    len += 4; /*1.3*/
    for (const auto &v2 : obj.experiments) {
      size_t len_54 = pdef::proto::size::Experiment(stream, v2); EXPECT_OR_BAIL(len_54); len += len_54; /**/ /*4.4*/
    }
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_pack_client_response(pdef::Stream &stream, const pdef::proto::packet_resource_pack_client_response &obj) {
    size_t len = 0;
    len += 1; /*response_status: u8*/ /*7.0*/
    len += 2; /*1.3*/
    for (const auto &v2 : obj.resourcepackids) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_text(pdef::Stream &stream, const pdef::proto::packet_text &obj) {
    size_t len = 0;
    const pdef::proto::packet_text::Type &type = obj.type; /*0.3*/
    len += 1; /*type^: u8*/ /*7.0*/
    len += 1; /*0.2*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_text::Type::Chat: { /*8.5*/
          len += stream.sizeOfVarInt(obj.source_name.length());
          len += obj.source_name.length(); /*source_name: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Whisper: { /*8.5*/
          len += stream.sizeOfVarInt(obj.source_name.length());
          len += obj.source_name.length(); /*source_name: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Announcement: { /*8.5*/
          len += stream.sizeOfVarInt(obj.source_name.length());
          len += obj.source_name.length(); /*source_name: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Raw: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Tip: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::System: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::JsonWhisper: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Json: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Translation: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.parameters.size()); /*1.3*/
          for (const auto &v5 : obj.parameters) {
            len += stream.sizeOfVarInt(v5.length());
            len += v5.length(); /*: pstring*/ /*4.1*/
          }
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Popup: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.parameters.size()); /*1.3*/
          for (const auto &v5 : obj.parameters) {
            len += stream.sizeOfVarInt(v5.length());
            len += v5.length(); /*: pstring*/ /*4.1*/
          }
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::JukeboxPopup: { /*8.5*/
          len += stream.sizeOfVarInt(obj.message.length());
          len += obj.message.length(); /*message: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.parameters.size()); /*1.3*/
          for (const auto &v5 : obj.parameters) {
            len += stream.sizeOfVarInt(v5.length());
            len += v5.length(); /*: pstring*/ /*4.1*/
          }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    len += stream.sizeOfVarInt(obj.xuid.length());
    len += obj.xuid.length(); /*xuid: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.platform_chat_id.length());
    len += obj.platform_chat_id.length(); /*platform_chat_id: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_time(pdef::Stream &stream, const pdef::proto::packet_set_time &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.time); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_start_game(pdef::Stream &stream, const pdef::proto::packet_start_game &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.entity_id); /*0.2*/
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt((int&)obj.player_gamemode); /*player_gamemode: zigzag32*/ /*7.0*/
    size_t len_55 = pdef::proto::size::vec3f(stream, obj.player_position); EXPECT_OR_BAIL(len_55); len += len_55; /*player_position*/ /*4.4*/
    size_t len_56 = pdef::proto::size::vec2f(stream, obj.rotation); EXPECT_OR_BAIL(len_56); len += len_56; /*rotation*/ /*4.4*/
    len += 8; /*0.2*/
    len += 2; /*0.2*/
    len += stream.sizeOfVarInt(obj.biome_name.length());
    len += obj.biome_name.length(); /*biome_name: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarInt((int&)obj.dimension); /*dimension: zigzag32*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.generator); /*0.2*/
    len += stream.sizeOfZigZagVarInt((int&)obj.world_gamemode); /*world_gamemode: zigzag32*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.difficulty); /*0.2*/
    size_t len_57 = pdef::proto::size::BlockCoordinates(stream, obj.spawn_position); EXPECT_OR_BAIL(len_57); len += len_57; /*spawn_position*/ /*4.4*/
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.day_cycle_stop_time); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.edu_offer); /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.edu_product_uuid.length());
    len += obj.edu_product_uuid.length(); /*edu_product_uuid: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.xbox_live_broadcast_mode); /*0.2*/
    len += stream.sizeOfVarInt(obj.platform_broadcast_mode); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.gamerules.size()); /*1.3*/
    for (const auto &v2 : obj.gamerules) {
      size_t len_58 = pdef::proto::size::GameRule(stream, v2); EXPECT_OR_BAIL(len_58); len += len_58; /**/ /*4.4*/
    }
    len += 4; /*1.3*/
    for (const auto &v2 : obj.experiments) {
      size_t len_59 = pdef::proto::size::Experiment(stream, v2); EXPECT_OR_BAIL(len_59); len += len_59; /**/ /*4.4*/
    }
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.permission_level); /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.game_version.length());
    len += obj.game_version.length(); /*game_version: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    size_t len_60 = pdef::proto::size::EducationSharedResourceURI(stream, obj.edu_resource_uri); EXPECT_OR_BAIL(len_60); len += len_60; /*edu_resource_uri*/ /*4.4*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.level_id.length());
    len += obj.level_id.length(); /*level_id: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.world_name.length());
    len += obj.world_name.length(); /*world_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.premium_world_template_id.length());
    len += obj.premium_world_template_id.length(); /*premium_world_template_id: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarInt((int&)obj.movement_authority); /*movement_authority: zigzag32*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.rewind_history_size); /*0.2*/
    len += 1; /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.enchantment_seed); /*0.2*/
    len += stream.sizeOfVarInt(obj.block_properties.size()); /*2.4*/
    for (const auto &v : obj.block_properties) { size_t len_61 = pdef::proto::size::BlockProperties(stream, v); EXPECT_OR_BAIL(len_61); len += len_61; } /*2.5*/
    len += stream.sizeOfVarInt(obj.itemstates.size()); /*2.4*/
    for (const auto &v : obj.itemstates) { size_t len_62 = pdef::proto::size::Itemstates(stream, v); EXPECT_OR_BAIL(len_62); len += len_62; } /*2.5*/
    len += stream.sizeOfVarInt(obj.multiplayer_correlation_id.length());
    len += obj.multiplayer_correlation_id.length(); /*multiplayer_correlation_id: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.engine.length());
    len += obj.engine.length(); /*engine: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_add_player(pdef::Stream &stream, const pdef::proto::packet_add_player &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.username.length());
    len += obj.username.length(); /*username: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarLong(obj.unique_entity_id); /*0.2*/
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.platform_chat_id.length());
    len += obj.platform_chat_id.length(); /*platform_chat_id: pstring*/ /*4.1*/
    size_t len_63 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_63); len += len_63; /*position*/ /*4.4*/
    size_t len_64 = pdef::proto::size::vec3f(stream, obj.velocity); EXPECT_OR_BAIL(len_64); len += len_64; /*velocity*/ /*4.4*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    size_t len_65 = pdef::proto::size::Item(stream, obj.held_item); EXPECT_OR_BAIL(len_65); len += len_65; /*held_item*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt((int&)obj.gamemode); /*gamemode: zigzag32*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.metadata.size()); /*2.4*/
    for (const auto &v : obj.metadata) { size_t len_66 = pdef::proto::size::MetadataDictionary(stream, v); EXPECT_OR_BAIL(len_66); len += len_66; } /*2.5*/
    len += stream.sizeOfVarInt(obj.flags); /*0.2*/
    len += stream.sizeOfVarInt(obj.command_permission); /*0.2*/
    len += stream.sizeOfVarInt(obj.action_permissions); /*0.2*/
    len += stream.sizeOfVarInt(obj.permission_level); /*0.2*/
    len += stream.sizeOfVarInt(obj.custom_stored_permissions); /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.links.size()); /*1.3*/
    for (const auto &v2 : obj.links) {
      size_t len_67 = pdef::proto::size::Link(stream, v2); EXPECT_OR_BAIL(len_67); len += len_67; /**/ /*4.4*/
    }
    len += stream.sizeOfVarInt(obj.device_id.length());
    len += obj.device_id.length(); /*device_id: pstring*/ /*4.1*/
    len += 4; /*device_os: li32*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_add_entity(pdef::Stream &stream, const pdef::proto::packet_add_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.entity_id_self); /*0.2*/
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.entity_type.length());
    len += obj.entity_type.length(); /*entity_type: pstring*/ /*4.1*/
    size_t len_68 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_68); len += len_68; /*position*/ /*4.4*/
    size_t len_69 = pdef::proto::size::vec3f(stream, obj.velocity); EXPECT_OR_BAIL(len_69); len += len_69; /*velocity*/ /*4.4*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.attributes.size()); /*2.4*/
    for (const auto &v : obj.attributes) { size_t len_70 = pdef::proto::size::EntityAttributes(stream, v); EXPECT_OR_BAIL(len_70); len += len_70; } /*2.5*/
    len += stream.sizeOfVarInt(obj.metadata.size()); /*2.4*/
    for (const auto &v : obj.metadata) { size_t len_71 = pdef::proto::size::MetadataDictionary(stream, v); EXPECT_OR_BAIL(len_71); len += len_71; } /*2.5*/
    len += stream.sizeOfVarInt(obj.links.size()); /*1.3*/
    for (const auto &v2 : obj.links) {
      size_t len_72 = pdef::proto::size::Link(stream, v2); EXPECT_OR_BAIL(len_72); len += len_72; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_remove_entity(pdef::Stream &stream, const pdef::proto::packet_remove_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.entity_id_self); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_add_item_entity(pdef::Stream &stream, const pdef::proto::packet_add_item_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.entity_id_self); /*0.2*/
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    size_t len_73 = pdef::proto::size::Item(stream, obj.item); EXPECT_OR_BAIL(len_73); len += len_73; /*item*/ /*4.4*/
    size_t len_74 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_74); len += len_74; /*position*/ /*4.4*/
    size_t len_75 = pdef::proto::size::vec3f(stream, obj.velocity); EXPECT_OR_BAIL(len_75); len += len_75; /*velocity*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.metadata.size()); /*2.4*/
    for (const auto &v : obj.metadata) { size_t len_76 = pdef::proto::size::MetadataDictionary(stream, v); EXPECT_OR_BAIL(len_76); len += len_76; } /*2.5*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_take_item_entity(pdef::Stream &stream, const pdef::proto::packet_take_item_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.target); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_move_entity(pdef::Stream &stream, const pdef::proto::packet_move_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += 1; /*0.2*/
    size_t len_77 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_77); len += len_77; /*position*/ /*4.4*/
    size_t len_78 = pdef::proto::size::Rotation(stream, obj.rotation); EXPECT_OR_BAIL(len_78); len += len_78; /*rotation*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_move_player(pdef::Stream &stream, const pdef::proto::packet_move_player &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.runtime_id); /*0.2*/
    size_t len_79 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_79); len += len_79; /*position*/ /*4.4*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    const pdef::proto::packet_move_player::Mode &mode = obj.mode; /*0.3*/
    len += 1; /*mode^: u8*/ /*7.0*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.ridden_runtime_id); /*0.2*/
    switch (mode) { /*8.0*/
      case pdef::proto::packet_move_player::Mode::Teleport: { /*8.5*/
        EXPECT_OR_BAIL(obj.teleport); const pdef::proto::packet_move_player::Teleport &v = *obj.teleport; /*8.6*/
          len += 4; /*cause: li32*/ /*7.0*/
          len += 4; /*source_entity_type: li32*/ /*7.0*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    len += stream.sizeOfVarInt64(obj.tick); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_rider_jump(pdef::Stream &stream, const pdef::proto::packet_rider_jump &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.jump_strength); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_block(pdef::Stream &stream, const pdef::proto::packet_update_block &obj) {
    size_t len = 0;
    size_t len_80 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_80); len += len_80; /*position*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.block_runtime_id); /*0.2*/
    int flags_val = 0; /*X*/
    if (obj.flags.neighbors) flags_val |= 1;
    if (obj.flags.network) flags_val |= 2;
    if (obj.flags.no_graphic) flags_val |= 4;
    if (obj.flags.unused) flags_val |= 8;
    if (obj.flags.priority) flags_val |= 16;
    len += stream.sizeOfVarInt(flags_val); /*flags: bitflags*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.layer); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_add_painting(pdef::Stream &stream, const pdef::proto::packet_add_painting &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.entity_id_self); /*0.2*/
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    size_t len_81 = pdef::proto::size::vec3f(stream, obj.coordinates); EXPECT_OR_BAIL(len_81); len += len_81; /*coordinates*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.direction); /*0.2*/
    len += stream.sizeOfVarInt(obj.title.length());
    len += obj.title.length(); /*title: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_tick_sync(pdef::Stream &stream, const pdef::proto::packet_tick_sync &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_level_sound_event_old(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_old &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    size_t len_82 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_82); len += len_82; /*position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.block_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.entity_type); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_level_event(pdef::Stream &stream, const pdef::proto::packet_level_event &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.event); /*event: zigzag32*/ /*7.0*/
    size_t len_83 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_83); len += len_83; /*position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.data); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_event(pdef::Stream &stream, const pdef::proto::packet_block_event &obj) {
    size_t len = 0;
    size_t len_84 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_84); len += len_84; /*position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt((int&)obj.type); /*type: zigzag32*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.data); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_event(pdef::Stream &stream, const pdef::proto::packet_entity_event &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += 1; /*event_id: u8*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.data); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_mob_effect(pdef::Stream &stream, const pdef::proto::packet_mob_effect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += 1; /*event_id: u8*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.effect_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.amplifier); /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.duration); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_attributes(pdef::Stream &stream, const pdef::proto::packet_update_attributes &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.attributes.size()); /*2.4*/
    for (const auto &v : obj.attributes) { size_t len_85 = pdef::proto::size::PlayerAttributes(stream, v); EXPECT_OR_BAIL(len_85); len += len_85; } /*2.5*/
    len += stream.sizeOfVarInt64(obj.tick); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_inventory_transaction(pdef::Stream &stream, const pdef::proto::packet_inventory_transaction &obj) {
    size_t len = 0;
    size_t len_86 = pdef::proto::size::Transaction(stream, obj.transaction); EXPECT_OR_BAIL(len_86); len += len_86; /*transaction*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_mob_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_equipment &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    size_t len_87 = pdef::proto::size::Item(stream, obj.item); EXPECT_OR_BAIL(len_87); len += len_87; /*item*/ /*4.4*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*window_id: i8*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_mob_armor_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_armor_equipment &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    size_t len_88 = pdef::proto::size::Item(stream, obj.helmet); EXPECT_OR_BAIL(len_88); len += len_88; /*helmet*/ /*4.4*/
    size_t len_89 = pdef::proto::size::Item(stream, obj.chestplate); EXPECT_OR_BAIL(len_89); len += len_89; /*chestplate*/ /*4.4*/
    size_t len_90 = pdef::proto::size::Item(stream, obj.leggings); EXPECT_OR_BAIL(len_90); len += len_90; /*leggings*/ /*4.4*/
    size_t len_91 = pdef::proto::size::Item(stream, obj.boots); EXPECT_OR_BAIL(len_91); len += len_91; /*boots*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_interact(pdef::Stream &stream, const pdef::proto::packet_interact &obj) {
    size_t len = 0;
    const pdef::proto::packet_interact::ActionId &action_id = obj.action_id; /*0.3*/
    len += 1; /*action_id^: u8*/ /*7.0*/
    len += stream.sizeOfVarInt64(obj.target_entity_id); /*0.2*/
    switch (action_id) { /*8.0*/
      case pdef::proto::packet_interact::ActionId::MouseOverEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.position); size_t len_92 = pdef::proto::size::vec3f(stream, *obj.position); EXPECT_OR_BAIL(len_92); len += len_92; /*position*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_interact::ActionId::LeaveVehicle: { /*8.5*/
        EXPECT_OR_BAIL(obj.position); size_t len_93 = pdef::proto::size::vec3f(stream, *obj.position); EXPECT_OR_BAIL(len_93); len += len_93; /*position*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_pick_request(pdef::Stream &stream, const pdef::proto::packet_block_pick_request &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.x); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.y); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.z); /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_entity_pick_request(pdef::Stream &stream, const pdef::proto::packet_entity_pick_request &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_action(pdef::Stream &stream, const pdef::proto::packet_player_action &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt((int&)obj.action); /*action: zigzag32*/ /*7.0*/
    size_t len_94 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_94); len += len_94; /*position*/ /*4.4*/
    size_t len_95 = pdef::proto::size::BlockCoordinates(stream, obj.result_position); EXPECT_OR_BAIL(len_95); len += len_95; /*result_position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.face); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_hurt_armor(pdef::Stream &stream, const pdef::proto::packet_hurt_armor &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.cause); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.damage); /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.armor_slots); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_entity_data(pdef::Stream &stream, const pdef::proto::packet_set_entity_data &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.metadata.size()); /*2.4*/
    for (const auto &v : obj.metadata) { size_t len_96 = pdef::proto::size::MetadataDictionary(stream, v); EXPECT_OR_BAIL(len_96); len += len_96; } /*2.5*/
    len += stream.sizeOfVarInt64(obj.tick); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_entity_motion(pdef::Stream &stream, const pdef::proto::packet_set_entity_motion &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    size_t len_97 = pdef::proto::size::vec3f(stream, obj.velocity); EXPECT_OR_BAIL(len_97); len += len_97; /*velocity*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_entity_link(pdef::Stream &stream, const pdef::proto::packet_set_entity_link &obj) {
    size_t len = 0;
    size_t len_98 = pdef::proto::size::Link(stream, obj.link); EXPECT_OR_BAIL(len_98); len += len_98; /*link*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_health(pdef::Stream &stream, const pdef::proto::packet_set_health &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.health); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_spawn_position(pdef::Stream &stream, const pdef::proto::packet_set_spawn_position &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.spawn_type); /*spawn_type: zigzag32*/ /*7.0*/
    size_t len_99 = pdef::proto::size::BlockCoordinates(stream, obj.player_position); EXPECT_OR_BAIL(len_99); len += len_99; /*player_position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.dimension); /*0.2*/
    size_t len_100 = pdef::proto::size::BlockCoordinates(stream, obj.world_position); EXPECT_OR_BAIL(len_100); len += len_100; /*world_position*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_animate(pdef::Stream &stream, const pdef::proto::packet_animate &obj) {
    size_t len = 0;
    const pdef::proto::packet_animate::ActionId &action_id = obj.action_id; /*0.3*/
    len += stream.sizeOfZigZagVarInt((int&)obj.action_id); /*action_id^: zigzag32*/ /*7.0*/
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    switch (action_id) { /*8.0*/
      case pdef::proto::packet_animate::ActionId::RowRight: { /*8.5*/
          len += 4; /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_animate::ActionId::RowLeft: { /*8.5*/
          len += 4; /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_respawn(pdef::Stream &stream, const pdef::proto::packet_respawn &obj) {
    size_t len = 0;
    size_t len_101 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_101); len += len_101; /*position*/ /*4.4*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_container_open(pdef::Stream &stream, const pdef::proto::packet_container_open &obj) {
    size_t len = 0;
    len += 1; /*window_id: i8*/ /*7.0*/
    len += 1; /*window_type: i8*/ /*7.0*/
    size_t len_102 = pdef::proto::size::BlockCoordinates(stream, obj.coordinates); EXPECT_OR_BAIL(len_102); len += len_102; /*coordinates*/ /*4.4*/
    len += stream.sizeOfZigZagVarLong(obj.runtime_entity_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_container_close(pdef::Stream &stream, const pdef::proto::packet_container_close &obj) {
    size_t len = 0;
    len += 1; /*window_id: i8*/ /*7.0*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_hotbar(pdef::Stream &stream, const pdef::proto::packet_player_hotbar &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.selected_slot); /*0.2*/
    len += 1; /*window_id: i8*/ /*7.0*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_inventory_content(pdef::Stream &stream, const pdef::proto::packet_inventory_content &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt((int&)obj.window_id); /*window_id: varint*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.input.size()); /*1.3*/
    for (const auto &v2 : obj.input) {
      size_t len_103 = pdef::proto::size::Item(stream, v2); EXPECT_OR_BAIL(len_103); len += len_103; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_inventory_slot(pdef::Stream &stream, const pdef::proto::packet_inventory_slot &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt((int&)obj.window_id); /*window_id: varint*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.slot); /*0.2*/
    size_t len_104 = pdef::proto::size::Item(stream, obj.item); EXPECT_OR_BAIL(len_104); len += len_104; /*item*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_container_set_data(pdef::Stream &stream, const pdef::proto::packet_container_set_data &obj) {
    size_t len = 0;
    len += 1; /*window_id: i8*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.property); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.value); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_crafting_data(pdef::Stream &stream, const pdef::proto::packet_crafting_data &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.recipes.size()); /*2.4*/
    for (const auto &v : obj.recipes) { size_t len_105 = pdef::proto::size::Recipes(stream, v); EXPECT_OR_BAIL(len_105); len += len_105; } /*2.5*/
    len += stream.sizeOfVarInt(obj.potion_type_recipes.size()); /*2.4*/
    for (const auto &v : obj.potion_type_recipes) { size_t len_106 = pdef::proto::size::PotionTypeRecipes(stream, v); EXPECT_OR_BAIL(len_106); len += len_106; } /*2.5*/
    len += stream.sizeOfVarInt(obj.potion_container_recipes.size()); /*2.4*/
    for (const auto &v : obj.potion_container_recipes) { size_t len_107 = pdef::proto::size::PotionContainerChangeRecipes(stream, v); EXPECT_OR_BAIL(len_107); len += len_107; } /*2.5*/
    len += stream.sizeOfVarInt(obj.material_reducers.size()); /*1.3*/
    for (const auto &v2 : obj.material_reducers) {
      size_t len_108 = pdef::proto::size::MaterialReducer(stream, v2); EXPECT_OR_BAIL(len_108); len += len_108; /**/ /*4.4*/
    }
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_crafting_event(pdef::Stream &stream, const pdef::proto::packet_crafting_event &obj) {
    size_t len = 0;
    len += 1; /*window_id: i8*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt((int&)obj.recipe_type); /*recipe_type: zigzag32*/ /*7.0*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.input.size()); /*1.3*/
    for (const auto &v2 : obj.input) {
      size_t len_109 = pdef::proto::size::Item(stream, v2); EXPECT_OR_BAIL(len_109); len += len_109; /**/ /*4.4*/
    }
    len += stream.sizeOfVarInt(obj.result.size()); /*1.3*/
    for (const auto &v2 : obj.result) {
      size_t len_110 = pdef::proto::size::Item(stream, v2); EXPECT_OR_BAIL(len_110); len += len_110; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_gui_data_pick_item(pdef::Stream &stream, const pdef::proto::packet_gui_data_pick_item &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.item_name.length());
    len += obj.item_name.length(); /*item_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.item_effects.length());
    len += obj.item_effects.length(); /*item_effects: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_adventure_settings(pdef::Stream &stream, const pdef::proto::packet_adventure_settings &obj) {
    size_t len = 0;
    int flags_val = 0; /*X*/
    if (obj.flags.world_immutable) flags_val |= 1;
    if (obj.flags.no_pvp) flags_val |= 2;
    if (obj.flags.auto_jump) flags_val |= 32;
    if (obj.flags.allow_flight) flags_val |= 64;
    if (obj.flags.no_clip) flags_val |= 128;
    if (obj.flags.world_builder) flags_val |= 256;
    if (obj.flags.flying) flags_val |= 512;
    if (obj.flags.muted) flags_val |= 1024;
    len += stream.sizeOfVarInt(flags_val); /*flags: bitflags*/ /*4.1*/
    len += stream.sizeOfVarInt((int&)obj.command_permission); /*command_permission: varint*/ /*7.0*/
    int action_permissions_val = 0; /*X*/
    if (obj.action_permissions.mine) action_permissions_val |= 65537;
    if (obj.action_permissions.doors_and_switches) action_permissions_val |= 65538;
    if (obj.action_permissions.open_containers) action_permissions_val |= 65540;
    if (obj.action_permissions.attack_players) action_permissions_val |= 65544;
    if (obj.action_permissions.attack_mobs) action_permissions_val |= 65552;
    if (obj.action_permissions.operator_) action_permissions_val |= 65568;
    if (obj.action_permissions.teleport) action_permissions_val |= 65664;
    if (obj.action_permissions.build) action_permissions_val |= 65792;
    if (obj.action_permissions.default_) action_permissions_val |= 66048;
    len += stream.sizeOfVarInt(action_permissions_val); /*action_permissions: bitflags*/ /*4.1*/
    len += stream.sizeOfVarInt((int&)obj.permission_level); /*permission_level: varint*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.custom_stored_permissions); /*0.2*/
    len += 8; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_block_entity_data(pdef::Stream &stream, const pdef::proto::packet_block_entity_data &obj) {
    size_t len = 0;
    size_t len_111 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_111); len += len_111; /*position*/ /*4.4*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_input(pdef::Stream &stream, const pdef::proto::packet_player_input &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_level_chunk(pdef::Stream &stream, const pdef::proto::packet_level_chunk &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.x); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.z); /*0.2*/
    const int &sub_chunk_count = obj.sub_chunk_count; /*0.1*/
    if (sub_chunk_count == -2) { /*8.2*/
      len += 2; /*0.2*/
    }
    const bool &cache_enabled = obj.cache_enabled; /*0.1*/
    if (cache_enabled == true) { /*8.1*/
        EXPECT_OR_BAIL(obj.blobs); const pdef::proto::packet_level_chunk::Blobs &v = *obj.blobs; /*8.6*/
        len += stream.sizeOfVarInt(v.hashes.size()); /*1.3*/
        for (const auto &v4 : v.hashes) {
          len += 8; /*0.2*/
        }
    }
    len += stream.sizeOfVarInt(obj.payload.size());
    len += obj.payload.size(); /*payload: buffer*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_commands_enabled(pdef::Stream &stream, const pdef::proto::packet_set_commands_enabled &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_difficulty(pdef::Stream &stream, const pdef::proto::packet_set_difficulty &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.difficulty); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_change_dimension(pdef::Stream &stream, const pdef::proto::packet_change_dimension &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.dimension); /*0.2*/
    size_t len_112 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_112); len += len_112; /*position*/ /*4.4*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_player_game_type(pdef::Stream &stream, const pdef::proto::packet_set_player_game_type &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.gamemode); /*gamemode: zigzag32*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_list(pdef::Stream &stream, const pdef::proto::packet_player_list &obj) {
    size_t len = 0;
    size_t len_113 = pdef::proto::size::PlayerRecords(stream, obj.records); EXPECT_OR_BAIL(len_113); len += len_113; /*records*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_simple_event(pdef::Stream &stream, const pdef::proto::packet_simple_event &obj) {
    size_t len = 0;
    len += 2; /*event_type: lu16*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_event(pdef::Stream &stream, const pdef::proto::packet_event &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt((int&)obj.event_type); /*event_type: zigzag32*/ /*7.0*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spawn_experience_orb(pdef::Stream &stream, const pdef::proto::packet_spawn_experience_orb &obj) {
    size_t len = 0;
    size_t len_114 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_114); len += len_114; /*position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.count); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_clientbound_map_item_data(pdef::Stream &stream, const pdef::proto::packet_clientbound_map_item_data &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.map_id); /*0.2*/
    int update_flags_val = 0; /*X*/
    update_flags_val |= (int)obj.update_flags.void_ << 0;
    update_flags_val |= (int)obj.update_flags.texture << 1;
    update_flags_val |= (int)obj.update_flags.decoration << 2;
    update_flags_val |= (int)obj.update_flags.initialisation << 3;
    len += stream.sizeOfVarInt(update_flags_val); /*update_flags^: bitflags*/ /*4.1*/
    const pdef::proto::packet_clientbound_map_item_data::update_flags_t &update_flags = obj.update_flags; /*0.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    if (update_flags.initialisation == true) { /*8.2*/
      len += stream.sizeOfVarInt(obj.included_in.size()); /*1.3*/
      for (const auto &v3 : obj.included_in) {
        len += stream.sizeOfZigZagVarLong(v3); /*0.2*/
      }
    }
    if ((update_flags.initialisation || update_flags.decoration || update_flags.texture) == true) { /*8.2*/
      len += 1; /*0.2*/
    }
    if (update_flags.decoration == true) { /*8.2*/
        EXPECT_OR_BAIL(obj.tracked); const pdef::proto::packet_clientbound_map_item_data::Tracked &v = *obj.tracked; /*8.6*/
        len += stream.sizeOfVarInt(v.objects.size()); /*1.3*/
        for (const auto &v4 : v.objects) {
          size_t len_115 = pdef::proto::size::TrackedObject(stream, v4); EXPECT_OR_BAIL(len_115); len += len_115; /**/ /*4.4*/
        }
        len += stream.sizeOfVarInt(v.decorations.size()); /*1.3*/
        for (const auto &v4 : v.decorations) {
          size_t len_116 = pdef::proto::size::MapDecoration(stream, v4); EXPECT_OR_BAIL(len_116); len += len_116; /**/ /*4.4*/
        }
    }
    if (update_flags.texture == true) { /*8.2*/
        EXPECT_OR_BAIL(obj.texture); const pdef::proto::packet_clientbound_map_item_data::Texture &v = *obj.texture; /*8.6*/
        len += stream.sizeOfZigZagVarInt(v.width); /*0.2*/
        len += stream.sizeOfZigZagVarInt(v.height); /*0.2*/
        len += stream.sizeOfZigZagVarInt(v.x_offset); /*0.2*/
        len += stream.sizeOfZigZagVarInt(v.y_offset); /*0.2*/
        len += stream.sizeOfVarInt(v.pixels.size()); /*1.3*/
        for (const auto &v4 : v.pixels) {
          len += stream.sizeOfVarInt(v4); /*0.2*/
        }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_map_info_request(pdef::Stream &stream, const pdef::proto::packet_map_info_request &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.map_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_request_chunk_radius(pdef::Stream &stream, const pdef::proto::packet_request_chunk_radius &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.chunk_radius); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_chunk_radius_update(pdef::Stream &stream, const pdef::proto::packet_chunk_radius_update &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.chunk_radius); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_item_frame_drop_item(pdef::Stream &stream, const pdef::proto::packet_item_frame_drop_item &obj) {
    size_t len = 0;
    size_t len_117 = pdef::proto::size::BlockCoordinates(stream, obj.coordinates); EXPECT_OR_BAIL(len_117); len += len_117; /*coordinates*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_game_rules_changed(pdef::Stream &stream, const pdef::proto::packet_game_rules_changed &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.rules.size()); /*1.3*/
    for (const auto &v2 : obj.rules) {
      size_t len_118 = pdef::proto::size::GameRule(stream, v2); EXPECT_OR_BAIL(len_118); len += len_118; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_camera(pdef::Stream &stream, const pdef::proto::packet_camera &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.camera_entity_unique_id); /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.target_player_unique_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_boss_event(pdef::Stream &stream, const pdef::proto::packet_boss_event &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.boss_entity_id); /*0.2*/
    const pdef::proto::packet_boss_event::Type &type = obj.type; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.type); /*type^: varint*/ /*7.0*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_boss_event::Type::ShowBar: { /*8.5*/
          len += stream.sizeOfVarInt(obj.title.length());
          len += obj.title.length(); /*title: pstring*/ /*4.1*/
          len += 4; /*0.2*/
          len += 2; /*0.2*/
          len += stream.sizeOfVarInt(obj.color); /*0.2*/
          len += stream.sizeOfVarInt(obj.overlay); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::RegisterPlayer: { /*8.5*/
          len += stream.sizeOfZigZagVarLong(obj.player_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::UnregisterPlayer: { /*8.5*/
          len += stream.sizeOfZigZagVarLong(obj.player_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::Query: { /*8.5*/
          len += stream.sizeOfZigZagVarLong(obj.player_id); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::SetBarProgress: { /*8.5*/
          len += 4; /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::SetBarTitle: { /*8.5*/
          len += stream.sizeOfVarInt(obj.title.length());
          len += obj.title.length(); /*title: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::UpdateProperties: { /*8.5*/
          len += 2; /*0.2*/
          len += stream.sizeOfVarInt(obj.color); /*0.2*/
          len += stream.sizeOfVarInt(obj.overlay); /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::Texture: { /*8.5*/
          len += stream.sizeOfVarInt(obj.color); /*0.2*/
          len += stream.sizeOfVarInt(obj.overlay); /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_show_credits(pdef::Stream &stream, const pdef::proto::packet_show_credits &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.status); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_available_commands(pdef::Stream &stream, const pdef::proto::packet_available_commands &obj) {
    size_t len = 0;
    const int &values_len = obj.values_len; /*0.1*/
    pdef::proto::packet_available_commands::_EnumType _enum_type; if (values_len <= 0xff) { _enum_type = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { _enum_type = pdef::proto::packet_available_commands::_EnumType::Short; } else { _enum_type = pdef::proto::packet_available_commands::_EnumType::Int; } /*_enum_type^: enum_size_based_on_values_len*/ /*4.1*/
    len += stream.sizeOfVarInt(values_len); /*1.1*/
    for (const auto &v2 : obj.enum_values) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += stream.sizeOfVarInt(obj.suffixes.size()); /*1.3*/
    for (const auto &v2 : obj.suffixes) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += stream.sizeOfVarInt(obj.enums.size()); /*1.3*/
    for (const auto &v2 : obj.enums) { /*5.20*/
      len += stream.sizeOfVarInt(v2.name.length());
      len += v2.name.length(); /*name: pstring*/ /*4.1*/
      if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Byte) { /*8.5*/
        len += 1; /*0.2*/
      }
      else if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Short) { /*8.5*/
        len += 2; /*0.2*/
      }
      else if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Int) { /*8.5*/
        len += 4; /*0.2*/
      }
    }
    len += stream.sizeOfVarInt(obj.command_data.size()); /*1.3*/
    for (const auto &v2 : obj.command_data) { /*5.20*/
      len += stream.sizeOfVarInt(v2.name.length());
      len += v2.name.length(); /*name: pstring*/ /*4.1*/
      len += stream.sizeOfVarInt(v2.description.length());
      len += v2.description.length(); /*description: pstring*/ /*4.1*/
      len += 2; /*0.2*/
      len += 1; /*0.2*/
      len += 4; /*0.2*/
      len += stream.sizeOfVarInt(v2.overloads.size()); /*1.3*/
      for (const auto &v3 : v2.overloads) { /*5.20*/
        len += stream.sizeOfVarInt(v3.parameters.size()); /*1.3*/
        for (const auto &v4 : v3.parameters) { /*5.20*/
          len += stream.sizeOfVarInt(v4.parameter_name.length());
          len += v4.parameter_name.length(); /*parameter_name: pstring*/ /*4.1*/
          len += 2; /*value_type: lu16*/ /*7.0*/
          len += 2; /*enum_type: lu16*/ /*7.0*/
          len += 1; /*0.2*/
          len += 1; /*options: bitfield*/ /*4.1*/
        }
      }
    }
    len += stream.sizeOfVarInt(obj.dynamic_enums.size()); /*1.3*/
    for (const auto &v2 : obj.dynamic_enums) { /*5.20*/
      len += stream.sizeOfVarInt(v2.name.length());
      len += v2.name.length(); /*name: pstring*/ /*4.1*/
      len += stream.sizeOfVarInt(v2.values.size()); /*1.3*/
      for (const auto &v3 : v2.values) {
        len += stream.sizeOfVarInt(v3.length());
        len += v3.length(); /*: pstring*/ /*4.1*/
      }
    }
    len += stream.sizeOfVarInt(obj.enum_constraints.size()); /*1.3*/
    for (const auto &v2 : obj.enum_constraints) { /*5.20*/
      len += 4; /*0.2*/
      len += 4; /*0.2*/
      len += stream.sizeOfVarInt(v2.constraints.size()); /*1.3*/
      for (const auto &v3 : v2.constraints) { /*5.20*/
        len += 1; /*constraint: u8*/ /*7.0*/
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_command_request(pdef::Stream &stream, const pdef::proto::packet_command_request &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.command.length());
    len += obj.command.length(); /*command: pstring*/ /*4.1*/
    size_t len_119 = pdef::proto::size::CommandOrigin(stream, obj.origin); EXPECT_OR_BAIL(len_119); len += len_119; /*origin*/ /*4.4*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_command_block_update(pdef::Stream &stream, const pdef::proto::packet_command_block_update &obj) {
    size_t len = 0;
    const bool &is_block = obj.is_block; /*0.1*/
    if (is_block == true) { /*8.1*/
        EXPECT_OR_BAIL(obj.position); size_t len_120 = pdef::proto::size::BlockCoordinates(stream, *obj.position); EXPECT_OR_BAIL(len_120); len += len_120; /*position*/ /*4.4*/
        len += stream.sizeOfVarInt((int&)obj.mode); /*mode: varint*/ /*7.0*/
        len += 1; /*0.2*/
        len += 1; /*0.2*/
    }
    else if (is_block == false) { /*8.1*/
        len += stream.sizeOfVarInt64(obj.minecart_entity_runtime_id); /*0.2*/
    }
    len += stream.sizeOfVarInt(obj.command.length());
    len += obj.command.length(); /*command: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.last_output.length());
    len += obj.last_output.length(); /*last_output: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_command_output(pdef::Stream &stream, const pdef::proto::packet_command_output &obj) {
    size_t len = 0;
    size_t len_121 = pdef::proto::size::CommandOrigin(stream, obj.origin); EXPECT_OR_BAIL(len_121); len += len_121; /*origin*/ /*4.4*/
    const pdef::proto::packet_command_output::OutputType &output_type = obj.output_type; /*0.3*/
    len += 1; /*output_type^: i8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.success_count); /*0.2*/
    len += stream.sizeOfVarInt(obj.output.size()); /*1.3*/
    for (const auto &v2 : obj.output) { /*5.20*/
      len += 1; /*0.2*/
      len += stream.sizeOfVarInt(v2.message_id.length());
      len += v2.message_id.length(); /*message_id: pstring*/ /*4.1*/
      len += stream.sizeOfVarInt(v2.parameters.size()); /*1.3*/
      for (const auto &v3 : v2.parameters) {
        len += stream.sizeOfVarInt(v3.length());
        len += v3.length(); /*: pstring*/ /*4.1*/
      }
    }
    switch (output_type) { /*8.0*/
      case pdef::proto::packet_command_output::OutputType::DataSet: { /*8.5*/
        len += stream.sizeOfVarInt(obj.data_set.length());
        len += obj.data_set.length(); /*data_set: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_trade(pdef::Stream &stream, const pdef::proto::packet_update_trade &obj) {
    size_t len = 0;
    len += 1; /*window_id: i8*/ /*7.0*/
    len += 1; /*window_type: i8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.size); /*0.2*/
    len += stream.sizeOfVarInt(obj.trade_tier); /*0.2*/
    len += stream.sizeOfVarInt64(obj.villager_unique_id); /*0.2*/
    len += stream.sizeOfVarInt64(obj.entity_unique_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.display_name.length());
    len += obj.display_name.length(); /*display_name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_equipment(pdef::Stream &stream, const pdef::proto::packet_update_equipment &obj) {
    size_t len = 0;
    len += 1; /*window_id: i8*/ /*7.0*/
    len += 1; /*window_type: i8*/ /*7.0*/
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.entity_id); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_pack_data_info(pdef::Stream &stream, const pdef::proto::packet_resource_pack_data_info &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.pack_id.length());
    len += obj.pack_id.length(); /*pack_id: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.hash.size());
    len += obj.hash.size(); /*hash: buffer*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*pack_type: u8*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_pack_chunk_data(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_data &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.pack_id.length());
    len += obj.pack_id.length(); /*pack_id: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.payload.size());
    len += obj.payload.size(); /*payload: buffer*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_resource_pack_chunk_request(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_request &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.pack_id.length());
    len += obj.pack_id.length(); /*pack_id: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_transfer(pdef::Stream &stream, const pdef::proto::packet_transfer &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.server_address.length());
    len += obj.server_address.length(); /*server_address: pstring*/ /*4.1*/
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_play_sound(pdef::Stream &stream, const pdef::proto::packet_play_sound &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    size_t len_122 = pdef::proto::size::BlockCoordinates(stream, obj.coordinates); EXPECT_OR_BAIL(len_122); len += len_122; /*coordinates*/ /*4.4*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_stop_sound(pdef::Stream &stream, const pdef::proto::packet_stop_sound &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_title(pdef::Stream &stream, const pdef::proto::packet_set_title &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.type); /*type: zigzag32*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.text.length());
    len += obj.text.length(); /*text: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarInt(obj.fade_in_time); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.stay_time); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.fade_out_time); /*0.2*/
    len += stream.sizeOfVarInt(obj.xuid.length());
    len += obj.xuid.length(); /*xuid: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.platform_online_id.length());
    len += obj.platform_online_id.length(); /*platform_online_id: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_add_behavior_tree(pdef::Stream &stream, const pdef::proto::packet_add_behavior_tree &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.behaviortree.length());
    len += obj.behaviortree.length(); /*behaviortree: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_structure_block_update(pdef::Stream &stream, const pdef::proto::packet_structure_block_update &obj) {
    size_t len = 0;
    size_t len_123 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_123); len += len_123; /*position*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.structure_name.length());
    len += obj.structure_name.length(); /*structure_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.data_field.length());
    len += obj.data_field.length(); /*data_field: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.structure_block_type); /*0.2*/
    size_t len_124 = pdef::proto::size::StructureBlockSettings(stream, obj.settings); EXPECT_OR_BAIL(len_124); len += len_124; /*settings*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.redstone_save_mode); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_show_store_offer(pdef::Stream &stream, const pdef::proto::packet_show_store_offer &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.offer_id.length());
    len += obj.offer_id.length(); /*offer_id: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_purchase_receipt(pdef::Stream &stream, const pdef::proto::packet_purchase_receipt &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.receipts.size()); /*1.3*/
    for (const auto &v2 : obj.receipts) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_skin(pdef::Stream &stream, const pdef::proto::packet_player_skin &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    size_t len_125 = pdef::proto::size::Skin(stream, obj.skin); EXPECT_OR_BAIL(len_125); len += len_125; /*skin*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.skin_name.length());
    len += obj.skin_name.length(); /*skin_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.old_skin_name.length());
    len += obj.old_skin_name.length(); /*old_skin_name: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_sub_client_login(pdef::Stream &stream, const pdef::proto::packet_sub_client_login &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_initiate_web_socket_connection(pdef::Stream &stream, const pdef::proto::packet_initiate_web_socket_connection &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.server.length());
    len += obj.server.length(); /*server: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_last_hurt_by(pdef::Stream &stream, const pdef::proto::packet_set_last_hurt_by &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entity_type); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_book_edit(pdef::Stream &stream, const pdef::proto::packet_book_edit &obj) {
    size_t len = 0;
    const pdef::proto::packet_book_edit::Type &type = obj.type; /*0.3*/
    len += 1; /*type^: u8*/ /*7.0*/
    len += 1; /*0.2*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_book_edit::Type::ReplacePage: { /*8.5*/
          len += 1; /*0.2*/
          len += stream.sizeOfVarInt(obj.text.length());
          len += obj.text.length(); /*text: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.photo_name.length());
          len += obj.photo_name.length(); /*photo_name: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::AddPage: { /*8.5*/
          len += 1; /*0.2*/
          len += stream.sizeOfVarInt(obj.text.length());
          len += obj.text.length(); /*text: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.photo_name.length());
          len += obj.photo_name.length(); /*photo_name: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::DeletePage: { /*8.5*/
          len += 1; /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::SwapPages: { /*8.5*/
          len += 1; /*0.2*/
          len += 1; /*0.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::Sign: { /*8.5*/
          len += stream.sizeOfVarInt(obj.title.length());
          len += obj.title.length(); /*title: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.author.length());
          len += obj.author.length(); /*author: pstring*/ /*4.1*/
          len += stream.sizeOfVarInt(obj.xuid.length());
          len += obj.xuid.length(); /*xuid: pstring*/ /*4.1*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_npc_request(pdef::Stream &stream, const pdef::proto::packet_npc_request &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    len += 1; /*request_type: u8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.command.length());
    len += obj.command.length(); /*command: pstring*/ /*4.1*/
    len += 1; /*action_type: u8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.scene_name.length());
    len += obj.scene_name.length(); /*scene_name: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_photo_transfer(pdef::Stream &stream, const pdef::proto::packet_photo_transfer &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.image_name.length());
    len += obj.image_name.length(); /*image_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.image_data.length());
    len += obj.image_data.length(); /*image_data: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.book_id.length());
    len += obj.book_id.length(); /*book_id: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.new_photo_name.length());
    len += obj.new_photo_name.length(); /*new_photo_name: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_modal_form_request(pdef::Stream &stream, const pdef::proto::packet_modal_form_request &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.form_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.data.length());
    len += obj.data.length(); /*data: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_modal_form_response(pdef::Stream &stream, const pdef::proto::packet_modal_form_response &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.form_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.data.length());
    len += obj.data.length(); /*data: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_server_settings_request(pdef::Stream &stream, const pdef::proto::packet_server_settings_request &obj) {
    size_t len = 0;
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_server_settings_response(pdef::Stream &stream, const pdef::proto::packet_server_settings_response &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.form_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.data.length());
    len += obj.data.length(); /*data: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_show_profile(pdef::Stream &stream, const pdef::proto::packet_show_profile &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.xuid.length());
    len += obj.xuid.length(); /*xuid: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_default_game_type(pdef::Stream &stream, const pdef::proto::packet_set_default_game_type &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.gamemode); /*gamemode: zigzag32*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_remove_objective(pdef::Stream &stream, const pdef::proto::packet_remove_objective &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.objective_name.length());
    len += obj.objective_name.length(); /*objective_name: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_display_objective(pdef::Stream &stream, const pdef::proto::packet_set_display_objective &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.display_slot.length());
    len += obj.display_slot.length(); /*display_slot: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.objective_name.length());
    len += obj.objective_name.length(); /*objective_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.display_name.length());
    len += obj.display_name.length(); /*display_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.criteria_name.length());
    len += obj.criteria_name.length(); /*criteria_name: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarInt(obj.sort_order); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_score(pdef::Stream &stream, const pdef::proto::packet_set_score &obj) {
    size_t len = 0;
    const pdef::proto::packet_set_score::Action &action = obj.action; /*0.3*/
    len += 1; /*action^: u8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.entries.size()); /*1.3*/
    for (const auto &v2 : obj.entries) { /*5.20*/
      len += stream.sizeOfZigZagVarLong(v2.scoreboard_id); /*0.2*/
      len += stream.sizeOfVarInt(v2.objective_name.length());
      len += v2.objective_name.length(); /*objective_name: pstring*/ /*4.1*/
      len += 4; /*0.2*/
      switch (action) { /*8.0*/
        case pdef::proto::packet_set_score::Action::Change: { /*8.5*/
            const pdef::proto::packet_set_score::Entries::EntryType &entry_type = v2.entry_type; /*0.3*/
            len += 1; /*entry_type^: i8*/ /*7.0*/
            switch (entry_type) { /*8.0*/
              case pdef::proto::packet_set_score::Entries::EntryType::Player: { /*8.5*/
                len += stream.sizeOfZigZagVarLong(v2.entity_unique_id); /*0.2*/
                break;
              } /*8.7*/
              case pdef::proto::packet_set_score::Entries::EntryType::Entity: { /*8.5*/
                len += stream.sizeOfZigZagVarLong(v2.entity_unique_id); /*0.2*/
                break;
              } /*8.7*/
              default: break; /*avoid unhandled case warning*/
            } /*8.8*/
            switch (entry_type) { /*8.0*/
              case pdef::proto::packet_set_score::Entries::EntryType::FakePlayer: { /*8.5*/
                len += stream.sizeOfVarInt(v2.custom_name.length());
                len += v2.custom_name.length(); /*custom_name: pstring*/ /*4.1*/
                break;
              } /*8.7*/
              default: break; /*avoid unhandled case warning*/
            } /*8.8*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_lab_table(pdef::Stream &stream, const pdef::proto::packet_lab_table &obj) {
    size_t len = 0;
    len += 1; /*action_type: u8*/ /*7.0*/
    size_t len_126 = pdef::proto::size::vec3i(stream, obj.position); EXPECT_OR_BAIL(len_126); len += len_126; /*position*/ /*4.4*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_block_synced(pdef::Stream &stream, const pdef::proto::packet_update_block_synced &obj) {
    size_t len = 0;
    size_t len_127 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_127); len += len_127; /*position*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.block_runtime_id); /*0.2*/
    int flags_val = 0; /*X*/
    if (obj.flags.neighbors) flags_val |= 1;
    if (obj.flags.network) flags_val |= 2;
    if (obj.flags.no_graphic) flags_val |= 4;
    if (obj.flags.unused) flags_val |= 8;
    if (obj.flags.priority) flags_val |= 16;
    len += stream.sizeOfVarInt(flags_val); /*flags: bitflags*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.layer); /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.entity_unique_id); /*0.2*/
    len += stream.sizeOfVarInt((int&)obj.transition_type); /*transition_type: varint*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_move_entity_delta(pdef::Stream &stream, const pdef::proto::packet_move_entity_delta &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    uint16_t flags_val = 0; /*X*/
    if (obj.flags.has_x) flags_val |= 1;
    if (obj.flags.has_y) flags_val |= 2;
    if (obj.flags.has_z) flags_val |= 4;
    if (obj.flags.has_rot_x) flags_val |= 8;
    if (obj.flags.has_rot_y) flags_val |= 16;
    if (obj.flags.has_rot_z) flags_val |= 32;
    if (obj.flags.on_ground) flags_val |= 64;
    if (obj.flags.teleport) flags_val |= 128;
    if (obj.flags.force_move) flags_val |= 256;
    len += 2; /*flags^: bitflags*/ /*4.1*/
    const pdef::proto::packet_move_entity_delta::flags_t &flags = obj.flags; /*0.1*/
    if (flags.has_x == true) { /*8.2*/
      len += 4; /*0.2*/
    }
    if (flags.has_y == true) { /*8.2*/
      len += 4; /*0.2*/
    }
    if (flags.has_z == true) { /*8.2*/
      len += 4; /*0.2*/
    }
    if (flags.has_rot_x == true) { /*8.2*/
      len += 1; /*0.2*/
    }
    if (flags.has_rot_y == true) { /*8.2*/
      len += 1; /*0.2*/
    }
    if (flags.has_rot_z == true) { /*8.2*/
      len += 1; /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_scoreboard_identity(pdef::Stream &stream, const pdef::proto::packet_set_scoreboard_identity &obj) {
    size_t len = 0;
    const pdef::proto::packet_set_scoreboard_identity::Action &action = obj.action; /*0.3*/
    len += 1; /*action^: i8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.entries.size()); /*1.3*/
    for (const auto &v2 : obj.entries) { /*5.20*/
      len += stream.sizeOfZigZagVarLong(v2.scoreboard_id); /*0.2*/
      switch (action) { /*8.0*/
        case pdef::proto::packet_set_scoreboard_identity::Action::RegisterIdentity: { /*8.5*/
          len += stream.sizeOfZigZagVarLong(v2.entity_unique_id); /*0.2*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_set_local_player_as_initialized(pdef::Stream &stream, const pdef::proto::packet_set_local_player_as_initialized &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_entity_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_soft_enum(pdef::Stream &stream, const pdef::proto::packet_update_soft_enum &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.enum_type.length());
    len += obj.enum_type.length(); /*enum_type: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.options.size()); /*1.3*/
    for (const auto &v2 : obj.options) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    len += 1; /*action_type: u8*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_network_stack_latency(pdef::Stream &stream, const pdef::proto::packet_network_stack_latency &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_script_custom_event(pdef::Stream &stream, const pdef::proto::packet_script_custom_event &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.event_name.length());
    len += obj.event_name.length(); /*event_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.event_data.length());
    len += obj.event_data.length(); /*event_data: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_spawn_particle_effect(pdef::Stream &stream, const pdef::proto::packet_spawn_particle_effect &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.entity_id); /*0.2*/
    size_t len_128 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_128); len += len_128; /*position*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.particle_name.length());
    len += obj.particle_name.length(); /*particle_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.molang_variables.size());
    len += obj.molang_variables.size(); /*molang_variables: buffer*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_available_entity_identifiers(pdef::Stream &stream, const pdef::proto::packet_available_entity_identifiers &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_level_sound_event_v2(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_v2 &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    size_t len_129 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_129); len += len_129; /*position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.block_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.entity_type.length());
    len += obj.entity_type.length(); /*entity_type: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_network_chunk_publisher_update(pdef::Stream &stream, const pdef::proto::packet_network_chunk_publisher_update &obj) {
    size_t len = 0;
    size_t len_130 = pdef::proto::size::BlockCoordinates(stream, obj.coordinates); EXPECT_OR_BAIL(len_130); len += len_130; /*coordinates*/ /*4.4*/
    len += stream.sizeOfVarInt(obj.radius); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_biome_definition_list(pdef::Stream &stream, const pdef::proto::packet_biome_definition_list &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_level_sound_event(pdef::Stream &stream, const pdef::proto::packet_level_sound_event &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt((int&)obj.sound_id); /*sound_id: varint*/ /*7.0*/
    size_t len_131 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_131); len += len_131; /*position*/ /*4.4*/
    len += stream.sizeOfZigZagVarInt(obj.extra_data); /*0.2*/
    len += stream.sizeOfVarInt(obj.entity_type.length());
    len += obj.entity_type.length(); /*entity_type: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_level_event_generic(pdef::Stream &stream, const pdef::proto::packet_level_event_generic &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.event_id); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_lectern_update(pdef::Stream &stream, const pdef::proto::packet_lectern_update &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    size_t len_132 = pdef::proto::size::vec3i(stream, obj.position); EXPECT_OR_BAIL(len_132); len += len_132; /*position*/ /*4.4*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_video_stream_connect(pdef::Stream &stream, const pdef::proto::packet_video_stream_connect &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.server_uri.length());
    len += obj.server_uri.length(); /*server_uri: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += 1; /*action: u8*/ /*7.0*/
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_add_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_add_ecs_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.network_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_remove_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_remove_ecs_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.network_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_client_cache_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_status &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_on_screen_texture_animation(pdef::Stream &stream, const pdef::proto::packet_on_screen_texture_animation &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_map_create_locked_copy(pdef::Stream &stream, const pdef::proto::packet_map_create_locked_copy &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.original_map_id); /*0.2*/
    len += stream.sizeOfZigZagVarLong(obj.new_map_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_structure_template_data_export_request(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_request &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    size_t len_133 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_133); len += len_133; /*position*/ /*4.4*/
    size_t len_134 = pdef::proto::size::StructureBlockSettings(stream, obj.settings); EXPECT_OR_BAIL(len_134); len += len_134; /*settings*/ /*4.4*/
    len += 1; /*request_type: u8*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_structure_template_data_export_response(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_response &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.name.length());
    len += obj.name.length(); /*name: pstring*/ /*4.1*/
    const bool &success = obj.success; /*0.1*/
    if (success == true) { /*8.1*/
      len += 1; /*0.2*/
    }
    len += 1; /*response_type: u8*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_block_properties(pdef::Stream &stream, const pdef::proto::packet_update_block_properties &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_client_cache_blob_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_blob_status &obj) {
    size_t len = 0;
    const int &misses = obj.misses; /*0.1*/
    const int &haves = obj.haves; /*0.1*/
    len += stream.sizeOfVarInt(misses); /*1.1*/
    for (const auto &v2 : obj.missing) {
      len += 8; /*0.2*/
    }
    len += stream.sizeOfVarInt(haves); /*1.1*/
    for (const auto &v2 : obj.have) {
      len += 8; /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_client_cache_miss_response(pdef::Stream &stream, const pdef::proto::packet_client_cache_miss_response &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.blobs.size()); /*1.3*/
    for (const auto &v2 : obj.blobs) {
      size_t len_135 = pdef::proto::size::Blob(stream, v2); EXPECT_OR_BAIL(len_135); len += len_135; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_education_settings(pdef::Stream &stream, const pdef::proto::packet_education_settings &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.CodeBuilderDefaultURI.length());
    len += obj.CodeBuilderDefaultURI.length(); /*CodeBuilderDefaultURI: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.CodeBuilderTitle.length());
    len += obj.CodeBuilderTitle.length(); /*CodeBuilderTitle: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.post_process_filter.length());
    len += obj.post_process_filter.length(); /*post_process_filter: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.screenshot_border_path.length());
    len += obj.screenshot_border_path.length(); /*screenshot_border_path: pstring*/ /*4.1*/
    const bool &has_agent_capabilities = obj.has_agent_capabilities; /*0.1*/
    if (has_agent_capabilities == true) { /*8.1*/
        EXPECT_OR_BAIL(obj.agent_capabilities); const pdef::proto::packet_education_settings::AgentCapabilities &v = *obj.agent_capabilities; /*8.6*/
        len += 1; /*0.2*/
        len += 1; /*0.2*/
    }
    const bool &HasOverrideURI = obj.HasOverrideURI; /*0.1*/
    if (HasOverrideURI == true) { /*8.1*/
      len += stream.sizeOfVarInt(obj.OverrideURI.length());
      len += obj.OverrideURI.length(); /*OverrideURI: pstring*/ /*4.1*/
    }
    len += 1; /*0.2*/
    const bool &has_external_link_settings = obj.has_external_link_settings; /*0.1*/
    if (has_external_link_settings == true) { /*8.1*/
        EXPECT_OR_BAIL(obj.external_link_settings); const pdef::proto::packet_education_settings::ExternalLinkSettings &v = *obj.external_link_settings; /*8.6*/
        len += 1; /*0.2*/
        len += stream.sizeOfVarInt(v.url.length());
        len += v.url.length(); /*url: pstring*/ /*4.1*/
        len += stream.sizeOfVarInt(v.display_name.length());
        len += v.display_name.length(); /*display_name: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_emote(pdef::Stream &stream, const pdef::proto::packet_emote &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.entity_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.emote_id.length());
    len += obj.emote_id.length(); /*emote_id: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_multiplayer_settings(pdef::Stream &stream, const pdef::proto::packet_multiplayer_settings &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.action_type); /*action_type: zigzag32*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_settings_command(pdef::Stream &stream, const pdef::proto::packet_settings_command &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.command_line.length());
    len += obj.command_line.length(); /*command_line: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_anvil_damage(pdef::Stream &stream, const pdef::proto::packet_anvil_damage &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    size_t len_136 = pdef::proto::size::BlockCoordinates(stream, obj.position); EXPECT_OR_BAIL(len_136); len += len_136; /*position*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_completed_using_item(pdef::Stream &stream, const pdef::proto::packet_completed_using_item &obj) {
    size_t len = 0;
    len += 2; /*0.2*/
    len += 4; /*use_method: li32*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_network_settings(pdef::Stream &stream, const pdef::proto::packet_network_settings &obj) {
    size_t len = 0;
    len += 2; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_auth_input(pdef::Stream &stream, const pdef::proto::packet_player_auth_input &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    size_t len_137 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_137); len += len_137; /*position*/ /*4.4*/
    size_t len_138 = pdef::proto::size::vec2f(stream, obj.move_vector); EXPECT_OR_BAIL(len_138); len += len_138; /*move_vector*/ /*4.4*/
    len += 4; /*0.2*/
    int64_t input_data_val = 0; /*X*/
    input_data_val |= (int64_t)obj.input_data.ascend << 0;
    input_data_val |= (int64_t)obj.input_data.descend << 1;
    input_data_val |= (int64_t)obj.input_data.north_jump << 2;
    input_data_val |= (int64_t)obj.input_data.jump_down << 3;
    input_data_val |= (int64_t)obj.input_data.sprint_down << 4;
    input_data_val |= (int64_t)obj.input_data.change_height << 5;
    input_data_val |= (int64_t)obj.input_data.jumping << 6;
    input_data_val |= (int64_t)obj.input_data.auto_jumping_in_water << 7;
    input_data_val |= (int64_t)obj.input_data.sneaking << 8;
    input_data_val |= (int64_t)obj.input_data.sneak_down << 9;
    input_data_val |= (int64_t)obj.input_data.up << 10;
    input_data_val |= (int64_t)obj.input_data.down << 11;
    input_data_val |= (int64_t)obj.input_data.left << 12;
    input_data_val |= (int64_t)obj.input_data.right << 13;
    input_data_val |= (int64_t)obj.input_data.up_left << 14;
    input_data_val |= (int64_t)obj.input_data.up_right << 15;
    input_data_val |= (int64_t)obj.input_data.want_up << 16;
    input_data_val |= (int64_t)obj.input_data.want_down << 17;
    input_data_val |= (int64_t)obj.input_data.want_down_slow << 18;
    input_data_val |= (int64_t)obj.input_data.want_up_slow << 19;
    input_data_val |= (int64_t)obj.input_data.sprinting << 20;
    input_data_val |= (int64_t)obj.input_data.ascend_block << 21;
    input_data_val |= (int64_t)obj.input_data.descend_block << 22;
    input_data_val |= (int64_t)obj.input_data.sneak_toggle_down << 23;
    input_data_val |= (int64_t)obj.input_data.persist_sneak << 24;
    input_data_val |= (int64_t)obj.input_data.start_sprinting << 25;
    input_data_val |= (int64_t)obj.input_data.stop_sprinting << 26;
    input_data_val |= (int64_t)obj.input_data.start_sneaking << 27;
    input_data_val |= (int64_t)obj.input_data.stop_sneaking << 28;
    input_data_val |= (int64_t)obj.input_data.start_swimming << 29;
    input_data_val |= (int64_t)obj.input_data.stop_swimming << 30;
    input_data_val |= (int64_t)obj.input_data.start_jumping << 31;
    input_data_val |= (int64_t)obj.input_data.start_gliding << 32;
    input_data_val |= (int64_t)obj.input_data.stop_gliding << 33;
    input_data_val |= (int64_t)obj.input_data.item_interact << 34;
    input_data_val |= (int64_t)obj.input_data.block_action << 35;
    input_data_val |= (int64_t)obj.input_data.item_stack_request << 36;
    len += stream.sizeOfVarInt64(input_data_val); /*input_data^: bitflags*/ /*4.1*/
    const pdef::proto::packet_player_auth_input::input_data_t &input_data = obj.input_data; /*0.1*/
    len += stream.sizeOfVarInt((int&)obj.input_mode); /*input_mode: varint*/ /*7.0*/
    const pdef::proto::packet_player_auth_input::PlayMode &play_mode = obj.play_mode; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.play_mode); /*play_mode^: varint*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt((int&)obj.interaction_model); /*interaction_model: zigzag32*/ /*7.0*/
    switch (play_mode) { /*8.0*/
      case pdef::proto::packet_player_auth_input::PlayMode::Reality: { /*8.5*/
        EXPECT_OR_BAIL(obj.gaze_direction); size_t len_139 = pdef::proto::size::vec3f(stream, *obj.gaze_direction); EXPECT_OR_BAIL(len_139); len += len_139; /*gaze_direction*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    len += stream.sizeOfVarInt64(obj.tick); /*0.2*/
    size_t len_140 = pdef::proto::size::vec3f(stream, obj.delta); EXPECT_OR_BAIL(len_140); len += len_140; /*delta*/ /*4.4*/
    if (input_data.item_interact == true) { /*8.2*/
        EXPECT_OR_BAIL(obj.transaction); const pdef::proto::packet_player_auth_input::Transaction &v = *obj.transaction; /*8.6*/
        size_t len_141 = pdef::proto::size::TransactionLegacy(stream, v.legacy); EXPECT_OR_BAIL(len_141); len += len_141; /*legacy*/ /*4.4*/
        len += stream.sizeOfVarInt(v.actions.size()); /*2.4*/
        for (const auto &v : v.actions) { size_t len_142 = pdef::proto::size::TransactionActions(stream, v); EXPECT_OR_BAIL(len_142); len += len_142; } /*2.5*/
        size_t len_143 = pdef::proto::size::TransactionUseItem(stream, v.data); EXPECT_OR_BAIL(len_143); len += len_143; /*data*/ /*4.4*/
    }
    if (input_data.item_stack_request == true) { /*8.2*/
      EXPECT_OR_BAIL(obj.item_stack_request); size_t len_144 = pdef::proto::size::ItemStackRequest(stream, *obj.item_stack_request); EXPECT_OR_BAIL(len_144); len += len_144; /*item_stack_request*/ /*4.4*/
    }
    if (input_data.block_action == true) { /*8.2*/
      len += stream.sizeOfZigZagVarInt(obj.block_action.size()); /*1.3*/
      for (const auto &v3 : obj.block_action) { /*5.20*/
        const pdef::proto::packet_player_auth_input::BlockAction::Action &action = v3.action; /*0.3*/
        len += stream.sizeOfZigZagVarInt((int&)v3.action); /*action^: zigzag32*/ /*7.0*/
        if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::StartBreak) { /*8.5*/
            EXPECT_OR_BAIL(v3.position); size_t len_145 = pdef::proto::size::vec3i(stream, *v3.position); EXPECT_OR_BAIL(len_145); len += len_145; /*position*/ /*4.4*/
            len += stream.sizeOfZigZagVarInt(v3.face); /*0.2*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::AbortBreak) { /*8.5*/
            EXPECT_OR_BAIL(v3.position); size_t len_146 = pdef::proto::size::vec3i(stream, *v3.position); EXPECT_OR_BAIL(len_146); len += len_146; /*position*/ /*4.4*/
            len += stream.sizeOfZigZagVarInt(v3.face); /*0.2*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::CrackBreak) { /*8.5*/
            EXPECT_OR_BAIL(v3.position); size_t len_147 = pdef::proto::size::vec3i(stream, *v3.position); EXPECT_OR_BAIL(len_147); len += len_147; /*position*/ /*4.4*/
            len += stream.sizeOfZigZagVarInt(v3.face); /*0.2*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::PredictBreak) { /*8.5*/
            EXPECT_OR_BAIL(v3.position); size_t len_148 = pdef::proto::size::vec3i(stream, *v3.position); EXPECT_OR_BAIL(len_148); len += len_148; /*position*/ /*4.4*/
            len += stream.sizeOfZigZagVarInt(v3.face); /*0.2*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::ContinueBreak) { /*8.5*/
            EXPECT_OR_BAIL(v3.position); size_t len_149 = pdef::proto::size::vec3i(stream, *v3.position); EXPECT_OR_BAIL(len_149); len += len_149; /*position*/ /*4.4*/
            len += stream.sizeOfZigZagVarInt(v3.face); /*0.2*/
        }
      }
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_creative_content(pdef::Stream &stream, const pdef::proto::packet_creative_content &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.items.size()); /*1.3*/
    for (const auto &v2 : obj.items) { /*5.20*/
      len += stream.sizeOfVarInt(v2.entry_id); /*0.2*/
      size_t len_150 = pdef::proto::size::ItemLegacy(stream, v2.item); EXPECT_OR_BAIL(len_150); len += len_150; /*item*/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_enchant_options(pdef::Stream &stream, const pdef::proto::packet_player_enchant_options &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.options.size()); /*1.3*/
    for (const auto &v2 : obj.options) {
      size_t len_151 = pdef::proto::size::EnchantOption(stream, v2); EXPECT_OR_BAIL(len_151); len += len_151; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_item_stack_request(pdef::Stream &stream, const pdef::proto::packet_item_stack_request &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.requests.size()); /*1.3*/
    for (const auto &v2 : obj.requests) {
      size_t len_152 = pdef::proto::size::ItemStackRequest(stream, v2); EXPECT_OR_BAIL(len_152); len += len_152; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_item_stack_response(pdef::Stream &stream, const pdef::proto::packet_item_stack_response &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.responses.size()); /*2.4*/
    for (const auto &v : obj.responses) { size_t len_153 = pdef::proto::size::ItemStackResponses(stream, v); EXPECT_OR_BAIL(len_153); len += len_153; } /*2.5*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_armor_damage(pdef::Stream &stream, const pdef::proto::packet_player_armor_damage &obj) {
    size_t len = 0;
    uint8_t type_val = 0; /*X*/
    if (obj.type.head) type_val |= 1;
    if (obj.type.chest) type_val |= 2;
    if (obj.type.legs) type_val |= 4;
    if (obj.type.feet) type_val |= 8;
    len += 1; /*type^: bitflags*/ /*4.1*/
    const pdef::proto::packet_player_armor_damage::type_t &type = obj.type; /*0.1*/
    if (type.head == true) { /*8.2*/
      len += stream.sizeOfZigZagVarInt(obj.helmet_damage); /*0.2*/
    }
    if (type.chest == true) { /*8.2*/
      len += stream.sizeOfZigZagVarInt(obj.chestplate_damage); /*0.2*/
    }
    if (type.legs == true) { /*8.2*/
      len += stream.sizeOfZigZagVarInt(obj.leggings_damage); /*0.2*/
    }
    if (type.feet == true) { /*8.2*/
      len += stream.sizeOfZigZagVarInt(obj.boots_damage); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_player_game_type(pdef::Stream &stream, const pdef::proto::packet_update_player_game_type &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.gamemode); /*gamemode: zigzag32*/ /*7.0*/
    len += stream.sizeOfZigZagVarLong(obj.player_unique_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_emote_list(pdef::Stream &stream, const pdef::proto::packet_emote_list &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.player_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.emote_pieces.size()); /*1.3*/
    for (const auto &v2 : obj.emote_pieces) {
      len += 8; /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_position_tracking_db_request(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_request &obj) {
    size_t len = 0;
    len += 1; /*action: u8*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.tracking_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_position_tracking_db_broadcast(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_broadcast &obj) {
    size_t len = 0;
    len += 1; /*broadcast_action: u8*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.tracking_id); /*0.2*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_packet_violation_warning(pdef::Stream &stream, const pdef::proto::packet_packet_violation_warning &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.violation_type); /*violation_type: zigzag32*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt((int&)obj.severity); /*severity: zigzag32*/ /*7.0*/
    len += stream.sizeOfZigZagVarInt(obj.packet_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.reason.length());
    len += obj.reason.length(); /*reason: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_motion_prediction_hints(pdef::Stream &stream, const pdef::proto::packet_motion_prediction_hints &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.entity_runtime_id); /*0.2*/
    size_t len_154 = pdef::proto::size::vec3f(stream, obj.velocity); EXPECT_OR_BAIL(len_154); len += len_154; /*velocity*/ /*4.4*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_animate_entity(pdef::Stream &stream, const pdef::proto::packet_animate_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.animation.length());
    len += obj.animation.length(); /*animation: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.next_state.length());
    len += obj.next_state.length(); /*next_state: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.stop_condition.length());
    len += obj.stop_condition.length(); /*stop_condition: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.controller.length());
    len += obj.controller.length(); /*controller: pstring*/ /*4.1*/
    len += 4; /*0.2*/
    len += stream.sizeOfVarInt(obj.runtime_entity_ids.size()); /*1.3*/
    for (const auto &v2 : obj.runtime_entity_ids) {
      len += stream.sizeOfVarInt64(v2); /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_camera_shake(pdef::Stream &stream, const pdef::proto::packet_camera_shake &obj) {
    size_t len = 0;
    len += 4; /*0.2*/
    len += 4; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*action: u8*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_player_fog(pdef::Stream &stream, const pdef::proto::packet_player_fog &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.stack.size()); /*1.3*/
    for (const auto &v2 : obj.stack) {
      len += stream.sizeOfVarInt(v2.length());
      len += v2.length(); /*: pstring*/ /*4.1*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_correct_player_move_prediction(pdef::Stream &stream, const pdef::proto::packet_correct_player_move_prediction &obj) {
    size_t len = 0;
    size_t len_155 = pdef::proto::size::vec3f(stream, obj.position); EXPECT_OR_BAIL(len_155); len += len_155; /*position*/ /*4.4*/
    size_t len_156 = pdef::proto::size::vec3f(stream, obj.delta); EXPECT_OR_BAIL(len_156); len += len_156; /*delta*/ /*4.4*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt64(obj.tick); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_item_component(pdef::Stream &stream, const pdef::proto::packet_item_component &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.entries.size()); /*2.4*/
    for (const auto &v : obj.entries) { size_t len_157 = pdef::proto::size::ItemComponentList(stream, v); EXPECT_OR_BAIL(len_157); len += len_157; } /*2.5*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_filter_text_packet(pdef::Stream &stream, const pdef::proto::packet_filter_text_packet &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.text.length());
    len += obj.text.length(); /*text: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_debug_renderer(pdef::Stream &stream, const pdef::proto::packet_debug_renderer &obj) {
    size_t len = 0;
    const pdef::proto::packet_debug_renderer::Type &type = obj.type; /*0.3*/
    len += 4; /*type^: li32*/ /*7.0*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_debug_renderer::Type::Clear: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_debug_renderer::Type::AddCube: { /*8.5*/
          len += stream.sizeOfVarInt(obj.text.length());
          len += obj.text.length(); /*text: pstring*/ /*4.1*/
          EXPECT_OR_BAIL(obj.position); size_t len_158 = pdef::proto::size::vec3f(stream, *obj.position); EXPECT_OR_BAIL(len_158); len += len_158; /*position*/ /*4.4*/
          len += 4; /*0.2*/
          len += 4; /*0.2*/
          len += 4; /*0.2*/
          len += 4; /*0.2*/
          len += 8; /*0.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_sync_entity_property(pdef::Stream &stream, const pdef::proto::packet_sync_entity_property &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_add_volume_entity(pdef::Stream &stream, const pdef::proto::packet_add_volume_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.runtime_id); /*0.2*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.encoding_identifier.length());
    len += obj.encoding_identifier.length(); /*encoding_identifier: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.instance_name.length());
    len += obj.instance_name.length(); /*instance_name: pstring*/ /*4.1*/
    const pdef::proto::packet_add_volume_entity::Bounds &v = obj.bounds; /*["packet_add_volume_entity"]*/ /*7.4*/
    len += stream.sizeOfZigZagVarInt(obj.dimension); /*0.2*/
    len += stream.sizeOfVarInt(obj.engine_version.length());
    len += obj.engine_version.length(); /*engine_version: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_remove_volume_entity(pdef::Stream &stream, const pdef::proto::packet_remove_volume_entity &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt64(obj.entity_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_simulation_type(pdef::Stream &stream, const pdef::proto::packet_simulation_type &obj) {
    size_t len = 0;
    len += 1; /*type: u8*/ /*7.0*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_npc_dialogue(pdef::Stream &stream, const pdef::proto::packet_npc_dialogue &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt((int&)obj.action_type); /*action_type: varint*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.dialogue.length());
    len += obj.dialogue.length(); /*dialogue: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.screen_name.length());
    len += obj.screen_name.length(); /*screen_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.npc_name.length());
    len += obj.npc_name.length(); /*npc_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.action_json.length());
    len += obj.action_json.length(); /*action_json: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_edu_uri_resource_packet(pdef::Stream &stream, const pdef::proto::packet_edu_uri_resource_packet &obj) {
    size_t len = 0;
    size_t len_159 = pdef::proto::size::EducationSharedResourceURI(stream, obj.resource); EXPECT_OR_BAIL(len_159); len += len_159; /*resource*/ /*4.4*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_create_photo(pdef::Stream &stream, const pdef::proto::packet_create_photo &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt(obj.photo_name.length());
    len += obj.photo_name.length(); /*photo_name: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.item_name.length());
    len += obj.item_name.length(); /*item_name: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_update_subchunk_blocks(pdef::Stream &stream, const pdef::proto::packet_update_subchunk_blocks &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.x); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.y); /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.z); /*0.2*/
    len += stream.sizeOfVarInt(obj.blocks.size()); /*1.3*/
    for (const auto &v2 : obj.blocks) {
      size_t len_160 = pdef::proto::size::BlockUpdate(stream, v2); EXPECT_OR_BAIL(len_160); len += len_160; /**/ /*4.4*/
    }
    len += stream.sizeOfVarInt(obj.extra.size()); /*1.3*/
    for (const auto &v2 : obj.extra) {
      size_t len_161 = pdef::proto::size::BlockUpdate(stream, v2); EXPECT_OR_BAIL(len_161); len += len_161; /**/ /*4.4*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_photo_info_request(pdef::Stream &stream, const pdef::proto::packet_photo_info_request &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.photo_id); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
size_t SubChunkEntryWithoutCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithoutCaching &obj) {
  size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*result: u8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.payload.size());
    len += obj.payload.size(); /*payload: buffer*/ /*4.1*/
    const pdef::proto::SubChunkEntryWithoutCaching::HeightmapType &heightmap_type = obj.heightmap_type; /*0.3*/
    len += 1; /*heightmap_type^: u8*/ /*7.0*/
    switch (heightmap_type) { /*8.0*/
      case pdef::proto::SubChunkEntryWithoutCaching::HeightmapType::HasData: { /*8.5*/
        len += 256; /*heightmap: buffer*/ /*4.1*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
size_t SubChunkEntryWithCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithCaching &obj) {
  size_t len = 0;
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    len += 1; /*0.2*/
    const pdef::proto::SubChunkEntryWithCaching::Result &result = obj.result; /*0.3*/
    len += 1; /*result^: u8*/ /*7.0*/
    switch (result) { /*8.0*/
      case pdef::proto::SubChunkEntryWithCaching::Result::SuccessAllAir: { /*8.5*/
        break;
      } /*8.7*/
      default: { /*8.3*/
        len += stream.sizeOfVarInt(obj.payload.size());
        len += obj.payload.size(); /*payload: buffer*/ /*4.1*/
        break;
      } /*8.7*/
    } /*8.8*/
    const pdef::proto::SubChunkEntryWithCaching::HeightmapType &heightmap_type = obj.heightmap_type; /*0.3*/
    len += 1; /*heightmap_type^: u8*/ /*7.0*/
    switch (heightmap_type) { /*8.0*/
      case pdef::proto::SubChunkEntryWithCaching::HeightmapType::HasData: { /*8.5*/
        len += 256; /*heightmap: buffer*/ /*4.1*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    len += 8; /*0.2*/
  DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
}
  size_t packet_subchunk(pdef::Stream &stream, const pdef::proto::packet_subchunk &obj) {
    size_t len = 0;
    const bool &cache_enabled = obj.cache_enabled; /*0.1*/
    len += stream.sizeOfZigZagVarInt(obj.dimension); /*0.2*/
    size_t len_162 = pdef::proto::size::vec3i(stream, obj.origin); EXPECT_OR_BAIL(len_162); len += len_162; /*origin*/ /*4.4*/
    if (cache_enabled == true) { /*8.1*/
      len += 4; /*2.4*/
      for (const auto &v : obj.entries_SubChunkEntryWithCaching) { size_t len_163 = pdef::proto::size::SubChunkEntryWithCaching(stream, v); EXPECT_OR_BAIL(len_163); len += len_163; } /*2.5*/
    }
    else if (cache_enabled == false) { /*8.1*/
      len += 4; /*2.4*/
      for (const auto &v : obj.entries_SubChunkEntryWithoutCaching) { size_t len_164 = pdef::proto::size::SubChunkEntryWithoutCaching(stream, v); EXPECT_OR_BAIL(len_164); len += len_164; } /*2.5*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_subchunk_request(pdef::Stream &stream, const pdef::proto::packet_subchunk_request &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt(obj.dimension); /*0.2*/
    size_t len_165 = pdef::proto::size::vec3i(stream, obj.origin); EXPECT_OR_BAIL(len_165); len += len_165; /*origin*/ /*4.4*/
    len += 4; /*1.3*/
    for (const auto &v2 : obj.requests) { /*5.20*/
      len += 1; /*0.2*/
      len += 1; /*0.2*/
      len += 1; /*0.2*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_client_start_item_cooldown(pdef::Stream &stream, const pdef::proto::packet_client_start_item_cooldown &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.category.length());
    len += obj.category.length(); /*category: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarInt(obj.duration); /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_script_message(pdef::Stream &stream, const pdef::proto::packet_script_message &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.message_id.length());
    len += obj.message_id.length(); /*message_id: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.data.length());
    len += obj.data.length(); /*data: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_code_builder_source(pdef::Stream &stream, const pdef::proto::packet_code_builder_source &obj) {
    size_t len = 0;
    len += 1; /*operation: u8*/ /*7.0*/
    len += 1; /*category: u8*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.value.length());
    len += obj.value.length(); /*value: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_ticking_areas_load_status(pdef::Stream &stream, const pdef::proto::packet_ticking_areas_load_status &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_dimension_data(pdef::Stream &stream, const pdef::proto::packet_dimension_data &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.definitions.size()); /*1.3*/
    for (const auto &v2 : obj.definitions) { /*5.20*/
      len += stream.sizeOfVarInt(v2.id.length());
      len += v2.id.length(); /*id: pstring*/ /*4.1*/
      len += stream.sizeOfZigZagVarInt(v2.max_height); /*0.2*/
      len += stream.sizeOfZigZagVarInt(v2.min_height); /*0.2*/
      len += stream.sizeOfZigZagVarInt((int&)v2.generator); /*generator: zigzag32*/ /*7.0*/
    }
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_agent_action(pdef::Stream &stream, const pdef::proto::packet_agent_action &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.request_id.length());
    len += obj.request_id.length(); /*request_id: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarInt((int&)obj.action_type); /*action_type: zigzag32*/ /*7.0*/
    len += stream.sizeOfVarInt(obj.body.length());
    len += obj.body.length(); /*body: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_change_mob_property(pdef::Stream &stream, const pdef::proto::packet_change_mob_property &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarLong(obj.entity_unique_id); /*0.2*/
    len += stream.sizeOfVarInt(obj.property.length());
    len += obj.property.length(); /*property: pstring*/ /*4.1*/
    len += 1; /*0.2*/
    len += stream.sizeOfVarInt(obj.string_value.length());
    len += obj.string_value.length(); /*string_value: pstring*/ /*4.1*/
    len += stream.sizeOfZigZagVarInt(obj.int_value); /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_lesson_progress(pdef::Stream &stream, const pdef::proto::packet_lesson_progress &obj) {
    size_t len = 0;
    len += 1; /*0.2*/
    len += stream.sizeOfZigZagVarInt(obj.score); /*0.2*/
    len += stream.sizeOfVarInt(obj.identifier.length());
    len += obj.identifier.length(); /*identifier: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_request_ability(pdef::Stream &stream, const pdef::proto::packet_request_ability &obj) {
    size_t len = 0;
    len += stream.sizeOfZigZagVarInt((int&)obj.ability); /*ability: zigzag32*/ /*7.0*/
    len += 1; /*value_type: u8*/ /*7.0*/
    len += 1; /*0.2*/
    len += 4; /*0.2*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_request_permissions(pdef::Stream &stream, const pdef::proto::packet_request_permissions &obj) {
    size_t len = 0;
    len += 8; /*0.2*/
    len += stream.sizeOfVarInt((int&)obj.permission_level); /*permission_level: varint*/ /*7.0*/
    uint16_t requested_permissions_val = 0; /*X*/
    if (obj.requested_permissions.build) requested_permissions_val |= 1;
    if (obj.requested_permissions.mine) requested_permissions_val |= 2;
    if (obj.requested_permissions.doors_and_switches) requested_permissions_val |= 4;
    if (obj.requested_permissions.open_containers) requested_permissions_val |= 8;
    if (obj.requested_permissions.attack_players) requested_permissions_val |= 16;
    if (obj.requested_permissions.attack_mobs) requested_permissions_val |= 32;
    if (obj.requested_permissions.operator_) requested_permissions_val |= 64;
    if (obj.requested_permissions.teleport) requested_permissions_val |= 128;
    len += 2; /*requested_permissions: bitflags*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t packet_toast_request(pdef::Stream &stream, const pdef::proto::packet_toast_request &obj) {
    size_t len = 0;
    len += stream.sizeOfVarInt(obj.title.length());
    len += obj.title.length(); /*title: pstring*/ /*4.1*/
    len += stream.sizeOfVarInt(obj.message.length());
    len += obj.message.length(); /*message: pstring*/ /*4.1*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
  size_t mcpe_packet(pdef::Stream &stream, const pdef::proto::mcpe_packet &obj) {
    size_t len = 0;
    const pdef::proto::mcpe_packet::Name &name = obj.name; /*0.3*/
    len += stream.sizeOfVarInt((int&)obj.name); /*name^: varint*/ /*7.0*/
    switch (name) { /*8.0*/
      case pdef::proto::mcpe_packet::Name::Login: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_login); size_t len_166 = pdef::proto::size::packet_login(stream, *obj.params_packet_login); EXPECT_OR_BAIL(len_166); len += len_166; /*params_packet_login*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayStatus: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_play_status); size_t len_167 = pdef::proto::size::packet_play_status(stream, *obj.params_packet_play_status); EXPECT_OR_BAIL(len_167); len += len_167; /*params_packet_play_status*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerToClientHandshake: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_server_to_client_handshake); size_t len_168 = pdef::proto::size::packet_server_to_client_handshake(stream, *obj.params_packet_server_to_client_handshake); EXPECT_OR_BAIL(len_168); len += len_168; /*params_packet_server_to_client_handshake*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientToServerHandshake: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_client_to_server_handshake); size_t len_169 = pdef::proto::size::packet_client_to_server_handshake(stream, *obj.params_packet_client_to_server_handshake); EXPECT_OR_BAIL(len_169); len += len_169; /*params_packet_client_to_server_handshake*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Disconnect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_disconnect); size_t len_170 = pdef::proto::size::packet_disconnect(stream, *obj.params_packet_disconnect); EXPECT_OR_BAIL(len_170); len += len_170; /*params_packet_disconnect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePacksInfo: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_packs_info); size_t len_171 = pdef::proto::size::packet_resource_packs_info(stream, *obj.params_packet_resource_packs_info); EXPECT_OR_BAIL(len_171); len += len_171; /*params_packet_resource_packs_info*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackStack: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_pack_stack); size_t len_172 = pdef::proto::size::packet_resource_pack_stack(stream, *obj.params_packet_resource_pack_stack); EXPECT_OR_BAIL(len_172); len += len_172; /*params_packet_resource_pack_stack*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackClientResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_pack_client_response); size_t len_173 = pdef::proto::size::packet_resource_pack_client_response(stream, *obj.params_packet_resource_pack_client_response); EXPECT_OR_BAIL(len_173); len += len_173; /*params_packet_resource_pack_client_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Text: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_text); size_t len_174 = pdef::proto::size::packet_text(stream, *obj.params_packet_text); EXPECT_OR_BAIL(len_174); len += len_174; /*params_packet_text*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetTime: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_time); size_t len_175 = pdef::proto::size::packet_set_time(stream, *obj.params_packet_set_time); EXPECT_OR_BAIL(len_175); len += len_175; /*params_packet_set_time*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StartGame: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_start_game); size_t len_176 = pdef::proto::size::packet_start_game(stream, *obj.params_packet_start_game); EXPECT_OR_BAIL(len_176); len += len_176; /*params_packet_start_game*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddPlayer: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_add_player); size_t len_177 = pdef::proto::size::packet_add_player(stream, *obj.params_packet_add_player); EXPECT_OR_BAIL(len_177); len += len_177; /*params_packet_add_player*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_add_entity); size_t len_178 = pdef::proto::size::packet_add_entity(stream, *obj.params_packet_add_entity); EXPECT_OR_BAIL(len_178); len += len_178; /*params_packet_add_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_remove_entity); size_t len_179 = pdef::proto::size::packet_remove_entity(stream, *obj.params_packet_remove_entity); EXPECT_OR_BAIL(len_179); len += len_179; /*params_packet_remove_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddItemEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_add_item_entity); size_t len_180 = pdef::proto::size::packet_add_item_entity(stream, *obj.params_packet_add_item_entity); EXPECT_OR_BAIL(len_180); len += len_180; /*params_packet_add_item_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TakeItemEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_take_item_entity); size_t len_181 = pdef::proto::size::packet_take_item_entity(stream, *obj.params_packet_take_item_entity); EXPECT_OR_BAIL(len_181); len += len_181; /*params_packet_take_item_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MoveEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_move_entity); size_t len_182 = pdef::proto::size::packet_move_entity(stream, *obj.params_packet_move_entity); EXPECT_OR_BAIL(len_182); len += len_182; /*params_packet_move_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MovePlayer: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_move_player); size_t len_183 = pdef::proto::size::packet_move_player(stream, *obj.params_packet_move_player); EXPECT_OR_BAIL(len_183); len += len_183; /*params_packet_move_player*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RiderJump: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_rider_jump); size_t len_184 = pdef::proto::size::packet_rider_jump(stream, *obj.params_packet_rider_jump); EXPECT_OR_BAIL(len_184); len += len_184; /*params_packet_rider_jump*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlock: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_block); size_t len_185 = pdef::proto::size::packet_update_block(stream, *obj.params_packet_update_block); EXPECT_OR_BAIL(len_185); len += len_185; /*params_packet_update_block*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddPainting: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_add_painting); size_t len_186 = pdef::proto::size::packet_add_painting(stream, *obj.params_packet_add_painting); EXPECT_OR_BAIL(len_186); len += len_186; /*params_packet_add_painting*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TickSync: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_tick_sync); size_t len_187 = pdef::proto::size::packet_tick_sync(stream, *obj.params_packet_tick_sync); EXPECT_OR_BAIL(len_187); len += len_187; /*params_packet_tick_sync*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEventOld: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_level_sound_event_old); size_t len_188 = pdef::proto::size::packet_level_sound_event_old(stream, *obj.params_packet_level_sound_event_old); EXPECT_OR_BAIL(len_188); len += len_188; /*params_packet_level_sound_event_old*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_level_event); size_t len_189 = pdef::proto::size::packet_level_event(stream, *obj.params_packet_level_event); EXPECT_OR_BAIL(len_189); len += len_189; /*params_packet_level_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_event); size_t len_190 = pdef::proto::size::packet_block_event(stream, *obj.params_packet_block_event); EXPECT_OR_BAIL(len_190); len += len_190; /*params_packet_block_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EntityEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_event); size_t len_191 = pdef::proto::size::packet_entity_event(stream, *obj.params_packet_entity_event); EXPECT_OR_BAIL(len_191); len += len_191; /*params_packet_entity_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_mob_effect); size_t len_192 = pdef::proto::size::packet_mob_effect(stream, *obj.params_packet_mob_effect); EXPECT_OR_BAIL(len_192); len += len_192; /*params_packet_mob_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateAttributes: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_attributes); size_t len_193 = pdef::proto::size::packet_update_attributes(stream, *obj.params_packet_update_attributes); EXPECT_OR_BAIL(len_193); len += len_193; /*params_packet_update_attributes*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventoryTransaction: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_inventory_transaction); size_t len_194 = pdef::proto::size::packet_inventory_transaction(stream, *obj.params_packet_inventory_transaction); EXPECT_OR_BAIL(len_194); len += len_194; /*params_packet_inventory_transaction*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobEquipment: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_mob_equipment); size_t len_195 = pdef::proto::size::packet_mob_equipment(stream, *obj.params_packet_mob_equipment); EXPECT_OR_BAIL(len_195); len += len_195; /*params_packet_mob_equipment*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobArmorEquipment: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_mob_armor_equipment); size_t len_196 = pdef::proto::size::packet_mob_armor_equipment(stream, *obj.params_packet_mob_armor_equipment); EXPECT_OR_BAIL(len_196); len += len_196; /*params_packet_mob_armor_equipment*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Interact: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_interact); size_t len_197 = pdef::proto::size::packet_interact(stream, *obj.params_packet_interact); EXPECT_OR_BAIL(len_197); len += len_197; /*params_packet_interact*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockPickRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_pick_request); size_t len_198 = pdef::proto::size::packet_block_pick_request(stream, *obj.params_packet_block_pick_request); EXPECT_OR_BAIL(len_198); len += len_198; /*params_packet_block_pick_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EntityPickRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_entity_pick_request); size_t len_199 = pdef::proto::size::packet_entity_pick_request(stream, *obj.params_packet_entity_pick_request); EXPECT_OR_BAIL(len_199); len += len_199; /*params_packet_entity_pick_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerAction: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_action); size_t len_200 = pdef::proto::size::packet_player_action(stream, *obj.params_packet_player_action); EXPECT_OR_BAIL(len_200); len += len_200; /*params_packet_player_action*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::HurtArmor: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_hurt_armor); size_t len_201 = pdef::proto::size::packet_hurt_armor(stream, *obj.params_packet_hurt_armor); EXPECT_OR_BAIL(len_201); len += len_201; /*params_packet_hurt_armor*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_entity_data); size_t len_202 = pdef::proto::size::packet_set_entity_data(stream, *obj.params_packet_set_entity_data); EXPECT_OR_BAIL(len_202); len += len_202; /*params_packet_set_entity_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityMotion: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_entity_motion); size_t len_203 = pdef::proto::size::packet_set_entity_motion(stream, *obj.params_packet_set_entity_motion); EXPECT_OR_BAIL(len_203); len += len_203; /*params_packet_set_entity_motion*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityLink: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_entity_link); size_t len_204 = pdef::proto::size::packet_set_entity_link(stream, *obj.params_packet_set_entity_link); EXPECT_OR_BAIL(len_204); len += len_204; /*params_packet_set_entity_link*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetHealth: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_health); size_t len_205 = pdef::proto::size::packet_set_health(stream, *obj.params_packet_set_health); EXPECT_OR_BAIL(len_205); len += len_205; /*params_packet_set_health*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetSpawnPosition: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_spawn_position); size_t len_206 = pdef::proto::size::packet_set_spawn_position(stream, *obj.params_packet_set_spawn_position); EXPECT_OR_BAIL(len_206); len += len_206; /*params_packet_set_spawn_position*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Animate: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_animate); size_t len_207 = pdef::proto::size::packet_animate(stream, *obj.params_packet_animate); EXPECT_OR_BAIL(len_207); len += len_207; /*params_packet_animate*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Respawn: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_respawn); size_t len_208 = pdef::proto::size::packet_respawn(stream, *obj.params_packet_respawn); EXPECT_OR_BAIL(len_208); len += len_208; /*params_packet_respawn*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerOpen: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_container_open); size_t len_209 = pdef::proto::size::packet_container_open(stream, *obj.params_packet_container_open); EXPECT_OR_BAIL(len_209); len += len_209; /*params_packet_container_open*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerClose: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_container_close); size_t len_210 = pdef::proto::size::packet_container_close(stream, *obj.params_packet_container_close); EXPECT_OR_BAIL(len_210); len += len_210; /*params_packet_container_close*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerHotbar: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_hotbar); size_t len_211 = pdef::proto::size::packet_player_hotbar(stream, *obj.params_packet_player_hotbar); EXPECT_OR_BAIL(len_211); len += len_211; /*params_packet_player_hotbar*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventoryContent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_inventory_content); size_t len_212 = pdef::proto::size::packet_inventory_content(stream, *obj.params_packet_inventory_content); EXPECT_OR_BAIL(len_212); len += len_212; /*params_packet_inventory_content*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventorySlot: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_inventory_slot); size_t len_213 = pdef::proto::size::packet_inventory_slot(stream, *obj.params_packet_inventory_slot); EXPECT_OR_BAIL(len_213); len += len_213; /*params_packet_inventory_slot*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerSetData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_container_set_data); size_t len_214 = pdef::proto::size::packet_container_set_data(stream, *obj.params_packet_container_set_data); EXPECT_OR_BAIL(len_214); len += len_214; /*params_packet_container_set_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CraftingData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_crafting_data); size_t len_215 = pdef::proto::size::packet_crafting_data(stream, *obj.params_packet_crafting_data); EXPECT_OR_BAIL(len_215); len += len_215; /*params_packet_crafting_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CraftingEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_crafting_event); size_t len_216 = pdef::proto::size::packet_crafting_event(stream, *obj.params_packet_crafting_event); EXPECT_OR_BAIL(len_216); len += len_216; /*params_packet_crafting_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::GuiDataPickItem: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_gui_data_pick_item); size_t len_217 = pdef::proto::size::packet_gui_data_pick_item(stream, *obj.params_packet_gui_data_pick_item); EXPECT_OR_BAIL(len_217); len += len_217; /*params_packet_gui_data_pick_item*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AdventureSettings: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_adventure_settings); size_t len_218 = pdef::proto::size::packet_adventure_settings(stream, *obj.params_packet_adventure_settings); EXPECT_OR_BAIL(len_218); len += len_218; /*params_packet_adventure_settings*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockEntityData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_block_entity_data); size_t len_219 = pdef::proto::size::packet_block_entity_data(stream, *obj.params_packet_block_entity_data); EXPECT_OR_BAIL(len_219); len += len_219; /*params_packet_block_entity_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerInput: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_input); size_t len_220 = pdef::proto::size::packet_player_input(stream, *obj.params_packet_player_input); EXPECT_OR_BAIL(len_220); len += len_220; /*params_packet_player_input*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelChunk: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_level_chunk); size_t len_221 = pdef::proto::size::packet_level_chunk(stream, *obj.params_packet_level_chunk); EXPECT_OR_BAIL(len_221); len += len_221; /*params_packet_level_chunk*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetCommandsEnabled: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_commands_enabled); size_t len_222 = pdef::proto::size::packet_set_commands_enabled(stream, *obj.params_packet_set_commands_enabled); EXPECT_OR_BAIL(len_222); len += len_222; /*params_packet_set_commands_enabled*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDifficulty: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_difficulty); size_t len_223 = pdef::proto::size::packet_set_difficulty(stream, *obj.params_packet_set_difficulty); EXPECT_OR_BAIL(len_223); len += len_223; /*params_packet_set_difficulty*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChangeDimension: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_change_dimension); size_t len_224 = pdef::proto::size::packet_change_dimension(stream, *obj.params_packet_change_dimension); EXPECT_OR_BAIL(len_224); len += len_224; /*params_packet_change_dimension*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetPlayerGameType: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_player_game_type); size_t len_225 = pdef::proto::size::packet_set_player_game_type(stream, *obj.params_packet_set_player_game_type); EXPECT_OR_BAIL(len_225); len += len_225; /*params_packet_set_player_game_type*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerList: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_list); size_t len_226 = pdef::proto::size::packet_player_list(stream, *obj.params_packet_player_list); EXPECT_OR_BAIL(len_226); len += len_226; /*params_packet_player_list*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SimpleEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_simple_event); size_t len_227 = pdef::proto::size::packet_simple_event(stream, *obj.params_packet_simple_event); EXPECT_OR_BAIL(len_227); len += len_227; /*params_packet_simple_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Event: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_event); size_t len_228 = pdef::proto::size::packet_event(stream, *obj.params_packet_event); EXPECT_OR_BAIL(len_228); len += len_228; /*params_packet_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SpawnExperienceOrb: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spawn_experience_orb); size_t len_229 = pdef::proto::size::packet_spawn_experience_orb(stream, *obj.params_packet_spawn_experience_orb); EXPECT_OR_BAIL(len_229); len += len_229; /*params_packet_spawn_experience_orb*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientboundMapItemData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_clientbound_map_item_data); size_t len_230 = pdef::proto::size::packet_clientbound_map_item_data(stream, *obj.params_packet_clientbound_map_item_data); EXPECT_OR_BAIL(len_230); len += len_230; /*params_packet_clientbound_map_item_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MapInfoRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_map_info_request); size_t len_231 = pdef::proto::size::packet_map_info_request(stream, *obj.params_packet_map_info_request); EXPECT_OR_BAIL(len_231); len += len_231; /*params_packet_map_info_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestChunkRadius: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_request_chunk_radius); size_t len_232 = pdef::proto::size::packet_request_chunk_radius(stream, *obj.params_packet_request_chunk_radius); EXPECT_OR_BAIL(len_232); len += len_232; /*params_packet_request_chunk_radius*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChunkRadiusUpdate: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_chunk_radius_update); size_t len_233 = pdef::proto::size::packet_chunk_radius_update(stream, *obj.params_packet_chunk_radius_update); EXPECT_OR_BAIL(len_233); len += len_233; /*params_packet_chunk_radius_update*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemFrameDropItem: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_item_frame_drop_item); size_t len_234 = pdef::proto::size::packet_item_frame_drop_item(stream, *obj.params_packet_item_frame_drop_item); EXPECT_OR_BAIL(len_234); len += len_234; /*params_packet_item_frame_drop_item*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::GameRulesChanged: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_game_rules_changed); size_t len_235 = pdef::proto::size::packet_game_rules_changed(stream, *obj.params_packet_game_rules_changed); EXPECT_OR_BAIL(len_235); len += len_235; /*params_packet_game_rules_changed*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Camera: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_camera); size_t len_236 = pdef::proto::size::packet_camera(stream, *obj.params_packet_camera); EXPECT_OR_BAIL(len_236); len += len_236; /*params_packet_camera*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BossEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_boss_event); size_t len_237 = pdef::proto::size::packet_boss_event(stream, *obj.params_packet_boss_event); EXPECT_OR_BAIL(len_237); len += len_237; /*params_packet_boss_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowCredits: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_show_credits); size_t len_238 = pdef::proto::size::packet_show_credits(stream, *obj.params_packet_show_credits); EXPECT_OR_BAIL(len_238); len += len_238; /*params_packet_show_credits*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AvailableCommands: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_available_commands); size_t len_239 = pdef::proto::size::packet_available_commands(stream, *obj.params_packet_available_commands); EXPECT_OR_BAIL(len_239); len += len_239; /*params_packet_available_commands*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_command_request); size_t len_240 = pdef::proto::size::packet_command_request(stream, *obj.params_packet_command_request); EXPECT_OR_BAIL(len_240); len += len_240; /*params_packet_command_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandBlockUpdate: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_command_block_update); size_t len_241 = pdef::proto::size::packet_command_block_update(stream, *obj.params_packet_command_block_update); EXPECT_OR_BAIL(len_241); len += len_241; /*params_packet_command_block_update*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandOutput: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_command_output); size_t len_242 = pdef::proto::size::packet_command_output(stream, *obj.params_packet_command_output); EXPECT_OR_BAIL(len_242); len += len_242; /*params_packet_command_output*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateTrade: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_trade); size_t len_243 = pdef::proto::size::packet_update_trade(stream, *obj.params_packet_update_trade); EXPECT_OR_BAIL(len_243); len += len_243; /*params_packet_update_trade*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateEquipment: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_equipment); size_t len_244 = pdef::proto::size::packet_update_equipment(stream, *obj.params_packet_update_equipment); EXPECT_OR_BAIL(len_244); len += len_244; /*params_packet_update_equipment*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackDataInfo: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_pack_data_info); size_t len_245 = pdef::proto::size::packet_resource_pack_data_info(stream, *obj.params_packet_resource_pack_data_info); EXPECT_OR_BAIL(len_245); len += len_245; /*params_packet_resource_pack_data_info*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackChunkData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_pack_chunk_data); size_t len_246 = pdef::proto::size::packet_resource_pack_chunk_data(stream, *obj.params_packet_resource_pack_chunk_data); EXPECT_OR_BAIL(len_246); len += len_246; /*params_packet_resource_pack_chunk_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackChunkRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_resource_pack_chunk_request); size_t len_247 = pdef::proto::size::packet_resource_pack_chunk_request(stream, *obj.params_packet_resource_pack_chunk_request); EXPECT_OR_BAIL(len_247); len += len_247; /*params_packet_resource_pack_chunk_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Transfer: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_transfer); size_t len_248 = pdef::proto::size::packet_transfer(stream, *obj.params_packet_transfer); EXPECT_OR_BAIL(len_248); len += len_248; /*params_packet_transfer*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlaySound: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_play_sound); size_t len_249 = pdef::proto::size::packet_play_sound(stream, *obj.params_packet_play_sound); EXPECT_OR_BAIL(len_249); len += len_249; /*params_packet_play_sound*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StopSound: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_stop_sound); size_t len_250 = pdef::proto::size::packet_stop_sound(stream, *obj.params_packet_stop_sound); EXPECT_OR_BAIL(len_250); len += len_250; /*params_packet_stop_sound*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetTitle: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_title); size_t len_251 = pdef::proto::size::packet_set_title(stream, *obj.params_packet_set_title); EXPECT_OR_BAIL(len_251); len += len_251; /*params_packet_set_title*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddBehaviorTree: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_add_behavior_tree); size_t len_252 = pdef::proto::size::packet_add_behavior_tree(stream, *obj.params_packet_add_behavior_tree); EXPECT_OR_BAIL(len_252); len += len_252; /*params_packet_add_behavior_tree*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureBlockUpdate: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_structure_block_update); size_t len_253 = pdef::proto::size::packet_structure_block_update(stream, *obj.params_packet_structure_block_update); EXPECT_OR_BAIL(len_253); len += len_253; /*params_packet_structure_block_update*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowStoreOffer: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_show_store_offer); size_t len_254 = pdef::proto::size::packet_show_store_offer(stream, *obj.params_packet_show_store_offer); EXPECT_OR_BAIL(len_254); len += len_254; /*params_packet_show_store_offer*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PurchaseReceipt: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_purchase_receipt); size_t len_255 = pdef::proto::size::packet_purchase_receipt(stream, *obj.params_packet_purchase_receipt); EXPECT_OR_BAIL(len_255); len += len_255; /*params_packet_purchase_receipt*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerSkin: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_skin); size_t len_256 = pdef::proto::size::packet_player_skin(stream, *obj.params_packet_player_skin); EXPECT_OR_BAIL(len_256); len += len_256; /*params_packet_player_skin*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SubClientLogin: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_sub_client_login); size_t len_257 = pdef::proto::size::packet_sub_client_login(stream, *obj.params_packet_sub_client_login); EXPECT_OR_BAIL(len_257); len += len_257; /*params_packet_sub_client_login*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InitiateWebSocketConnection: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_initiate_web_socket_connection); size_t len_258 = pdef::proto::size::packet_initiate_web_socket_connection(stream, *obj.params_packet_initiate_web_socket_connection); EXPECT_OR_BAIL(len_258); len += len_258; /*params_packet_initiate_web_socket_connection*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetLastHurtBy: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_last_hurt_by); size_t len_259 = pdef::proto::size::packet_set_last_hurt_by(stream, *obj.params_packet_set_last_hurt_by); EXPECT_OR_BAIL(len_259); len += len_259; /*params_packet_set_last_hurt_by*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BookEdit: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_book_edit); size_t len_260 = pdef::proto::size::packet_book_edit(stream, *obj.params_packet_book_edit); EXPECT_OR_BAIL(len_260); len += len_260; /*params_packet_book_edit*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NpcRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_npc_request); size_t len_261 = pdef::proto::size::packet_npc_request(stream, *obj.params_packet_npc_request); EXPECT_OR_BAIL(len_261); len += len_261; /*params_packet_npc_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PhotoTransfer: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_photo_transfer); size_t len_262 = pdef::proto::size::packet_photo_transfer(stream, *obj.params_packet_photo_transfer); EXPECT_OR_BAIL(len_262); len += len_262; /*params_packet_photo_transfer*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ModalFormRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_modal_form_request); size_t len_263 = pdef::proto::size::packet_modal_form_request(stream, *obj.params_packet_modal_form_request); EXPECT_OR_BAIL(len_263); len += len_263; /*params_packet_modal_form_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ModalFormResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_modal_form_response); size_t len_264 = pdef::proto::size::packet_modal_form_response(stream, *obj.params_packet_modal_form_response); EXPECT_OR_BAIL(len_264); len += len_264; /*params_packet_modal_form_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerSettingsRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_server_settings_request); size_t len_265 = pdef::proto::size::packet_server_settings_request(stream, *obj.params_packet_server_settings_request); EXPECT_OR_BAIL(len_265); len += len_265; /*params_packet_server_settings_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerSettingsResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_server_settings_response); size_t len_266 = pdef::proto::size::packet_server_settings_response(stream, *obj.params_packet_server_settings_response); EXPECT_OR_BAIL(len_266); len += len_266; /*params_packet_server_settings_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowProfile: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_show_profile); size_t len_267 = pdef::proto::size::packet_show_profile(stream, *obj.params_packet_show_profile); EXPECT_OR_BAIL(len_267); len += len_267; /*params_packet_show_profile*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDefaultGameType: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_default_game_type); size_t len_268 = pdef::proto::size::packet_set_default_game_type(stream, *obj.params_packet_set_default_game_type); EXPECT_OR_BAIL(len_268); len += len_268; /*params_packet_set_default_game_type*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveObjective: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_remove_objective); size_t len_269 = pdef::proto::size::packet_remove_objective(stream, *obj.params_packet_remove_objective); EXPECT_OR_BAIL(len_269); len += len_269; /*params_packet_remove_objective*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDisplayObjective: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_display_objective); size_t len_270 = pdef::proto::size::packet_set_display_objective(stream, *obj.params_packet_set_display_objective); EXPECT_OR_BAIL(len_270); len += len_270; /*params_packet_set_display_objective*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetScore: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_score); size_t len_271 = pdef::proto::size::packet_set_score(stream, *obj.params_packet_set_score); EXPECT_OR_BAIL(len_271); len += len_271; /*params_packet_set_score*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LabTable: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_lab_table); size_t len_272 = pdef::proto::size::packet_lab_table(stream, *obj.params_packet_lab_table); EXPECT_OR_BAIL(len_272); len += len_272; /*params_packet_lab_table*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlockSynced: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_block_synced); size_t len_273 = pdef::proto::size::packet_update_block_synced(stream, *obj.params_packet_update_block_synced); EXPECT_OR_BAIL(len_273); len += len_273; /*params_packet_update_block_synced*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MoveEntityDelta: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_move_entity_delta); size_t len_274 = pdef::proto::size::packet_move_entity_delta(stream, *obj.params_packet_move_entity_delta); EXPECT_OR_BAIL(len_274); len += len_274; /*params_packet_move_entity_delta*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetScoreboardIdentity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_scoreboard_identity); size_t len_275 = pdef::proto::size::packet_set_scoreboard_identity(stream, *obj.params_packet_set_scoreboard_identity); EXPECT_OR_BAIL(len_275); len += len_275; /*params_packet_set_scoreboard_identity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetLocalPlayerAsInitialized: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_set_local_player_as_initialized); size_t len_276 = pdef::proto::size::packet_set_local_player_as_initialized(stream, *obj.params_packet_set_local_player_as_initialized); EXPECT_OR_BAIL(len_276); len += len_276; /*params_packet_set_local_player_as_initialized*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateSoftEnum: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_soft_enum); size_t len_277 = pdef::proto::size::packet_update_soft_enum(stream, *obj.params_packet_update_soft_enum); EXPECT_OR_BAIL(len_277); len += len_277; /*params_packet_update_soft_enum*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkStackLatency: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_network_stack_latency); size_t len_278 = pdef::proto::size::packet_network_stack_latency(stream, *obj.params_packet_network_stack_latency); EXPECT_OR_BAIL(len_278); len += len_278; /*params_packet_network_stack_latency*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ScriptCustomEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_script_custom_event); size_t len_279 = pdef::proto::size::packet_script_custom_event(stream, *obj.params_packet_script_custom_event); EXPECT_OR_BAIL(len_279); len += len_279; /*params_packet_script_custom_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SpawnParticleEffect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_spawn_particle_effect); size_t len_280 = pdef::proto::size::packet_spawn_particle_effect(stream, *obj.params_packet_spawn_particle_effect); EXPECT_OR_BAIL(len_280); len += len_280; /*params_packet_spawn_particle_effect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AvailableEntityIdentifiers: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_available_entity_identifiers); size_t len_281 = pdef::proto::size::packet_available_entity_identifiers(stream, *obj.params_packet_available_entity_identifiers); EXPECT_OR_BAIL(len_281); len += len_281; /*params_packet_available_entity_identifiers*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEventV2: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_level_sound_event_v2); size_t len_282 = pdef::proto::size::packet_level_sound_event_v2(stream, *obj.params_packet_level_sound_event_v2); EXPECT_OR_BAIL(len_282); len += len_282; /*params_packet_level_sound_event_v2*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkChunkPublisherUpdate: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_network_chunk_publisher_update); size_t len_283 = pdef::proto::size::packet_network_chunk_publisher_update(stream, *obj.params_packet_network_chunk_publisher_update); EXPECT_OR_BAIL(len_283); len += len_283; /*params_packet_network_chunk_publisher_update*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BiomeDefinitionList: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_biome_definition_list); size_t len_284 = pdef::proto::size::packet_biome_definition_list(stream, *obj.params_packet_biome_definition_list); EXPECT_OR_BAIL(len_284); len += len_284; /*params_packet_biome_definition_list*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEvent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_level_sound_event); size_t len_285 = pdef::proto::size::packet_level_sound_event(stream, *obj.params_packet_level_sound_event); EXPECT_OR_BAIL(len_285); len += len_285; /*params_packet_level_sound_event*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelEventGeneric: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_level_event_generic); size_t len_286 = pdef::proto::size::packet_level_event_generic(stream, *obj.params_packet_level_event_generic); EXPECT_OR_BAIL(len_286); len += len_286; /*params_packet_level_event_generic*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LecternUpdate: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_lectern_update); size_t len_287 = pdef::proto::size::packet_lectern_update(stream, *obj.params_packet_lectern_update); EXPECT_OR_BAIL(len_287); len += len_287; /*params_packet_lectern_update*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::VideoStreamConnect: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_video_stream_connect); size_t len_288 = pdef::proto::size::packet_video_stream_connect(stream, *obj.params_packet_video_stream_connect); EXPECT_OR_BAIL(len_288); len += len_288; /*params_packet_video_stream_connect*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddEcsEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_add_ecs_entity); size_t len_289 = pdef::proto::size::packet_add_ecs_entity(stream, *obj.params_packet_add_ecs_entity); EXPECT_OR_BAIL(len_289); len += len_289; /*params_packet_add_ecs_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveEcsEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_remove_ecs_entity); size_t len_290 = pdef::proto::size::packet_remove_ecs_entity(stream, *obj.params_packet_remove_ecs_entity); EXPECT_OR_BAIL(len_290); len += len_290; /*params_packet_remove_ecs_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheStatus: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_client_cache_status); size_t len_291 = pdef::proto::size::packet_client_cache_status(stream, *obj.params_packet_client_cache_status); EXPECT_OR_BAIL(len_291); len += len_291; /*params_packet_client_cache_status*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::OnScreenTextureAnimation: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_on_screen_texture_animation); size_t len_292 = pdef::proto::size::packet_on_screen_texture_animation(stream, *obj.params_packet_on_screen_texture_animation); EXPECT_OR_BAIL(len_292); len += len_292; /*params_packet_on_screen_texture_animation*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MapCreateLockedCopy: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_map_create_locked_copy); size_t len_293 = pdef::proto::size::packet_map_create_locked_copy(stream, *obj.params_packet_map_create_locked_copy); EXPECT_OR_BAIL(len_293); len += len_293; /*params_packet_map_create_locked_copy*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureTemplateDataExportRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_structure_template_data_export_request); size_t len_294 = pdef::proto::size::packet_structure_template_data_export_request(stream, *obj.params_packet_structure_template_data_export_request); EXPECT_OR_BAIL(len_294); len += len_294; /*params_packet_structure_template_data_export_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureTemplateDataExportResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_structure_template_data_export_response); size_t len_295 = pdef::proto::size::packet_structure_template_data_export_response(stream, *obj.params_packet_structure_template_data_export_response); EXPECT_OR_BAIL(len_295); len += len_295; /*params_packet_structure_template_data_export_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlockProperties: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_block_properties); size_t len_296 = pdef::proto::size::packet_update_block_properties(stream, *obj.params_packet_update_block_properties); EXPECT_OR_BAIL(len_296); len += len_296; /*params_packet_update_block_properties*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheBlobStatus: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_client_cache_blob_status); size_t len_297 = pdef::proto::size::packet_client_cache_blob_status(stream, *obj.params_packet_client_cache_blob_status); EXPECT_OR_BAIL(len_297); len += len_297; /*params_packet_client_cache_blob_status*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheMissResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_client_cache_miss_response); size_t len_298 = pdef::proto::size::packet_client_cache_miss_response(stream, *obj.params_packet_client_cache_miss_response); EXPECT_OR_BAIL(len_298); len += len_298; /*params_packet_client_cache_miss_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EducationSettings: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_education_settings); size_t len_299 = pdef::proto::size::packet_education_settings(stream, *obj.params_packet_education_settings); EXPECT_OR_BAIL(len_299); len += len_299; /*params_packet_education_settings*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Emote: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_emote); size_t len_300 = pdef::proto::size::packet_emote(stream, *obj.params_packet_emote); EXPECT_OR_BAIL(len_300); len += len_300; /*params_packet_emote*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MultiplayerSettings: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_multiplayer_settings); size_t len_301 = pdef::proto::size::packet_multiplayer_settings(stream, *obj.params_packet_multiplayer_settings); EXPECT_OR_BAIL(len_301); len += len_301; /*params_packet_multiplayer_settings*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SettingsCommand: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_settings_command); size_t len_302 = pdef::proto::size::packet_settings_command(stream, *obj.params_packet_settings_command); EXPECT_OR_BAIL(len_302); len += len_302; /*params_packet_settings_command*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AnvilDamage: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_anvil_damage); size_t len_303 = pdef::proto::size::packet_anvil_damage(stream, *obj.params_packet_anvil_damage); EXPECT_OR_BAIL(len_303); len += len_303; /*params_packet_anvil_damage*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CompletedUsingItem: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_completed_using_item); size_t len_304 = pdef::proto::size::packet_completed_using_item(stream, *obj.params_packet_completed_using_item); EXPECT_OR_BAIL(len_304); len += len_304; /*params_packet_completed_using_item*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkSettings: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_network_settings); size_t len_305 = pdef::proto::size::packet_network_settings(stream, *obj.params_packet_network_settings); EXPECT_OR_BAIL(len_305); len += len_305; /*params_packet_network_settings*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerAuthInput: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_auth_input); size_t len_306 = pdef::proto::size::packet_player_auth_input(stream, *obj.params_packet_player_auth_input); EXPECT_OR_BAIL(len_306); len += len_306; /*params_packet_player_auth_input*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CreativeContent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_creative_content); size_t len_307 = pdef::proto::size::packet_creative_content(stream, *obj.params_packet_creative_content); EXPECT_OR_BAIL(len_307); len += len_307; /*params_packet_creative_content*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerEnchantOptions: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_enchant_options); size_t len_308 = pdef::proto::size::packet_player_enchant_options(stream, *obj.params_packet_player_enchant_options); EXPECT_OR_BAIL(len_308); len += len_308; /*params_packet_player_enchant_options*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemStackRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_item_stack_request); size_t len_309 = pdef::proto::size::packet_item_stack_request(stream, *obj.params_packet_item_stack_request); EXPECT_OR_BAIL(len_309); len += len_309; /*params_packet_item_stack_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemStackResponse: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_item_stack_response); size_t len_310 = pdef::proto::size::packet_item_stack_response(stream, *obj.params_packet_item_stack_response); EXPECT_OR_BAIL(len_310); len += len_310; /*params_packet_item_stack_response*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerArmorDamage: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_armor_damage); size_t len_311 = pdef::proto::size::packet_player_armor_damage(stream, *obj.params_packet_player_armor_damage); EXPECT_OR_BAIL(len_311); len += len_311; /*params_packet_player_armor_damage*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdatePlayerGameType: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_player_game_type); size_t len_312 = pdef::proto::size::packet_update_player_game_type(stream, *obj.params_packet_update_player_game_type); EXPECT_OR_BAIL(len_312); len += len_312; /*params_packet_update_player_game_type*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EmoteList: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_emote_list); size_t len_313 = pdef::proto::size::packet_emote_list(stream, *obj.params_packet_emote_list); EXPECT_OR_BAIL(len_313); len += len_313; /*params_packet_emote_list*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PositionTrackingDbRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_position_tracking_db_request); size_t len_314 = pdef::proto::size::packet_position_tracking_db_request(stream, *obj.params_packet_position_tracking_db_request); EXPECT_OR_BAIL(len_314); len += len_314; /*params_packet_position_tracking_db_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PositionTrackingDbBroadcast: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_position_tracking_db_broadcast); size_t len_315 = pdef::proto::size::packet_position_tracking_db_broadcast(stream, *obj.params_packet_position_tracking_db_broadcast); EXPECT_OR_BAIL(len_315); len += len_315; /*params_packet_position_tracking_db_broadcast*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PacketViolationWarning: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_packet_violation_warning); size_t len_316 = pdef::proto::size::packet_packet_violation_warning(stream, *obj.params_packet_packet_violation_warning); EXPECT_OR_BAIL(len_316); len += len_316; /*params_packet_packet_violation_warning*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MotionPredictionHints: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_motion_prediction_hints); size_t len_317 = pdef::proto::size::packet_motion_prediction_hints(stream, *obj.params_packet_motion_prediction_hints); EXPECT_OR_BAIL(len_317); len += len_317; /*params_packet_motion_prediction_hints*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AnimateEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_animate_entity); size_t len_318 = pdef::proto::size::packet_animate_entity(stream, *obj.params_packet_animate_entity); EXPECT_OR_BAIL(len_318); len += len_318; /*params_packet_animate_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CameraShake: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_camera_shake); size_t len_319 = pdef::proto::size::packet_camera_shake(stream, *obj.params_packet_camera_shake); EXPECT_OR_BAIL(len_319); len += len_319; /*params_packet_camera_shake*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerFog: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_player_fog); size_t len_320 = pdef::proto::size::packet_player_fog(stream, *obj.params_packet_player_fog); EXPECT_OR_BAIL(len_320); len += len_320; /*params_packet_player_fog*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CorrectPlayerMovePrediction: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_correct_player_move_prediction); size_t len_321 = pdef::proto::size::packet_correct_player_move_prediction(stream, *obj.params_packet_correct_player_move_prediction); EXPECT_OR_BAIL(len_321); len += len_321; /*params_packet_correct_player_move_prediction*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemComponent: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_item_component); size_t len_322 = pdef::proto::size::packet_item_component(stream, *obj.params_packet_item_component); EXPECT_OR_BAIL(len_322); len += len_322; /*params_packet_item_component*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::FilterTextPacket: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_filter_text_packet); size_t len_323 = pdef::proto::size::packet_filter_text_packet(stream, *obj.params_packet_filter_text_packet); EXPECT_OR_BAIL(len_323); len += len_323; /*params_packet_filter_text_packet*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::DebugRenderer: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_debug_renderer); size_t len_324 = pdef::proto::size::packet_debug_renderer(stream, *obj.params_packet_debug_renderer); EXPECT_OR_BAIL(len_324); len += len_324; /*params_packet_debug_renderer*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SyncEntityProperty: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_sync_entity_property); size_t len_325 = pdef::proto::size::packet_sync_entity_property(stream, *obj.params_packet_sync_entity_property); EXPECT_OR_BAIL(len_325); len += len_325; /*params_packet_sync_entity_property*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddVolumeEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_add_volume_entity); size_t len_326 = pdef::proto::size::packet_add_volume_entity(stream, *obj.params_packet_add_volume_entity); EXPECT_OR_BAIL(len_326); len += len_326; /*params_packet_add_volume_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveVolumeEntity: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_remove_volume_entity); size_t len_327 = pdef::proto::size::packet_remove_volume_entity(stream, *obj.params_packet_remove_volume_entity); EXPECT_OR_BAIL(len_327); len += len_327; /*params_packet_remove_volume_entity*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SimulationType: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_simulation_type); size_t len_328 = pdef::proto::size::packet_simulation_type(stream, *obj.params_packet_simulation_type); EXPECT_OR_BAIL(len_328); len += len_328; /*params_packet_simulation_type*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NpcDialogue: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_npc_dialogue); size_t len_329 = pdef::proto::size::packet_npc_dialogue(stream, *obj.params_packet_npc_dialogue); EXPECT_OR_BAIL(len_329); len += len_329; /*params_packet_npc_dialogue*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EduUriResourcePacket: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_edu_uri_resource_packet); size_t len_330 = pdef::proto::size::packet_edu_uri_resource_packet(stream, *obj.params_packet_edu_uri_resource_packet); EXPECT_OR_BAIL(len_330); len += len_330; /*params_packet_edu_uri_resource_packet*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CreatePhoto: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_create_photo); size_t len_331 = pdef::proto::size::packet_create_photo(stream, *obj.params_packet_create_photo); EXPECT_OR_BAIL(len_331); len += len_331; /*params_packet_create_photo*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateSubchunkBlocks: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_update_subchunk_blocks); size_t len_332 = pdef::proto::size::packet_update_subchunk_blocks(stream, *obj.params_packet_update_subchunk_blocks); EXPECT_OR_BAIL(len_332); len += len_332; /*params_packet_update_subchunk_blocks*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PhotoInfoRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_photo_info_request); size_t len_333 = pdef::proto::size::packet_photo_info_request(stream, *obj.params_packet_photo_info_request); EXPECT_OR_BAIL(len_333); len += len_333; /*params_packet_photo_info_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Subchunk: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_subchunk); size_t len_334 = pdef::proto::size::packet_subchunk(stream, *obj.params_packet_subchunk); EXPECT_OR_BAIL(len_334); len += len_334; /*params_packet_subchunk*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SubchunkRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_subchunk_request); size_t len_335 = pdef::proto::size::packet_subchunk_request(stream, *obj.params_packet_subchunk_request); EXPECT_OR_BAIL(len_335); len += len_335; /*params_packet_subchunk_request*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientStartItemCooldown: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_client_start_item_cooldown); size_t len_336 = pdef::proto::size::packet_client_start_item_cooldown(stream, *obj.params_packet_client_start_item_cooldown); EXPECT_OR_BAIL(len_336); len += len_336; /*params_packet_client_start_item_cooldown*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ScriptMessage: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_script_message); size_t len_337 = pdef::proto::size::packet_script_message(stream, *obj.params_packet_script_message); EXPECT_OR_BAIL(len_337); len += len_337; /*params_packet_script_message*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CodeBuilderSource: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_code_builder_source); size_t len_338 = pdef::proto::size::packet_code_builder_source(stream, *obj.params_packet_code_builder_source); EXPECT_OR_BAIL(len_338); len += len_338; /*params_packet_code_builder_source*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TickingAreasLoadStatus: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_ticking_areas_load_status); size_t len_339 = pdef::proto::size::packet_ticking_areas_load_status(stream, *obj.params_packet_ticking_areas_load_status); EXPECT_OR_BAIL(len_339); len += len_339; /*params_packet_ticking_areas_load_status*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::DimensionData: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_dimension_data); size_t len_340 = pdef::proto::size::packet_dimension_data(stream, *obj.params_packet_dimension_data); EXPECT_OR_BAIL(len_340); len += len_340; /*params_packet_dimension_data*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AgentAction: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_agent_action); size_t len_341 = pdef::proto::size::packet_agent_action(stream, *obj.params_packet_agent_action); EXPECT_OR_BAIL(len_341); len += len_341; /*params_packet_agent_action*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChangeMobProperty: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_change_mob_property); size_t len_342 = pdef::proto::size::packet_change_mob_property(stream, *obj.params_packet_change_mob_property); EXPECT_OR_BAIL(len_342); len += len_342; /*params_packet_change_mob_property*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LessonProgress: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_lesson_progress); size_t len_343 = pdef::proto::size::packet_lesson_progress(stream, *obj.params_packet_lesson_progress); EXPECT_OR_BAIL(len_343); len += len_343; /*params_packet_lesson_progress*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestAbility: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_request_ability); size_t len_344 = pdef::proto::size::packet_request_ability(stream, *obj.params_packet_request_ability); EXPECT_OR_BAIL(len_344); len += len_344; /*params_packet_request_ability*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestPermissions: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_request_permissions); size_t len_345 = pdef::proto::size::packet_request_permissions(stream, *obj.params_packet_request_permissions); EXPECT_OR_BAIL(len_345); len += len_345; /*params_packet_request_permissions*/ /*4.4*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ToastRequest: { /*8.5*/
        EXPECT_OR_BAIL(obj.params_packet_toast_request); size_t len_346 = pdef::proto::size::packet_toast_request(stream, *obj.params_packet_toast_request); EXPECT_OR_BAIL(len_346); len += len_346; /*params_packet_toast_request*/ /*4.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    DBG_PRINT("%s: sized at %lld\n", __func__, len); return len;
  }
}

namespace pdef::proto::encode {
bool BehaviourPackInfos(pdef::Stream &stream, const pdef::proto::BehaviourPackInfos &obj, bool allocate);
bool TexturePackInfos(pdef::Stream &stream, const pdef::proto::TexturePackInfos &obj, bool allocate);
bool ResourcePackIdVersions(pdef::Stream &stream, const pdef::proto::ResourcePackIdVersions &obj, bool allocate);
bool Experiment(pdef::Stream &stream, const pdef::proto::Experiment &obj, bool allocate);
bool GameRule(pdef::Stream &stream, const pdef::proto::GameRule &obj, bool allocate);
bool Blob(pdef::Stream &stream, const pdef::proto::Blob &obj, bool allocate);
bool BlockProperties(pdef::Stream &stream, const pdef::proto::BlockProperties &obj, bool allocate);
bool Itemstates(pdef::Stream &stream, const pdef::proto::Itemstates &obj, bool allocate);
bool ItemExtraDataWithBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithBlockingTick &obj, bool allocate);
bool ItemExtraDataWithoutBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithoutBlockingTick &obj, bool allocate);
bool ItemLegacy(pdef::Stream &stream, const pdef::proto::ItemLegacy &obj, bool allocate);
bool Item(pdef::Stream &stream, const pdef::proto::Item &obj, bool allocate);
bool vec3i(pdef::Stream &stream, const pdef::proto::vec3i &obj, bool allocate);
bool vec3u(pdef::Stream &stream, const pdef::proto::vec3u &obj, bool allocate);
bool vec3f(pdef::Stream &stream, const pdef::proto::vec3f &obj, bool allocate);
bool vec2f(pdef::Stream &stream, const pdef::proto::vec2f &obj, bool allocate);
bool MetadataDictionary(pdef::Stream &stream, const pdef::proto::MetadataDictionary &obj, bool allocate);
bool Link(pdef::Stream &stream, const pdef::proto::Link &obj, bool allocate);
bool EntityAttributes(pdef::Stream &stream, const pdef::proto::EntityAttributes &obj, bool allocate);
bool Rotation(pdef::Stream &stream, const pdef::proto::Rotation &obj, bool allocate);
bool BlockCoordinates(pdef::Stream &stream, const pdef::proto::BlockCoordinates &obj, bool allocate);
bool PlayerAttributes(pdef::Stream &stream, const pdef::proto::PlayerAttributes &obj, bool allocate);
bool TransactionUseItem(pdef::Stream &stream, const pdef::proto::TransactionUseItem &obj, bool allocate);
bool TransactionActions(pdef::Stream &stream, const pdef::proto::TransactionActions &obj, bool allocate);
bool TransactionLegacy(pdef::Stream &stream, const pdef::proto::TransactionLegacy &obj, bool allocate);
bool Transaction(pdef::Stream &stream, const pdef::proto::Transaction &obj, bool allocate);
bool RecipeIngredient(pdef::Stream &stream, const pdef::proto::RecipeIngredient &obj, bool allocate);
bool PotionTypeRecipes(pdef::Stream &stream, const pdef::proto::PotionTypeRecipes &obj, bool allocate);
bool PotionContainerChangeRecipes(pdef::Stream &stream, const pdef::proto::PotionContainerChangeRecipes &obj, bool allocate);
bool Recipes(pdef::Stream &stream, const pdef::proto::Recipes &obj, bool allocate);
bool SkinImage(pdef::Stream &stream, const pdef::proto::SkinImage &obj, bool allocate);
bool Skin(pdef::Stream &stream, const pdef::proto::Skin &obj, bool allocate);
bool PlayerRecords(pdef::Stream &stream, const pdef::proto::PlayerRecords &obj, bool allocate);
bool Enchant(pdef::Stream &stream, const pdef::proto::Enchant &obj, bool allocate);
bool EnchantOption(pdef::Stream &stream, const pdef::proto::EnchantOption &obj, bool allocate);
bool StackRequestSlotInfo(pdef::Stream &stream, const pdef::proto::StackRequestSlotInfo &obj, bool allocate);
bool ItemStackRequest(pdef::Stream &stream, const pdef::proto::ItemStackRequest &obj, bool allocate);
bool ItemStackResponses(pdef::Stream &stream, const pdef::proto::ItemStackResponses &obj, bool allocate);
bool ItemComponentList(pdef::Stream &stream, const pdef::proto::ItemComponentList &obj, bool allocate);
bool CommandOrigin(pdef::Stream &stream, const pdef::proto::CommandOrigin &obj, bool allocate);
bool TrackedObject(pdef::Stream &stream, const pdef::proto::TrackedObject &obj, bool allocate);
bool MapDecoration(pdef::Stream &stream, const pdef::proto::MapDecoration &obj, bool allocate);
bool StructureBlockSettings(pdef::Stream &stream, const pdef::proto::StructureBlockSettings &obj, bool allocate);
bool EducationSharedResourceURI(pdef::Stream &stream, const pdef::proto::EducationSharedResourceURI &obj, bool allocate);
bool EducationExternalLinkSettings(pdef::Stream &stream, const pdef::proto::EducationExternalLinkSettings &obj, bool allocate);
bool BlockUpdate(pdef::Stream &stream, const pdef::proto::BlockUpdate &obj, bool allocate);
bool MaterialReducer(pdef::Stream &stream, const pdef::proto::MaterialReducer &obj, bool allocate);
bool packet_login(pdef::Stream &stream, const pdef::proto::packet_login &obj, bool allocate);
bool LoginTokens(pdef::Stream &stream, const pdef::proto::LoginTokens &obj, bool allocate);
bool packet_play_status(pdef::Stream &stream, const pdef::proto::packet_play_status &obj, bool allocate);
bool packet_server_to_client_handshake(pdef::Stream &stream, const pdef::proto::packet_server_to_client_handshake &obj, bool allocate);
bool packet_client_to_server_handshake(pdef::Stream &stream, const pdef::proto::packet_client_to_server_handshake &obj, bool allocate);
bool packet_disconnect(pdef::Stream &stream, const pdef::proto::packet_disconnect &obj, bool allocate);
bool packet_resource_packs_info(pdef::Stream &stream, const pdef::proto::packet_resource_packs_info &obj, bool allocate);
bool packet_resource_pack_stack(pdef::Stream &stream, const pdef::proto::packet_resource_pack_stack &obj, bool allocate);
bool packet_resource_pack_client_response(pdef::Stream &stream, const pdef::proto::packet_resource_pack_client_response &obj, bool allocate);
bool packet_text(pdef::Stream &stream, const pdef::proto::packet_text &obj, bool allocate);
bool packet_set_time(pdef::Stream &stream, const pdef::proto::packet_set_time &obj, bool allocate);
bool packet_start_game(pdef::Stream &stream, const pdef::proto::packet_start_game &obj, bool allocate);
bool packet_add_player(pdef::Stream &stream, const pdef::proto::packet_add_player &obj, bool allocate);
bool packet_add_entity(pdef::Stream &stream, const pdef::proto::packet_add_entity &obj, bool allocate);
bool packet_remove_entity(pdef::Stream &stream, const pdef::proto::packet_remove_entity &obj, bool allocate);
bool packet_add_item_entity(pdef::Stream &stream, const pdef::proto::packet_add_item_entity &obj, bool allocate);
bool packet_take_item_entity(pdef::Stream &stream, const pdef::proto::packet_take_item_entity &obj, bool allocate);
bool packet_move_entity(pdef::Stream &stream, const pdef::proto::packet_move_entity &obj, bool allocate);
bool packet_move_player(pdef::Stream &stream, const pdef::proto::packet_move_player &obj, bool allocate);
bool packet_rider_jump(pdef::Stream &stream, const pdef::proto::packet_rider_jump &obj, bool allocate);
bool packet_update_block(pdef::Stream &stream, const pdef::proto::packet_update_block &obj, bool allocate);
bool packet_add_painting(pdef::Stream &stream, const pdef::proto::packet_add_painting &obj, bool allocate);
bool packet_tick_sync(pdef::Stream &stream, const pdef::proto::packet_tick_sync &obj, bool allocate);
bool packet_level_sound_event_old(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_old &obj, bool allocate);
bool packet_level_event(pdef::Stream &stream, const pdef::proto::packet_level_event &obj, bool allocate);
bool packet_block_event(pdef::Stream &stream, const pdef::proto::packet_block_event &obj, bool allocate);
bool packet_entity_event(pdef::Stream &stream, const pdef::proto::packet_entity_event &obj, bool allocate);
bool packet_mob_effect(pdef::Stream &stream, const pdef::proto::packet_mob_effect &obj, bool allocate);
bool packet_update_attributes(pdef::Stream &stream, const pdef::proto::packet_update_attributes &obj, bool allocate);
bool packet_inventory_transaction(pdef::Stream &stream, const pdef::proto::packet_inventory_transaction &obj, bool allocate);
bool packet_mob_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_equipment &obj, bool allocate);
bool packet_mob_armor_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_armor_equipment &obj, bool allocate);
bool packet_interact(pdef::Stream &stream, const pdef::proto::packet_interact &obj, bool allocate);
bool packet_block_pick_request(pdef::Stream &stream, const pdef::proto::packet_block_pick_request &obj, bool allocate);
bool packet_entity_pick_request(pdef::Stream &stream, const pdef::proto::packet_entity_pick_request &obj, bool allocate);
bool packet_player_action(pdef::Stream &stream, const pdef::proto::packet_player_action &obj, bool allocate);
bool packet_hurt_armor(pdef::Stream &stream, const pdef::proto::packet_hurt_armor &obj, bool allocate);
bool packet_set_entity_data(pdef::Stream &stream, const pdef::proto::packet_set_entity_data &obj, bool allocate);
bool packet_set_entity_motion(pdef::Stream &stream, const pdef::proto::packet_set_entity_motion &obj, bool allocate);
bool packet_set_entity_link(pdef::Stream &stream, const pdef::proto::packet_set_entity_link &obj, bool allocate);
bool packet_set_health(pdef::Stream &stream, const pdef::proto::packet_set_health &obj, bool allocate);
bool packet_set_spawn_position(pdef::Stream &stream, const pdef::proto::packet_set_spawn_position &obj, bool allocate);
bool packet_animate(pdef::Stream &stream, const pdef::proto::packet_animate &obj, bool allocate);
bool packet_respawn(pdef::Stream &stream, const pdef::proto::packet_respawn &obj, bool allocate);
bool packet_container_open(pdef::Stream &stream, const pdef::proto::packet_container_open &obj, bool allocate);
bool packet_container_close(pdef::Stream &stream, const pdef::proto::packet_container_close &obj, bool allocate);
bool packet_player_hotbar(pdef::Stream &stream, const pdef::proto::packet_player_hotbar &obj, bool allocate);
bool packet_inventory_content(pdef::Stream &stream, const pdef::proto::packet_inventory_content &obj, bool allocate);
bool packet_inventory_slot(pdef::Stream &stream, const pdef::proto::packet_inventory_slot &obj, bool allocate);
bool packet_container_set_data(pdef::Stream &stream, const pdef::proto::packet_container_set_data &obj, bool allocate);
bool packet_crafting_data(pdef::Stream &stream, const pdef::proto::packet_crafting_data &obj, bool allocate);
bool packet_crafting_event(pdef::Stream &stream, const pdef::proto::packet_crafting_event &obj, bool allocate);
bool packet_gui_data_pick_item(pdef::Stream &stream, const pdef::proto::packet_gui_data_pick_item &obj, bool allocate);
bool packet_adventure_settings(pdef::Stream &stream, const pdef::proto::packet_adventure_settings &obj, bool allocate);
bool packet_block_entity_data(pdef::Stream &stream, const pdef::proto::packet_block_entity_data &obj, bool allocate);
bool packet_player_input(pdef::Stream &stream, const pdef::proto::packet_player_input &obj, bool allocate);
bool packet_level_chunk(pdef::Stream &stream, const pdef::proto::packet_level_chunk &obj, bool allocate);
bool packet_set_commands_enabled(pdef::Stream &stream, const pdef::proto::packet_set_commands_enabled &obj, bool allocate);
bool packet_set_difficulty(pdef::Stream &stream, const pdef::proto::packet_set_difficulty &obj, bool allocate);
bool packet_change_dimension(pdef::Stream &stream, const pdef::proto::packet_change_dimension &obj, bool allocate);
bool packet_set_player_game_type(pdef::Stream &stream, const pdef::proto::packet_set_player_game_type &obj, bool allocate);
bool packet_player_list(pdef::Stream &stream, const pdef::proto::packet_player_list &obj, bool allocate);
bool packet_simple_event(pdef::Stream &stream, const pdef::proto::packet_simple_event &obj, bool allocate);
bool packet_event(pdef::Stream &stream, const pdef::proto::packet_event &obj, bool allocate);
bool packet_spawn_experience_orb(pdef::Stream &stream, const pdef::proto::packet_spawn_experience_orb &obj, bool allocate);
bool packet_clientbound_map_item_data(pdef::Stream &stream, const pdef::proto::packet_clientbound_map_item_data &obj, bool allocate);
bool packet_map_info_request(pdef::Stream &stream, const pdef::proto::packet_map_info_request &obj, bool allocate);
bool packet_request_chunk_radius(pdef::Stream &stream, const pdef::proto::packet_request_chunk_radius &obj, bool allocate);
bool packet_chunk_radius_update(pdef::Stream &stream, const pdef::proto::packet_chunk_radius_update &obj, bool allocate);
bool packet_item_frame_drop_item(pdef::Stream &stream, const pdef::proto::packet_item_frame_drop_item &obj, bool allocate);
bool packet_game_rules_changed(pdef::Stream &stream, const pdef::proto::packet_game_rules_changed &obj, bool allocate);
bool packet_camera(pdef::Stream &stream, const pdef::proto::packet_camera &obj, bool allocate);
bool packet_boss_event(pdef::Stream &stream, const pdef::proto::packet_boss_event &obj, bool allocate);
bool packet_show_credits(pdef::Stream &stream, const pdef::proto::packet_show_credits &obj, bool allocate);
bool packet_available_commands(pdef::Stream &stream, const pdef::proto::packet_available_commands &obj, bool allocate);
bool packet_command_request(pdef::Stream &stream, const pdef::proto::packet_command_request &obj, bool allocate);
bool packet_command_block_update(pdef::Stream &stream, const pdef::proto::packet_command_block_update &obj, bool allocate);
bool packet_command_output(pdef::Stream &stream, const pdef::proto::packet_command_output &obj, bool allocate);
bool packet_update_trade(pdef::Stream &stream, const pdef::proto::packet_update_trade &obj, bool allocate);
bool packet_update_equipment(pdef::Stream &stream, const pdef::proto::packet_update_equipment &obj, bool allocate);
bool packet_resource_pack_data_info(pdef::Stream &stream, const pdef::proto::packet_resource_pack_data_info &obj, bool allocate);
bool packet_resource_pack_chunk_data(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_data &obj, bool allocate);
bool packet_resource_pack_chunk_request(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_request &obj, bool allocate);
bool packet_transfer(pdef::Stream &stream, const pdef::proto::packet_transfer &obj, bool allocate);
bool packet_play_sound(pdef::Stream &stream, const pdef::proto::packet_play_sound &obj, bool allocate);
bool packet_stop_sound(pdef::Stream &stream, const pdef::proto::packet_stop_sound &obj, bool allocate);
bool packet_set_title(pdef::Stream &stream, const pdef::proto::packet_set_title &obj, bool allocate);
bool packet_add_behavior_tree(pdef::Stream &stream, const pdef::proto::packet_add_behavior_tree &obj, bool allocate);
bool packet_structure_block_update(pdef::Stream &stream, const pdef::proto::packet_structure_block_update &obj, bool allocate);
bool packet_show_store_offer(pdef::Stream &stream, const pdef::proto::packet_show_store_offer &obj, bool allocate);
bool packet_purchase_receipt(pdef::Stream &stream, const pdef::proto::packet_purchase_receipt &obj, bool allocate);
bool packet_player_skin(pdef::Stream &stream, const pdef::proto::packet_player_skin &obj, bool allocate);
bool packet_sub_client_login(pdef::Stream &stream, const pdef::proto::packet_sub_client_login &obj, bool allocate);
bool packet_initiate_web_socket_connection(pdef::Stream &stream, const pdef::proto::packet_initiate_web_socket_connection &obj, bool allocate);
bool packet_set_last_hurt_by(pdef::Stream &stream, const pdef::proto::packet_set_last_hurt_by &obj, bool allocate);
bool packet_book_edit(pdef::Stream &stream, const pdef::proto::packet_book_edit &obj, bool allocate);
bool packet_npc_request(pdef::Stream &stream, const pdef::proto::packet_npc_request &obj, bool allocate);
bool packet_photo_transfer(pdef::Stream &stream, const pdef::proto::packet_photo_transfer &obj, bool allocate);
bool packet_modal_form_request(pdef::Stream &stream, const pdef::proto::packet_modal_form_request &obj, bool allocate);
bool packet_modal_form_response(pdef::Stream &stream, const pdef::proto::packet_modal_form_response &obj, bool allocate);
bool packet_server_settings_request(pdef::Stream &stream, const pdef::proto::packet_server_settings_request &obj, bool allocate);
bool packet_server_settings_response(pdef::Stream &stream, const pdef::proto::packet_server_settings_response &obj, bool allocate);
bool packet_show_profile(pdef::Stream &stream, const pdef::proto::packet_show_profile &obj, bool allocate);
bool packet_set_default_game_type(pdef::Stream &stream, const pdef::proto::packet_set_default_game_type &obj, bool allocate);
bool packet_remove_objective(pdef::Stream &stream, const pdef::proto::packet_remove_objective &obj, bool allocate);
bool packet_set_display_objective(pdef::Stream &stream, const pdef::proto::packet_set_display_objective &obj, bool allocate);
bool packet_set_score(pdef::Stream &stream, const pdef::proto::packet_set_score &obj, bool allocate);
bool packet_lab_table(pdef::Stream &stream, const pdef::proto::packet_lab_table &obj, bool allocate);
bool packet_update_block_synced(pdef::Stream &stream, const pdef::proto::packet_update_block_synced &obj, bool allocate);
bool packet_move_entity_delta(pdef::Stream &stream, const pdef::proto::packet_move_entity_delta &obj, bool allocate);
bool packet_set_scoreboard_identity(pdef::Stream &stream, const pdef::proto::packet_set_scoreboard_identity &obj, bool allocate);
bool packet_set_local_player_as_initialized(pdef::Stream &stream, const pdef::proto::packet_set_local_player_as_initialized &obj, bool allocate);
bool packet_update_soft_enum(pdef::Stream &stream, const pdef::proto::packet_update_soft_enum &obj, bool allocate);
bool packet_network_stack_latency(pdef::Stream &stream, const pdef::proto::packet_network_stack_latency &obj, bool allocate);
bool packet_script_custom_event(pdef::Stream &stream, const pdef::proto::packet_script_custom_event &obj, bool allocate);
bool packet_spawn_particle_effect(pdef::Stream &stream, const pdef::proto::packet_spawn_particle_effect &obj, bool allocate);
bool packet_available_entity_identifiers(pdef::Stream &stream, const pdef::proto::packet_available_entity_identifiers &obj, bool allocate);
bool packet_level_sound_event_v2(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_v2 &obj, bool allocate);
bool packet_network_chunk_publisher_update(pdef::Stream &stream, const pdef::proto::packet_network_chunk_publisher_update &obj, bool allocate);
bool packet_biome_definition_list(pdef::Stream &stream, const pdef::proto::packet_biome_definition_list &obj, bool allocate);
bool packet_level_sound_event(pdef::Stream &stream, const pdef::proto::packet_level_sound_event &obj, bool allocate);
bool packet_level_event_generic(pdef::Stream &stream, const pdef::proto::packet_level_event_generic &obj, bool allocate);
bool packet_lectern_update(pdef::Stream &stream, const pdef::proto::packet_lectern_update &obj, bool allocate);
bool packet_video_stream_connect(pdef::Stream &stream, const pdef::proto::packet_video_stream_connect &obj, bool allocate);
bool packet_add_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_add_ecs_entity &obj, bool allocate);
bool packet_remove_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_remove_ecs_entity &obj, bool allocate);
bool packet_client_cache_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_status &obj, bool allocate);
bool packet_on_screen_texture_animation(pdef::Stream &stream, const pdef::proto::packet_on_screen_texture_animation &obj, bool allocate);
bool packet_map_create_locked_copy(pdef::Stream &stream, const pdef::proto::packet_map_create_locked_copy &obj, bool allocate);
bool packet_structure_template_data_export_request(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_request &obj, bool allocate);
bool packet_structure_template_data_export_response(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_response &obj, bool allocate);
bool packet_update_block_properties(pdef::Stream &stream, const pdef::proto::packet_update_block_properties &obj, bool allocate);
bool packet_client_cache_blob_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_blob_status &obj, bool allocate);
bool packet_client_cache_miss_response(pdef::Stream &stream, const pdef::proto::packet_client_cache_miss_response &obj, bool allocate);
bool packet_education_settings(pdef::Stream &stream, const pdef::proto::packet_education_settings &obj, bool allocate);
bool packet_emote(pdef::Stream &stream, const pdef::proto::packet_emote &obj, bool allocate);
bool packet_multiplayer_settings(pdef::Stream &stream, const pdef::proto::packet_multiplayer_settings &obj, bool allocate);
bool packet_settings_command(pdef::Stream &stream, const pdef::proto::packet_settings_command &obj, bool allocate);
bool packet_anvil_damage(pdef::Stream &stream, const pdef::proto::packet_anvil_damage &obj, bool allocate);
bool packet_completed_using_item(pdef::Stream &stream, const pdef::proto::packet_completed_using_item &obj, bool allocate);
bool packet_network_settings(pdef::Stream &stream, const pdef::proto::packet_network_settings &obj, bool allocate);
bool packet_player_auth_input(pdef::Stream &stream, const pdef::proto::packet_player_auth_input &obj, bool allocate);
bool packet_creative_content(pdef::Stream &stream, const pdef::proto::packet_creative_content &obj, bool allocate);
bool packet_player_enchant_options(pdef::Stream &stream, const pdef::proto::packet_player_enchant_options &obj, bool allocate);
bool packet_item_stack_request(pdef::Stream &stream, const pdef::proto::packet_item_stack_request &obj, bool allocate);
bool packet_item_stack_response(pdef::Stream &stream, const pdef::proto::packet_item_stack_response &obj, bool allocate);
bool packet_player_armor_damage(pdef::Stream &stream, const pdef::proto::packet_player_armor_damage &obj, bool allocate);
bool packet_update_player_game_type(pdef::Stream &stream, const pdef::proto::packet_update_player_game_type &obj, bool allocate);
bool packet_emote_list(pdef::Stream &stream, const pdef::proto::packet_emote_list &obj, bool allocate);
bool packet_position_tracking_db_request(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_request &obj, bool allocate);
bool packet_position_tracking_db_broadcast(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_broadcast &obj, bool allocate);
bool packet_packet_violation_warning(pdef::Stream &stream, const pdef::proto::packet_packet_violation_warning &obj, bool allocate);
bool packet_motion_prediction_hints(pdef::Stream &stream, const pdef::proto::packet_motion_prediction_hints &obj, bool allocate);
bool packet_animate_entity(pdef::Stream &stream, const pdef::proto::packet_animate_entity &obj, bool allocate);
bool packet_camera_shake(pdef::Stream &stream, const pdef::proto::packet_camera_shake &obj, bool allocate);
bool packet_player_fog(pdef::Stream &stream, const pdef::proto::packet_player_fog &obj, bool allocate);
bool packet_correct_player_move_prediction(pdef::Stream &stream, const pdef::proto::packet_correct_player_move_prediction &obj, bool allocate);
bool packet_item_component(pdef::Stream &stream, const pdef::proto::packet_item_component &obj, bool allocate);
bool packet_filter_text_packet(pdef::Stream &stream, const pdef::proto::packet_filter_text_packet &obj, bool allocate);
bool packet_debug_renderer(pdef::Stream &stream, const pdef::proto::packet_debug_renderer &obj, bool allocate);
bool packet_sync_entity_property(pdef::Stream &stream, const pdef::proto::packet_sync_entity_property &obj, bool allocate);
bool packet_add_volume_entity(pdef::Stream &stream, const pdef::proto::packet_add_volume_entity &obj, bool allocate);
bool packet_remove_volume_entity(pdef::Stream &stream, const pdef::proto::packet_remove_volume_entity &obj, bool allocate);
bool packet_simulation_type(pdef::Stream &stream, const pdef::proto::packet_simulation_type &obj, bool allocate);
bool packet_npc_dialogue(pdef::Stream &stream, const pdef::proto::packet_npc_dialogue &obj, bool allocate);
bool packet_edu_uri_resource_packet(pdef::Stream &stream, const pdef::proto::packet_edu_uri_resource_packet &obj, bool allocate);
bool packet_create_photo(pdef::Stream &stream, const pdef::proto::packet_create_photo &obj, bool allocate);
bool packet_update_subchunk_blocks(pdef::Stream &stream, const pdef::proto::packet_update_subchunk_blocks &obj, bool allocate);
bool packet_photo_info_request(pdef::Stream &stream, const pdef::proto::packet_photo_info_request &obj, bool allocate);
bool SubChunkEntryWithoutCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithoutCaching &obj, bool allocate);
bool SubChunkEntryWithCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithCaching &obj, bool allocate);
bool packet_subchunk(pdef::Stream &stream, const pdef::proto::packet_subchunk &obj, bool allocate);
bool packet_subchunk_request(pdef::Stream &stream, const pdef::proto::packet_subchunk_request &obj, bool allocate);
bool packet_client_start_item_cooldown(pdef::Stream &stream, const pdef::proto::packet_client_start_item_cooldown &obj, bool allocate);
bool packet_script_message(pdef::Stream &stream, const pdef::proto::packet_script_message &obj, bool allocate);
bool packet_code_builder_source(pdef::Stream &stream, const pdef::proto::packet_code_builder_source &obj, bool allocate);
bool packet_ticking_areas_load_status(pdef::Stream &stream, const pdef::proto::packet_ticking_areas_load_status &obj, bool allocate);
bool packet_dimension_data(pdef::Stream &stream, const pdef::proto::packet_dimension_data &obj, bool allocate);
bool packet_agent_action(pdef::Stream &stream, const pdef::proto::packet_agent_action &obj, bool allocate);
bool packet_change_mob_property(pdef::Stream &stream, const pdef::proto::packet_change_mob_property &obj, bool allocate);
bool packet_lesson_progress(pdef::Stream &stream, const pdef::proto::packet_lesson_progress &obj, bool allocate);
bool packet_request_ability(pdef::Stream &stream, const pdef::proto::packet_request_ability &obj, bool allocate);
bool packet_request_permissions(pdef::Stream &stream, const pdef::proto::packet_request_permissions &obj, bool allocate);
bool packet_toast_request(pdef::Stream &stream, const pdef::proto::packet_toast_request &obj, bool allocate);
bool mcpe_packet(pdef::Stream &stream, const pdef::proto::mcpe_packet &obj, bool allocate);
bool BehaviourPackInfos(pdef::Stream &stream, const pdef::proto::BehaviourPackInfos &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::BehaviourPackInfos(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.uuid.length());
    WRITE_OR_BAIL(writeString, obj.uuid); /*uuid: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.version.length());
    WRITE_OR_BAIL(writeString, obj.version); /*version: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.size); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.content_key.length());
    WRITE_OR_BAIL(writeString, obj.content_key); /*content_key: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.sub_pack_name.length());
    WRITE_OR_BAIL(writeString, obj.sub_pack_name); /*sub_pack_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.content_identity.length());
    WRITE_OR_BAIL(writeString, obj.content_identity); /*content_identity: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_scripts); /*0.4*/
  return true;
}
bool TexturePackInfos(pdef::Stream &stream, const pdef::proto::TexturePackInfos &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::TexturePackInfos(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.uuid.length());
    WRITE_OR_BAIL(writeString, obj.uuid); /*uuid: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.version.length());
    WRITE_OR_BAIL(writeString, obj.version); /*version: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.size); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.content_key.length());
    WRITE_OR_BAIL(writeString, obj.content_key); /*content_key: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.sub_pack_name.length());
    WRITE_OR_BAIL(writeString, obj.sub_pack_name); /*sub_pack_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.content_identity.length());
    WRITE_OR_BAIL(writeString, obj.content_identity); /*content_identity: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_scripts); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.rtx_enabled); /*0.4*/
  return true;
}
bool ResourcePackIdVersions(pdef::Stream &stream, const pdef::proto::ResourcePackIdVersions &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::ResourcePackIdVersions(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.uuid.length());
    WRITE_OR_BAIL(writeString, obj.uuid); /*uuid: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.version.length());
    WRITE_OR_BAIL(writeString, obj.version); /*version: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
  return true;
}
  bool Experiment(pdef::Stream &stream, const pdef::proto::Experiment &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Experiment(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.enabled); /*0.4*/
    return true;
  }
  bool GameRule(pdef::Stream &stream, const pdef::proto::GameRule &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::GameRule(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.editable); /*0.4*/
    const pdef::proto::GameRule::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.type); /*7.1*/
    switch (type) { /*8.0*/
      case pdef::proto::GameRule::Type::Bool: { /*8.5*/
        WRITE_OR_BAIL(writeBool, (bool)obj.value_bool); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::GameRule::Type::Int: { /*8.5*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.value_zigzag32); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::GameRule::Type::Float: { /*8.5*/
        WRITE_OR_BAIL(writeFloatLE, (float)obj.value_lf32); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool Blob(pdef::Stream &stream, const pdef::proto::Blob &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Blob(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.hash); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.payload.size());
    WRITE_OR_BAIL(writeBuffer, obj.payload); /*payload: buffer*/ /*4.2*/
    return true;
  }
bool BlockProperties(pdef::Stream &stream, const pdef::proto::BlockProperties &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::BlockProperties(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.state); /*0.4*/
  return true;
}
bool Itemstates(pdef::Stream &stream, const pdef::proto::Itemstates &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::Itemstates(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeShortLE, (int16_t)obj.runtime_id); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.component_based); /*0.4*/
  return true;
}
  bool ItemExtraDataWithBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithBlockingTick &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::ItemExtraDataWithBlockingTick(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::ItemExtraDataWithBlockingTick::HasNbt &has_nbt = obj.has_nbt; /*0.3*/
    WRITE_OR_BAIL(writeUShortLE, (uint16_t)(uint16_t&)obj.has_nbt); /*7.1*/
    switch (has_nbt) { /*8.0*/
      case pdef::proto::ItemExtraDataWithBlockingTick::HasNbt::True: { /*8.5*/
        const pdef::proto::ItemExtraDataWithBlockingTick::Nbt &v = *obj.nbt; /*8.5*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)v.version); /*0.4*/
          WRITE_OR_BAIL(writeByte, (int8_t)v.nbt); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.can_place_on.size()); /*1.4*/
    for (const auto &v2 : obj.can_place_on) { /*3.1*/
      WRITE_OR_BAIL(writeShortLE, (int16_t)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.can_destroy.size()); /*1.4*/
    for (const auto &v2 : obj.can_destroy) { /*3.1*/
      WRITE_OR_BAIL(writeShortLE, (int16_t)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.blocking_tick); /*0.4*/
    return true;
  }
  bool ItemExtraDataWithoutBlockingTick(pdef::Stream &stream, const pdef::proto::ItemExtraDataWithoutBlockingTick &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::ItemExtraDataWithoutBlockingTick(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::ItemExtraDataWithoutBlockingTick::HasNbt &has_nbt = obj.has_nbt; /*0.3*/
    WRITE_OR_BAIL(writeUShortLE, (uint16_t)(uint16_t&)obj.has_nbt); /*7.1*/
    switch (has_nbt) { /*8.0*/
      case pdef::proto::ItemExtraDataWithoutBlockingTick::HasNbt::True: { /*8.5*/
        const pdef::proto::ItemExtraDataWithoutBlockingTick::Nbt &v = *obj.nbt; /*8.5*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)v.version); /*0.4*/
          WRITE_OR_BAIL(writeByte, (int8_t)v.nbt); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.can_place_on.size()); /*1.4*/
    for (const auto &v2 : obj.can_place_on) { /*3.1*/
      WRITE_OR_BAIL(writeShortLE, (int16_t)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.can_destroy.size()); /*1.4*/
    for (const auto &v2 : obj.can_destroy) { /*3.1*/
      WRITE_OR_BAIL(writeShortLE, (int16_t)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    return true;
  }
  bool ItemLegacy(pdef::Stream &stream, const pdef::proto::ItemLegacy &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::ItemLegacy(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &network_id = obj.network_id; /*0.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.network_id); /*0.4*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        WRITE_OR_BAIL(writeUShortLE, (uint16_t)obj.count); /*0.4*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.metadata); /*0.4*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.block_runtime_id); /*0.4*/
        if (network_id == pdef::proto::ShieldItemID) { /*8.4*/
          WRITE_OR_BAIL(writeByte, (int8_t)obj.extra__ShieldItemID); /*0.4*/
        }
        else {
          WRITE_OR_BAIL(writeByte, (int8_t)obj.extra_default); /*0.4*/
        }
    }
    return true;
  }
  bool Item(pdef::Stream &stream, const pdef::proto::Item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &network_id = obj.network_id; /*0.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.network_id); /*0.4*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        WRITE_OR_BAIL(writeUShortLE, (uint16_t)obj.count); /*0.4*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.metadata); /*0.4*/
        const uint8_t &has_stack_id = obj.has_stack_id; /*0.1*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)obj.has_stack_id); /*0.4*/
        if (has_stack_id == 0) { /*8.2*/
        }
        else {
          WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.stack_id); /*0.4*/
        }
        WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.block_runtime_id); /*0.4*/
        if (network_id == pdef::proto::ShieldItemID) { /*8.4*/
          WRITE_OR_BAIL(writeByte, (int8_t)obj.extra__ShieldItemID); /*0.4*/
        }
        else {
          WRITE_OR_BAIL(writeByte, (int8_t)obj.extra_default); /*0.4*/
        }
    }
    return true;
  }
  bool vec3i(pdef::Stream &stream, const pdef::proto::vec3i &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::vec3i(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.z); /*0.4*/
    return true;
  }
  bool vec3u(pdef::Stream &stream, const pdef::proto::vec3u &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::vec3u(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.z); /*0.4*/
    return true;
  }
  bool vec3f(pdef::Stream &stream, const pdef::proto::vec3f &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::vec3f(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatLE, (float)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.z); /*0.4*/
    return true;
  }
  bool vec2f(pdef::Stream &stream, const pdef::proto::vec2f &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::vec2f(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatLE, (float)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.z); /*0.4*/
    return true;
  }
bool MetadataDictionary(pdef::Stream &stream, const pdef::proto::MetadataDictionary &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::MetadataDictionary(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::MetadataDictionary::Key &key = obj.key; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.key); /*7.1*/
    const pdef::proto::MetadataDictionary::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.type); /*7.1*/
    switch (key) { /*8.0*/
      case pdef::proto::MetadataDictionary::Key::Flags: { /*8.5*/
        int64_t value_MetadataFlags1_val = 0;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.onfire << 0;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sneaking << 1;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.riding << 2;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sprinting << 3;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.action << 4;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.invisible << 5;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.tempted << 6;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.inlove << 7;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.saddled << 8;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.powered << 9;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.ignited << 10;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.baby << 11;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.converting << 12;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.critical << 13;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_show_nametag << 14;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.always_show_nametag << 15;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.no_ai << 16;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.silent << 17;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.wallclimbing << 18;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_climb << 19;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.swimmer << 20;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_fly << 21;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.walker << 22;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.resting << 23;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sitting << 24;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.angry << 25;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.interested << 26;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.charged << 27;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.tamed << 28;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.orphaned << 29;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.leashed << 30;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.sheared << 31;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.gliding << 32;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.elder << 33;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.moving << 34;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.breathing << 35;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.chested << 36;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.stackable << 37;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.showbase << 38;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.rearing << 39;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.vibrating << 40;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.idling << 41;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.evoker_spell << 42;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.charge_attack << 43;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.wasd_controlled << 44;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.can_power_jump << 45;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.linger << 46;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.has_collision << 47;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.affected_by_gravity << 48;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.fire_immune << 49;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.dancing << 50;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.enchanted << 51;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.show_trident_rope << 52;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.container_private << 53;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.transforming << 54;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.spin_attack << 55;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.swimming << 56;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.bribed << 57;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.pregnant << 58;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.laying_egg << 59;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.rider_can_pick << 60;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.transition_sitting << 61;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.eating << 62;
        value_MetadataFlags1_val |= (int64_t)obj.value_MetadataFlags1.laying_down << 63;
        WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)value_MetadataFlags1_val) /*value_MetadataFlags1: bitflags*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::MetadataDictionary::Key::FlagsExtended: { /*8.5*/
        int64_t value_MetadataFlags2_val = 0;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.sneezing << 0;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.trusting << 1;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.rolling << 2;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.scared << 3;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.in_scaffolding << 4;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.over_scaffolding << 5;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.fall_through_scaffolding << 6;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.blocking << 7;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.transition_blocking << 8;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.blocked_using_shield << 9;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.blocked_using_damaged_shield << 10;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.sleeping << 11;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.wants_to_wake << 12;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.trade_interest << 13;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.door_breaker << 14;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.breaking_obstruction << 15;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.door_opener << 16;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.illager_captain << 17;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.stunned << 18;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.roaring << 19;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.delayed_attacking << 20;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.avoiding_mobs << 21;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.avoiding_block << 22;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.facing_target_to_range_attack << 23;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.hidden_when_invisible << 24;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.is_in_ui << 25;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.stalking << 26;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.emoting << 27;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.celebrating << 28;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.admiring << 29;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.celebrating_special << 30;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.unknown95 << 31;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.ram_attack << 32;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.playing_dead << 33;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.in_ascendable_block << 34;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.over_descendable_block << 35;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.croaking << 36;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.eat_mob << 37;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.jump_goal_jump << 38;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.emerging << 39;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.sniffing << 40;
        value_MetadataFlags2_val |= (int64_t)obj.value_MetadataFlags2.digging << 41;
        WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)value_MetadataFlags2_val) /*value_MetadataFlags2: bitflags*/ /*4.2*/
        break;
      } /*8.7*/
      default: { /*8.3*/
        switch (type) { /*8.0*/
          case pdef::proto::MetadataDictionary::Type::Byte: { /*8.5*/
            WRITE_OR_BAIL(writeByte, (int8_t)obj.value_i8); /*0.4*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Short: { /*8.5*/
            WRITE_OR_BAIL(writeShortLE, (int16_t)obj.value_li16); /*0.4*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Int: { /*8.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.value_zigzag32); /*0.4*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Float: { /*8.5*/
            WRITE_OR_BAIL(writeFloatLE, (float)obj.value_lf32); /*0.4*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::String: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.value_string.length());
            WRITE_OR_BAIL(writeString, obj.value_string); /*value_string: pstring*/ /*4.2*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Compound: { /*8.5*/
            WRITE_OR_BAIL(writeByte, (int8_t)obj.value_nbt); /*0.4*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Vec3i: { /*8.5*/
            pdef::proto::encode::vec3i(stream, *obj.value_vec3i); /*vec3i*/ /*4.5*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Long: { /*8.5*/
            WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.value_zigzag64); /*0.4*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Vec3f: { /*8.5*/
            pdef::proto::encode::vec3f(stream, *obj.value_vec3f); /*vec3f*/ /*4.5*/
            break;
          } /*8.7*/
          default: break; /*avoid unhandled case warning*/
        } /*8.8*/
        break;
      } /*8.7*/
    } /*8.8*/
  return true;
}
  bool Link(pdef::Stream &stream, const pdef::proto::Link &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Link(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.ridden_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.rider_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.immediate); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.rider_initiated); /*0.4*/
    return true;
  }
bool EntityAttributes(pdef::Stream &stream, const pdef::proto::EntityAttributes &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::EntityAttributes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.min); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.value); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.max); /*0.4*/
  return true;
}
  bool Rotation(pdef::Stream &stream, const pdef::proto::Rotation &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Rotation(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.head_yaw); /*0.4*/
    return true;
  }
  bool BlockCoordinates(pdef::Stream &stream, const pdef::proto::BlockCoordinates &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::BlockCoordinates(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.z); /*0.4*/
    return true;
  }
bool PlayerAttributes(pdef::Stream &stream, const pdef::proto::PlayerAttributes &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::PlayerAttributes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatLE, (float)obj.min); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.max); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.current); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.default_); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
  return true;
}
  bool TransactionUseItem(pdef::Stream &stream, const pdef::proto::TransactionUseItem &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::TransactionUseItem(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.action_type); /*7.1*/
    pdef::proto::encode::BlockCoordinates(stream, obj.block_position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.face); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.hotbar_slot); /*0.4*/
    pdef::proto::encode::Item(stream, obj.held_item); /*Item*/ /*4.5*/
    pdef::proto::encode::vec3f(stream, obj.player_pos); /*vec3f*/ /*4.5*/
    pdef::proto::encode::vec3f(stream, obj.click_pos); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.block_runtime_id); /*0.4*/
    return true;
  }
bool TransactionActions(pdef::Stream &stream, const pdef::proto::TransactionActions &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::TransactionActions(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::TransactionActions::SourceType &source_type = obj.source_type; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.source_type); /*7.1*/
    switch (source_type) { /*8.0*/
      case pdef::proto::TransactionActions::SourceType::Container: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.inventory_id); /*7.1*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::Craft: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::WorldInteraction: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.flags); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::CraftSlot: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.slot); /*0.4*/
    pdef::proto::encode::Item(stream, obj.old_item); /*Item*/ /*4.5*/
    pdef::proto::encode::Item(stream, obj.new_item); /*Item*/ /*4.5*/
  return true;
}
  bool TransactionLegacy(pdef::Stream &stream, const pdef::proto::TransactionLegacy &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::TransactionLegacy(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &legacy_request_id = obj.legacy_request_id; /*0.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.legacy_request_id); /*0.4*/
    if (legacy_request_id == 0) { /*8.2*/
    }
    else {
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.legacy_transactions.size()); /*1.4*/
      for (const auto &v3 : obj.legacy_transactions) { /*5.20*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)v3.container_id); /*0.4*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.changed_slots.size()); /*1.4*/
        for (const auto &v4 : v3.changed_slots) { /*5.20*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)v4.slot_id); /*0.4*/
        }
      }
    }
    return true;
  }
  bool Transaction(pdef::Stream &stream, const pdef::proto::Transaction &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Transaction(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::TransactionLegacy(stream, obj.legacy); /*TransactionLegacy*/ /*4.5*/
    const pdef::proto::Transaction::TransactionType &transaction_type = obj.transaction_type; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.transaction_type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.actions.size()); /*2.1*/
    for (const auto &v : obj.actions) { pdef::proto::encode::TransactionActions(stream, v); } /*2.2*/
    switch (transaction_type) { /*8.0*/
      case pdef::proto::Transaction::TransactionType::Normal: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::InventoryMismatch: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemUse: { /*8.5*/
        pdef::proto::encode::TransactionUseItem(stream, *obj.transaction_data_TransactionUseItem); /*TransactionUseItem*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemUseOnEntity: { /*8.5*/
        const pdef::proto::Transaction::TransactionDataItemUseOnEntity &v = *obj.transaction_data_item_use_on_entity; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)v.entity_runtime_id); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)v.action_type); /*7.1*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.hotbar_slot); /*0.4*/
          pdef::proto::encode::Item(stream, v.held_item); /*Item*/ /*4.5*/
          pdef::proto::encode::vec3f(stream, v.player_pos); /*vec3f*/ /*4.5*/
          pdef::proto::encode::vec3f(stream, v.click_pos); /*vec3f*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemRelease: { /*8.5*/
        const pdef::proto::Transaction::TransactionDataItemRelease &v = *obj.transaction_data_item_release; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)v.action_type); /*7.1*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.hotbar_slot); /*0.4*/
          pdef::proto::encode::Item(stream, v.held_item); /*Item*/ /*4.5*/
          pdef::proto::encode::vec3f(stream, v.head_pos); /*vec3f*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool RecipeIngredient(pdef::Stream &stream, const pdef::proto::RecipeIngredient &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::RecipeIngredient(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &network_id = obj.network_id; /*0.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.network_id); /*0.4*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.network_data); /*0.4*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.count); /*0.4*/
    }
    return true;
  }
bool PotionTypeRecipes(pdef::Stream &stream, const pdef::proto::PotionTypeRecipes &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::PotionTypeRecipes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.input_item_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.input_item_meta); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.ingredient_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.ingredient_meta); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.output_item_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.output_item_meta); /*0.4*/
  return true;
}
bool PotionContainerChangeRecipes(pdef::Stream &stream, const pdef::proto::PotionContainerChangeRecipes &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::PotionContainerChangeRecipes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.input_item_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.ingredient_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.output_item_id); /*0.4*/
  return true;
}
bool Recipes(pdef::Stream &stream, const pdef::proto::Recipes &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::Recipes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::Recipes::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.type); /*7.1*/
    switch (type) { /*8.0*/
      case pdef::proto::Recipes::Type::Shapeless: { /*8.5*/
        const pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.recipe_id.length());
          WRITE_OR_BAIL(writeString, v.recipe_id); /*recipe_id: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.input.size()); /*1.4*/
          for (const auto &v5 : v.input) { /*3.1*/
            pdef::proto::encode::RecipeIngredient(stream, v5); /*RecipeIngredient*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.output.size()); /*1.4*/
          for (const auto &v5 : v.output) { /*3.1*/
            pdef::proto::encode::ItemLegacy(stream, v5); /*ItemLegacy*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.block.length());
          WRITE_OR_BAIL(writeString, v.block); /*block: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.priority); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.network_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShulkerBox: { /*8.5*/
        const pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.recipe_id.length());
          WRITE_OR_BAIL(writeString, v.recipe_id); /*recipe_id: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.input.size()); /*1.4*/
          for (const auto &v5 : v.input) { /*3.1*/
            pdef::proto::encode::RecipeIngredient(stream, v5); /*RecipeIngredient*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.output.size()); /*1.4*/
          for (const auto &v5 : v.output) { /*3.1*/
            pdef::proto::encode::ItemLegacy(stream, v5); /*ItemLegacy*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.block.length());
          WRITE_OR_BAIL(writeString, v.block); /*block: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.priority); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.network_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShapelessChemistry: { /*8.5*/
        const pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.recipe_id.length());
          WRITE_OR_BAIL(writeString, v.recipe_id); /*recipe_id: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.input.size()); /*1.4*/
          for (const auto &v5 : v.input) { /*3.1*/
            pdef::proto::encode::RecipeIngredient(stream, v5); /*RecipeIngredient*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.output.size()); /*1.4*/
          for (const auto &v5 : v.output) { /*3.1*/
            pdef::proto::encode::ItemLegacy(stream, v5); /*ItemLegacy*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.block.length());
          WRITE_OR_BAIL(writeString, v.block); /*block: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.priority); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.network_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Shaped: { /*8.5*/
        const pdef::proto::Recipes::RecipeShapedOrShapedChemistry &v = *obj.recipe_shaped_or_shaped_chemistry; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.recipe_id.length());
          WRITE_OR_BAIL(writeString, v.recipe_id); /*recipe_id: pstring*/ /*4.2*/
          const int &width = v.width; /*0.1*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.width); /*0.4*/
          const int &height = v.height; /*0.1*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.height); /*0.4*/
          for (const auto &v : v.input) { /*5.1*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)height); /*5.4*/
            for (const auto &v : v) { /*5.10*/
              pdef::proto::encode::RecipeIngredient(stream, v); /*5.13*/
            }
          }
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.output.size()); /*1.4*/
          for (const auto &v5 : v.output) { /*3.1*/
            pdef::proto::encode::ItemLegacy(stream, v5); /*ItemLegacy*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.block.length());
          WRITE_OR_BAIL(writeString, v.block); /*block: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.priority); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.network_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShapedChemistry: { /*8.5*/
        const pdef::proto::Recipes::RecipeShapedOrShapedChemistry &v = *obj.recipe_shaped_or_shaped_chemistry; /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.recipe_id.length());
          WRITE_OR_BAIL(writeString, v.recipe_id); /*recipe_id: pstring*/ /*4.2*/
          const int &width = v.width; /*0.1*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.width); /*0.4*/
          const int &height = v.height; /*0.1*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.height); /*0.4*/
          for (const auto &v : v.input) { /*5.1*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)height); /*5.4*/
            for (const auto &v : v) { /*5.10*/
              pdef::proto::encode::RecipeIngredient(stream, v); /*5.13*/
            }
          }
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.output.size()); /*1.4*/
          for (const auto &v5 : v.output) { /*3.1*/
            pdef::proto::encode::ItemLegacy(stream, v5); /*ItemLegacy*/ /*4.5*/
          }
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.block.length());
          WRITE_OR_BAIL(writeString, v.block); /*block: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.priority); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.network_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Furnace: { /*8.5*/
        const pdef::proto::Recipes::RecipeFurnace &v = *obj.recipe_furnace; /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.input_id); /*0.4*/
          pdef::proto::encode::ItemLegacy(stream, v.output); /*ItemLegacy*/ /*4.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.block.length());
          WRITE_OR_BAIL(writeString, v.block); /*block: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::FurnaceWithMetadata: { /*8.5*/
        const pdef::proto::Recipes::RecipeFurnaceWithMetadata &v = *obj.recipe_furnace_with_metadata; /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.input_id); /*0.4*/
          WRITE_OR_BAIL(writeZigZagVarInt, (int)v.input_meta); /*0.4*/
          pdef::proto::encode::ItemLegacy(stream, v.output); /*ItemLegacy*/ /*4.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.block.length());
          WRITE_OR_BAIL(writeString, v.block); /*block: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Multi: { /*8.5*/
        const pdef::proto::Recipes::RecipeMulti &v = *obj.recipe_multi; /*8.5*/
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.network_id); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  return true;
}
  bool SkinImage(pdef::Stream &stream, const pdef::proto::SkinImage &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::SkinImage(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.width); /*0.4*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.height); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data.size());
    WRITE_OR_BAIL(writeBuffer, obj.data); /*data: buffer*/ /*4.2*/
    return true;
  }
  bool Skin(pdef::Stream &stream, const pdef::proto::Skin &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Skin(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skin_id.length());
    WRITE_OR_BAIL(writeString, obj.skin_id); /*skin_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.play_fab_id.length());
    WRITE_OR_BAIL(writeString, obj.play_fab_id); /*play_fab_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skin_resource_pack.length());
    WRITE_OR_BAIL(writeString, obj.skin_resource_pack); /*skin_resource_pack: pstring*/ /*4.2*/
    pdef::proto::encode::SkinImage(stream, obj.skin_data); /*SkinImage*/ /*4.5*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.animations.size()); /*1.4*/
    for (const auto &v2 : obj.animations) { /*5.20*/
      pdef::proto::encode::SkinImage(stream, v2.skin_image); /*SkinImage*/ /*4.5*/
      WRITE_OR_BAIL(writeIntLE, (int32_t)v2.animation_type); /*0.4*/
      WRITE_OR_BAIL(writeFloatLE, (float)v2.animation_frames); /*0.4*/
      WRITE_OR_BAIL(writeFloatLE, (float)v2.expression_type); /*0.4*/
    }
    pdef::proto::encode::SkinImage(stream, obj.cape_data); /*SkinImage*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.geometry_data.length());
    WRITE_OR_BAIL(writeString, obj.geometry_data); /*geometry_data: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.geometry_data_version.length());
    WRITE_OR_BAIL(writeString, obj.geometry_data_version); /*geometry_data_version: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.animation_data.length());
    WRITE_OR_BAIL(writeString, obj.animation_data); /*animation_data: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.cape_id.length());
    WRITE_OR_BAIL(writeString, obj.cape_id); /*cape_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.full_skin_id.length());
    WRITE_OR_BAIL(writeString, obj.full_skin_id); /*full_skin_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.arm_size.length());
    WRITE_OR_BAIL(writeString, obj.arm_size); /*arm_size: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skin_color.length());
    WRITE_OR_BAIL(writeString, obj.skin_color); /*skin_color: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.personal_pieces.size()); /*1.4*/
    for (const auto &v2 : obj.personal_pieces) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.piece_id.length());
      WRITE_OR_BAIL(writeString, v2.piece_id); /*piece_id: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.piece_type.length());
      WRITE_OR_BAIL(writeString, v2.piece_type); /*piece_type: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.pack_id.length());
      WRITE_OR_BAIL(writeString, v2.pack_id); /*pack_id: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeBool, (bool)v2.is_default_piece); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.product_id.length());
      WRITE_OR_BAIL(writeString, v2.product_id); /*product_id: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.piece_tint_colors.size()); /*1.4*/
    for (const auto &v2 : obj.piece_tint_colors) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.piece_type.length());
      WRITE_OR_BAIL(writeString, v2.piece_type); /*piece_type: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeIntLE, (int32_t)v2.colors.size()); /*1.4*/
      for (const auto &v3 : v2.colors) { /*3.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.length());
        WRITE_OR_BAIL(writeString, v3); /*: pstring*/ /*4.2*/
      }
    }
    WRITE_OR_BAIL(writeBool, (bool)obj.premium); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.persona); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.cape_on_classic); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.primary_user); /*0.4*/
    return true;
  }
  bool PlayerRecords(pdef::Stream &stream, const pdef::proto::PlayerRecords &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::PlayerRecords(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::PlayerRecords::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.type); /*7.1*/
    const int &records_count = obj.records_count; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.records_count); /*0.4*/
    switch (type) { /*8.0*/
      case pdef::proto::PlayerRecords::Type::Add: { /*8.5*/
        const pdef::proto::PlayerRecords::RecordsAdd &v = *obj.records_add; /*8.5*/
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
          WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v.entity_unique_id); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.username.length());
          WRITE_OR_BAIL(writeString, v.username); /*username: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.xbox_user_id.length());
          WRITE_OR_BAIL(writeString, v.xbox_user_id); /*xbox_user_id: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.platform_chat_id.length());
          WRITE_OR_BAIL(writeString, v.platform_chat_id); /*platform_chat_id: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeIntLE, (int32_t)v.build_platform); /*0.4*/
          pdef::proto::encode::Skin(stream, v.skin_data); /*Skin*/ /*4.5*/
          WRITE_OR_BAIL(writeBool, (bool)v.is_teacher); /*0.4*/
          WRITE_OR_BAIL(writeBool, (bool)v.is_host); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::PlayerRecords::Type::Remove: { /*8.5*/
        const pdef::proto::PlayerRecords::RecordsRemove &v = *obj.records_remove; /*8.5*/
          WRITE_OR_BAIL(writeULongBE, (uint64_t)v.uuid); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    switch (type) { /*8.0*/
      case pdef::proto::PlayerRecords::Type::Add: { /*8.5*/
        for (const auto &v4 : obj.verified) { /*3.1*/
          WRITE_OR_BAIL(writeBool, (bool)v4); /*0.4*/
        }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool Enchant(pdef::Stream &stream, const pdef::proto::Enchant &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::Enchant(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.level); /*0.4*/
    return true;
  }
  bool EnchantOption(pdef::Stream &stream, const pdef::proto::EnchantOption &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::EnchantOption(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.cost); /*0.4*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.slot_flags); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.equip_enchants.size()); /*1.4*/
    for (const auto &v2 : obj.equip_enchants) { /*3.1*/
      pdef::proto::encode::Enchant(stream, v2); /*Enchant*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.held_enchants.size()); /*1.4*/
    for (const auto &v2 : obj.held_enchants) { /*3.1*/
      pdef::proto::encode::Enchant(stream, v2); /*Enchant*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.self_enchants.size()); /*1.4*/
    for (const auto &v2 : obj.self_enchants) { /*3.1*/
      pdef::proto::encode::Enchant(stream, v2); /*Enchant*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.option_id); /*0.4*/
    return true;
  }
  bool StackRequestSlotInfo(pdef::Stream &stream, const pdef::proto::StackRequestSlotInfo &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::StackRequestSlotInfo(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.slot_type); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.slot); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.stack_id); /*0.4*/
    return true;
  }
  bool ItemStackRequest(pdef::Stream &stream, const pdef::proto::ItemStackRequest &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::ItemStackRequest(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.request_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.actions.size()); /*1.4*/
    for (const auto &v2 : obj.actions) { /*5.20*/
      const pdef::proto::ItemStackRequest::Actions::TypeId &type_id = v2.type_id; /*0.3*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)v2.type_id); /*7.1*/
      switch (type_id) { /*8.0*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Take: { /*8.5*/
            WRITE_OR_BAIL(writeUByte, (uint8_t)v2.count); /*0.4*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.source); /*StackRequestSlotInfo*/ /*4.5*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.destination); /*StackRequestSlotInfo*/ /*4.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Place: { /*8.5*/
            WRITE_OR_BAIL(writeUByte, (uint8_t)v2.count); /*0.4*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.source); /*StackRequestSlotInfo*/ /*4.5*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.destination); /*StackRequestSlotInfo*/ /*4.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Swap: { /*8.5*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.source); /*StackRequestSlotInfo*/ /*4.5*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.destination); /*StackRequestSlotInfo*/ /*4.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Drop: { /*8.5*/
            WRITE_OR_BAIL(writeUByte, (uint8_t)v2.count); /*0.4*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.source); /*StackRequestSlotInfo*/ /*4.5*/
            WRITE_OR_BAIL(writeBool, (bool)v2.randomly); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Destroy: { /*8.5*/
            WRITE_OR_BAIL(writeUByte, (uint8_t)v2.count); /*0.4*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.source); /*StackRequestSlotInfo*/ /*4.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Consume: { /*8.5*/
            WRITE_OR_BAIL(writeUByte, (uint8_t)v2.count); /*0.4*/
            pdef::proto::encode::StackRequestSlotInfo(stream, *v2.source); /*StackRequestSlotInfo*/ /*4.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Create: { /*8.5*/
            WRITE_OR_BAIL(writeUByte, (uint8_t)v2.result_slot_id); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::BeaconPayment: { /*8.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v2.primary_effect); /*0.4*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v2.secondary_effect); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::MineBlock: { /*8.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v2.unknown1); /*0.4*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v2.predicted_durability); /*0.4*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v2.network_id); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftRecipe: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.recipe_network_id); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftRecipeAuto: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.recipe_network_id); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftCreative: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.item_id); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Optional: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.recipe_network_id); /*0.4*/
            WRITE_OR_BAIL(writeIntLE, (int32_t)v2.filtered_string_index); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftGrindstoneRequest: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.recipe_network_id); /*0.4*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.cost); /*0.4*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftLoomRequest: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.pattern.length());
            WRITE_OR_BAIL(writeString, v2.pattern); /*pattern: pstring*/ /*4.2*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::NonImplemented: { /*8.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::ResultsDeprecated: { /*8.5*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.result_items.size()); /*1.4*/
            for (const auto &v6 : v2.result_items) { /*3.1*/
              pdef::proto::encode::ItemLegacy(stream, v6); /*ItemLegacy*/ /*4.5*/
            }
            WRITE_OR_BAIL(writeUByte, (uint8_t)v2.times_crafted); /*0.4*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.custom_names.size()); /*1.4*/
    for (const auto &v2 : obj.custom_names) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    return true;
  }
bool ItemStackResponses(pdef::Stream &stream, const pdef::proto::ItemStackResponses &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::ItemStackResponses(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::ItemStackResponses::Status &status = obj.status; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.status); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.request_id); /*0.4*/
    switch (status) { /*8.0*/
      case pdef::proto::ItemStackResponses::Status::Ok: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.containers.size()); /*1.4*/
          for (const auto &v5 : obj.containers) { /*5.20*/
            WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)v5.slot_type); /*7.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v5.slots.size()); /*1.4*/
            for (const auto &v6 : v5.slots) { /*5.20*/
              WRITE_OR_BAIL(writeUByte, (uint8_t)v6.slot); /*0.4*/
              WRITE_OR_BAIL(writeUByte, (uint8_t)v6.hotbar_slot); /*0.4*/
              WRITE_OR_BAIL(writeUByte, (uint8_t)v6.count); /*0.4*/
              WRITE_OR_BAIL(writeZigZagVarInt, (int)v6.item_stack_id); /*0.4*/
              WRITE_OR_BAIL(writeUnsignedVarInt, (int)v6.custom_name.length());
              WRITE_OR_BAIL(writeString, v6.custom_name); /*custom_name: pstring*/ /*4.2*/
              WRITE_OR_BAIL(writeZigZagVarInt, (int)v6.durability_correction); /*0.4*/
            }
          }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  return true;
}
bool ItemComponentList(pdef::Stream &stream, const pdef::proto::ItemComponentList &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::ItemComponentList(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
  return true;
}
  bool CommandOrigin(pdef::Stream &stream, const pdef::proto::CommandOrigin &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::CommandOrigin(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::CommandOrigin::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.type); /*7.1*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.uuid); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.request_id.length());
    WRITE_OR_BAIL(writeString, obj.request_id); /*request_id: pstring*/ /*4.2*/
    switch (type) { /*8.0*/
      case pdef::proto::CommandOrigin::Type::DevConsole: { /*8.5*/
        const pdef::proto::CommandOrigin::PlayerEntityId &v = *obj.player_entity_id; /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v.player_entity_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::CommandOrigin::Type::Test: { /*8.5*/
        const pdef::proto::CommandOrigin::PlayerEntityId &v = *obj.player_entity_id; /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v.player_entity_id); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool TrackedObject(pdef::Stream &stream, const pdef::proto::TrackedObject &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::TrackedObject(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::TrackedObject::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)(int32_t&)obj.type); /*7.1*/
    switch (type) { /*8.0*/
      case pdef::proto::TrackedObject::Type::Entity: { /*8.5*/
        WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_unique_id); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    switch (type) { /*8.0*/
      case pdef::proto::TrackedObject::Type::Block: { /*8.5*/
        pdef::proto::encode::BlockCoordinates(stream, *obj.block_position); /*BlockCoordinates*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool MapDecoration(pdef::Stream &stream, const pdef::proto::MapDecoration &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::MapDecoration(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.rotation); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.label.length());
    WRITE_OR_BAIL(writeString, obj.label); /*label: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.color_abgr); /*0.4*/
    return true;
  }
  bool StructureBlockSettings(pdef::Stream &stream, const pdef::proto::StructureBlockSettings &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::StructureBlockSettings(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.palette_name.length());
    WRITE_OR_BAIL(writeString, obj.palette_name); /*palette_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.ignore_entities); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.ignore_blocks); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.non_ticking_players_and_ticking_areas); /*0.4*/
    pdef::proto::encode::BlockCoordinates(stream, obj.size); /*BlockCoordinates*/ /*4.5*/
    pdef::proto::encode::BlockCoordinates(stream, obj.structure_offset); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.last_editing_player_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.rotation); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.mirror); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.animation_mode); /*7.1*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.animation_duration); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.integrity); /*0.4*/
    WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.seed); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.pivot); /*vec3f*/ /*4.5*/
    return true;
  }
  bool EducationSharedResourceURI(pdef::Stream &stream, const pdef::proto::EducationSharedResourceURI &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::EducationSharedResourceURI(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.button_name.length());
    WRITE_OR_BAIL(writeString, obj.button_name); /*button_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.link_uri.length());
    WRITE_OR_BAIL(writeString, obj.link_uri); /*link_uri: pstring*/ /*4.2*/
    return true;
  }
  bool EducationExternalLinkSettings(pdef::Stream &stream, const pdef::proto::EducationExternalLinkSettings &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::EducationExternalLinkSettings(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.url.length());
    WRITE_OR_BAIL(writeString, obj.url); /*url: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.display_name.length());
    WRITE_OR_BAIL(writeString, obj.display_name); /*display_name: pstring*/ /*4.2*/
    return true;
  }
  bool BlockUpdate(pdef::Stream &stream, const pdef::proto::BlockUpdate &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::BlockUpdate(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.runtime_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.flags); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.transition_type); /*7.1*/
    return true;
  }
  bool MaterialReducer(pdef::Stream &stream, const pdef::proto::MaterialReducer &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::MaterialReducer(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.mix); /*0.4*/
    const pdef::proto::MaterialReducer::Items &v = obj.items; /*["MaterialReducer"]*/ /*7.4*/
    return true;
  }
  bool packet_login(pdef::Stream &stream, const pdef::proto::packet_login &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_login(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)obj.protocol_version); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.tokens); /*0.4*/
    return true;
  }
  bool LoginTokens(pdef::Stream &stream, const pdef::proto::LoginTokens &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::LoginTokens(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.identity.length());
    WRITE_OR_BAIL(writeString, obj.identity); /*identity: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.client.length());
    WRITE_OR_BAIL(writeString, obj.client); /*client: pstring*/ /*4.2*/
    return true;
  }
  bool packet_play_status(pdef::Stream &stream, const pdef::proto::packet_play_status &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_play_status(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeIntBE, (int32_t)(int32_t&)obj.status); /*7.1*/
    return true;
  }
  bool packet_server_to_client_handshake(pdef::Stream &stream, const pdef::proto::packet_server_to_client_handshake &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_server_to_client_handshake(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.token.length());
    WRITE_OR_BAIL(writeString, obj.token); /*token: pstring*/ /*4.2*/
    return true;
  }
  bool packet_client_to_server_handshake(pdef::Stream &stream, const pdef::proto::packet_client_to_server_handshake &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_client_to_server_handshake(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    return true;
  }
  bool packet_disconnect(pdef::Stream &stream, const pdef::proto::packet_disconnect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_disconnect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.hide_disconnect_reason); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
    WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
    return true;
  }
  bool packet_resource_packs_info(pdef::Stream &stream, const pdef::proto::packet_resource_packs_info &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_resource_packs_info(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.must_accept); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_scripts); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.force_server_packs); /*0.4*/
    WRITE_OR_BAIL(writeShortLE, (int16_t)obj.behaviour_packs.size()); /*2.1*/
    for (const auto &v : obj.behaviour_packs) { pdef::proto::encode::BehaviourPackInfos(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeShortLE, (int16_t)obj.texture_packs.size()); /*2.1*/
    for (const auto &v : obj.texture_packs) { pdef::proto::encode::TexturePackInfos(stream, v); } /*2.2*/
    return true;
  }
  bool packet_resource_pack_stack(pdef::Stream &stream, const pdef::proto::packet_resource_pack_stack &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_resource_pack_stack(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.must_accept); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.behavior_packs.size()); /*2.1*/
    for (const auto &v : obj.behavior_packs) { pdef::proto::encode::ResourcePackIdVersions(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.resource_packs.size()); /*2.1*/
    for (const auto &v : obj.resource_packs) { pdef::proto::encode::ResourcePackIdVersions(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.game_version.length());
    WRITE_OR_BAIL(writeString, obj.game_version); /*game_version: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.experiments.size()); /*1.4*/
    for (const auto &v2 : obj.experiments) { /*3.1*/
      pdef::proto::encode::Experiment(stream, v2); /*Experiment*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeBool, (bool)obj.experiments_previously_used); /*0.4*/
    return true;
  }
  bool packet_resource_pack_client_response(pdef::Stream &stream, const pdef::proto::packet_resource_pack_client_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_resource_pack_client_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.response_status); /*7.1*/
    WRITE_OR_BAIL(writeShortLE, (int16_t)obj.resourcepackids.size()); /*1.4*/
    for (const auto &v2 : obj.resourcepackids) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    return true;
  }
  bool packet_text(pdef::Stream &stream, const pdef::proto::packet_text &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_text(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::packet_text::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.type); /*7.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.needs_translation); /*0.4*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_text::Type::Chat: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.source_name.length());
          WRITE_OR_BAIL(writeString, obj.source_name); /*source_name: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Whisper: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.source_name.length());
          WRITE_OR_BAIL(writeString, obj.source_name); /*source_name: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Announcement: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.source_name.length());
          WRITE_OR_BAIL(writeString, obj.source_name); /*source_name: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Raw: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Tip: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::System: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::JsonWhisper: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Json: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Translation: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.parameters.size()); /*1.4*/
          for (const auto &v5 : obj.parameters) { /*3.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v5.length());
            WRITE_OR_BAIL(writeString, v5); /*: pstring*/ /*4.2*/
          }
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Popup: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.parameters.size()); /*1.4*/
          for (const auto &v5 : obj.parameters) { /*3.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v5.length());
            WRITE_OR_BAIL(writeString, v5); /*: pstring*/ /*4.2*/
          }
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::JukeboxPopup: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
          WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.parameters.size()); /*1.4*/
          for (const auto &v5 : obj.parameters) { /*3.1*/
            WRITE_OR_BAIL(writeUnsignedVarInt, (int)v5.length());
            WRITE_OR_BAIL(writeString, v5); /*: pstring*/ /*4.2*/
          }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.xuid.length());
    WRITE_OR_BAIL(writeString, obj.xuid); /*xuid: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.platform_chat_id.length());
    WRITE_OR_BAIL(writeString, obj.platform_chat_id); /*platform_chat_id: pstring*/ /*4.2*/
    return true;
  }
  bool packet_set_time(pdef::Stream &stream, const pdef::proto::packet_set_time &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_time(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.time); /*0.4*/
    return true;
  }
  bool packet_start_game(pdef::Stream &stream, const pdef::proto::packet_start_game &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_start_game(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.player_gamemode); /*7.1*/
    pdef::proto::encode::vec3f(stream, obj.player_position); /*vec3f*/ /*4.5*/
    pdef::proto::encode::vec2f(stream, obj.rotation); /*vec2f*/ /*4.5*/
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.seed); /*0.4*/
    WRITE_OR_BAIL(writeShortLE, (int16_t)obj.biome_type); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.biome_name.length());
    WRITE_OR_BAIL(writeString, obj.biome_name); /*biome_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.dimension); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.generator); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.world_gamemode); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.difficulty); /*0.4*/
    pdef::proto::encode::BlockCoordinates(stream, obj.spawn_position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeBool, (bool)obj.achievements_disabled); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.day_cycle_stop_time); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.edu_offer); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.edu_features_enabled); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.edu_product_uuid.length());
    WRITE_OR_BAIL(writeString, obj.edu_product_uuid); /*edu_product_uuid: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.rain_level); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.lightning_level); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_confirmed_platform_locked_content); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_multiplayer); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.broadcast_to_lan); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.xbox_live_broadcast_mode); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.platform_broadcast_mode); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.enable_commands); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_texturepacks_required); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.gamerules.size()); /*1.4*/
    for (const auto &v2 : obj.gamerules) { /*3.1*/
      pdef::proto::encode::GameRule(stream, v2); /*GameRule*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.experiments.size()); /*1.4*/
    for (const auto &v2 : obj.experiments) { /*3.1*/
      pdef::proto::encode::Experiment(stream, v2); /*Experiment*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeBool, (bool)obj.experiments_previously_used); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.bonus_chest); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.map_enabled); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.permission_level); /*0.4*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.server_chunk_tick_range); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_locked_behavior_pack); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_locked_resource_pack); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_from_locked_world_template); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.msa_gamertags_only); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_from_world_template); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_world_template_option_locked); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.only_spawn_v1_villagers); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.game_version.length());
    WRITE_OR_BAIL(writeString, obj.game_version); /*game_version: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.limited_world_width); /*0.4*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.limited_world_length); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_new_nether); /*0.4*/
    pdef::proto::encode::EducationSharedResourceURI(stream, obj.edu_resource_uri); /*EducationSharedResourceURI*/ /*4.5*/
    WRITE_OR_BAIL(writeBool, (bool)obj.experimental_gameplay_override); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.level_id.length());
    WRITE_OR_BAIL(writeString, obj.level_id); /*level_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.world_name.length());
    WRITE_OR_BAIL(writeString, obj.world_name); /*world_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.premium_world_template_id.length());
    WRITE_OR_BAIL(writeString, obj.premium_world_template_id); /*premium_world_template_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_trial); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.movement_authority); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.rewind_history_size); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.server_authoritative_block_breaking); /*0.4*/
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.current_tick); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.enchantment_seed); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.block_properties.size()); /*2.1*/
    for (const auto &v : obj.block_properties) { pdef::proto::encode::BlockProperties(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.itemstates.size()); /*2.1*/
    for (const auto &v : obj.itemstates) { pdef::proto::encode::Itemstates(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.multiplayer_correlation_id.length());
    WRITE_OR_BAIL(writeString, obj.multiplayer_correlation_id); /*multiplayer_correlation_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.server_authoritative_inventory); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.engine.length());
    WRITE_OR_BAIL(writeString, obj.engine); /*engine: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.property_data); /*0.4*/
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.block_pallette_checksum); /*0.4*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.world_template_id); /*0.4*/
    return true;
  }
  bool packet_add_player(pdef::Stream &stream, const pdef::proto::packet_add_player &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_add_player(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.uuid); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.username.length());
    WRITE_OR_BAIL(writeString, obj.username); /*username: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.unique_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.platform_chat_id.length());
    WRITE_OR_BAIL(writeString, obj.platform_chat_id); /*platform_chat_id: pstring*/ /*4.2*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    pdef::proto::encode::vec3f(stream, obj.velocity); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.head_yaw); /*0.4*/
    pdef::proto::encode::Item(stream, obj.held_item); /*Item*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.gamemode); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.metadata.size()); /*2.1*/
    for (const auto &v : obj.metadata) { pdef::proto::encode::MetadataDictionary(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.flags); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command_permission); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action_permissions); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.permission_level); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.custom_stored_permissions); /*0.4*/
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.user_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.links.size()); /*1.4*/
    for (const auto &v2 : obj.links) { /*3.1*/
      pdef::proto::encode::Link(stream, v2); /*Link*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.device_id.length());
    WRITE_OR_BAIL(writeString, obj.device_id); /*device_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)(int32_t&)obj.device_os); /*7.1*/
    return true;
  }
  bool packet_add_entity(pdef::Stream &stream, const pdef::proto::packet_add_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_add_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_id_self); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entity_type.length());
    WRITE_OR_BAIL(writeString, obj.entity_type); /*entity_type: pstring*/ /*4.2*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    pdef::proto::encode::vec3f(stream, obj.velocity); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.head_yaw); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.attributes.size()); /*2.1*/
    for (const auto &v : obj.attributes) { pdef::proto::encode::EntityAttributes(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.metadata.size()); /*2.1*/
    for (const auto &v : obj.metadata) { pdef::proto::encode::MetadataDictionary(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.links.size()); /*1.4*/
    for (const auto &v2 : obj.links) { /*3.1*/
      pdef::proto::encode::Link(stream, v2); /*Link*/ /*4.5*/
    }
    return true;
  }
  bool packet_remove_entity(pdef::Stream &stream, const pdef::proto::packet_remove_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_remove_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_id_self); /*0.4*/
    return true;
  }
  bool packet_add_item_entity(pdef::Stream &stream, const pdef::proto::packet_add_item_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_add_item_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_id_self); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    pdef::proto::encode::Item(stream, obj.item); /*Item*/ /*4.5*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    pdef::proto::encode::vec3f(stream, obj.velocity); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.metadata.size()); /*2.1*/
    for (const auto &v : obj.metadata) { pdef::proto::encode::MetadataDictionary(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_from_fishing); /*0.4*/
    return true;
  }
  bool packet_take_item_entity(pdef::Stream &stream, const pdef::proto::packet_take_item_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_take_item_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.target); /*0.4*/
    return true;
  }
  bool packet_move_entity(pdef::Stream &stream, const pdef::proto::packet_move_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_move_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.flags); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    pdef::proto::encode::Rotation(stream, obj.rotation); /*Rotation*/ /*4.5*/
    return true;
  }
  bool packet_move_player(pdef::Stream &stream, const pdef::proto::packet_move_player &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_move_player(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.runtime_id); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.yaw); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.head_yaw); /*0.4*/
    const pdef::proto::packet_move_player::Mode &mode = obj.mode; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.mode); /*7.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.on_ground); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.ridden_runtime_id); /*0.4*/
    switch (mode) { /*8.0*/
      case pdef::proto::packet_move_player::Mode::Teleport: { /*8.5*/
        const pdef::proto::packet_move_player::Teleport &v = *obj.teleport; /*8.5*/
          WRITE_OR_BAIL(writeIntLE, (int32_t)(int32_t&)v.cause); /*7.1*/
          WRITE_OR_BAIL(writeIntLE, (int32_t)(int32_t&)v.source_entity_type); /*7.1*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.tick); /*0.4*/
    return true;
  }
  bool packet_rider_jump(pdef::Stream &stream, const pdef::proto::packet_rider_jump &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_rider_jump(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.jump_strength); /*0.4*/
    return true;
  }
  bool packet_update_block(pdef::Stream &stream, const pdef::proto::packet_update_block &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_block(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.block_runtime_id); /*0.4*/
    int flags_val = 0;
    if (obj.flags.neighbors) flags_val |= 1;
    if (obj.flags.network) flags_val |= 2;
    if (obj.flags.no_graphic) flags_val |= 4;
    if (obj.flags.unused) flags_val |= 8;
    if (obj.flags.priority) flags_val |= 16;
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)flags_val) /*flags: bitflags*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.layer); /*0.4*/
    return true;
  }
  bool packet_add_painting(pdef::Stream &stream, const pdef::proto::packet_add_painting &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_add_painting(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_id_self); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.coordinates); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.direction); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title.length());
    WRITE_OR_BAIL(writeString, obj.title); /*title: pstring*/ /*4.2*/
    return true;
  }
  bool packet_tick_sync(pdef::Stream &stream, const pdef::proto::packet_tick_sync &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_tick_sync(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.request_time); /*0.4*/
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.response_time); /*0.4*/
    return true;
  }
  bool packet_level_sound_event_old(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_old &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_level_sound_event_old(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.sound_id); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.block_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.entity_type); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_baby_mob); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_global); /*0.4*/
    return true;
  }
  bool packet_level_event(pdef::Stream &stream, const pdef::proto::packet_level_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_level_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.event); /*7.1*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.data); /*0.4*/
    return true;
  }
  bool packet_block_event(pdef::Stream &stream, const pdef::proto::packet_block_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_block_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.type); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.data); /*0.4*/
    return true;
  }
  bool packet_entity_event(pdef::Stream &stream, const pdef::proto::packet_entity_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_entity_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.event_id); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.data); /*0.4*/
    return true;
  }
  bool packet_mob_effect(pdef::Stream &stream, const pdef::proto::packet_mob_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_mob_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.event_id); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.effect_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.amplifier); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.particles); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.duration); /*0.4*/
    return true;
  }
  bool packet_update_attributes(pdef::Stream &stream, const pdef::proto::packet_update_attributes &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_attributes(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.attributes.size()); /*2.1*/
    for (const auto &v : obj.attributes) { pdef::proto::encode::PlayerAttributes(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.tick); /*0.4*/
    return true;
  }
  bool packet_inventory_transaction(pdef::Stream &stream, const pdef::proto::packet_inventory_transaction &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_inventory_transaction(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::Transaction(stream, obj.transaction); /*Transaction*/ /*4.5*/
    return true;
  }
  bool packet_mob_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_equipment &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_mob_equipment(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    pdef::proto::encode::Item(stream, obj.item); /*Item*/ /*4.5*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.slot); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.selected_slot); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    return true;
  }
  bool packet_mob_armor_equipment(pdef::Stream &stream, const pdef::proto::packet_mob_armor_equipment &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_mob_armor_equipment(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    pdef::proto::encode::Item(stream, obj.helmet); /*Item*/ /*4.5*/
    pdef::proto::encode::Item(stream, obj.chestplate); /*Item*/ /*4.5*/
    pdef::proto::encode::Item(stream, obj.leggings); /*Item*/ /*4.5*/
    pdef::proto::encode::Item(stream, obj.boots); /*Item*/ /*4.5*/
    return true;
  }
  bool packet_interact(pdef::Stream &stream, const pdef::proto::packet_interact &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_interact(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::packet_interact::ActionId &action_id = obj.action_id; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action_id); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.target_entity_id); /*0.4*/
    switch (action_id) { /*8.0*/
      case pdef::proto::packet_interact::ActionId::MouseOverEntity: { /*8.5*/
        pdef::proto::encode::vec3f(stream, *obj.position); /*vec3f*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_interact::ActionId::LeaveVehicle: { /*8.5*/
        pdef::proto::encode::vec3f(stream, *obj.position); /*vec3f*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_block_pick_request(pdef::Stream &stream, const pdef::proto::packet_block_pick_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_block_pick_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.add_user_data); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.selected_slot); /*0.4*/
    return true;
  }
  bool packet_entity_pick_request(pdef::Stream &stream, const pdef::proto::packet_entity_pick_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_entity_pick_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.selected_slot); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.with_data); /*0.4*/
    return true;
  }
  bool packet_player_action(pdef::Stream &stream, const pdef::proto::packet_player_action &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_action(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.action); /*7.1*/
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    pdef::proto::encode::BlockCoordinates(stream, obj.result_position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.face); /*0.4*/
    return true;
  }
  bool packet_hurt_armor(pdef::Stream &stream, const pdef::proto::packet_hurt_armor &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_hurt_armor(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.cause); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.damage); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.armor_slots); /*0.4*/
    return true;
  }
  bool packet_set_entity_data(pdef::Stream &stream, const pdef::proto::packet_set_entity_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_entity_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.metadata.size()); /*2.1*/
    for (const auto &v : obj.metadata) { pdef::proto::encode::MetadataDictionary(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.tick); /*0.4*/
    return true;
  }
  bool packet_set_entity_motion(pdef::Stream &stream, const pdef::proto::packet_set_entity_motion &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_entity_motion(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.velocity); /*vec3f*/ /*4.5*/
    return true;
  }
  bool packet_set_entity_link(pdef::Stream &stream, const pdef::proto::packet_set_entity_link &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_entity_link(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::Link(stream, obj.link); /*Link*/ /*4.5*/
    return true;
  }
  bool packet_set_health(pdef::Stream &stream, const pdef::proto::packet_set_health &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_health(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.health); /*0.4*/
    return true;
  }
  bool packet_set_spawn_position(pdef::Stream &stream, const pdef::proto::packet_set_spawn_position &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_spawn_position(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.spawn_type); /*7.1*/
    pdef::proto::encode::BlockCoordinates(stream, obj.player_position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.dimension); /*0.4*/
    pdef::proto::encode::BlockCoordinates(stream, obj.world_position); /*BlockCoordinates*/ /*4.5*/
    return true;
  }
  bool packet_animate(pdef::Stream &stream, const pdef::proto::packet_animate &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_animate(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::packet_animate::ActionId &action_id = obj.action_id; /*0.3*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.action_id); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    switch (action_id) { /*8.0*/
      case pdef::proto::packet_animate::ActionId::RowRight: { /*8.5*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.boat_rowing_time); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_animate::ActionId::RowLeft: { /*8.5*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.boat_rowing_time); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_respawn(pdef::Stream &stream, const pdef::proto::packet_respawn &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_respawn(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.state); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    return true;
  }
  bool packet_container_open(pdef::Stream &stream, const pdef::proto::packet_container_open &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_container_open(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_type); /*7.1*/
    pdef::proto::encode::BlockCoordinates(stream, obj.coordinates); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    return true;
  }
  bool packet_container_close(pdef::Stream &stream, const pdef::proto::packet_container_close &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_container_close(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.server); /*0.4*/
    return true;
  }
  bool packet_player_hotbar(pdef::Stream &stream, const pdef::proto::packet_player_hotbar &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_hotbar(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.selected_slot); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.select_slot); /*0.4*/
    return true;
  }
  bool packet_inventory_content(pdef::Stream &stream, const pdef::proto::packet_inventory_content &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_inventory_content(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.input.size()); /*1.4*/
    for (const auto &v2 : obj.input) { /*3.1*/
      pdef::proto::encode::Item(stream, v2); /*Item*/ /*4.5*/
    }
    return true;
  }
  bool packet_inventory_slot(pdef::Stream &stream, const pdef::proto::packet_inventory_slot &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_inventory_slot(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.slot); /*0.4*/
    pdef::proto::encode::Item(stream, obj.item); /*Item*/ /*4.5*/
    return true;
  }
  bool packet_container_set_data(pdef::Stream &stream, const pdef::proto::packet_container_set_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_container_set_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.property); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.value); /*0.4*/
    return true;
  }
  bool packet_crafting_data(pdef::Stream &stream, const pdef::proto::packet_crafting_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_crafting_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.recipes.size()); /*2.1*/
    for (const auto &v : obj.recipes) { pdef::proto::encode::Recipes(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.potion_type_recipes.size()); /*2.1*/
    for (const auto &v : obj.potion_type_recipes) { pdef::proto::encode::PotionTypeRecipes(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.potion_container_recipes.size()); /*2.1*/
    for (const auto &v : obj.potion_container_recipes) { pdef::proto::encode::PotionContainerChangeRecipes(stream, v); } /*2.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.material_reducers.size()); /*1.4*/
    for (const auto &v2 : obj.material_reducers) { /*3.1*/
      pdef::proto::encode::MaterialReducer(stream, v2); /*MaterialReducer*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeBool, (bool)obj.clear_recipes); /*0.4*/
    return true;
  }
  bool packet_crafting_event(pdef::Stream &stream, const pdef::proto::packet_crafting_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_crafting_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.recipe_type); /*7.1*/
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.recipe_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.input.size()); /*1.4*/
    for (const auto &v2 : obj.input) { /*3.1*/
      pdef::proto::encode::Item(stream, v2); /*Item*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.result.size()); /*1.4*/
    for (const auto &v2 : obj.result) { /*3.1*/
      pdef::proto::encode::Item(stream, v2); /*Item*/ /*4.5*/
    }
    return true;
  }
  bool packet_gui_data_pick_item(pdef::Stream &stream, const pdef::proto::packet_gui_data_pick_item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_gui_data_pick_item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.item_name.length());
    WRITE_OR_BAIL(writeString, obj.item_name); /*item_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.item_effects.length());
    WRITE_OR_BAIL(writeString, obj.item_effects); /*item_effects: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.hotbar_slot); /*0.4*/
    return true;
  }
  bool packet_adventure_settings(pdef::Stream &stream, const pdef::proto::packet_adventure_settings &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_adventure_settings(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    int flags_val = 0;
    if (obj.flags.world_immutable) flags_val |= 1;
    if (obj.flags.no_pvp) flags_val |= 2;
    if (obj.flags.auto_jump) flags_val |= 32;
    if (obj.flags.allow_flight) flags_val |= 64;
    if (obj.flags.no_clip) flags_val |= 128;
    if (obj.flags.world_builder) flags_val |= 256;
    if (obj.flags.flying) flags_val |= 512;
    if (obj.flags.muted) flags_val |= 1024;
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)flags_val) /*flags: bitflags*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.command_permission); /*7.1*/
    int action_permissions_val = 0;
    if (obj.action_permissions.mine) action_permissions_val |= 65537;
    if (obj.action_permissions.doors_and_switches) action_permissions_val |= 65538;
    if (obj.action_permissions.open_containers) action_permissions_val |= 65540;
    if (obj.action_permissions.attack_players) action_permissions_val |= 65544;
    if (obj.action_permissions.attack_mobs) action_permissions_val |= 65552;
    if (obj.action_permissions.operator_) action_permissions_val |= 65568;
    if (obj.action_permissions.teleport) action_permissions_val |= 65664;
    if (obj.action_permissions.build) action_permissions_val |= 65792;
    if (obj.action_permissions.default_) action_permissions_val |= 66048;
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)action_permissions_val) /*action_permissions: bitflags*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.permission_level); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.custom_stored_permissions); /*0.4*/
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.user_id); /*0.4*/
    return true;
  }
  bool packet_block_entity_data(pdef::Stream &stream, const pdef::proto::packet_block_entity_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_block_entity_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_player_input(pdef::Stream &stream, const pdef::proto::packet_player_input &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_input(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatLE, (float)obj.motion_x); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.motion_z); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.jumping); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.sneaking); /*0.4*/
    return true;
  }
  bool packet_level_chunk(pdef::Stream &stream, const pdef::proto::packet_level_chunk &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_level_chunk(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.z); /*0.4*/
    const int &sub_chunk_count = obj.sub_chunk_count; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.sub_chunk_count); /*0.4*/
    if (sub_chunk_count == -2) { /*8.2*/
      WRITE_OR_BAIL(writeUShortLE, (uint16_t)obj.highest_subchunk_count); /*0.4*/
    }
    const bool &cache_enabled = obj.cache_enabled; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.cache_enabled); /*0.4*/
    if (cache_enabled == true) { /*8.1*/
        const pdef::proto::packet_level_chunk::Blobs &v = *obj.blobs; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.hashes.size()); /*1.4*/
        for (const auto &v4 : v.hashes) { /*3.1*/
          WRITE_OR_BAIL(writeULongLE, (uint64_t)v4); /*0.4*/
        }
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.payload.size());
    WRITE_OR_BAIL(writeBuffer, obj.payload); /*payload: buffer*/ /*4.2*/
    return true;
  }
  bool packet_set_commands_enabled(pdef::Stream &stream, const pdef::proto::packet_set_commands_enabled &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_commands_enabled(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.enabled); /*0.4*/
    return true;
  }
  bool packet_set_difficulty(pdef::Stream &stream, const pdef::proto::packet_set_difficulty &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_difficulty(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.difficulty); /*0.4*/
    return true;
  }
  bool packet_change_dimension(pdef::Stream &stream, const pdef::proto::packet_change_dimension &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_change_dimension(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.dimension); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeBool, (bool)obj.respawn); /*0.4*/
    return true;
  }
  bool packet_set_player_game_type(pdef::Stream &stream, const pdef::proto::packet_set_player_game_type &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_player_game_type(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.gamemode); /*7.1*/
    return true;
  }
  bool packet_player_list(pdef::Stream &stream, const pdef::proto::packet_player_list &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_list(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::PlayerRecords(stream, obj.records); /*PlayerRecords*/ /*4.5*/
    return true;
  }
  bool packet_simple_event(pdef::Stream &stream, const pdef::proto::packet_simple_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_simple_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUShortLE, (uint16_t)(uint16_t&)obj.event_type); /*7.1*/
    return true;
  }
  bool packet_event(pdef::Stream &stream, const pdef::proto::packet_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.event_type); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.use_player_id); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.event_data); /*0.4*/
    return true;
  }
  bool packet_spawn_experience_orb(pdef::Stream &stream, const pdef::proto::packet_spawn_experience_orb &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_spawn_experience_orb(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.count); /*0.4*/
    return true;
  }
  bool packet_clientbound_map_item_data(pdef::Stream &stream, const pdef::proto::packet_clientbound_map_item_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_clientbound_map_item_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.map_id); /*0.4*/
    int update_flags_val = 0;
    update_flags_val |= (int)obj.update_flags.void_ << 0;
    update_flags_val |= (int)obj.update_flags.texture << 1;
    update_flags_val |= (int)obj.update_flags.decoration << 2;
    update_flags_val |= (int)obj.update_flags.initialisation << 3;
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)update_flags_val) /*update_flags: bitflags*/ /*4.2*/
    const pdef::proto::packet_clientbound_map_item_data::update_flags_t &update_flags = obj.update_flags; /*0.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.dimension); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.locked); /*0.4*/
    if (update_flags.initialisation == true) { /*8.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.included_in.size()); /*1.4*/
      for (const auto &v3 : obj.included_in) { /*3.1*/
        WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v3); /*0.4*/
      }
    }
    if ((update_flags.initialisation || update_flags.decoration || update_flags.texture) == true) { /*8.2*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.scale); /*0.4*/
    }
    if (update_flags.decoration == true) { /*8.2*/
        const pdef::proto::packet_clientbound_map_item_data::Tracked &v = *obj.tracked; /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.objects.size()); /*1.4*/
        for (const auto &v4 : v.objects) { /*3.1*/
          pdef::proto::encode::TrackedObject(stream, v4); /*TrackedObject*/ /*4.5*/
        }
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.decorations.size()); /*1.4*/
        for (const auto &v4 : v.decorations) { /*3.1*/
          pdef::proto::encode::MapDecoration(stream, v4); /*MapDecoration*/ /*4.5*/
        }
    }
    if (update_flags.texture == true) { /*8.2*/
        const pdef::proto::packet_clientbound_map_item_data::Texture &v = *obj.texture; /*8.5*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)v.width); /*0.4*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)v.height); /*0.4*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)v.x_offset); /*0.4*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)v.y_offset); /*0.4*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.pixels.size()); /*1.4*/
        for (const auto &v4 : v.pixels) { /*3.1*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v4); /*0.4*/
        }
    }
    return true;
  }
  bool packet_map_info_request(pdef::Stream &stream, const pdef::proto::packet_map_info_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_map_info_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.map_id); /*0.4*/
    return true;
  }
  bool packet_request_chunk_radius(pdef::Stream &stream, const pdef::proto::packet_request_chunk_radius &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_request_chunk_radius(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.chunk_radius); /*0.4*/
    return true;
  }
  bool packet_chunk_radius_update(pdef::Stream &stream, const pdef::proto::packet_chunk_radius_update &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_chunk_radius_update(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.chunk_radius); /*0.4*/
    return true;
  }
  bool packet_item_frame_drop_item(pdef::Stream &stream, const pdef::proto::packet_item_frame_drop_item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_item_frame_drop_item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.coordinates); /*BlockCoordinates*/ /*4.5*/
    return true;
  }
  bool packet_game_rules_changed(pdef::Stream &stream, const pdef::proto::packet_game_rules_changed &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_game_rules_changed(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.rules.size()); /*1.4*/
    for (const auto &v2 : obj.rules) { /*3.1*/
      pdef::proto::encode::GameRule(stream, v2); /*GameRule*/ /*4.5*/
    }
    return true;
  }
  bool packet_camera(pdef::Stream &stream, const pdef::proto::packet_camera &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_camera(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.camera_entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.target_player_unique_id); /*0.4*/
    return true;
  }
  bool packet_boss_event(pdef::Stream &stream, const pdef::proto::packet_boss_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_boss_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.boss_entity_id); /*0.4*/
    const pdef::proto::packet_boss_event::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.type); /*7.1*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_boss_event::Type::ShowBar: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title.length());
          WRITE_OR_BAIL(writeString, obj.title); /*title: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.progress); /*0.4*/
          WRITE_OR_BAIL(writeShortLE, (int16_t)obj.screen_darkening); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.color); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.overlay); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::RegisterPlayer: { /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.player_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::UnregisterPlayer: { /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.player_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::Query: { /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.player_id); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::SetBarProgress: { /*8.5*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.progress); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::SetBarTitle: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title.length());
          WRITE_OR_BAIL(writeString, obj.title); /*title: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::UpdateProperties: { /*8.5*/
          WRITE_OR_BAIL(writeShortLE, (int16_t)obj.screen_darkening); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.color); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.overlay); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::Texture: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.color); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.overlay); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_show_credits(pdef::Stream &stream, const pdef::proto::packet_show_credits &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_show_credits(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.status); /*0.4*/
    return true;
  }
  bool packet_available_commands(pdef::Stream &stream, const pdef::proto::packet_available_commands &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_available_commands(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &values_len = obj.values_len; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.values_len); /*0.4*/
    pdef::proto::packet_available_commands::_EnumType _enum_type; if (values_len <= 0xff) { _enum_type = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { _enum_type = pdef::proto::packet_available_commands::_EnumType::Short; } else { _enum_type = pdef::proto::packet_available_commands::_EnumType::Int; } /*_enum_type: enum_size_based_on_values_len*/ /*4.2*/
    for (const auto &v2 : obj.enum_values) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.suffixes.size()); /*1.4*/
    for (const auto &v2 : obj.suffixes) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.enums.size()); /*1.4*/
    for (const auto &v2 : obj.enums) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.name.length());
      WRITE_OR_BAIL(writeString, v2.name); /*name: pstring*/ /*4.2*/
      if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Byte) { /*8.5*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)v2.values_u8); /*0.4*/
      }
      else if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Short) { /*8.5*/
        WRITE_OR_BAIL(writeUShortLE, (uint16_t)v2.values_lu16); /*0.4*/
      }
      else if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Int) { /*8.5*/
        WRITE_OR_BAIL(writeUIntLE, (uint32_t)v2.values_lu32); /*0.4*/
      }
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command_data.size()); /*1.4*/
    for (const auto &v2 : obj.command_data) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.name.length());
      WRITE_OR_BAIL(writeString, v2.name); /*name: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.description.length());
      WRITE_OR_BAIL(writeString, v2.description); /*description: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUShortLE, (uint16_t)v2.flags); /*0.4*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)v2.permission_level); /*0.4*/
      WRITE_OR_BAIL(writeIntLE, (int32_t)v2.alias); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.overloads.size()); /*1.4*/
      for (const auto &v3 : v2.overloads) { /*5.20*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.parameters.size()); /*1.4*/
        for (const auto &v4 : v3.parameters) { /*5.20*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)v4.parameter_name.length());
          WRITE_OR_BAIL(writeString, v4.parameter_name); /*parameter_name: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUShortLE, (uint16_t)(uint16_t&)v4.value_type); /*7.1*/
          WRITE_OR_BAIL(writeUShortLE, (uint16_t)(uint16_t&)v4.enum_type); /*7.1*/
          WRITE_OR_BAIL(writeBool, (bool)v4.optional); /*0.4*/
          uint8_t options_val = 0;
          options_val |= v4.options.unused << 0;
          options_val |= v4.options.collapse_enum << 1;
          options_val |= v4.options.has_semantic_constraint << 2;
          options_val |= v4.options.as_chained_command << 3;
          options_val |= v4.options.unknown2 << 4;
          WRITE_OR_BAIL(writeUByte, options_val); /*options: bitfield*/ /*4.2*/
        }
      }
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.dynamic_enums.size()); /*1.4*/
    for (const auto &v2 : obj.dynamic_enums) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.name.length());
      WRITE_OR_BAIL(writeString, v2.name); /*name: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.values.size()); /*1.4*/
      for (const auto &v3 : v2.values) { /*3.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.length());
        WRITE_OR_BAIL(writeString, v3); /*: pstring*/ /*4.2*/
      }
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.enum_constraints.size()); /*1.4*/
    for (const auto &v2 : obj.enum_constraints) { /*5.20*/
      WRITE_OR_BAIL(writeIntLE, (int32_t)v2.value_index); /*0.4*/
      WRITE_OR_BAIL(writeIntLE, (int32_t)v2.enum_index); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.constraints.size()); /*1.4*/
      for (const auto &v3 : v2.constraints) { /*5.20*/
        WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)v3.constraint); /*7.1*/
      }
    }
    return true;
  }
  bool packet_command_request(pdef::Stream &stream, const pdef::proto::packet_command_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_command_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command.length());
    WRITE_OR_BAIL(writeString, obj.command); /*command: pstring*/ /*4.2*/
    pdef::proto::encode::CommandOrigin(stream, obj.origin); /*CommandOrigin*/ /*4.5*/
    WRITE_OR_BAIL(writeBool, (bool)obj.internal); /*0.4*/
    return true;
  }
  bool packet_command_block_update(pdef::Stream &stream, const pdef::proto::packet_command_block_update &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_command_block_update(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const bool &is_block = obj.is_block; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_block); /*0.4*/
    if (is_block == true) { /*8.1*/
        pdef::proto::encode::BlockCoordinates(stream, *obj.position); /*BlockCoordinates*/ /*4.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.mode); /*7.1*/
        WRITE_OR_BAIL(writeBool, (bool)obj.needs_redstone); /*0.4*/
        WRITE_OR_BAIL(writeBool, (bool)obj.conditional); /*0.4*/
    }
    else if (is_block == false) { /*8.1*/
        WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.minecart_entity_runtime_id); /*0.4*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command.length());
    WRITE_OR_BAIL(writeString, obj.command); /*command: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.last_output.length());
    WRITE_OR_BAIL(writeString, obj.last_output); /*last_output: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.should_track_output); /*0.4*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.tick_delay); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.execute_on_first_tick); /*0.4*/
    return true;
  }
  bool packet_command_output(pdef::Stream &stream, const pdef::proto::packet_command_output &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_command_output(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::CommandOrigin(stream, obj.origin); /*CommandOrigin*/ /*4.5*/
    const pdef::proto::packet_command_output::OutputType &output_type = obj.output_type; /*0.3*/
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.output_type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.success_count); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.output.size()); /*1.4*/
    for (const auto &v2 : obj.output) { /*5.20*/
      WRITE_OR_BAIL(writeBool, (bool)v2.success); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.message_id.length());
      WRITE_OR_BAIL(writeString, v2.message_id); /*message_id: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.parameters.size()); /*1.4*/
      for (const auto &v3 : v2.parameters) { /*3.1*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v3.length());
        WRITE_OR_BAIL(writeString, v3); /*: pstring*/ /*4.2*/
      }
    }
    switch (output_type) { /*8.0*/
      case pdef::proto::packet_command_output::OutputType::DataSet: { /*8.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data_set.length());
        WRITE_OR_BAIL(writeString, obj.data_set); /*data_set: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_update_trade(pdef::Stream &stream, const pdef::proto::packet_update_trade &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_trade(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.size); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.trade_tier); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.villager_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.display_name.length());
    WRITE_OR_BAIL(writeString, obj.display_name); /*display_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.new_trading_ui); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.economic_trades); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.offers); /*0.4*/
    return true;
  }
  bool packet_update_equipment(pdef::Stream &stream, const pdef::proto::packet_update_equipment &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_equipment(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_id); /*7.1*/
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.window_type); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.size); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_id); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.inventory); /*0.4*/
    return true;
  }
  bool packet_resource_pack_data_info(pdef::Stream &stream, const pdef::proto::packet_resource_pack_data_info &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_resource_pack_data_info(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.pack_id.length());
    WRITE_OR_BAIL(writeString, obj.pack_id); /*pack_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.max_chunk_size); /*0.4*/
    WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.chunk_count); /*0.4*/
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.size); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.hash.size());
    WRITE_OR_BAIL(writeBuffer, obj.hash); /*hash: buffer*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_premium); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.pack_type); /*7.1*/
    return true;
  }
  bool packet_resource_pack_chunk_data(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_resource_pack_chunk_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.pack_id.length());
    WRITE_OR_BAIL(writeString, obj.pack_id); /*pack_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.chunk_index); /*0.4*/
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.progress); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.payload.size());
    WRITE_OR_BAIL(writeBuffer, obj.payload); /*payload: buffer*/ /*4.2*/
    return true;
  }
  bool packet_resource_pack_chunk_request(pdef::Stream &stream, const pdef::proto::packet_resource_pack_chunk_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_resource_pack_chunk_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.pack_id.length());
    WRITE_OR_BAIL(writeString, obj.pack_id); /*pack_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.chunk_index); /*0.4*/
    return true;
  }
  bool packet_transfer(pdef::Stream &stream, const pdef::proto::packet_transfer &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_transfer(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.server_address.length());
    WRITE_OR_BAIL(writeString, obj.server_address); /*server_address: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUShortLE, (uint16_t)obj.port); /*0.4*/
    return true;
  }
  bool packet_play_sound(pdef::Stream &stream, const pdef::proto::packet_play_sound &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_play_sound(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    pdef::proto::encode::BlockCoordinates(stream, obj.coordinates); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.volume); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.pitch); /*0.4*/
    return true;
  }
  bool packet_stop_sound(pdef::Stream &stream, const pdef::proto::packet_stop_sound &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_stop_sound(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.stop_all); /*0.4*/
    return true;
  }
  bool packet_set_title(pdef::Stream &stream, const pdef::proto::packet_set_title &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_title(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
    WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.fade_in_time); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.stay_time); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.fade_out_time); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.xuid.length());
    WRITE_OR_BAIL(writeString, obj.xuid); /*xuid: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.platform_online_id.length());
    WRITE_OR_BAIL(writeString, obj.platform_online_id); /*platform_online_id: pstring*/ /*4.2*/
    return true;
  }
  bool packet_add_behavior_tree(pdef::Stream &stream, const pdef::proto::packet_add_behavior_tree &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_add_behavior_tree(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.behaviortree.length());
    WRITE_OR_BAIL(writeString, obj.behaviortree); /*behaviortree: pstring*/ /*4.2*/
    return true;
  }
  bool packet_structure_block_update(pdef::Stream &stream, const pdef::proto::packet_structure_block_update &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_structure_block_update(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.structure_name.length());
    WRITE_OR_BAIL(writeString, obj.structure_name); /*structure_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data_field.length());
    WRITE_OR_BAIL(writeString, obj.data_field); /*data_field: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.include_players); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.show_bounding_box); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.structure_block_type); /*0.4*/
    pdef::proto::encode::StructureBlockSettings(stream, obj.settings); /*StructureBlockSettings*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.redstone_save_mode); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.should_trigger); /*0.4*/
    return true;
  }
  bool packet_show_store_offer(pdef::Stream &stream, const pdef::proto::packet_show_store_offer &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_show_store_offer(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.offer_id.length());
    WRITE_OR_BAIL(writeString, obj.offer_id); /*offer_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.show_all); /*0.4*/
    return true;
  }
  bool packet_purchase_receipt(pdef::Stream &stream, const pdef::proto::packet_purchase_receipt &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_purchase_receipt(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.receipts.size()); /*1.4*/
    for (const auto &v2 : obj.receipts) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    return true;
  }
  bool packet_player_skin(pdef::Stream &stream, const pdef::proto::packet_player_skin &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_skin(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongBE, (uint64_t)obj.uuid); /*0.4*/
    pdef::proto::encode::Skin(stream, obj.skin); /*Skin*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.skin_name.length());
    WRITE_OR_BAIL(writeString, obj.skin_name); /*skin_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.old_skin_name.length());
    WRITE_OR_BAIL(writeString, obj.old_skin_name); /*old_skin_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_verified); /*0.4*/
    return true;
  }
  bool packet_sub_client_login(pdef::Stream &stream, const pdef::proto::packet_sub_client_login &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_sub_client_login(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.tokens); /*0.4*/
    return true;
  }
  bool packet_initiate_web_socket_connection(pdef::Stream &stream, const pdef::proto::packet_initiate_web_socket_connection &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_initiate_web_socket_connection(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.server.length());
    WRITE_OR_BAIL(writeString, obj.server); /*server: pstring*/ /*4.2*/
    return true;
  }
  bool packet_set_last_hurt_by(pdef::Stream &stream, const pdef::proto::packet_set_last_hurt_by &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_last_hurt_by(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entity_type); /*0.4*/
    return true;
  }
  bool packet_book_edit(pdef::Stream &stream, const pdef::proto::packet_book_edit &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_book_edit(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::packet_book_edit::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.type); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.slot); /*0.4*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_book_edit::Type::ReplacePage: { /*8.5*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)obj.page_number); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
          WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.photo_name.length());
          WRITE_OR_BAIL(writeString, obj.photo_name); /*photo_name: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::AddPage: { /*8.5*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)obj.page_number); /*0.4*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
          WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.photo_name.length());
          WRITE_OR_BAIL(writeString, obj.photo_name); /*photo_name: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::DeletePage: { /*8.5*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)obj.page_number); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::SwapPages: { /*8.5*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)obj.page1); /*0.4*/
          WRITE_OR_BAIL(writeUByte, (uint8_t)obj.page2); /*0.4*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::Sign: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title.length());
          WRITE_OR_BAIL(writeString, obj.title); /*title: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.author.length());
          WRITE_OR_BAIL(writeString, obj.author); /*author: pstring*/ /*4.2*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.xuid.length());
          WRITE_OR_BAIL(writeString, obj.xuid); /*xuid: pstring*/ /*4.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_npc_request(pdef::Stream &stream, const pdef::proto::packet_npc_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_npc_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.request_type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command.length());
    WRITE_OR_BAIL(writeString, obj.command); /*command: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action_type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.scene_name.length());
    WRITE_OR_BAIL(writeString, obj.scene_name); /*scene_name: pstring*/ /*4.2*/
    return true;
  }
  bool packet_photo_transfer(pdef::Stream &stream, const pdef::proto::packet_photo_transfer &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_photo_transfer(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.image_name.length());
    WRITE_OR_BAIL(writeString, obj.image_name); /*image_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.image_data.length());
    WRITE_OR_BAIL(writeString, obj.image_data); /*image_data: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.book_id.length());
    WRITE_OR_BAIL(writeString, obj.book_id); /*book_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.photo_type); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.source_type); /*0.4*/
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.owner_entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.new_photo_name.length());
    WRITE_OR_BAIL(writeString, obj.new_photo_name); /*new_photo_name: pstring*/ /*4.2*/
    return true;
  }
  bool packet_modal_form_request(pdef::Stream &stream, const pdef::proto::packet_modal_form_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_modal_form_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.form_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data.length());
    WRITE_OR_BAIL(writeString, obj.data); /*data: pstring*/ /*4.2*/
    return true;
  }
  bool packet_modal_form_response(pdef::Stream &stream, const pdef::proto::packet_modal_form_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_modal_form_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.form_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data.length());
    WRITE_OR_BAIL(writeString, obj.data); /*data: pstring*/ /*4.2*/
    return true;
  }
  bool packet_server_settings_request(pdef::Stream &stream, const pdef::proto::packet_server_settings_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_server_settings_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    return true;
  }
  bool packet_server_settings_response(pdef::Stream &stream, const pdef::proto::packet_server_settings_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_server_settings_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.form_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data.length());
    WRITE_OR_BAIL(writeString, obj.data); /*data: pstring*/ /*4.2*/
    return true;
  }
  bool packet_show_profile(pdef::Stream &stream, const pdef::proto::packet_show_profile &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_show_profile(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.xuid.length());
    WRITE_OR_BAIL(writeString, obj.xuid); /*xuid: pstring*/ /*4.2*/
    return true;
  }
  bool packet_set_default_game_type(pdef::Stream &stream, const pdef::proto::packet_set_default_game_type &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_default_game_type(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.gamemode); /*7.1*/
    return true;
  }
  bool packet_remove_objective(pdef::Stream &stream, const pdef::proto::packet_remove_objective &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_remove_objective(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.objective_name.length());
    WRITE_OR_BAIL(writeString, obj.objective_name); /*objective_name: pstring*/ /*4.2*/
    return true;
  }
  bool packet_set_display_objective(pdef::Stream &stream, const pdef::proto::packet_set_display_objective &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_display_objective(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.display_slot.length());
    WRITE_OR_BAIL(writeString, obj.display_slot); /*display_slot: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.objective_name.length());
    WRITE_OR_BAIL(writeString, obj.objective_name); /*objective_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.display_name.length());
    WRITE_OR_BAIL(writeString, obj.display_name); /*display_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.criteria_name.length());
    WRITE_OR_BAIL(writeString, obj.criteria_name); /*criteria_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.sort_order); /*0.4*/
    return true;
  }
  bool packet_set_score(pdef::Stream &stream, const pdef::proto::packet_set_score &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_score(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::packet_set_score::Action &action = obj.action; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entries.size()); /*1.4*/
    for (const auto &v2 : obj.entries) { /*5.20*/
      WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v2.scoreboard_id); /*0.4*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.objective_name.length());
      WRITE_OR_BAIL(writeString, v2.objective_name); /*objective_name: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeIntLE, (int32_t)v2.score); /*0.4*/
      switch (action) { /*8.0*/
        case pdef::proto::packet_set_score::Action::Change: { /*8.5*/
            const pdef::proto::packet_set_score::Entries::EntryType &entry_type = v2.entry_type; /*0.3*/
            WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)v2.entry_type); /*7.1*/
            switch (entry_type) { /*8.0*/
              case pdef::proto::packet_set_score::Entries::EntryType::Player: { /*8.5*/
                WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v2.entity_unique_id); /*0.4*/
                break;
              } /*8.7*/
              case pdef::proto::packet_set_score::Entries::EntryType::Entity: { /*8.5*/
                WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v2.entity_unique_id); /*0.4*/
                break;
              } /*8.7*/
              default: break; /*avoid unhandled case warning*/
            } /*8.8*/
            switch (entry_type) { /*8.0*/
              case pdef::proto::packet_set_score::Entries::EntryType::FakePlayer: { /*8.5*/
                WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.custom_name.length());
                WRITE_OR_BAIL(writeString, v2.custom_name); /*custom_name: pstring*/ /*4.2*/
                break;
              } /*8.7*/
              default: break; /*avoid unhandled case warning*/
            } /*8.8*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    return true;
  }
  bool packet_lab_table(pdef::Stream &stream, const pdef::proto::packet_lab_table &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_lab_table(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action_type); /*7.1*/
    pdef::proto::encode::vec3i(stream, obj.position); /*vec3i*/ /*4.5*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.reaction_type); /*0.4*/
    return true;
  }
  bool packet_update_block_synced(pdef::Stream &stream, const pdef::proto::packet_update_block_synced &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_block_synced(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.block_runtime_id); /*0.4*/
    int flags_val = 0;
    if (obj.flags.neighbors) flags_val |= 1;
    if (obj.flags.network) flags_val |= 2;
    if (obj.flags.no_graphic) flags_val |= 4;
    if (obj.flags.unused) flags_val |= 8;
    if (obj.flags.priority) flags_val |= 16;
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)flags_val) /*flags: bitflags*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.layer); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.transition_type); /*7.1*/
    return true;
  }
  bool packet_move_entity_delta(pdef::Stream &stream, const pdef::proto::packet_move_entity_delta &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_move_entity_delta(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    uint16_t flags_val = 0;
    if (obj.flags.has_x) flags_val |= 1;
    if (obj.flags.has_y) flags_val |= 2;
    if (obj.flags.has_z) flags_val |= 4;
    if (obj.flags.has_rot_x) flags_val |= 8;
    if (obj.flags.has_rot_y) flags_val |= 16;
    if (obj.flags.has_rot_z) flags_val |= 32;
    if (obj.flags.on_ground) flags_val |= 64;
    if (obj.flags.teleport) flags_val |= 128;
    if (obj.flags.force_move) flags_val |= 256;
    WRITE_OR_BAIL(writeUShortLE, (uint16_t)flags_val) /*flags: bitflags*/ /*4.2*/
    const pdef::proto::packet_move_entity_delta::flags_t &flags = obj.flags; /*0.1*/
    if (flags.has_x == true) { /*8.2*/
      WRITE_OR_BAIL(writeFloatLE, (float)obj.x); /*0.4*/
    }
    if (flags.has_y == true) { /*8.2*/
      WRITE_OR_BAIL(writeFloatLE, (float)obj.y); /*0.4*/
    }
    if (flags.has_z == true) { /*8.2*/
      WRITE_OR_BAIL(writeFloatLE, (float)obj.z); /*0.4*/
    }
    if (flags.has_rot_x == true) { /*8.2*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.rot_x); /*0.4*/
    }
    if (flags.has_rot_y == true) { /*8.2*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.rot_y); /*0.4*/
    }
    if (flags.has_rot_z == true) { /*8.2*/
      WRITE_OR_BAIL(writeUByte, (uint8_t)obj.rot_z); /*0.4*/
    }
    return true;
  }
  bool packet_set_scoreboard_identity(pdef::Stream &stream, const pdef::proto::packet_set_scoreboard_identity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_scoreboard_identity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::packet_set_scoreboard_identity::Action &action = obj.action; /*0.3*/
    WRITE_OR_BAIL(writeByte, (int8_t)(int8_t&)obj.action); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entries.size()); /*1.4*/
    for (const auto &v2 : obj.entries) { /*5.20*/
      WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v2.scoreboard_id); /*0.4*/
      switch (action) { /*8.0*/
        case pdef::proto::packet_set_scoreboard_identity::Action::RegisterIdentity: { /*8.5*/
          WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)v2.entity_unique_id); /*0.4*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    return true;
  }
  bool packet_set_local_player_as_initialized(pdef::Stream &stream, const pdef::proto::packet_set_local_player_as_initialized &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_set_local_player_as_initialized(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_entity_id); /*0.4*/
    return true;
  }
  bool packet_update_soft_enum(pdef::Stream &stream, const pdef::proto::packet_update_soft_enum &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_soft_enum(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.enum_type.length());
    WRITE_OR_BAIL(writeString, obj.enum_type); /*enum_type: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.options.size()); /*1.4*/
    for (const auto &v2 : obj.options) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action_type); /*7.1*/
    return true;
  }
  bool packet_network_stack_latency(pdef::Stream &stream, const pdef::proto::packet_network_stack_latency &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_network_stack_latency(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.timestamp); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.needs_response); /*0.4*/
    return true;
  }
  bool packet_script_custom_event(pdef::Stream &stream, const pdef::proto::packet_script_custom_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_script_custom_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.event_name.length());
    WRITE_OR_BAIL(writeString, obj.event_name); /*event_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.event_data.length());
    WRITE_OR_BAIL(writeString, obj.event_data); /*event_data: pstring*/ /*4.2*/
    return true;
  }
  bool packet_spawn_particle_effect(pdef::Stream &stream, const pdef::proto::packet_spawn_particle_effect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_spawn_particle_effect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.dimension); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_id); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.particle_name.length());
    WRITE_OR_BAIL(writeString, obj.particle_name); /*particle_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.molang_variables.size());
    WRITE_OR_BAIL(writeBuffer, obj.molang_variables); /*molang_variables: buffer*/ /*4.2*/
    return true;
  }
  bool packet_available_entity_identifiers(pdef::Stream &stream, const pdef::proto::packet_available_entity_identifiers &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_available_entity_identifiers(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_level_sound_event_v2(pdef::Stream &stream, const pdef::proto::packet_level_sound_event_v2 &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_level_sound_event_v2(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.sound_id); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.block_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entity_type.length());
    WRITE_OR_BAIL(writeString, obj.entity_type); /*entity_type: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_baby_mob); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_global); /*0.4*/
    return true;
  }
  bool packet_network_chunk_publisher_update(pdef::Stream &stream, const pdef::proto::packet_network_chunk_publisher_update &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_network_chunk_publisher_update(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::BlockCoordinates(stream, obj.coordinates); /*BlockCoordinates*/ /*4.5*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.radius); /*0.4*/
    return true;
  }
  bool packet_biome_definition_list(pdef::Stream &stream, const pdef::proto::packet_biome_definition_list &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_biome_definition_list(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_level_sound_event(pdef::Stream &stream, const pdef::proto::packet_level_sound_event &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_level_sound_event(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.sound_id); /*7.1*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.extra_data); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entity_type.length());
    WRITE_OR_BAIL(writeString, obj.entity_type); /*entity_type: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_baby_mob); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.is_global); /*0.4*/
    return true;
  }
  bool packet_level_event_generic(pdef::Stream &stream, const pdef::proto::packet_level_event_generic &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_level_event_generic(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.event_id); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_lectern_update(pdef::Stream &stream, const pdef::proto::packet_lectern_update &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_lectern_update(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.page); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.page_count); /*0.4*/
    pdef::proto::encode::vec3i(stream, obj.position); /*vec3i*/ /*4.5*/
    WRITE_OR_BAIL(writeBool, (bool)obj.drop_book); /*0.4*/
    return true;
  }
  bool packet_video_stream_connect(pdef::Stream &stream, const pdef::proto::packet_video_stream_connect &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_video_stream_connect(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.server_uri.length());
    WRITE_OR_BAIL(writeString, obj.server_uri); /*server_uri: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.frame_send_frequency); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action); /*7.1*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.resolution_x); /*0.4*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.resolution_y); /*0.4*/
    return true;
  }
  bool packet_add_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_add_ecs_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_add_ecs_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.network_id); /*0.4*/
    return true;
  }
  bool packet_remove_ecs_entity(pdef::Stream &stream, const pdef::proto::packet_remove_ecs_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_remove_ecs_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.network_id); /*0.4*/
    return true;
  }
  bool packet_client_cache_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_status &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_client_cache_status(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.enabled); /*0.4*/
    return true;
  }
  bool packet_on_screen_texture_animation(pdef::Stream &stream, const pdef::proto::packet_on_screen_texture_animation &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_on_screen_texture_animation(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.animation_type); /*0.4*/
    return true;
  }
  bool packet_map_create_locked_copy(pdef::Stream &stream, const pdef::proto::packet_map_create_locked_copy &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_map_create_locked_copy(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.original_map_id); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.new_map_id); /*0.4*/
    return true;
  }
  bool packet_structure_template_data_export_request(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_structure_template_data_export_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    pdef::proto::encode::StructureBlockSettings(stream, obj.settings); /*StructureBlockSettings*/ /*4.5*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.request_type); /*7.1*/
    return true;
  }
  bool packet_structure_template_data_export_response(pdef::Stream &stream, const pdef::proto::packet_structure_template_data_export_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_structure_template_data_export_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.name.length());
    WRITE_OR_BAIL(writeString, obj.name); /*name: pstring*/ /*4.2*/
    const bool &success = obj.success; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.success); /*0.4*/
    if (success == true) { /*8.1*/
      WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.response_type); /*7.1*/
    return true;
  }
  bool packet_update_block_properties(pdef::Stream &stream, const pdef::proto::packet_update_block_properties &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_block_properties(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_client_cache_blob_status(pdef::Stream &stream, const pdef::proto::packet_client_cache_blob_status &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_client_cache_blob_status(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const int &misses = obj.misses; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.misses); /*0.4*/
    const int &haves = obj.haves; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.haves); /*0.4*/
    for (const auto &v2 : obj.missing) { /*3.1*/
      WRITE_OR_BAIL(writeULongLE, (uint64_t)v2); /*0.4*/
    }
    for (const auto &v2 : obj.have) { /*3.1*/
      WRITE_OR_BAIL(writeULongLE, (uint64_t)v2); /*0.4*/
    }
    return true;
  }
  bool packet_client_cache_miss_response(pdef::Stream &stream, const pdef::proto::packet_client_cache_miss_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_client_cache_miss_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blobs.size()); /*1.4*/
    for (const auto &v2 : obj.blobs) { /*3.1*/
      pdef::proto::encode::Blob(stream, v2); /*Blob*/ /*4.5*/
    }
    return true;
  }
  bool packet_education_settings(pdef::Stream &stream, const pdef::proto::packet_education_settings &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_education_settings(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.CodeBuilderDefaultURI.length());
    WRITE_OR_BAIL(writeString, obj.CodeBuilderDefaultURI); /*CodeBuilderDefaultURI: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.CodeBuilderTitle.length());
    WRITE_OR_BAIL(writeString, obj.CodeBuilderTitle); /*CodeBuilderTitle: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.CanResizeCodeBuilder); /*0.4*/
    WRITE_OR_BAIL(writeBool, (bool)obj.disable_legacy_title_bar); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.post_process_filter.length());
    WRITE_OR_BAIL(writeString, obj.post_process_filter); /*post_process_filter: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.screenshot_border_path.length());
    WRITE_OR_BAIL(writeString, obj.screenshot_border_path); /*screenshot_border_path: pstring*/ /*4.2*/
    const bool &has_agent_capabilities = obj.has_agent_capabilities; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_agent_capabilities); /*0.4*/
    if (has_agent_capabilities == true) { /*8.1*/
        const pdef::proto::packet_education_settings::AgentCapabilities &v = *obj.agent_capabilities; /*8.5*/
        WRITE_OR_BAIL(writeBool, (bool)v.has); /*0.4*/
        WRITE_OR_BAIL(writeBool, (bool)v.can_modify_blocks); /*0.4*/
    }
    const bool &HasOverrideURI = obj.HasOverrideURI; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.HasOverrideURI); /*0.4*/
    if (HasOverrideURI == true) { /*8.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.OverrideURI.length());
      WRITE_OR_BAIL(writeString, obj.OverrideURI); /*OverrideURI: pstring*/ /*4.2*/
    }
    WRITE_OR_BAIL(writeBool, (bool)obj.HasQuiz); /*0.4*/
    const bool &has_external_link_settings = obj.has_external_link_settings; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.has_external_link_settings); /*0.4*/
    if (has_external_link_settings == true) { /*8.1*/
        const pdef::proto::packet_education_settings::ExternalLinkSettings &v = *obj.external_link_settings; /*8.5*/
        WRITE_OR_BAIL(writeBool, (bool)v.has); /*0.4*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.url.length());
        WRITE_OR_BAIL(writeString, v.url); /*url: pstring*/ /*4.2*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.display_name.length());
        WRITE_OR_BAIL(writeString, v.display_name); /*display_name: pstring*/ /*4.2*/
    }
    return true;
  }
  bool packet_emote(pdef::Stream &stream, const pdef::proto::packet_emote &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_emote(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.emote_id.length());
    WRITE_OR_BAIL(writeString, obj.emote_id); /*emote_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.flags); /*0.4*/
    return true;
  }
  bool packet_multiplayer_settings(pdef::Stream &stream, const pdef::proto::packet_multiplayer_settings &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_multiplayer_settings(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.action_type); /*7.1*/
    return true;
  }
  bool packet_settings_command(pdef::Stream &stream, const pdef::proto::packet_settings_command &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_settings_command(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.command_line.length());
    WRITE_OR_BAIL(writeString, obj.command_line); /*command_line: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.suppress_output); /*0.4*/
    return true;
  }
  bool packet_anvil_damage(pdef::Stream &stream, const pdef::proto::packet_anvil_damage &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_anvil_damage(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.damage); /*0.4*/
    pdef::proto::encode::BlockCoordinates(stream, obj.position); /*BlockCoordinates*/ /*4.5*/
    return true;
  }
  bool packet_completed_using_item(pdef::Stream &stream, const pdef::proto::packet_completed_using_item &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_completed_using_item(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeShortLE, (int16_t)obj.used_item_id); /*0.4*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)(int32_t&)obj.use_method); /*7.1*/
    return true;
  }
  bool packet_network_settings(pdef::Stream &stream, const pdef::proto::packet_network_settings &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_network_settings(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUShortBE, (uint16_t)obj.compression_threshold); /*0.4*/
    return true;
  }
  bool packet_player_auth_input(pdef::Stream &stream, const pdef::proto::packet_player_auth_input &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_auth_input(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatLE, (float)obj.pitch); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.yaw); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    pdef::proto::encode::vec2f(stream, obj.move_vector); /*vec2f*/ /*4.5*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.head_yaw); /*0.4*/
    int64_t input_data_val = 0;
    input_data_val |= (int64_t)obj.input_data.ascend << 0;
    input_data_val |= (int64_t)obj.input_data.descend << 1;
    input_data_val |= (int64_t)obj.input_data.north_jump << 2;
    input_data_val |= (int64_t)obj.input_data.jump_down << 3;
    input_data_val |= (int64_t)obj.input_data.sprint_down << 4;
    input_data_val |= (int64_t)obj.input_data.change_height << 5;
    input_data_val |= (int64_t)obj.input_data.jumping << 6;
    input_data_val |= (int64_t)obj.input_data.auto_jumping_in_water << 7;
    input_data_val |= (int64_t)obj.input_data.sneaking << 8;
    input_data_val |= (int64_t)obj.input_data.sneak_down << 9;
    input_data_val |= (int64_t)obj.input_data.up << 10;
    input_data_val |= (int64_t)obj.input_data.down << 11;
    input_data_val |= (int64_t)obj.input_data.left << 12;
    input_data_val |= (int64_t)obj.input_data.right << 13;
    input_data_val |= (int64_t)obj.input_data.up_left << 14;
    input_data_val |= (int64_t)obj.input_data.up_right << 15;
    input_data_val |= (int64_t)obj.input_data.want_up << 16;
    input_data_val |= (int64_t)obj.input_data.want_down << 17;
    input_data_val |= (int64_t)obj.input_data.want_down_slow << 18;
    input_data_val |= (int64_t)obj.input_data.want_up_slow << 19;
    input_data_val |= (int64_t)obj.input_data.sprinting << 20;
    input_data_val |= (int64_t)obj.input_data.ascend_block << 21;
    input_data_val |= (int64_t)obj.input_data.descend_block << 22;
    input_data_val |= (int64_t)obj.input_data.sneak_toggle_down << 23;
    input_data_val |= (int64_t)obj.input_data.persist_sneak << 24;
    input_data_val |= (int64_t)obj.input_data.start_sprinting << 25;
    input_data_val |= (int64_t)obj.input_data.stop_sprinting << 26;
    input_data_val |= (int64_t)obj.input_data.start_sneaking << 27;
    input_data_val |= (int64_t)obj.input_data.stop_sneaking << 28;
    input_data_val |= (int64_t)obj.input_data.start_swimming << 29;
    input_data_val |= (int64_t)obj.input_data.stop_swimming << 30;
    input_data_val |= (int64_t)obj.input_data.start_jumping << 31;
    input_data_val |= (int64_t)obj.input_data.start_gliding << 32;
    input_data_val |= (int64_t)obj.input_data.stop_gliding << 33;
    input_data_val |= (int64_t)obj.input_data.item_interact << 34;
    input_data_val |= (int64_t)obj.input_data.block_action << 35;
    input_data_val |= (int64_t)obj.input_data.item_stack_request << 36;
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)input_data_val) /*input_data: bitflags*/ /*4.2*/
    const pdef::proto::packet_player_auth_input::input_data_t &input_data = obj.input_data; /*0.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.input_mode); /*7.1*/
    const pdef::proto::packet_player_auth_input::PlayMode &play_mode = obj.play_mode; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.play_mode); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.interaction_model); /*7.1*/
    switch (play_mode) { /*8.0*/
      case pdef::proto::packet_player_auth_input::PlayMode::Reality: { /*8.5*/
        pdef::proto::encode::vec3f(stream, *obj.gaze_direction); /*vec3f*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.tick); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.delta); /*vec3f*/ /*4.5*/
    if (input_data.item_interact == true) { /*8.2*/
        const pdef::proto::packet_player_auth_input::Transaction &v = *obj.transaction; /*8.5*/
        pdef::proto::encode::TransactionLegacy(stream, v.legacy); /*TransactionLegacy*/ /*4.5*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)v.actions.size()); /*2.1*/
        for (const auto &v : v.actions) { pdef::proto::encode::TransactionActions(stream, v); } /*2.2*/
        pdef::proto::encode::TransactionUseItem(stream, v.data); /*TransactionUseItem*/ /*4.5*/
    }
    if (input_data.item_stack_request == true) { /*8.2*/
      pdef::proto::encode::ItemStackRequest(stream, *obj.item_stack_request); /*ItemStackRequest*/ /*4.5*/
    }
    if (input_data.block_action == true) { /*8.2*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.block_action.size()); /*1.4*/
      for (const auto &v3 : obj.block_action) { /*5.20*/
        const pdef::proto::packet_player_auth_input::BlockAction::Action &action = v3.action; /*0.3*/
        WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)v3.action); /*7.1*/
        if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::StartBreak) { /*8.5*/
            pdef::proto::encode::vec3i(stream, *v3.position); /*vec3i*/ /*4.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v3.face); /*0.4*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::AbortBreak) { /*8.5*/
            pdef::proto::encode::vec3i(stream, *v3.position); /*vec3i*/ /*4.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v3.face); /*0.4*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::CrackBreak) { /*8.5*/
            pdef::proto::encode::vec3i(stream, *v3.position); /*vec3i*/ /*4.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v3.face); /*0.4*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::PredictBreak) { /*8.5*/
            pdef::proto::encode::vec3i(stream, *v3.position); /*vec3i*/ /*4.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v3.face); /*0.4*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::ContinueBreak) { /*8.5*/
            pdef::proto::encode::vec3i(stream, *v3.position); /*vec3i*/ /*4.5*/
            WRITE_OR_BAIL(writeZigZagVarInt, (int)v3.face); /*0.4*/
        }
      }
    }
    return true;
  }
  bool packet_creative_content(pdef::Stream &stream, const pdef::proto::packet_creative_content &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_creative_content(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.items.size()); /*1.4*/
    for (const auto &v2 : obj.items) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.entry_id); /*0.4*/
      pdef::proto::encode::ItemLegacy(stream, v2.item); /*ItemLegacy*/ /*4.5*/
    }
    return true;
  }
  bool packet_player_enchant_options(pdef::Stream &stream, const pdef::proto::packet_player_enchant_options &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_enchant_options(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.options.size()); /*1.4*/
    for (const auto &v2 : obj.options) { /*3.1*/
      pdef::proto::encode::EnchantOption(stream, v2); /*EnchantOption*/ /*4.5*/
    }
    return true;
  }
  bool packet_item_stack_request(pdef::Stream &stream, const pdef::proto::packet_item_stack_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_item_stack_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.requests.size()); /*1.4*/
    for (const auto &v2 : obj.requests) { /*3.1*/
      pdef::proto::encode::ItemStackRequest(stream, v2); /*ItemStackRequest*/ /*4.5*/
    }
    return true;
  }
  bool packet_item_stack_response(pdef::Stream &stream, const pdef::proto::packet_item_stack_response &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_item_stack_response(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.responses.size()); /*2.1*/
    for (const auto &v : obj.responses) { pdef::proto::encode::ItemStackResponses(stream, v); } /*2.2*/
    return true;
  }
  bool packet_player_armor_damage(pdef::Stream &stream, const pdef::proto::packet_player_armor_damage &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_armor_damage(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    uint8_t type_val = 0;
    if (obj.type.head) type_val |= 1;
    if (obj.type.chest) type_val |= 2;
    if (obj.type.legs) type_val |= 4;
    if (obj.type.feet) type_val |= 8;
    WRITE_OR_BAIL(writeUByte, (uint8_t)type_val) /*type: bitflags*/ /*4.2*/
    const pdef::proto::packet_player_armor_damage::type_t &type = obj.type; /*0.1*/
    if (type.head == true) { /*8.2*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.helmet_damage); /*0.4*/
    }
    if (type.chest == true) { /*8.2*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.chestplate_damage); /*0.4*/
    }
    if (type.legs == true) { /*8.2*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.leggings_damage); /*0.4*/
    }
    if (type.feet == true) { /*8.2*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.boots_damage); /*0.4*/
    }
    return true;
  }
  bool packet_update_player_game_type(pdef::Stream &stream, const pdef::proto::packet_update_player_game_type &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_player_game_type(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.gamemode); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.player_unique_id); /*0.4*/
    return true;
  }
  bool packet_emote_list(pdef::Stream &stream, const pdef::proto::packet_emote_list &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_emote_list(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.player_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.emote_pieces.size()); /*1.4*/
    for (const auto &v2 : obj.emote_pieces) { /*3.1*/
      WRITE_OR_BAIL(writeULongBE, (uint64_t)v2); /*0.4*/
    }
    return true;
  }
  bool packet_position_tracking_db_request(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_position_tracking_db_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.tracking_id); /*0.4*/
    return true;
  }
  bool packet_position_tracking_db_broadcast(pdef::Stream &stream, const pdef::proto::packet_position_tracking_db_broadcast &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_position_tracking_db_broadcast(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.broadcast_action); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.tracking_id); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_packet_violation_warning(pdef::Stream &stream, const pdef::proto::packet_packet_violation_warning &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_packet_violation_warning(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.violation_type); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.severity); /*7.1*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.packet_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.reason.length());
    WRITE_OR_BAIL(writeString, obj.reason); /*reason: pstring*/ /*4.2*/
    return true;
  }
  bool packet_motion_prediction_hints(pdef::Stream &stream, const pdef::proto::packet_motion_prediction_hints &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_motion_prediction_hints(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.entity_runtime_id); /*0.4*/
    pdef::proto::encode::vec3f(stream, obj.velocity); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeBool, (bool)obj.on_ground); /*0.4*/
    return true;
  }
  bool packet_animate_entity(pdef::Stream &stream, const pdef::proto::packet_animate_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_animate_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.animation.length());
    WRITE_OR_BAIL(writeString, obj.animation); /*animation: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.next_state.length());
    WRITE_OR_BAIL(writeString, obj.next_state); /*next_state: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.stop_condition.length());
    WRITE_OR_BAIL(writeString, obj.stop_condition); /*stop_condition: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)obj.stop_condition_version); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.controller.length());
    WRITE_OR_BAIL(writeString, obj.controller); /*controller: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.blend_out_time); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.runtime_entity_ids.size()); /*1.4*/
    for (const auto &v2 : obj.runtime_entity_ids) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)v2); /*0.4*/
    }
    return true;
  }
  bool packet_camera_shake(pdef::Stream &stream, const pdef::proto::packet_camera_shake &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_camera_shake(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeFloatLE, (float)obj.intensity); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.duration); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.type); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.action); /*7.1*/
    return true;
  }
  bool packet_player_fog(pdef::Stream &stream, const pdef::proto::packet_player_fog &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_player_fog(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.stack.size()); /*1.4*/
    for (const auto &v2 : obj.stack) { /*3.1*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.length());
      WRITE_OR_BAIL(writeString, v2); /*: pstring*/ /*4.2*/
    }
    return true;
  }
  bool packet_correct_player_move_prediction(pdef::Stream &stream, const pdef::proto::packet_correct_player_move_prediction &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_correct_player_move_prediction(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::vec3f(stream, obj.position); /*vec3f*/ /*4.5*/
    pdef::proto::encode::vec3f(stream, obj.delta); /*vec3f*/ /*4.5*/
    WRITE_OR_BAIL(writeBool, (bool)obj.on_ground); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.tick); /*0.4*/
    return true;
  }
  bool packet_item_component(pdef::Stream &stream, const pdef::proto::packet_item_component &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_item_component(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.entries.size()); /*2.1*/
    for (const auto &v : obj.entries) { pdef::proto::encode::ItemComponentList(stream, v); } /*2.2*/
    return true;
  }
  bool packet_filter_text_packet(pdef::Stream &stream, const pdef::proto::packet_filter_text_packet &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_filter_text_packet(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
    WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.from_server); /*0.4*/
    return true;
  }
  bool packet_debug_renderer(pdef::Stream &stream, const pdef::proto::packet_debug_renderer &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_debug_renderer(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::packet_debug_renderer::Type &type = obj.type; /*0.3*/
    WRITE_OR_BAIL(writeIntLE, (int32_t)(int32_t&)obj.type); /*7.1*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_debug_renderer::Type::Clear: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_debug_renderer::Type::AddCube: { /*8.5*/
          WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.text.length());
          WRITE_OR_BAIL(writeString, obj.text); /*text: pstring*/ /*4.2*/
          pdef::proto::encode::vec3f(stream, *obj.position); /*vec3f*/ /*4.5*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.red); /*0.4*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.green); /*0.4*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.blue); /*0.4*/
          WRITE_OR_BAIL(writeFloatLE, (float)obj.alpha); /*0.4*/
          WRITE_OR_BAIL(writeLongLE, (int64_t)obj.duration); /*0.4*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_sync_entity_property(pdef::Stream &stream, const pdef::proto::packet_sync_entity_property &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_sync_entity_property(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    return true;
  }
  bool packet_add_volume_entity(pdef::Stream &stream, const pdef::proto::packet_add_volume_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_add_volume_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.runtime_id); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.nbt); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.encoding_identifier.length());
    WRITE_OR_BAIL(writeString, obj.encoding_identifier); /*encoding_identifier: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.instance_name.length());
    WRITE_OR_BAIL(writeString, obj.instance_name); /*instance_name: pstring*/ /*4.2*/
    const pdef::proto::packet_add_volume_entity::Bounds &v = obj.bounds; /*["packet_add_volume_entity"]*/ /*7.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.dimension); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.engine_version.length());
    WRITE_OR_BAIL(writeString, obj.engine_version); /*engine_version: pstring*/ /*4.2*/
    return true;
  }
  bool packet_remove_volume_entity(pdef::Stream &stream, const pdef::proto::packet_remove_volume_entity &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_remove_volume_entity(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarLong, (int64_t)obj.entity_id); /*0.4*/
    return true;
  }
  bool packet_simulation_type(pdef::Stream &stream, const pdef::proto::packet_simulation_type &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_simulation_type(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.type); /*7.1*/
    return true;
  }
  bool packet_npc_dialogue(pdef::Stream &stream, const pdef::proto::packet_npc_dialogue &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_npc_dialogue(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.entity_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.action_type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.dialogue.length());
    WRITE_OR_BAIL(writeString, obj.dialogue); /*dialogue: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.screen_name.length());
    WRITE_OR_BAIL(writeString, obj.screen_name); /*screen_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.npc_name.length());
    WRITE_OR_BAIL(writeString, obj.npc_name); /*npc_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.action_json.length());
    WRITE_OR_BAIL(writeString, obj.action_json); /*action_json: pstring*/ /*4.2*/
    return true;
  }
  bool packet_edu_uri_resource_packet(pdef::Stream &stream, const pdef::proto::packet_edu_uri_resource_packet &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_edu_uri_resource_packet(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    pdef::proto::encode::EducationSharedResourceURI(stream, obj.resource); /*EducationSharedResourceURI*/ /*4.5*/
    return true;
  }
  bool packet_create_photo(pdef::Stream &stream, const pdef::proto::packet_create_photo &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_create_photo(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.photo_name.length());
    WRITE_OR_BAIL(writeString, obj.photo_name); /*photo_name: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.item_name.length());
    WRITE_OR_BAIL(writeString, obj.item_name); /*item_name: pstring*/ /*4.2*/
    return true;
  }
  bool packet_update_subchunk_blocks(pdef::Stream &stream, const pdef::proto::packet_update_subchunk_blocks &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_update_subchunk_blocks(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.x); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.y); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.z); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.blocks.size()); /*1.4*/
    for (const auto &v2 : obj.blocks) { /*3.1*/
      pdef::proto::encode::BlockUpdate(stream, v2); /*BlockUpdate*/ /*4.5*/
    }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.extra.size()); /*1.4*/
    for (const auto &v2 : obj.extra) { /*3.1*/
      pdef::proto::encode::BlockUpdate(stream, v2); /*BlockUpdate*/ /*4.5*/
    }
    return true;
  }
  bool packet_photo_info_request(pdef::Stream &stream, const pdef::proto::packet_photo_info_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_photo_info_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.photo_id); /*0.4*/
    return true;
  }
bool SubChunkEntryWithoutCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithoutCaching &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::SubChunkEntryWithoutCaching(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dx); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dy); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dz); /*0.4*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.result); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.payload.size());
    WRITE_OR_BAIL(writeBuffer, obj.payload); /*payload: buffer*/ /*4.2*/
    const pdef::proto::SubChunkEntryWithoutCaching::HeightmapType &heightmap_type = obj.heightmap_type; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.heightmap_type); /*7.1*/
    switch (heightmap_type) { /*8.0*/
      case pdef::proto::SubChunkEntryWithoutCaching::HeightmapType::HasData: { /*8.5*/
        WRITE_OR_BAIL(writeBuffer, obj.heightmap); /*heightmap: buffer*/ /*4.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  return true;
}
bool SubChunkEntryWithCaching(pdef::Stream &stream, const pdef::proto::SubChunkEntryWithCaching &obj, bool allocate = true) {
  if (allocate) { auto writeSize = pdef::proto::size::SubChunkEntryWithCaching(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dx); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dy); /*0.4*/
    WRITE_OR_BAIL(writeByte, (int8_t)obj.dz); /*0.4*/
    const pdef::proto::SubChunkEntryWithCaching::Result &result = obj.result; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.result); /*7.1*/
    switch (result) { /*8.0*/
      case pdef::proto::SubChunkEntryWithCaching::Result::SuccessAllAir: { /*8.5*/
        break;
      } /*8.7*/
      default: { /*8.3*/
        WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.payload.size());
        WRITE_OR_BAIL(writeBuffer, obj.payload); /*payload: buffer*/ /*4.2*/
        break;
      } /*8.7*/
    } /*8.8*/
    const pdef::proto::SubChunkEntryWithCaching::HeightmapType &heightmap_type = obj.heightmap_type; /*0.3*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.heightmap_type); /*7.1*/
    switch (heightmap_type) { /*8.0*/
      case pdef::proto::SubChunkEntryWithCaching::HeightmapType::HasData: { /*8.5*/
        WRITE_OR_BAIL(writeBuffer, obj.heightmap); /*heightmap: buffer*/ /*4.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    WRITE_OR_BAIL(writeULongLE, (uint64_t)obj.blob_id); /*0.4*/
  return true;
}
  bool packet_subchunk(pdef::Stream &stream, const pdef::proto::packet_subchunk &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_subchunk(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const bool &cache_enabled = obj.cache_enabled; /*0.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.cache_enabled); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.dimension); /*0.4*/
    pdef::proto::encode::vec3i(stream, obj.origin); /*vec3i*/ /*4.5*/
    if (cache_enabled == true) { /*8.1*/
      WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.entries_SubChunkEntryWithCaching.size()); /*2.1*/
      for (const auto &v : obj.entries_SubChunkEntryWithCaching) { pdef::proto::encode::SubChunkEntryWithCaching(stream, v); } /*2.2*/
    }
    else if (cache_enabled == false) { /*8.1*/
      WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.entries_SubChunkEntryWithoutCaching.size()); /*2.1*/
      for (const auto &v : obj.entries_SubChunkEntryWithoutCaching) { pdef::proto::encode::SubChunkEntryWithoutCaching(stream, v); } /*2.2*/
    }
    return true;
  }
  bool packet_subchunk_request(pdef::Stream &stream, const pdef::proto::packet_subchunk_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_subchunk_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.dimension); /*0.4*/
    pdef::proto::encode::vec3i(stream, obj.origin); /*vec3i*/ /*4.5*/
    WRITE_OR_BAIL(writeUIntLE, (uint32_t)obj.requests.size()); /*1.4*/
    for (const auto &v2 : obj.requests) { /*5.20*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.dx); /*0.4*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.dy); /*0.4*/
      WRITE_OR_BAIL(writeByte, (int8_t)v2.dz); /*0.4*/
    }
    return true;
  }
  bool packet_client_start_item_cooldown(pdef::Stream &stream, const pdef::proto::packet_client_start_item_cooldown &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_client_start_item_cooldown(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.category.length());
    WRITE_OR_BAIL(writeString, obj.category); /*category: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.duration); /*0.4*/
    return true;
  }
  bool packet_script_message(pdef::Stream &stream, const pdef::proto::packet_script_message &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_script_message(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message_id.length());
    WRITE_OR_BAIL(writeString, obj.message_id); /*message_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.data.length());
    WRITE_OR_BAIL(writeString, obj.data); /*data: pstring*/ /*4.2*/
    return true;
  }
  bool packet_code_builder_source(pdef::Stream &stream, const pdef::proto::packet_code_builder_source &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_code_builder_source(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.operation); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.category); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.value.length());
    WRITE_OR_BAIL(writeString, obj.value); /*value: pstring*/ /*4.2*/
    return true;
  }
  bool packet_ticking_areas_load_status(pdef::Stream &stream, const pdef::proto::packet_ticking_areas_load_status &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_ticking_areas_load_status(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeBool, (bool)obj.preload); /*0.4*/
    return true;
  }
  bool packet_dimension_data(pdef::Stream &stream, const pdef::proto::packet_dimension_data &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_dimension_data(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.definitions.size()); /*1.4*/
    for (const auto &v2 : obj.definitions) { /*5.20*/
      WRITE_OR_BAIL(writeUnsignedVarInt, (int)v2.id.length());
      WRITE_OR_BAIL(writeString, v2.id); /*id: pstring*/ /*4.2*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)v2.max_height); /*0.4*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)v2.min_height); /*0.4*/
      WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)v2.generator); /*7.1*/
    }
    return true;
  }
  bool packet_agent_action(pdef::Stream &stream, const pdef::proto::packet_agent_action &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_agent_action(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.request_id.length());
    WRITE_OR_BAIL(writeString, obj.request_id); /*request_id: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.action_type); /*7.1*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.body.length());
    WRITE_OR_BAIL(writeString, obj.body); /*body: pstring*/ /*4.2*/
    return true;
  }
  bool packet_change_mob_property(pdef::Stream &stream, const pdef::proto::packet_change_mob_property &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_change_mob_property(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarLong, (int64_t)obj.entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.property.length());
    WRITE_OR_BAIL(writeString, obj.property); /*property: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeBool, (bool)obj.bool_value); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.string_value.length());
    WRITE_OR_BAIL(writeString, obj.string_value); /*string_value: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.int_value); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.float_value); /*0.4*/
    return true;
  }
  bool packet_lesson_progress(pdef::Stream &stream, const pdef::proto::packet_lesson_progress &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_lesson_progress(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUByte, (uint8_t)obj.action); /*0.4*/
    WRITE_OR_BAIL(writeZigZagVarInt, (int)obj.score); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.identifier.length());
    WRITE_OR_BAIL(writeString, obj.identifier); /*identifier: pstring*/ /*4.2*/
    return true;
  }
  bool packet_request_ability(pdef::Stream &stream, const pdef::proto::packet_request_ability &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_request_ability(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeZigZagVarInt, (int)(int&)obj.ability); /*7.1*/
    WRITE_OR_BAIL(writeUByte, (uint8_t)(uint8_t&)obj.value_type); /*7.1*/
    WRITE_OR_BAIL(writeBool, (bool)obj.bool_value); /*0.4*/
    WRITE_OR_BAIL(writeFloatLE, (float)obj.float_val); /*0.4*/
    return true;
  }
  bool packet_request_permissions(pdef::Stream &stream, const pdef::proto::packet_request_permissions &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_request_permissions(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeLongLE, (int64_t)obj.entity_unique_id); /*0.4*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.permission_level); /*7.1*/
    uint16_t requested_permissions_val = 0;
    if (obj.requested_permissions.build) requested_permissions_val |= 1;
    if (obj.requested_permissions.mine) requested_permissions_val |= 2;
    if (obj.requested_permissions.doors_and_switches) requested_permissions_val |= 4;
    if (obj.requested_permissions.open_containers) requested_permissions_val |= 8;
    if (obj.requested_permissions.attack_players) requested_permissions_val |= 16;
    if (obj.requested_permissions.attack_mobs) requested_permissions_val |= 32;
    if (obj.requested_permissions.operator_) requested_permissions_val |= 64;
    if (obj.requested_permissions.teleport) requested_permissions_val |= 128;
    WRITE_OR_BAIL(writeUShortLE, (uint16_t)requested_permissions_val) /*requested_permissions: bitflags*/ /*4.2*/
    return true;
  }
  bool packet_toast_request(pdef::Stream &stream, const pdef::proto::packet_toast_request &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::packet_toast_request(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.title.length());
    WRITE_OR_BAIL(writeString, obj.title); /*title: pstring*/ /*4.2*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)obj.message.length());
    WRITE_OR_BAIL(writeString, obj.message); /*message: pstring*/ /*4.2*/
    return true;
  }
  bool mcpe_packet(pdef::Stream &stream, const pdef::proto::mcpe_packet &obj, bool allocate = true) {
    if (allocate) { auto writeSize = pdef::proto::size::mcpe_packet(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }
    const pdef::proto::mcpe_packet::Name &name = obj.name; /*0.3*/
    WRITE_OR_BAIL(writeUnsignedVarInt, (int)(int&)obj.name); /*7.1*/
    switch (name) { /*8.0*/
      case pdef::proto::mcpe_packet::Name::Login: { /*8.5*/
        pdef::proto::encode::packet_login(stream, *obj.params_packet_login); /*packet_login*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayStatus: { /*8.5*/
        pdef::proto::encode::packet_play_status(stream, *obj.params_packet_play_status); /*packet_play_status*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerToClientHandshake: { /*8.5*/
        pdef::proto::encode::packet_server_to_client_handshake(stream, *obj.params_packet_server_to_client_handshake); /*packet_server_to_client_handshake*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientToServerHandshake: { /*8.5*/
        pdef::proto::encode::packet_client_to_server_handshake(stream, *obj.params_packet_client_to_server_handshake); /*packet_client_to_server_handshake*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Disconnect: { /*8.5*/
        pdef::proto::encode::packet_disconnect(stream, *obj.params_packet_disconnect); /*packet_disconnect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePacksInfo: { /*8.5*/
        pdef::proto::encode::packet_resource_packs_info(stream, *obj.params_packet_resource_packs_info); /*packet_resource_packs_info*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackStack: { /*8.5*/
        pdef::proto::encode::packet_resource_pack_stack(stream, *obj.params_packet_resource_pack_stack); /*packet_resource_pack_stack*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackClientResponse: { /*8.5*/
        pdef::proto::encode::packet_resource_pack_client_response(stream, *obj.params_packet_resource_pack_client_response); /*packet_resource_pack_client_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Text: { /*8.5*/
        pdef::proto::encode::packet_text(stream, *obj.params_packet_text); /*packet_text*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetTime: { /*8.5*/
        pdef::proto::encode::packet_set_time(stream, *obj.params_packet_set_time); /*packet_set_time*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StartGame: { /*8.5*/
        pdef::proto::encode::packet_start_game(stream, *obj.params_packet_start_game); /*packet_start_game*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddPlayer: { /*8.5*/
        pdef::proto::encode::packet_add_player(stream, *obj.params_packet_add_player); /*packet_add_player*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddEntity: { /*8.5*/
        pdef::proto::encode::packet_add_entity(stream, *obj.params_packet_add_entity); /*packet_add_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveEntity: { /*8.5*/
        pdef::proto::encode::packet_remove_entity(stream, *obj.params_packet_remove_entity); /*packet_remove_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddItemEntity: { /*8.5*/
        pdef::proto::encode::packet_add_item_entity(stream, *obj.params_packet_add_item_entity); /*packet_add_item_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TakeItemEntity: { /*8.5*/
        pdef::proto::encode::packet_take_item_entity(stream, *obj.params_packet_take_item_entity); /*packet_take_item_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MoveEntity: { /*8.5*/
        pdef::proto::encode::packet_move_entity(stream, *obj.params_packet_move_entity); /*packet_move_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MovePlayer: { /*8.5*/
        pdef::proto::encode::packet_move_player(stream, *obj.params_packet_move_player); /*packet_move_player*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RiderJump: { /*8.5*/
        pdef::proto::encode::packet_rider_jump(stream, *obj.params_packet_rider_jump); /*packet_rider_jump*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlock: { /*8.5*/
        pdef::proto::encode::packet_update_block(stream, *obj.params_packet_update_block); /*packet_update_block*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddPainting: { /*8.5*/
        pdef::proto::encode::packet_add_painting(stream, *obj.params_packet_add_painting); /*packet_add_painting*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TickSync: { /*8.5*/
        pdef::proto::encode::packet_tick_sync(stream, *obj.params_packet_tick_sync); /*packet_tick_sync*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEventOld: { /*8.5*/
        pdef::proto::encode::packet_level_sound_event_old(stream, *obj.params_packet_level_sound_event_old); /*packet_level_sound_event_old*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelEvent: { /*8.5*/
        pdef::proto::encode::packet_level_event(stream, *obj.params_packet_level_event); /*packet_level_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockEvent: { /*8.5*/
        pdef::proto::encode::packet_block_event(stream, *obj.params_packet_block_event); /*packet_block_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EntityEvent: { /*8.5*/
        pdef::proto::encode::packet_entity_event(stream, *obj.params_packet_entity_event); /*packet_entity_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobEffect: { /*8.5*/
        pdef::proto::encode::packet_mob_effect(stream, *obj.params_packet_mob_effect); /*packet_mob_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateAttributes: { /*8.5*/
        pdef::proto::encode::packet_update_attributes(stream, *obj.params_packet_update_attributes); /*packet_update_attributes*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventoryTransaction: { /*8.5*/
        pdef::proto::encode::packet_inventory_transaction(stream, *obj.params_packet_inventory_transaction); /*packet_inventory_transaction*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobEquipment: { /*8.5*/
        pdef::proto::encode::packet_mob_equipment(stream, *obj.params_packet_mob_equipment); /*packet_mob_equipment*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobArmorEquipment: { /*8.5*/
        pdef::proto::encode::packet_mob_armor_equipment(stream, *obj.params_packet_mob_armor_equipment); /*packet_mob_armor_equipment*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Interact: { /*8.5*/
        pdef::proto::encode::packet_interact(stream, *obj.params_packet_interact); /*packet_interact*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockPickRequest: { /*8.5*/
        pdef::proto::encode::packet_block_pick_request(stream, *obj.params_packet_block_pick_request); /*packet_block_pick_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EntityPickRequest: { /*8.5*/
        pdef::proto::encode::packet_entity_pick_request(stream, *obj.params_packet_entity_pick_request); /*packet_entity_pick_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerAction: { /*8.5*/
        pdef::proto::encode::packet_player_action(stream, *obj.params_packet_player_action); /*packet_player_action*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::HurtArmor: { /*8.5*/
        pdef::proto::encode::packet_hurt_armor(stream, *obj.params_packet_hurt_armor); /*packet_hurt_armor*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityData: { /*8.5*/
        pdef::proto::encode::packet_set_entity_data(stream, *obj.params_packet_set_entity_data); /*packet_set_entity_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityMotion: { /*8.5*/
        pdef::proto::encode::packet_set_entity_motion(stream, *obj.params_packet_set_entity_motion); /*packet_set_entity_motion*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityLink: { /*8.5*/
        pdef::proto::encode::packet_set_entity_link(stream, *obj.params_packet_set_entity_link); /*packet_set_entity_link*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetHealth: { /*8.5*/
        pdef::proto::encode::packet_set_health(stream, *obj.params_packet_set_health); /*packet_set_health*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetSpawnPosition: { /*8.5*/
        pdef::proto::encode::packet_set_spawn_position(stream, *obj.params_packet_set_spawn_position); /*packet_set_spawn_position*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Animate: { /*8.5*/
        pdef::proto::encode::packet_animate(stream, *obj.params_packet_animate); /*packet_animate*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Respawn: { /*8.5*/
        pdef::proto::encode::packet_respawn(stream, *obj.params_packet_respawn); /*packet_respawn*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerOpen: { /*8.5*/
        pdef::proto::encode::packet_container_open(stream, *obj.params_packet_container_open); /*packet_container_open*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerClose: { /*8.5*/
        pdef::proto::encode::packet_container_close(stream, *obj.params_packet_container_close); /*packet_container_close*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerHotbar: { /*8.5*/
        pdef::proto::encode::packet_player_hotbar(stream, *obj.params_packet_player_hotbar); /*packet_player_hotbar*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventoryContent: { /*8.5*/
        pdef::proto::encode::packet_inventory_content(stream, *obj.params_packet_inventory_content); /*packet_inventory_content*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventorySlot: { /*8.5*/
        pdef::proto::encode::packet_inventory_slot(stream, *obj.params_packet_inventory_slot); /*packet_inventory_slot*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerSetData: { /*8.5*/
        pdef::proto::encode::packet_container_set_data(stream, *obj.params_packet_container_set_data); /*packet_container_set_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CraftingData: { /*8.5*/
        pdef::proto::encode::packet_crafting_data(stream, *obj.params_packet_crafting_data); /*packet_crafting_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CraftingEvent: { /*8.5*/
        pdef::proto::encode::packet_crafting_event(stream, *obj.params_packet_crafting_event); /*packet_crafting_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::GuiDataPickItem: { /*8.5*/
        pdef::proto::encode::packet_gui_data_pick_item(stream, *obj.params_packet_gui_data_pick_item); /*packet_gui_data_pick_item*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AdventureSettings: { /*8.5*/
        pdef::proto::encode::packet_adventure_settings(stream, *obj.params_packet_adventure_settings); /*packet_adventure_settings*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockEntityData: { /*8.5*/
        pdef::proto::encode::packet_block_entity_data(stream, *obj.params_packet_block_entity_data); /*packet_block_entity_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerInput: { /*8.5*/
        pdef::proto::encode::packet_player_input(stream, *obj.params_packet_player_input); /*packet_player_input*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelChunk: { /*8.5*/
        pdef::proto::encode::packet_level_chunk(stream, *obj.params_packet_level_chunk); /*packet_level_chunk*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetCommandsEnabled: { /*8.5*/
        pdef::proto::encode::packet_set_commands_enabled(stream, *obj.params_packet_set_commands_enabled); /*packet_set_commands_enabled*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDifficulty: { /*8.5*/
        pdef::proto::encode::packet_set_difficulty(stream, *obj.params_packet_set_difficulty); /*packet_set_difficulty*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChangeDimension: { /*8.5*/
        pdef::proto::encode::packet_change_dimension(stream, *obj.params_packet_change_dimension); /*packet_change_dimension*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetPlayerGameType: { /*8.5*/
        pdef::proto::encode::packet_set_player_game_type(stream, *obj.params_packet_set_player_game_type); /*packet_set_player_game_type*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerList: { /*8.5*/
        pdef::proto::encode::packet_player_list(stream, *obj.params_packet_player_list); /*packet_player_list*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SimpleEvent: { /*8.5*/
        pdef::proto::encode::packet_simple_event(stream, *obj.params_packet_simple_event); /*packet_simple_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Event: { /*8.5*/
        pdef::proto::encode::packet_event(stream, *obj.params_packet_event); /*packet_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SpawnExperienceOrb: { /*8.5*/
        pdef::proto::encode::packet_spawn_experience_orb(stream, *obj.params_packet_spawn_experience_orb); /*packet_spawn_experience_orb*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientboundMapItemData: { /*8.5*/
        pdef::proto::encode::packet_clientbound_map_item_data(stream, *obj.params_packet_clientbound_map_item_data); /*packet_clientbound_map_item_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MapInfoRequest: { /*8.5*/
        pdef::proto::encode::packet_map_info_request(stream, *obj.params_packet_map_info_request); /*packet_map_info_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestChunkRadius: { /*8.5*/
        pdef::proto::encode::packet_request_chunk_radius(stream, *obj.params_packet_request_chunk_radius); /*packet_request_chunk_radius*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChunkRadiusUpdate: { /*8.5*/
        pdef::proto::encode::packet_chunk_radius_update(stream, *obj.params_packet_chunk_radius_update); /*packet_chunk_radius_update*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemFrameDropItem: { /*8.5*/
        pdef::proto::encode::packet_item_frame_drop_item(stream, *obj.params_packet_item_frame_drop_item); /*packet_item_frame_drop_item*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::GameRulesChanged: { /*8.5*/
        pdef::proto::encode::packet_game_rules_changed(stream, *obj.params_packet_game_rules_changed); /*packet_game_rules_changed*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Camera: { /*8.5*/
        pdef::proto::encode::packet_camera(stream, *obj.params_packet_camera); /*packet_camera*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BossEvent: { /*8.5*/
        pdef::proto::encode::packet_boss_event(stream, *obj.params_packet_boss_event); /*packet_boss_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowCredits: { /*8.5*/
        pdef::proto::encode::packet_show_credits(stream, *obj.params_packet_show_credits); /*packet_show_credits*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AvailableCommands: { /*8.5*/
        pdef::proto::encode::packet_available_commands(stream, *obj.params_packet_available_commands); /*packet_available_commands*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandRequest: { /*8.5*/
        pdef::proto::encode::packet_command_request(stream, *obj.params_packet_command_request); /*packet_command_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandBlockUpdate: { /*8.5*/
        pdef::proto::encode::packet_command_block_update(stream, *obj.params_packet_command_block_update); /*packet_command_block_update*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandOutput: { /*8.5*/
        pdef::proto::encode::packet_command_output(stream, *obj.params_packet_command_output); /*packet_command_output*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateTrade: { /*8.5*/
        pdef::proto::encode::packet_update_trade(stream, *obj.params_packet_update_trade); /*packet_update_trade*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateEquipment: { /*8.5*/
        pdef::proto::encode::packet_update_equipment(stream, *obj.params_packet_update_equipment); /*packet_update_equipment*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackDataInfo: { /*8.5*/
        pdef::proto::encode::packet_resource_pack_data_info(stream, *obj.params_packet_resource_pack_data_info); /*packet_resource_pack_data_info*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackChunkData: { /*8.5*/
        pdef::proto::encode::packet_resource_pack_chunk_data(stream, *obj.params_packet_resource_pack_chunk_data); /*packet_resource_pack_chunk_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackChunkRequest: { /*8.5*/
        pdef::proto::encode::packet_resource_pack_chunk_request(stream, *obj.params_packet_resource_pack_chunk_request); /*packet_resource_pack_chunk_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Transfer: { /*8.5*/
        pdef::proto::encode::packet_transfer(stream, *obj.params_packet_transfer); /*packet_transfer*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlaySound: { /*8.5*/
        pdef::proto::encode::packet_play_sound(stream, *obj.params_packet_play_sound); /*packet_play_sound*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StopSound: { /*8.5*/
        pdef::proto::encode::packet_stop_sound(stream, *obj.params_packet_stop_sound); /*packet_stop_sound*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetTitle: { /*8.5*/
        pdef::proto::encode::packet_set_title(stream, *obj.params_packet_set_title); /*packet_set_title*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddBehaviorTree: { /*8.5*/
        pdef::proto::encode::packet_add_behavior_tree(stream, *obj.params_packet_add_behavior_tree); /*packet_add_behavior_tree*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureBlockUpdate: { /*8.5*/
        pdef::proto::encode::packet_structure_block_update(stream, *obj.params_packet_structure_block_update); /*packet_structure_block_update*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowStoreOffer: { /*8.5*/
        pdef::proto::encode::packet_show_store_offer(stream, *obj.params_packet_show_store_offer); /*packet_show_store_offer*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PurchaseReceipt: { /*8.5*/
        pdef::proto::encode::packet_purchase_receipt(stream, *obj.params_packet_purchase_receipt); /*packet_purchase_receipt*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerSkin: { /*8.5*/
        pdef::proto::encode::packet_player_skin(stream, *obj.params_packet_player_skin); /*packet_player_skin*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SubClientLogin: { /*8.5*/
        pdef::proto::encode::packet_sub_client_login(stream, *obj.params_packet_sub_client_login); /*packet_sub_client_login*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InitiateWebSocketConnection: { /*8.5*/
        pdef::proto::encode::packet_initiate_web_socket_connection(stream, *obj.params_packet_initiate_web_socket_connection); /*packet_initiate_web_socket_connection*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetLastHurtBy: { /*8.5*/
        pdef::proto::encode::packet_set_last_hurt_by(stream, *obj.params_packet_set_last_hurt_by); /*packet_set_last_hurt_by*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BookEdit: { /*8.5*/
        pdef::proto::encode::packet_book_edit(stream, *obj.params_packet_book_edit); /*packet_book_edit*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NpcRequest: { /*8.5*/
        pdef::proto::encode::packet_npc_request(stream, *obj.params_packet_npc_request); /*packet_npc_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PhotoTransfer: { /*8.5*/
        pdef::proto::encode::packet_photo_transfer(stream, *obj.params_packet_photo_transfer); /*packet_photo_transfer*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ModalFormRequest: { /*8.5*/
        pdef::proto::encode::packet_modal_form_request(stream, *obj.params_packet_modal_form_request); /*packet_modal_form_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ModalFormResponse: { /*8.5*/
        pdef::proto::encode::packet_modal_form_response(stream, *obj.params_packet_modal_form_response); /*packet_modal_form_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerSettingsRequest: { /*8.5*/
        pdef::proto::encode::packet_server_settings_request(stream, *obj.params_packet_server_settings_request); /*packet_server_settings_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerSettingsResponse: { /*8.5*/
        pdef::proto::encode::packet_server_settings_response(stream, *obj.params_packet_server_settings_response); /*packet_server_settings_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowProfile: { /*8.5*/
        pdef::proto::encode::packet_show_profile(stream, *obj.params_packet_show_profile); /*packet_show_profile*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDefaultGameType: { /*8.5*/
        pdef::proto::encode::packet_set_default_game_type(stream, *obj.params_packet_set_default_game_type); /*packet_set_default_game_type*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveObjective: { /*8.5*/
        pdef::proto::encode::packet_remove_objective(stream, *obj.params_packet_remove_objective); /*packet_remove_objective*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDisplayObjective: { /*8.5*/
        pdef::proto::encode::packet_set_display_objective(stream, *obj.params_packet_set_display_objective); /*packet_set_display_objective*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetScore: { /*8.5*/
        pdef::proto::encode::packet_set_score(stream, *obj.params_packet_set_score); /*packet_set_score*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LabTable: { /*8.5*/
        pdef::proto::encode::packet_lab_table(stream, *obj.params_packet_lab_table); /*packet_lab_table*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlockSynced: { /*8.5*/
        pdef::proto::encode::packet_update_block_synced(stream, *obj.params_packet_update_block_synced); /*packet_update_block_synced*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MoveEntityDelta: { /*8.5*/
        pdef::proto::encode::packet_move_entity_delta(stream, *obj.params_packet_move_entity_delta); /*packet_move_entity_delta*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetScoreboardIdentity: { /*8.5*/
        pdef::proto::encode::packet_set_scoreboard_identity(stream, *obj.params_packet_set_scoreboard_identity); /*packet_set_scoreboard_identity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetLocalPlayerAsInitialized: { /*8.5*/
        pdef::proto::encode::packet_set_local_player_as_initialized(stream, *obj.params_packet_set_local_player_as_initialized); /*packet_set_local_player_as_initialized*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateSoftEnum: { /*8.5*/
        pdef::proto::encode::packet_update_soft_enum(stream, *obj.params_packet_update_soft_enum); /*packet_update_soft_enum*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkStackLatency: { /*8.5*/
        pdef::proto::encode::packet_network_stack_latency(stream, *obj.params_packet_network_stack_latency); /*packet_network_stack_latency*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ScriptCustomEvent: { /*8.5*/
        pdef::proto::encode::packet_script_custom_event(stream, *obj.params_packet_script_custom_event); /*packet_script_custom_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SpawnParticleEffect: { /*8.5*/
        pdef::proto::encode::packet_spawn_particle_effect(stream, *obj.params_packet_spawn_particle_effect); /*packet_spawn_particle_effect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AvailableEntityIdentifiers: { /*8.5*/
        pdef::proto::encode::packet_available_entity_identifiers(stream, *obj.params_packet_available_entity_identifiers); /*packet_available_entity_identifiers*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEventV2: { /*8.5*/
        pdef::proto::encode::packet_level_sound_event_v2(stream, *obj.params_packet_level_sound_event_v2); /*packet_level_sound_event_v2*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkChunkPublisherUpdate: { /*8.5*/
        pdef::proto::encode::packet_network_chunk_publisher_update(stream, *obj.params_packet_network_chunk_publisher_update); /*packet_network_chunk_publisher_update*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BiomeDefinitionList: { /*8.5*/
        pdef::proto::encode::packet_biome_definition_list(stream, *obj.params_packet_biome_definition_list); /*packet_biome_definition_list*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEvent: { /*8.5*/
        pdef::proto::encode::packet_level_sound_event(stream, *obj.params_packet_level_sound_event); /*packet_level_sound_event*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelEventGeneric: { /*8.5*/
        pdef::proto::encode::packet_level_event_generic(stream, *obj.params_packet_level_event_generic); /*packet_level_event_generic*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LecternUpdate: { /*8.5*/
        pdef::proto::encode::packet_lectern_update(stream, *obj.params_packet_lectern_update); /*packet_lectern_update*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::VideoStreamConnect: { /*8.5*/
        pdef::proto::encode::packet_video_stream_connect(stream, *obj.params_packet_video_stream_connect); /*packet_video_stream_connect*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddEcsEntity: { /*8.5*/
        pdef::proto::encode::packet_add_ecs_entity(stream, *obj.params_packet_add_ecs_entity); /*packet_add_ecs_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveEcsEntity: { /*8.5*/
        pdef::proto::encode::packet_remove_ecs_entity(stream, *obj.params_packet_remove_ecs_entity); /*packet_remove_ecs_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheStatus: { /*8.5*/
        pdef::proto::encode::packet_client_cache_status(stream, *obj.params_packet_client_cache_status); /*packet_client_cache_status*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::OnScreenTextureAnimation: { /*8.5*/
        pdef::proto::encode::packet_on_screen_texture_animation(stream, *obj.params_packet_on_screen_texture_animation); /*packet_on_screen_texture_animation*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MapCreateLockedCopy: { /*8.5*/
        pdef::proto::encode::packet_map_create_locked_copy(stream, *obj.params_packet_map_create_locked_copy); /*packet_map_create_locked_copy*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureTemplateDataExportRequest: { /*8.5*/
        pdef::proto::encode::packet_structure_template_data_export_request(stream, *obj.params_packet_structure_template_data_export_request); /*packet_structure_template_data_export_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureTemplateDataExportResponse: { /*8.5*/
        pdef::proto::encode::packet_structure_template_data_export_response(stream, *obj.params_packet_structure_template_data_export_response); /*packet_structure_template_data_export_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlockProperties: { /*8.5*/
        pdef::proto::encode::packet_update_block_properties(stream, *obj.params_packet_update_block_properties); /*packet_update_block_properties*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheBlobStatus: { /*8.5*/
        pdef::proto::encode::packet_client_cache_blob_status(stream, *obj.params_packet_client_cache_blob_status); /*packet_client_cache_blob_status*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheMissResponse: { /*8.5*/
        pdef::proto::encode::packet_client_cache_miss_response(stream, *obj.params_packet_client_cache_miss_response); /*packet_client_cache_miss_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EducationSettings: { /*8.5*/
        pdef::proto::encode::packet_education_settings(stream, *obj.params_packet_education_settings); /*packet_education_settings*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Emote: { /*8.5*/
        pdef::proto::encode::packet_emote(stream, *obj.params_packet_emote); /*packet_emote*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MultiplayerSettings: { /*8.5*/
        pdef::proto::encode::packet_multiplayer_settings(stream, *obj.params_packet_multiplayer_settings); /*packet_multiplayer_settings*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SettingsCommand: { /*8.5*/
        pdef::proto::encode::packet_settings_command(stream, *obj.params_packet_settings_command); /*packet_settings_command*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AnvilDamage: { /*8.5*/
        pdef::proto::encode::packet_anvil_damage(stream, *obj.params_packet_anvil_damage); /*packet_anvil_damage*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CompletedUsingItem: { /*8.5*/
        pdef::proto::encode::packet_completed_using_item(stream, *obj.params_packet_completed_using_item); /*packet_completed_using_item*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkSettings: { /*8.5*/
        pdef::proto::encode::packet_network_settings(stream, *obj.params_packet_network_settings); /*packet_network_settings*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerAuthInput: { /*8.5*/
        pdef::proto::encode::packet_player_auth_input(stream, *obj.params_packet_player_auth_input); /*packet_player_auth_input*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CreativeContent: { /*8.5*/
        pdef::proto::encode::packet_creative_content(stream, *obj.params_packet_creative_content); /*packet_creative_content*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerEnchantOptions: { /*8.5*/
        pdef::proto::encode::packet_player_enchant_options(stream, *obj.params_packet_player_enchant_options); /*packet_player_enchant_options*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemStackRequest: { /*8.5*/
        pdef::proto::encode::packet_item_stack_request(stream, *obj.params_packet_item_stack_request); /*packet_item_stack_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemStackResponse: { /*8.5*/
        pdef::proto::encode::packet_item_stack_response(stream, *obj.params_packet_item_stack_response); /*packet_item_stack_response*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerArmorDamage: { /*8.5*/
        pdef::proto::encode::packet_player_armor_damage(stream, *obj.params_packet_player_armor_damage); /*packet_player_armor_damage*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdatePlayerGameType: { /*8.5*/
        pdef::proto::encode::packet_update_player_game_type(stream, *obj.params_packet_update_player_game_type); /*packet_update_player_game_type*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EmoteList: { /*8.5*/
        pdef::proto::encode::packet_emote_list(stream, *obj.params_packet_emote_list); /*packet_emote_list*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PositionTrackingDbRequest: { /*8.5*/
        pdef::proto::encode::packet_position_tracking_db_request(stream, *obj.params_packet_position_tracking_db_request); /*packet_position_tracking_db_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PositionTrackingDbBroadcast: { /*8.5*/
        pdef::proto::encode::packet_position_tracking_db_broadcast(stream, *obj.params_packet_position_tracking_db_broadcast); /*packet_position_tracking_db_broadcast*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PacketViolationWarning: { /*8.5*/
        pdef::proto::encode::packet_packet_violation_warning(stream, *obj.params_packet_packet_violation_warning); /*packet_packet_violation_warning*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MotionPredictionHints: { /*8.5*/
        pdef::proto::encode::packet_motion_prediction_hints(stream, *obj.params_packet_motion_prediction_hints); /*packet_motion_prediction_hints*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AnimateEntity: { /*8.5*/
        pdef::proto::encode::packet_animate_entity(stream, *obj.params_packet_animate_entity); /*packet_animate_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CameraShake: { /*8.5*/
        pdef::proto::encode::packet_camera_shake(stream, *obj.params_packet_camera_shake); /*packet_camera_shake*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerFog: { /*8.5*/
        pdef::proto::encode::packet_player_fog(stream, *obj.params_packet_player_fog); /*packet_player_fog*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CorrectPlayerMovePrediction: { /*8.5*/
        pdef::proto::encode::packet_correct_player_move_prediction(stream, *obj.params_packet_correct_player_move_prediction); /*packet_correct_player_move_prediction*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemComponent: { /*8.5*/
        pdef::proto::encode::packet_item_component(stream, *obj.params_packet_item_component); /*packet_item_component*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::FilterTextPacket: { /*8.5*/
        pdef::proto::encode::packet_filter_text_packet(stream, *obj.params_packet_filter_text_packet); /*packet_filter_text_packet*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::DebugRenderer: { /*8.5*/
        pdef::proto::encode::packet_debug_renderer(stream, *obj.params_packet_debug_renderer); /*packet_debug_renderer*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SyncEntityProperty: { /*8.5*/
        pdef::proto::encode::packet_sync_entity_property(stream, *obj.params_packet_sync_entity_property); /*packet_sync_entity_property*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddVolumeEntity: { /*8.5*/
        pdef::proto::encode::packet_add_volume_entity(stream, *obj.params_packet_add_volume_entity); /*packet_add_volume_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveVolumeEntity: { /*8.5*/
        pdef::proto::encode::packet_remove_volume_entity(stream, *obj.params_packet_remove_volume_entity); /*packet_remove_volume_entity*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SimulationType: { /*8.5*/
        pdef::proto::encode::packet_simulation_type(stream, *obj.params_packet_simulation_type); /*packet_simulation_type*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NpcDialogue: { /*8.5*/
        pdef::proto::encode::packet_npc_dialogue(stream, *obj.params_packet_npc_dialogue); /*packet_npc_dialogue*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EduUriResourcePacket: { /*8.5*/
        pdef::proto::encode::packet_edu_uri_resource_packet(stream, *obj.params_packet_edu_uri_resource_packet); /*packet_edu_uri_resource_packet*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CreatePhoto: { /*8.5*/
        pdef::proto::encode::packet_create_photo(stream, *obj.params_packet_create_photo); /*packet_create_photo*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateSubchunkBlocks: { /*8.5*/
        pdef::proto::encode::packet_update_subchunk_blocks(stream, *obj.params_packet_update_subchunk_blocks); /*packet_update_subchunk_blocks*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PhotoInfoRequest: { /*8.5*/
        pdef::proto::encode::packet_photo_info_request(stream, *obj.params_packet_photo_info_request); /*packet_photo_info_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Subchunk: { /*8.5*/
        pdef::proto::encode::packet_subchunk(stream, *obj.params_packet_subchunk); /*packet_subchunk*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SubchunkRequest: { /*8.5*/
        pdef::proto::encode::packet_subchunk_request(stream, *obj.params_packet_subchunk_request); /*packet_subchunk_request*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientStartItemCooldown: { /*8.5*/
        pdef::proto::encode::packet_client_start_item_cooldown(stream, *obj.params_packet_client_start_item_cooldown); /*packet_client_start_item_cooldown*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ScriptMessage: { /*8.5*/
        pdef::proto::encode::packet_script_message(stream, *obj.params_packet_script_message); /*packet_script_message*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CodeBuilderSource: { /*8.5*/
        pdef::proto::encode::packet_code_builder_source(stream, *obj.params_packet_code_builder_source); /*packet_code_builder_source*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TickingAreasLoadStatus: { /*8.5*/
        pdef::proto::encode::packet_ticking_areas_load_status(stream, *obj.params_packet_ticking_areas_load_status); /*packet_ticking_areas_load_status*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::DimensionData: { /*8.5*/
        pdef::proto::encode::packet_dimension_data(stream, *obj.params_packet_dimension_data); /*packet_dimension_data*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AgentAction: { /*8.5*/
        pdef::proto::encode::packet_agent_action(stream, *obj.params_packet_agent_action); /*packet_agent_action*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChangeMobProperty: { /*8.5*/
        pdef::proto::encode::packet_change_mob_property(stream, *obj.params_packet_change_mob_property); /*packet_change_mob_property*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LessonProgress: { /*8.5*/
        pdef::proto::encode::packet_lesson_progress(stream, *obj.params_packet_lesson_progress); /*packet_lesson_progress*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestAbility: { /*8.5*/
        pdef::proto::encode::packet_request_ability(stream, *obj.params_packet_request_ability); /*packet_request_ability*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestPermissions: { /*8.5*/
        pdef::proto::encode::packet_request_permissions(stream, *obj.params_packet_request_permissions); /*packet_request_permissions*/ /*4.5*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ToastRequest: { /*8.5*/
        pdef::proto::encode::packet_toast_request(stream, *obj.params_packet_toast_request); /*packet_toast_request*/ /*4.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

namespace pdef::proto::decode {
bool BehaviourPackInfos(pdef::Stream &stream, pdef::proto::BehaviourPackInfos &obj);
bool TexturePackInfos(pdef::Stream &stream, pdef::proto::TexturePackInfos &obj);
bool ResourcePackIdVersions(pdef::Stream &stream, pdef::proto::ResourcePackIdVersions &obj);
bool Experiment(pdef::Stream &stream, pdef::proto::Experiment &obj);
bool GameRule(pdef::Stream &stream, pdef::proto::GameRule &obj);
bool Blob(pdef::Stream &stream, pdef::proto::Blob &obj);
bool BlockProperties(pdef::Stream &stream, pdef::proto::BlockProperties &obj);
bool Itemstates(pdef::Stream &stream, pdef::proto::Itemstates &obj);
bool ItemExtraDataWithBlockingTick(pdef::Stream &stream, pdef::proto::ItemExtraDataWithBlockingTick &obj);
bool ItemExtraDataWithoutBlockingTick(pdef::Stream &stream, pdef::proto::ItemExtraDataWithoutBlockingTick &obj);
bool ItemLegacy(pdef::Stream &stream, pdef::proto::ItemLegacy &obj);
bool Item(pdef::Stream &stream, pdef::proto::Item &obj);
bool vec3i(pdef::Stream &stream, pdef::proto::vec3i &obj);
bool vec3u(pdef::Stream &stream, pdef::proto::vec3u &obj);
bool vec3f(pdef::Stream &stream, pdef::proto::vec3f &obj);
bool vec2f(pdef::Stream &stream, pdef::proto::vec2f &obj);
bool MetadataDictionary(pdef::Stream &stream, pdef::proto::MetadataDictionary &obj);
bool Link(pdef::Stream &stream, pdef::proto::Link &obj);
bool EntityAttributes(pdef::Stream &stream, pdef::proto::EntityAttributes &obj);
bool Rotation(pdef::Stream &stream, pdef::proto::Rotation &obj);
bool BlockCoordinates(pdef::Stream &stream, pdef::proto::BlockCoordinates &obj);
bool PlayerAttributes(pdef::Stream &stream, pdef::proto::PlayerAttributes &obj);
bool TransactionUseItem(pdef::Stream &stream, pdef::proto::TransactionUseItem &obj);
bool TransactionActions(pdef::Stream &stream, pdef::proto::TransactionActions &obj);
bool TransactionLegacy(pdef::Stream &stream, pdef::proto::TransactionLegacy &obj);
bool Transaction(pdef::Stream &stream, pdef::proto::Transaction &obj);
bool RecipeIngredient(pdef::Stream &stream, pdef::proto::RecipeIngredient &obj);
bool PotionTypeRecipes(pdef::Stream &stream, pdef::proto::PotionTypeRecipes &obj);
bool PotionContainerChangeRecipes(pdef::Stream &stream, pdef::proto::PotionContainerChangeRecipes &obj);
bool Recipes(pdef::Stream &stream, pdef::proto::Recipes &obj);
bool SkinImage(pdef::Stream &stream, pdef::proto::SkinImage &obj);
bool Skin(pdef::Stream &stream, pdef::proto::Skin &obj);
bool PlayerRecords(pdef::Stream &stream, pdef::proto::PlayerRecords &obj);
bool Enchant(pdef::Stream &stream, pdef::proto::Enchant &obj);
bool EnchantOption(pdef::Stream &stream, pdef::proto::EnchantOption &obj);
bool StackRequestSlotInfo(pdef::Stream &stream, pdef::proto::StackRequestSlotInfo &obj);
bool ItemStackRequest(pdef::Stream &stream, pdef::proto::ItemStackRequest &obj);
bool ItemStackResponses(pdef::Stream &stream, pdef::proto::ItemStackResponses &obj);
bool ItemComponentList(pdef::Stream &stream, pdef::proto::ItemComponentList &obj);
bool CommandOrigin(pdef::Stream &stream, pdef::proto::CommandOrigin &obj);
bool TrackedObject(pdef::Stream &stream, pdef::proto::TrackedObject &obj);
bool MapDecoration(pdef::Stream &stream, pdef::proto::MapDecoration &obj);
bool StructureBlockSettings(pdef::Stream &stream, pdef::proto::StructureBlockSettings &obj);
bool EducationSharedResourceURI(pdef::Stream &stream, pdef::proto::EducationSharedResourceURI &obj);
bool EducationExternalLinkSettings(pdef::Stream &stream, pdef::proto::EducationExternalLinkSettings &obj);
bool BlockUpdate(pdef::Stream &stream, pdef::proto::BlockUpdate &obj);
bool MaterialReducer(pdef::Stream &stream, pdef::proto::MaterialReducer &obj);
bool packet_login(pdef::Stream &stream, pdef::proto::packet_login &obj);
bool LoginTokens(pdef::Stream &stream, pdef::proto::LoginTokens &obj);
bool packet_play_status(pdef::Stream &stream, pdef::proto::packet_play_status &obj);
bool packet_server_to_client_handshake(pdef::Stream &stream, pdef::proto::packet_server_to_client_handshake &obj);
bool packet_client_to_server_handshake(pdef::Stream &stream, pdef::proto::packet_client_to_server_handshake &obj);
bool packet_disconnect(pdef::Stream &stream, pdef::proto::packet_disconnect &obj);
bool packet_resource_packs_info(pdef::Stream &stream, pdef::proto::packet_resource_packs_info &obj);
bool packet_resource_pack_stack(pdef::Stream &stream, pdef::proto::packet_resource_pack_stack &obj);
bool packet_resource_pack_client_response(pdef::Stream &stream, pdef::proto::packet_resource_pack_client_response &obj);
bool packet_text(pdef::Stream &stream, pdef::proto::packet_text &obj);
bool packet_set_time(pdef::Stream &stream, pdef::proto::packet_set_time &obj);
bool packet_start_game(pdef::Stream &stream, pdef::proto::packet_start_game &obj);
bool packet_add_player(pdef::Stream &stream, pdef::proto::packet_add_player &obj);
bool packet_add_entity(pdef::Stream &stream, pdef::proto::packet_add_entity &obj);
bool packet_remove_entity(pdef::Stream &stream, pdef::proto::packet_remove_entity &obj);
bool packet_add_item_entity(pdef::Stream &stream, pdef::proto::packet_add_item_entity &obj);
bool packet_take_item_entity(pdef::Stream &stream, pdef::proto::packet_take_item_entity &obj);
bool packet_move_entity(pdef::Stream &stream, pdef::proto::packet_move_entity &obj);
bool packet_move_player(pdef::Stream &stream, pdef::proto::packet_move_player &obj);
bool packet_rider_jump(pdef::Stream &stream, pdef::proto::packet_rider_jump &obj);
bool packet_update_block(pdef::Stream &stream, pdef::proto::packet_update_block &obj);
bool packet_add_painting(pdef::Stream &stream, pdef::proto::packet_add_painting &obj);
bool packet_tick_sync(pdef::Stream &stream, pdef::proto::packet_tick_sync &obj);
bool packet_level_sound_event_old(pdef::Stream &stream, pdef::proto::packet_level_sound_event_old &obj);
bool packet_level_event(pdef::Stream &stream, pdef::proto::packet_level_event &obj);
bool packet_block_event(pdef::Stream &stream, pdef::proto::packet_block_event &obj);
bool packet_entity_event(pdef::Stream &stream, pdef::proto::packet_entity_event &obj);
bool packet_mob_effect(pdef::Stream &stream, pdef::proto::packet_mob_effect &obj);
bool packet_update_attributes(pdef::Stream &stream, pdef::proto::packet_update_attributes &obj);
bool packet_inventory_transaction(pdef::Stream &stream, pdef::proto::packet_inventory_transaction &obj);
bool packet_mob_equipment(pdef::Stream &stream, pdef::proto::packet_mob_equipment &obj);
bool packet_mob_armor_equipment(pdef::Stream &stream, pdef::proto::packet_mob_armor_equipment &obj);
bool packet_interact(pdef::Stream &stream, pdef::proto::packet_interact &obj);
bool packet_block_pick_request(pdef::Stream &stream, pdef::proto::packet_block_pick_request &obj);
bool packet_entity_pick_request(pdef::Stream &stream, pdef::proto::packet_entity_pick_request &obj);
bool packet_player_action(pdef::Stream &stream, pdef::proto::packet_player_action &obj);
bool packet_hurt_armor(pdef::Stream &stream, pdef::proto::packet_hurt_armor &obj);
bool packet_set_entity_data(pdef::Stream &stream, pdef::proto::packet_set_entity_data &obj);
bool packet_set_entity_motion(pdef::Stream &stream, pdef::proto::packet_set_entity_motion &obj);
bool packet_set_entity_link(pdef::Stream &stream, pdef::proto::packet_set_entity_link &obj);
bool packet_set_health(pdef::Stream &stream, pdef::proto::packet_set_health &obj);
bool packet_set_spawn_position(pdef::Stream &stream, pdef::proto::packet_set_spawn_position &obj);
bool packet_animate(pdef::Stream &stream, pdef::proto::packet_animate &obj);
bool packet_respawn(pdef::Stream &stream, pdef::proto::packet_respawn &obj);
bool packet_container_open(pdef::Stream &stream, pdef::proto::packet_container_open &obj);
bool packet_container_close(pdef::Stream &stream, pdef::proto::packet_container_close &obj);
bool packet_player_hotbar(pdef::Stream &stream, pdef::proto::packet_player_hotbar &obj);
bool packet_inventory_content(pdef::Stream &stream, pdef::proto::packet_inventory_content &obj);
bool packet_inventory_slot(pdef::Stream &stream, pdef::proto::packet_inventory_slot &obj);
bool packet_container_set_data(pdef::Stream &stream, pdef::proto::packet_container_set_data &obj);
bool packet_crafting_data(pdef::Stream &stream, pdef::proto::packet_crafting_data &obj);
bool packet_crafting_event(pdef::Stream &stream, pdef::proto::packet_crafting_event &obj);
bool packet_gui_data_pick_item(pdef::Stream &stream, pdef::proto::packet_gui_data_pick_item &obj);
bool packet_adventure_settings(pdef::Stream &stream, pdef::proto::packet_adventure_settings &obj);
bool packet_block_entity_data(pdef::Stream &stream, pdef::proto::packet_block_entity_data &obj);
bool packet_player_input(pdef::Stream &stream, pdef::proto::packet_player_input &obj);
bool packet_level_chunk(pdef::Stream &stream, pdef::proto::packet_level_chunk &obj);
bool packet_set_commands_enabled(pdef::Stream &stream, pdef::proto::packet_set_commands_enabled &obj);
bool packet_set_difficulty(pdef::Stream &stream, pdef::proto::packet_set_difficulty &obj);
bool packet_change_dimension(pdef::Stream &stream, pdef::proto::packet_change_dimension &obj);
bool packet_set_player_game_type(pdef::Stream &stream, pdef::proto::packet_set_player_game_type &obj);
bool packet_player_list(pdef::Stream &stream, pdef::proto::packet_player_list &obj);
bool packet_simple_event(pdef::Stream &stream, pdef::proto::packet_simple_event &obj);
bool packet_event(pdef::Stream &stream, pdef::proto::packet_event &obj);
bool packet_spawn_experience_orb(pdef::Stream &stream, pdef::proto::packet_spawn_experience_orb &obj);
bool packet_clientbound_map_item_data(pdef::Stream &stream, pdef::proto::packet_clientbound_map_item_data &obj);
bool packet_map_info_request(pdef::Stream &stream, pdef::proto::packet_map_info_request &obj);
bool packet_request_chunk_radius(pdef::Stream &stream, pdef::proto::packet_request_chunk_radius &obj);
bool packet_chunk_radius_update(pdef::Stream &stream, pdef::proto::packet_chunk_radius_update &obj);
bool packet_item_frame_drop_item(pdef::Stream &stream, pdef::proto::packet_item_frame_drop_item &obj);
bool packet_game_rules_changed(pdef::Stream &stream, pdef::proto::packet_game_rules_changed &obj);
bool packet_camera(pdef::Stream &stream, pdef::proto::packet_camera &obj);
bool packet_boss_event(pdef::Stream &stream, pdef::proto::packet_boss_event &obj);
bool packet_show_credits(pdef::Stream &stream, pdef::proto::packet_show_credits &obj);
bool packet_available_commands(pdef::Stream &stream, pdef::proto::packet_available_commands &obj);
bool packet_command_request(pdef::Stream &stream, pdef::proto::packet_command_request &obj);
bool packet_command_block_update(pdef::Stream &stream, pdef::proto::packet_command_block_update &obj);
bool packet_command_output(pdef::Stream &stream, pdef::proto::packet_command_output &obj);
bool packet_update_trade(pdef::Stream &stream, pdef::proto::packet_update_trade &obj);
bool packet_update_equipment(pdef::Stream &stream, pdef::proto::packet_update_equipment &obj);
bool packet_resource_pack_data_info(pdef::Stream &stream, pdef::proto::packet_resource_pack_data_info &obj);
bool packet_resource_pack_chunk_data(pdef::Stream &stream, pdef::proto::packet_resource_pack_chunk_data &obj);
bool packet_resource_pack_chunk_request(pdef::Stream &stream, pdef::proto::packet_resource_pack_chunk_request &obj);
bool packet_transfer(pdef::Stream &stream, pdef::proto::packet_transfer &obj);
bool packet_play_sound(pdef::Stream &stream, pdef::proto::packet_play_sound &obj);
bool packet_stop_sound(pdef::Stream &stream, pdef::proto::packet_stop_sound &obj);
bool packet_set_title(pdef::Stream &stream, pdef::proto::packet_set_title &obj);
bool packet_add_behavior_tree(pdef::Stream &stream, pdef::proto::packet_add_behavior_tree &obj);
bool packet_structure_block_update(pdef::Stream &stream, pdef::proto::packet_structure_block_update &obj);
bool packet_show_store_offer(pdef::Stream &stream, pdef::proto::packet_show_store_offer &obj);
bool packet_purchase_receipt(pdef::Stream &stream, pdef::proto::packet_purchase_receipt &obj);
bool packet_player_skin(pdef::Stream &stream, pdef::proto::packet_player_skin &obj);
bool packet_sub_client_login(pdef::Stream &stream, pdef::proto::packet_sub_client_login &obj);
bool packet_initiate_web_socket_connection(pdef::Stream &stream, pdef::proto::packet_initiate_web_socket_connection &obj);
bool packet_set_last_hurt_by(pdef::Stream &stream, pdef::proto::packet_set_last_hurt_by &obj);
bool packet_book_edit(pdef::Stream &stream, pdef::proto::packet_book_edit &obj);
bool packet_npc_request(pdef::Stream &stream, pdef::proto::packet_npc_request &obj);
bool packet_photo_transfer(pdef::Stream &stream, pdef::proto::packet_photo_transfer &obj);
bool packet_modal_form_request(pdef::Stream &stream, pdef::proto::packet_modal_form_request &obj);
bool packet_modal_form_response(pdef::Stream &stream, pdef::proto::packet_modal_form_response &obj);
bool packet_server_settings_request(pdef::Stream &stream, pdef::proto::packet_server_settings_request &obj);
bool packet_server_settings_response(pdef::Stream &stream, pdef::proto::packet_server_settings_response &obj);
bool packet_show_profile(pdef::Stream &stream, pdef::proto::packet_show_profile &obj);
bool packet_set_default_game_type(pdef::Stream &stream, pdef::proto::packet_set_default_game_type &obj);
bool packet_remove_objective(pdef::Stream &stream, pdef::proto::packet_remove_objective &obj);
bool packet_set_display_objective(pdef::Stream &stream, pdef::proto::packet_set_display_objective &obj);
bool packet_set_score(pdef::Stream &stream, pdef::proto::packet_set_score &obj);
bool packet_lab_table(pdef::Stream &stream, pdef::proto::packet_lab_table &obj);
bool packet_update_block_synced(pdef::Stream &stream, pdef::proto::packet_update_block_synced &obj);
bool packet_move_entity_delta(pdef::Stream &stream, pdef::proto::packet_move_entity_delta &obj);
bool packet_set_scoreboard_identity(pdef::Stream &stream, pdef::proto::packet_set_scoreboard_identity &obj);
bool packet_set_local_player_as_initialized(pdef::Stream &stream, pdef::proto::packet_set_local_player_as_initialized &obj);
bool packet_update_soft_enum(pdef::Stream &stream, pdef::proto::packet_update_soft_enum &obj);
bool packet_network_stack_latency(pdef::Stream &stream, pdef::proto::packet_network_stack_latency &obj);
bool packet_script_custom_event(pdef::Stream &stream, pdef::proto::packet_script_custom_event &obj);
bool packet_spawn_particle_effect(pdef::Stream &stream, pdef::proto::packet_spawn_particle_effect &obj);
bool packet_available_entity_identifiers(pdef::Stream &stream, pdef::proto::packet_available_entity_identifiers &obj);
bool packet_level_sound_event_v2(pdef::Stream &stream, pdef::proto::packet_level_sound_event_v2 &obj);
bool packet_network_chunk_publisher_update(pdef::Stream &stream, pdef::proto::packet_network_chunk_publisher_update &obj);
bool packet_biome_definition_list(pdef::Stream &stream, pdef::proto::packet_biome_definition_list &obj);
bool packet_level_sound_event(pdef::Stream &stream, pdef::proto::packet_level_sound_event &obj);
bool packet_level_event_generic(pdef::Stream &stream, pdef::proto::packet_level_event_generic &obj);
bool packet_lectern_update(pdef::Stream &stream, pdef::proto::packet_lectern_update &obj);
bool packet_video_stream_connect(pdef::Stream &stream, pdef::proto::packet_video_stream_connect &obj);
bool packet_add_ecs_entity(pdef::Stream &stream, pdef::proto::packet_add_ecs_entity &obj);
bool packet_remove_ecs_entity(pdef::Stream &stream, pdef::proto::packet_remove_ecs_entity &obj);
bool packet_client_cache_status(pdef::Stream &stream, pdef::proto::packet_client_cache_status &obj);
bool packet_on_screen_texture_animation(pdef::Stream &stream, pdef::proto::packet_on_screen_texture_animation &obj);
bool packet_map_create_locked_copy(pdef::Stream &stream, pdef::proto::packet_map_create_locked_copy &obj);
bool packet_structure_template_data_export_request(pdef::Stream &stream, pdef::proto::packet_structure_template_data_export_request &obj);
bool packet_structure_template_data_export_response(pdef::Stream &stream, pdef::proto::packet_structure_template_data_export_response &obj);
bool packet_update_block_properties(pdef::Stream &stream, pdef::proto::packet_update_block_properties &obj);
bool packet_client_cache_blob_status(pdef::Stream &stream, pdef::proto::packet_client_cache_blob_status &obj);
bool packet_client_cache_miss_response(pdef::Stream &stream, pdef::proto::packet_client_cache_miss_response &obj);
bool packet_education_settings(pdef::Stream &stream, pdef::proto::packet_education_settings &obj);
bool packet_emote(pdef::Stream &stream, pdef::proto::packet_emote &obj);
bool packet_multiplayer_settings(pdef::Stream &stream, pdef::proto::packet_multiplayer_settings &obj);
bool packet_settings_command(pdef::Stream &stream, pdef::proto::packet_settings_command &obj);
bool packet_anvil_damage(pdef::Stream &stream, pdef::proto::packet_anvil_damage &obj);
bool packet_completed_using_item(pdef::Stream &stream, pdef::proto::packet_completed_using_item &obj);
bool packet_network_settings(pdef::Stream &stream, pdef::proto::packet_network_settings &obj);
bool packet_player_auth_input(pdef::Stream &stream, pdef::proto::packet_player_auth_input &obj);
bool packet_creative_content(pdef::Stream &stream, pdef::proto::packet_creative_content &obj);
bool packet_player_enchant_options(pdef::Stream &stream, pdef::proto::packet_player_enchant_options &obj);
bool packet_item_stack_request(pdef::Stream &stream, pdef::proto::packet_item_stack_request &obj);
bool packet_item_stack_response(pdef::Stream &stream, pdef::proto::packet_item_stack_response &obj);
bool packet_player_armor_damage(pdef::Stream &stream, pdef::proto::packet_player_armor_damage &obj);
bool packet_update_player_game_type(pdef::Stream &stream, pdef::proto::packet_update_player_game_type &obj);
bool packet_emote_list(pdef::Stream &stream, pdef::proto::packet_emote_list &obj);
bool packet_position_tracking_db_request(pdef::Stream &stream, pdef::proto::packet_position_tracking_db_request &obj);
bool packet_position_tracking_db_broadcast(pdef::Stream &stream, pdef::proto::packet_position_tracking_db_broadcast &obj);
bool packet_packet_violation_warning(pdef::Stream &stream, pdef::proto::packet_packet_violation_warning &obj);
bool packet_motion_prediction_hints(pdef::Stream &stream, pdef::proto::packet_motion_prediction_hints &obj);
bool packet_animate_entity(pdef::Stream &stream, pdef::proto::packet_animate_entity &obj);
bool packet_camera_shake(pdef::Stream &stream, pdef::proto::packet_camera_shake &obj);
bool packet_player_fog(pdef::Stream &stream, pdef::proto::packet_player_fog &obj);
bool packet_correct_player_move_prediction(pdef::Stream &stream, pdef::proto::packet_correct_player_move_prediction &obj);
bool packet_item_component(pdef::Stream &stream, pdef::proto::packet_item_component &obj);
bool packet_filter_text_packet(pdef::Stream &stream, pdef::proto::packet_filter_text_packet &obj);
bool packet_debug_renderer(pdef::Stream &stream, pdef::proto::packet_debug_renderer &obj);
bool packet_sync_entity_property(pdef::Stream &stream, pdef::proto::packet_sync_entity_property &obj);
bool packet_add_volume_entity(pdef::Stream &stream, pdef::proto::packet_add_volume_entity &obj);
bool packet_remove_volume_entity(pdef::Stream &stream, pdef::proto::packet_remove_volume_entity &obj);
bool packet_simulation_type(pdef::Stream &stream, pdef::proto::packet_simulation_type &obj);
bool packet_npc_dialogue(pdef::Stream &stream, pdef::proto::packet_npc_dialogue &obj);
bool packet_edu_uri_resource_packet(pdef::Stream &stream, pdef::proto::packet_edu_uri_resource_packet &obj);
bool packet_create_photo(pdef::Stream &stream, pdef::proto::packet_create_photo &obj);
bool packet_update_subchunk_blocks(pdef::Stream &stream, pdef::proto::packet_update_subchunk_blocks &obj);
bool packet_photo_info_request(pdef::Stream &stream, pdef::proto::packet_photo_info_request &obj);
bool SubChunkEntryWithoutCaching(pdef::Stream &stream, pdef::proto::SubChunkEntryWithoutCaching &obj);
bool SubChunkEntryWithCaching(pdef::Stream &stream, pdef::proto::SubChunkEntryWithCaching &obj);
bool packet_subchunk(pdef::Stream &stream, pdef::proto::packet_subchunk &obj);
bool packet_subchunk_request(pdef::Stream &stream, pdef::proto::packet_subchunk_request &obj);
bool packet_client_start_item_cooldown(pdef::Stream &stream, pdef::proto::packet_client_start_item_cooldown &obj);
bool packet_script_message(pdef::Stream &stream, pdef::proto::packet_script_message &obj);
bool packet_code_builder_source(pdef::Stream &stream, pdef::proto::packet_code_builder_source &obj);
bool packet_ticking_areas_load_status(pdef::Stream &stream, pdef::proto::packet_ticking_areas_load_status &obj);
bool packet_dimension_data(pdef::Stream &stream, pdef::proto::packet_dimension_data &obj);
bool packet_agent_action(pdef::Stream &stream, pdef::proto::packet_agent_action &obj);
bool packet_change_mob_property(pdef::Stream &stream, pdef::proto::packet_change_mob_property &obj);
bool packet_lesson_progress(pdef::Stream &stream, pdef::proto::packet_lesson_progress &obj);
bool packet_request_ability(pdef::Stream &stream, pdef::proto::packet_request_ability &obj);
bool packet_request_permissions(pdef::Stream &stream, pdef::proto::packet_request_permissions &obj);
bool packet_toast_request(pdef::Stream &stream, pdef::proto::packet_toast_request &obj);
bool mcpe_packet(pdef::Stream &stream, pdef::proto::mcpe_packet &obj);
bool BehaviourPackInfos(pdef::Stream &stream, pdef::proto::BehaviourPackInfos &obj) {
    int uuid_strlen; READ_OR_BAIL(readUnsignedVarInt, uuid_strlen);
    if (!stream.readString(obj.uuid, uuid_strlen)) return false; /*uuid: pstring*/ /*4.3*/
    int version_strlen; READ_OR_BAIL(readUnsignedVarInt, version_strlen);
    if (!stream.readString(obj.version, version_strlen)) return false; /*version: pstring*/ /*4.3*/
    READ_OR_BAIL(readULongLE, obj.size); /*0.5*/
    int content_key_strlen; READ_OR_BAIL(readUnsignedVarInt, content_key_strlen);
    if (!stream.readString(obj.content_key, content_key_strlen)) return false; /*content_key: pstring*/ /*4.3*/
    int sub_pack_name_strlen; READ_OR_BAIL(readUnsignedVarInt, sub_pack_name_strlen);
    if (!stream.readString(obj.sub_pack_name, sub_pack_name_strlen)) return false; /*sub_pack_name: pstring*/ /*4.3*/
    int content_identity_strlen; READ_OR_BAIL(readUnsignedVarInt, content_identity_strlen);
    if (!stream.readString(obj.content_identity, content_identity_strlen)) return false; /*content_identity: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.has_scripts); /*0.5*/
  return true;
}
bool TexturePackInfos(pdef::Stream &stream, pdef::proto::TexturePackInfos &obj) {
    int uuid_strlen; READ_OR_BAIL(readUnsignedVarInt, uuid_strlen);
    if (!stream.readString(obj.uuid, uuid_strlen)) return false; /*uuid: pstring*/ /*4.3*/
    int version_strlen; READ_OR_BAIL(readUnsignedVarInt, version_strlen);
    if (!stream.readString(obj.version, version_strlen)) return false; /*version: pstring*/ /*4.3*/
    READ_OR_BAIL(readULongLE, obj.size); /*0.5*/
    int content_key_strlen; READ_OR_BAIL(readUnsignedVarInt, content_key_strlen);
    if (!stream.readString(obj.content_key, content_key_strlen)) return false; /*content_key: pstring*/ /*4.3*/
    int sub_pack_name_strlen; READ_OR_BAIL(readUnsignedVarInt, sub_pack_name_strlen);
    if (!stream.readString(obj.sub_pack_name, sub_pack_name_strlen)) return false; /*sub_pack_name: pstring*/ /*4.3*/
    int content_identity_strlen; READ_OR_BAIL(readUnsignedVarInt, content_identity_strlen);
    if (!stream.readString(obj.content_identity, content_identity_strlen)) return false; /*content_identity: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.has_scripts); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.rtx_enabled); /*0.5*/
  return true;
}
bool ResourcePackIdVersions(pdef::Stream &stream, pdef::proto::ResourcePackIdVersions &obj) {
    int uuid_strlen; READ_OR_BAIL(readUnsignedVarInt, uuid_strlen);
    if (!stream.readString(obj.uuid, uuid_strlen)) return false; /*uuid: pstring*/ /*4.3*/
    int version_strlen; READ_OR_BAIL(readUnsignedVarInt, version_strlen);
    if (!stream.readString(obj.version, version_strlen)) return false; /*version: pstring*/ /*4.3*/
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
  return true;
}
  bool Experiment(pdef::Stream &stream, pdef::proto::Experiment &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.enabled); /*0.5*/
    return true;
  }
  bool GameRule(pdef::Stream &stream, pdef::proto::GameRule &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.editable); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.type); /*7.2*/
    const pdef::proto::GameRule::Type &type = obj.type; /*0.7*/
    switch (type) { /*8.0*/
      case pdef::proto::GameRule::Type::Bool: { /*8.5*/
        READ_OR_BAIL(readBool, (bool&)obj.value_bool); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::GameRule::Type::Int: { /*8.5*/
        READ_OR_BAIL(readZigZagVarInt, obj.value_zigzag32); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::GameRule::Type::Float: { /*8.5*/
        READ_OR_BAIL(readFloatLE, obj.value_lf32); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool Blob(pdef::Stream &stream, pdef::proto::Blob &obj) {
    READ_OR_BAIL(readULongLE, obj.hash); /*0.5*/
    int payload_len; READ_OR_BAIL(readUnsignedVarInt, payload_len);if (!stream.readBuffer(obj.payload, payload_len)) return false; /*payload: buffer*/ /*4.3*/
    return true;
  }
bool BlockProperties(pdef::Stream &stream, pdef::proto::BlockProperties &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.state); /*0.5*/
  return true;
}
bool Itemstates(pdef::Stream &stream, pdef::proto::Itemstates &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readShortLE, obj.runtime_id); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.component_based); /*0.5*/
  return true;
}
  bool ItemExtraDataWithBlockingTick(pdef::Stream &stream, pdef::proto::ItemExtraDataWithBlockingTick &obj) {
    READ_OR_BAIL(readUShortLE, (uint16_t&)obj.has_nbt); /*7.2*/
    const pdef::proto::ItemExtraDataWithBlockingTick::HasNbt &has_nbt = obj.has_nbt; /*0.7*/
    switch (has_nbt) { /*8.0*/
      case pdef::proto::ItemExtraDataWithBlockingTick::HasNbt::True: { /*8.5*/
         obj.nbt = {}; pdef::proto::ItemExtraDataWithBlockingTick::Nbt &v = *obj.nbt; /*8.4*/
          READ_OR_BAIL(readUByte, v.version); /*0.5*/
          READ_OR_BAIL(readByte, v.nbt); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    int32_t can_place_on_len; READ_OR_BAIL(readIntLE, can_place_on_len); /*1.5*/
    obj.can_place_on.resize(can_place_on_len); /*1.6*/
    for (int i = 0; i < can_place_on_len; i++) {
      auto &v2 = obj.can_place_on[i]; /*3.4*/
      int16_t _strlen; READ_OR_BAIL(readShortLE, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    int32_t can_destroy_len; READ_OR_BAIL(readIntLE, can_destroy_len); /*1.5*/
    obj.can_destroy.resize(can_destroy_len); /*1.6*/
    for (int i = 0; i < can_destroy_len; i++) {
      auto &v2 = obj.can_destroy[i]; /*3.4*/
      int16_t _strlen; READ_OR_BAIL(readShortLE, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    READ_OR_BAIL(readLongLE, obj.blocking_tick); /*0.5*/
    return true;
  }
  bool ItemExtraDataWithoutBlockingTick(pdef::Stream &stream, pdef::proto::ItemExtraDataWithoutBlockingTick &obj) {
    READ_OR_BAIL(readUShortLE, (uint16_t&)obj.has_nbt); /*7.2*/
    const pdef::proto::ItemExtraDataWithoutBlockingTick::HasNbt &has_nbt = obj.has_nbt; /*0.7*/
    switch (has_nbt) { /*8.0*/
      case pdef::proto::ItemExtraDataWithoutBlockingTick::HasNbt::True: { /*8.5*/
         obj.nbt = {}; pdef::proto::ItemExtraDataWithoutBlockingTick::Nbt &v = *obj.nbt; /*8.4*/
          READ_OR_BAIL(readUByte, v.version); /*0.5*/
          READ_OR_BAIL(readByte, v.nbt); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    int32_t can_place_on_len; READ_OR_BAIL(readIntLE, can_place_on_len); /*1.5*/
    obj.can_place_on.resize(can_place_on_len); /*1.6*/
    for (int i = 0; i < can_place_on_len; i++) {
      auto &v2 = obj.can_place_on[i]; /*3.4*/
      int16_t _strlen; READ_OR_BAIL(readShortLE, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    int32_t can_destroy_len; READ_OR_BAIL(readIntLE, can_destroy_len); /*1.5*/
    obj.can_destroy.resize(can_destroy_len); /*1.6*/
    for (int i = 0; i < can_destroy_len; i++) {
      auto &v2 = obj.can_destroy[i]; /*3.4*/
      int16_t _strlen; READ_OR_BAIL(readShortLE, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    return true;
  }
  bool ItemLegacy(pdef::Stream &stream, pdef::proto::ItemLegacy &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.network_id); /*0.5*/
    int &network_id = obj.network_id; /*0.6*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        READ_OR_BAIL(readUShortLE, obj.count); /*0.5*/
        READ_OR_BAIL(readUnsignedVarInt, obj.metadata); /*0.5*/
        READ_OR_BAIL(readZigZagVarInt, obj.block_runtime_id); /*0.5*/
        if (network_id == pdef::proto::ShieldItemID) { /*8.4*/
          READ_OR_BAIL(readByte, obj.extra__ShieldItemID); /*0.5*/
        }
        else {
          READ_OR_BAIL(readByte, obj.extra_default); /*0.5*/
        }
    }
    return true;
  }
  bool Item(pdef::Stream &stream, pdef::proto::Item &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.network_id); /*0.5*/
    int &network_id = obj.network_id; /*0.6*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        READ_OR_BAIL(readUShortLE, obj.count); /*0.5*/
        READ_OR_BAIL(readUnsignedVarInt, obj.metadata); /*0.5*/
        READ_OR_BAIL(readUByte, obj.has_stack_id); /*0.5*/
        uint8_t &has_stack_id = obj.has_stack_id; /*0.6*/
        if (has_stack_id == 0) { /*8.2*/
        }
        else {
          READ_OR_BAIL(readZigZagVarInt, obj.stack_id); /*0.5*/
        }
        READ_OR_BAIL(readZigZagVarInt, obj.block_runtime_id); /*0.5*/
        if (network_id == pdef::proto::ShieldItemID) { /*8.4*/
          READ_OR_BAIL(readByte, obj.extra__ShieldItemID); /*0.5*/
        }
        else {
          READ_OR_BAIL(readByte, obj.extra_default); /*0.5*/
        }
    }
    return true;
  }
  bool vec3i(pdef::Stream &stream, pdef::proto::vec3i &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.x); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.y); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.z); /*0.5*/
    return true;
  }
  bool vec3u(pdef::Stream &stream, pdef::proto::vec3u &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.x); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.y); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.z); /*0.5*/
    return true;
  }
  bool vec3f(pdef::Stream &stream, pdef::proto::vec3f &obj) {
    READ_OR_BAIL(readFloatLE, obj.x); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.y); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.z); /*0.5*/
    return true;
  }
  bool vec2f(pdef::Stream &stream, pdef::proto::vec2f &obj) {
    READ_OR_BAIL(readFloatLE, obj.x); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.z); /*0.5*/
    return true;
  }
bool MetadataDictionary(pdef::Stream &stream, pdef::proto::MetadataDictionary &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.key); /*7.2*/
    const pdef::proto::MetadataDictionary::Key &key = obj.key; /*0.7*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.type); /*7.2*/
    const pdef::proto::MetadataDictionary::Type &type = obj.type; /*0.7*/
    switch (key) { /*8.0*/
      case pdef::proto::MetadataDictionary::Key::Flags: { /*8.5*/
        int64_t value_MetadataFlags1_val;
        READ_OR_BAIL(readZigZagVarLong, value_MetadataFlags1_val);
        obj.value_MetadataFlags1.onfire = value_MetadataFlags1_val & ((int64_t)1 << 0);
        obj.value_MetadataFlags1.sneaking = value_MetadataFlags1_val & ((int64_t)1 << 1);
        obj.value_MetadataFlags1.riding = value_MetadataFlags1_val & ((int64_t)1 << 2);
        obj.value_MetadataFlags1.sprinting = value_MetadataFlags1_val & ((int64_t)1 << 3);
        obj.value_MetadataFlags1.action = value_MetadataFlags1_val & ((int64_t)1 << 4);
        obj.value_MetadataFlags1.invisible = value_MetadataFlags1_val & ((int64_t)1 << 5);
        obj.value_MetadataFlags1.tempted = value_MetadataFlags1_val & ((int64_t)1 << 6);
        obj.value_MetadataFlags1.inlove = value_MetadataFlags1_val & ((int64_t)1 << 7);
        obj.value_MetadataFlags1.saddled = value_MetadataFlags1_val & ((int64_t)1 << 8);
        obj.value_MetadataFlags1.powered = value_MetadataFlags1_val & ((int64_t)1 << 9);
        obj.value_MetadataFlags1.ignited = value_MetadataFlags1_val & ((int64_t)1 << 10);
        obj.value_MetadataFlags1.baby = value_MetadataFlags1_val & ((int64_t)1 << 11);
        obj.value_MetadataFlags1.converting = value_MetadataFlags1_val & ((int64_t)1 << 12);
        obj.value_MetadataFlags1.critical = value_MetadataFlags1_val & ((int64_t)1 << 13);
        obj.value_MetadataFlags1.can_show_nametag = value_MetadataFlags1_val & ((int64_t)1 << 14);
        obj.value_MetadataFlags1.always_show_nametag = value_MetadataFlags1_val & ((int64_t)1 << 15);
        obj.value_MetadataFlags1.no_ai = value_MetadataFlags1_val & ((int64_t)1 << 16);
        obj.value_MetadataFlags1.silent = value_MetadataFlags1_val & ((int64_t)1 << 17);
        obj.value_MetadataFlags1.wallclimbing = value_MetadataFlags1_val & ((int64_t)1 << 18);
        obj.value_MetadataFlags1.can_climb = value_MetadataFlags1_val & ((int64_t)1 << 19);
        obj.value_MetadataFlags1.swimmer = value_MetadataFlags1_val & ((int64_t)1 << 20);
        obj.value_MetadataFlags1.can_fly = value_MetadataFlags1_val & ((int64_t)1 << 21);
        obj.value_MetadataFlags1.walker = value_MetadataFlags1_val & ((int64_t)1 << 22);
        obj.value_MetadataFlags1.resting = value_MetadataFlags1_val & ((int64_t)1 << 23);
        obj.value_MetadataFlags1.sitting = value_MetadataFlags1_val & ((int64_t)1 << 24);
        obj.value_MetadataFlags1.angry = value_MetadataFlags1_val & ((int64_t)1 << 25);
        obj.value_MetadataFlags1.interested = value_MetadataFlags1_val & ((int64_t)1 << 26);
        obj.value_MetadataFlags1.charged = value_MetadataFlags1_val & ((int64_t)1 << 27);
        obj.value_MetadataFlags1.tamed = value_MetadataFlags1_val & ((int64_t)1 << 28);
        obj.value_MetadataFlags1.orphaned = value_MetadataFlags1_val & ((int64_t)1 << 29);
        obj.value_MetadataFlags1.leashed = value_MetadataFlags1_val & ((int64_t)1 << 30);
        obj.value_MetadataFlags1.sheared = value_MetadataFlags1_val & ((int64_t)1 << 31);
        obj.value_MetadataFlags1.gliding = value_MetadataFlags1_val & ((int64_t)1 << 32);
        obj.value_MetadataFlags1.elder = value_MetadataFlags1_val & ((int64_t)1 << 33);
        obj.value_MetadataFlags1.moving = value_MetadataFlags1_val & ((int64_t)1 << 34);
        obj.value_MetadataFlags1.breathing = value_MetadataFlags1_val & ((int64_t)1 << 35);
        obj.value_MetadataFlags1.chested = value_MetadataFlags1_val & ((int64_t)1 << 36);
        obj.value_MetadataFlags1.stackable = value_MetadataFlags1_val & ((int64_t)1 << 37);
        obj.value_MetadataFlags1.showbase = value_MetadataFlags1_val & ((int64_t)1 << 38);
        obj.value_MetadataFlags1.rearing = value_MetadataFlags1_val & ((int64_t)1 << 39);
        obj.value_MetadataFlags1.vibrating = value_MetadataFlags1_val & ((int64_t)1 << 40);
        obj.value_MetadataFlags1.idling = value_MetadataFlags1_val & ((int64_t)1 << 41);
        obj.value_MetadataFlags1.evoker_spell = value_MetadataFlags1_val & ((int64_t)1 << 42);
        obj.value_MetadataFlags1.charge_attack = value_MetadataFlags1_val & ((int64_t)1 << 43);
        obj.value_MetadataFlags1.wasd_controlled = value_MetadataFlags1_val & ((int64_t)1 << 44);
        obj.value_MetadataFlags1.can_power_jump = value_MetadataFlags1_val & ((int64_t)1 << 45);
        obj.value_MetadataFlags1.linger = value_MetadataFlags1_val & ((int64_t)1 << 46);
        obj.value_MetadataFlags1.has_collision = value_MetadataFlags1_val & ((int64_t)1 << 47);
        obj.value_MetadataFlags1.affected_by_gravity = value_MetadataFlags1_val & ((int64_t)1 << 48);
        obj.value_MetadataFlags1.fire_immune = value_MetadataFlags1_val & ((int64_t)1 << 49);
        obj.value_MetadataFlags1.dancing = value_MetadataFlags1_val & ((int64_t)1 << 50);
        obj.value_MetadataFlags1.enchanted = value_MetadataFlags1_val & ((int64_t)1 << 51);
        obj.value_MetadataFlags1.show_trident_rope = value_MetadataFlags1_val & ((int64_t)1 << 52);
        obj.value_MetadataFlags1.container_private = value_MetadataFlags1_val & ((int64_t)1 << 53);
        obj.value_MetadataFlags1.transforming = value_MetadataFlags1_val & ((int64_t)1 << 54);
        obj.value_MetadataFlags1.spin_attack = value_MetadataFlags1_val & ((int64_t)1 << 55);
        obj.value_MetadataFlags1.swimming = value_MetadataFlags1_val & ((int64_t)1 << 56);
        obj.value_MetadataFlags1.bribed = value_MetadataFlags1_val & ((int64_t)1 << 57);
        obj.value_MetadataFlags1.pregnant = value_MetadataFlags1_val & ((int64_t)1 << 58);
        obj.value_MetadataFlags1.laying_egg = value_MetadataFlags1_val & ((int64_t)1 << 59);
        obj.value_MetadataFlags1.rider_can_pick = value_MetadataFlags1_val & ((int64_t)1 << 60);
        obj.value_MetadataFlags1.transition_sitting = value_MetadataFlags1_val & ((int64_t)1 << 61);
        obj.value_MetadataFlags1.eating = value_MetadataFlags1_val & ((int64_t)1 << 62);
        obj.value_MetadataFlags1.laying_down = value_MetadataFlags1_val & ((int64_t)1 << 63); /*value_MetadataFlags1: bitflags*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::MetadataDictionary::Key::FlagsExtended: { /*8.5*/
        int64_t value_MetadataFlags2_val;
        READ_OR_BAIL(readZigZagVarLong, value_MetadataFlags2_val);
        obj.value_MetadataFlags2.sneezing = value_MetadataFlags2_val & ((int64_t)1 << 0);
        obj.value_MetadataFlags2.trusting = value_MetadataFlags2_val & ((int64_t)1 << 1);
        obj.value_MetadataFlags2.rolling = value_MetadataFlags2_val & ((int64_t)1 << 2);
        obj.value_MetadataFlags2.scared = value_MetadataFlags2_val & ((int64_t)1 << 3);
        obj.value_MetadataFlags2.in_scaffolding = value_MetadataFlags2_val & ((int64_t)1 << 4);
        obj.value_MetadataFlags2.over_scaffolding = value_MetadataFlags2_val & ((int64_t)1 << 5);
        obj.value_MetadataFlags2.fall_through_scaffolding = value_MetadataFlags2_val & ((int64_t)1 << 6);
        obj.value_MetadataFlags2.blocking = value_MetadataFlags2_val & ((int64_t)1 << 7);
        obj.value_MetadataFlags2.transition_blocking = value_MetadataFlags2_val & ((int64_t)1 << 8);
        obj.value_MetadataFlags2.blocked_using_shield = value_MetadataFlags2_val & ((int64_t)1 << 9);
        obj.value_MetadataFlags2.blocked_using_damaged_shield = value_MetadataFlags2_val & ((int64_t)1 << 10);
        obj.value_MetadataFlags2.sleeping = value_MetadataFlags2_val & ((int64_t)1 << 11);
        obj.value_MetadataFlags2.wants_to_wake = value_MetadataFlags2_val & ((int64_t)1 << 12);
        obj.value_MetadataFlags2.trade_interest = value_MetadataFlags2_val & ((int64_t)1 << 13);
        obj.value_MetadataFlags2.door_breaker = value_MetadataFlags2_val & ((int64_t)1 << 14);
        obj.value_MetadataFlags2.breaking_obstruction = value_MetadataFlags2_val & ((int64_t)1 << 15);
        obj.value_MetadataFlags2.door_opener = value_MetadataFlags2_val & ((int64_t)1 << 16);
        obj.value_MetadataFlags2.illager_captain = value_MetadataFlags2_val & ((int64_t)1 << 17);
        obj.value_MetadataFlags2.stunned = value_MetadataFlags2_val & ((int64_t)1 << 18);
        obj.value_MetadataFlags2.roaring = value_MetadataFlags2_val & ((int64_t)1 << 19);
        obj.value_MetadataFlags2.delayed_attacking = value_MetadataFlags2_val & ((int64_t)1 << 20);
        obj.value_MetadataFlags2.avoiding_mobs = value_MetadataFlags2_val & ((int64_t)1 << 21);
        obj.value_MetadataFlags2.avoiding_block = value_MetadataFlags2_val & ((int64_t)1 << 22);
        obj.value_MetadataFlags2.facing_target_to_range_attack = value_MetadataFlags2_val & ((int64_t)1 << 23);
        obj.value_MetadataFlags2.hidden_when_invisible = value_MetadataFlags2_val & ((int64_t)1 << 24);
        obj.value_MetadataFlags2.is_in_ui = value_MetadataFlags2_val & ((int64_t)1 << 25);
        obj.value_MetadataFlags2.stalking = value_MetadataFlags2_val & ((int64_t)1 << 26);
        obj.value_MetadataFlags2.emoting = value_MetadataFlags2_val & ((int64_t)1 << 27);
        obj.value_MetadataFlags2.celebrating = value_MetadataFlags2_val & ((int64_t)1 << 28);
        obj.value_MetadataFlags2.admiring = value_MetadataFlags2_val & ((int64_t)1 << 29);
        obj.value_MetadataFlags2.celebrating_special = value_MetadataFlags2_val & ((int64_t)1 << 30);
        obj.value_MetadataFlags2.unknown95 = value_MetadataFlags2_val & ((int64_t)1 << 31);
        obj.value_MetadataFlags2.ram_attack = value_MetadataFlags2_val & ((int64_t)1 << 32);
        obj.value_MetadataFlags2.playing_dead = value_MetadataFlags2_val & ((int64_t)1 << 33);
        obj.value_MetadataFlags2.in_ascendable_block = value_MetadataFlags2_val & ((int64_t)1 << 34);
        obj.value_MetadataFlags2.over_descendable_block = value_MetadataFlags2_val & ((int64_t)1 << 35);
        obj.value_MetadataFlags2.croaking = value_MetadataFlags2_val & ((int64_t)1 << 36);
        obj.value_MetadataFlags2.eat_mob = value_MetadataFlags2_val & ((int64_t)1 << 37);
        obj.value_MetadataFlags2.jump_goal_jump = value_MetadataFlags2_val & ((int64_t)1 << 38);
        obj.value_MetadataFlags2.emerging = value_MetadataFlags2_val & ((int64_t)1 << 39);
        obj.value_MetadataFlags2.sniffing = value_MetadataFlags2_val & ((int64_t)1 << 40);
        obj.value_MetadataFlags2.digging = value_MetadataFlags2_val & ((int64_t)1 << 41); /*value_MetadataFlags2: bitflags*/ /*4.3*/
        break;
      } /*8.7*/
      default: { /*8.3*/
        switch (type) { /*8.0*/
          case pdef::proto::MetadataDictionary::Type::Byte: { /*8.5*/
            READ_OR_BAIL(readByte, obj.value_i8); /*0.5*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Short: { /*8.5*/
            READ_OR_BAIL(readShortLE, obj.value_li16); /*0.5*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Int: { /*8.5*/
            READ_OR_BAIL(readZigZagVarInt, obj.value_zigzag32); /*0.5*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Float: { /*8.5*/
            READ_OR_BAIL(readFloatLE, obj.value_lf32); /*0.5*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::String: { /*8.5*/
            int value_string_strlen; READ_OR_BAIL(readUnsignedVarInt, value_string_strlen);
            if (!stream.readString(obj.value_string, value_string_strlen)) return false; /*value_string: pstring*/ /*4.3*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Compound: { /*8.5*/
            READ_OR_BAIL(readByte, obj.value_nbt); /*0.5*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Vec3i: { /*8.5*/
            obj.value_vec3i = {}; pdef::proto::decode::vec3i(stream, *obj.value_vec3i); /*obj*/ /*4.6*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Long: { /*8.5*/
            READ_OR_BAIL(readZigZagVarLong, obj.value_zigzag64); /*0.5*/
            break;
          } /*8.7*/
          case pdef::proto::MetadataDictionary::Type::Vec3f: { /*8.5*/
            obj.value_vec3f = {}; pdef::proto::decode::vec3f(stream, *obj.value_vec3f); /*obj*/ /*4.6*/
            break;
          } /*8.7*/
          default: break; /*avoid unhandled case warning*/
        } /*8.8*/
        break;
      } /*8.7*/
    } /*8.8*/
  return true;
}
  bool Link(pdef::Stream &stream, pdef::proto::Link &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.ridden_entity_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.rider_entity_id); /*0.5*/
    READ_OR_BAIL(readUByte, obj.type); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.immediate); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.rider_initiated); /*0.5*/
    return true;
  }
bool EntityAttributes(pdef::Stream &stream, pdef::proto::EntityAttributes &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readFloatLE, obj.min); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.value); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.max); /*0.5*/
  return true;
}
  bool Rotation(pdef::Stream &stream, pdef::proto::Rotation &obj) {
    READ_OR_BAIL(readByte, obj.yaw); /*0.5*/
    READ_OR_BAIL(readByte, obj.pitch); /*0.5*/
    READ_OR_BAIL(readByte, obj.head_yaw); /*0.5*/
    return true;
  }
  bool BlockCoordinates(pdef::Stream &stream, pdef::proto::BlockCoordinates &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.x); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.y); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.z); /*0.5*/
    return true;
  }
bool PlayerAttributes(pdef::Stream &stream, pdef::proto::PlayerAttributes &obj) {
    READ_OR_BAIL(readFloatLE, obj.min); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.max); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.current); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.default_); /*0.5*/
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
  return true;
}
  bool TransactionUseItem(pdef::Stream &stream, pdef::proto::TransactionUseItem &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.action_type); /*7.2*/
    pdef::proto::decode::BlockCoordinates(stream, obj.block_position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.face); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.hotbar_slot); /*0.5*/
    pdef::proto::decode::Item(stream, obj.held_item); /*obj*/ /*4.6*/
    pdef::proto::decode::vec3f(stream, obj.player_pos); /*obj*/ /*4.6*/
    pdef::proto::decode::vec3f(stream, obj.click_pos); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUnsignedVarInt, obj.block_runtime_id); /*0.5*/
    return true;
  }
bool TransactionActions(pdef::Stream &stream, pdef::proto::TransactionActions &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.source_type); /*7.2*/
    const pdef::proto::TransactionActions::SourceType &source_type = obj.source_type; /*0.7*/
    switch (source_type) { /*8.0*/
      case pdef::proto::TransactionActions::SourceType::Container: { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, (int&)obj.inventory_id); /*7.2*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::Craft: { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::WorldInteraction: { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.flags); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::TransactionActions::SourceType::CraftSlot: { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.action); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    READ_OR_BAIL(readUnsignedVarInt, obj.slot); /*0.5*/
    pdef::proto::decode::Item(stream, obj.old_item); /*obj*/ /*4.6*/
    pdef::proto::decode::Item(stream, obj.new_item); /*obj*/ /*4.6*/
  return true;
}
  bool TransactionLegacy(pdef::Stream &stream, pdef::proto::TransactionLegacy &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.legacy_request_id); /*0.5*/
    int &legacy_request_id = obj.legacy_request_id; /*0.6*/
    if (legacy_request_id == 0) { /*8.2*/
    }
    else {
      int legacy_transactions_len; READ_OR_BAIL(readUnsignedVarInt, legacy_transactions_len); /*1.5*/
      obj.legacy_transactions.resize(legacy_transactions_len); /*1.6*/
      for (int i = 0; i < legacy_transactions_len; i++) { /*5*/
        pdef::proto::TransactionLegacy::LegacyTransactions &v3 = obj.legacy_transactions[i]; /*5.23*/
        READ_OR_BAIL(readUByte, v3.container_id); /*0.5*/
        int changed_slots_len; READ_OR_BAIL(readUnsignedVarInt, changed_slots_len); /*1.5*/
        v3.changed_slots.resize(changed_slots_len); /*1.6*/
        for (int i = 0; i < changed_slots_len; i++) { /*5*/
          pdef::proto::TransactionLegacy::LegacyTransactions::ChangedSlots &v4 = v3.changed_slots[i]; /*5.23*/
          READ_OR_BAIL(readUByte, v4.slot_id); /*0.5*/
        }
      }
    }
    return true;
  }
  bool Transaction(pdef::Stream &stream, pdef::proto::Transaction &obj) {
    pdef::proto::decode::TransactionLegacy(stream, obj.legacy); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.transaction_type); /*7.2*/
    const pdef::proto::Transaction::TransactionType &transaction_type = obj.transaction_type; /*0.7*/
    int actions_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, actions_len); /*2.6*/
    obj.actions.resize(actions_len); /*2.7*/
    for (int i = 0; i < actions_len; i++) { pdef::proto::decode::TransactionActions(stream, obj.actions[i]); } /*2.8*/
    switch (transaction_type) { /*8.0*/
      case pdef::proto::Transaction::TransactionType::Normal: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::InventoryMismatch: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemUse: { /*8.5*/
        obj.transaction_data_TransactionUseItem = {}; pdef::proto::decode::TransactionUseItem(stream, *obj.transaction_data_TransactionUseItem); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemUseOnEntity: { /*8.5*/
         obj.transaction_data_item_use_on_entity = {}; pdef::proto::Transaction::TransactionDataItemUseOnEntity &v = *obj.transaction_data_item_use_on_entity; /*8.4*/
          READ_OR_BAIL(readUnsignedVarLong, v.entity_runtime_id); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, (int&)v.action_type); /*7.2*/
          READ_OR_BAIL(readZigZagVarInt, v.hotbar_slot); /*0.5*/
          pdef::proto::decode::Item(stream, v.held_item); /*v*/ /*4.6*/
          pdef::proto::decode::vec3f(stream, v.player_pos); /*v*/ /*4.6*/
          pdef::proto::decode::vec3f(stream, v.click_pos); /*v*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::Transaction::TransactionType::ItemRelease: { /*8.5*/
         obj.transaction_data_item_release = {}; pdef::proto::Transaction::TransactionDataItemRelease &v = *obj.transaction_data_item_release; /*8.4*/
          READ_OR_BAIL(readUnsignedVarInt, (int&)v.action_type); /*7.2*/
          READ_OR_BAIL(readZigZagVarInt, v.hotbar_slot); /*0.5*/
          pdef::proto::decode::Item(stream, v.held_item); /*v*/ /*4.6*/
          pdef::proto::decode::vec3f(stream, v.head_pos); /*v*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool RecipeIngredient(pdef::Stream &stream, pdef::proto::RecipeIngredient &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.network_id); /*0.5*/
    int &network_id = obj.network_id; /*0.6*/
    if (network_id == 0) { /*8.2*/
    }
    else {
        READ_OR_BAIL(readZigZagVarInt, obj.network_data); /*0.5*/
        READ_OR_BAIL(readZigZagVarInt, obj.count); /*0.5*/
    }
    return true;
  }
bool PotionTypeRecipes(pdef::Stream &stream, pdef::proto::PotionTypeRecipes &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.input_item_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.input_item_meta); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.ingredient_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.ingredient_meta); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.output_item_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.output_item_meta); /*0.5*/
  return true;
}
bool PotionContainerChangeRecipes(pdef::Stream &stream, pdef::proto::PotionContainerChangeRecipes &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.input_item_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.ingredient_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.output_item_id); /*0.5*/
  return true;
}
bool Recipes(pdef::Stream &stream, pdef::proto::Recipes &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.type); /*7.2*/
    const pdef::proto::Recipes::Type &type = obj.type; /*0.7*/
    switch (type) { /*8.0*/
      case pdef::proto::Recipes::Type::Shapeless: { /*8.5*/
         obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry = {}; pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.4*/
          int recipe_id_strlen; READ_OR_BAIL(readUnsignedVarInt, recipe_id_strlen);
          if (!stream.readString(v.recipe_id, recipe_id_strlen)) return false; /*recipe_id: pstring*/ /*4.3*/
          int input_len; READ_OR_BAIL(readUnsignedVarInt, input_len); /*1.5*/
          v.input.resize(input_len); /*1.6*/
          for (int i = 0; i < input_len; i++) {
            auto &v5 = v.input[i]; /*3.4*/
            pdef::proto::decode::RecipeIngredient(stream, v5); /*v5*/ /*4.6*/
          }
          int output_len; READ_OR_BAIL(readUnsignedVarInt, output_len); /*1.5*/
          v.output.resize(output_len); /*1.6*/
          for (int i = 0; i < output_len; i++) {
            auto &v5 = v.output[i]; /*3.4*/
            pdef::proto::decode::ItemLegacy(stream, v5); /*v5*/ /*4.6*/
          }
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
          int block_strlen; READ_OR_BAIL(readUnsignedVarInt, block_strlen);
          if (!stream.readString(v.block, block_strlen)) return false; /*block: pstring*/ /*4.3*/
          READ_OR_BAIL(readZigZagVarInt, v.priority); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.network_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShulkerBox: { /*8.5*/
         obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry = {}; pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.4*/
          int recipe_id_strlen; READ_OR_BAIL(readUnsignedVarInt, recipe_id_strlen);
          if (!stream.readString(v.recipe_id, recipe_id_strlen)) return false; /*recipe_id: pstring*/ /*4.3*/
          int input_len; READ_OR_BAIL(readUnsignedVarInt, input_len); /*1.5*/
          v.input.resize(input_len); /*1.6*/
          for (int i = 0; i < input_len; i++) {
            auto &v5 = v.input[i]; /*3.4*/
            pdef::proto::decode::RecipeIngredient(stream, v5); /*v5*/ /*4.6*/
          }
          int output_len; READ_OR_BAIL(readUnsignedVarInt, output_len); /*1.5*/
          v.output.resize(output_len); /*1.6*/
          for (int i = 0; i < output_len; i++) {
            auto &v5 = v.output[i]; /*3.4*/
            pdef::proto::decode::ItemLegacy(stream, v5); /*v5*/ /*4.6*/
          }
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
          int block_strlen; READ_OR_BAIL(readUnsignedVarInt, block_strlen);
          if (!stream.readString(v.block, block_strlen)) return false; /*block: pstring*/ /*4.3*/
          READ_OR_BAIL(readZigZagVarInt, v.priority); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.network_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShapelessChemistry: { /*8.5*/
         obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry = {}; pdef::proto::Recipes::RecipeShapelessOrShulkerBoxOrShapelessChemistry &v = *obj.recipe_shapeless_or_shulker_box_or_shapeless_chemistry; /*8.4*/
          int recipe_id_strlen; READ_OR_BAIL(readUnsignedVarInt, recipe_id_strlen);
          if (!stream.readString(v.recipe_id, recipe_id_strlen)) return false; /*recipe_id: pstring*/ /*4.3*/
          int input_len; READ_OR_BAIL(readUnsignedVarInt, input_len); /*1.5*/
          v.input.resize(input_len); /*1.6*/
          for (int i = 0; i < input_len; i++) {
            auto &v5 = v.input[i]; /*3.4*/
            pdef::proto::decode::RecipeIngredient(stream, v5); /*v5*/ /*4.6*/
          }
          int output_len; READ_OR_BAIL(readUnsignedVarInt, output_len); /*1.5*/
          v.output.resize(output_len); /*1.6*/
          for (int i = 0; i < output_len; i++) {
            auto &v5 = v.output[i]; /*3.4*/
            pdef::proto::decode::ItemLegacy(stream, v5); /*v5*/ /*4.6*/
          }
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
          int block_strlen; READ_OR_BAIL(readUnsignedVarInt, block_strlen);
          if (!stream.readString(v.block, block_strlen)) return false; /*block: pstring*/ /*4.3*/
          READ_OR_BAIL(readZigZagVarInt, v.priority); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.network_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Shaped: { /*8.5*/
         obj.recipe_shaped_or_shaped_chemistry = {}; pdef::proto::Recipes::RecipeShapedOrShapedChemistry &v = *obj.recipe_shaped_or_shaped_chemistry; /*8.4*/
          int recipe_id_strlen; READ_OR_BAIL(readUnsignedVarInt, recipe_id_strlen);
          if (!stream.readString(v.recipe_id, recipe_id_strlen)) return false; /*recipe_id: pstring*/ /*4.3*/
          READ_OR_BAIL(readZigZagVarInt, v.width); /*0.5*/
          int &width = v.width; /*0.6*/
          READ_OR_BAIL(readZigZagVarInt, v.height); /*0.5*/
          int &height = v.height; /*0.6*/
          v.input.resize(width); /*1.6*/
          for (int i = 0; i < width; i++) { /*5.2*/
            int input_len2; READ_OR_BAIL(readZigZagVarInt, input_len2); /*5.5*/
            v.input[i].resize(input_len2); /*5.10*/
            for (int j = 0; j < height; j++) { /*5.11*/
              pdef::proto::decode::RecipeIngredient(stream, v.input[i][j]); /*5.14*/
            }
          }
          int output_len; READ_OR_BAIL(readUnsignedVarInt, output_len); /*1.5*/
          v.output.resize(output_len); /*1.6*/
          for (int i = 0; i < output_len; i++) {
            auto &v5 = v.output[i]; /*3.4*/
            pdef::proto::decode::ItemLegacy(stream, v5); /*v5*/ /*4.6*/
          }
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
          int block_strlen; READ_OR_BAIL(readUnsignedVarInt, block_strlen);
          if (!stream.readString(v.block, block_strlen)) return false; /*block: pstring*/ /*4.3*/
          READ_OR_BAIL(readZigZagVarInt, v.priority); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.network_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::ShapedChemistry: { /*8.5*/
         obj.recipe_shaped_or_shaped_chemistry = {}; pdef::proto::Recipes::RecipeShapedOrShapedChemistry &v = *obj.recipe_shaped_or_shaped_chemistry; /*8.4*/
          int recipe_id_strlen; READ_OR_BAIL(readUnsignedVarInt, recipe_id_strlen);
          if (!stream.readString(v.recipe_id, recipe_id_strlen)) return false; /*recipe_id: pstring*/ /*4.3*/
          READ_OR_BAIL(readZigZagVarInt, v.width); /*0.5*/
          int &width = v.width; /*0.6*/
          READ_OR_BAIL(readZigZagVarInt, v.height); /*0.5*/
          int &height = v.height; /*0.6*/
          v.input.resize(width); /*1.6*/
          for (int i = 0; i < width; i++) { /*5.2*/
            int input_len2; READ_OR_BAIL(readZigZagVarInt, input_len2); /*5.5*/
            v.input[i].resize(input_len2); /*5.10*/
            for (int j = 0; j < height; j++) { /*5.11*/
              pdef::proto::decode::RecipeIngredient(stream, v.input[i][j]); /*5.14*/
            }
          }
          int output_len; READ_OR_BAIL(readUnsignedVarInt, output_len); /*1.5*/
          v.output.resize(output_len); /*1.6*/
          for (int i = 0; i < output_len; i++) {
            auto &v5 = v.output[i]; /*3.4*/
            pdef::proto::decode::ItemLegacy(stream, v5); /*v5*/ /*4.6*/
          }
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
          int block_strlen; READ_OR_BAIL(readUnsignedVarInt, block_strlen);
          if (!stream.readString(v.block, block_strlen)) return false; /*block: pstring*/ /*4.3*/
          READ_OR_BAIL(readZigZagVarInt, v.priority); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.network_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Furnace: { /*8.5*/
         obj.recipe_furnace = {}; pdef::proto::Recipes::RecipeFurnace &v = *obj.recipe_furnace; /*8.4*/
          READ_OR_BAIL(readZigZagVarInt, v.input_id); /*0.5*/
          pdef::proto::decode::ItemLegacy(stream, v.output); /*v*/ /*4.6*/
          int block_strlen; READ_OR_BAIL(readUnsignedVarInt, block_strlen);
          if (!stream.readString(v.block, block_strlen)) return false; /*block: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::FurnaceWithMetadata: { /*8.5*/
         obj.recipe_furnace_with_metadata = {}; pdef::proto::Recipes::RecipeFurnaceWithMetadata &v = *obj.recipe_furnace_with_metadata; /*8.4*/
          READ_OR_BAIL(readZigZagVarInt, v.input_id); /*0.5*/
          READ_OR_BAIL(readZigZagVarInt, v.input_meta); /*0.5*/
          pdef::proto::decode::ItemLegacy(stream, v.output); /*v*/ /*4.6*/
          int block_strlen; READ_OR_BAIL(readUnsignedVarInt, block_strlen);
          if (!stream.readString(v.block, block_strlen)) return false; /*block: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::Recipes::Type::Multi: { /*8.5*/
         obj.recipe_multi = {}; pdef::proto::Recipes::RecipeMulti &v = *obj.recipe_multi; /*8.4*/
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, v.network_id); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  return true;
}
  bool SkinImage(pdef::Stream &stream, pdef::proto::SkinImage &obj) {
    READ_OR_BAIL(readIntLE, obj.width); /*0.5*/
    READ_OR_BAIL(readIntLE, obj.height); /*0.5*/
    int data_len; READ_OR_BAIL(readUnsignedVarInt, data_len);if (!stream.readBuffer(obj.data, data_len)) return false; /*data: buffer*/ /*4.3*/
    return true;
  }
  bool Skin(pdef::Stream &stream, pdef::proto::Skin &obj) {
    int skin_id_strlen; READ_OR_BAIL(readUnsignedVarInt, skin_id_strlen);
    if (!stream.readString(obj.skin_id, skin_id_strlen)) return false; /*skin_id: pstring*/ /*4.3*/
    int play_fab_id_strlen; READ_OR_BAIL(readUnsignedVarInt, play_fab_id_strlen);
    if (!stream.readString(obj.play_fab_id, play_fab_id_strlen)) return false; /*play_fab_id: pstring*/ /*4.3*/
    int skin_resource_pack_strlen; READ_OR_BAIL(readUnsignedVarInt, skin_resource_pack_strlen);
    if (!stream.readString(obj.skin_resource_pack, skin_resource_pack_strlen)) return false; /*skin_resource_pack: pstring*/ /*4.3*/
    pdef::proto::decode::SkinImage(stream, obj.skin_data); /*obj*/ /*4.6*/
    int32_t animations_len; READ_OR_BAIL(readIntLE, animations_len); /*1.5*/
    obj.animations.resize(animations_len); /*1.6*/
    for (int i = 0; i < animations_len; i++) { /*5*/
      pdef::proto::Skin::Animations &v2 = obj.animations[i]; /*5.23*/
      pdef::proto::decode::SkinImage(stream, v2.skin_image); /*v2*/ /*4.6*/
      READ_OR_BAIL(readIntLE, v2.animation_type); /*0.5*/
      READ_OR_BAIL(readFloatLE, v2.animation_frames); /*0.5*/
      READ_OR_BAIL(readFloatLE, v2.expression_type); /*0.5*/
    }
    pdef::proto::decode::SkinImage(stream, obj.cape_data); /*obj*/ /*4.6*/
    int geometry_data_strlen; READ_OR_BAIL(readUnsignedVarInt, geometry_data_strlen);
    if (!stream.readString(obj.geometry_data, geometry_data_strlen)) return false; /*geometry_data: pstring*/ /*4.3*/
    int geometry_data_version_strlen; READ_OR_BAIL(readUnsignedVarInt, geometry_data_version_strlen);
    if (!stream.readString(obj.geometry_data_version, geometry_data_version_strlen)) return false; /*geometry_data_version: pstring*/ /*4.3*/
    int animation_data_strlen; READ_OR_BAIL(readUnsignedVarInt, animation_data_strlen);
    if (!stream.readString(obj.animation_data, animation_data_strlen)) return false; /*animation_data: pstring*/ /*4.3*/
    int cape_id_strlen; READ_OR_BAIL(readUnsignedVarInt, cape_id_strlen);
    if (!stream.readString(obj.cape_id, cape_id_strlen)) return false; /*cape_id: pstring*/ /*4.3*/
    int full_skin_id_strlen; READ_OR_BAIL(readUnsignedVarInt, full_skin_id_strlen);
    if (!stream.readString(obj.full_skin_id, full_skin_id_strlen)) return false; /*full_skin_id: pstring*/ /*4.3*/
    int arm_size_strlen; READ_OR_BAIL(readUnsignedVarInt, arm_size_strlen);
    if (!stream.readString(obj.arm_size, arm_size_strlen)) return false; /*arm_size: pstring*/ /*4.3*/
    int skin_color_strlen; READ_OR_BAIL(readUnsignedVarInt, skin_color_strlen);
    if (!stream.readString(obj.skin_color, skin_color_strlen)) return false; /*skin_color: pstring*/ /*4.3*/
    int32_t personal_pieces_len; READ_OR_BAIL(readIntLE, personal_pieces_len); /*1.5*/
    obj.personal_pieces.resize(personal_pieces_len); /*1.6*/
    for (int i = 0; i < personal_pieces_len; i++) { /*5*/
      pdef::proto::Skin::PersonalPieces &v2 = obj.personal_pieces[i]; /*5.23*/
      int piece_id_strlen; READ_OR_BAIL(readUnsignedVarInt, piece_id_strlen);
      if (!stream.readString(v2.piece_id, piece_id_strlen)) return false; /*piece_id: pstring*/ /*4.3*/
      int piece_type_strlen; READ_OR_BAIL(readUnsignedVarInt, piece_type_strlen);
      if (!stream.readString(v2.piece_type, piece_type_strlen)) return false; /*piece_type: pstring*/ /*4.3*/
      int pack_id_strlen; READ_OR_BAIL(readUnsignedVarInt, pack_id_strlen);
      if (!stream.readString(v2.pack_id, pack_id_strlen)) return false; /*pack_id: pstring*/ /*4.3*/
      READ_OR_BAIL(readBool, (bool&)v2.is_default_piece); /*0.5*/
      int product_id_strlen; READ_OR_BAIL(readUnsignedVarInt, product_id_strlen);
      if (!stream.readString(v2.product_id, product_id_strlen)) return false; /*product_id: pstring*/ /*4.3*/
    }
    int32_t piece_tint_colors_len; READ_OR_BAIL(readIntLE, piece_tint_colors_len); /*1.5*/
    obj.piece_tint_colors.resize(piece_tint_colors_len); /*1.6*/
    for (int i = 0; i < piece_tint_colors_len; i++) { /*5*/
      pdef::proto::Skin::PieceTintColors &v2 = obj.piece_tint_colors[i]; /*5.23*/
      int piece_type_strlen; READ_OR_BAIL(readUnsignedVarInt, piece_type_strlen);
      if (!stream.readString(v2.piece_type, piece_type_strlen)) return false; /*piece_type: pstring*/ /*4.3*/
      int32_t colors_len; READ_OR_BAIL(readIntLE, colors_len); /*1.5*/
      v2.colors.resize(colors_len); /*1.6*/
      for (int i = 0; i < colors_len; i++) {
        auto &v3 = v2.colors[i]; /*3.4*/
        int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
        if (!stream.readString(v3, _strlen)) return false; /*: pstring*/ /*4.3*/
      }
    }
    READ_OR_BAIL(readBool, (bool&)obj.premium); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.persona); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.cape_on_classic); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.primary_user); /*0.5*/
    return true;
  }
  bool PlayerRecords(pdef::Stream &stream, pdef::proto::PlayerRecords &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.type); /*7.2*/
    const pdef::proto::PlayerRecords::Type &type = obj.type; /*0.7*/
    READ_OR_BAIL(readUnsignedVarInt, obj.records_count); /*0.5*/
    int &records_count = obj.records_count; /*0.6*/
    switch (type) { /*8.0*/
      case pdef::proto::PlayerRecords::Type::Add: { /*8.5*/
         obj.records_add = {}; pdef::proto::PlayerRecords::RecordsAdd &v = *obj.records_add; /*8.4*/
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
          READ_OR_BAIL(readZigZagVarLong, v.entity_unique_id); /*0.5*/
          int username_strlen; READ_OR_BAIL(readUnsignedVarInt, username_strlen);
          if (!stream.readString(v.username, username_strlen)) return false; /*username: pstring*/ /*4.3*/
          int xbox_user_id_strlen; READ_OR_BAIL(readUnsignedVarInt, xbox_user_id_strlen);
          if (!stream.readString(v.xbox_user_id, xbox_user_id_strlen)) return false; /*xbox_user_id: pstring*/ /*4.3*/
          int platform_chat_id_strlen; READ_OR_BAIL(readUnsignedVarInt, platform_chat_id_strlen);
          if (!stream.readString(v.platform_chat_id, platform_chat_id_strlen)) return false; /*platform_chat_id: pstring*/ /*4.3*/
          READ_OR_BAIL(readIntLE, v.build_platform); /*0.5*/
          pdef::proto::decode::Skin(stream, v.skin_data); /*v*/ /*4.6*/
          READ_OR_BAIL(readBool, (bool&)v.is_teacher); /*0.5*/
          READ_OR_BAIL(readBool, (bool&)v.is_host); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::PlayerRecords::Type::Remove: { /*8.5*/
         obj.records_remove = {}; pdef::proto::PlayerRecords::RecordsRemove &v = *obj.records_remove; /*8.4*/
          READ_OR_BAIL(readULongBE, v.uuid); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    switch (type) { /*8.0*/
      case pdef::proto::PlayerRecords::Type::Add: { /*8.5*/
        obj.verified.resize(records_count); /*1.6*/
        for (int i = 0; i < records_count; i++) {
          auto &v4 = obj.verified[i]; /*3.4*/
          READ_OR_BAIL(readBool, (bool&)v4); /*0.5*/
        }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool Enchant(pdef::Stream &stream, pdef::proto::Enchant &obj) {
    READ_OR_BAIL(readUByte, obj.id); /*0.5*/
    READ_OR_BAIL(readUByte, obj.level); /*0.5*/
    return true;
  }
  bool EnchantOption(pdef::Stream &stream, pdef::proto::EnchantOption &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.cost); /*0.5*/
    READ_OR_BAIL(readIntLE, obj.slot_flags); /*0.5*/
    int equip_enchants_len; READ_OR_BAIL(readUnsignedVarInt, equip_enchants_len); /*1.5*/
    obj.equip_enchants.resize(equip_enchants_len); /*1.6*/
    for (int i = 0; i < equip_enchants_len; i++) {
      auto &v2 = obj.equip_enchants[i]; /*3.4*/
      pdef::proto::decode::Enchant(stream, v2); /*v2*/ /*4.6*/
    }
    int held_enchants_len; READ_OR_BAIL(readUnsignedVarInt, held_enchants_len); /*1.5*/
    obj.held_enchants.resize(held_enchants_len); /*1.6*/
    for (int i = 0; i < held_enchants_len; i++) {
      auto &v2 = obj.held_enchants[i]; /*3.4*/
      pdef::proto::decode::Enchant(stream, v2); /*v2*/ /*4.6*/
    }
    int self_enchants_len; READ_OR_BAIL(readUnsignedVarInt, self_enchants_len); /*1.5*/
    obj.self_enchants.resize(self_enchants_len); /*1.6*/
    for (int i = 0; i < self_enchants_len; i++) {
      auto &v2 = obj.self_enchants[i]; /*3.4*/
      pdef::proto::decode::Enchant(stream, v2); /*v2*/ /*4.6*/
    }
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarInt, obj.option_id); /*0.5*/
    return true;
  }
  bool StackRequestSlotInfo(pdef::Stream &stream, pdef::proto::StackRequestSlotInfo &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.slot_type); /*7.2*/
    READ_OR_BAIL(readUByte, obj.slot); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.stack_id); /*0.5*/
    return true;
  }
  bool ItemStackRequest(pdef::Stream &stream, pdef::proto::ItemStackRequest &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.request_id); /*0.5*/
    int actions_len; READ_OR_BAIL(readUnsignedVarInt, actions_len); /*1.5*/
    obj.actions.resize(actions_len); /*1.6*/
    for (int i = 0; i < actions_len; i++) { /*5*/
      pdef::proto::ItemStackRequest::Actions &v2 = obj.actions[i]; /*5.23*/
      READ_OR_BAIL(readUByte, (uint8_t&)v2.type_id); /*7.2*/
      const pdef::proto::ItemStackRequest::Actions::TypeId &type_id = v2.type_id; /*0.7*/
      switch (type_id) { /*8.0*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Take: { /*8.5*/
            READ_OR_BAIL(readUByte, v2.count); /*0.5*/
            v2.source = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.source); /*v2*/ /*4.6*/
            v2.destination = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.destination); /*v2*/ /*4.6*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Place: { /*8.5*/
            READ_OR_BAIL(readUByte, v2.count); /*0.5*/
            v2.source = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.source); /*v2*/ /*4.6*/
            v2.destination = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.destination); /*v2*/ /*4.6*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Swap: { /*8.5*/
            v2.source = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.source); /*v2*/ /*4.6*/
            v2.destination = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.destination); /*v2*/ /*4.6*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Drop: { /*8.5*/
            READ_OR_BAIL(readUByte, v2.count); /*0.5*/
            v2.source = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.source); /*v2*/ /*4.6*/
            READ_OR_BAIL(readBool, (bool&)v2.randomly); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Destroy: { /*8.5*/
            READ_OR_BAIL(readUByte, v2.count); /*0.5*/
            v2.source = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.source); /*v2*/ /*4.6*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Consume: { /*8.5*/
            READ_OR_BAIL(readUByte, v2.count); /*0.5*/
            v2.source = {}; pdef::proto::decode::StackRequestSlotInfo(stream, *v2.source); /*v2*/ /*4.6*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Create: { /*8.5*/
            READ_OR_BAIL(readUByte, v2.result_slot_id); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::BeaconPayment: { /*8.5*/
            READ_OR_BAIL(readZigZagVarInt, v2.primary_effect); /*0.5*/
            READ_OR_BAIL(readZigZagVarInt, v2.secondary_effect); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::MineBlock: { /*8.5*/
            READ_OR_BAIL(readZigZagVarInt, v2.unknown1); /*0.5*/
            READ_OR_BAIL(readZigZagVarInt, v2.predicted_durability); /*0.5*/
            READ_OR_BAIL(readZigZagVarInt, v2.network_id); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftRecipe: { /*8.5*/
            READ_OR_BAIL(readUnsignedVarInt, v2.recipe_network_id); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftRecipeAuto: { /*8.5*/
            READ_OR_BAIL(readUnsignedVarInt, v2.recipe_network_id); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftCreative: { /*8.5*/
            READ_OR_BAIL(readUnsignedVarInt, v2.item_id); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::Optional: { /*8.5*/
            READ_OR_BAIL(readUnsignedVarInt, v2.recipe_network_id); /*0.5*/
            READ_OR_BAIL(readIntLE, v2.filtered_string_index); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftGrindstoneRequest: { /*8.5*/
            READ_OR_BAIL(readUnsignedVarInt, v2.recipe_network_id); /*0.5*/
            READ_OR_BAIL(readUnsignedVarInt, v2.cost); /*0.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::CraftLoomRequest: { /*8.5*/
            int pattern_strlen; READ_OR_BAIL(readUnsignedVarInt, pattern_strlen);
            if (!stream.readString(v2.pattern, pattern_strlen)) return false; /*pattern: pstring*/ /*4.3*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::NonImplemented: { /*8.5*/
          break;
        } /*8.7*/
        case pdef::proto::ItemStackRequest::Actions::TypeId::ResultsDeprecated: { /*8.5*/
            int result_items_len; READ_OR_BAIL(readUnsignedVarInt, result_items_len); /*1.5*/
            v2.result_items.resize(result_items_len); /*1.6*/
            for (int i = 0; i < result_items_len; i++) {
              auto &v6 = v2.result_items[i]; /*3.4*/
              pdef::proto::decode::ItemLegacy(stream, v6); /*v6*/ /*4.6*/
            }
            READ_OR_BAIL(readUByte, v2.times_crafted); /*0.5*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    int custom_names_len; READ_OR_BAIL(readUnsignedVarInt, custom_names_len); /*1.5*/
    obj.custom_names.resize(custom_names_len); /*1.6*/
    for (int i = 0; i < custom_names_len; i++) {
      auto &v2 = obj.custom_names[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    return true;
  }
bool ItemStackResponses(pdef::Stream &stream, pdef::proto::ItemStackResponses &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.status); /*7.2*/
    const pdef::proto::ItemStackResponses::Status &status = obj.status; /*0.7*/
    READ_OR_BAIL(readZigZagVarInt, obj.request_id); /*0.5*/
    switch (status) { /*8.0*/
      case pdef::proto::ItemStackResponses::Status::Ok: { /*8.5*/
          int containers_len; READ_OR_BAIL(readUnsignedVarInt, containers_len); /*1.5*/
          obj.containers.resize(containers_len); /*1.6*/
          for (int i = 0; i < containers_len; i++) { /*5*/
            pdef::proto::ItemStackResponses::Containers &v5 = obj.containers[i]; /*5.23*/
            READ_OR_BAIL(readUByte, (uint8_t&)v5.slot_type); /*7.2*/
            int slots_len; READ_OR_BAIL(readUnsignedVarInt, slots_len); /*1.5*/
            v5.slots.resize(slots_len); /*1.6*/
            for (int i = 0; i < slots_len; i++) { /*5*/
              pdef::proto::ItemStackResponses::Containers::Slots &v6 = v5.slots[i]; /*5.23*/
              READ_OR_BAIL(readUByte, v6.slot); /*0.5*/
              READ_OR_BAIL(readUByte, v6.hotbar_slot); /*0.5*/
              READ_OR_BAIL(readUByte, v6.count); /*0.5*/
              READ_OR_BAIL(readZigZagVarInt, v6.item_stack_id); /*0.5*/
              int custom_name_strlen; READ_OR_BAIL(readUnsignedVarInt, custom_name_strlen);
              if (!stream.readString(v6.custom_name, custom_name_strlen)) return false; /*custom_name: pstring*/ /*4.3*/
              READ_OR_BAIL(readZigZagVarInt, v6.durability_correction); /*0.5*/
            }
          }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  return true;
}
bool ItemComponentList(pdef::Stream &stream, pdef::proto::ItemComponentList &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
  return true;
}
  bool CommandOrigin(pdef::Stream &stream, pdef::proto::CommandOrigin &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.type); /*7.2*/
    const pdef::proto::CommandOrigin::Type &type = obj.type; /*0.7*/
    READ_OR_BAIL(readULongBE, obj.uuid); /*0.5*/
    int request_id_strlen; READ_OR_BAIL(readUnsignedVarInt, request_id_strlen);
    if (!stream.readString(obj.request_id, request_id_strlen)) return false; /*request_id: pstring*/ /*4.3*/
    switch (type) { /*8.0*/
      case pdef::proto::CommandOrigin::Type::DevConsole: { /*8.5*/
         obj.player_entity_id = {}; pdef::proto::CommandOrigin::PlayerEntityId &v = *obj.player_entity_id; /*8.4*/
          READ_OR_BAIL(readZigZagVarLong, v.player_entity_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::CommandOrigin::Type::Test: { /*8.5*/
         obj.player_entity_id = {}; pdef::proto::CommandOrigin::PlayerEntityId &v = *obj.player_entity_id; /*8.4*/
          READ_OR_BAIL(readZigZagVarLong, v.player_entity_id); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool TrackedObject(pdef::Stream &stream, pdef::proto::TrackedObject &obj) {
    READ_OR_BAIL(readIntLE, (int32_t&)obj.type); /*7.2*/
    const pdef::proto::TrackedObject::Type &type = obj.type; /*0.7*/
    switch (type) { /*8.0*/
      case pdef::proto::TrackedObject::Type::Entity: { /*8.5*/
        READ_OR_BAIL(readZigZagVarLong, obj.entity_unique_id); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    switch (type) { /*8.0*/
      case pdef::proto::TrackedObject::Type::Block: { /*8.5*/
        obj.block_position = {}; pdef::proto::decode::BlockCoordinates(stream, *obj.block_position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool MapDecoration(pdef::Stream &stream, pdef::proto::MapDecoration &obj) {
    READ_OR_BAIL(readUByte, obj.type); /*0.5*/
    READ_OR_BAIL(readUByte, obj.rotation); /*0.5*/
    READ_OR_BAIL(readUByte, obj.x); /*0.5*/
    READ_OR_BAIL(readUByte, obj.y); /*0.5*/
    int label_strlen; READ_OR_BAIL(readUnsignedVarInt, label_strlen);
    if (!stream.readString(obj.label, label_strlen)) return false; /*label: pstring*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.color_abgr); /*0.5*/
    return true;
  }
  bool StructureBlockSettings(pdef::Stream &stream, pdef::proto::StructureBlockSettings &obj) {
    int palette_name_strlen; READ_OR_BAIL(readUnsignedVarInt, palette_name_strlen);
    if (!stream.readString(obj.palette_name, palette_name_strlen)) return false; /*palette_name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.ignore_entities); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.ignore_blocks); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.non_ticking_players_and_ticking_areas); /*0.5*/
    pdef::proto::decode::BlockCoordinates(stream, obj.size); /*obj*/ /*4.6*/
    pdef::proto::decode::BlockCoordinates(stream, obj.structure_offset); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarLong, obj.last_editing_player_unique_id); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.rotation); /*7.2*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.mirror); /*7.2*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.animation_mode); /*7.2*/
    READ_OR_BAIL(readFloatLE, obj.animation_duration); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.integrity); /*0.5*/
    READ_OR_BAIL(readUIntLE, obj.seed); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.pivot); /*obj*/ /*4.6*/
    return true;
  }
  bool EducationSharedResourceURI(pdef::Stream &stream, pdef::proto::EducationSharedResourceURI &obj) {
    int button_name_strlen; READ_OR_BAIL(readUnsignedVarInt, button_name_strlen);
    if (!stream.readString(obj.button_name, button_name_strlen)) return false; /*button_name: pstring*/ /*4.3*/
    int link_uri_strlen; READ_OR_BAIL(readUnsignedVarInt, link_uri_strlen);
    if (!stream.readString(obj.link_uri, link_uri_strlen)) return false; /*link_uri: pstring*/ /*4.3*/
    return true;
  }
  bool EducationExternalLinkSettings(pdef::Stream &stream, pdef::proto::EducationExternalLinkSettings &obj) {
    int url_strlen; READ_OR_BAIL(readUnsignedVarInt, url_strlen);
    if (!stream.readString(obj.url, url_strlen)) return false; /*url: pstring*/ /*4.3*/
    int display_name_strlen; READ_OR_BAIL(readUnsignedVarInt, display_name_strlen);
    if (!stream.readString(obj.display_name, display_name_strlen)) return false; /*display_name: pstring*/ /*4.3*/
    return true;
  }
  bool BlockUpdate(pdef::Stream &stream, pdef::proto::BlockUpdate &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUnsignedVarInt, obj.runtime_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.flags); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.entity_unique_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.transition_type); /*7.2*/
    return true;
  }
  bool MaterialReducer(pdef::Stream &stream, pdef::proto::MaterialReducer &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.mix); /*0.5*/
    const pdef::proto::MaterialReducer::Items &v = obj.items = {}; /*["MaterialReducer"]*/ /*7.3*/
    return true;
  }
  bool packet_login(pdef::Stream &stream, pdef::proto::packet_login &obj) {
    READ_OR_BAIL(readIntBE, obj.protocol_version); /*0.5*/
    READ_OR_BAIL(readByte, obj.tokens); /*0.5*/
    return true;
  }
  bool LoginTokens(pdef::Stream &stream, pdef::proto::LoginTokens &obj) {
    int32_t identity_strlen; READ_OR_BAIL(readIntLE, identity_strlen);
    if (!stream.readString(obj.identity, identity_strlen)) return false; /*identity: pstring*/ /*4.3*/
    int32_t client_strlen; READ_OR_BAIL(readIntLE, client_strlen);
    if (!stream.readString(obj.client, client_strlen)) return false; /*client: pstring*/ /*4.3*/
    return true;
  }
  bool packet_play_status(pdef::Stream &stream, pdef::proto::packet_play_status &obj) {
    READ_OR_BAIL(readIntBE, (int32_t&)obj.status); /*7.2*/
    return true;
  }
  bool packet_server_to_client_handshake(pdef::Stream &stream, pdef::proto::packet_server_to_client_handshake &obj) {
    int token_strlen; READ_OR_BAIL(readUnsignedVarInt, token_strlen);
    if (!stream.readString(obj.token, token_strlen)) return false; /*token: pstring*/ /*4.3*/
    return true;
  }
  bool packet_client_to_server_handshake(pdef::Stream &stream, pdef::proto::packet_client_to_server_handshake &obj) {
    return true;
  }
  bool packet_disconnect(pdef::Stream &stream, pdef::proto::packet_disconnect &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.hide_disconnect_reason); /*0.5*/
    int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
    if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
    return true;
  }
  bool packet_resource_packs_info(pdef::Stream &stream, pdef::proto::packet_resource_packs_info &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.must_accept); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.has_scripts); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.force_server_packs); /*0.5*/
    int16_t behaviour_packs_len; /*2.3*/
    READ_OR_BAIL(readShortLE, behaviour_packs_len); /*2.6*/
    obj.behaviour_packs.resize(behaviour_packs_len); /*2.7*/
    for (int i = 0; i < behaviour_packs_len; i++) { pdef::proto::decode::BehaviourPackInfos(stream, obj.behaviour_packs[i]); } /*2.8*/
    int16_t texture_packs_len; /*2.3*/
    READ_OR_BAIL(readShortLE, texture_packs_len); /*2.6*/
    obj.texture_packs.resize(texture_packs_len); /*2.7*/
    for (int i = 0; i < texture_packs_len; i++) { pdef::proto::decode::TexturePackInfos(stream, obj.texture_packs[i]); } /*2.8*/
    return true;
  }
  bool packet_resource_pack_stack(pdef::Stream &stream, pdef::proto::packet_resource_pack_stack &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.must_accept); /*0.5*/
    int behavior_packs_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, behavior_packs_len); /*2.6*/
    obj.behavior_packs.resize(behavior_packs_len); /*2.7*/
    for (int i = 0; i < behavior_packs_len; i++) { pdef::proto::decode::ResourcePackIdVersions(stream, obj.behavior_packs[i]); } /*2.8*/
    int resource_packs_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, resource_packs_len); /*2.6*/
    obj.resource_packs.resize(resource_packs_len); /*2.7*/
    for (int i = 0; i < resource_packs_len; i++) { pdef::proto::decode::ResourcePackIdVersions(stream, obj.resource_packs[i]); } /*2.8*/
    int game_version_strlen; READ_OR_BAIL(readUnsignedVarInt, game_version_strlen);
    if (!stream.readString(obj.game_version, game_version_strlen)) return false; /*game_version: pstring*/ /*4.3*/
    int32_t experiments_len; READ_OR_BAIL(readIntLE, experiments_len); /*1.5*/
    obj.experiments.resize(experiments_len); /*1.6*/
    for (int i = 0; i < experiments_len; i++) {
      auto &v2 = obj.experiments[i]; /*3.4*/
      pdef::proto::decode::Experiment(stream, v2); /*v2*/ /*4.6*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.experiments_previously_used); /*0.5*/
    return true;
  }
  bool packet_resource_pack_client_response(pdef::Stream &stream, pdef::proto::packet_resource_pack_client_response &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.response_status); /*7.2*/
    int16_t resourcepackids_len; READ_OR_BAIL(readShortLE, resourcepackids_len); /*1.5*/
    obj.resourcepackids.resize(resourcepackids_len); /*1.6*/
    for (int i = 0; i < resourcepackids_len; i++) {
      auto &v2 = obj.resourcepackids[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    return true;
  }
  bool packet_text(pdef::Stream &stream, pdef::proto::packet_text &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.type); /*7.2*/
    const pdef::proto::packet_text::Type &type = obj.type; /*0.7*/
    READ_OR_BAIL(readBool, (bool&)obj.needs_translation); /*0.5*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_text::Type::Chat: { /*8.5*/
          int source_name_strlen; READ_OR_BAIL(readUnsignedVarInt, source_name_strlen);
          if (!stream.readString(obj.source_name, source_name_strlen)) return false; /*source_name: pstring*/ /*4.3*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Whisper: { /*8.5*/
          int source_name_strlen; READ_OR_BAIL(readUnsignedVarInt, source_name_strlen);
          if (!stream.readString(obj.source_name, source_name_strlen)) return false; /*source_name: pstring*/ /*4.3*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Announcement: { /*8.5*/
          int source_name_strlen; READ_OR_BAIL(readUnsignedVarInt, source_name_strlen);
          if (!stream.readString(obj.source_name, source_name_strlen)) return false; /*source_name: pstring*/ /*4.3*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Raw: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Tip: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::System: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::JsonWhisper: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Json: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Translation: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
          int parameters_len; READ_OR_BAIL(readUnsignedVarInt, parameters_len); /*1.5*/
          obj.parameters.resize(parameters_len); /*1.6*/
          for (int i = 0; i < parameters_len; i++) {
            auto &v5 = obj.parameters[i]; /*3.4*/
            int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
            if (!stream.readString(v5, _strlen)) return false; /*: pstring*/ /*4.3*/
          }
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::Popup: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
          int parameters_len; READ_OR_BAIL(readUnsignedVarInt, parameters_len); /*1.5*/
          obj.parameters.resize(parameters_len); /*1.6*/
          for (int i = 0; i < parameters_len; i++) {
            auto &v5 = obj.parameters[i]; /*3.4*/
            int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
            if (!stream.readString(v5, _strlen)) return false; /*: pstring*/ /*4.3*/
          }
        break;
      } /*8.7*/
      case pdef::proto::packet_text::Type::JukeboxPopup: { /*8.5*/
          int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
          if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
          int parameters_len; READ_OR_BAIL(readUnsignedVarInt, parameters_len); /*1.5*/
          obj.parameters.resize(parameters_len); /*1.6*/
          for (int i = 0; i < parameters_len; i++) {
            auto &v5 = obj.parameters[i]; /*3.4*/
            int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
            if (!stream.readString(v5, _strlen)) return false; /*: pstring*/ /*4.3*/
          }
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    int xuid_strlen; READ_OR_BAIL(readUnsignedVarInt, xuid_strlen);
    if (!stream.readString(obj.xuid, xuid_strlen)) return false; /*xuid: pstring*/ /*4.3*/
    int platform_chat_id_strlen; READ_OR_BAIL(readUnsignedVarInt, platform_chat_id_strlen);
    if (!stream.readString(obj.platform_chat_id, platform_chat_id_strlen)) return false; /*platform_chat_id: pstring*/ /*4.3*/
    return true;
  }
  bool packet_set_time(pdef::Stream &stream, pdef::proto::packet_set_time &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.time); /*0.5*/
    return true;
  }
  bool packet_start_game(pdef::Stream &stream, pdef::proto::packet_start_game &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.entity_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.player_gamemode); /*7.2*/
    pdef::proto::decode::vec3f(stream, obj.player_position); /*obj*/ /*4.6*/
    pdef::proto::decode::vec2f(stream, obj.rotation); /*obj*/ /*4.6*/
    READ_OR_BAIL(readULongLE, obj.seed); /*0.5*/
    READ_OR_BAIL(readShortLE, obj.biome_type); /*0.5*/
    int biome_name_strlen; READ_OR_BAIL(readUnsignedVarInt, biome_name_strlen);
    if (!stream.readString(obj.biome_name, biome_name_strlen)) return false; /*biome_name: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.dimension); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.generator); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.world_gamemode); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.difficulty); /*0.5*/
    pdef::proto::decode::BlockCoordinates(stream, obj.spawn_position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readBool, (bool&)obj.achievements_disabled); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.day_cycle_stop_time); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.edu_offer); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.edu_features_enabled); /*0.5*/
    int edu_product_uuid_strlen; READ_OR_BAIL(readUnsignedVarInt, edu_product_uuid_strlen);
    if (!stream.readString(obj.edu_product_uuid, edu_product_uuid_strlen)) return false; /*edu_product_uuid: pstring*/ /*4.3*/
    READ_OR_BAIL(readFloatLE, obj.rain_level); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.lightning_level); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.has_confirmed_platform_locked_content); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_multiplayer); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.broadcast_to_lan); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.xbox_live_broadcast_mode); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.platform_broadcast_mode); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.enable_commands); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_texturepacks_required); /*0.5*/
    int gamerules_len; READ_OR_BAIL(readUnsignedVarInt, gamerules_len); /*1.5*/
    obj.gamerules.resize(gamerules_len); /*1.6*/
    for (int i = 0; i < gamerules_len; i++) {
      auto &v2 = obj.gamerules[i]; /*3.4*/
      pdef::proto::decode::GameRule(stream, v2); /*v2*/ /*4.6*/
    }
    int32_t experiments_len; READ_OR_BAIL(readIntLE, experiments_len); /*1.5*/
    obj.experiments.resize(experiments_len); /*1.6*/
    for (int i = 0; i < experiments_len; i++) {
      auto &v2 = obj.experiments[i]; /*3.4*/
      pdef::proto::decode::Experiment(stream, v2); /*v2*/ /*4.6*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.experiments_previously_used); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.bonus_chest); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.map_enabled); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.permission_level); /*0.5*/
    READ_OR_BAIL(readIntLE, obj.server_chunk_tick_range); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.has_locked_behavior_pack); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.has_locked_resource_pack); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_from_locked_world_template); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.msa_gamertags_only); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_from_world_template); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_world_template_option_locked); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.only_spawn_v1_villagers); /*0.5*/
    int game_version_strlen; READ_OR_BAIL(readUnsignedVarInt, game_version_strlen);
    if (!stream.readString(obj.game_version, game_version_strlen)) return false; /*game_version: pstring*/ /*4.3*/
    READ_OR_BAIL(readIntLE, obj.limited_world_width); /*0.5*/
    READ_OR_BAIL(readIntLE, obj.limited_world_length); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_new_nether); /*0.5*/
    pdef::proto::decode::EducationSharedResourceURI(stream, obj.edu_resource_uri); /*obj*/ /*4.6*/
    READ_OR_BAIL(readBool, (bool&)obj.experimental_gameplay_override); /*0.5*/
    int level_id_strlen; READ_OR_BAIL(readUnsignedVarInt, level_id_strlen);
    if (!stream.readString(obj.level_id, level_id_strlen)) return false; /*level_id: pstring*/ /*4.3*/
    int world_name_strlen; READ_OR_BAIL(readUnsignedVarInt, world_name_strlen);
    if (!stream.readString(obj.world_name, world_name_strlen)) return false; /*world_name: pstring*/ /*4.3*/
    int premium_world_template_id_strlen; READ_OR_BAIL(readUnsignedVarInt, premium_world_template_id_strlen);
    if (!stream.readString(obj.premium_world_template_id, premium_world_template_id_strlen)) return false; /*premium_world_template_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.is_trial); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.movement_authority); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.rewind_history_size); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.server_authoritative_block_breaking); /*0.5*/
    READ_OR_BAIL(readLongLE, obj.current_tick); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.enchantment_seed); /*0.5*/
    int block_properties_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, block_properties_len); /*2.6*/
    obj.block_properties.resize(block_properties_len); /*2.7*/
    for (int i = 0; i < block_properties_len; i++) { pdef::proto::decode::BlockProperties(stream, obj.block_properties[i]); } /*2.8*/
    int itemstates_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, itemstates_len); /*2.6*/
    obj.itemstates.resize(itemstates_len); /*2.7*/
    for (int i = 0; i < itemstates_len; i++) { pdef::proto::decode::Itemstates(stream, obj.itemstates[i]); } /*2.8*/
    int multiplayer_correlation_id_strlen; READ_OR_BAIL(readUnsignedVarInt, multiplayer_correlation_id_strlen);
    if (!stream.readString(obj.multiplayer_correlation_id, multiplayer_correlation_id_strlen)) return false; /*multiplayer_correlation_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.server_authoritative_inventory); /*0.5*/
    int engine_strlen; READ_OR_BAIL(readUnsignedVarInt, engine_strlen);
    if (!stream.readString(obj.engine, engine_strlen)) return false; /*engine: pstring*/ /*4.3*/
    READ_OR_BAIL(readByte, obj.property_data); /*0.5*/
    READ_OR_BAIL(readULongLE, obj.block_pallette_checksum); /*0.5*/
    READ_OR_BAIL(readULongBE, obj.world_template_id); /*0.5*/
    return true;
  }
  bool packet_add_player(pdef::Stream &stream, pdef::proto::packet_add_player &obj) {
    READ_OR_BAIL(readULongBE, obj.uuid); /*0.5*/
    int username_strlen; READ_OR_BAIL(readUnsignedVarInt, username_strlen);
    if (!stream.readString(obj.username, username_strlen)) return false; /*username: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarLong, obj.unique_entity_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    int platform_chat_id_strlen; READ_OR_BAIL(readUnsignedVarInt, platform_chat_id_strlen);
    if (!stream.readString(obj.platform_chat_id, platform_chat_id_strlen)) return false; /*platform_chat_id: pstring*/ /*4.3*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::vec3f(stream, obj.velocity); /*obj*/ /*4.6*/
    READ_OR_BAIL(readFloatLE, obj.pitch); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.head_yaw); /*0.5*/
    pdef::proto::decode::Item(stream, obj.held_item); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.gamemode); /*7.2*/
    int metadata_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, metadata_len); /*2.6*/
    obj.metadata.resize(metadata_len); /*2.7*/
    for (int i = 0; i < metadata_len; i++) { pdef::proto::decode::MetadataDictionary(stream, obj.metadata[i]); } /*2.8*/
    READ_OR_BAIL(readUnsignedVarInt, obj.flags); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.command_permission); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.action_permissions); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.permission_level); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.custom_stored_permissions); /*0.5*/
    READ_OR_BAIL(readLongLE, obj.user_id); /*0.5*/
    int links_len; READ_OR_BAIL(readUnsignedVarInt, links_len); /*1.5*/
    obj.links.resize(links_len); /*1.6*/
    for (int i = 0; i < links_len; i++) {
      auto &v2 = obj.links[i]; /*3.4*/
      pdef::proto::decode::Link(stream, v2); /*v2*/ /*4.6*/
    }
    int device_id_strlen; READ_OR_BAIL(readUnsignedVarInt, device_id_strlen);
    if (!stream.readString(obj.device_id, device_id_strlen)) return false; /*device_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readIntLE, (int32_t&)obj.device_os); /*7.2*/
    return true;
  }
  bool packet_add_entity(pdef::Stream &stream, pdef::proto::packet_add_entity &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.entity_id_self); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    int entity_type_strlen; READ_OR_BAIL(readUnsignedVarInt, entity_type_strlen);
    if (!stream.readString(obj.entity_type, entity_type_strlen)) return false; /*entity_type: pstring*/ /*4.3*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::vec3f(stream, obj.velocity); /*obj*/ /*4.6*/
    READ_OR_BAIL(readFloatLE, obj.pitch); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.head_yaw); /*0.5*/
    int attributes_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, attributes_len); /*2.6*/
    obj.attributes.resize(attributes_len); /*2.7*/
    for (int i = 0; i < attributes_len; i++) { pdef::proto::decode::EntityAttributes(stream, obj.attributes[i]); } /*2.8*/
    int metadata_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, metadata_len); /*2.6*/
    obj.metadata.resize(metadata_len); /*2.7*/
    for (int i = 0; i < metadata_len; i++) { pdef::proto::decode::MetadataDictionary(stream, obj.metadata[i]); } /*2.8*/
    int links_len; READ_OR_BAIL(readUnsignedVarInt, links_len); /*1.5*/
    obj.links.resize(links_len); /*1.6*/
    for (int i = 0; i < links_len; i++) {
      auto &v2 = obj.links[i]; /*3.4*/
      pdef::proto::decode::Link(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_remove_entity(pdef::Stream &stream, pdef::proto::packet_remove_entity &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.entity_id_self); /*0.5*/
    return true;
  }
  bool packet_add_item_entity(pdef::Stream &stream, pdef::proto::packet_add_item_entity &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.entity_id_self); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    pdef::proto::decode::Item(stream, obj.item); /*obj*/ /*4.6*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::vec3f(stream, obj.velocity); /*obj*/ /*4.6*/
    int metadata_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, metadata_len); /*2.6*/
    obj.metadata.resize(metadata_len); /*2.7*/
    for (int i = 0; i < metadata_len; i++) { pdef::proto::decode::MetadataDictionary(stream, obj.metadata[i]); } /*2.8*/
    READ_OR_BAIL(readBool, (bool&)obj.is_from_fishing); /*0.5*/
    return true;
  }
  bool packet_take_item_entity(pdef::Stream &stream, pdef::proto::packet_take_item_entity &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.target); /*0.5*/
    return true;
  }
  bool packet_move_entity(pdef::Stream &stream, pdef::proto::packet_move_entity &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readUByte, obj.flags); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::Rotation(stream, obj.rotation); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_move_player(pdef::Stream &stream, pdef::proto::packet_move_player &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.runtime_id); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readFloatLE, obj.pitch); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.yaw); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.head_yaw); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.mode); /*7.2*/
    const pdef::proto::packet_move_player::Mode &mode = obj.mode; /*0.7*/
    READ_OR_BAIL(readBool, (bool&)obj.on_ground); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.ridden_runtime_id); /*0.5*/
    switch (mode) { /*8.0*/
      case pdef::proto::packet_move_player::Mode::Teleport: { /*8.5*/
         obj.teleport = {}; pdef::proto::packet_move_player::Teleport &v = *obj.teleport; /*8.4*/
          READ_OR_BAIL(readIntLE, (int32_t&)v.cause); /*7.2*/
          READ_OR_BAIL(readIntLE, (int32_t&)v.source_entity_type); /*7.2*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    READ_OR_BAIL(readUnsignedVarLong, obj.tick); /*0.5*/
    return true;
  }
  bool packet_rider_jump(pdef::Stream &stream, pdef::proto::packet_rider_jump &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.jump_strength); /*0.5*/
    return true;
  }
  bool packet_update_block(pdef::Stream &stream, pdef::proto::packet_update_block &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUnsignedVarInt, obj.block_runtime_id); /*0.5*/
    int flags_val;
    READ_OR_BAIL(readUnsignedVarInt, flags_val);
    obj.flags.neighbors = (flags_val & 1) == 1;
    obj.flags.network = (flags_val & 2) == 2;
    obj.flags.no_graphic = (flags_val & 4) == 4;
    obj.flags.unused = (flags_val & 8) == 8;
    obj.flags.priority = (flags_val & 16) == 16; /*flags: bitflags*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.layer); /*0.5*/
    return true;
  }
  bool packet_add_painting(pdef::Stream &stream, pdef::proto::packet_add_painting &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.entity_id_self); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.coordinates); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.direction); /*0.5*/
    int title_strlen; READ_OR_BAIL(readUnsignedVarInt, title_strlen);
    if (!stream.readString(obj.title, title_strlen)) return false; /*title: pstring*/ /*4.3*/
    return true;
  }
  bool packet_tick_sync(pdef::Stream &stream, pdef::proto::packet_tick_sync &obj) {
    READ_OR_BAIL(readLongLE, obj.request_time); /*0.5*/
    READ_OR_BAIL(readLongLE, obj.response_time); /*0.5*/
    return true;
  }
  bool packet_level_sound_event_old(pdef::Stream &stream, pdef::proto::packet_level_sound_event_old &obj) {
    READ_OR_BAIL(readUByte, obj.sound_id); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.block_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.entity_type); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_baby_mob); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_global); /*0.5*/
    return true;
  }
  bool packet_level_event(pdef::Stream &stream, pdef::proto::packet_level_event &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.event); /*7.2*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.data); /*0.5*/
    return true;
  }
  bool packet_block_event(pdef::Stream &stream, pdef::proto::packet_block_event &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.type); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.data); /*0.5*/
    return true;
  }
  bool packet_entity_event(pdef::Stream &stream, pdef::proto::packet_entity_event &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.event_id); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.data); /*0.5*/
    return true;
  }
  bool packet_mob_effect(pdef::Stream &stream, pdef::proto::packet_mob_effect &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.event_id); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.effect_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.amplifier); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.particles); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.duration); /*0.5*/
    return true;
  }
  bool packet_update_attributes(pdef::Stream &stream, pdef::proto::packet_update_attributes &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    int attributes_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, attributes_len); /*2.6*/
    obj.attributes.resize(attributes_len); /*2.7*/
    for (int i = 0; i < attributes_len; i++) { pdef::proto::decode::PlayerAttributes(stream, obj.attributes[i]); } /*2.8*/
    READ_OR_BAIL(readUnsignedVarLong, obj.tick); /*0.5*/
    return true;
  }
  bool packet_inventory_transaction(pdef::Stream &stream, pdef::proto::packet_inventory_transaction &obj) {
    pdef::proto::decode::Transaction(stream, obj.transaction); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_mob_equipment(pdef::Stream &stream, pdef::proto::packet_mob_equipment &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    pdef::proto::decode::Item(stream, obj.item); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUByte, obj.slot); /*0.5*/
    READ_OR_BAIL(readUByte, obj.selected_slot); /*0.5*/
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    return true;
  }
  bool packet_mob_armor_equipment(pdef::Stream &stream, pdef::proto::packet_mob_armor_equipment &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    pdef::proto::decode::Item(stream, obj.helmet); /*obj*/ /*4.6*/
    pdef::proto::decode::Item(stream, obj.chestplate); /*obj*/ /*4.6*/
    pdef::proto::decode::Item(stream, obj.leggings); /*obj*/ /*4.6*/
    pdef::proto::decode::Item(stream, obj.boots); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_interact(pdef::Stream &stream, pdef::proto::packet_interact &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action_id); /*7.2*/
    const pdef::proto::packet_interact::ActionId &action_id = obj.action_id; /*0.7*/
    READ_OR_BAIL(readUnsignedVarLong, obj.target_entity_id); /*0.5*/
    switch (action_id) { /*8.0*/
      case pdef::proto::packet_interact::ActionId::MouseOverEntity: { /*8.5*/
        obj.position = {}; pdef::proto::decode::vec3f(stream, *obj.position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::packet_interact::ActionId::LeaveVehicle: { /*8.5*/
        obj.position = {}; pdef::proto::decode::vec3f(stream, *obj.position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_block_pick_request(pdef::Stream &stream, pdef::proto::packet_block_pick_request &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.x); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.y); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.z); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.add_user_data); /*0.5*/
    READ_OR_BAIL(readUByte, obj.selected_slot); /*0.5*/
    return true;
  }
  bool packet_entity_pick_request(pdef::Stream &stream, pdef::proto::packet_entity_pick_request &obj) {
    READ_OR_BAIL(readULongLE, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readUByte, obj.selected_slot); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.with_data); /*0.5*/
    return true;
  }
  bool packet_player_action(pdef::Stream &stream, pdef::proto::packet_player_action &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.action); /*7.2*/
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::BlockCoordinates(stream, obj.result_position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.face); /*0.5*/
    return true;
  }
  bool packet_hurt_armor(pdef::Stream &stream, pdef::proto::packet_hurt_armor &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.cause); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.damage); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.armor_slots); /*0.5*/
    return true;
  }
  bool packet_set_entity_data(pdef::Stream &stream, pdef::proto::packet_set_entity_data &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    int metadata_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, metadata_len); /*2.6*/
    obj.metadata.resize(metadata_len); /*2.7*/
    for (int i = 0; i < metadata_len; i++) { pdef::proto::decode::MetadataDictionary(stream, obj.metadata[i]); } /*2.8*/
    READ_OR_BAIL(readUnsignedVarLong, obj.tick); /*0.5*/
    return true;
  }
  bool packet_set_entity_motion(pdef::Stream &stream, pdef::proto::packet_set_entity_motion &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.velocity); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_set_entity_link(pdef::Stream &stream, pdef::proto::packet_set_entity_link &obj) {
    pdef::proto::decode::Link(stream, obj.link); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_set_health(pdef::Stream &stream, pdef::proto::packet_set_health &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.health); /*0.5*/
    return true;
  }
  bool packet_set_spawn_position(pdef::Stream &stream, pdef::proto::packet_set_spawn_position &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.spawn_type); /*7.2*/
    pdef::proto::decode::BlockCoordinates(stream, obj.player_position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.dimension); /*0.5*/
    pdef::proto::decode::BlockCoordinates(stream, obj.world_position); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_animate(pdef::Stream &stream, pdef::proto::packet_animate &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.action_id); /*7.2*/
    const pdef::proto::packet_animate::ActionId &action_id = obj.action_id; /*0.7*/
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    switch (action_id) { /*8.0*/
      case pdef::proto::packet_animate::ActionId::RowRight: { /*8.5*/
          READ_OR_BAIL(readFloatLE, obj.boat_rowing_time); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_animate::ActionId::RowLeft: { /*8.5*/
          READ_OR_BAIL(readFloatLE, obj.boat_rowing_time); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_respawn(pdef::Stream &stream, pdef::proto::packet_respawn &obj) {
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUByte, obj.state); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    return true;
  }
  bool packet_container_open(pdef::Stream &stream, pdef::proto::packet_container_open &obj) {
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readByte, (int8_t&)obj.window_type); /*7.2*/
    pdef::proto::decode::BlockCoordinates(stream, obj.coordinates); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarLong, obj.runtime_entity_id); /*0.5*/
    return true;
  }
  bool packet_container_close(pdef::Stream &stream, pdef::proto::packet_container_close &obj) {
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readBool, (bool&)obj.server); /*0.5*/
    return true;
  }
  bool packet_player_hotbar(pdef::Stream &stream, pdef::proto::packet_player_hotbar &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.selected_slot); /*0.5*/
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readBool, (bool&)obj.select_slot); /*0.5*/
    return true;
  }
  bool packet_inventory_content(pdef::Stream &stream, pdef::proto::packet_inventory_content &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.window_id); /*7.2*/
    int input_len; READ_OR_BAIL(readUnsignedVarInt, input_len); /*1.5*/
    obj.input.resize(input_len); /*1.6*/
    for (int i = 0; i < input_len; i++) {
      auto &v2 = obj.input[i]; /*3.4*/
      pdef::proto::decode::Item(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_inventory_slot(pdef::Stream &stream, pdef::proto::packet_inventory_slot &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readUnsignedVarInt, obj.slot); /*0.5*/
    pdef::proto::decode::Item(stream, obj.item); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_container_set_data(pdef::Stream &stream, pdef::proto::packet_container_set_data &obj) {
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.property); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.value); /*0.5*/
    return true;
  }
  bool packet_crafting_data(pdef::Stream &stream, pdef::proto::packet_crafting_data &obj) {
    int recipes_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, recipes_len); /*2.6*/
    obj.recipes.resize(recipes_len); /*2.7*/
    for (int i = 0; i < recipes_len; i++) { pdef::proto::decode::Recipes(stream, obj.recipes[i]); } /*2.8*/
    int potion_type_recipes_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, potion_type_recipes_len); /*2.6*/
    obj.potion_type_recipes.resize(potion_type_recipes_len); /*2.7*/
    for (int i = 0; i < potion_type_recipes_len; i++) { pdef::proto::decode::PotionTypeRecipes(stream, obj.potion_type_recipes[i]); } /*2.8*/
    int potion_container_recipes_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, potion_container_recipes_len); /*2.6*/
    obj.potion_container_recipes.resize(potion_container_recipes_len); /*2.7*/
    for (int i = 0; i < potion_container_recipes_len; i++) { pdef::proto::decode::PotionContainerChangeRecipes(stream, obj.potion_container_recipes[i]); } /*2.8*/
    int material_reducers_len; READ_OR_BAIL(readUnsignedVarInt, material_reducers_len); /*1.5*/
    obj.material_reducers.resize(material_reducers_len); /*1.6*/
    for (int i = 0; i < material_reducers_len; i++) {
      auto &v2 = obj.material_reducers[i]; /*3.4*/
      pdef::proto::decode::MaterialReducer(stream, v2); /*v2*/ /*4.6*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.clear_recipes); /*0.5*/
    return true;
  }
  bool packet_crafting_event(pdef::Stream &stream, pdef::proto::packet_crafting_event &obj) {
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.recipe_type); /*7.2*/
    READ_OR_BAIL(readULongBE, obj.recipe_id); /*0.5*/
    int input_len; READ_OR_BAIL(readUnsignedVarInt, input_len); /*1.5*/
    obj.input.resize(input_len); /*1.6*/
    for (int i = 0; i < input_len; i++) {
      auto &v2 = obj.input[i]; /*3.4*/
      pdef::proto::decode::Item(stream, v2); /*v2*/ /*4.6*/
    }
    int result_len; READ_OR_BAIL(readUnsignedVarInt, result_len); /*1.5*/
    obj.result.resize(result_len); /*1.6*/
    for (int i = 0; i < result_len; i++) {
      auto &v2 = obj.result[i]; /*3.4*/
      pdef::proto::decode::Item(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_gui_data_pick_item(pdef::Stream &stream, pdef::proto::packet_gui_data_pick_item &obj) {
    int item_name_strlen; READ_OR_BAIL(readUnsignedVarInt, item_name_strlen);
    if (!stream.readString(obj.item_name, item_name_strlen)) return false; /*item_name: pstring*/ /*4.3*/
    int item_effects_strlen; READ_OR_BAIL(readUnsignedVarInt, item_effects_strlen);
    if (!stream.readString(obj.item_effects, item_effects_strlen)) return false; /*item_effects: pstring*/ /*4.3*/
    READ_OR_BAIL(readIntLE, obj.hotbar_slot); /*0.5*/
    return true;
  }
  bool packet_adventure_settings(pdef::Stream &stream, pdef::proto::packet_adventure_settings &obj) {
    int flags_val;
    READ_OR_BAIL(readUnsignedVarInt, flags_val);
    obj.flags.world_immutable = (flags_val & 1) == 1;
    obj.flags.no_pvp = (flags_val & 2) == 2;
    obj.flags.auto_jump = (flags_val & 32) == 32;
    obj.flags.allow_flight = (flags_val & 64) == 64;
    obj.flags.no_clip = (flags_val & 128) == 128;
    obj.flags.world_builder = (flags_val & 256) == 256;
    obj.flags.flying = (flags_val & 512) == 512;
    obj.flags.muted = (flags_val & 1024) == 1024; /*flags: bitflags*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.command_permission); /*7.2*/
    int action_permissions_val;
    READ_OR_BAIL(readUnsignedVarInt, action_permissions_val);
    obj.action_permissions.mine = (action_permissions_val & 65537) == 65537;
    obj.action_permissions.doors_and_switches = (action_permissions_val & 65538) == 65538;
    obj.action_permissions.open_containers = (action_permissions_val & 65540) == 65540;
    obj.action_permissions.attack_players = (action_permissions_val & 65544) == 65544;
    obj.action_permissions.attack_mobs = (action_permissions_val & 65552) == 65552;
    obj.action_permissions.operator_ = (action_permissions_val & 65568) == 65568;
    obj.action_permissions.teleport = (action_permissions_val & 65664) == 65664;
    obj.action_permissions.build = (action_permissions_val & 65792) == 65792;
    obj.action_permissions.default_ = (action_permissions_val & 66048) == 66048; /*action_permissions: bitflags*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.permission_level); /*7.2*/
    READ_OR_BAIL(readUnsignedVarInt, obj.custom_stored_permissions); /*0.5*/
    READ_OR_BAIL(readLongLE, obj.user_id); /*0.5*/
    return true;
  }
  bool packet_block_entity_data(pdef::Stream &stream, pdef::proto::packet_block_entity_data &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_player_input(pdef::Stream &stream, pdef::proto::packet_player_input &obj) {
    READ_OR_BAIL(readFloatLE, obj.motion_x); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.motion_z); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.jumping); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.sneaking); /*0.5*/
    return true;
  }
  bool packet_level_chunk(pdef::Stream &stream, pdef::proto::packet_level_chunk &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.x); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.z); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.sub_chunk_count); /*0.5*/
    int &sub_chunk_count = obj.sub_chunk_count; /*0.6*/
    if (sub_chunk_count == -2) { /*8.2*/
      READ_OR_BAIL(readUShortLE, obj.highest_subchunk_count); /*0.5*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.cache_enabled); /*0.5*/
    bool &cache_enabled = obj.cache_enabled; /*0.6*/
    if (cache_enabled == true) { /*8.1*/
         obj.blobs = {}; pdef::proto::packet_level_chunk::Blobs &v = *obj.blobs; /*8.4*/
        int hashes_len; READ_OR_BAIL(readUnsignedVarInt, hashes_len); /*1.5*/
        v.hashes.resize(hashes_len); /*1.6*/
        for (int i = 0; i < hashes_len; i++) {
          auto &v4 = v.hashes[i]; /*3.4*/
          READ_OR_BAIL(readULongLE, v4); /*0.5*/
        }
    }
    int payload_len; READ_OR_BAIL(readUnsignedVarInt, payload_len);if (!stream.readBuffer(obj.payload, payload_len)) return false; /*payload: buffer*/ /*4.3*/
    return true;
  }
  bool packet_set_commands_enabled(pdef::Stream &stream, pdef::proto::packet_set_commands_enabled &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.enabled); /*0.5*/
    return true;
  }
  bool packet_set_difficulty(pdef::Stream &stream, pdef::proto::packet_set_difficulty &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.difficulty); /*0.5*/
    return true;
  }
  bool packet_change_dimension(pdef::Stream &stream, pdef::proto::packet_change_dimension &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.dimension); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readBool, (bool&)obj.respawn); /*0.5*/
    return true;
  }
  bool packet_set_player_game_type(pdef::Stream &stream, pdef::proto::packet_set_player_game_type &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.gamemode); /*7.2*/
    return true;
  }
  bool packet_player_list(pdef::Stream &stream, pdef::proto::packet_player_list &obj) {
    pdef::proto::decode::PlayerRecords(stream, obj.records); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_simple_event(pdef::Stream &stream, pdef::proto::packet_simple_event &obj) {
    READ_OR_BAIL(readUShortLE, (uint16_t&)obj.event_type); /*7.2*/
    return true;
  }
  bool packet_event(pdef::Stream &stream, pdef::proto::packet_event &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.event_type); /*7.2*/
    READ_OR_BAIL(readUByte, obj.use_player_id); /*0.5*/
    READ_OR_BAIL(readByte, obj.event_data); /*0.5*/
    return true;
  }
  bool packet_spawn_experience_orb(pdef::Stream &stream, pdef::proto::packet_spawn_experience_orb &obj) {
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.count); /*0.5*/
    return true;
  }
  bool packet_clientbound_map_item_data(pdef::Stream &stream, pdef::proto::packet_clientbound_map_item_data &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.map_id); /*0.5*/
    int update_flags_val;
    READ_OR_BAIL(readUnsignedVarInt, update_flags_val);
    obj.update_flags.void_ = update_flags_val & ((int)1 << 0);
    obj.update_flags.texture = update_flags_val & ((int)1 << 1);
    obj.update_flags.decoration = update_flags_val & ((int)1 << 2);
    obj.update_flags.initialisation = update_flags_val & ((int)1 << 3); /*update_flags: bitflags*/ /*4.3*/
    pdef::proto::packet_clientbound_map_item_data::update_flags_t &update_flags = obj.update_flags; /*0.7*/
    READ_OR_BAIL(readUByte, obj.dimension); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.locked); /*0.5*/
    if (update_flags.initialisation == true) { /*8.2*/
      int included_in_len; READ_OR_BAIL(readUnsignedVarInt, included_in_len); /*1.5*/
      obj.included_in.resize(included_in_len); /*1.6*/
      for (int i = 0; i < included_in_len; i++) {
        auto &v3 = obj.included_in[i]; /*3.4*/
        READ_OR_BAIL(readZigZagVarLong, v3); /*0.5*/
      }
    }
    if ((update_flags.initialisation || update_flags.decoration || update_flags.texture) == true) { /*8.2*/
      READ_OR_BAIL(readUByte, obj.scale); /*0.5*/
    }
    if (update_flags.decoration == true) { /*8.2*/
         obj.tracked = {}; pdef::proto::packet_clientbound_map_item_data::Tracked &v = *obj.tracked; /*8.4*/
        int objects_len; READ_OR_BAIL(readUnsignedVarInt, objects_len); /*1.5*/
        v.objects.resize(objects_len); /*1.6*/
        for (int i = 0; i < objects_len; i++) {
          auto &v4 = v.objects[i]; /*3.4*/
          pdef::proto::decode::TrackedObject(stream, v4); /*v4*/ /*4.6*/
        }
        int decorations_len; READ_OR_BAIL(readUnsignedVarInt, decorations_len); /*1.5*/
        v.decorations.resize(decorations_len); /*1.6*/
        for (int i = 0; i < decorations_len; i++) {
          auto &v4 = v.decorations[i]; /*3.4*/
          pdef::proto::decode::MapDecoration(stream, v4); /*v4*/ /*4.6*/
        }
    }
    if (update_flags.texture == true) { /*8.2*/
         obj.texture = {}; pdef::proto::packet_clientbound_map_item_data::Texture &v = *obj.texture; /*8.4*/
        READ_OR_BAIL(readZigZagVarInt, v.width); /*0.5*/
        READ_OR_BAIL(readZigZagVarInt, v.height); /*0.5*/
        READ_OR_BAIL(readZigZagVarInt, v.x_offset); /*0.5*/
        READ_OR_BAIL(readZigZagVarInt, v.y_offset); /*0.5*/
        int pixels_len; READ_OR_BAIL(readUnsignedVarInt, pixels_len); /*1.5*/
        v.pixels.resize(pixels_len); /*1.6*/
        for (int i = 0; i < pixels_len; i++) {
          auto &v4 = v.pixels[i]; /*3.4*/
          READ_OR_BAIL(readUnsignedVarInt, v4); /*0.5*/
        }
    }
    return true;
  }
  bool packet_map_info_request(pdef::Stream &stream, pdef::proto::packet_map_info_request &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.map_id); /*0.5*/
    return true;
  }
  bool packet_request_chunk_radius(pdef::Stream &stream, pdef::proto::packet_request_chunk_radius &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.chunk_radius); /*0.5*/
    return true;
  }
  bool packet_chunk_radius_update(pdef::Stream &stream, pdef::proto::packet_chunk_radius_update &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.chunk_radius); /*0.5*/
    return true;
  }
  bool packet_item_frame_drop_item(pdef::Stream &stream, pdef::proto::packet_item_frame_drop_item &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.coordinates); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_game_rules_changed(pdef::Stream &stream, pdef::proto::packet_game_rules_changed &obj) {
    int rules_len; READ_OR_BAIL(readUnsignedVarInt, rules_len); /*1.5*/
    obj.rules.resize(rules_len); /*1.6*/
    for (int i = 0; i < rules_len; i++) {
      auto &v2 = obj.rules[i]; /*3.4*/
      pdef::proto::decode::GameRule(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_camera(pdef::Stream &stream, pdef::proto::packet_camera &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.camera_entity_unique_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.target_player_unique_id); /*0.5*/
    return true;
  }
  bool packet_boss_event(pdef::Stream &stream, pdef::proto::packet_boss_event &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.boss_entity_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.type); /*7.2*/
    const pdef::proto::packet_boss_event::Type &type = obj.type; /*0.7*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_boss_event::Type::ShowBar: { /*8.5*/
          int title_strlen; READ_OR_BAIL(readUnsignedVarInt, title_strlen);
          if (!stream.readString(obj.title, title_strlen)) return false; /*title: pstring*/ /*4.3*/
          READ_OR_BAIL(readFloatLE, obj.progress); /*0.5*/
          READ_OR_BAIL(readShortLE, obj.screen_darkening); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.color); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.overlay); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::RegisterPlayer: { /*8.5*/
          READ_OR_BAIL(readZigZagVarLong, obj.player_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::UnregisterPlayer: { /*8.5*/
          READ_OR_BAIL(readZigZagVarLong, obj.player_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::Query: { /*8.5*/
          READ_OR_BAIL(readZigZagVarLong, obj.player_id); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::SetBarProgress: { /*8.5*/
          READ_OR_BAIL(readFloatLE, obj.progress); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::SetBarTitle: { /*8.5*/
          int title_strlen; READ_OR_BAIL(readUnsignedVarInt, title_strlen);
          if (!stream.readString(obj.title, title_strlen)) return false; /*title: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::UpdateProperties: { /*8.5*/
          READ_OR_BAIL(readShortLE, obj.screen_darkening); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.color); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.overlay); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_boss_event::Type::Texture: { /*8.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.color); /*0.5*/
          READ_OR_BAIL(readUnsignedVarInt, obj.overlay); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_show_credits(pdef::Stream &stream, pdef::proto::packet_show_credits &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.status); /*0.5*/
    return true;
  }
  bool packet_available_commands(pdef::Stream &stream, pdef::proto::packet_available_commands &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.values_len); /*0.5*/
    int &values_len = obj.values_len; /*0.6*/
    pdef::proto::packet_available_commands::_EnumType _enum_type; if (values_len <= 0xff) { _enum_type = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { _enum_type = pdef::proto::packet_available_commands::_EnumType::Short; } else { _enum_type = pdef::proto::packet_available_commands::_EnumType::Int; } /*_enum_type: enum_size_based_on_values_len*/ /*4.3*/
    obj.enum_values.resize(values_len); /*1.6*/
    for (int i = 0; i < values_len; i++) {
      auto &v2 = obj.enum_values[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    int suffixes_len; READ_OR_BAIL(readUnsignedVarInt, suffixes_len); /*1.5*/
    obj.suffixes.resize(suffixes_len); /*1.6*/
    for (int i = 0; i < suffixes_len; i++) {
      auto &v2 = obj.suffixes[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    int enums_len; READ_OR_BAIL(readUnsignedVarInt, enums_len); /*1.5*/
    obj.enums.resize(enums_len); /*1.6*/
    for (int i = 0; i < enums_len; i++) { /*5*/
      pdef::proto::packet_available_commands::Enums &v2 = obj.enums[i]; /*5.23*/
      int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
      if (!stream.readString(v2.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
      if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Byte) { /*8.5*/
        READ_OR_BAIL(readUByte, v2.values_u8); /*0.5*/
      }
      else if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Short) { /*8.5*/
        READ_OR_BAIL(readUShortLE, v2.values_lu16); /*0.5*/
      }
      else if (_enum_type == pdef::proto::packet_available_commands::_EnumType::Int) { /*8.5*/
        READ_OR_BAIL(readUIntLE, v2.values_lu32); /*0.5*/
      }
    }
    int command_data_len; READ_OR_BAIL(readUnsignedVarInt, command_data_len); /*1.5*/
    obj.command_data.resize(command_data_len); /*1.6*/
    for (int i = 0; i < command_data_len; i++) { /*5*/
      pdef::proto::packet_available_commands::CommandData &v2 = obj.command_data[i]; /*5.23*/
      int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
      if (!stream.readString(v2.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
      int description_strlen; READ_OR_BAIL(readUnsignedVarInt, description_strlen);
      if (!stream.readString(v2.description, description_strlen)) return false; /*description: pstring*/ /*4.3*/
      READ_OR_BAIL(readUShortLE, v2.flags); /*0.5*/
      READ_OR_BAIL(readUByte, v2.permission_level); /*0.5*/
      READ_OR_BAIL(readIntLE, v2.alias); /*0.5*/
      int overloads_len; READ_OR_BAIL(readUnsignedVarInt, overloads_len); /*1.5*/
      v2.overloads.resize(overloads_len); /*1.6*/
      for (int i = 0; i < overloads_len; i++) { /*5*/
        pdef::proto::packet_available_commands::CommandData::Overloads &v3 = v2.overloads[i]; /*5.23*/
        int parameters_len; READ_OR_BAIL(readUnsignedVarInt, parameters_len); /*1.5*/
        v3.parameters.resize(parameters_len); /*1.6*/
        for (int i = 0; i < parameters_len; i++) { /*5*/
          pdef::proto::packet_available_commands::CommandData::Overloads::Parameters &v4 = v3.parameters[i]; /*5.23*/
          int parameter_name_strlen; READ_OR_BAIL(readUnsignedVarInt, parameter_name_strlen);
          if (!stream.readString(v4.parameter_name, parameter_name_strlen)) return false; /*parameter_name: pstring*/ /*4.3*/
          READ_OR_BAIL(readUShortLE, (uint16_t&)v4.value_type); /*7.2*/
          READ_OR_BAIL(readUShortLE, (uint16_t&)v4.enum_type); /*7.2*/
          READ_OR_BAIL(readBool, (bool&)v4.optional); /*0.5*/
          uint8_t options_val;
          READ_OR_BAIL(readUByte, options_val);
          v4.options.unused = options_val >> 0 & 1;
          v4.options.collapse_enum = options_val >> 1 & 1;
          v4.options.has_semantic_constraint = options_val >> 2 & 1;
          v4.options.as_chained_command = options_val >> 3 & 1;
          v4.options.unknown2 = options_val >> 4 & 4; /*options: bitfield*/ /*4.3*/
        }
      }
    }
    int dynamic_enums_len; READ_OR_BAIL(readUnsignedVarInt, dynamic_enums_len); /*1.5*/
    obj.dynamic_enums.resize(dynamic_enums_len); /*1.6*/
    for (int i = 0; i < dynamic_enums_len; i++) { /*5*/
      pdef::proto::packet_available_commands::DynamicEnums &v2 = obj.dynamic_enums[i]; /*5.23*/
      int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
      if (!stream.readString(v2.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
      int values_len; READ_OR_BAIL(readUnsignedVarInt, values_len); /*1.5*/
      v2.values.resize(values_len); /*1.6*/
      for (int i = 0; i < values_len; i++) {
        auto &v3 = v2.values[i]; /*3.4*/
        int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
        if (!stream.readString(v3, _strlen)) return false; /*: pstring*/ /*4.3*/
      }
    }
    int enum_constraints_len; READ_OR_BAIL(readUnsignedVarInt, enum_constraints_len); /*1.5*/
    obj.enum_constraints.resize(enum_constraints_len); /*1.6*/
    for (int i = 0; i < enum_constraints_len; i++) { /*5*/
      pdef::proto::packet_available_commands::EnumConstraints &v2 = obj.enum_constraints[i]; /*5.23*/
      READ_OR_BAIL(readIntLE, v2.value_index); /*0.5*/
      READ_OR_BAIL(readIntLE, v2.enum_index); /*0.5*/
      int constraints_len; READ_OR_BAIL(readUnsignedVarInt, constraints_len); /*1.5*/
      v2.constraints.resize(constraints_len); /*1.6*/
      for (int i = 0; i < constraints_len; i++) { /*5*/
        pdef::proto::packet_available_commands::EnumConstraints::Constraints &v3 = v2.constraints[i]; /*5.23*/
        READ_OR_BAIL(readUByte, (uint8_t&)v3.constraint); /*7.2*/
      }
    }
    return true;
  }
  bool packet_command_request(pdef::Stream &stream, pdef::proto::packet_command_request &obj) {
    int command_strlen; READ_OR_BAIL(readUnsignedVarInt, command_strlen);
    if (!stream.readString(obj.command, command_strlen)) return false; /*command: pstring*/ /*4.3*/
    pdef::proto::decode::CommandOrigin(stream, obj.origin); /*obj*/ /*4.6*/
    READ_OR_BAIL(readBool, (bool&)obj.internal); /*0.5*/
    return true;
  }
  bool packet_command_block_update(pdef::Stream &stream, pdef::proto::packet_command_block_update &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.is_block); /*0.5*/
    bool &is_block = obj.is_block; /*0.6*/
    if (is_block == true) { /*8.1*/
        obj.position = {}; pdef::proto::decode::BlockCoordinates(stream, *obj.position); /*obj*/ /*4.6*/
        READ_OR_BAIL(readUnsignedVarInt, (int&)obj.mode); /*7.2*/
        READ_OR_BAIL(readBool, (bool&)obj.needs_redstone); /*0.5*/
        READ_OR_BAIL(readBool, (bool&)obj.conditional); /*0.5*/
    }
    else if (is_block == false) { /*8.1*/
        READ_OR_BAIL(readUnsignedVarLong, obj.minecart_entity_runtime_id); /*0.5*/
    }
    int command_strlen; READ_OR_BAIL(readUnsignedVarInt, command_strlen);
    if (!stream.readString(obj.command, command_strlen)) return false; /*command: pstring*/ /*4.3*/
    int last_output_strlen; READ_OR_BAIL(readUnsignedVarInt, last_output_strlen);
    if (!stream.readString(obj.last_output, last_output_strlen)) return false; /*last_output: pstring*/ /*4.3*/
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.should_track_output); /*0.5*/
    READ_OR_BAIL(readIntLE, obj.tick_delay); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.execute_on_first_tick); /*0.5*/
    return true;
  }
  bool packet_command_output(pdef::Stream &stream, pdef::proto::packet_command_output &obj) {
    pdef::proto::decode::CommandOrigin(stream, obj.origin); /*obj*/ /*4.6*/
    READ_OR_BAIL(readByte, (int8_t&)obj.output_type); /*7.2*/
    const pdef::proto::packet_command_output::OutputType &output_type = obj.output_type; /*0.7*/
    READ_OR_BAIL(readUnsignedVarInt, obj.success_count); /*0.5*/
    int output_len; READ_OR_BAIL(readUnsignedVarInt, output_len); /*1.5*/
    obj.output.resize(output_len); /*1.6*/
    for (int i = 0; i < output_len; i++) { /*5*/
      pdef::proto::packet_command_output::Output &v2 = obj.output[i]; /*5.23*/
      READ_OR_BAIL(readBool, (bool&)v2.success); /*0.5*/
      int message_id_strlen; READ_OR_BAIL(readUnsignedVarInt, message_id_strlen);
      if (!stream.readString(v2.message_id, message_id_strlen)) return false; /*message_id: pstring*/ /*4.3*/
      int parameters_len; READ_OR_BAIL(readUnsignedVarInt, parameters_len); /*1.5*/
      v2.parameters.resize(parameters_len); /*1.6*/
      for (int i = 0; i < parameters_len; i++) {
        auto &v3 = v2.parameters[i]; /*3.4*/
        int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
        if (!stream.readString(v3, _strlen)) return false; /*: pstring*/ /*4.3*/
      }
    }
    switch (output_type) { /*8.0*/
      case pdef::proto::packet_command_output::OutputType::DataSet: { /*8.5*/
        int data_set_strlen; READ_OR_BAIL(readUnsignedVarInt, data_set_strlen);
        if (!stream.readString(obj.data_set, data_set_strlen)) return false; /*data_set: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_update_trade(pdef::Stream &stream, pdef::proto::packet_update_trade &obj) {
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readByte, (int8_t&)obj.window_type); /*7.2*/
    READ_OR_BAIL(readUnsignedVarInt, obj.size); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, obj.trade_tier); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.villager_unique_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.entity_unique_id); /*0.5*/
    int display_name_strlen; READ_OR_BAIL(readUnsignedVarInt, display_name_strlen);
    if (!stream.readString(obj.display_name, display_name_strlen)) return false; /*display_name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.new_trading_ui); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.economic_trades); /*0.5*/
    READ_OR_BAIL(readByte, obj.offers); /*0.5*/
    return true;
  }
  bool packet_update_equipment(pdef::Stream &stream, pdef::proto::packet_update_equipment &obj) {
    READ_OR_BAIL(readByte, (int8_t&)obj.window_id); /*7.2*/
    READ_OR_BAIL(readByte, (int8_t&)obj.window_type); /*7.2*/
    READ_OR_BAIL(readUByte, obj.size); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.entity_id); /*0.5*/
    READ_OR_BAIL(readByte, obj.inventory); /*0.5*/
    return true;
  }
  bool packet_resource_pack_data_info(pdef::Stream &stream, pdef::proto::packet_resource_pack_data_info &obj) {
    int pack_id_strlen; READ_OR_BAIL(readUnsignedVarInt, pack_id_strlen);
    if (!stream.readString(obj.pack_id, pack_id_strlen)) return false; /*pack_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readUIntLE, obj.max_chunk_size); /*0.5*/
    READ_OR_BAIL(readUIntLE, obj.chunk_count); /*0.5*/
    READ_OR_BAIL(readULongLE, obj.size); /*0.5*/
    int hash_len; READ_OR_BAIL(readUnsignedVarInt, hash_len);if (!stream.readBuffer(obj.hash, hash_len)) return false; /*hash: buffer*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.is_premium); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.pack_type); /*7.2*/
    return true;
  }
  bool packet_resource_pack_chunk_data(pdef::Stream &stream, pdef::proto::packet_resource_pack_chunk_data &obj) {
    int pack_id_strlen; READ_OR_BAIL(readUnsignedVarInt, pack_id_strlen);
    if (!stream.readString(obj.pack_id, pack_id_strlen)) return false; /*pack_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readUIntLE, obj.chunk_index); /*0.5*/
    READ_OR_BAIL(readULongLE, obj.progress); /*0.5*/
    int payload_len; READ_OR_BAIL(readUnsignedVarInt, payload_len);if (!stream.readBuffer(obj.payload, payload_len)) return false; /*payload: buffer*/ /*4.3*/
    return true;
  }
  bool packet_resource_pack_chunk_request(pdef::Stream &stream, pdef::proto::packet_resource_pack_chunk_request &obj) {
    int pack_id_strlen; READ_OR_BAIL(readUnsignedVarInt, pack_id_strlen);
    if (!stream.readString(obj.pack_id, pack_id_strlen)) return false; /*pack_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readUIntLE, obj.chunk_index); /*0.5*/
    return true;
  }
  bool packet_transfer(pdef::Stream &stream, pdef::proto::packet_transfer &obj) {
    int server_address_strlen; READ_OR_BAIL(readUnsignedVarInt, server_address_strlen);
    if (!stream.readString(obj.server_address, server_address_strlen)) return false; /*server_address: pstring*/ /*4.3*/
    READ_OR_BAIL(readUShortLE, obj.port); /*0.5*/
    return true;
  }
  bool packet_play_sound(pdef::Stream &stream, pdef::proto::packet_play_sound &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    pdef::proto::decode::BlockCoordinates(stream, obj.coordinates); /*obj*/ /*4.6*/
    READ_OR_BAIL(readFloatLE, obj.volume); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.pitch); /*0.5*/
    return true;
  }
  bool packet_stop_sound(pdef::Stream &stream, pdef::proto::packet_stop_sound &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.stop_all); /*0.5*/
    return true;
  }
  bool packet_set_title(pdef::Stream &stream, pdef::proto::packet_set_title &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.type); /*7.2*/
    int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
    if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarInt, obj.fade_in_time); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.stay_time); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.fade_out_time); /*0.5*/
    int xuid_strlen; READ_OR_BAIL(readUnsignedVarInt, xuid_strlen);
    if (!stream.readString(obj.xuid, xuid_strlen)) return false; /*xuid: pstring*/ /*4.3*/
    int platform_online_id_strlen; READ_OR_BAIL(readUnsignedVarInt, platform_online_id_strlen);
    if (!stream.readString(obj.platform_online_id, platform_online_id_strlen)) return false; /*platform_online_id: pstring*/ /*4.3*/
    return true;
  }
  bool packet_add_behavior_tree(pdef::Stream &stream, pdef::proto::packet_add_behavior_tree &obj) {
    int behaviortree_strlen; READ_OR_BAIL(readUnsignedVarInt, behaviortree_strlen);
    if (!stream.readString(obj.behaviortree, behaviortree_strlen)) return false; /*behaviortree: pstring*/ /*4.3*/
    return true;
  }
  bool packet_structure_block_update(pdef::Stream &stream, pdef::proto::packet_structure_block_update &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    int structure_name_strlen; READ_OR_BAIL(readUnsignedVarInt, structure_name_strlen);
    if (!stream.readString(obj.structure_name, structure_name_strlen)) return false; /*structure_name: pstring*/ /*4.3*/
    int data_field_strlen; READ_OR_BAIL(readUnsignedVarInt, data_field_strlen);
    if (!stream.readString(obj.data_field, data_field_strlen)) return false; /*data_field: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.include_players); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.show_bounding_box); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.structure_block_type); /*0.5*/
    pdef::proto::decode::StructureBlockSettings(stream, obj.settings); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.redstone_save_mode); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.should_trigger); /*0.5*/
    return true;
  }
  bool packet_show_store_offer(pdef::Stream &stream, pdef::proto::packet_show_store_offer &obj) {
    int offer_id_strlen; READ_OR_BAIL(readUnsignedVarInt, offer_id_strlen);
    if (!stream.readString(obj.offer_id, offer_id_strlen)) return false; /*offer_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.show_all); /*0.5*/
    return true;
  }
  bool packet_purchase_receipt(pdef::Stream &stream, pdef::proto::packet_purchase_receipt &obj) {
    int receipts_len; READ_OR_BAIL(readUnsignedVarInt, receipts_len); /*1.5*/
    obj.receipts.resize(receipts_len); /*1.6*/
    for (int i = 0; i < receipts_len; i++) {
      auto &v2 = obj.receipts[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    return true;
  }
  bool packet_player_skin(pdef::Stream &stream, pdef::proto::packet_player_skin &obj) {
    READ_OR_BAIL(readULongBE, obj.uuid); /*0.5*/
    pdef::proto::decode::Skin(stream, obj.skin); /*obj*/ /*4.6*/
    int skin_name_strlen; READ_OR_BAIL(readUnsignedVarInt, skin_name_strlen);
    if (!stream.readString(obj.skin_name, skin_name_strlen)) return false; /*skin_name: pstring*/ /*4.3*/
    int old_skin_name_strlen; READ_OR_BAIL(readUnsignedVarInt, old_skin_name_strlen);
    if (!stream.readString(obj.old_skin_name, old_skin_name_strlen)) return false; /*old_skin_name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.is_verified); /*0.5*/
    return true;
  }
  bool packet_sub_client_login(pdef::Stream &stream, pdef::proto::packet_sub_client_login &obj) {
    READ_OR_BAIL(readByte, obj.tokens); /*0.5*/
    return true;
  }
  bool packet_initiate_web_socket_connection(pdef::Stream &stream, pdef::proto::packet_initiate_web_socket_connection &obj) {
    int server_strlen; READ_OR_BAIL(readUnsignedVarInt, server_strlen);
    if (!stream.readString(obj.server, server_strlen)) return false; /*server: pstring*/ /*4.3*/
    return true;
  }
  bool packet_set_last_hurt_by(pdef::Stream &stream, pdef::proto::packet_set_last_hurt_by &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.entity_type); /*0.5*/
    return true;
  }
  bool packet_book_edit(pdef::Stream &stream, pdef::proto::packet_book_edit &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.type); /*7.2*/
    const pdef::proto::packet_book_edit::Type &type = obj.type; /*0.7*/
    READ_OR_BAIL(readUByte, obj.slot); /*0.5*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_book_edit::Type::ReplacePage: { /*8.5*/
          READ_OR_BAIL(readUByte, obj.page_number); /*0.5*/
          int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
          if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
          int photo_name_strlen; READ_OR_BAIL(readUnsignedVarInt, photo_name_strlen);
          if (!stream.readString(obj.photo_name, photo_name_strlen)) return false; /*photo_name: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::AddPage: { /*8.5*/
          READ_OR_BAIL(readUByte, obj.page_number); /*0.5*/
          int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
          if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
          int photo_name_strlen; READ_OR_BAIL(readUnsignedVarInt, photo_name_strlen);
          if (!stream.readString(obj.photo_name, photo_name_strlen)) return false; /*photo_name: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::DeletePage: { /*8.5*/
          READ_OR_BAIL(readUByte, obj.page_number); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::SwapPages: { /*8.5*/
          READ_OR_BAIL(readUByte, obj.page1); /*0.5*/
          READ_OR_BAIL(readUByte, obj.page2); /*0.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_book_edit::Type::Sign: { /*8.5*/
          int title_strlen; READ_OR_BAIL(readUnsignedVarInt, title_strlen);
          if (!stream.readString(obj.title, title_strlen)) return false; /*title: pstring*/ /*4.3*/
          int author_strlen; READ_OR_BAIL(readUnsignedVarInt, author_strlen);
          if (!stream.readString(obj.author, author_strlen)) return false; /*author: pstring*/ /*4.3*/
          int xuid_strlen; READ_OR_BAIL(readUnsignedVarInt, xuid_strlen);
          if (!stream.readString(obj.xuid, xuid_strlen)) return false; /*xuid: pstring*/ /*4.3*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_npc_request(pdef::Stream &stream, pdef::proto::packet_npc_request &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.request_type); /*7.2*/
    int command_strlen; READ_OR_BAIL(readUnsignedVarInt, command_strlen);
    if (!stream.readString(obj.command, command_strlen)) return false; /*command: pstring*/ /*4.3*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action_type); /*7.2*/
    int scene_name_strlen; READ_OR_BAIL(readUnsignedVarInt, scene_name_strlen);
    if (!stream.readString(obj.scene_name, scene_name_strlen)) return false; /*scene_name: pstring*/ /*4.3*/
    return true;
  }
  bool packet_photo_transfer(pdef::Stream &stream, pdef::proto::packet_photo_transfer &obj) {
    int image_name_strlen; READ_OR_BAIL(readUnsignedVarInt, image_name_strlen);
    if (!stream.readString(obj.image_name, image_name_strlen)) return false; /*image_name: pstring*/ /*4.3*/
    int image_data_strlen; READ_OR_BAIL(readUnsignedVarInt, image_data_strlen);
    if (!stream.readString(obj.image_data, image_data_strlen)) return false; /*image_data: pstring*/ /*4.3*/
    int book_id_strlen; READ_OR_BAIL(readUnsignedVarInt, book_id_strlen);
    if (!stream.readString(obj.book_id, book_id_strlen)) return false; /*book_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readUByte, obj.photo_type); /*0.5*/
    READ_OR_BAIL(readUByte, obj.source_type); /*0.5*/
    READ_OR_BAIL(readLongLE, obj.owner_entity_unique_id); /*0.5*/
    int new_photo_name_strlen; READ_OR_BAIL(readUnsignedVarInt, new_photo_name_strlen);
    if (!stream.readString(obj.new_photo_name, new_photo_name_strlen)) return false; /*new_photo_name: pstring*/ /*4.3*/
    return true;
  }
  bool packet_modal_form_request(pdef::Stream &stream, pdef::proto::packet_modal_form_request &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.form_id); /*0.5*/
    int data_strlen; READ_OR_BAIL(readUnsignedVarInt, data_strlen);
    if (!stream.readString(obj.data, data_strlen)) return false; /*data: pstring*/ /*4.3*/
    return true;
  }
  bool packet_modal_form_response(pdef::Stream &stream, pdef::proto::packet_modal_form_response &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.form_id); /*0.5*/
    int data_strlen; READ_OR_BAIL(readUnsignedVarInt, data_strlen);
    if (!stream.readString(obj.data, data_strlen)) return false; /*data: pstring*/ /*4.3*/
    return true;
  }
  bool packet_server_settings_request(pdef::Stream &stream, pdef::proto::packet_server_settings_request &obj) {
    return true;
  }
  bool packet_server_settings_response(pdef::Stream &stream, pdef::proto::packet_server_settings_response &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.form_id); /*0.5*/
    int data_strlen; READ_OR_BAIL(readUnsignedVarInt, data_strlen);
    if (!stream.readString(obj.data, data_strlen)) return false; /*data: pstring*/ /*4.3*/
    return true;
  }
  bool packet_show_profile(pdef::Stream &stream, pdef::proto::packet_show_profile &obj) {
    int xuid_strlen; READ_OR_BAIL(readUnsignedVarInt, xuid_strlen);
    if (!stream.readString(obj.xuid, xuid_strlen)) return false; /*xuid: pstring*/ /*4.3*/
    return true;
  }
  bool packet_set_default_game_type(pdef::Stream &stream, pdef::proto::packet_set_default_game_type &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.gamemode); /*7.2*/
    return true;
  }
  bool packet_remove_objective(pdef::Stream &stream, pdef::proto::packet_remove_objective &obj) {
    int objective_name_strlen; READ_OR_BAIL(readUnsignedVarInt, objective_name_strlen);
    if (!stream.readString(obj.objective_name, objective_name_strlen)) return false; /*objective_name: pstring*/ /*4.3*/
    return true;
  }
  bool packet_set_display_objective(pdef::Stream &stream, pdef::proto::packet_set_display_objective &obj) {
    int display_slot_strlen; READ_OR_BAIL(readUnsignedVarInt, display_slot_strlen);
    if (!stream.readString(obj.display_slot, display_slot_strlen)) return false; /*display_slot: pstring*/ /*4.3*/
    int objective_name_strlen; READ_OR_BAIL(readUnsignedVarInt, objective_name_strlen);
    if (!stream.readString(obj.objective_name, objective_name_strlen)) return false; /*objective_name: pstring*/ /*4.3*/
    int display_name_strlen; READ_OR_BAIL(readUnsignedVarInt, display_name_strlen);
    if (!stream.readString(obj.display_name, display_name_strlen)) return false; /*display_name: pstring*/ /*4.3*/
    int criteria_name_strlen; READ_OR_BAIL(readUnsignedVarInt, criteria_name_strlen);
    if (!stream.readString(obj.criteria_name, criteria_name_strlen)) return false; /*criteria_name: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarInt, obj.sort_order); /*0.5*/
    return true;
  }
  bool packet_set_score(pdef::Stream &stream, pdef::proto::packet_set_score &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action); /*7.2*/
    const pdef::proto::packet_set_score::Action &action = obj.action; /*0.7*/
    int entries_len; READ_OR_BAIL(readUnsignedVarInt, entries_len); /*1.5*/
    obj.entries.resize(entries_len); /*1.6*/
    for (int i = 0; i < entries_len; i++) { /*5*/
      pdef::proto::packet_set_score::Entries &v2 = obj.entries[i]; /*5.23*/
      READ_OR_BAIL(readZigZagVarLong, v2.scoreboard_id); /*0.5*/
      int objective_name_strlen; READ_OR_BAIL(readUnsignedVarInt, objective_name_strlen);
      if (!stream.readString(v2.objective_name, objective_name_strlen)) return false; /*objective_name: pstring*/ /*4.3*/
      READ_OR_BAIL(readIntLE, v2.score); /*0.5*/
      switch (action) { /*8.0*/
        case pdef::proto::packet_set_score::Action::Change: { /*8.5*/
            READ_OR_BAIL(readByte, (int8_t&)v2.entry_type); /*7.2*/
            const pdef::proto::packet_set_score::Entries::EntryType &entry_type = v2.entry_type; /*0.7*/
            switch (entry_type) { /*8.0*/
              case pdef::proto::packet_set_score::Entries::EntryType::Player: { /*8.5*/
                READ_OR_BAIL(readZigZagVarLong, v2.entity_unique_id); /*0.5*/
                break;
              } /*8.7*/
              case pdef::proto::packet_set_score::Entries::EntryType::Entity: { /*8.5*/
                READ_OR_BAIL(readZigZagVarLong, v2.entity_unique_id); /*0.5*/
                break;
              } /*8.7*/
              default: break; /*avoid unhandled case warning*/
            } /*8.8*/
            switch (entry_type) { /*8.0*/
              case pdef::proto::packet_set_score::Entries::EntryType::FakePlayer: { /*8.5*/
                int custom_name_strlen; READ_OR_BAIL(readUnsignedVarInt, custom_name_strlen);
                if (!stream.readString(v2.custom_name, custom_name_strlen)) return false; /*custom_name: pstring*/ /*4.3*/
                break;
              } /*8.7*/
              default: break; /*avoid unhandled case warning*/
            } /*8.8*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    return true;
  }
  bool packet_lab_table(pdef::Stream &stream, pdef::proto::packet_lab_table &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action_type); /*7.2*/
    pdef::proto::decode::vec3i(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUByte, obj.reaction_type); /*0.5*/
    return true;
  }
  bool packet_update_block_synced(pdef::Stream &stream, pdef::proto::packet_update_block_synced &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUnsignedVarInt, obj.block_runtime_id); /*0.5*/
    int flags_val;
    READ_OR_BAIL(readUnsignedVarInt, flags_val);
    obj.flags.neighbors = (flags_val & 1) == 1;
    obj.flags.network = (flags_val & 2) == 2;
    obj.flags.no_graphic = (flags_val & 4) == 4;
    obj.flags.unused = (flags_val & 8) == 8;
    obj.flags.priority = (flags_val & 16) == 16; /*flags: bitflags*/ /*4.3*/
    READ_OR_BAIL(readUnsignedVarInt, obj.layer); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.entity_unique_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.transition_type); /*7.2*/
    return true;
  }
  bool packet_move_entity_delta(pdef::Stream &stream, pdef::proto::packet_move_entity_delta &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    uint16_t flags_val;
    READ_OR_BAIL(readUShortLE, flags_val);
    obj.flags.has_x = (flags_val & 1) == 1;
    obj.flags.has_y = (flags_val & 2) == 2;
    obj.flags.has_z = (flags_val & 4) == 4;
    obj.flags.has_rot_x = (flags_val & 8) == 8;
    obj.flags.has_rot_y = (flags_val & 16) == 16;
    obj.flags.has_rot_z = (flags_val & 32) == 32;
    obj.flags.on_ground = (flags_val & 64) == 64;
    obj.flags.teleport = (flags_val & 128) == 128;
    obj.flags.force_move = (flags_val & 256) == 256; /*flags: bitflags*/ /*4.3*/
    pdef::proto::packet_move_entity_delta::flags_t &flags = obj.flags; /*0.7*/
    if (flags.has_x == true) { /*8.2*/
      READ_OR_BAIL(readFloatLE, obj.x); /*0.5*/
    }
    if (flags.has_y == true) { /*8.2*/
      READ_OR_BAIL(readFloatLE, obj.y); /*0.5*/
    }
    if (flags.has_z == true) { /*8.2*/
      READ_OR_BAIL(readFloatLE, obj.z); /*0.5*/
    }
    if (flags.has_rot_x == true) { /*8.2*/
      READ_OR_BAIL(readUByte, obj.rot_x); /*0.5*/
    }
    if (flags.has_rot_y == true) { /*8.2*/
      READ_OR_BAIL(readUByte, obj.rot_y); /*0.5*/
    }
    if (flags.has_rot_z == true) { /*8.2*/
      READ_OR_BAIL(readUByte, obj.rot_z); /*0.5*/
    }
    return true;
  }
  bool packet_set_scoreboard_identity(pdef::Stream &stream, pdef::proto::packet_set_scoreboard_identity &obj) {
    READ_OR_BAIL(readByte, (int8_t&)obj.action); /*7.2*/
    const pdef::proto::packet_set_scoreboard_identity::Action &action = obj.action; /*0.7*/
    int entries_len; READ_OR_BAIL(readUnsignedVarInt, entries_len); /*1.5*/
    obj.entries.resize(entries_len); /*1.6*/
    for (int i = 0; i < entries_len; i++) { /*5*/
      pdef::proto::packet_set_scoreboard_identity::Entries &v2 = obj.entries[i]; /*5.23*/
      READ_OR_BAIL(readZigZagVarLong, v2.scoreboard_id); /*0.5*/
      switch (action) { /*8.0*/
        case pdef::proto::packet_set_scoreboard_identity::Action::RegisterIdentity: { /*8.5*/
          READ_OR_BAIL(readZigZagVarLong, v2.entity_unique_id); /*0.5*/
          break;
        } /*8.7*/
        default: break; /*avoid unhandled case warning*/
      } /*8.8*/
    }
    return true;
  }
  bool packet_set_local_player_as_initialized(pdef::Stream &stream, pdef::proto::packet_set_local_player_as_initialized &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_entity_id); /*0.5*/
    return true;
  }
  bool packet_update_soft_enum(pdef::Stream &stream, pdef::proto::packet_update_soft_enum &obj) {
    int enum_type_strlen; READ_OR_BAIL(readUnsignedVarInt, enum_type_strlen);
    if (!stream.readString(obj.enum_type, enum_type_strlen)) return false; /*enum_type: pstring*/ /*4.3*/
    int options_len; READ_OR_BAIL(readUnsignedVarInt, options_len); /*1.5*/
    obj.options.resize(options_len); /*1.6*/
    for (int i = 0; i < options_len; i++) {
      auto &v2 = obj.options[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action_type); /*7.2*/
    return true;
  }
  bool packet_network_stack_latency(pdef::Stream &stream, pdef::proto::packet_network_stack_latency &obj) {
    READ_OR_BAIL(readULongLE, obj.timestamp); /*0.5*/
    READ_OR_BAIL(readUByte, obj.needs_response); /*0.5*/
    return true;
  }
  bool packet_script_custom_event(pdef::Stream &stream, pdef::proto::packet_script_custom_event &obj) {
    int event_name_strlen; READ_OR_BAIL(readUnsignedVarInt, event_name_strlen);
    if (!stream.readString(obj.event_name, event_name_strlen)) return false; /*event_name: pstring*/ /*4.3*/
    int event_data_strlen; READ_OR_BAIL(readUnsignedVarInt, event_data_strlen);
    if (!stream.readString(obj.event_data, event_data_strlen)) return false; /*event_data: pstring*/ /*4.3*/
    return true;
  }
  bool packet_spawn_particle_effect(pdef::Stream &stream, pdef::proto::packet_spawn_particle_effect &obj) {
    READ_OR_BAIL(readUByte, obj.dimension); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.entity_id); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    int particle_name_strlen; READ_OR_BAIL(readUnsignedVarInt, particle_name_strlen);
    if (!stream.readString(obj.particle_name, particle_name_strlen)) return false; /*particle_name: pstring*/ /*4.3*/
    int molang_variables_len; READ_OR_BAIL(readUnsignedVarInt, molang_variables_len);if (!stream.readBuffer(obj.molang_variables, molang_variables_len)) return false; /*molang_variables: buffer*/ /*4.3*/
    return true;
  }
  bool packet_available_entity_identifiers(pdef::Stream &stream, pdef::proto::packet_available_entity_identifiers &obj) {
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_level_sound_event_v2(pdef::Stream &stream, pdef::proto::packet_level_sound_event_v2 &obj) {
    READ_OR_BAIL(readUByte, obj.sound_id); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.block_id); /*0.5*/
    int entity_type_strlen; READ_OR_BAIL(readUnsignedVarInt, entity_type_strlen);
    if (!stream.readString(obj.entity_type, entity_type_strlen)) return false; /*entity_type: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.is_baby_mob); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_global); /*0.5*/
    return true;
  }
  bool packet_network_chunk_publisher_update(pdef::Stream &stream, pdef::proto::packet_network_chunk_publisher_update &obj) {
    pdef::proto::decode::BlockCoordinates(stream, obj.coordinates); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUnsignedVarInt, obj.radius); /*0.5*/
    return true;
  }
  bool packet_biome_definition_list(pdef::Stream &stream, pdef::proto::packet_biome_definition_list &obj) {
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_level_sound_event(pdef::Stream &stream, pdef::proto::packet_level_sound_event &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.sound_id); /*7.2*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.extra_data); /*0.5*/
    int entity_type_strlen; READ_OR_BAIL(readUnsignedVarInt, entity_type_strlen);
    if (!stream.readString(obj.entity_type, entity_type_strlen)) return false; /*entity_type: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.is_baby_mob); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.is_global); /*0.5*/
    return true;
  }
  bool packet_level_event_generic(pdef::Stream &stream, pdef::proto::packet_level_event_generic &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.event_id); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_lectern_update(pdef::Stream &stream, pdef::proto::packet_lectern_update &obj) {
    READ_OR_BAIL(readUByte, obj.page); /*0.5*/
    READ_OR_BAIL(readUByte, obj.page_count); /*0.5*/
    pdef::proto::decode::vec3i(stream, obj.position); /*obj*/ /*4.6*/
    READ_OR_BAIL(readBool, (bool&)obj.drop_book); /*0.5*/
    return true;
  }
  bool packet_video_stream_connect(pdef::Stream &stream, pdef::proto::packet_video_stream_connect &obj) {
    int server_uri_strlen; READ_OR_BAIL(readUnsignedVarInt, server_uri_strlen);
    if (!stream.readString(obj.server_uri, server_uri_strlen)) return false; /*server_uri: pstring*/ /*4.3*/
    READ_OR_BAIL(readFloatLE, obj.frame_send_frequency); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action); /*7.2*/
    READ_OR_BAIL(readIntLE, obj.resolution_x); /*0.5*/
    READ_OR_BAIL(readIntLE, obj.resolution_y); /*0.5*/
    return true;
  }
  bool packet_add_ecs_entity(pdef::Stream &stream, pdef::proto::packet_add_ecs_entity &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.network_id); /*0.5*/
    return true;
  }
  bool packet_remove_ecs_entity(pdef::Stream &stream, pdef::proto::packet_remove_ecs_entity &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.network_id); /*0.5*/
    return true;
  }
  bool packet_client_cache_status(pdef::Stream &stream, pdef::proto::packet_client_cache_status &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.enabled); /*0.5*/
    return true;
  }
  bool packet_on_screen_texture_animation(pdef::Stream &stream, pdef::proto::packet_on_screen_texture_animation &obj) {
    READ_OR_BAIL(readUIntLE, obj.animation_type); /*0.5*/
    return true;
  }
  bool packet_map_create_locked_copy(pdef::Stream &stream, pdef::proto::packet_map_create_locked_copy &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.original_map_id); /*0.5*/
    READ_OR_BAIL(readZigZagVarLong, obj.new_map_id); /*0.5*/
    return true;
  }
  bool packet_structure_template_data_export_request(pdef::Stream &stream, pdef::proto::packet_structure_template_data_export_request &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::StructureBlockSettings(stream, obj.settings); /*obj*/ /*4.6*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.request_type); /*7.2*/
    return true;
  }
  bool packet_structure_template_data_export_response(pdef::Stream &stream, pdef::proto::packet_structure_template_data_export_response &obj) {
    int name_strlen; READ_OR_BAIL(readUnsignedVarInt, name_strlen);
    if (!stream.readString(obj.name, name_strlen)) return false; /*name: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.success); /*0.5*/
    bool &success = obj.success; /*0.6*/
    if (success == true) { /*8.1*/
      READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    }
    READ_OR_BAIL(readUByte, (uint8_t&)obj.response_type); /*7.2*/
    return true;
  }
  bool packet_update_block_properties(pdef::Stream &stream, pdef::proto::packet_update_block_properties &obj) {
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_client_cache_blob_status(pdef::Stream &stream, pdef::proto::packet_client_cache_blob_status &obj) {
    READ_OR_BAIL(readUnsignedVarInt, obj.misses); /*0.5*/
    int &misses = obj.misses; /*0.6*/
    READ_OR_BAIL(readUnsignedVarInt, obj.haves); /*0.5*/
    int &haves = obj.haves; /*0.6*/
    obj.missing.resize(misses); /*1.6*/
    for (int i = 0; i < misses; i++) {
      auto &v2 = obj.missing[i]; /*3.4*/
      READ_OR_BAIL(readULongLE, v2); /*0.5*/
    }
    obj.have.resize(haves); /*1.6*/
    for (int i = 0; i < haves; i++) {
      auto &v2 = obj.have[i]; /*3.4*/
      READ_OR_BAIL(readULongLE, v2); /*0.5*/
    }
    return true;
  }
  bool packet_client_cache_miss_response(pdef::Stream &stream, pdef::proto::packet_client_cache_miss_response &obj) {
    int blobs_len; READ_OR_BAIL(readUnsignedVarInt, blobs_len); /*1.5*/
    obj.blobs.resize(blobs_len); /*1.6*/
    for (int i = 0; i < blobs_len; i++) {
      auto &v2 = obj.blobs[i]; /*3.4*/
      pdef::proto::decode::Blob(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_education_settings(pdef::Stream &stream, pdef::proto::packet_education_settings &obj) {
    int CodeBuilderDefaultURI_strlen; READ_OR_BAIL(readUnsignedVarInt, CodeBuilderDefaultURI_strlen);
    if (!stream.readString(obj.CodeBuilderDefaultURI, CodeBuilderDefaultURI_strlen)) return false; /*CodeBuilderDefaultURI: pstring*/ /*4.3*/
    int CodeBuilderTitle_strlen; READ_OR_BAIL(readUnsignedVarInt, CodeBuilderTitle_strlen);
    if (!stream.readString(obj.CodeBuilderTitle, CodeBuilderTitle_strlen)) return false; /*CodeBuilderTitle: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.CanResizeCodeBuilder); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.disable_legacy_title_bar); /*0.5*/
    int post_process_filter_strlen; READ_OR_BAIL(readUnsignedVarInt, post_process_filter_strlen);
    if (!stream.readString(obj.post_process_filter, post_process_filter_strlen)) return false; /*post_process_filter: pstring*/ /*4.3*/
    int screenshot_border_path_strlen; READ_OR_BAIL(readUnsignedVarInt, screenshot_border_path_strlen);
    if (!stream.readString(obj.screenshot_border_path, screenshot_border_path_strlen)) return false; /*screenshot_border_path: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.has_agent_capabilities); /*0.5*/
    bool &has_agent_capabilities = obj.has_agent_capabilities; /*0.6*/
    if (has_agent_capabilities == true) { /*8.1*/
         obj.agent_capabilities = {}; pdef::proto::packet_education_settings::AgentCapabilities &v = *obj.agent_capabilities; /*8.4*/
        READ_OR_BAIL(readBool, (bool&)v.has); /*0.5*/
        READ_OR_BAIL(readBool, (bool&)v.can_modify_blocks); /*0.5*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.HasOverrideURI); /*0.5*/
    bool &HasOverrideURI = obj.HasOverrideURI; /*0.6*/
    if (HasOverrideURI == true) { /*8.1*/
      int OverrideURI_strlen; READ_OR_BAIL(readUnsignedVarInt, OverrideURI_strlen);
      if (!stream.readString(obj.OverrideURI, OverrideURI_strlen)) return false; /*OverrideURI: pstring*/ /*4.3*/
    }
    READ_OR_BAIL(readBool, (bool&)obj.HasQuiz); /*0.5*/
    READ_OR_BAIL(readBool, (bool&)obj.has_external_link_settings); /*0.5*/
    bool &has_external_link_settings = obj.has_external_link_settings; /*0.6*/
    if (has_external_link_settings == true) { /*8.1*/
         obj.external_link_settings = {}; pdef::proto::packet_education_settings::ExternalLinkSettings &v = *obj.external_link_settings; /*8.4*/
        READ_OR_BAIL(readBool, (bool&)v.has); /*0.5*/
        int url_strlen; READ_OR_BAIL(readUnsignedVarInt, url_strlen);
        if (!stream.readString(v.url, url_strlen)) return false; /*url: pstring*/ /*4.3*/
        int display_name_strlen; READ_OR_BAIL(readUnsignedVarInt, display_name_strlen);
        if (!stream.readString(v.display_name, display_name_strlen)) return false; /*display_name: pstring*/ /*4.3*/
    }
    return true;
  }
  bool packet_emote(pdef::Stream &stream, pdef::proto::packet_emote &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.entity_id); /*0.5*/
    int emote_id_strlen; READ_OR_BAIL(readUnsignedVarInt, emote_id_strlen);
    if (!stream.readString(obj.emote_id, emote_id_strlen)) return false; /*emote_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readUByte, obj.flags); /*0.5*/
    return true;
  }
  bool packet_multiplayer_settings(pdef::Stream &stream, pdef::proto::packet_multiplayer_settings &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.action_type); /*7.2*/
    return true;
  }
  bool packet_settings_command(pdef::Stream &stream, pdef::proto::packet_settings_command &obj) {
    int command_line_strlen; READ_OR_BAIL(readUnsignedVarInt, command_line_strlen);
    if (!stream.readString(obj.command_line, command_line_strlen)) return false; /*command_line: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.suppress_output); /*0.5*/
    return true;
  }
  bool packet_anvil_damage(pdef::Stream &stream, pdef::proto::packet_anvil_damage &obj) {
    READ_OR_BAIL(readUByte, obj.damage); /*0.5*/
    pdef::proto::decode::BlockCoordinates(stream, obj.position); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_completed_using_item(pdef::Stream &stream, pdef::proto::packet_completed_using_item &obj) {
    READ_OR_BAIL(readShortLE, obj.used_item_id); /*0.5*/
    READ_OR_BAIL(readIntLE, (int32_t&)obj.use_method); /*7.2*/
    return true;
  }
  bool packet_network_settings(pdef::Stream &stream, pdef::proto::packet_network_settings &obj) {
    READ_OR_BAIL(readUShortBE, obj.compression_threshold); /*0.5*/
    return true;
  }
  bool packet_player_auth_input(pdef::Stream &stream, pdef::proto::packet_player_auth_input &obj) {
    READ_OR_BAIL(readFloatLE, obj.pitch); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.yaw); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::vec2f(stream, obj.move_vector); /*obj*/ /*4.6*/
    READ_OR_BAIL(readFloatLE, obj.head_yaw); /*0.5*/
    int64_t input_data_val;
    READ_OR_BAIL(readUnsignedVarLong, input_data_val);
    obj.input_data.ascend = input_data_val & ((int64_t)1 << 0);
    obj.input_data.descend = input_data_val & ((int64_t)1 << 1);
    obj.input_data.north_jump = input_data_val & ((int64_t)1 << 2);
    obj.input_data.jump_down = input_data_val & ((int64_t)1 << 3);
    obj.input_data.sprint_down = input_data_val & ((int64_t)1 << 4);
    obj.input_data.change_height = input_data_val & ((int64_t)1 << 5);
    obj.input_data.jumping = input_data_val & ((int64_t)1 << 6);
    obj.input_data.auto_jumping_in_water = input_data_val & ((int64_t)1 << 7);
    obj.input_data.sneaking = input_data_val & ((int64_t)1 << 8);
    obj.input_data.sneak_down = input_data_val & ((int64_t)1 << 9);
    obj.input_data.up = input_data_val & ((int64_t)1 << 10);
    obj.input_data.down = input_data_val & ((int64_t)1 << 11);
    obj.input_data.left = input_data_val & ((int64_t)1 << 12);
    obj.input_data.right = input_data_val & ((int64_t)1 << 13);
    obj.input_data.up_left = input_data_val & ((int64_t)1 << 14);
    obj.input_data.up_right = input_data_val & ((int64_t)1 << 15);
    obj.input_data.want_up = input_data_val & ((int64_t)1 << 16);
    obj.input_data.want_down = input_data_val & ((int64_t)1 << 17);
    obj.input_data.want_down_slow = input_data_val & ((int64_t)1 << 18);
    obj.input_data.want_up_slow = input_data_val & ((int64_t)1 << 19);
    obj.input_data.sprinting = input_data_val & ((int64_t)1 << 20);
    obj.input_data.ascend_block = input_data_val & ((int64_t)1 << 21);
    obj.input_data.descend_block = input_data_val & ((int64_t)1 << 22);
    obj.input_data.sneak_toggle_down = input_data_val & ((int64_t)1 << 23);
    obj.input_data.persist_sneak = input_data_val & ((int64_t)1 << 24);
    obj.input_data.start_sprinting = input_data_val & ((int64_t)1 << 25);
    obj.input_data.stop_sprinting = input_data_val & ((int64_t)1 << 26);
    obj.input_data.start_sneaking = input_data_val & ((int64_t)1 << 27);
    obj.input_data.stop_sneaking = input_data_val & ((int64_t)1 << 28);
    obj.input_data.start_swimming = input_data_val & ((int64_t)1 << 29);
    obj.input_data.stop_swimming = input_data_val & ((int64_t)1 << 30);
    obj.input_data.start_jumping = input_data_val & ((int64_t)1 << 31);
    obj.input_data.start_gliding = input_data_val & ((int64_t)1 << 32);
    obj.input_data.stop_gliding = input_data_val & ((int64_t)1 << 33);
    obj.input_data.item_interact = input_data_val & ((int64_t)1 << 34);
    obj.input_data.block_action = input_data_val & ((int64_t)1 << 35);
    obj.input_data.item_stack_request = input_data_val & ((int64_t)1 << 36); /*input_data: bitflags*/ /*4.3*/
    pdef::proto::packet_player_auth_input::input_data_t &input_data = obj.input_data; /*0.7*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.input_mode); /*7.2*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.play_mode); /*7.2*/
    const pdef::proto::packet_player_auth_input::PlayMode &play_mode = obj.play_mode; /*0.7*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.interaction_model); /*7.2*/
    switch (play_mode) { /*8.0*/
      case pdef::proto::packet_player_auth_input::PlayMode::Reality: { /*8.5*/
        obj.gaze_direction = {}; pdef::proto::decode::vec3f(stream, *obj.gaze_direction); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    READ_OR_BAIL(readUnsignedVarLong, obj.tick); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.delta); /*obj*/ /*4.6*/
    if (input_data.item_interact == true) { /*8.2*/
         obj.transaction = {}; pdef::proto::packet_player_auth_input::Transaction &v = *obj.transaction; /*8.4*/
        pdef::proto::decode::TransactionLegacy(stream, v.legacy); /*v*/ /*4.6*/
        int actions_len; /*2.3*/
        READ_OR_BAIL(readUnsignedVarInt, actions_len); /*2.6*/
        v.actions.resize(actions_len); /*2.7*/
        for (int i = 0; i < actions_len; i++) { pdef::proto::decode::TransactionActions(stream, v.actions[i]); } /*2.8*/
        pdef::proto::decode::TransactionUseItem(stream, v.data); /*v*/ /*4.6*/
    }
    if (input_data.item_stack_request == true) { /*8.2*/
      obj.item_stack_request = {}; pdef::proto::decode::ItemStackRequest(stream, *obj.item_stack_request); /*obj*/ /*4.6*/
    }
    if (input_data.block_action == true) { /*8.2*/
      int block_action_len; READ_OR_BAIL(readZigZagVarInt, block_action_len); /*1.5*/
      obj.block_action.resize(block_action_len); /*1.6*/
      for (int i = 0; i < block_action_len; i++) { /*5*/
        pdef::proto::packet_player_auth_input::BlockAction &v3 = obj.block_action[i]; /*5.23*/
        READ_OR_BAIL(readZigZagVarInt, (int&)v3.action); /*7.2*/
        const pdef::proto::packet_player_auth_input::BlockAction::Action &action = v3.action; /*0.7*/
        if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::StartBreak) { /*8.5*/
            v3.position = {}; pdef::proto::decode::vec3i(stream, *v3.position); /*v3*/ /*4.6*/
            READ_OR_BAIL(readZigZagVarInt, v3.face); /*0.5*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::AbortBreak) { /*8.5*/
            v3.position = {}; pdef::proto::decode::vec3i(stream, *v3.position); /*v3*/ /*4.6*/
            READ_OR_BAIL(readZigZagVarInt, v3.face); /*0.5*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::CrackBreak) { /*8.5*/
            v3.position = {}; pdef::proto::decode::vec3i(stream, *v3.position); /*v3*/ /*4.6*/
            READ_OR_BAIL(readZigZagVarInt, v3.face); /*0.5*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::PredictBreak) { /*8.5*/
            v3.position = {}; pdef::proto::decode::vec3i(stream, *v3.position); /*v3*/ /*4.6*/
            READ_OR_BAIL(readZigZagVarInt, v3.face); /*0.5*/
        }
        else if (action == pdef::proto::packet_player_auth_input::BlockAction::Action::ContinueBreak) { /*8.5*/
            v3.position = {}; pdef::proto::decode::vec3i(stream, *v3.position); /*v3*/ /*4.6*/
            READ_OR_BAIL(readZigZagVarInt, v3.face); /*0.5*/
        }
      }
    }
    return true;
  }
  bool packet_creative_content(pdef::Stream &stream, pdef::proto::packet_creative_content &obj) {
    int items_len; READ_OR_BAIL(readUnsignedVarInt, items_len); /*1.5*/
    obj.items.resize(items_len); /*1.6*/
    for (int i = 0; i < items_len; i++) { /*5*/
      pdef::proto::packet_creative_content::Items &v2 = obj.items[i]; /*5.23*/
      READ_OR_BAIL(readUnsignedVarInt, v2.entry_id); /*0.5*/
      pdef::proto::decode::ItemLegacy(stream, v2.item); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_player_enchant_options(pdef::Stream &stream, pdef::proto::packet_player_enchant_options &obj) {
    int options_len; READ_OR_BAIL(readUnsignedVarInt, options_len); /*1.5*/
    obj.options.resize(options_len); /*1.6*/
    for (int i = 0; i < options_len; i++) {
      auto &v2 = obj.options[i]; /*3.4*/
      pdef::proto::decode::EnchantOption(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_item_stack_request(pdef::Stream &stream, pdef::proto::packet_item_stack_request &obj) {
    int requests_len; READ_OR_BAIL(readUnsignedVarInt, requests_len); /*1.5*/
    obj.requests.resize(requests_len); /*1.6*/
    for (int i = 0; i < requests_len; i++) {
      auto &v2 = obj.requests[i]; /*3.4*/
      pdef::proto::decode::ItemStackRequest(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_item_stack_response(pdef::Stream &stream, pdef::proto::packet_item_stack_response &obj) {
    int responses_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, responses_len); /*2.6*/
    obj.responses.resize(responses_len); /*2.7*/
    for (int i = 0; i < responses_len; i++) { pdef::proto::decode::ItemStackResponses(stream, obj.responses[i]); } /*2.8*/
    return true;
  }
  bool packet_player_armor_damage(pdef::Stream &stream, pdef::proto::packet_player_armor_damage &obj) {
    uint8_t type_val;
    READ_OR_BAIL(readUByte, type_val);
    obj.type.head = (type_val & 1) == 1;
    obj.type.chest = (type_val & 2) == 2;
    obj.type.legs = (type_val & 4) == 4;
    obj.type.feet = (type_val & 8) == 8; /*type: bitflags*/ /*4.3*/
    pdef::proto::packet_player_armor_damage::type_t &type = obj.type; /*0.7*/
    if (type.head == true) { /*8.2*/
      READ_OR_BAIL(readZigZagVarInt, obj.helmet_damage); /*0.5*/
    }
    if (type.chest == true) { /*8.2*/
      READ_OR_BAIL(readZigZagVarInt, obj.chestplate_damage); /*0.5*/
    }
    if (type.legs == true) { /*8.2*/
      READ_OR_BAIL(readZigZagVarInt, obj.leggings_damage); /*0.5*/
    }
    if (type.feet == true) { /*8.2*/
      READ_OR_BAIL(readZigZagVarInt, obj.boots_damage); /*0.5*/
    }
    return true;
  }
  bool packet_update_player_game_type(pdef::Stream &stream, pdef::proto::packet_update_player_game_type &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.gamemode); /*7.2*/
    READ_OR_BAIL(readZigZagVarLong, obj.player_unique_id); /*0.5*/
    return true;
  }
  bool packet_emote_list(pdef::Stream &stream, pdef::proto::packet_emote_list &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.player_id); /*0.5*/
    int emote_pieces_len; READ_OR_BAIL(readUnsignedVarInt, emote_pieces_len); /*1.5*/
    obj.emote_pieces.resize(emote_pieces_len); /*1.6*/
    for (int i = 0; i < emote_pieces_len; i++) {
      auto &v2 = obj.emote_pieces[i]; /*3.4*/
      READ_OR_BAIL(readULongBE, v2); /*0.5*/
    }
    return true;
  }
  bool packet_position_tracking_db_request(pdef::Stream &stream, pdef::proto::packet_position_tracking_db_request &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.tracking_id); /*0.5*/
    return true;
  }
  bool packet_position_tracking_db_broadcast(pdef::Stream &stream, pdef::proto::packet_position_tracking_db_broadcast &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.broadcast_action); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.tracking_id); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_packet_violation_warning(pdef::Stream &stream, pdef::proto::packet_packet_violation_warning &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.violation_type); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.severity); /*7.2*/
    READ_OR_BAIL(readZigZagVarInt, obj.packet_id); /*0.5*/
    int reason_strlen; READ_OR_BAIL(readUnsignedVarInt, reason_strlen);
    if (!stream.readString(obj.reason, reason_strlen)) return false; /*reason: pstring*/ /*4.3*/
    return true;
  }
  bool packet_motion_prediction_hints(pdef::Stream &stream, pdef::proto::packet_motion_prediction_hints &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.entity_runtime_id); /*0.5*/
    pdef::proto::decode::vec3f(stream, obj.velocity); /*obj*/ /*4.6*/
    READ_OR_BAIL(readBool, (bool&)obj.on_ground); /*0.5*/
    return true;
  }
  bool packet_animate_entity(pdef::Stream &stream, pdef::proto::packet_animate_entity &obj) {
    int animation_strlen; READ_OR_BAIL(readUnsignedVarInt, animation_strlen);
    if (!stream.readString(obj.animation, animation_strlen)) return false; /*animation: pstring*/ /*4.3*/
    int next_state_strlen; READ_OR_BAIL(readUnsignedVarInt, next_state_strlen);
    if (!stream.readString(obj.next_state, next_state_strlen)) return false; /*next_state: pstring*/ /*4.3*/
    int stop_condition_strlen; READ_OR_BAIL(readUnsignedVarInt, stop_condition_strlen);
    if (!stream.readString(obj.stop_condition, stop_condition_strlen)) return false; /*stop_condition: pstring*/ /*4.3*/
    READ_OR_BAIL(readIntLE, obj.stop_condition_version); /*0.5*/
    int controller_strlen; READ_OR_BAIL(readUnsignedVarInt, controller_strlen);
    if (!stream.readString(obj.controller, controller_strlen)) return false; /*controller: pstring*/ /*4.3*/
    READ_OR_BAIL(readFloatLE, obj.blend_out_time); /*0.5*/
    int runtime_entity_ids_len; READ_OR_BAIL(readUnsignedVarInt, runtime_entity_ids_len); /*1.5*/
    obj.runtime_entity_ids.resize(runtime_entity_ids_len); /*1.6*/
    for (int i = 0; i < runtime_entity_ids_len; i++) {
      auto &v2 = obj.runtime_entity_ids[i]; /*3.4*/
      READ_OR_BAIL(readUnsignedVarLong, v2); /*0.5*/
    }
    return true;
  }
  bool packet_camera_shake(pdef::Stream &stream, pdef::proto::packet_camera_shake &obj) {
    READ_OR_BAIL(readFloatLE, obj.intensity); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.duration); /*0.5*/
    READ_OR_BAIL(readUByte, obj.type); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.action); /*7.2*/
    return true;
  }
  bool packet_player_fog(pdef::Stream &stream, pdef::proto::packet_player_fog &obj) {
    int stack_len; READ_OR_BAIL(readUnsignedVarInt, stack_len); /*1.5*/
    obj.stack.resize(stack_len); /*1.6*/
    for (int i = 0; i < stack_len; i++) {
      auto &v2 = obj.stack[i]; /*3.4*/
      int _strlen; READ_OR_BAIL(readUnsignedVarInt, _strlen);
      if (!stream.readString(v2, _strlen)) return false; /*: pstring*/ /*4.3*/
    }
    return true;
  }
  bool packet_correct_player_move_prediction(pdef::Stream &stream, pdef::proto::packet_correct_player_move_prediction &obj) {
    pdef::proto::decode::vec3f(stream, obj.position); /*obj*/ /*4.6*/
    pdef::proto::decode::vec3f(stream, obj.delta); /*obj*/ /*4.6*/
    READ_OR_BAIL(readBool, (bool&)obj.on_ground); /*0.5*/
    READ_OR_BAIL(readUnsignedVarLong, obj.tick); /*0.5*/
    return true;
  }
  bool packet_item_component(pdef::Stream &stream, pdef::proto::packet_item_component &obj) {
    int entries_len; /*2.3*/
    READ_OR_BAIL(readUnsignedVarInt, entries_len); /*2.6*/
    obj.entries.resize(entries_len); /*2.7*/
    for (int i = 0; i < entries_len; i++) { pdef::proto::decode::ItemComponentList(stream, obj.entries[i]); } /*2.8*/
    return true;
  }
  bool packet_filter_text_packet(pdef::Stream &stream, pdef::proto::packet_filter_text_packet &obj) {
    int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
    if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.from_server); /*0.5*/
    return true;
  }
  bool packet_debug_renderer(pdef::Stream &stream, pdef::proto::packet_debug_renderer &obj) {
    READ_OR_BAIL(readIntLE, (int32_t&)obj.type); /*7.2*/
    const pdef::proto::packet_debug_renderer::Type &type = obj.type; /*0.7*/
    switch (type) { /*8.0*/
      case pdef::proto::packet_debug_renderer::Type::Clear: { /*8.5*/
        break;
      } /*8.7*/
      case pdef::proto::packet_debug_renderer::Type::AddCube: { /*8.5*/
          int text_strlen; READ_OR_BAIL(readUnsignedVarInt, text_strlen);
          if (!stream.readString(obj.text, text_strlen)) return false; /*text: pstring*/ /*4.3*/
          obj.position = {}; pdef::proto::decode::vec3f(stream, *obj.position); /*obj*/ /*4.6*/
          READ_OR_BAIL(readFloatLE, obj.red); /*0.5*/
          READ_OR_BAIL(readFloatLE, obj.green); /*0.5*/
          READ_OR_BAIL(readFloatLE, obj.blue); /*0.5*/
          READ_OR_BAIL(readFloatLE, obj.alpha); /*0.5*/
          READ_OR_BAIL(readLongLE, obj.duration); /*0.5*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
  bool packet_sync_entity_property(pdef::Stream &stream, pdef::proto::packet_sync_entity_property &obj) {
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    return true;
  }
  bool packet_add_volume_entity(pdef::Stream &stream, pdef::proto::packet_add_volume_entity &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.runtime_id); /*0.5*/
    READ_OR_BAIL(readByte, obj.nbt); /*0.5*/
    int encoding_identifier_strlen; READ_OR_BAIL(readUnsignedVarInt, encoding_identifier_strlen);
    if (!stream.readString(obj.encoding_identifier, encoding_identifier_strlen)) return false; /*encoding_identifier: pstring*/ /*4.3*/
    int instance_name_strlen; READ_OR_BAIL(readUnsignedVarInt, instance_name_strlen);
    if (!stream.readString(obj.instance_name, instance_name_strlen)) return false; /*instance_name: pstring*/ /*4.3*/
    const pdef::proto::packet_add_volume_entity::Bounds &v = obj.bounds = {}; /*["packet_add_volume_entity"]*/ /*7.3*/
    READ_OR_BAIL(readZigZagVarInt, obj.dimension); /*0.5*/
    int engine_version_strlen; READ_OR_BAIL(readUnsignedVarInt, engine_version_strlen);
    if (!stream.readString(obj.engine_version, engine_version_strlen)) return false; /*engine_version: pstring*/ /*4.3*/
    return true;
  }
  bool packet_remove_volume_entity(pdef::Stream &stream, pdef::proto::packet_remove_volume_entity &obj) {
    READ_OR_BAIL(readUnsignedVarLong, obj.entity_id); /*0.5*/
    return true;
  }
  bool packet_simulation_type(pdef::Stream &stream, pdef::proto::packet_simulation_type &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.type); /*7.2*/
    return true;
  }
  bool packet_npc_dialogue(pdef::Stream &stream, pdef::proto::packet_npc_dialogue &obj) {
    READ_OR_BAIL(readULongLE, obj.entity_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.action_type); /*7.2*/
    int dialogue_strlen; READ_OR_BAIL(readUnsignedVarInt, dialogue_strlen);
    if (!stream.readString(obj.dialogue, dialogue_strlen)) return false; /*dialogue: pstring*/ /*4.3*/
    int screen_name_strlen; READ_OR_BAIL(readUnsignedVarInt, screen_name_strlen);
    if (!stream.readString(obj.screen_name, screen_name_strlen)) return false; /*screen_name: pstring*/ /*4.3*/
    int npc_name_strlen; READ_OR_BAIL(readUnsignedVarInt, npc_name_strlen);
    if (!stream.readString(obj.npc_name, npc_name_strlen)) return false; /*npc_name: pstring*/ /*4.3*/
    int action_json_strlen; READ_OR_BAIL(readUnsignedVarInt, action_json_strlen);
    if (!stream.readString(obj.action_json, action_json_strlen)) return false; /*action_json: pstring*/ /*4.3*/
    return true;
  }
  bool packet_edu_uri_resource_packet(pdef::Stream &stream, pdef::proto::packet_edu_uri_resource_packet &obj) {
    pdef::proto::decode::EducationSharedResourceURI(stream, obj.resource); /*obj*/ /*4.6*/
    return true;
  }
  bool packet_create_photo(pdef::Stream &stream, pdef::proto::packet_create_photo &obj) {
    READ_OR_BAIL(readLongLE, obj.entity_unique_id); /*0.5*/
    int photo_name_strlen; READ_OR_BAIL(readUnsignedVarInt, photo_name_strlen);
    if (!stream.readString(obj.photo_name, photo_name_strlen)) return false; /*photo_name: pstring*/ /*4.3*/
    int item_name_strlen; READ_OR_BAIL(readUnsignedVarInt, item_name_strlen);
    if (!stream.readString(obj.item_name, item_name_strlen)) return false; /*item_name: pstring*/ /*4.3*/
    return true;
  }
  bool packet_update_subchunk_blocks(pdef::Stream &stream, pdef::proto::packet_update_subchunk_blocks &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.x); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.y); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.z); /*0.5*/
    int blocks_len; READ_OR_BAIL(readUnsignedVarInt, blocks_len); /*1.5*/
    obj.blocks.resize(blocks_len); /*1.6*/
    for (int i = 0; i < blocks_len; i++) {
      auto &v2 = obj.blocks[i]; /*3.4*/
      pdef::proto::decode::BlockUpdate(stream, v2); /*v2*/ /*4.6*/
    }
    int extra_len; READ_OR_BAIL(readUnsignedVarInt, extra_len); /*1.5*/
    obj.extra.resize(extra_len); /*1.6*/
    for (int i = 0; i < extra_len; i++) {
      auto &v2 = obj.extra[i]; /*3.4*/
      pdef::proto::decode::BlockUpdate(stream, v2); /*v2*/ /*4.6*/
    }
    return true;
  }
  bool packet_photo_info_request(pdef::Stream &stream, pdef::proto::packet_photo_info_request &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.photo_id); /*0.5*/
    return true;
  }
bool SubChunkEntryWithoutCaching(pdef::Stream &stream, pdef::proto::SubChunkEntryWithoutCaching &obj) {
    READ_OR_BAIL(readByte, obj.dx); /*0.5*/
    READ_OR_BAIL(readByte, obj.dy); /*0.5*/
    READ_OR_BAIL(readByte, obj.dz); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.result); /*7.2*/
    int payload_len; READ_OR_BAIL(readUnsignedVarInt, payload_len);if (!stream.readBuffer(obj.payload, payload_len)) return false; /*payload: buffer*/ /*4.3*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.heightmap_type); /*7.2*/
    const pdef::proto::SubChunkEntryWithoutCaching::HeightmapType &heightmap_type = obj.heightmap_type; /*0.7*/
    switch (heightmap_type) { /*8.0*/
      case pdef::proto::SubChunkEntryWithoutCaching::HeightmapType::HasData: { /*8.5*/
        if (!stream.readBuffer(obj.heightmap, 256)) return false; /*heightmap: buffer*/ /*4.3*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
  return true;
}
bool SubChunkEntryWithCaching(pdef::Stream &stream, pdef::proto::SubChunkEntryWithCaching &obj) {
    READ_OR_BAIL(readByte, obj.dx); /*0.5*/
    READ_OR_BAIL(readByte, obj.dy); /*0.5*/
    READ_OR_BAIL(readByte, obj.dz); /*0.5*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.result); /*7.2*/
    const pdef::proto::SubChunkEntryWithCaching::Result &result = obj.result; /*0.7*/
    switch (result) { /*8.0*/
      case pdef::proto::SubChunkEntryWithCaching::Result::SuccessAllAir: { /*8.5*/
        break;
      } /*8.7*/
      default: { /*8.3*/
        int payload_len; READ_OR_BAIL(readUnsignedVarInt, payload_len);if (!stream.readBuffer(obj.payload, payload_len)) return false; /*payload: buffer*/ /*4.3*/
        break;
      } /*8.7*/
    } /*8.8*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.heightmap_type); /*7.2*/
    const pdef::proto::SubChunkEntryWithCaching::HeightmapType &heightmap_type = obj.heightmap_type; /*0.7*/
    switch (heightmap_type) { /*8.0*/
      case pdef::proto::SubChunkEntryWithCaching::HeightmapType::HasData: { /*8.5*/
        if (!stream.readBuffer(obj.heightmap, 256)) return false; /*heightmap: buffer*/ /*4.3*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    READ_OR_BAIL(readULongLE, obj.blob_id); /*0.5*/
  return true;
}
  bool packet_subchunk(pdef::Stream &stream, pdef::proto::packet_subchunk &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.cache_enabled); /*0.5*/
    bool &cache_enabled = obj.cache_enabled; /*0.6*/
    READ_OR_BAIL(readZigZagVarInt, obj.dimension); /*0.5*/
    pdef::proto::decode::vec3i(stream, obj.origin); /*obj*/ /*4.6*/
    if (cache_enabled == true) { /*8.1*/
      uint32_t entries_SubChunkEntryWithCaching_len; /*2.3*/
      READ_OR_BAIL(readUIntLE, entries_SubChunkEntryWithCaching_len); /*2.6*/
      obj.entries_SubChunkEntryWithCaching.resize(entries_SubChunkEntryWithCaching_len); /*2.7*/
      for (int i = 0; i < entries_SubChunkEntryWithCaching_len; i++) { pdef::proto::decode::SubChunkEntryWithCaching(stream, obj.entries_SubChunkEntryWithCaching[i]); } /*2.8*/
    }
    else if (cache_enabled == false) { /*8.1*/
      uint32_t entries_SubChunkEntryWithoutCaching_len; /*2.3*/
      READ_OR_BAIL(readUIntLE, entries_SubChunkEntryWithoutCaching_len); /*2.6*/
      obj.entries_SubChunkEntryWithoutCaching.resize(entries_SubChunkEntryWithoutCaching_len); /*2.7*/
      for (int i = 0; i < entries_SubChunkEntryWithoutCaching_len; i++) { pdef::proto::decode::SubChunkEntryWithoutCaching(stream, obj.entries_SubChunkEntryWithoutCaching[i]); } /*2.8*/
    }
    return true;
  }
  bool packet_subchunk_request(pdef::Stream &stream, pdef::proto::packet_subchunk_request &obj) {
    READ_OR_BAIL(readZigZagVarInt, obj.dimension); /*0.5*/
    pdef::proto::decode::vec3i(stream, obj.origin); /*obj*/ /*4.6*/
    uint32_t requests_len; READ_OR_BAIL(readUIntLE, requests_len); /*1.5*/
    obj.requests.resize(requests_len); /*1.6*/
    for (int i = 0; i < requests_len; i++) { /*5*/
      pdef::proto::packet_subchunk_request::Requests &v2 = obj.requests[i]; /*5.23*/
      READ_OR_BAIL(readByte, v2.dx); /*0.5*/
      READ_OR_BAIL(readByte, v2.dy); /*0.5*/
      READ_OR_BAIL(readByte, v2.dz); /*0.5*/
    }
    return true;
  }
  bool packet_client_start_item_cooldown(pdef::Stream &stream, pdef::proto::packet_client_start_item_cooldown &obj) {
    int category_strlen; READ_OR_BAIL(readUnsignedVarInt, category_strlen);
    if (!stream.readString(obj.category, category_strlen)) return false; /*category: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarInt, obj.duration); /*0.5*/
    return true;
  }
  bool packet_script_message(pdef::Stream &stream, pdef::proto::packet_script_message &obj) {
    int message_id_strlen; READ_OR_BAIL(readUnsignedVarInt, message_id_strlen);
    if (!stream.readString(obj.message_id, message_id_strlen)) return false; /*message_id: pstring*/ /*4.3*/
    int data_strlen; READ_OR_BAIL(readUnsignedVarInt, data_strlen);
    if (!stream.readString(obj.data, data_strlen)) return false; /*data: pstring*/ /*4.3*/
    return true;
  }
  bool packet_code_builder_source(pdef::Stream &stream, pdef::proto::packet_code_builder_source &obj) {
    READ_OR_BAIL(readUByte, (uint8_t&)obj.operation); /*7.2*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.category); /*7.2*/
    int value_strlen; READ_OR_BAIL(readUnsignedVarInt, value_strlen);
    if (!stream.readString(obj.value, value_strlen)) return false; /*value: pstring*/ /*4.3*/
    return true;
  }
  bool packet_ticking_areas_load_status(pdef::Stream &stream, pdef::proto::packet_ticking_areas_load_status &obj) {
    READ_OR_BAIL(readBool, (bool&)obj.preload); /*0.5*/
    return true;
  }
  bool packet_dimension_data(pdef::Stream &stream, pdef::proto::packet_dimension_data &obj) {
    int definitions_len; READ_OR_BAIL(readUnsignedVarInt, definitions_len); /*1.5*/
    obj.definitions.resize(definitions_len); /*1.6*/
    for (int i = 0; i < definitions_len; i++) { /*5*/
      pdef::proto::packet_dimension_data::Definitions &v2 = obj.definitions[i]; /*5.23*/
      int id_strlen; READ_OR_BAIL(readUnsignedVarInt, id_strlen);
      if (!stream.readString(v2.id, id_strlen)) return false; /*id: pstring*/ /*4.3*/
      READ_OR_BAIL(readZigZagVarInt, v2.max_height); /*0.5*/
      READ_OR_BAIL(readZigZagVarInt, v2.min_height); /*0.5*/
      READ_OR_BAIL(readZigZagVarInt, (int&)v2.generator); /*7.2*/
    }
    return true;
  }
  bool packet_agent_action(pdef::Stream &stream, pdef::proto::packet_agent_action &obj) {
    int request_id_strlen; READ_OR_BAIL(readUnsignedVarInt, request_id_strlen);
    if (!stream.readString(obj.request_id, request_id_strlen)) return false; /*request_id: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.action_type); /*7.2*/
    int body_strlen; READ_OR_BAIL(readUnsignedVarInt, body_strlen);
    if (!stream.readString(obj.body, body_strlen)) return false; /*body: pstring*/ /*4.3*/
    return true;
  }
  bool packet_change_mob_property(pdef::Stream &stream, pdef::proto::packet_change_mob_property &obj) {
    READ_OR_BAIL(readZigZagVarLong, obj.entity_unique_id); /*0.5*/
    int property_strlen; READ_OR_BAIL(readUnsignedVarInt, property_strlen);
    if (!stream.readString(obj.property, property_strlen)) return false; /*property: pstring*/ /*4.3*/
    READ_OR_BAIL(readBool, (bool&)obj.bool_value); /*0.5*/
    int string_value_strlen; READ_OR_BAIL(readUnsignedVarInt, string_value_strlen);
    if (!stream.readString(obj.string_value, string_value_strlen)) return false; /*string_value: pstring*/ /*4.3*/
    READ_OR_BAIL(readZigZagVarInt, obj.int_value); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.float_value); /*0.5*/
    return true;
  }
  bool packet_lesson_progress(pdef::Stream &stream, pdef::proto::packet_lesson_progress &obj) {
    READ_OR_BAIL(readUByte, obj.action); /*0.5*/
    READ_OR_BAIL(readZigZagVarInt, obj.score); /*0.5*/
    int identifier_strlen; READ_OR_BAIL(readUnsignedVarInt, identifier_strlen);
    if (!stream.readString(obj.identifier, identifier_strlen)) return false; /*identifier: pstring*/ /*4.3*/
    return true;
  }
  bool packet_request_ability(pdef::Stream &stream, pdef::proto::packet_request_ability &obj) {
    READ_OR_BAIL(readZigZagVarInt, (int&)obj.ability); /*7.2*/
    READ_OR_BAIL(readUByte, (uint8_t&)obj.value_type); /*7.2*/
    READ_OR_BAIL(readBool, (bool&)obj.bool_value); /*0.5*/
    READ_OR_BAIL(readFloatLE, obj.float_val); /*0.5*/
    return true;
  }
  bool packet_request_permissions(pdef::Stream &stream, pdef::proto::packet_request_permissions &obj) {
    READ_OR_BAIL(readLongLE, obj.entity_unique_id); /*0.5*/
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.permission_level); /*7.2*/
    uint16_t requested_permissions_val;
    READ_OR_BAIL(readUShortLE, requested_permissions_val);
    obj.requested_permissions.build = (requested_permissions_val & 1) == 1;
    obj.requested_permissions.mine = (requested_permissions_val & 2) == 2;
    obj.requested_permissions.doors_and_switches = (requested_permissions_val & 4) == 4;
    obj.requested_permissions.open_containers = (requested_permissions_val & 8) == 8;
    obj.requested_permissions.attack_players = (requested_permissions_val & 16) == 16;
    obj.requested_permissions.attack_mobs = (requested_permissions_val & 32) == 32;
    obj.requested_permissions.operator_ = (requested_permissions_val & 64) == 64;
    obj.requested_permissions.teleport = (requested_permissions_val & 128) == 128; /*requested_permissions: bitflags*/ /*4.3*/
    return true;
  }
  bool packet_toast_request(pdef::Stream &stream, pdef::proto::packet_toast_request &obj) {
    int title_strlen; READ_OR_BAIL(readUnsignedVarInt, title_strlen);
    if (!stream.readString(obj.title, title_strlen)) return false; /*title: pstring*/ /*4.3*/
    int message_strlen; READ_OR_BAIL(readUnsignedVarInt, message_strlen);
    if (!stream.readString(obj.message, message_strlen)) return false; /*message: pstring*/ /*4.3*/
    return true;
  }
  bool mcpe_packet(pdef::Stream &stream, pdef::proto::mcpe_packet &obj) {
    READ_OR_BAIL(readUnsignedVarInt, (int&)obj.name); /*7.2*/
    const pdef::proto::mcpe_packet::Name &name = obj.name; /*0.7*/
    switch (name) { /*8.0*/
      case pdef::proto::mcpe_packet::Name::Login: { /*8.5*/
        obj.params_packet_login = {}; pdef::proto::decode::packet_login(stream, *obj.params_packet_login); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayStatus: { /*8.5*/
        obj.params_packet_play_status = {}; pdef::proto::decode::packet_play_status(stream, *obj.params_packet_play_status); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerToClientHandshake: { /*8.5*/
        obj.params_packet_server_to_client_handshake = {}; pdef::proto::decode::packet_server_to_client_handshake(stream, *obj.params_packet_server_to_client_handshake); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientToServerHandshake: { /*8.5*/
        obj.params_packet_client_to_server_handshake = {}; pdef::proto::decode::packet_client_to_server_handshake(stream, *obj.params_packet_client_to_server_handshake); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Disconnect: { /*8.5*/
        obj.params_packet_disconnect = {}; pdef::proto::decode::packet_disconnect(stream, *obj.params_packet_disconnect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePacksInfo: { /*8.5*/
        obj.params_packet_resource_packs_info = {}; pdef::proto::decode::packet_resource_packs_info(stream, *obj.params_packet_resource_packs_info); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackStack: { /*8.5*/
        obj.params_packet_resource_pack_stack = {}; pdef::proto::decode::packet_resource_pack_stack(stream, *obj.params_packet_resource_pack_stack); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackClientResponse: { /*8.5*/
        obj.params_packet_resource_pack_client_response = {}; pdef::proto::decode::packet_resource_pack_client_response(stream, *obj.params_packet_resource_pack_client_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Text: { /*8.5*/
        obj.params_packet_text = {}; pdef::proto::decode::packet_text(stream, *obj.params_packet_text); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetTime: { /*8.5*/
        obj.params_packet_set_time = {}; pdef::proto::decode::packet_set_time(stream, *obj.params_packet_set_time); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StartGame: { /*8.5*/
        obj.params_packet_start_game = {}; pdef::proto::decode::packet_start_game(stream, *obj.params_packet_start_game); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddPlayer: { /*8.5*/
        obj.params_packet_add_player = {}; pdef::proto::decode::packet_add_player(stream, *obj.params_packet_add_player); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddEntity: { /*8.5*/
        obj.params_packet_add_entity = {}; pdef::proto::decode::packet_add_entity(stream, *obj.params_packet_add_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveEntity: { /*8.5*/
        obj.params_packet_remove_entity = {}; pdef::proto::decode::packet_remove_entity(stream, *obj.params_packet_remove_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddItemEntity: { /*8.5*/
        obj.params_packet_add_item_entity = {}; pdef::proto::decode::packet_add_item_entity(stream, *obj.params_packet_add_item_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TakeItemEntity: { /*8.5*/
        obj.params_packet_take_item_entity = {}; pdef::proto::decode::packet_take_item_entity(stream, *obj.params_packet_take_item_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MoveEntity: { /*8.5*/
        obj.params_packet_move_entity = {}; pdef::proto::decode::packet_move_entity(stream, *obj.params_packet_move_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MovePlayer: { /*8.5*/
        obj.params_packet_move_player = {}; pdef::proto::decode::packet_move_player(stream, *obj.params_packet_move_player); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RiderJump: { /*8.5*/
        obj.params_packet_rider_jump = {}; pdef::proto::decode::packet_rider_jump(stream, *obj.params_packet_rider_jump); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlock: { /*8.5*/
        obj.params_packet_update_block = {}; pdef::proto::decode::packet_update_block(stream, *obj.params_packet_update_block); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddPainting: { /*8.5*/
        obj.params_packet_add_painting = {}; pdef::proto::decode::packet_add_painting(stream, *obj.params_packet_add_painting); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TickSync: { /*8.5*/
        obj.params_packet_tick_sync = {}; pdef::proto::decode::packet_tick_sync(stream, *obj.params_packet_tick_sync); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEventOld: { /*8.5*/
        obj.params_packet_level_sound_event_old = {}; pdef::proto::decode::packet_level_sound_event_old(stream, *obj.params_packet_level_sound_event_old); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelEvent: { /*8.5*/
        obj.params_packet_level_event = {}; pdef::proto::decode::packet_level_event(stream, *obj.params_packet_level_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockEvent: { /*8.5*/
        obj.params_packet_block_event = {}; pdef::proto::decode::packet_block_event(stream, *obj.params_packet_block_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EntityEvent: { /*8.5*/
        obj.params_packet_entity_event = {}; pdef::proto::decode::packet_entity_event(stream, *obj.params_packet_entity_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobEffect: { /*8.5*/
        obj.params_packet_mob_effect = {}; pdef::proto::decode::packet_mob_effect(stream, *obj.params_packet_mob_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateAttributes: { /*8.5*/
        obj.params_packet_update_attributes = {}; pdef::proto::decode::packet_update_attributes(stream, *obj.params_packet_update_attributes); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventoryTransaction: { /*8.5*/
        obj.params_packet_inventory_transaction = {}; pdef::proto::decode::packet_inventory_transaction(stream, *obj.params_packet_inventory_transaction); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobEquipment: { /*8.5*/
        obj.params_packet_mob_equipment = {}; pdef::proto::decode::packet_mob_equipment(stream, *obj.params_packet_mob_equipment); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MobArmorEquipment: { /*8.5*/
        obj.params_packet_mob_armor_equipment = {}; pdef::proto::decode::packet_mob_armor_equipment(stream, *obj.params_packet_mob_armor_equipment); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Interact: { /*8.5*/
        obj.params_packet_interact = {}; pdef::proto::decode::packet_interact(stream, *obj.params_packet_interact); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockPickRequest: { /*8.5*/
        obj.params_packet_block_pick_request = {}; pdef::proto::decode::packet_block_pick_request(stream, *obj.params_packet_block_pick_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EntityPickRequest: { /*8.5*/
        obj.params_packet_entity_pick_request = {}; pdef::proto::decode::packet_entity_pick_request(stream, *obj.params_packet_entity_pick_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerAction: { /*8.5*/
        obj.params_packet_player_action = {}; pdef::proto::decode::packet_player_action(stream, *obj.params_packet_player_action); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::HurtArmor: { /*8.5*/
        obj.params_packet_hurt_armor = {}; pdef::proto::decode::packet_hurt_armor(stream, *obj.params_packet_hurt_armor); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityData: { /*8.5*/
        obj.params_packet_set_entity_data = {}; pdef::proto::decode::packet_set_entity_data(stream, *obj.params_packet_set_entity_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityMotion: { /*8.5*/
        obj.params_packet_set_entity_motion = {}; pdef::proto::decode::packet_set_entity_motion(stream, *obj.params_packet_set_entity_motion); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetEntityLink: { /*8.5*/
        obj.params_packet_set_entity_link = {}; pdef::proto::decode::packet_set_entity_link(stream, *obj.params_packet_set_entity_link); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetHealth: { /*8.5*/
        obj.params_packet_set_health = {}; pdef::proto::decode::packet_set_health(stream, *obj.params_packet_set_health); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetSpawnPosition: { /*8.5*/
        obj.params_packet_set_spawn_position = {}; pdef::proto::decode::packet_set_spawn_position(stream, *obj.params_packet_set_spawn_position); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Animate: { /*8.5*/
        obj.params_packet_animate = {}; pdef::proto::decode::packet_animate(stream, *obj.params_packet_animate); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Respawn: { /*8.5*/
        obj.params_packet_respawn = {}; pdef::proto::decode::packet_respawn(stream, *obj.params_packet_respawn); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerOpen: { /*8.5*/
        obj.params_packet_container_open = {}; pdef::proto::decode::packet_container_open(stream, *obj.params_packet_container_open); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerClose: { /*8.5*/
        obj.params_packet_container_close = {}; pdef::proto::decode::packet_container_close(stream, *obj.params_packet_container_close); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerHotbar: { /*8.5*/
        obj.params_packet_player_hotbar = {}; pdef::proto::decode::packet_player_hotbar(stream, *obj.params_packet_player_hotbar); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventoryContent: { /*8.5*/
        obj.params_packet_inventory_content = {}; pdef::proto::decode::packet_inventory_content(stream, *obj.params_packet_inventory_content); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InventorySlot: { /*8.5*/
        obj.params_packet_inventory_slot = {}; pdef::proto::decode::packet_inventory_slot(stream, *obj.params_packet_inventory_slot); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ContainerSetData: { /*8.5*/
        obj.params_packet_container_set_data = {}; pdef::proto::decode::packet_container_set_data(stream, *obj.params_packet_container_set_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CraftingData: { /*8.5*/
        obj.params_packet_crafting_data = {}; pdef::proto::decode::packet_crafting_data(stream, *obj.params_packet_crafting_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CraftingEvent: { /*8.5*/
        obj.params_packet_crafting_event = {}; pdef::proto::decode::packet_crafting_event(stream, *obj.params_packet_crafting_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::GuiDataPickItem: { /*8.5*/
        obj.params_packet_gui_data_pick_item = {}; pdef::proto::decode::packet_gui_data_pick_item(stream, *obj.params_packet_gui_data_pick_item); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AdventureSettings: { /*8.5*/
        obj.params_packet_adventure_settings = {}; pdef::proto::decode::packet_adventure_settings(stream, *obj.params_packet_adventure_settings); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BlockEntityData: { /*8.5*/
        obj.params_packet_block_entity_data = {}; pdef::proto::decode::packet_block_entity_data(stream, *obj.params_packet_block_entity_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerInput: { /*8.5*/
        obj.params_packet_player_input = {}; pdef::proto::decode::packet_player_input(stream, *obj.params_packet_player_input); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelChunk: { /*8.5*/
        obj.params_packet_level_chunk = {}; pdef::proto::decode::packet_level_chunk(stream, *obj.params_packet_level_chunk); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetCommandsEnabled: { /*8.5*/
        obj.params_packet_set_commands_enabled = {}; pdef::proto::decode::packet_set_commands_enabled(stream, *obj.params_packet_set_commands_enabled); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDifficulty: { /*8.5*/
        obj.params_packet_set_difficulty = {}; pdef::proto::decode::packet_set_difficulty(stream, *obj.params_packet_set_difficulty); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChangeDimension: { /*8.5*/
        obj.params_packet_change_dimension = {}; pdef::proto::decode::packet_change_dimension(stream, *obj.params_packet_change_dimension); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetPlayerGameType: { /*8.5*/
        obj.params_packet_set_player_game_type = {}; pdef::proto::decode::packet_set_player_game_type(stream, *obj.params_packet_set_player_game_type); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerList: { /*8.5*/
        obj.params_packet_player_list = {}; pdef::proto::decode::packet_player_list(stream, *obj.params_packet_player_list); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SimpleEvent: { /*8.5*/
        obj.params_packet_simple_event = {}; pdef::proto::decode::packet_simple_event(stream, *obj.params_packet_simple_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Event: { /*8.5*/
        obj.params_packet_event = {}; pdef::proto::decode::packet_event(stream, *obj.params_packet_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SpawnExperienceOrb: { /*8.5*/
        obj.params_packet_spawn_experience_orb = {}; pdef::proto::decode::packet_spawn_experience_orb(stream, *obj.params_packet_spawn_experience_orb); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientboundMapItemData: { /*8.5*/
        obj.params_packet_clientbound_map_item_data = {}; pdef::proto::decode::packet_clientbound_map_item_data(stream, *obj.params_packet_clientbound_map_item_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MapInfoRequest: { /*8.5*/
        obj.params_packet_map_info_request = {}; pdef::proto::decode::packet_map_info_request(stream, *obj.params_packet_map_info_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestChunkRadius: { /*8.5*/
        obj.params_packet_request_chunk_radius = {}; pdef::proto::decode::packet_request_chunk_radius(stream, *obj.params_packet_request_chunk_radius); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChunkRadiusUpdate: { /*8.5*/
        obj.params_packet_chunk_radius_update = {}; pdef::proto::decode::packet_chunk_radius_update(stream, *obj.params_packet_chunk_radius_update); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemFrameDropItem: { /*8.5*/
        obj.params_packet_item_frame_drop_item = {}; pdef::proto::decode::packet_item_frame_drop_item(stream, *obj.params_packet_item_frame_drop_item); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::GameRulesChanged: { /*8.5*/
        obj.params_packet_game_rules_changed = {}; pdef::proto::decode::packet_game_rules_changed(stream, *obj.params_packet_game_rules_changed); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Camera: { /*8.5*/
        obj.params_packet_camera = {}; pdef::proto::decode::packet_camera(stream, *obj.params_packet_camera); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BossEvent: { /*8.5*/
        obj.params_packet_boss_event = {}; pdef::proto::decode::packet_boss_event(stream, *obj.params_packet_boss_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowCredits: { /*8.5*/
        obj.params_packet_show_credits = {}; pdef::proto::decode::packet_show_credits(stream, *obj.params_packet_show_credits); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AvailableCommands: { /*8.5*/
        obj.params_packet_available_commands = {}; pdef::proto::decode::packet_available_commands(stream, *obj.params_packet_available_commands); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandRequest: { /*8.5*/
        obj.params_packet_command_request = {}; pdef::proto::decode::packet_command_request(stream, *obj.params_packet_command_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandBlockUpdate: { /*8.5*/
        obj.params_packet_command_block_update = {}; pdef::proto::decode::packet_command_block_update(stream, *obj.params_packet_command_block_update); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CommandOutput: { /*8.5*/
        obj.params_packet_command_output = {}; pdef::proto::decode::packet_command_output(stream, *obj.params_packet_command_output); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateTrade: { /*8.5*/
        obj.params_packet_update_trade = {}; pdef::proto::decode::packet_update_trade(stream, *obj.params_packet_update_trade); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateEquipment: { /*8.5*/
        obj.params_packet_update_equipment = {}; pdef::proto::decode::packet_update_equipment(stream, *obj.params_packet_update_equipment); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackDataInfo: { /*8.5*/
        obj.params_packet_resource_pack_data_info = {}; pdef::proto::decode::packet_resource_pack_data_info(stream, *obj.params_packet_resource_pack_data_info); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackChunkData: { /*8.5*/
        obj.params_packet_resource_pack_chunk_data = {}; pdef::proto::decode::packet_resource_pack_chunk_data(stream, *obj.params_packet_resource_pack_chunk_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ResourcePackChunkRequest: { /*8.5*/
        obj.params_packet_resource_pack_chunk_request = {}; pdef::proto::decode::packet_resource_pack_chunk_request(stream, *obj.params_packet_resource_pack_chunk_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Transfer: { /*8.5*/
        obj.params_packet_transfer = {}; pdef::proto::decode::packet_transfer(stream, *obj.params_packet_transfer); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlaySound: { /*8.5*/
        obj.params_packet_play_sound = {}; pdef::proto::decode::packet_play_sound(stream, *obj.params_packet_play_sound); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StopSound: { /*8.5*/
        obj.params_packet_stop_sound = {}; pdef::proto::decode::packet_stop_sound(stream, *obj.params_packet_stop_sound); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetTitle: { /*8.5*/
        obj.params_packet_set_title = {}; pdef::proto::decode::packet_set_title(stream, *obj.params_packet_set_title); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddBehaviorTree: { /*8.5*/
        obj.params_packet_add_behavior_tree = {}; pdef::proto::decode::packet_add_behavior_tree(stream, *obj.params_packet_add_behavior_tree); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureBlockUpdate: { /*8.5*/
        obj.params_packet_structure_block_update = {}; pdef::proto::decode::packet_structure_block_update(stream, *obj.params_packet_structure_block_update); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowStoreOffer: { /*8.5*/
        obj.params_packet_show_store_offer = {}; pdef::proto::decode::packet_show_store_offer(stream, *obj.params_packet_show_store_offer); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PurchaseReceipt: { /*8.5*/
        obj.params_packet_purchase_receipt = {}; pdef::proto::decode::packet_purchase_receipt(stream, *obj.params_packet_purchase_receipt); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerSkin: { /*8.5*/
        obj.params_packet_player_skin = {}; pdef::proto::decode::packet_player_skin(stream, *obj.params_packet_player_skin); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SubClientLogin: { /*8.5*/
        obj.params_packet_sub_client_login = {}; pdef::proto::decode::packet_sub_client_login(stream, *obj.params_packet_sub_client_login); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::InitiateWebSocketConnection: { /*8.5*/
        obj.params_packet_initiate_web_socket_connection = {}; pdef::proto::decode::packet_initiate_web_socket_connection(stream, *obj.params_packet_initiate_web_socket_connection); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetLastHurtBy: { /*8.5*/
        obj.params_packet_set_last_hurt_by = {}; pdef::proto::decode::packet_set_last_hurt_by(stream, *obj.params_packet_set_last_hurt_by); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BookEdit: { /*8.5*/
        obj.params_packet_book_edit = {}; pdef::proto::decode::packet_book_edit(stream, *obj.params_packet_book_edit); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NpcRequest: { /*8.5*/
        obj.params_packet_npc_request = {}; pdef::proto::decode::packet_npc_request(stream, *obj.params_packet_npc_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PhotoTransfer: { /*8.5*/
        obj.params_packet_photo_transfer = {}; pdef::proto::decode::packet_photo_transfer(stream, *obj.params_packet_photo_transfer); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ModalFormRequest: { /*8.5*/
        obj.params_packet_modal_form_request = {}; pdef::proto::decode::packet_modal_form_request(stream, *obj.params_packet_modal_form_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ModalFormResponse: { /*8.5*/
        obj.params_packet_modal_form_response = {}; pdef::proto::decode::packet_modal_form_response(stream, *obj.params_packet_modal_form_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerSettingsRequest: { /*8.5*/
        obj.params_packet_server_settings_request = {}; pdef::proto::decode::packet_server_settings_request(stream, *obj.params_packet_server_settings_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ServerSettingsResponse: { /*8.5*/
        obj.params_packet_server_settings_response = {}; pdef::proto::decode::packet_server_settings_response(stream, *obj.params_packet_server_settings_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ShowProfile: { /*8.5*/
        obj.params_packet_show_profile = {}; pdef::proto::decode::packet_show_profile(stream, *obj.params_packet_show_profile); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDefaultGameType: { /*8.5*/
        obj.params_packet_set_default_game_type = {}; pdef::proto::decode::packet_set_default_game_type(stream, *obj.params_packet_set_default_game_type); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveObjective: { /*8.5*/
        obj.params_packet_remove_objective = {}; pdef::proto::decode::packet_remove_objective(stream, *obj.params_packet_remove_objective); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetDisplayObjective: { /*8.5*/
        obj.params_packet_set_display_objective = {}; pdef::proto::decode::packet_set_display_objective(stream, *obj.params_packet_set_display_objective); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetScore: { /*8.5*/
        obj.params_packet_set_score = {}; pdef::proto::decode::packet_set_score(stream, *obj.params_packet_set_score); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LabTable: { /*8.5*/
        obj.params_packet_lab_table = {}; pdef::proto::decode::packet_lab_table(stream, *obj.params_packet_lab_table); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlockSynced: { /*8.5*/
        obj.params_packet_update_block_synced = {}; pdef::proto::decode::packet_update_block_synced(stream, *obj.params_packet_update_block_synced); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MoveEntityDelta: { /*8.5*/
        obj.params_packet_move_entity_delta = {}; pdef::proto::decode::packet_move_entity_delta(stream, *obj.params_packet_move_entity_delta); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetScoreboardIdentity: { /*8.5*/
        obj.params_packet_set_scoreboard_identity = {}; pdef::proto::decode::packet_set_scoreboard_identity(stream, *obj.params_packet_set_scoreboard_identity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SetLocalPlayerAsInitialized: { /*8.5*/
        obj.params_packet_set_local_player_as_initialized = {}; pdef::proto::decode::packet_set_local_player_as_initialized(stream, *obj.params_packet_set_local_player_as_initialized); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateSoftEnum: { /*8.5*/
        obj.params_packet_update_soft_enum = {}; pdef::proto::decode::packet_update_soft_enum(stream, *obj.params_packet_update_soft_enum); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkStackLatency: { /*8.5*/
        obj.params_packet_network_stack_latency = {}; pdef::proto::decode::packet_network_stack_latency(stream, *obj.params_packet_network_stack_latency); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ScriptCustomEvent: { /*8.5*/
        obj.params_packet_script_custom_event = {}; pdef::proto::decode::packet_script_custom_event(stream, *obj.params_packet_script_custom_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SpawnParticleEffect: { /*8.5*/
        obj.params_packet_spawn_particle_effect = {}; pdef::proto::decode::packet_spawn_particle_effect(stream, *obj.params_packet_spawn_particle_effect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AvailableEntityIdentifiers: { /*8.5*/
        obj.params_packet_available_entity_identifiers = {}; pdef::proto::decode::packet_available_entity_identifiers(stream, *obj.params_packet_available_entity_identifiers); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEventV2: { /*8.5*/
        obj.params_packet_level_sound_event_v2 = {}; pdef::proto::decode::packet_level_sound_event_v2(stream, *obj.params_packet_level_sound_event_v2); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkChunkPublisherUpdate: { /*8.5*/
        obj.params_packet_network_chunk_publisher_update = {}; pdef::proto::decode::packet_network_chunk_publisher_update(stream, *obj.params_packet_network_chunk_publisher_update); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::BiomeDefinitionList: { /*8.5*/
        obj.params_packet_biome_definition_list = {}; pdef::proto::decode::packet_biome_definition_list(stream, *obj.params_packet_biome_definition_list); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelSoundEvent: { /*8.5*/
        obj.params_packet_level_sound_event = {}; pdef::proto::decode::packet_level_sound_event(stream, *obj.params_packet_level_sound_event); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LevelEventGeneric: { /*8.5*/
        obj.params_packet_level_event_generic = {}; pdef::proto::decode::packet_level_event_generic(stream, *obj.params_packet_level_event_generic); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LecternUpdate: { /*8.5*/
        obj.params_packet_lectern_update = {}; pdef::proto::decode::packet_lectern_update(stream, *obj.params_packet_lectern_update); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::VideoStreamConnect: { /*8.5*/
        obj.params_packet_video_stream_connect = {}; pdef::proto::decode::packet_video_stream_connect(stream, *obj.params_packet_video_stream_connect); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddEcsEntity: { /*8.5*/
        obj.params_packet_add_ecs_entity = {}; pdef::proto::decode::packet_add_ecs_entity(stream, *obj.params_packet_add_ecs_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveEcsEntity: { /*8.5*/
        obj.params_packet_remove_ecs_entity = {}; pdef::proto::decode::packet_remove_ecs_entity(stream, *obj.params_packet_remove_ecs_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheStatus: { /*8.5*/
        obj.params_packet_client_cache_status = {}; pdef::proto::decode::packet_client_cache_status(stream, *obj.params_packet_client_cache_status); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::OnScreenTextureAnimation: { /*8.5*/
        obj.params_packet_on_screen_texture_animation = {}; pdef::proto::decode::packet_on_screen_texture_animation(stream, *obj.params_packet_on_screen_texture_animation); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MapCreateLockedCopy: { /*8.5*/
        obj.params_packet_map_create_locked_copy = {}; pdef::proto::decode::packet_map_create_locked_copy(stream, *obj.params_packet_map_create_locked_copy); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureTemplateDataExportRequest: { /*8.5*/
        obj.params_packet_structure_template_data_export_request = {}; pdef::proto::decode::packet_structure_template_data_export_request(stream, *obj.params_packet_structure_template_data_export_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::StructureTemplateDataExportResponse: { /*8.5*/
        obj.params_packet_structure_template_data_export_response = {}; pdef::proto::decode::packet_structure_template_data_export_response(stream, *obj.params_packet_structure_template_data_export_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateBlockProperties: { /*8.5*/
        obj.params_packet_update_block_properties = {}; pdef::proto::decode::packet_update_block_properties(stream, *obj.params_packet_update_block_properties); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheBlobStatus: { /*8.5*/
        obj.params_packet_client_cache_blob_status = {}; pdef::proto::decode::packet_client_cache_blob_status(stream, *obj.params_packet_client_cache_blob_status); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientCacheMissResponse: { /*8.5*/
        obj.params_packet_client_cache_miss_response = {}; pdef::proto::decode::packet_client_cache_miss_response(stream, *obj.params_packet_client_cache_miss_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EducationSettings: { /*8.5*/
        obj.params_packet_education_settings = {}; pdef::proto::decode::packet_education_settings(stream, *obj.params_packet_education_settings); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Emote: { /*8.5*/
        obj.params_packet_emote = {}; pdef::proto::decode::packet_emote(stream, *obj.params_packet_emote); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MultiplayerSettings: { /*8.5*/
        obj.params_packet_multiplayer_settings = {}; pdef::proto::decode::packet_multiplayer_settings(stream, *obj.params_packet_multiplayer_settings); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SettingsCommand: { /*8.5*/
        obj.params_packet_settings_command = {}; pdef::proto::decode::packet_settings_command(stream, *obj.params_packet_settings_command); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AnvilDamage: { /*8.5*/
        obj.params_packet_anvil_damage = {}; pdef::proto::decode::packet_anvil_damage(stream, *obj.params_packet_anvil_damage); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CompletedUsingItem: { /*8.5*/
        obj.params_packet_completed_using_item = {}; pdef::proto::decode::packet_completed_using_item(stream, *obj.params_packet_completed_using_item); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NetworkSettings: { /*8.5*/
        obj.params_packet_network_settings = {}; pdef::proto::decode::packet_network_settings(stream, *obj.params_packet_network_settings); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerAuthInput: { /*8.5*/
        obj.params_packet_player_auth_input = {}; pdef::proto::decode::packet_player_auth_input(stream, *obj.params_packet_player_auth_input); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CreativeContent: { /*8.5*/
        obj.params_packet_creative_content = {}; pdef::proto::decode::packet_creative_content(stream, *obj.params_packet_creative_content); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerEnchantOptions: { /*8.5*/
        obj.params_packet_player_enchant_options = {}; pdef::proto::decode::packet_player_enchant_options(stream, *obj.params_packet_player_enchant_options); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemStackRequest: { /*8.5*/
        obj.params_packet_item_stack_request = {}; pdef::proto::decode::packet_item_stack_request(stream, *obj.params_packet_item_stack_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemStackResponse: { /*8.5*/
        obj.params_packet_item_stack_response = {}; pdef::proto::decode::packet_item_stack_response(stream, *obj.params_packet_item_stack_response); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerArmorDamage: { /*8.5*/
        obj.params_packet_player_armor_damage = {}; pdef::proto::decode::packet_player_armor_damage(stream, *obj.params_packet_player_armor_damage); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdatePlayerGameType: { /*8.5*/
        obj.params_packet_update_player_game_type = {}; pdef::proto::decode::packet_update_player_game_type(stream, *obj.params_packet_update_player_game_type); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EmoteList: { /*8.5*/
        obj.params_packet_emote_list = {}; pdef::proto::decode::packet_emote_list(stream, *obj.params_packet_emote_list); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PositionTrackingDbRequest: { /*8.5*/
        obj.params_packet_position_tracking_db_request = {}; pdef::proto::decode::packet_position_tracking_db_request(stream, *obj.params_packet_position_tracking_db_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PositionTrackingDbBroadcast: { /*8.5*/
        obj.params_packet_position_tracking_db_broadcast = {}; pdef::proto::decode::packet_position_tracking_db_broadcast(stream, *obj.params_packet_position_tracking_db_broadcast); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PacketViolationWarning: { /*8.5*/
        obj.params_packet_packet_violation_warning = {}; pdef::proto::decode::packet_packet_violation_warning(stream, *obj.params_packet_packet_violation_warning); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::MotionPredictionHints: { /*8.5*/
        obj.params_packet_motion_prediction_hints = {}; pdef::proto::decode::packet_motion_prediction_hints(stream, *obj.params_packet_motion_prediction_hints); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AnimateEntity: { /*8.5*/
        obj.params_packet_animate_entity = {}; pdef::proto::decode::packet_animate_entity(stream, *obj.params_packet_animate_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CameraShake: { /*8.5*/
        obj.params_packet_camera_shake = {}; pdef::proto::decode::packet_camera_shake(stream, *obj.params_packet_camera_shake); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PlayerFog: { /*8.5*/
        obj.params_packet_player_fog = {}; pdef::proto::decode::packet_player_fog(stream, *obj.params_packet_player_fog); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CorrectPlayerMovePrediction: { /*8.5*/
        obj.params_packet_correct_player_move_prediction = {}; pdef::proto::decode::packet_correct_player_move_prediction(stream, *obj.params_packet_correct_player_move_prediction); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ItemComponent: { /*8.5*/
        obj.params_packet_item_component = {}; pdef::proto::decode::packet_item_component(stream, *obj.params_packet_item_component); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::FilterTextPacket: { /*8.5*/
        obj.params_packet_filter_text_packet = {}; pdef::proto::decode::packet_filter_text_packet(stream, *obj.params_packet_filter_text_packet); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::DebugRenderer: { /*8.5*/
        obj.params_packet_debug_renderer = {}; pdef::proto::decode::packet_debug_renderer(stream, *obj.params_packet_debug_renderer); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SyncEntityProperty: { /*8.5*/
        obj.params_packet_sync_entity_property = {}; pdef::proto::decode::packet_sync_entity_property(stream, *obj.params_packet_sync_entity_property); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AddVolumeEntity: { /*8.5*/
        obj.params_packet_add_volume_entity = {}; pdef::proto::decode::packet_add_volume_entity(stream, *obj.params_packet_add_volume_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RemoveVolumeEntity: { /*8.5*/
        obj.params_packet_remove_volume_entity = {}; pdef::proto::decode::packet_remove_volume_entity(stream, *obj.params_packet_remove_volume_entity); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SimulationType: { /*8.5*/
        obj.params_packet_simulation_type = {}; pdef::proto::decode::packet_simulation_type(stream, *obj.params_packet_simulation_type); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::NpcDialogue: { /*8.5*/
        obj.params_packet_npc_dialogue = {}; pdef::proto::decode::packet_npc_dialogue(stream, *obj.params_packet_npc_dialogue); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::EduUriResourcePacket: { /*8.5*/
        obj.params_packet_edu_uri_resource_packet = {}; pdef::proto::decode::packet_edu_uri_resource_packet(stream, *obj.params_packet_edu_uri_resource_packet); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CreatePhoto: { /*8.5*/
        obj.params_packet_create_photo = {}; pdef::proto::decode::packet_create_photo(stream, *obj.params_packet_create_photo); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::UpdateSubchunkBlocks: { /*8.5*/
        obj.params_packet_update_subchunk_blocks = {}; pdef::proto::decode::packet_update_subchunk_blocks(stream, *obj.params_packet_update_subchunk_blocks); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::PhotoInfoRequest: { /*8.5*/
        obj.params_packet_photo_info_request = {}; pdef::proto::decode::packet_photo_info_request(stream, *obj.params_packet_photo_info_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::Subchunk: { /*8.5*/
        obj.params_packet_subchunk = {}; pdef::proto::decode::packet_subchunk(stream, *obj.params_packet_subchunk); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::SubchunkRequest: { /*8.5*/
        obj.params_packet_subchunk_request = {}; pdef::proto::decode::packet_subchunk_request(stream, *obj.params_packet_subchunk_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ClientStartItemCooldown: { /*8.5*/
        obj.params_packet_client_start_item_cooldown = {}; pdef::proto::decode::packet_client_start_item_cooldown(stream, *obj.params_packet_client_start_item_cooldown); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ScriptMessage: { /*8.5*/
        obj.params_packet_script_message = {}; pdef::proto::decode::packet_script_message(stream, *obj.params_packet_script_message); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::CodeBuilderSource: { /*8.5*/
        obj.params_packet_code_builder_source = {}; pdef::proto::decode::packet_code_builder_source(stream, *obj.params_packet_code_builder_source); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::TickingAreasLoadStatus: { /*8.5*/
        obj.params_packet_ticking_areas_load_status = {}; pdef::proto::decode::packet_ticking_areas_load_status(stream, *obj.params_packet_ticking_areas_load_status); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::DimensionData: { /*8.5*/
        obj.params_packet_dimension_data = {}; pdef::proto::decode::packet_dimension_data(stream, *obj.params_packet_dimension_data); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::AgentAction: { /*8.5*/
        obj.params_packet_agent_action = {}; pdef::proto::decode::packet_agent_action(stream, *obj.params_packet_agent_action); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ChangeMobProperty: { /*8.5*/
        obj.params_packet_change_mob_property = {}; pdef::proto::decode::packet_change_mob_property(stream, *obj.params_packet_change_mob_property); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::LessonProgress: { /*8.5*/
        obj.params_packet_lesson_progress = {}; pdef::proto::decode::packet_lesson_progress(stream, *obj.params_packet_lesson_progress); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestAbility: { /*8.5*/
        obj.params_packet_request_ability = {}; pdef::proto::decode::packet_request_ability(stream, *obj.params_packet_request_ability); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::RequestPermissions: { /*8.5*/
        obj.params_packet_request_permissions = {}; pdef::proto::decode::packet_request_permissions(stream, *obj.params_packet_request_permissions); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      case pdef::proto::mcpe_packet::Name::ToastRequest: { /*8.5*/
        obj.params_packet_toast_request = {}; pdef::proto::decode::packet_toast_request(stream, *obj.params_packet_toast_request); /*obj*/ /*4.6*/
        break;
      } /*8.7*/
      default: break; /*avoid unhandled case warning*/
    } /*8.8*/
    return true;
  }
}

#undef WRITE_OR_BAIL
#undef READ_OR_BAIL
