#ifndef __RUNNER_INTERNALS_H__
#define __RUNNER_INTERNALS_H__

#define MASK_KIND_RVALUE 0x0ffffff
typedef enum RValueType {
	VALUE_REAL = 0,
	VALUE_STRING = 1,
	VALUE_ARRAY = 2,
	VALUE_PTR = 3,
	VALUE_VEC3 = 4,
	VALUE_UNDEFINED = 5,
	VALUE_OBJECT = 6,
	VALUE_INT32 = 7,
	VALUE_VEC4 = 8,
	VALUE_MATRIX = 9,
	VALUE_INT64 = 10,
	VALUE_ACCESSOR = 11,
	VALUE_JSNULL = 12,
	VALUE_BOOL = 13,
	VALUE_ITERATOR = 14,
	VALUE_REF = 15,
	VALUE_UNSET = MASK_KIND_RVALUE
} RValueType;

typedef struct Ref {
	void* m_thing;
	int m_refCount;
	int m_size;
} Ref;

typedef struct RValue {
	/* ... */
	union {
		int v32;
		long long v64;
		double val;
		/* pointers */

        Ref *str;
	} rvalue;

	int flags;
	RValueType kind;
} RValue;

typedef struct VariableDecl {
	char *name;
	RValue *rval;
	void *unk1;
	void *unk2;
} VariableDecl;

typedef enum GamepadButtonState {
	GAMEPAD_BUTTON_STATE_UP = -1,
	GAMEPAD_BUTTON_STATE_NEUTRAL = 0,
	GAMEPAD_BUTTON_STATE_HELD = 1,
	GAMEPAD_BUTTON_STATE_DOWN = 2
} GamepadButtonState;

#define MAX_GAMEPADS 4
typedef struct Gamepad {
	int is_available; 
	double buttons[16];
	double deadzone;
	double axis[4];
} Gamepad;

#define os_windows    ((double)(0.0f))
#define os_android    ((double)(4.0f))
#define os_linux      ((double)(6.0f))
#define os_psvita     ((double)(12.0f))
#define gp_face1      ((double)(32769.0f))
#define gp_face2      ((double)(32770.0f))
#define gp_face3      ((double)(32771.0f))
#define gp_face4      ((double)(32772.0f))
#define gp_shoulderl  ((double)(32773.0f))
#define gp_shoulderr  ((double)(32774.0f))
#define gp_shoulderlb ((double)(32775.0f))
#define gp_shoulderrb ((double)(32776.0f))
#define gp_select     ((double)(32777.0f))
#define gp_start      ((double)(32778.0f))
#define gp_stickl     ((double)(32779.0f))
#define gp_stickr     ((double)(32780.0f))
#define gp_padu       ((double)(32781.0f))
#define gp_padd       ((double)(32782.0f))
#define gp_padl       ((double)(32783.0f))
#define gp_padr       ((double)(32784.0f))
#define gp_axislh     ((double)(32785.0f))
#define gp_axislv     ((double)(32786.0f))
#define gp_axisrh     ((double)(32787.0f))
#define gp_axisrv     ((double)(32788.0f))

extern Gamepad yoyo_gamepads[MAX_GAMEPADS];
 
typedef ABI_ATTR void (*routine_t)(RValue *ret, void *self, void *other, int argc, RValue *args);
typedef ABI_ATTR void (*fct_add_t)(const char *name, routine_t func, int argc, char ret);
typedef ABI_ATTR int  (*create_ds_map_t)(int, ...);
typedef ABI_ATTR void (*create_async_event_with_ds_map_t)(int, int);

extern uintptr_t *New_Room;
extern fct_add_t Function_Add;
extern create_ds_map_t CreateDsMap;
extern create_async_event_with_ds_map_t CreateAsynEventWithDSMap;

extern void register_gamepad_functs(fct_add_t);

#endif /* __RUNNER_INTERNALS_H__ */