"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const { isHiddenFile: checkHiddenFileWin } = require("./binding");

const isHiddenFile = (path) => {
    switch (process.platform) {
        case "win32":
            return checkHiddenFileWin(path)
        default:
            return /(^|\/)\.[^\/\.]/g.test(path)
    }
}

exports.isHiddenFile = isHiddenFile