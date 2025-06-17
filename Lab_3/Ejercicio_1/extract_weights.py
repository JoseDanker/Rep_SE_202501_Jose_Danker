import numpy as np
import tensorflow as tf

interpreter = tf.lite.Interpreter(model_path="hello_world_float.tflite")
interpreter.allocate_tensors()

for d in interpreter.get_tensor_details():
    name = d['name']
    if 'MatMul' in name or 'BiasAdd' in name:
        try:
            w = interpreter.get_tensor(d['index'])
        except ValueError:
            print(f"// WARNING: Tensor {name} no disponible con get_tensor()")
            continue

        flat = w.flatten()
        if len(w.shape) == 2:
            shape = w.shape
            print(f"float {name.replace('/', '_')}[{shape[0]}][{shape[1]}] = {{")
            for i in range(shape[0]):
                row = ", ".join([f"{v:.6f}" for v in w[i]])
                print(f"    {{ {row} }},")
            print("};\n")
        else:
            print(f"float {name.replace('/', '_')}[{len(flat)}] = {{ {', '.join([f'{v:.6f}' for v in flat])} }};\n")
