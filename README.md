<h1 align="center">📖 42 HUMANGL</h1>

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/nutshell.jpeg">

<h2 align="center">Hierarchical modeling with OpenGL using my own matrix stack and transformations for a skeletal animation</h2>

## Menu

[Setup](#setup)

[How to use](#how-to-use)

[Keys](#keys)

[How it Looks](#how-it-looks)

[Resources](#resources)

## Setup

You need at least OpenGl 4

There is 5 include paths through the files where u need to change the username in case, you would like to run the program by yourself.

You will also need:
```
	- stb_image.h
	- GLFW
	- Specific GLAD headers based on OpenGL version
	- GLM
	- imgui
```

## How to use

```
make human
```

## Keys

I use basic GLFW functions to handle the key inputs so nothing special.

```
Handling keypress events as:
		Text rendering:
			7:		on/off to show details and keybindings
		Camera movement:
			W:		move camera forward
			A:		move camera left
			S:		move camera backwards
			D:		move camera right
			X:		move camera down
			SPACE:		move camera up
			8:		incrase camera movement speed
			9:		decrase camera movement speed
		Object Rotation:
			I:		rotates the object left on X axis
			K:		rotates the object right on X axis
			J:		rotates the object left on Y axis
			L:		rotates the object right on Y axis
			U:		rotates the object left on Z axis
			O:		rotates the object right on Z axis
			M:		incrases the speed
			N:		reduces the speed
		Polygon Mode:
			1: 		wireframe
			2:		points
			3:		filled
		Switching beteewen texture and color:
			C:		color mode
				4:	changing the value of R
				5:	changing the value of G
				6:	changing the value of B
			V:		texture mode
			B:		texture versions
						- texture
						- color
						- mixture between texture and color
						- light on
			T:		changes the texture to the next
			Y:		changes the texture to the previous
		Light:
			Z:		lighting on
			to controll it's position:
				Q:	LightPos.x -+ 0.25;
				E:	LightPos.x ++ 0.25;
				R:	LightPos.y -+ 0.25;
				F:	LightPos.y ++ 0.25;
				G:	LightPos.z -+ 0.25;
				H:	LightPos.z ++ 0.25;

```

## Video

https://github.com/zstenger93/scop/assets/115490237/019743e2-e5d1-488f-8b00-443503a921a9

## How it Looks

## Text rendering

There are quite a few ways to do it. For this project I've found `imgui` the best and esier to use compared to other ones I've tried like `freetype`.

It's considerably faster to make it compile and work. Afterwards the how to use it is straight forward.

[Menu](#menu)