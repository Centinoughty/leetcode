// Is object empty
// EASY

var isEmpty = function(obj) {
    if (typeof obj == "object" && obj !== null) {
        return Object.keys(obj).length === 0;
    }

    return obj.length === 0;
};