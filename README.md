# Hamba

`hamba` is a C-based program that displays customizable ASCII art along with a user-defined message. The ASCII art is dynamically loaded from a text file, allowing users to easily modify the displayed image without altering the program's code.

## Requirements

- GCC or any other C compiler.

## Setup

1. Clone this repo.
 
   ```sh
   git@github.com:uthsobcb/hamba.git
   ```

2. By defalut this cow is given

   ```
        /)  (\
   .-._((,~~.))_.-,
    `=.   99   ,='
      / ,o~~o. \
     { { .__. } }
      ) `~~~\' (
     /`-._   _\.-\
    /         )   \
                       
   ```

3. Compile the program using GCC:

   ```sh
   gcc -o hamba hamba.c
   ```

## Usage

### Display a Message

Run the program with the `-say` option followed by your message:

```sh
./hamba -say "Hello, World"
```

Example Output:

```
       << Hello >>
          ||
          ||
        /)  (\
   .-._((,~~.))_.-,
    `=.   99   ,='
      / ,o~~o. \
     { { .__. } }
      ) `~~~\' (
     /`-._   _\.-\
    /         )   \

```

## Display Random Messages
```sh
./hamba -r 
``` 
This will show a random inspirational message
### Display Help

To see usage instructions, run the program with the `-help` option:

```sh
./hamba -help
```

Output:

```
Usage: cowsay [OPTION] [MESSAGE]
Options:
  -say    Display the ASCII art with your message
  -help     Show this help message
Arguments:
  MESSAGE     The message to display
```


## Customizing the ASCII Art

To modify the ASCII art, edit the `cow.txt` file. For example, you can replace the content with a different ASCII drawing:

```
     __
    (oo)
  /------\/\
 / |    ||
*  ||----||
```

Running the program again will display the updated ASCII art.

## Error Handling

- If the `cow.txt` file is missing or cannot be opened, the program will display an error message:

  ```
  Error opening ASCII art file: No such file or directory
  ```

- If invalid arguments are provided, the program will notify the user and suggest using the `-help` option.


## Contribution

Feel free to fork the repository and submit pull requests to enhance the program!

