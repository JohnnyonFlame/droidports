# GDB Helper. Forces symbols from the loaded JNI library into gdb
set pagination off

define set_apk
    run $arg0
end

# Load the loader binary
file gmloader

# Add existing .so file symbols by setting a breakpoint into so_relocate
break __gdb_breakpoint_add_symbol_file
commands
    eval "add-symbol-file %s -o %p", fname, mod->text_base
end

# All done
set pagination on