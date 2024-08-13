// Add two promises
// EASY

type P = Promise<number>

async function addTwoPromises(promise1: P, promise2: P): P {
    const result = await Promise.all([promise1, promise2]);
    return result[0] + result[1];
};
