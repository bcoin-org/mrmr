/*!
 * murmur3.js - murmur3 hash for node.js
 * Copyright (c) 2014-2015, Fedor Indutny (MIT License)
 * Copyright (c) 2014-2017, Christopher Jeffrey (MIT License).
 * https://github.com/bcoin-org/bcoin
 */

'use strict';

if (process.env.NODE_BACKEND === 'js')
  module.exports = require('./murmur3-browser');
else
  module.exports = require('./binding');
