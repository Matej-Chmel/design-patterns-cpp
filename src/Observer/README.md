# Observer

Observer pattern describes relationship between Subject and its Observers. Subject contains data on which all Observers depend. If that data changes, the Subject notifies the Observers who react to this change.

## Examples

- Model View Controller (MVC)
  - Many Views (Observers) depend on data in the Model (Subject). Controller or any one of the Views can change that data. If they do so, Model notifies all Views that observe it.
- Camera - Shader
  - In computer graphics, Shader is a type of program that usually runs on GPU. Camera views a scene. When Camera (Subject) moves, all Shaders (Observers) that are linked to at least one visible model, must be notified of this movement.
