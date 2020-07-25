/*!
 * mrmr.js - murmur3 hash for node.js
 * Copyright (c) 2017, Christopher Jeffrey (MIT License).
 * https://github.com/bcoin-org/mrmr
 */

'use strict';

const assert = require('bsert');
const binding = require('loady')('mrmr', __dirname);

/*
 * Murmur3
 */

function sum(data, seed) {
  assert(Buffer.isBuffer(data));
  return binding.murmur3_sum(data, seed >>> 0);
}

function tweak(data, n, tweak) {
  assert(Buffer.isBuffer(data));
  return binding.murmur3_tweak(data, n >>> 0, tweak >>> 0);
}

/**
 * Expose
 */

exports.native = 2;
exports.sum = sum;
exports.tweak = tweak;
