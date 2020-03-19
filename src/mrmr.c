/**
 * mrmr.cc - murmur3 hash for node.js
 * Copyright (c) 2016-2020, Christopher Jeffrey (MIT License)
 * https://github.com/bcoin-org/mrmr
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <node_api.h>
#include "murmur3.h"

#define CHECK(expr) do {                               \
  if (!(expr)) {                                       \
    fprintf(stderr, "%s:%d: Assertion `%s' failed.\n", \
            __FILE__, __LINE__, #expr);                \
    fflush(stderr);                                    \
    abort();                                           \
  }                                                    \
} while (0)

/*
 * Murmur3
 */

static napi_value
mrmr_murmur3_sum(napi_env env, napi_callback_info info) {
  napi_value argv[2];
  size_t argc = 2;
  uint32_t out;
  const uint8_t *msg;
  size_t msg_len;
  uint32_t seed;
  napi_value result;

  CHECK(napi_get_cb_info(env, info, &argc, argv, NULL, NULL) == napi_ok);
  CHECK(argc == 2);
  CHECK(napi_get_buffer_info(env, argv[0], (void **)&msg, &msg_len) == napi_ok);
  CHECK(napi_get_value_uint32(env, argv[1], &seed) == napi_ok);

  out = murmur3_sum(msg, msg_len, seed);

  CHECK(napi_create_uint32(env, out, &result) == napi_ok);

  return result;
}

static napi_value
mrmr_murmur3_tweak(napi_env env, napi_callback_info info) {
  napi_value argv[3];
  size_t argc = 3;
  uint32_t out;
  const uint8_t *msg;
  size_t msg_len;
  uint32_t n, tweak;
  napi_value result;

  CHECK(napi_get_cb_info(env, info, &argc, argv, NULL, NULL) == napi_ok);
  CHECK(argc == 3);
  CHECK(napi_get_buffer_info(env, argv[0], (void **)&msg, &msg_len) == napi_ok);
  CHECK(napi_get_value_uint32(env, argv[1], &n) == napi_ok);
  CHECK(napi_get_value_uint32(env, argv[2], &tweak) == napi_ok);

  out = murmur3_tweak(msg, msg_len, n, tweak);

  CHECK(napi_create_uint32(env, out, &result) == napi_ok);

  return result;
}

/*
 * Module
 */

napi_value
mrmr_init(napi_env env, napi_value exports) {
  size_t i;

  static struct {
    const char *name;
    napi_callback callback;
  } funcs[] = {
    /* Murmur3 */
    { "murmur3_sum", mrmr_murmur3_sum },
    { "murmur3_tweak", mrmr_murmur3_tweak },
  };

  for (i = 0; i < sizeof(funcs) / sizeof(funcs[0]); i++) {
    const char *name = funcs[i].name;
    napi_callback callback = funcs[i].callback;
    napi_value fn;

    CHECK(napi_create_function(env,
                               name,
                               NAPI_AUTO_LENGTH,
                               callback,
                               NULL,
                               &fn) == napi_ok);

    CHECK(napi_set_named_property(env, exports, name, fn) == napi_ok);
  }

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, mrmr_init)
