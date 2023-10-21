<h1 align="center">📖 42 SCOP</h1>

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/nutshell.jpeg">

<h2 align="center">Rendering engine with OpenGL for object files</h2>

## Menu

[Setup](#setup)

[How to use](#how-to-use)

[Keys](#keys)

[How it Looks](#how-it-looks)

[Object Files](#object-files)

[.mtl Files](#.mtl-files)

[Input Handling](#input-handling)

[Creating Triangle](#creating-triangles)

[Color](#color)

[UV Normalizing](#uv-normalizing)

[Normals](#normals)

[Light](#light)

[Resources](#resources)

## Setup

Have at least OpenGL 3 or above or leave the page now and run for the sake of your sanity.

You will also need:
```
	- stb_image.h
	- GLFW
	- Specific GLAD headers based on OpenGL version
	- GLM
```

## How to use

In the Makefile there are quite a few options to play around with eg:

```
make 42
make teapot
make skull
make axe
make plane
make castle
make spider
make alien
make monster
make building
make camel
make hb
make sw
make sculp
make pumpkin
make tric
make parrot
make house
```

Feel free to explore. Each one of them will launch with the corresponding object

## Keys

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

## How it Looks

With rendered text, light on

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/text.png">

Teapot with uv map texture

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/teapot.png">

Object which for I created the .obj file manually (yes I like the pain)

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/hb.png">

With wireframe

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/hb_w.png">

Plane with wireframe

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/plane.png">

An alien animal with colorful texture

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/alienanimal.png">

With basic light on and ambient at 0.0

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/alien_light_on.png">

Monster with better lighting

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/monster.png">

Skull with it's texture on

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/skull.png">

Polygon mode WIREFRAME

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/skull_wire.png">

A cool result with messed up uv mapping

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/skull1.png">

Just because it looks cool

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/skull_color.png">

Book of dreams

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/book.png">

Camel with it's texture

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/camel.png">

Polygon mode WIREFRAME

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/camel_wire.png">

42 logo with wireframe

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/42.png">

T-rex

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/trex.png">

For Star Wars fans

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/sw.png">

## Object Files

Object files (.obj) are commonly used to store 3D model information. The structure of these files can vary, allowing different layouts for vertex data. Faces, which define triangles or squares, can be represented in multiple ways, such as:

```
f 4 9 7 1
```

or

```
f 23/123/123 321/3213/213 43/45/12 423/3423/432
```

(there are more)

## .mtl Files

Material files (.mtl) contain values essential for material and lighting calculations in the rendering process. While a single object can have multiple texture files with different material attributes, this project currently supports handling one texture file per object.

## Input Handling

Make yourself a favor, plan and save all the values in a structured way, then start playing with them

## Creating Triangles

One face contains 3 or 4 indexes and each of them marks the index of an x, y and z coordinate for one point of a triangle or square.

Combining these coordinates from a face will result one triangle or square.

In case of squares I calculated 2 triangle from each square because I couldn't make the deprecated GL_QUADS to draw at that point.

## Color and Texture

Colors and textures enhance the visual appeal of 3D models. You can apply normal colors or use UV coordinates provided in the .obj file. UV coordinates represent the actual texture coordinates for the object. If these coordinates are not available, you might need to calculate them manually.

## UV Normalizing

In case you don't have them, you need to calculate it yourself, or better say, you can try lmao

## Normals

Normals are crucial for lighting calculations, contributing to the realism of the rendered scene. They define the direction a surface is facing, affecting how light interacts with the object. Proper implementation of normals is essential for accurate lighting and shading effects.

## Light

<img align=center src="https://github.com/zstenger93/scop/blob/master/readme_src/light.png">

Lighting in 3D graphics is a complex topic. Implementing different lighting models and techniques can significantly impact the visual quality of your scenes. Experimentation and understanding different lighting properties can help achieve realistic lighting effects in your 3D models.

## Resources

This site provides a good general explanation what can you do with this project

https://learnopengl.com/Introduction

[Menu](#menu)