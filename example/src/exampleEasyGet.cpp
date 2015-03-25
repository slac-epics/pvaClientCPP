/*exampleEasyGet.cpp */
/**
 * Copyright - See the COPYRIGHT that is included with this distribution.
 * EPICS pvData is distributed subject to a Software License Agreement found
 * in file LICENSE that is included with this distribution.
 */
/**
 * @author mrk
 */

/* Author: Marty Kraimer */

#include <iostream>

#include <pv/easyPVA.h>

using namespace std;
using namespace epics::pvData;
using namespace epics::pvAccess;
using namespace epics::easyPVA;


static void exampleDouble(EasyPVAPtr const &easyPVA)
{
    cout << "example double scalar\n";
    double value;
    try {
        cout << "short way\n";
        value =  easyPVA->channel("exampleDouble")->get()->getData()->getDouble();
        cout << "as double " << value << endl;
    } catch (std::runtime_error e) {
        cout << "exception " << e.what() << endl;
    }
    cout << "long way\n";
    EasyChannelPtr easyChannel = easyPVA->createChannel("exampleDouble");
    easyChannel->issueConnect();
    Status status = easyChannel->waitConnect(2.0);
    if(!status.isOK()) {cout << " connect failed\n"; return;}
    EasyGetPtr easyGet = easyChannel->createGet();
    easyGet->issueConnect();
    status = easyGet->waitConnect();
    if(!status.isOK()) {cout << " createGet failed\n"; return;}
    EasyGetDataPtr easyData = easyGet->getData();
    value = easyData->getDouble();
    cout << "as double " << value << endl;
}

static void exampleDoubleArray(EasyPVAPtr const &easyPVA)
{
    cout << "example double array\n";
    shared_vector<const double> value;
    try {
        cout << "short way\n";
        value =  easyPVA->channel("exampleDoubleArray")->get()->getData()->getDoubleArray();
        cout << "as doubleArray " << value << endl;
    } catch (std::runtime_error e) {
        cout << "exception " << e.what() << endl;
    }
    try {
        cout << "long way\n";
        EasyChannelPtr easyChannel = easyPVA->createChannel("exampleDoubleArray");
        easyChannel->connect(2.0);
        EasyGetPtr easyGet = easyChannel->createGet();
        EasyGetDataPtr easyData = easyGet->getData();
        value = easyData->getDoubleArray();
        cout << "as doubleArray " << value << endl;
    } catch (std::runtime_error e) {
        cout << "exception " << e.what() << endl;
    }
}

static void examplePowerSupply(EasyPVAPtr const &easyPVA)
{
    cout << "example powerSupply\n";
    PVStructurePtr pvStructure;
    try {
        cout << "short way\n";
        pvStructure =  easyPVA->channel("examplePowerSupply")->
            get("field()")->getData()->getPVStructure();
        cout << pvStructure << endl;
    } catch (std::runtime_error e) {
        cout << "exception " << e.what() << endl;
    }
     
}

static void exampleCADouble(EasyPVAPtr const &easyPVA)
{
    cout << "example double scalar\n";
    double value;
    try {
        cout << "short way\n";
        value =  easyPVA->channel("double00","ca",5.0)->get()->getData()->getDouble();
        cout << "as double " << value << endl;
    } catch (std::runtime_error e) {
        cout << "exception " << e.what() << endl;
    }
    cout << "long way\n";
    EasyChannelPtr easyChannel = easyPVA->createChannel("double00","ca");
    easyChannel->issueConnect();
    Status status = easyChannel->waitConnect(2.0);
    if(!status.isOK()) {cout << " connect failed\n"; return;}
    EasyGetPtr easyGet = easyChannel->createGet();
    easyGet->issueConnect();
    status = easyGet->waitConnect();
    if(!status.isOK()) {cout << " createGet failed\n"; return;}
    EasyGetDataPtr easyData = easyGet->getData();
    value = easyData->getDouble();
    cout << "as double " << value << endl;
}

static void exampleCADoubleArray(EasyPVAPtr const &easyPVA)
{
    cout << "example double array\n";
    shared_vector<const double> value;
    try {
        cout << "short way\n";
        value =  easyPVA->channel("doubleArray","ca",5.0)->get()->getData()->getDoubleArray();
        cout << "as doubleArray " << value << endl;
    } catch (std::runtime_error e) {
        cout << "exception " << e.what() << endl;
    }
    try {
        cout << "long way\n";
        EasyChannelPtr easyChannel = easyPVA->createChannel("doubleArray","ca");
        easyChannel->connect(2.0);
        EasyGetPtr easyGet = easyChannel->createGet();
        EasyGetDataPtr easyData = easyGet->getData();
        value = easyData->getDoubleArray();
        cout << "as doubleArray " << value << endl;
    } catch (std::runtime_error e) {
        cout << "exception " << e.what() << endl;
    }
}

int main(int argc,char *argv[])
{
    EasyPVAPtr easyPVA = EasyPVA::create();
    exampleDouble(easyPVA);
    exampleDoubleArray(easyPVA);
    examplePowerSupply(easyPVA);
    exampleCADouble(easyPVA);
    exampleCADoubleArray(easyPVA);
    cout << "done\n";
    return 0;
}
