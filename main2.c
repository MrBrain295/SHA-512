#![allow(dead_code, mutable_transmutes, non_camel_case_types, non_snake_case,
         non_upper_case_globals, unused_assignments, unused_mut)]
#![register_tool(c2rust)]
#![feature(main, register_tool)]
extern "C" {
    #[no_mangle]
    fn printf(_: *const libc::c_char, _: ...) -> libc::c_int;
    #[no_mangle]
    fn crypt(__key: *const libc::c_char, __salt: *const libc::c_char)
     -> *mut libc::c_char;
}
//
// $ gcc main2.c -std=c11 -Wall -lcrypt
// $ ./a.out
// $6$ziqjIomt8n./Hzqd$p0Nb/vCETx2HEKdDrlYyPrKx2axug6s6tLx6hqgfsw9ex0mQXNh9bQ2kXnHDmd/j6JdTprCuEqNZrnhDkCidj.
//
// $ ./pencrypter.py --salt ziqjIomt8n./Hzqd --password test
// $6$ziqjIomt8n./Hzqd$p0Nb/vCETx2HEKdDrlYyPrKx2axug6s6tLx6hqgfsw9ex0mQXNh9bQ2kXnHDmd/j6JdTprCuEqNZrnhDkCidj.
//
unsafe fn main_0() -> libc::c_int {
    let mut result: *mut libc::c_char =
        crypt(b"test2\x00" as *const u8 as *const libc::c_char,
              b"$6$ziqjIomt8n./Hzqd$\x00" as *const u8 as
                  *const libc::c_char);
    printf(b"%s\n\x00" as *const u8 as *const libc::c_char, result);
    return 0 as libc::c_int;
}
#[main]
pub fn main() { unsafe { ::std::process::exit(main_0() as i32) } }
