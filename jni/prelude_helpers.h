#define STATIC_FIELD(type, id, default, sig) type id = default;
#define DYNAMIC_FIELD
FIELDS
#undef DYNAMIC_FIELD
#undef STATIC_FIELD

#define STATIC_FIELD(...)
#define DYNAMIC_FIELD(type, id, sig) type id;
typedef struct STRUCT_NAME {
    _jclass *clazz;
    FIELDS
} STRUCT_NAME;
#undef DYNAMIC_FIELD
#undef STATIC_FIELD

