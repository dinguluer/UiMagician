var Home_Single_Floor_Device_Array = [
  { floorName: 'First', roomName: 'Bedroom', deviceName: 'Tube Light', 
    url: 'ws://192.168.65.153:8089', canvasName: 'HomeFirstBedroomTubeLight_Image_ID', bLocal: 'false', btnType: 92 , bNoState: 'true', userName: 'admin', password: 'd50c3180375c27927c22e42a379c3f67', domain: 'mydomain.com', VariableName: 'HomeFirstBedroomTubeLight_VAR' , 
    onTxEventvscpclass: 30 , onTxEventvscptype: 5 , onTxEventdata: undefined , onTxEventguid: undefined , onTxEventindex: 0 , onTxEventzone: 0 , onTxEventsubzone: 1 , 
    offTxEventvscpclass: 30 , offTxEventvscptype: 6 , offTxEventdata: undefined , offTxEventguid: undefined , offTxEventindex: 0 , offTxEventzone: 0 , offTxEventsubzone: 1 , 
    onRxEventvscpclass: 20 , onRxEventvscptype: 3 , onRxEventdata: undefined , onRxEventguid: undefined , onRxEventindex: 0 , onRxEventzone: 0 , onRxEventsubzone: 1 , 
    offRxEventvscpclass: 20 , offRxEventvscptype: 4 , offRxEventdata: undefined , offRxEventguid: undefined , offRxEventindex: 0 , offRxEventzone: 0 , offRxEventsubzone: 1
  },

  { floorName: 'First', roomName: 'Balcony', deviceName: 'Bulb', 
    url: 'ws://192.168.65.153:8089', canvasName: 'HomeFirstBalconyBulb_Image_ID', bLocal: 'false', btnType: 94 , bNoState: 'true', userName: 'admin', password: 'd50c3180375c27927c22e42a379c3f67', domain: 'mydomain.com', VariableName: 'HomeFirstBalconyBulb_VAR' , 
    onTxEventvscpclass: 30 , onTxEventvscptype: 5 , onTxEventdata: undefined , onTxEventguid: undefined , onTxEventindex: 0 , onTxEventzone: 0 , onTxEventsubzone: 3 , 
    offTxEventvscpclass: 30 , offTxEventvscptype: 6 , offTxEventdata: undefined , offTxEventguid: undefined , offTxEventindex: 0 , offTxEventzone: 0 , offTxEventsubzone: 3 , 
    onRxEventvscpclass: 20 , onRxEventvscptype: 3 , onRxEventdata: undefined , onRxEventguid: undefined , onRxEventindex: 0 , onRxEventzone: 0 , onRxEventsubzone: 3 , 
    offRxEventvscpclass: 20 , offRxEventvscptype: 4 , offRxEventdata: undefined , offRxEventguid: undefined , offRxEventindex: 0 , offRxEventzone: 0 , offRxEventsubzone: 3
  },

  { floorName: 'First', roomName: 'Kitchen', deviceName: 'Fan', 
    url: 'ws://192.168.65.153:8089', canvasName: 'HomeFirstKitchenFan_Image_ID', bLocal: 'false', btnType: 94 , bNoState: 'true', userName: 'admin', password: 'd50c3180375c27927c22e42a379c3f67', domain: 'mydomain.com', VariableName: 'HomeFirstKitchenFan_VAR' , 
    onTxEventvscpclass: 30 , onTxEventvscptype: 5 , onTxEventdata: undefined , onTxEventguid: undefined , onTxEventindex: 0 , onTxEventzone: 0 , onTxEventsubzone: 5 , 
    offTxEventvscpclass: 30 , offTxEventvscptype: 6 , offTxEventdata: undefined , offTxEventguid: undefined , offTxEventindex: 0 , offTxEventzone: 0 , offTxEventsubzone: 5 , 
    onRxEventvscpclass: 20 , onRxEventvscptype: 3 , onRxEventdata: undefined , onRxEventguid: undefined , onRxEventindex: 0 , onRxEventzone: 0 , onRxEventsubzone: 5 , 
    offRxEventvscpclass: 20 , offRxEventvscptype: 4 , offRxEventdata: undefined , offRxEventguid: undefined , offRxEventindex: 0 , offRxEventzone: 0 , offRxEventsubzone: 5
  }
];






var Home_Single_Floor_Variable_Slider_Device_Array = [
  { floorName: 'First', roomName: 'Bedroom', deviceName: 'Dimmer', 
    url: 'ws://192.168.65.153:8089', canvasName: 'HomeFirstBedroomDimmer_Image_ID', canvasLocalTxtName: 'HomeFirstBedroomDimmer_Local_Txt_ID', canvasRemoteTxtName: 'HomeFirstBedroomDimmer_Remote_Txt_ID', Max: 100 , Min: 0 , userName: 'admin', password: 'd50c3180375c27927c22e42a379c3f67', domain: 'mydomain.com', VariableName: 'HomeFirstBedroomDimmer_VAR', 
    TxEventvscpclass: 30 , TxEventvscptype: 20 , TxEventdata: undefined , TxEventguid: undefined , TxEventindex: undefined , TxEventzone: 0 , TxEventsubzone: 0 , 
    RxEventvscpclass: 20 , RxEventvscptype: 40 , RxEventdata: undefined , RxEventguid: undefined , RxEventindex: undefined , RxEventzone: 0 , RxEventsubzone: 0
  }
];






var Home_Single_Floor_Variable_Switch_Device_Array = [
];





var Home_Single_Floor_Sensor_Device_Array = [
  { floorName: 'First', roomName: 'Garden', deviceName: 'Temperature Sensor', 
    url: 'ws://192.168.65.153:8089', id: 'HomeFirstGardenTemperatureSensor_Remote_Txt_ID', graphId: 'HomeFirstGardenTemperatureSensor_chart_div', graphUnitId: 'HomeFirstGardenTemperatureSensor_chart_unit_div', graphType: 'area', vscpclass: 10 , vscptype: 6 , codingIndex: 0 , 
    sensorIndex: undefined , sensorZone: undefined , sensorSubzone: undefined , 
    decimals: 1 , formatstr: '{0} Degrees {1}' , guid: '00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:02' , fncallback: undefined , userName: 'admin', password: 'd50c3180375c27927c22e42a379c3f67', domain: 'mydomain.com', VariableName: 'HomeFirstGardenTemperatureSensor_VAR'
  }
];
var Single_Floor_Device_Array = [
Home_Single_Floor_Device_Array
];







var Single_Floor_Variable_Slider_Device_Array = [
Home_Single_Floor_Variable_Slider_Device_Array
];







var Single_Floor_Variable_Switch_Device_Array = [
Home_Single_Floor_Variable_Switch_Device_Array
];







var Single_Floor_Sensor_Device_Array = [
Home_Single_Floor_Sensor_Device_Array
];

