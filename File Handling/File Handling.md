## Opening a File

Opening a file in cpp means associating that file with stream objects through which we can perform operations on the file.

``` 
fstream file(filePath, mode);
```

### Choosing stream class:
- ifstream: for read only operations (i for input)
- ofstream: for write-only operations (o for output)
- fstream: any operation

### Initialization of stream object
- Using constructor: object(fileName, mode). Doesn't allow the stream object to be reusable + May throw exceptions.
- Creating a file: open()
- Reading data: read()
- Writing new data: write()
- Closing a file: close()
- Checking if a file exists: check()
```c++
std::ifstream check(filename);
    if (check.good()) {
        std::cerr << "File already exists. Not overwriting." << std::endl;
        return 1;
    }
    check.close();
```
### Mode:
Set of operations we are allowed to perform on a file.
- ios::in: Open the file for reading. This is the default mode if no mode is specified.
- ios::out: Open the file for writing. If the file does not exist, it will be created. If the file already exists, its contents will be overwritten.
- ios::app: Open the file for appending. If the file does not exist, it will be created. If the file already exists, new data will be appended to the end of the file.
- ios::ate: Open the file for reading and move the read pointer to the end of the file.
- ios::binary: Open the file in binary mode. This mode is used when working with binary files, such as images or executables.
- ios::trunc: Open the file for writing and truncate it to zero length. If the file already exists, its contents will be lost.
- ios::noreplace: Creates a new file but fails if a file with given name already exists. Usually used in combination with ios::out.
We can combine different modes using or symbol | .
Eg: ios::in | ios::out , which is the default mode for fstream object.

### Notes:
Wherever we decide to write in a file (say at a pointer p), we erase all the existing content of the file from pointer p till the end, and then perform our write operation. (for append, we write from the eof, from which the file is already empty.)
