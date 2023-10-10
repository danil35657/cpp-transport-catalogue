// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: map_renderer.proto

#include "map_renderer.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace proto {
PROTOBUF_CONSTEXPR Point::Point(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.x_)*/0
  , /*decltype(_impl_.y_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PointDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PointDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PointDefaultTypeInternal() {}
  union {
    Point _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PointDefaultTypeInternal _Point_default_instance_;
PROTOBUF_CONSTEXPR MapRendererSettings::MapRendererSettings(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.color_palette_)*/{}
  , /*decltype(_impl_.bus_label_offset_)*/nullptr
  , /*decltype(_impl_.stop_label_offset_)*/nullptr
  , /*decltype(_impl_.underlayer_color_)*/nullptr
  , /*decltype(_impl_.width_)*/0
  , /*decltype(_impl_.height_)*/0
  , /*decltype(_impl_.padding_)*/0
  , /*decltype(_impl_.line_width_)*/0
  , /*decltype(_impl_.stop_radius_)*/0
  , /*decltype(_impl_.bus_label_font_size_)*/0u
  , /*decltype(_impl_.stop_label_font_size_)*/0u
  , /*decltype(_impl_.underlayer_width_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct MapRendererSettingsDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MapRendererSettingsDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MapRendererSettingsDefaultTypeInternal() {}
  union {
    MapRendererSettings _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MapRendererSettingsDefaultTypeInternal _MapRendererSettings_default_instance_;
}  // namespace proto
static ::_pb::Metadata file_level_metadata_map_5frenderer_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_map_5frenderer_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_map_5frenderer_2eproto = nullptr;

const uint32_t TableStruct_map_5frenderer_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::Point, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::Point, _impl_.x_),
  PROTOBUF_FIELD_OFFSET(::proto::Point, _impl_.y_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.width_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.height_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.padding_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.line_width_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.stop_radius_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.bus_label_font_size_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.bus_label_offset_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.stop_label_font_size_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.stop_label_offset_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.underlayer_color_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.underlayer_width_),
  PROTOBUF_FIELD_OFFSET(::proto::MapRendererSettings, _impl_.color_palette_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::proto::Point)},
  { 8, -1, -1, sizeof(::proto::MapRendererSettings)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::proto::_Point_default_instance_._instance,
  &::proto::_MapRendererSettings_default_instance_._instance,
};

const char descriptor_table_protodef_map_5frenderer_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022map_renderer.proto\022\005proto\032\tsvg.proto\"\035"
  "\n\005Point\022\t\n\001x\030\001 \001(\001\022\t\n\001y\030\002 \001(\001\"\341\002\n\023MapRen"
  "dererSettings\022\r\n\005width\030\001 \001(\001\022\016\n\006height\030\002"
  " \001(\001\022\017\n\007padding\030\003 \001(\001\022\022\n\nline_width\030\004 \001("
  "\001\022\023\n\013stop_radius\030\005 \001(\001\022\033\n\023bus_label_font"
  "_size\030\006 \001(\r\022&\n\020bus_label_offset\030\007 \001(\0132\014."
  "proto.Point\022\034\n\024stop_label_font_size\030\010 \001("
  "\r\022\'\n\021stop_label_offset\030\t \001(\0132\014.proto.Poi"
  "nt\022&\n\020underlayer_color\030\n \001(\0132\014.proto.Col"
  "or\022\030\n\020underlayer_width\030\013 \001(\001\022#\n\rcolor_pa"
  "lette\030\014 \003(\0132\014.proto.Colorb\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_map_5frenderer_2eproto_deps[1] = {
  &::descriptor_table_svg_2eproto,
};
static ::_pbi::once_flag descriptor_table_map_5frenderer_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_map_5frenderer_2eproto = {
    false, false, 433, descriptor_table_protodef_map_5frenderer_2eproto,
    "map_renderer.proto",
    &descriptor_table_map_5frenderer_2eproto_once, descriptor_table_map_5frenderer_2eproto_deps, 1, 2,
    schemas, file_default_instances, TableStruct_map_5frenderer_2eproto::offsets,
    file_level_metadata_map_5frenderer_2eproto, file_level_enum_descriptors_map_5frenderer_2eproto,
    file_level_service_descriptors_map_5frenderer_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_map_5frenderer_2eproto_getter() {
  return &descriptor_table_map_5frenderer_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_map_5frenderer_2eproto(&descriptor_table_map_5frenderer_2eproto);
namespace proto {

// ===================================================================

class Point::_Internal {
 public:
};

Point::Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:proto.Point)
}
Point::Point(const Point& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Point* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.x_){}
    , decltype(_impl_.y_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.x_, &from._impl_.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.y_) -
    reinterpret_cast<char*>(&_impl_.x_)) + sizeof(_impl_.y_));
  // @@protoc_insertion_point(copy_constructor:proto.Point)
}

inline void Point::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.x_){0}
    , decltype(_impl_.y_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Point::~Point() {
  // @@protoc_insertion_point(destructor:proto.Point)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Point::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Point::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Point::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.Point)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.y_) -
      reinterpret_cast<char*>(&_impl_.x_)) + sizeof(_impl_.y_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Point::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // double x = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          _impl_.x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double y = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 17)) {
          _impl_.y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Point::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.Point)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // double x = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_x = this->_internal_x();
  uint64_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(1, this->_internal_x(), target);
  }

  // double y = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_y = this->_internal_y();
  uint64_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(2, this->_internal_y(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.Point)
  return target;
}

size_t Point::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.Point)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // double x = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_x = this->_internal_x();
  uint64_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    total_size += 1 + 8;
  }

  // double y = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_y = this->_internal_y();
  uint64_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Point::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Point::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Point::GetClassData() const { return &_class_data_; }


void Point::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Point*>(&to_msg);
  auto& from = static_cast<const Point&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:proto.Point)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_x = from._internal_x();
  uint64_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    _this->_internal_set_x(from._internal_x());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_y = from._internal_y();
  uint64_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    _this->_internal_set_y(from._internal_y());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Point::CopyFrom(const Point& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.Point)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Point::IsInitialized() const {
  return true;
}

void Point::InternalSwap(Point* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Point, _impl_.y_)
      + sizeof(Point::_impl_.y_)
      - PROTOBUF_FIELD_OFFSET(Point, _impl_.x_)>(
          reinterpret_cast<char*>(&_impl_.x_),
          reinterpret_cast<char*>(&other->_impl_.x_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Point::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_map_5frenderer_2eproto_getter, &descriptor_table_map_5frenderer_2eproto_once,
      file_level_metadata_map_5frenderer_2eproto[0]);
}

// ===================================================================

class MapRendererSettings::_Internal {
 public:
  static const ::proto::Point& bus_label_offset(const MapRendererSettings* msg);
  static const ::proto::Point& stop_label_offset(const MapRendererSettings* msg);
  static const ::proto::Color& underlayer_color(const MapRendererSettings* msg);
};

const ::proto::Point&
MapRendererSettings::_Internal::bus_label_offset(const MapRendererSettings* msg) {
  return *msg->_impl_.bus_label_offset_;
}
const ::proto::Point&
MapRendererSettings::_Internal::stop_label_offset(const MapRendererSettings* msg) {
  return *msg->_impl_.stop_label_offset_;
}
const ::proto::Color&
MapRendererSettings::_Internal::underlayer_color(const MapRendererSettings* msg) {
  return *msg->_impl_.underlayer_color_;
}
void MapRendererSettings::clear_underlayer_color() {
  if (GetArenaForAllocation() == nullptr && _impl_.underlayer_color_ != nullptr) {
    delete _impl_.underlayer_color_;
  }
  _impl_.underlayer_color_ = nullptr;
}
void MapRendererSettings::clear_color_palette() {
  _impl_.color_palette_.Clear();
}
MapRendererSettings::MapRendererSettings(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:proto.MapRendererSettings)
}
MapRendererSettings::MapRendererSettings(const MapRendererSettings& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  MapRendererSettings* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.color_palette_){from._impl_.color_palette_}
    , decltype(_impl_.bus_label_offset_){nullptr}
    , decltype(_impl_.stop_label_offset_){nullptr}
    , decltype(_impl_.underlayer_color_){nullptr}
    , decltype(_impl_.width_){}
    , decltype(_impl_.height_){}
    , decltype(_impl_.padding_){}
    , decltype(_impl_.line_width_){}
    , decltype(_impl_.stop_radius_){}
    , decltype(_impl_.bus_label_font_size_){}
    , decltype(_impl_.stop_label_font_size_){}
    , decltype(_impl_.underlayer_width_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_bus_label_offset()) {
    _this->_impl_.bus_label_offset_ = new ::proto::Point(*from._impl_.bus_label_offset_);
  }
  if (from._internal_has_stop_label_offset()) {
    _this->_impl_.stop_label_offset_ = new ::proto::Point(*from._impl_.stop_label_offset_);
  }
  if (from._internal_has_underlayer_color()) {
    _this->_impl_.underlayer_color_ = new ::proto::Color(*from._impl_.underlayer_color_);
  }
  ::memcpy(&_impl_.width_, &from._impl_.width_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.underlayer_width_) -
    reinterpret_cast<char*>(&_impl_.width_)) + sizeof(_impl_.underlayer_width_));
  // @@protoc_insertion_point(copy_constructor:proto.MapRendererSettings)
}

inline void MapRendererSettings::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.color_palette_){arena}
    , decltype(_impl_.bus_label_offset_){nullptr}
    , decltype(_impl_.stop_label_offset_){nullptr}
    , decltype(_impl_.underlayer_color_){nullptr}
    , decltype(_impl_.width_){0}
    , decltype(_impl_.height_){0}
    , decltype(_impl_.padding_){0}
    , decltype(_impl_.line_width_){0}
    , decltype(_impl_.stop_radius_){0}
    , decltype(_impl_.bus_label_font_size_){0u}
    , decltype(_impl_.stop_label_font_size_){0u}
    , decltype(_impl_.underlayer_width_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

MapRendererSettings::~MapRendererSettings() {
  // @@protoc_insertion_point(destructor:proto.MapRendererSettings)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MapRendererSettings::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.color_palette_.~RepeatedPtrField();
  if (this != internal_default_instance()) delete _impl_.bus_label_offset_;
  if (this != internal_default_instance()) delete _impl_.stop_label_offset_;
  if (this != internal_default_instance()) delete _impl_.underlayer_color_;
}

void MapRendererSettings::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void MapRendererSettings::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.MapRendererSettings)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.color_palette_.Clear();
  if (GetArenaForAllocation() == nullptr && _impl_.bus_label_offset_ != nullptr) {
    delete _impl_.bus_label_offset_;
  }
  _impl_.bus_label_offset_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.stop_label_offset_ != nullptr) {
    delete _impl_.stop_label_offset_;
  }
  _impl_.stop_label_offset_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.underlayer_color_ != nullptr) {
    delete _impl_.underlayer_color_;
  }
  _impl_.underlayer_color_ = nullptr;
  ::memset(&_impl_.width_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.underlayer_width_) -
      reinterpret_cast<char*>(&_impl_.width_)) + sizeof(_impl_.underlayer_width_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MapRendererSettings::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // double width = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          _impl_.width_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double height = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 17)) {
          _impl_.height_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double padding = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 25)) {
          _impl_.padding_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double line_width = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          _impl_.line_width_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double stop_radius = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 41)) {
          _impl_.stop_radius_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // uint32 bus_label_font_size = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          _impl_.bus_label_font_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .proto.Point bus_label_offset = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          ptr = ctx->ParseMessage(_internal_mutable_bus_label_offset(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 stop_label_font_size = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 64)) {
          _impl_.stop_label_font_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .proto.Point stop_label_offset = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 74)) {
          ptr = ctx->ParseMessage(_internal_mutable_stop_label_offset(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .proto.Color underlayer_color = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 82)) {
          ptr = ctx->ParseMessage(_internal_mutable_underlayer_color(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double underlayer_width = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 89)) {
          _impl_.underlayer_width_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // repeated .proto.Color color_palette = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 98)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_color_palette(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<98>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MapRendererSettings::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.MapRendererSettings)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // double width = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_width = this->_internal_width();
  uint64_t raw_width;
  memcpy(&raw_width, &tmp_width, sizeof(tmp_width));
  if (raw_width != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(1, this->_internal_width(), target);
  }

  // double height = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = this->_internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(2, this->_internal_height(), target);
  }

  // double padding = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_padding = this->_internal_padding();
  uint64_t raw_padding;
  memcpy(&raw_padding, &tmp_padding, sizeof(tmp_padding));
  if (raw_padding != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(3, this->_internal_padding(), target);
  }

  // double line_width = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_line_width = this->_internal_line_width();
  uint64_t raw_line_width;
  memcpy(&raw_line_width, &tmp_line_width, sizeof(tmp_line_width));
  if (raw_line_width != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(4, this->_internal_line_width(), target);
  }

  // double stop_radius = 5;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_stop_radius = this->_internal_stop_radius();
  uint64_t raw_stop_radius;
  memcpy(&raw_stop_radius, &tmp_stop_radius, sizeof(tmp_stop_radius));
  if (raw_stop_radius != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(5, this->_internal_stop_radius(), target);
  }

  // uint32 bus_label_font_size = 6;
  if (this->_internal_bus_label_font_size() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(6, this->_internal_bus_label_font_size(), target);
  }

  // .proto.Point bus_label_offset = 7;
  if (this->_internal_has_bus_label_offset()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(7, _Internal::bus_label_offset(this),
        _Internal::bus_label_offset(this).GetCachedSize(), target, stream);
  }

  // uint32 stop_label_font_size = 8;
  if (this->_internal_stop_label_font_size() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(8, this->_internal_stop_label_font_size(), target);
  }

  // .proto.Point stop_label_offset = 9;
  if (this->_internal_has_stop_label_offset()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(9, _Internal::stop_label_offset(this),
        _Internal::stop_label_offset(this).GetCachedSize(), target, stream);
  }

  // .proto.Color underlayer_color = 10;
  if (this->_internal_has_underlayer_color()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(10, _Internal::underlayer_color(this),
        _Internal::underlayer_color(this).GetCachedSize(), target, stream);
  }

  // double underlayer_width = 11;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_underlayer_width = this->_internal_underlayer_width();
  uint64_t raw_underlayer_width;
  memcpy(&raw_underlayer_width, &tmp_underlayer_width, sizeof(tmp_underlayer_width));
  if (raw_underlayer_width != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(11, this->_internal_underlayer_width(), target);
  }

  // repeated .proto.Color color_palette = 12;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_color_palette_size()); i < n; i++) {
    const auto& repfield = this->_internal_color_palette(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(12, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.MapRendererSettings)
  return target;
}

size_t MapRendererSettings::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.MapRendererSettings)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .proto.Color color_palette = 12;
  total_size += 1UL * this->_internal_color_palette_size();
  for (const auto& msg : this->_impl_.color_palette_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // .proto.Point bus_label_offset = 7;
  if (this->_internal_has_bus_label_offset()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.bus_label_offset_);
  }

  // .proto.Point stop_label_offset = 9;
  if (this->_internal_has_stop_label_offset()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.stop_label_offset_);
  }

  // .proto.Color underlayer_color = 10;
  if (this->_internal_has_underlayer_color()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.underlayer_color_);
  }

  // double width = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_width = this->_internal_width();
  uint64_t raw_width;
  memcpy(&raw_width, &tmp_width, sizeof(tmp_width));
  if (raw_width != 0) {
    total_size += 1 + 8;
  }

  // double height = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = this->_internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    total_size += 1 + 8;
  }

  // double padding = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_padding = this->_internal_padding();
  uint64_t raw_padding;
  memcpy(&raw_padding, &tmp_padding, sizeof(tmp_padding));
  if (raw_padding != 0) {
    total_size += 1 + 8;
  }

  // double line_width = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_line_width = this->_internal_line_width();
  uint64_t raw_line_width;
  memcpy(&raw_line_width, &tmp_line_width, sizeof(tmp_line_width));
  if (raw_line_width != 0) {
    total_size += 1 + 8;
  }

  // double stop_radius = 5;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_stop_radius = this->_internal_stop_radius();
  uint64_t raw_stop_radius;
  memcpy(&raw_stop_radius, &tmp_stop_radius, sizeof(tmp_stop_radius));
  if (raw_stop_radius != 0) {
    total_size += 1 + 8;
  }

  // uint32 bus_label_font_size = 6;
  if (this->_internal_bus_label_font_size() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_bus_label_font_size());
  }

  // uint32 stop_label_font_size = 8;
  if (this->_internal_stop_label_font_size() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_stop_label_font_size());
  }

  // double underlayer_width = 11;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_underlayer_width = this->_internal_underlayer_width();
  uint64_t raw_underlayer_width;
  memcpy(&raw_underlayer_width, &tmp_underlayer_width, sizeof(tmp_underlayer_width));
  if (raw_underlayer_width != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MapRendererSettings::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    MapRendererSettings::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MapRendererSettings::GetClassData() const { return &_class_data_; }


void MapRendererSettings::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<MapRendererSettings*>(&to_msg);
  auto& from = static_cast<const MapRendererSettings&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:proto.MapRendererSettings)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.color_palette_.MergeFrom(from._impl_.color_palette_);
  if (from._internal_has_bus_label_offset()) {
    _this->_internal_mutable_bus_label_offset()->::proto::Point::MergeFrom(
        from._internal_bus_label_offset());
  }
  if (from._internal_has_stop_label_offset()) {
    _this->_internal_mutable_stop_label_offset()->::proto::Point::MergeFrom(
        from._internal_stop_label_offset());
  }
  if (from._internal_has_underlayer_color()) {
    _this->_internal_mutable_underlayer_color()->::proto::Color::MergeFrom(
        from._internal_underlayer_color());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_width = from._internal_width();
  uint64_t raw_width;
  memcpy(&raw_width, &tmp_width, sizeof(tmp_width));
  if (raw_width != 0) {
    _this->_internal_set_width(from._internal_width());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = from._internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    _this->_internal_set_height(from._internal_height());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_padding = from._internal_padding();
  uint64_t raw_padding;
  memcpy(&raw_padding, &tmp_padding, sizeof(tmp_padding));
  if (raw_padding != 0) {
    _this->_internal_set_padding(from._internal_padding());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_line_width = from._internal_line_width();
  uint64_t raw_line_width;
  memcpy(&raw_line_width, &tmp_line_width, sizeof(tmp_line_width));
  if (raw_line_width != 0) {
    _this->_internal_set_line_width(from._internal_line_width());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_stop_radius = from._internal_stop_radius();
  uint64_t raw_stop_radius;
  memcpy(&raw_stop_radius, &tmp_stop_radius, sizeof(tmp_stop_radius));
  if (raw_stop_radius != 0) {
    _this->_internal_set_stop_radius(from._internal_stop_radius());
  }
  if (from._internal_bus_label_font_size() != 0) {
    _this->_internal_set_bus_label_font_size(from._internal_bus_label_font_size());
  }
  if (from._internal_stop_label_font_size() != 0) {
    _this->_internal_set_stop_label_font_size(from._internal_stop_label_font_size());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_underlayer_width = from._internal_underlayer_width();
  uint64_t raw_underlayer_width;
  memcpy(&raw_underlayer_width, &tmp_underlayer_width, sizeof(tmp_underlayer_width));
  if (raw_underlayer_width != 0) {
    _this->_internal_set_underlayer_width(from._internal_underlayer_width());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MapRendererSettings::CopyFrom(const MapRendererSettings& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.MapRendererSettings)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MapRendererSettings::IsInitialized() const {
  return true;
}

void MapRendererSettings::InternalSwap(MapRendererSettings* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.color_palette_.InternalSwap(&other->_impl_.color_palette_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MapRendererSettings, _impl_.underlayer_width_)
      + sizeof(MapRendererSettings::_impl_.underlayer_width_)
      - PROTOBUF_FIELD_OFFSET(MapRendererSettings, _impl_.bus_label_offset_)>(
          reinterpret_cast<char*>(&_impl_.bus_label_offset_),
          reinterpret_cast<char*>(&other->_impl_.bus_label_offset_));
}

::PROTOBUF_NAMESPACE_ID::Metadata MapRendererSettings::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_map_5frenderer_2eproto_getter, &descriptor_table_map_5frenderer_2eproto_once,
      file_level_metadata_map_5frenderer_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::proto::Point*
Arena::CreateMaybeMessage< ::proto::Point >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::Point >(arena);
}
template<> PROTOBUF_NOINLINE ::proto::MapRendererSettings*
Arena::CreateMaybeMessage< ::proto::MapRendererSettings >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::MapRendererSettings >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>