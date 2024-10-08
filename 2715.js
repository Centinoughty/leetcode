// Timeout cancellation
// EASY

/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */

var cancellable = function(fn, args, t) {
  const timer = setTimeout(() => fn(...args), t);
  return () => {
      clearTimeout(timer);
  }
};