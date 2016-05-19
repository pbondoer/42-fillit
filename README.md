# fillit @ 42
Can you feel it?

Group project with tdupont@42

**There is a better, faster version that uses bitfields [over
here](https://github.com/pbondoer/42-fillit-bitwise), check it out!**

After finishing [libft](https://github.com/pbondoer/42-libft), fillit is the
second mandatory project before [get_next_line](https://github.com/pbondoer/
42-get_next_line), and after that, you branch out. The purpose is to make the
smallest possible "square" (which can contain holes) with a given list of
tetriminos, but the disposition must be as such that it returns the first
possible solution when placing them recursively from the top left.

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```
