# Environment Classification on the STM32 L4 
This project was developed by Jeremy Gerster, 5 Jul 2025, as part of the course: *Machine Learning on Microcontrollers*, ETH Zurich.<br>
The goal of the project was to deploy an Environmental Sound Classifier (based on the UrbanSound8K dataset) onto the STM32 B-L475E-IOT01A2 board, profile its performance, and compare it against alternative implementations and state-of-the-art models.<br>

---

## Demo:

https://github.com/user-attachments/assets/fd01e48a-573f-445d-ac64-141597460702

---

## Setup (Keras model only)

Create and activate a virtual environment, then install dependencies:
```bash
python -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```
The steps involving dataset preprocessing, model training and evaluation steps are provided in `main.ipynb`.

---

### Problem & Goal
<p align="center"><img src="sources_readme/goal.png" alt="goal" width="900"></p>

### Dataset & Augmentation
<p align="center"><img src="sources_readme/dataset.png" alt="goal" width="dataset"></p>

### Preprocessing & Model Architecture
<p align="center"><img src="sources_readme/preproc_model1.png" alt="preproc_model1" width="500"></p>
<p align="center"><img src="sources_readme/preproc_model2.png" alt="preproc_model2" width="500"></p>
<p align="center"><img src="sources_readme/preproc_model3.png" alt="preproc_model3" width="500"></p>

### Hardware Platform & Implementation 
<p align="center"><img src="sources_readme/implementation1.png" alt="implementation1" width="500"></p>
<p align="center"><img src="sources_readme/implementation2.png" alt="implementation2" width="500"></p>
<p align="center"><img src="sources_readme/implementation3.png" alt="implementation3" width="500"></p>

### Experimental Evaluation 
<p align="center"><img src="sources_readme/eval1.png" alt="eval1" width="500"></p>
<p align="center"><img src="sources_readme/eval2.png" alt="eval2" width="500"></p>
<p align="center"><img src="sources_readme/eval3.png" alt="eval3" width="500"></p>

### Comparisons
<p align="center"><img src="sources_readme/comparison1.png" alt="comparison1" width="500"></p>
<p align="center"><img src="sources_readme/comparison2.png" alt="comparison2" width="500"></p>
