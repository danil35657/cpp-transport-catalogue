// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: map_renderer.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_map_5frenderer_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_map_5frenderer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "svg.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_map_5frenderer_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_map_5frenderer_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_map_5frenderer_2eproto;
namespace proto {
class MapRendererSettings;
struct MapRendererSettingsDefaultTypeInternal;
extern MapRendererSettingsDefaultTypeInternal _MapRendererSettings_default_instance_;
class Point;
struct PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> ::proto::MapRendererSettings* Arena::CreateMaybeMessage<::proto::MapRendererSettings>(Arena*);
template<> ::proto::Point* Arena::CreateMaybeMessage<::proto::Point>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto {

// ===================================================================

class Point final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  ~Point() override;
  explicit PROTOBUF_CONSTEXPR Point(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Point& default_instance() {
    return *internal_default_instance();
  }
  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Point& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Point& from) {
    Point::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Point* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:proto.Point)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    double x_;
    double y_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_map_5frenderer_2eproto;
};
// -------------------------------------------------------------------

class MapRendererSettings final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.MapRendererSettings) */ {
 public:
  inline MapRendererSettings() : MapRendererSettings(nullptr) {}
  ~MapRendererSettings() override;
  explicit PROTOBUF_CONSTEXPR MapRendererSettings(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MapRendererSettings(const MapRendererSettings& from);
  MapRendererSettings(MapRendererSettings&& from) noexcept
    : MapRendererSettings() {
    *this = ::std::move(from);
  }

  inline MapRendererSettings& operator=(const MapRendererSettings& from) {
    CopyFrom(from);
    return *this;
  }
  inline MapRendererSettings& operator=(MapRendererSettings&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MapRendererSettings& default_instance() {
    return *internal_default_instance();
  }
  static inline const MapRendererSettings* internal_default_instance() {
    return reinterpret_cast<const MapRendererSettings*>(
               &_MapRendererSettings_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(MapRendererSettings& a, MapRendererSettings& b) {
    a.Swap(&b);
  }
  inline void Swap(MapRendererSettings* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MapRendererSettings* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MapRendererSettings* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MapRendererSettings>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const MapRendererSettings& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const MapRendererSettings& from) {
    MapRendererSettings::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MapRendererSettings* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.MapRendererSettings";
  }
  protected:
  explicit MapRendererSettings(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kColorPaletteFieldNumber = 12,
    kBusLabelOffsetFieldNumber = 7,
    kStopLabelOffsetFieldNumber = 9,
    kUnderlayerColorFieldNumber = 10,
    kWidthFieldNumber = 1,
    kHeightFieldNumber = 2,
    kPaddingFieldNumber = 3,
    kLineWidthFieldNumber = 4,
    kStopRadiusFieldNumber = 5,
    kBusLabelFontSizeFieldNumber = 6,
    kStopLabelFontSizeFieldNumber = 8,
    kUnderlayerWidthFieldNumber = 11,
  };
  // repeated .proto.Color color_palette = 12;
  int color_palette_size() const;
  private:
  int _internal_color_palette_size() const;
  public:
  void clear_color_palette();
  ::proto::Color* mutable_color_palette(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Color >*
      mutable_color_palette();
  private:
  const ::proto::Color& _internal_color_palette(int index) const;
  ::proto::Color* _internal_add_color_palette();
  public:
  const ::proto::Color& color_palette(int index) const;
  ::proto::Color* add_color_palette();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Color >&
      color_palette() const;

  // .proto.Point bus_label_offset = 7;
  bool has_bus_label_offset() const;
  private:
  bool _internal_has_bus_label_offset() const;
  public:
  void clear_bus_label_offset();
  const ::proto::Point& bus_label_offset() const;
  PROTOBUF_NODISCARD ::proto::Point* release_bus_label_offset();
  ::proto::Point* mutable_bus_label_offset();
  void set_allocated_bus_label_offset(::proto::Point* bus_label_offset);
  private:
  const ::proto::Point& _internal_bus_label_offset() const;
  ::proto::Point* _internal_mutable_bus_label_offset();
  public:
  void unsafe_arena_set_allocated_bus_label_offset(
      ::proto::Point* bus_label_offset);
  ::proto::Point* unsafe_arena_release_bus_label_offset();

  // .proto.Point stop_label_offset = 9;
  bool has_stop_label_offset() const;
  private:
  bool _internal_has_stop_label_offset() const;
  public:
  void clear_stop_label_offset();
  const ::proto::Point& stop_label_offset() const;
  PROTOBUF_NODISCARD ::proto::Point* release_stop_label_offset();
  ::proto::Point* mutable_stop_label_offset();
  void set_allocated_stop_label_offset(::proto::Point* stop_label_offset);
  private:
  const ::proto::Point& _internal_stop_label_offset() const;
  ::proto::Point* _internal_mutable_stop_label_offset();
  public:
  void unsafe_arena_set_allocated_stop_label_offset(
      ::proto::Point* stop_label_offset);
  ::proto::Point* unsafe_arena_release_stop_label_offset();

  // .proto.Color underlayer_color = 10;
  bool has_underlayer_color() const;
  private:
  bool _internal_has_underlayer_color() const;
  public:
  void clear_underlayer_color();
  const ::proto::Color& underlayer_color() const;
  PROTOBUF_NODISCARD ::proto::Color* release_underlayer_color();
  ::proto::Color* mutable_underlayer_color();
  void set_allocated_underlayer_color(::proto::Color* underlayer_color);
  private:
  const ::proto::Color& _internal_underlayer_color() const;
  ::proto::Color* _internal_mutable_underlayer_color();
  public:
  void unsafe_arena_set_allocated_underlayer_color(
      ::proto::Color* underlayer_color);
  ::proto::Color* unsafe_arena_release_underlayer_color();

  // double width = 1;
  void clear_width();
  double width() const;
  void set_width(double value);
  private:
  double _internal_width() const;
  void _internal_set_width(double value);
  public:

  // double height = 2;
  void clear_height();
  double height() const;
  void set_height(double value);
  private:
  double _internal_height() const;
  void _internal_set_height(double value);
  public:

  // double padding = 3;
  void clear_padding();
  double padding() const;
  void set_padding(double value);
  private:
  double _internal_padding() const;
  void _internal_set_padding(double value);
  public:

  // double line_width = 4;
  void clear_line_width();
  double line_width() const;
  void set_line_width(double value);
  private:
  double _internal_line_width() const;
  void _internal_set_line_width(double value);
  public:

  // double stop_radius = 5;
  void clear_stop_radius();
  double stop_radius() const;
  void set_stop_radius(double value);
  private:
  double _internal_stop_radius() const;
  void _internal_set_stop_radius(double value);
  public:

  // uint32 bus_label_font_size = 6;
  void clear_bus_label_font_size();
  uint32_t bus_label_font_size() const;
  void set_bus_label_font_size(uint32_t value);
  private:
  uint32_t _internal_bus_label_font_size() const;
  void _internal_set_bus_label_font_size(uint32_t value);
  public:

  // uint32 stop_label_font_size = 8;
  void clear_stop_label_font_size();
  uint32_t stop_label_font_size() const;
  void set_stop_label_font_size(uint32_t value);
  private:
  uint32_t _internal_stop_label_font_size() const;
  void _internal_set_stop_label_font_size(uint32_t value);
  public:

  // double underlayer_width = 11;
  void clear_underlayer_width();
  double underlayer_width() const;
  void set_underlayer_width(double value);
  private:
  double _internal_underlayer_width() const;
  void _internal_set_underlayer_width(double value);
  public:

  // @@protoc_insertion_point(class_scope:proto.MapRendererSettings)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Color > color_palette_;
    ::proto::Point* bus_label_offset_;
    ::proto::Point* stop_label_offset_;
    ::proto::Color* underlayer_color_;
    double width_;
    double height_;
    double padding_;
    double line_width_;
    double stop_radius_;
    uint32_t bus_label_font_size_;
    uint32_t stop_label_font_size_;
    double underlayer_width_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_map_5frenderer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Point

// double x = 1;
inline void Point::clear_x() {
  _impl_.x_ = 0;
}
inline double Point::_internal_x() const {
  return _impl_.x_;
}
inline double Point::x() const {
  // @@protoc_insertion_point(field_get:proto.Point.x)
  return _internal_x();
}
inline void Point::_internal_set_x(double value) {
  
  _impl_.x_ = value;
}
inline void Point::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:proto.Point.x)
}

// double y = 2;
inline void Point::clear_y() {
  _impl_.y_ = 0;
}
inline double Point::_internal_y() const {
  return _impl_.y_;
}
inline double Point::y() const {
  // @@protoc_insertion_point(field_get:proto.Point.y)
  return _internal_y();
}
inline void Point::_internal_set_y(double value) {
  
  _impl_.y_ = value;
}
inline void Point::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:proto.Point.y)
}

// -------------------------------------------------------------------

// MapRendererSettings

// double width = 1;
inline void MapRendererSettings::clear_width() {
  _impl_.width_ = 0;
}
inline double MapRendererSettings::_internal_width() const {
  return _impl_.width_;
}
inline double MapRendererSettings::width() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.width)
  return _internal_width();
}
inline void MapRendererSettings::_internal_set_width(double value) {
  
  _impl_.width_ = value;
}
inline void MapRendererSettings::set_width(double value) {
  _internal_set_width(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.width)
}

// double height = 2;
inline void MapRendererSettings::clear_height() {
  _impl_.height_ = 0;
}
inline double MapRendererSettings::_internal_height() const {
  return _impl_.height_;
}
inline double MapRendererSettings::height() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.height)
  return _internal_height();
}
inline void MapRendererSettings::_internal_set_height(double value) {
  
  _impl_.height_ = value;
}
inline void MapRendererSettings::set_height(double value) {
  _internal_set_height(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.height)
}

// double padding = 3;
inline void MapRendererSettings::clear_padding() {
  _impl_.padding_ = 0;
}
inline double MapRendererSettings::_internal_padding() const {
  return _impl_.padding_;
}
inline double MapRendererSettings::padding() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.padding)
  return _internal_padding();
}
inline void MapRendererSettings::_internal_set_padding(double value) {
  
  _impl_.padding_ = value;
}
inline void MapRendererSettings::set_padding(double value) {
  _internal_set_padding(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.padding)
}

// double line_width = 4;
inline void MapRendererSettings::clear_line_width() {
  _impl_.line_width_ = 0;
}
inline double MapRendererSettings::_internal_line_width() const {
  return _impl_.line_width_;
}
inline double MapRendererSettings::line_width() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.line_width)
  return _internal_line_width();
}
inline void MapRendererSettings::_internal_set_line_width(double value) {
  
  _impl_.line_width_ = value;
}
inline void MapRendererSettings::set_line_width(double value) {
  _internal_set_line_width(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.line_width)
}

// double stop_radius = 5;
inline void MapRendererSettings::clear_stop_radius() {
  _impl_.stop_radius_ = 0;
}
inline double MapRendererSettings::_internal_stop_radius() const {
  return _impl_.stop_radius_;
}
inline double MapRendererSettings::stop_radius() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.stop_radius)
  return _internal_stop_radius();
}
inline void MapRendererSettings::_internal_set_stop_radius(double value) {
  
  _impl_.stop_radius_ = value;
}
inline void MapRendererSettings::set_stop_radius(double value) {
  _internal_set_stop_radius(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.stop_radius)
}

// uint32 bus_label_font_size = 6;
inline void MapRendererSettings::clear_bus_label_font_size() {
  _impl_.bus_label_font_size_ = 0u;
}
inline uint32_t MapRendererSettings::_internal_bus_label_font_size() const {
  return _impl_.bus_label_font_size_;
}
inline uint32_t MapRendererSettings::bus_label_font_size() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.bus_label_font_size)
  return _internal_bus_label_font_size();
}
inline void MapRendererSettings::_internal_set_bus_label_font_size(uint32_t value) {
  
  _impl_.bus_label_font_size_ = value;
}
inline void MapRendererSettings::set_bus_label_font_size(uint32_t value) {
  _internal_set_bus_label_font_size(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.bus_label_font_size)
}

// .proto.Point bus_label_offset = 7;
inline bool MapRendererSettings::_internal_has_bus_label_offset() const {
  return this != internal_default_instance() && _impl_.bus_label_offset_ != nullptr;
}
inline bool MapRendererSettings::has_bus_label_offset() const {
  return _internal_has_bus_label_offset();
}
inline void MapRendererSettings::clear_bus_label_offset() {
  if (GetArenaForAllocation() == nullptr && _impl_.bus_label_offset_ != nullptr) {
    delete _impl_.bus_label_offset_;
  }
  _impl_.bus_label_offset_ = nullptr;
}
inline const ::proto::Point& MapRendererSettings::_internal_bus_label_offset() const {
  const ::proto::Point* p = _impl_.bus_label_offset_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto::Point&>(
      ::proto::_Point_default_instance_);
}
inline const ::proto::Point& MapRendererSettings::bus_label_offset() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.bus_label_offset)
  return _internal_bus_label_offset();
}
inline void MapRendererSettings::unsafe_arena_set_allocated_bus_label_offset(
    ::proto::Point* bus_label_offset) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.bus_label_offset_);
  }
  _impl_.bus_label_offset_ = bus_label_offset;
  if (bus_label_offset) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:proto.MapRendererSettings.bus_label_offset)
}
inline ::proto::Point* MapRendererSettings::release_bus_label_offset() {
  
  ::proto::Point* temp = _impl_.bus_label_offset_;
  _impl_.bus_label_offset_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::proto::Point* MapRendererSettings::unsafe_arena_release_bus_label_offset() {
  // @@protoc_insertion_point(field_release:proto.MapRendererSettings.bus_label_offset)
  
  ::proto::Point* temp = _impl_.bus_label_offset_;
  _impl_.bus_label_offset_ = nullptr;
  return temp;
}
inline ::proto::Point* MapRendererSettings::_internal_mutable_bus_label_offset() {
  
  if (_impl_.bus_label_offset_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto::Point>(GetArenaForAllocation());
    _impl_.bus_label_offset_ = p;
  }
  return _impl_.bus_label_offset_;
}
inline ::proto::Point* MapRendererSettings::mutable_bus_label_offset() {
  ::proto::Point* _msg = _internal_mutable_bus_label_offset();
  // @@protoc_insertion_point(field_mutable:proto.MapRendererSettings.bus_label_offset)
  return _msg;
}
inline void MapRendererSettings::set_allocated_bus_label_offset(::proto::Point* bus_label_offset) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.bus_label_offset_;
  }
  if (bus_label_offset) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(bus_label_offset);
    if (message_arena != submessage_arena) {
      bus_label_offset = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, bus_label_offset, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.bus_label_offset_ = bus_label_offset;
  // @@protoc_insertion_point(field_set_allocated:proto.MapRendererSettings.bus_label_offset)
}

// uint32 stop_label_font_size = 8;
inline void MapRendererSettings::clear_stop_label_font_size() {
  _impl_.stop_label_font_size_ = 0u;
}
inline uint32_t MapRendererSettings::_internal_stop_label_font_size() const {
  return _impl_.stop_label_font_size_;
}
inline uint32_t MapRendererSettings::stop_label_font_size() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.stop_label_font_size)
  return _internal_stop_label_font_size();
}
inline void MapRendererSettings::_internal_set_stop_label_font_size(uint32_t value) {
  
  _impl_.stop_label_font_size_ = value;
}
inline void MapRendererSettings::set_stop_label_font_size(uint32_t value) {
  _internal_set_stop_label_font_size(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.stop_label_font_size)
}

// .proto.Point stop_label_offset = 9;
inline bool MapRendererSettings::_internal_has_stop_label_offset() const {
  return this != internal_default_instance() && _impl_.stop_label_offset_ != nullptr;
}
inline bool MapRendererSettings::has_stop_label_offset() const {
  return _internal_has_stop_label_offset();
}
inline void MapRendererSettings::clear_stop_label_offset() {
  if (GetArenaForAllocation() == nullptr && _impl_.stop_label_offset_ != nullptr) {
    delete _impl_.stop_label_offset_;
  }
  _impl_.stop_label_offset_ = nullptr;
}
inline const ::proto::Point& MapRendererSettings::_internal_stop_label_offset() const {
  const ::proto::Point* p = _impl_.stop_label_offset_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto::Point&>(
      ::proto::_Point_default_instance_);
}
inline const ::proto::Point& MapRendererSettings::stop_label_offset() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.stop_label_offset)
  return _internal_stop_label_offset();
}
inline void MapRendererSettings::unsafe_arena_set_allocated_stop_label_offset(
    ::proto::Point* stop_label_offset) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.stop_label_offset_);
  }
  _impl_.stop_label_offset_ = stop_label_offset;
  if (stop_label_offset) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:proto.MapRendererSettings.stop_label_offset)
}
inline ::proto::Point* MapRendererSettings::release_stop_label_offset() {
  
  ::proto::Point* temp = _impl_.stop_label_offset_;
  _impl_.stop_label_offset_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::proto::Point* MapRendererSettings::unsafe_arena_release_stop_label_offset() {
  // @@protoc_insertion_point(field_release:proto.MapRendererSettings.stop_label_offset)
  
  ::proto::Point* temp = _impl_.stop_label_offset_;
  _impl_.stop_label_offset_ = nullptr;
  return temp;
}
inline ::proto::Point* MapRendererSettings::_internal_mutable_stop_label_offset() {
  
  if (_impl_.stop_label_offset_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto::Point>(GetArenaForAllocation());
    _impl_.stop_label_offset_ = p;
  }
  return _impl_.stop_label_offset_;
}
inline ::proto::Point* MapRendererSettings::mutable_stop_label_offset() {
  ::proto::Point* _msg = _internal_mutable_stop_label_offset();
  // @@protoc_insertion_point(field_mutable:proto.MapRendererSettings.stop_label_offset)
  return _msg;
}
inline void MapRendererSettings::set_allocated_stop_label_offset(::proto::Point* stop_label_offset) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.stop_label_offset_;
  }
  if (stop_label_offset) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(stop_label_offset);
    if (message_arena != submessage_arena) {
      stop_label_offset = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, stop_label_offset, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.stop_label_offset_ = stop_label_offset;
  // @@protoc_insertion_point(field_set_allocated:proto.MapRendererSettings.stop_label_offset)
}

// .proto.Color underlayer_color = 10;
inline bool MapRendererSettings::_internal_has_underlayer_color() const {
  return this != internal_default_instance() && _impl_.underlayer_color_ != nullptr;
}
inline bool MapRendererSettings::has_underlayer_color() const {
  return _internal_has_underlayer_color();
}
inline const ::proto::Color& MapRendererSettings::_internal_underlayer_color() const {
  const ::proto::Color* p = _impl_.underlayer_color_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto::Color&>(
      ::proto::_Color_default_instance_);
}
inline const ::proto::Color& MapRendererSettings::underlayer_color() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.underlayer_color)
  return _internal_underlayer_color();
}
inline void MapRendererSettings::unsafe_arena_set_allocated_underlayer_color(
    ::proto::Color* underlayer_color) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.underlayer_color_);
  }
  _impl_.underlayer_color_ = underlayer_color;
  if (underlayer_color) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:proto.MapRendererSettings.underlayer_color)
}
inline ::proto::Color* MapRendererSettings::release_underlayer_color() {
  
  ::proto::Color* temp = _impl_.underlayer_color_;
  _impl_.underlayer_color_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::proto::Color* MapRendererSettings::unsafe_arena_release_underlayer_color() {
  // @@protoc_insertion_point(field_release:proto.MapRendererSettings.underlayer_color)
  
  ::proto::Color* temp = _impl_.underlayer_color_;
  _impl_.underlayer_color_ = nullptr;
  return temp;
}
inline ::proto::Color* MapRendererSettings::_internal_mutable_underlayer_color() {
  
  if (_impl_.underlayer_color_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto::Color>(GetArenaForAllocation());
    _impl_.underlayer_color_ = p;
  }
  return _impl_.underlayer_color_;
}
inline ::proto::Color* MapRendererSettings::mutable_underlayer_color() {
  ::proto::Color* _msg = _internal_mutable_underlayer_color();
  // @@protoc_insertion_point(field_mutable:proto.MapRendererSettings.underlayer_color)
  return _msg;
}
inline void MapRendererSettings::set_allocated_underlayer_color(::proto::Color* underlayer_color) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.underlayer_color_);
  }
  if (underlayer_color) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(underlayer_color));
    if (message_arena != submessage_arena) {
      underlayer_color = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, underlayer_color, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.underlayer_color_ = underlayer_color;
  // @@protoc_insertion_point(field_set_allocated:proto.MapRendererSettings.underlayer_color)
}

// double underlayer_width = 11;
inline void MapRendererSettings::clear_underlayer_width() {
  _impl_.underlayer_width_ = 0;
}
inline double MapRendererSettings::_internal_underlayer_width() const {
  return _impl_.underlayer_width_;
}
inline double MapRendererSettings::underlayer_width() const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.underlayer_width)
  return _internal_underlayer_width();
}
inline void MapRendererSettings::_internal_set_underlayer_width(double value) {
  
  _impl_.underlayer_width_ = value;
}
inline void MapRendererSettings::set_underlayer_width(double value) {
  _internal_set_underlayer_width(value);
  // @@protoc_insertion_point(field_set:proto.MapRendererSettings.underlayer_width)
}

// repeated .proto.Color color_palette = 12;
inline int MapRendererSettings::_internal_color_palette_size() const {
  return _impl_.color_palette_.size();
}
inline int MapRendererSettings::color_palette_size() const {
  return _internal_color_palette_size();
}
inline ::proto::Color* MapRendererSettings::mutable_color_palette(int index) {
  // @@protoc_insertion_point(field_mutable:proto.MapRendererSettings.color_palette)
  return _impl_.color_palette_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Color >*
MapRendererSettings::mutable_color_palette() {
  // @@protoc_insertion_point(field_mutable_list:proto.MapRendererSettings.color_palette)
  return &_impl_.color_palette_;
}
inline const ::proto::Color& MapRendererSettings::_internal_color_palette(int index) const {
  return _impl_.color_palette_.Get(index);
}
inline const ::proto::Color& MapRendererSettings::color_palette(int index) const {
  // @@protoc_insertion_point(field_get:proto.MapRendererSettings.color_palette)
  return _internal_color_palette(index);
}
inline ::proto::Color* MapRendererSettings::_internal_add_color_palette() {
  return _impl_.color_palette_.Add();
}
inline ::proto::Color* MapRendererSettings::add_color_palette() {
  ::proto::Color* _add = _internal_add_color_palette();
  // @@protoc_insertion_point(field_add:proto.MapRendererSettings.color_palette)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Color >&
MapRendererSettings::color_palette() const {
  // @@protoc_insertion_point(field_list:proto.MapRendererSettings.color_palette)
  return _impl_.color_palette_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_map_5frenderer_2eproto