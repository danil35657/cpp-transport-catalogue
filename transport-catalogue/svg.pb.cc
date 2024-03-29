// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: svg.proto

#include "svg.pb.h"

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
PROTOBUF_CONSTEXPR ColorString::ColorString(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.color_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ColorStringDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ColorStringDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ColorStringDefaultTypeInternal() {}
  union {
    ColorString _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ColorStringDefaultTypeInternal _ColorString_default_instance_;
PROTOBUF_CONSTEXPR ColorArray::ColorArray(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.color_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ColorArrayDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ColorArrayDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ColorArrayDefaultTypeInternal() {}
  union {
    ColorArray _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ColorArrayDefaultTypeInternal _ColorArray_default_instance_;
PROTOBUF_CONSTEXPR Color::Color(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.color_string_)*/nullptr
  , /*decltype(_impl_.color_array_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ColorDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ColorDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ColorDefaultTypeInternal() {}
  union {
    Color _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ColorDefaultTypeInternal _Color_default_instance_;
}  // namespace proto
static ::_pb::Metadata file_level_metadata_svg_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_svg_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_svg_2eproto = nullptr;

const uint32_t TableStruct_svg_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::ColorString, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::ColorString, _impl_.color_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::ColorArray, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::ColorArray, _impl_.color_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::Color, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::Color, _impl_.color_string_),
  PROTOBUF_FIELD_OFFSET(::proto::Color, _impl_.color_array_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::proto::ColorString)},
  { 7, -1, -1, sizeof(::proto::ColorArray)},
  { 14, -1, -1, sizeof(::proto::Color)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::proto::_ColorString_default_instance_._instance,
  &::proto::_ColorArray_default_instance_._instance,
  &::proto::_Color_default_instance_._instance,
};

const char descriptor_table_protodef_svg_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\tsvg.proto\022\005proto\"\034\n\013ColorString\022\r\n\005col"
  "or\030\001 \001(\t\"\033\n\nColorArray\022\r\n\005color\030\001 \003(\002\"Y\n"
  "\005Color\022(\n\014color_string\030\001 \001(\0132\022.proto.Col"
  "orString\022&\n\013color_array\030\002 \001(\0132\021.proto.Co"
  "lorArrayb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_svg_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_svg_2eproto = {
    false, false, 176, descriptor_table_protodef_svg_2eproto,
    "svg.proto",
    &descriptor_table_svg_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_svg_2eproto::offsets,
    file_level_metadata_svg_2eproto, file_level_enum_descriptors_svg_2eproto,
    file_level_service_descriptors_svg_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_svg_2eproto_getter() {
  return &descriptor_table_svg_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_svg_2eproto(&descriptor_table_svg_2eproto);
namespace proto {

// ===================================================================

class ColorString::_Internal {
 public:
};

ColorString::ColorString(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:proto.ColorString)
}
ColorString::ColorString(const ColorString& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ColorString* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.color_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.color_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.color_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_color().empty()) {
    _this->_impl_.color_.Set(from._internal_color(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:proto.ColorString)
}

inline void ColorString::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.color_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.color_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.color_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ColorString::~ColorString() {
  // @@protoc_insertion_point(destructor:proto.ColorString)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ColorString::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.color_.Destroy();
}

void ColorString::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ColorString::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.ColorString)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.color_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ColorString::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string color = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_color();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.ColorString.color"));
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

uint8_t* ColorString::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.ColorString)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string color = 1;
  if (!this->_internal_color().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_color().data(), static_cast<int>(this->_internal_color().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.ColorString.color");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_color(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.ColorString)
  return target;
}

size_t ColorString::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.ColorString)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string color = 1;
  if (!this->_internal_color().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_color());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ColorString::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ColorString::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ColorString::GetClassData() const { return &_class_data_; }


void ColorString::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ColorString*>(&to_msg);
  auto& from = static_cast<const ColorString&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:proto.ColorString)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_color().empty()) {
    _this->_internal_set_color(from._internal_color());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ColorString::CopyFrom(const ColorString& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.ColorString)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ColorString::IsInitialized() const {
  return true;
}

void ColorString::InternalSwap(ColorString* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.color_, lhs_arena,
      &other->_impl_.color_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata ColorString::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_svg_2eproto_getter, &descriptor_table_svg_2eproto_once,
      file_level_metadata_svg_2eproto[0]);
}

// ===================================================================

class ColorArray::_Internal {
 public:
};

ColorArray::ColorArray(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:proto.ColorArray)
}
ColorArray::ColorArray(const ColorArray& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ColorArray* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.color_){from._impl_.color_}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:proto.ColorArray)
}

inline void ColorArray::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.color_){arena}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

ColorArray::~ColorArray() {
  // @@protoc_insertion_point(destructor:proto.ColorArray)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ColorArray::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.color_.~RepeatedField();
}

void ColorArray::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ColorArray::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.ColorArray)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.color_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ColorArray::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated float color = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedFloatParser(_internal_mutable_color(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 13) {
          _internal_add_color(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr));
          ptr += sizeof(float);
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

uint8_t* ColorArray::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.ColorArray)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated float color = 1;
  if (this->_internal_color_size() > 0) {
    target = stream->WriteFixedPacked(1, _internal_color(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.ColorArray)
  return target;
}

size_t ColorArray::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.ColorArray)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated float color = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_color_size());
    size_t data_size = 4UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ColorArray::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ColorArray::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ColorArray::GetClassData() const { return &_class_data_; }


void ColorArray::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ColorArray*>(&to_msg);
  auto& from = static_cast<const ColorArray&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:proto.ColorArray)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.color_.MergeFrom(from._impl_.color_);
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ColorArray::CopyFrom(const ColorArray& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.ColorArray)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ColorArray::IsInitialized() const {
  return true;
}

void ColorArray::InternalSwap(ColorArray* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.color_.InternalSwap(&other->_impl_.color_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ColorArray::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_svg_2eproto_getter, &descriptor_table_svg_2eproto_once,
      file_level_metadata_svg_2eproto[1]);
}

// ===================================================================

class Color::_Internal {
 public:
  static const ::proto::ColorString& color_string(const Color* msg);
  static const ::proto::ColorArray& color_array(const Color* msg);
};

const ::proto::ColorString&
Color::_Internal::color_string(const Color* msg) {
  return *msg->_impl_.color_string_;
}
const ::proto::ColorArray&
Color::_Internal::color_array(const Color* msg) {
  return *msg->_impl_.color_array_;
}
Color::Color(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:proto.Color)
}
Color::Color(const Color& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Color* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.color_string_){nullptr}
    , decltype(_impl_.color_array_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_color_string()) {
    _this->_impl_.color_string_ = new ::proto::ColorString(*from._impl_.color_string_);
  }
  if (from._internal_has_color_array()) {
    _this->_impl_.color_array_ = new ::proto::ColorArray(*from._impl_.color_array_);
  }
  // @@protoc_insertion_point(copy_constructor:proto.Color)
}

inline void Color::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.color_string_){nullptr}
    , decltype(_impl_.color_array_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Color::~Color() {
  // @@protoc_insertion_point(destructor:proto.Color)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Color::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.color_string_;
  if (this != internal_default_instance()) delete _impl_.color_array_;
}

void Color::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Color::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.Color)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.color_string_ != nullptr) {
    delete _impl_.color_string_;
  }
  _impl_.color_string_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.color_array_ != nullptr) {
    delete _impl_.color_array_;
  }
  _impl_.color_array_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Color::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .proto.ColorString color_string = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_color_string(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .proto.ColorArray color_array = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_color_array(), ptr);
          CHK_(ptr);
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

uint8_t* Color::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.Color)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .proto.ColorString color_string = 1;
  if (this->_internal_has_color_string()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::color_string(this),
        _Internal::color_string(this).GetCachedSize(), target, stream);
  }

  // .proto.ColorArray color_array = 2;
  if (this->_internal_has_color_array()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::color_array(this),
        _Internal::color_array(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.Color)
  return target;
}

size_t Color::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.Color)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .proto.ColorString color_string = 1;
  if (this->_internal_has_color_string()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.color_string_);
  }

  // .proto.ColorArray color_array = 2;
  if (this->_internal_has_color_array()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.color_array_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Color::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Color::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Color::GetClassData() const { return &_class_data_; }


void Color::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Color*>(&to_msg);
  auto& from = static_cast<const Color&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:proto.Color)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_color_string()) {
    _this->_internal_mutable_color_string()->::proto::ColorString::MergeFrom(
        from._internal_color_string());
  }
  if (from._internal_has_color_array()) {
    _this->_internal_mutable_color_array()->::proto::ColorArray::MergeFrom(
        from._internal_color_array());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Color::CopyFrom(const Color& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.Color)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Color::IsInitialized() const {
  return true;
}

void Color::InternalSwap(Color* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Color, _impl_.color_array_)
      + sizeof(Color::_impl_.color_array_)
      - PROTOBUF_FIELD_OFFSET(Color, _impl_.color_string_)>(
          reinterpret_cast<char*>(&_impl_.color_string_),
          reinterpret_cast<char*>(&other->_impl_.color_string_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Color::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_svg_2eproto_getter, &descriptor_table_svg_2eproto_once,
      file_level_metadata_svg_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::proto::ColorString*
Arena::CreateMaybeMessage< ::proto::ColorString >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::ColorString >(arena);
}
template<> PROTOBUF_NOINLINE ::proto::ColorArray*
Arena::CreateMaybeMessage< ::proto::ColorArray >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::ColorArray >(arena);
}
template<> PROTOBUF_NOINLINE ::proto::Color*
Arena::CreateMaybeMessage< ::proto::Color >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::Color >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
