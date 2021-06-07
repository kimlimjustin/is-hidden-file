"use strict";
Object.defineProperty(exports, "__esModule", { value: true });

const isHiddenFile = (path) => {
    switch (process.platform) {
        case "win32":
            const { isHiddenFile: checkHiddenFileWin } = require("./binding");
            return checkHiddenFileWin(path)
        default:
            return /(^|\/)\.[^\/\.]/g.test(path)
    }
}

exports.isHiddenFile = isHiddenFile