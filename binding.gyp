{
  "targets": [{
    "target_name": "mrmr",
    "sources": [
      "./src/murmur3.c",
      "./src/mrmr.c"
    ],
    "conditions": [
      ["OS != 'mac' and OS != 'win'", {
        "cflags": [
          "-std=c99",
          "-Wall",
          "-Wextra",
          "-Wno-implicit-fallthrough"
        ]
      }],
      ["OS == 'mac'", {
        "xcode_settings": {
          "GCC_C_LANGUAGE_STANDARD": "c99",
          "WARNING_CFLAGS": [
            "-Wall",
            "-Wextra",
            "-Wno-implicit-fallthrough"
          ]
        }
      }],
      ["OS == 'win'", {
        "msvs_disabled_warnings=": [
          4146, # negation of unsigned integer
          4244, # implicit integer demotion
          4267, # implicit size_t demotion
          4334  # implicit 32->64 bit shift
        ]
      }],
      ["node_byteorder == 'big'", {
        "defines": [
          "WORDS_BIGENDIAN"
        ]
      }]
    ]
  }]
}
