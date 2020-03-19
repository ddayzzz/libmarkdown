# Simple Markdown parser
Convert Markdown to HTML. This repo is a library of [Mooction/MyNotPad](https://github.com/mooction/MyNotePad) and I extract the library from it. This project has a few source files and requires only a C++11 compatible compiler.

# Installation
For compile library and a simple demo program:
```bash
cd libmarkdown
mkdir build && cd build
cmake .. && make
```

# Built-in Demo
Usage: `md2html <infile> <outfile>`. You can test it with an example from [sample/test1_lf.md](sample/test1_lf.md) whose proper output might be [sample/test1_lf_preview.html](sample/test1_lf_preview.html)
