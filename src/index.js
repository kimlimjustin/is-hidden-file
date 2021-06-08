"use strict";
Object.defineProperty(exports, "__esModule", { value: true });

/**
 * Check whether a file/folder is hidden on system
 * @author Justin Maximillian Kimlim <kimlimjustin@gmail.com>
 * @license MIT
 * @param {string} path - file/folder absolute path
 * @returns {boolean} Result
*/

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