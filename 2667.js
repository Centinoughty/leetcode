// Create hello world function
// EASY

/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
  return function(...args) {
      return "Hello World";
  }
};

/**
* const f = createHelloWorld();
* f(); // "Hello World"
*/