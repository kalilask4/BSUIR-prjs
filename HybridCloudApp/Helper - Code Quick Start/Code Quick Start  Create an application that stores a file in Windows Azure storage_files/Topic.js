function WatermarkFocus(control,defaultValue,cssValue){if(control.value==defaultValue){control.value="";control.className=cssValue}document.onkeydown=""}function WatermarkBlur(control,defaultValue,cssValue){if(control.value==""){control.value=defaultValue;control.className=cssValue}}function AddWatermark(controlName,defaultValue,cssValue){if(document.getElementById(controlName).value==""){document.getElementById(controlName).value=defaultValue;document.getElementById(controlName).className=cssValue}}function WatermarkOnSubmit(control,defaultValue,cssValue){if(control.value==defaultValue){control.value="";control.className=cssValue}}function TextBoxCharactersCounter(control,counter,max){if(control.value.length>max)control.value=control.value.substring(0,max);else counter.innerHTML=(max-control.value.length).toString()}