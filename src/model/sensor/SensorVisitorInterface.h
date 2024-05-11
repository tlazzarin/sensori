#ifndef MODEL_SENSOR_VISITOR_INTERFACE_H
#define MODEL_SENSOR_VISITOR_INTERFACE_H

namespace model{
    namespace sensor{
        class QuantitySensor;
        class EventSensor;
        class XYSensor;
        class SensorVisitorInterface{
            public:
                virtual ~SensorVisitorInterface()=default;
                virtual void visitQuantitySensor(QuantitySensor* quantitySensor)=0;
                virtual void visitEventSensor(EventSensor* eventSensor)=0;
                virtual void visitXYSensor(XYSensor* xYSensor)=0;
        };
    }
}

#endif