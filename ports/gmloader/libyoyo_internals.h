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
#define vk_nokey       (0)
#define vk_anykey      (1)
#define vk_enter       (13)
#define vk_return      (13)
#define vk_shift       (16)
#define vk_control     (17)
#define vk_alt         (18)
#define vk_escape      (27)
#define vk_space       (32)
#define vk_backspace   (8)
#define vk_tab         (9)
#define vk_pause       (19)
#define vk_printscreen (44)
#define vk_left        (37)
#define vk_right       (39)
#define vk_up          (38)
#define vk_down        (40)
#define vk_home        (36)
#define vk_end         (35)
#define vk_delete      (46)
#define vk_insert      (45)
#define vk_pageup      (33)
#define vk_pagedown    (34)
#define vk_f1          (112)
#define vk_f2          (113)
#define vk_f3          (114)
#define vk_f4          (115)
#define vk_f5          (116)
#define vk_f6          (117)
#define vk_f7          (118)
#define vk_f8          (119)
#define vk_f9          (120)
#define vk_f10         (121)
#define vk_f11         (122)
#define vk_f12         (123)
#define vk_numpad0     (96)
#define vk_numpad1     (97)
#define vk_numpad2     (98)
#define vk_numpad3     (99)
#define vk_numpad4     (100)
#define vk_numpad5     (101)
#define vk_numpad6     (102)
#define vk_numpad7     (103)
#define vk_numpad8     (104)
#define vk_numpad9     (105)
#define vk_divide      (111)
#define vk_multiply    (106)
#define vk_subtract    (109)
#define vk_add         (107)
#define vk_decimal     (110)
#define vk_lshift      (160)
#define vk_lcontrol    (162)
#define vk_lalt        (164)
#define vk_rshift      (161)
#define vk_rcontrol    (163)
#define vk_ralt        (165)

extern Gamepad yoyo_gamepads[MAX_GAMEPADS];
 
// Symbols from libyoyo.so
typedef ABI_ATTR void (*routine_t)(RValue *ret, void *self, void *other, int argc, RValue *args);
typedef ABI_ATTR void (*fct_add_t)(const char *name, routine_t func, int argc, char ret);
typedef ABI_ATTR int  (*create_ds_map_t)(int, ...);
typedef ABI_ATTR void (*create_async_event_with_ds_map_t)(int, int);

extern uintptr_t *New_Room;
extern fct_add_t Function_Add;
extern create_ds_map_t CreateDsMap;
extern create_async_event_with_ds_map_t CreateAsynEventWithDSMap;

extern uintptr_t *New_Room;
extern fct_add_t Function_Add;
extern create_ds_map_t CreateDsMap;
extern create_async_event_with_ds_map_t CreateAsynEventWithDSMap;
#define N_BUTTONS 30
extern uint8_t *_IO_ButtonDown;
extern uint8_t *_IO_ButtonPressed;
extern uint8_t *_IO_ButtonReleased;
extern int32_t *g_MousePosX;
extern int32_t *g_MousePosY;

#define N_KEYS 256
extern uint8_t prev_kbd_state[N_KEYS];
extern uint8_t cur_keys[N_KEYS];
extern uint8_t *_IO_KeyDown;
extern uint8_t *_IO_LastKey;
extern uint8_t *_IO_CurrentKey;
extern uint8_t *_IO_KeyPressed;
extern uint8_t *_IO_KeyReleased;
ABI_ATTR extern int32_t (*YYGetInt32)(RValue *val, int idx);
ABI_ATTR extern int32_t (*Graphics_DisplayWidth)();
ABI_ATTR extern int32_t (*Graphics_DisplayHeight)();

extern void register_gamepad_functs(fct_add_t);

#endif /* __RUNNER_INTERNALS_H__ */