# is-hidden-file
> Check if a file/folder is hidden on all platforms.

Unix: Check file name starts with `.`.
Windows: Check if file hidden using native code.

## Usage
```
const { isHiddenFile } = require("is-hidden-file");

console.log(isHiddenFile(".git")) // true
console.log(isHiddenFile("README.md")) // false
```

## License
MIT