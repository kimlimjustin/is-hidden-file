const { isHiddenFile } = require("./index");
const path = require("path");

test("Is .git folder hidden?", () => {
    expect(isHiddenFile(path.join(__dirname, "../.git"))).toBe(true)
})

test("Is src folder hidden?", () => {
    expect(isHiddenFile(path.join(__dirname))).toBe(false)
})