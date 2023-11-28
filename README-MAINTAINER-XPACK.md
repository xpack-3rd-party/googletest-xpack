[![license](https://img.shields.io/github/license/xpack-3rd-party/googletest-xpack)](https://github.com/xpack-3rd-party/googletest-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/xpack-3rd-party/googletest-xpack/actions/workflows/ci.yml/badge.svg)](https://github.com/xpack-3rd-party/googletest-xpack/actions/workflows/ci.yml)
[![GitHub issues](https://img.shields.io/github/issues/xpack-3rd-party/googletest-xpack.svg)](https://github.com/xpack-3rd-party/googletest-xpack/issues/)
[![GitHub pulls](https://img.shields.io/github/issues-pr/xpack-3rd-party/googletest-xpack.svg)](https://github.com/xpack-3rd-party/googletest-xpack/pulls)

# Maintainer info

## Project repository

The project is hosted on GitHub:

- <https://github.com/xpack-3rd-party/googletest-xpack.git>

To clone the stable branch (`xpack`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/xpack-3rd-party/googletest-xpack.git && \
mkdir -p ~/Work/xpack-3rd-party && \
git clone \
  https://github.com/xpack-3rd-party/googletest-xpack.git \
  ~/Work/xpack-3rd-party/googletest-xpack.git
```

For development purposes, clone the development branch (`xpack-develop`):

```sh
rm -rf ~/Work/xpack-3rd-party/googletest-xpack.git && \
mkdir -p ~/Work/xpack-3rd-party && \
git clone \
  --branch xpack-develop \
  https://github.com/xpack-3rd-party/googletest-xpack.git \
  ~/Work/xpack-3rd-party/googletest-xpack.git
```

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

To run the native tests, a C++ development environment is required.
On macOS install Command Line Tools, on Ubuntu `build-essential`.

## Code formatting

Code formatting is done using `clang-format --style=file`, either manually
from a script, or automatically from Visual Studio Code, or the Eclipse
CppStyle plug-in.

Always reformat the source files that were changed.

## How to make new releases

### Release schedule

There are no fixed releases.

### Check Git

In the `micro-os-plus/googletest-xpack` Git repo:

- switch to the `xpack-develop` branch
- if needed, merge the `xpack` branch

No need to add a tag here, it'll be added when the release is created.

### Increase the version

Determine the upstream version (like `4.0.0`) and eventually update the
`package.json` file; the format is `4.0.0-pre`.

### Fix possible open issues

Check GitHub issues and pull requests:

- <https://github.com/micro-os-plus/googletest-xpack/issues/>

and fix them; assign them to a milestone (like `4.0.0`).

### Update `README-MAINTAINER.md`

Update the `README-MAINTAINER.md` file to reflect the changes
related to the new version.

### Update `CHANGELOG.md`

- open the `CHANGELOG.md` file
- check if all previous fixed issues are in
- add a new entry like _* v4.0.0_
- commit with a message like _prepare v4.0.0_

### Push changes

- reformat the source files that were changed
- commit and push

### Manual tests

To run the tests manually on the local machine:

```sh
xpm run install-all -C ~/Work/xpack-3rd-party/googletest-xpack.git
xpm run test-all -C ~/Work/xpack-3rd-party/googletest-xpack.git
```

## Publish on the npmjs.com server

- select the `xpack-develop` branch
- commit all changes
- update versions in `README-MAINTAINER-XPACK.md`
- update `CHANGELOG-XPACK.md`
- commit with a message like _prepare v1.11.0-1_
- `npm pack` and check the content of the archive, which should list
  only `package.json`, `README.md`, `LICENSE`, `CHANGELOG-XPACK.md`,
  the sources and CMake/meson files;
  possibly adjust `.npmignore`
- `npm version v1.11.0-1`
- push the `xpack-develop` branch to GitHub
- the `postversion` npm script should also update tags via `git push origin --tags`
- wait for the CI job to complete
  (<https://github.com/xpack-3rd-party/googletest-xpack/actions/workflows/ci.yml>)

### Publish

- `npm publish --tag next` (use `npm publish --access public` when
  publishing for the first time)

The version is visible at:

- <https://www.npmjs.com/package/@xpack-3rd-party/googletest?activeTab=versions>

## Update the repo

When the package is considered stable:

- with a Git client (VS Code is fine)
- merge `xpack-develop` into `xpack`
- push to GitHub
- select `xpack-develop`

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @xpack-3rd-party/googletest`
- `npm dist-tag add @xpack-3rd-party/googletest@1.11.0-1 latest`
- `npm dist-tag ls @xpack-3rd-party/googletest`