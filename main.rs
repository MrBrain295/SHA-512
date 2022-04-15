#![allow(dead_code, mutable_transmutes, non_camel_case_types, non_snake_case,
         non_upper_case_globals, unused_assignments, unused_mut)]
#![register_tool(c2rust)]
#![feature(main, register_tool)]
extern "C" {
    #[no_mangle]
    fn printf(_: *const libc::c_char, _: ...) -> libc::c_int;
    #[no_mangle]
    fn crypt(key: *const libc::c_char, salt: *const libc::c_char)
     -> *mut libc::c_char;
}
unsafe fn main_0() -> libc::c_int {
    printf(b"%s\n\x00" as *const u8 as *const libc::c_char,
           crypt(b"This is my password!\x00" as *const u8 as
                     *const libc::c_char,
                 b"$6$8n./Hzqd\x00" as *const u8 as *const libc::c_char));
    return 0 as libc::c_int;
}
#[main]
pub fn main() { unsafe { ::std::process::exit(main_0() as i32) } }
