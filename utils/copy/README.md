# `copy.exe`

This is a command line tool that interacts with the Windows API to copy files and text to the clipboard.

> I created this because sometimes I'd want to share source code I'd made, but I'd have to open Windows Explorer to grab the files instead of being able to do it all from my terminal, so I created this.

## Copying Text

You can copy text by using the `-s` flag. This will group together all the arguments after it and copy that to the clipboard.

```ps1
$ copy -s "Hello world"
$ copy -s Hello world
```

Both of the above inputs are valid.

## Copying Files

To copy a file, simply list the target filepath as the first argument. Relative paths are permitted, and this will interact with the Windows API to place the target file onto the clipboard, if possible.

```ps1
$ copy ..\example.txt
$ copy test.py
```

Both of the above inputs are valid.

## Features to Add

- Improve the representation of errors with some ANSI colour codes.