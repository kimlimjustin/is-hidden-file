<div align="center">

# is-hidden-file
[![npm version](https://img.shields.io/badge/dynamic/json?color=317EFB&logo=npm&style=for-the-badge&label=Version&query=version&url=https%3A%2F%2Funpkg.com%2Fis-hidden-file%40latest%2Fpackage.json)](https://www.npmjs.com/package/is-hidden-file)
</div>

> Check if a file/folder is hidden on all platforms.

- Unix: Check file name starts with `.`.
- Windows: Check if file hidden using native code.

## Installation
- npm: `npm i is-hidden-file`
- yarn: `yarn add is-hidden-file`

## Usage
#### Node js
```js
const { isHiddenFile } = require("is-hidden-file");

console.log(isHiddenFile(".git")) // true
console.log(isHiddenFile("README.md")) // false
```

#### Node js with typescript
```ts
import { isHiddenFile } from "is-hidden-file";

console.log(isHiddenFile(".git")) // true
console.log(isHiddenFile("README.md")) // false
```

## License
MIT