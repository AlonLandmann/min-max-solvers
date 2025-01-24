# Min Max Solvers

This repo contains a progression of [min-max](https://en.wikipedia.org/wiki/Minimax) solvers that I built for fun while taking my first programming course in C-programming at the Technion - Israel institute of technology in 2017.

I've left the code completely untouched since then, but it's still working great.

The first file is simply a direct min-max tree solver that requires that the user define the payoffs in the final nodes. The second one is a tic-tac-toe solver, which solves the game in real-time.

Perhaps the most interesting is the third, which is a connect-four solver, and not a bad one. It doesn't solve the full game tree, which is quite large, but instead uses the same approach traditional chess engines use of building a heuristic positional evaluation function when a certain depth down the min-max tree is reached.

Before starting the game the user is prompted to determine the strength of the computer. The number he enters is related to how deep the solver will look down the game tree before it uses the heuristic.

When learning python seven years later, I've rebuilt these solvers in python, but lo and behold they turned out much much slower and worse than the ones I built as a newbie in 2017. C just works better.

Please give the connect-four game a try if you're interested, it's a really strong and formidable opponent, and I'm quite sure level 4, 5, and higher are quite tough to beat. I don't think I've ever beaten them.

If you don't trust the executable files, you may have a look at the C code, and recompile it. Just be sure to use the -O3 optimization flag.

```
gcc -O3 3-connect-four.c -o 3-connect-four
```
