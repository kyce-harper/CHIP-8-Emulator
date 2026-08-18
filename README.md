# CHIP-8 Emulator: Learning Project

[![CI](https://github.com/kyce-harper/CHIP-8-Emulator/actions/workflows/ci.yml/badge.svg)](https://github.com/kyce-harper/CHIP-8-Emulator/actions/workflows/ci.yml)

Built a CHIP-8 emulator in C++ by following along with the
[codeslinger CHIP-8 tutorial](http://www.codeslinger.co.uk/pages/projects/chip8.html).

## Committing & Branching Rules

**Branches**
- Never commit directly to `main` always go through a PR (Even though its literally me lol :) )
- Delete the branch after it's merged

**Commits**
- Build locally (`cmake --build build`) and confirm the lesson's checkpoint passes before committing

**Pull Requests**
- Open the PR once the lesson's checkpoint is verified working locally
- Wait for the CI check to pass before merging

**CI**
- `main` must always build cleanly. A red badge means stop and fix it before starting the next lesson.