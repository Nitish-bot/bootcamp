// Problem Description – once(fn)
//
// You are required to implement a wrapper function named once that accepts a
// callback-based asynchronous function `fn`.
// The wrapper should ensure that `fn` is executed only on the first call.
// Any subsequent calls should not re-execute `fn` and should instead invoke
// the callback with the same result (or error) from the first invocation.

function once(fn) {
  let called = false;
  let cachedError = null;
  let cachedResult = null;

  return function(...args) {
    const callback = args[args.length - 1];
    const fnArgs = args.slice(0, -1);

    if (called) {
      if (cachedError) {
        callback(cachedError);
      } else {
        callback(null, cachedResult);
      }
      return;
    }

    fn(...fnArgs, (err, result) => {
      if (err) {
        cachedError = err;
      } else {
        cachedResult = result;
      }

      callback(err, result);
    });
    called = true;
  };
}

module.exports = once;