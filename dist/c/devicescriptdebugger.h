// Autogenerated C header file for DeviceScript Debugger
#ifndef _JACDAC_SPEC_DEVS_DBG_H
#define _JACDAC_SPEC_DEVS_DBG_H 1

#define JD_SERVICE_CLASS_DEVS_DBG  0x155b5b40

// enum ValueTag (uint8_t)
#define JD_DEVS_DBG_VALUE_TAG_NUMBER 0x1
#define JD_DEVS_DBG_VALUE_TAG_SPECIAL 0x2
#define JD_DEVS_DBG_VALUE_TAG_FIBER 0x3
#define JD_DEVS_DBG_VALUE_TAG_BUILTIN_OBJECT 0x5
#define JD_DEVS_DBG_VALUE_TAG_EXOTIC 0x6
#define JD_DEVS_DBG_VALUE_TAG_UNHANDLED 0x7
#define JD_DEVS_DBG_VALUE_TAG_IMG_BUFFER 0x20
#define JD_DEVS_DBG_VALUE_TAG_IMG_STRING_BUILTIN 0x21
#define JD_DEVS_DBG_VALUE_TAG_IMG_STRING_ASCII 0x22
#define JD_DEVS_DBG_VALUE_TAG_IMG_STRING_UTF8 0x23
#define JD_DEVS_DBG_VALUE_TAG_IMG_ROLE 0x30
#define JD_DEVS_DBG_VALUE_TAG_IMG_FUNCTION 0x31
#define JD_DEVS_DBG_VALUE_TAG_IMG_ROLE_MEMBER 0x32
#define JD_DEVS_DBG_VALUE_TAG_OBJ_ARRAY 0x51
#define JD_DEVS_DBG_VALUE_TAG_OBJ_MAP 0x52
#define JD_DEVS_DBG_VALUE_TAG_OBJ_BUFFER 0x53
#define JD_DEVS_DBG_VALUE_TAG_OBJ_STRING 0x54
#define JD_DEVS_DBG_VALUE_TAG_OBJ_STACK_FRAME 0x55
#define JD_DEVS_DBG_VALUE_TAG_OBJ_PACKET 0x56
#define JD_DEVS_DBG_VALUE_TAG_OBJ_BOUND_FUNCTION 0x57
#define JD_DEVS_DBG_VALUE_TAG_OBJ_OPAQUE 0x58
#define JD_DEVS_DBG_VALUE_TAG_OBJ_ANY 0x50
#define JD_DEVS_DBG_VALUE_TAG_OBJ_MASK 0xf0
#define JD_DEVS_DBG_VALUE_TAG_USER1 0xf1
#define JD_DEVS_DBG_VALUE_TAG_USER2 0xf2
#define JD_DEVS_DBG_VALUE_TAG_USER3 0xf3
#define JD_DEVS_DBG_VALUE_TAG_USER4 0xf4

// enum ValueSpecial (uint8_t)
#define JD_DEVS_DBG_VALUE_SPECIAL_NULL 0x0
#define JD_DEVS_DBG_VALUE_SPECIAL_TRUE 0x1
#define JD_DEVS_DBG_VALUE_SPECIAL_FALSE 0x2
#define JD_DEVS_DBG_VALUE_SPECIAL_GLOBALS 0x64
#define JD_DEVS_DBG_VALUE_SPECIAL_CURRENT_EXCEPTION 0x65

// enum FunIdx (uint16_t)
#define JD_DEVS_DBG_FUN_IDX_NONE 0x0
#define JD_DEVS_DBG_FUN_IDX_MAIN 0xc34f
#define JD_DEVS_DBG_FUN_IDX_FIRST_BUILT_IN 0xc350

// enum FiberHandle (uint32_t)
#define JD_DEVS_DBG_FIBER_HANDLE_NONE 0x0

// enum ProgramCounter (uint32_t)

// enum ObjStackFrame (uint32_t)
#define JD_DEVS_DBG_OBJ_STACK_FRAME_NULL 0x0

// enum String (uint32_t)
#define JD_DEVS_DBG_STRING_STATIC_INDICATOR_MASK 0x80000001
#define JD_DEVS_DBG_STRING_STATIC_TAG_MASK 0x7f000000
#define JD_DEVS_DBG_STRING_STATIC_INDEX_MASK 0xfffffe
#define JD_DEVS_DBG_STRING_UNHANDLED 0x0

// enum StepFlags (uint16_t)
#define JD_DEVS_DBG_STEP_FLAGS_STEP_OUT 0x1
#define JD_DEVS_DBG_STEP_FLAGS_STEP_IN 0x2
#define JD_DEVS_DBG_STEP_FLAGS_THROW 0x4

// enum SuspensionType (uint8_t)
#define JD_DEVS_DBG_SUSPENSION_TYPE_NONE 0x0
#define JD_DEVS_DBG_SUSPENSION_TYPE_BREAKPOINT 0x1
#define JD_DEVS_DBG_SUSPENSION_TYPE_UNHANDLED_EXCEPTION 0x2
#define JD_DEVS_DBG_SUSPENSION_TYPE_HANDLED_EXCEPTION 0x3
#define JD_DEVS_DBG_SUSPENSION_TYPE_HALT 0x4
#define JD_DEVS_DBG_SUSPENSION_TYPE_PANIC 0x5
#define JD_DEVS_DBG_SUSPENSION_TYPE_RESTART 0x6
#define JD_DEVS_DBG_SUSPENSION_TYPE_DEBUGGER_STMT 0x7
#define JD_DEVS_DBG_SUSPENSION_TYPE_STEP 0x8

/**
 * Argument: results pipe (bytes). List the currently running fibers (threads).
 */
#define JD_DEVS_DBG_CMD_READ_FIBERS 0x80

/**
 * List the currently running fibers (threads).
 */
typedef struct jd_devs_dbg_fiber {
    uint32_t handle;  // FiberHandle
    uint16_t initial_fn;  // FunIdx
    uint16_t curr_fn;  // FunIdx
} jd_devs_dbg_fiber_t;


/**
 * List stack frames in a fiber.
 */
#define JD_DEVS_DBG_CMD_READ_STACK 0x81
typedef struct jd_devs_dbg_read_stack {
    uint8_t results[12];  // pipe
    uint32_t fiber_handle;  // FiberHandle
} jd_devs_dbg_read_stack_t;


/**
 * List stack frames in a fiber.
 */
typedef struct jd_devs_dbg_stackframe {
    uint32_t self;  // ObjStackFrame
    uint32_t pc;  // ProgramCounter
    uint32_t closure;  // ObjStackFrame
    uint16_t fn_idx;  // FunIdx
    uint16_t reserved;
} jd_devs_dbg_stackframe_t;


/**
 * Read variable slots in a stack frame, elements of an array, etc.
 */
#define JD_DEVS_DBG_CMD_READ_INDEXED_VALUES 0x82
typedef struct jd_devs_dbg_read_indexed_values {
    uint8_t results[12];  // pipe
    uint32_t v0;
    uint8_t tag;  // ValueTag
    uint8_t reserved;
    uint16_t start;
    uint16_t length;
} jd_devs_dbg_read_indexed_values_t;


/**
 * Read variable slots in a stack frame, elements of an array, etc.
 */
typedef struct jd_devs_dbg_value {
    uint32_t v0;
    uint32_t v1;
    uint16_t fn_idx;  // FunIdx
    uint8_t tag;  // ValueTag
} jd_devs_dbg_value_t;


/**
 * Read variable slots in an object.
 */
#define JD_DEVS_DBG_CMD_READ_NAMED_VALUES 0x83
typedef struct jd_devs_dbg_read_named_values {
    uint8_t results[12];  // pipe
    uint32_t v0;
    uint8_t tag;  // ValueTag
} jd_devs_dbg_read_named_values_t;


/**
 * Read variable slots in an object.
 */
typedef struct jd_devs_dbg_key_value {
    uint32_t key;  // String
    uint32_t v0;
    uint32_t v1;
    uint16_t fn_idx;  // FunIdx
    uint8_t tag;  // ValueTag
} jd_devs_dbg_key_value_t;


/**
 * Read a specific value.
 */
#define JD_DEVS_DBG_CMD_READ_VALUE 0x84
typedef struct jd_devs_dbg_read_value {
    uint32_t v0;
    uint8_t tag;  // ValueTag
} jd_devs_dbg_read_value_t;


/**
 * Report: 
 */
typedef struct jd_devs_dbg_read_value_report {
    uint32_t v0;
    uint32_t v1;
    uint16_t fn_idx;  // FunIdx
    uint8_t tag;  // ValueTag
} jd_devs_dbg_read_value_report_t;


/**
 * Read bytes of a string (UTF8) or buffer value.
 */
#define JD_DEVS_DBG_CMD_READ_BYTES 0x85
typedef struct jd_devs_dbg_read_bytes {
    uint8_t results[12];  // pipe
    uint32_t v0;
    uint8_t tag;  // ValueTag
    uint8_t reserved;
    uint16_t start;
    uint16_t length;
} jd_devs_dbg_read_bytes_t;


/**
 * Argument: data bytes. Read bytes of a string (UTF8) or buffer value.
 */

/**
 * Set breakpoint(s) at a location(s).
 */
#define JD_DEVS_DBG_CMD_SET_BREAKPOINTS 0x90
typedef struct jd_devs_dbg_set_breakpoints {
    uint32_t break_pc[0];  // ProgramCounter
} jd_devs_dbg_set_breakpoints_t;


/**
 * Clear breakpoint(s) at a location(s).
 */
#define JD_DEVS_DBG_CMD_CLEAR_BREAKPOINTS 0x91
typedef struct jd_devs_dbg_clear_breakpoints {
    uint32_t break_pc[0];  // ProgramCounter
} jd_devs_dbg_clear_breakpoints_t;


/**
 * No args. Clear all breakpoints.
 */
#define JD_DEVS_DBG_CMD_CLEAR_ALL_BREAKPOINTS 0x92

/**
 * No args. Resume program execution after a breakpoint was hit.
 */
#define JD_DEVS_DBG_CMD_RESUME 0x93

/**
 * No args. Try suspending current program. Client needs to wait for `suspended` event afterwards.
 */
#define JD_DEVS_DBG_CMD_HALT 0x94

/**
 * No args. Run the program from the beginning and halt on first instruction.
 */
#define JD_DEVS_DBG_CMD_RESTART_AND_HALT 0x95

/**
 * Set breakpoints that only trigger in the specified stackframe and resume program.
 * The breakpoints are cleared automatically on next suspension (regardless of the reason).
 */
#define JD_DEVS_DBG_CMD_STEP 0x96
typedef struct jd_devs_dbg_step {
    uint32_t stackframe;  // ObjStackFrame
    uint16_t flags;  // StepFlags
    uint16_t reserved;
    uint32_t break_pc[0];  // ProgramCounter
} jd_devs_dbg_step_t;


/**
 * Read-write bool (uint8_t). Turn on/off the debugger interface.
 */
#define JD_DEVS_DBG_REG_ENABLED JD_REG_INTENSITY

/**
 * Read-write bool (uint8_t). Wheather to place breakpoint at unhandled exception.
 */
#define JD_DEVS_DBG_REG_BREAK_AT_UNHANDLED_EXN 0x80

/**
 * Read-write bool (uint8_t). Wheather to place breakpoint at handled exception.
 */
#define JD_DEVS_DBG_REG_BREAK_AT_HANDLED_EXN 0x81

/**
 * Read-only bool (uint8_t). Indicates if the program is currently suspended.
 * Most commands can only be executed when the program is suspended.
 */
#define JD_DEVS_DBG_REG_IS_SUSPENDED 0x180

/**
 * Emitted when the program hits a breakpoint or similar event in the specified fiber.
 */
#define JD_DEVS_DBG_EV_SUSPENDED 0x80
typedef struct jd_devs_dbg_suspended {
    uint32_t fiber;  // FiberHandle
    uint8_t type;  // SuspensionType
} jd_devs_dbg_suspended_t;


#endif