# Focus Engine
This project describes the development of the **Focus Engine**, a cross-platform, game engine for creating modern 3D-games in C++.

## What is being developed?
The Focus Engine consists of the actual game engine itself and an editor.

- The game engine itself is the underlying codebase and the basic fundament of your game project.

- The editor is a interactive application, that allows you to easily create and organize assets for your game.

## Why another engine?
While there already are many other game engines, most of them perfectly functional and ready to use, the Focus Engine aims to combine the following features into a unique package:

### 1. Free and Open-Source
Unlike many other game engines the Focus Engine and all of its source code are released under the Apache-2.0 Licence. This means the engine is and will always be free to use, modify and redistribute in any way you desire.

### 2. Aimed at engineers and programmers
Many game engines put a strong emphasis on accessability for people who are not comfortable with writing complex code or maintaining large code bases. Instead they offer heavy abstraction layers that allow non-programmers to create simple games without writing too much (or in extreme cases any) source code.

However this oversimplification leads to unnecessary restrictions of creative expression when designing the architecture of more sophisticated games.

Because of that the Focus Engine is setup with as little boilerplate as possible, in order to fit nicely in every game developers workflow.

This also means that the Focus Engine does not enforce patterns like the Entity-Component-System or other top-down-workflows, to give you more freedom of expressing your thoughts through code, without too many engine-specific restrictions.

### 3. C++ all the way!
This point strongly coincides with the aforementioned one. C++ is often used to create game engines, due to its efficient performance and mature set of features. However when it comes to writing actual games on top of these engines, most game engines encourage developers to use alternative languages such as C# or scripting languages.

The choice of supporting an additional language (and thus adding more complexity) is usually justified by the statement that C++ is too verbose for game development and eventually slows down the overall creative process. However looking at the syntax of modern C++, specifically the changes introduced to the C++ ISO-standard with C++11 and C++20, most points of criticism regarding C++ seem to be either outdated or purely anecdotal to begin with.

The often quoted paradigm of *"sticking to an easy language and only bothering with C++, when writing performance-critical, complex code"* also seems illogical, considering that every piece of code in a video game may be performance critical and that the complexity of code is something, which can not be easily evaluated.

Finally supporting C++ as the sole programming language for the Focus Engine leads to a higher-quality C++-API, which also grants developers direct access to all its core features and inner workings. It is also obvious that a custom scripting language will never reach the maturity, feature-density and community support the C++ programming language already has.

### 4. Cross-platform
The Focus Engine, its editor and of course the games created with them are meant to run on Linux, MacOS and Windows, so that users on every of these major platforms may benefit from this project.

### 5. Powerful graphics
The Focus Engine utilizes the Vulkan graphics API to render images. This low-level API grants fine control and efficient usage of the host systems GPU.
