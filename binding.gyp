{
  "targets": [{
    "target_name": "mrmr",
    "sources": [
      "./src/murmur3.c",
      "./src/mrmr.c"
    ],
    "cflags": [
      "-Wall",
      "-Wextra",
      "-Wno-implicit-fallthrough",
      "-O3"
    ],
    "cflags_c": [
      "-std=c99"
    ],
    "conditions": [
      ["node_byteorder=='big'", {
        "defines": [
          "WORDS_BIGENDIAN"
        ]
      }]
    ]
  }]
}
