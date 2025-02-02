//!  @file main.cpp The Combined API (CAPI) sample application.
//----------------------------------------------------------------------------
//
//  Copyright (C) 2017, Northern Digital Inc. All rights reserved.
//
//  All Northern Digital Inc. ("NDI") Media and/or Sample Code and/or Sample Code
//  Documentation (collectively referred to as "Sample Code") is licensed and provided "as
//  is" without warranty of any kind. The licensee, by use of the Sample Code, warrants to
//  NDI that the Sample Code is fit for the use and purpose for which the licensee intends to
//  use the Sample Code. NDI makes no warranties, express or implied, that the functions
//  contained in the Sample Code will meet the licensee's requirements or that the operation
//  of the programs contained therein will be error free. This warranty as expressed herein is
//  exclusive and NDI expressly disclaims any and all express and/or implied, in fact or in
//  law, warranties, representations, and conditions of every kind pertaining in any way to
//  the Sample Code licensed and provided by NDI hereunder, including without limitation,
//  each warranty and/or condition of quality, merchantability, description, operation,
//  adequacy, suitability, fitness for particular purpose, title, interference with use or
//  enjoyment, and/or non infringement, whether express or implied by statute, common law,
//  usage of trade, course of dealing, custom, or otherwise. No NDI dealer, distributor, agent
//  or employee is authorized to make any modification or addition to this warranty.
//  In no event shall NDI nor any of its employees be liable for any direct, indirect,
//  incidental, special, exemplary, or consequential damages, sundry damages or any
//  damages whatsoever, including, but not limited to, procurement of substitute goods or
//  services, loss of use, data or profits, or business interruption, however caused. In no
//  event shall NDI's liability to the licensee exceed the amount paid by the licensee for the
//  Sample Code or any NDI products that accompany the Sample Code. The said limitations
//  and exclusions of liability shall apply whether or not any such damages are construed as
//  arising from a breach of a representation, warranty, guarantee, covenant, obligation,
//  condition or fundamental term or on any theory of liability, whether in contract, strict
//  liability, or tort (including negligence or otherwise) arising in any way out of the use of
//  the Sample Code even if advised of the possibility of such damage. In no event shall
//  NDI be liable for any claims, losses, damages, judgments, costs, awards, expenses or
//  liabilities of any kind whatsoever arising directly or indirectly from any injury to person
//  or property, arising from the Sample Code or any use thereof
//
//----------------------------------------------------------------------------


#include "polarisv.h"


PolarisV::PolarisV()
{
    capi = CombinedApi();
    apiSupportsBX2 = false;
    // Attempt to connect to the device
    if (capi.connect("P9-01525.local") != 0)
    {
        // Print the error and exit if we can't connect to a device
        std::cout << "Connection Failed!" << std::endl;
        std::cout << "Press Enter to continue...";
//        std::cin.ignore();
    }
    else
    {
        std::cout << "Connected!" << std::endl;

        // Print the firmware version for debugging purposes
        std::cout << capi.getUserParameter("Features.Firmware.Version") << std::endl;

        // Determine if the connected device supports the BX2 command
        determineApiSupportForBX2();

        // Initialize the system. This clears all pstd::cin.ignore();reviously loaded tools, unsaved settings etc...
        onErrorPrintDebugMessage("capi.initialize()", capi.initialize());

        // Demonstrate getting/setting user parameters
        configureUserParameters();

        // Various tool types are configured in slightly different ways
//        if (passiveTool.isEmpty()){
//            configurePassiveTools(default_passiveTool);
//        }else{
//            configurePassiveTools(passiveTool);
//        }
//        configurePassiveTools("3_332.rom");
//        fileName = "5_1280_3.5mm";
        configurePassiveTools("5_1190.rom");

//        configurePassiveTools("3_161.rom");
//        configurePassiveTools("SLen_350_18.rom");
//        configurePassiveTools("kurze_Spitze_Test.rom");
        configurePassiveTools("NDI_Tracker4.rom");

        configurePassiveTools("NDI_Tracker2.rom");

        //configureActiveWirelessTools();
        //if (scu_hostname.length() > 0)
        //{
        //	configureActiveTools(scu_hostname);
        //}

        // Dummy tools are used to report 3Ds in the absence of real tools.
        // TSTART will fail if real and dummy tools of the same type are enabled simultaneously.
        // To experiment with dummy tools, comment out the previous tool configurations first.
        // configureDummyTools();

        // Once loaded or detected, tools are initialized and enabled the same way
        initializeAndEnableTools();
    }
}

//QString PolarisV::getFileName()
//{
//    return fileName;
//}


/**
 * @brief There's no standard cross platform sleep() method prior to C++11
 */
void PolarisV::sleepSeconds(unsigned numSeconds)
{
   timer->start(numSeconds);
}

/**
 * @brief Prints a debug message if a method call failed.
 * @details To use, pass the method name and the error code returned by the method.
 *          Eg: onErrorPrintDebugMessage("capi.initialize()", capi.initialize());
 *          If the call succeeds, this method does nothing.
 *          If the call fails, this method prints an error message to stdout.
 */
void PolarisV::onErrorPrintDebugMessage(std::string methodName, int errorCode)
{
    if (errorCode < 0)
    {
//        std::cout << methodName << " failed: " << capi.errorToString(errorCode) << std::endl;
    }
}

/**
* @brief Returns the string: "[tool.id] s/n:[tool.serialNumber]" used in CSV output
*/
std::string PolarisV::getToolInfo(std::string toolHandle)
{
    // Get the port handle info from PHINF
    PortHandleInfo info = capi.portHandleInfo(toolHandle);

    // Return the ID and SerialNumber the desired string format
    std::string outputString = info.getToolId();
    outputString.append(" s/n:").append(info.getSerialNumber());
    return outputString;
}

/**
* @brief Returns a string representation of the data in CSV format.
* @details The CSV format is: "Frame#,ToolHandle,Face,TransformStatus,q0,qx,qy,qz,tx,ty,tz,error,#markers,[Marker1:status,x,y,z],[Marker2..."
*/
std::string PolarisV::toolDataToCSV(const ToolData& toolData)
{
    std::stringstream stream;
    stream << std::setprecision(toolData.PRECISION) << std::setfill('0');
    stream << "" << static_cast<unsigned>(toolData.frameNumber) << ","
           << "Port:" << static_cast<unsigned>(toolData.transform.toolHandle) << ",";
    if (toolData.transform.isMissing())
    {
        stream << "Missing,,,,,,,,";
    }
    else
    {
        stream << static_cast<unsigned>(toolData.transform.getFaceNumber()) << ","
               << TransformStatus::toString(toolData.transform.getErrorCode()) << ","
               << toolData.transform.q0 << "," << toolData.transform.qx << "," << toolData.transform.qy << "," << toolData.transform.qz << ","
               << toolData.transform.tx << "," << toolData.transform.ty << "," << toolData.transform.tz << "," << toolData.transform.error;
    }

    // Each marker is printed as: status,tx,ty,tz
    stream << "," << toolData.markers.size();
    for ( int i = 0; i < toolData.markers.size(); i++)
    {
        stream << "," << MarkerStatus::toString(toolData.markers[i].status);
        if (toolData.markers[i].status == MarkerStatus::Missing)
        {
            stream << ",,,";
        }
        else
        {
            stream << "," << toolData.markers[i].x << "," << toolData.markers[i].y << "," << toolData.markers[i].z;
        }
    }
    return stream.str();
}

/**
 * @brief Write tracking data to a CSV file in the format: "#Tools,ToolInfo,Frame#,[Tool1],Frame#,[Tool2]..."
 * @details It's worth noting that the number lines in the file does not necessarily match the number of frames collected.
 *          NDI measurement systems support different types of tools: passive, active, and active-wireless.
 *          Because different tool types are detected in different physical ways, each tool type has a separate frame for
 *          collecting data for all tools of that type. Each line of the file has the same number of tools, but each tool
 *          may have a different frame number that corresponds to its tool type.
 * @param numberOfLines The number of lines to write
 */
void PolarisV::writeCSV(std::string fileName, int numberOfLines)
{
    // Assumption: tools are not enabled/disabled during CSV output
    std::vector<PortHandleInfo> portHandles = capi.portHandleSearchRequest(PortHandleSearchRequestOption::Enabled);
    if (portHandles.size() < 1)
    {
//        std::cout << "Cannot write CSV file when no tools are enabled!" << std::endl;
        return;
    }

    // Lookup and store the serial number for each enabled tool
    std::vector<ToolData> enabledTools;
    for (int i = 0; i < portHandles.size(); i++)
    {
        enabledTools.push_back(ToolData());
        enabledTools.back().transform.toolHandle = (uint16_t) capi.stringToInt(portHandles[i].getPortHandle());
        enabledTools.back().toolInfo = getToolInfo(portHandles[i].getPortHandle());
    }

    // Start tracking
//    std::cout << std::endl << "Entering tracking mode and collecting data for CSV file..." << std::endl;
    onErrorPrintDebugMessage("capi.startTracking()", capi.startTracking());

    // Print header information to the first line of the output file
//    std::cout << std::endl << "Writing CSV file..." << std::endl;
    std::ofstream csvFile(fileName.c_str());
    csvFile << "#Tools,ToolInfo,Frame#,PortHandle,Face#,TransformStatus,Q0,Qx,Qy,Qz,Tx,Ty,Tz,Error,Markers,State,Tx,Ty,Tz" << std::endl;

    // Loop to gather tracking data and write to the file
    int linesWritten = 0;
    int previousFrameNumber = 0; // use this variable to avoid printing duplicate data with BX
    while (linesWritten < numberOfLines)
    {
        // Get new tool data using BX2
        std::vector<ToolData> newToolData = apiSupportsBX2 ? capi.getTrackingDataBX2("--6d=tools --3d=tools --sensor=none --1d=buttons") :
                                                             capi.getTrackingDataBX(TrackingReplyOption::TransformData | TrackingReplyOption::AllTransforms);

        // Update enabledTools array with new data
        for (int t = 0; t < enabledTools.size(); t++)
        {
            for (int j = 0; j < newToolData.size(); j++)
            {
                if (enabledTools[t].transform.toolHandle == newToolData[j].transform.toolHandle)
                {
                    // Copy the new tool data
                    newToolData[j].toolInfo = enabledTools[t].toolInfo; // keep the serial number
                    enabledTools[t] = newToolData[j]; // use the new data
                }
            }
        }

        // If we're using BX2 there's extra work to do because BX2 and BX use opposite philosophies.
        // BX will always return data for all enabled tools, but some of the data may be old: #linesWritten == # BX commands
        // BX2 never returns old data, but cannot guarantee new data for all enabled tools with each call: #linesWritten <= # BX2 commands
        // We want a CSV file with data for all enabled tools in each line, but this requires multiple BX2 calls.
        if (apiSupportsBX2)
        {
            // Count the number of tools that have new data
            int newDataCount = 0;
            for (int t = 0; t < enabledTools.size(); t++)
            {
                if (enabledTools[t].dataIsNew)
                {
                    newDataCount++;
                }
            }

            // Send another BX2 if some tools still have old data
            if (newDataCount < enabledTools.size())
            {
                continue;
            }
        }
        else
        {
            if (previousFrameNumber == enabledTools[0].frameNumber)
            {
                // If the frame number didn't change, don't print duplicate data to the CSV, send another BX
                continue;
            }
            else
            {
                // This frame number is different, so we'll print a line to the CSV, but remember it for next time
                previousFrameNumber = enabledTools[0].frameNumber;
            }
        }

        // Print a line of the CSV file if all enabled tools have new data
        csvFile << std::dec << enabledTools.size();
        for (int t = 0; t < enabledTools.size(); t++)
        {
            csvFile << "," << enabledTools[t].toolInfo << "," << toolDataToCSV(enabledTools[t]);
            enabledTools[t].dataIsNew = false; // once printed, the data becomes "old"
        }
        csvFile << std::endl;
        linesWritten++;
    }

    // Stop tracking and return to configuration mode
    onErrorPrintDebugMessage("capi.stopTracking()", capi.stopTracking());
}

/**
 * @brief Prints a ToolData object to stdout
 * @param toolData The data to print
 */
void PolarisV::printToolData(const ToolData& toolData)
{
    if (toolData.systemAlerts.size() > 0)
    {
//        std::cout << "[" << toolData.systemAlerts.size() << " alerts] ";
        for (int a = 0; a < toolData.systemAlerts.size(); a++)
        {
//            std::cout << toolData.systemAlerts[a].toString() << std::endl;
        }
    }

    if (toolData.buttons.size() > 0)
    {
//        std::cout << "[buttons: ";
        for (int b = 0; b < toolData.buttons.size(); b++)
        {
//            std::cout << ButtonState::toString(toolData.buttons[b]) << " ";
        }
//        std::cout << "] ";
    }
    std::string temp=toolDataToCSV(toolData);
//    std::cout << temp << std::endl;
    emit sendToolData(toolData);
    emit sendData(QString::fromStdString(temp));

}

/**
 * @brief Put the system into tracking mode, and get a few frames of data.
 */
void PolarisV::printTrackingData()
{

    // Demonstrate TX command: ASCII command sent, ASCII reply received
//    std::cout << capi.getTrackingDataTX() << std::endl;

    // Demonstrate BX or BX2 command
    std::vector<ToolData> toolData =  apiSupportsBX2 ? capi.getTrackingDataBX2() : capi.getTrackingDataBX();

    // Print to stdout in similar format to CSV
//    std::cout << "[alerts] [buttons] Frame#,ToolHandle,Face#,TransformStatus,Q0,Qx,Qy,Qz,Tx,Ty,Tz,Error,#Markers,State,Tx,Ty,Tz" << std::endl;
    for (int i = 0; i < toolData.size(); i++)
    {
        printToolData(toolData[i]);
        if(_singleFrame)
        {
            _tools.push_back(PolarisTool(toolData[i]));
        }
    }
}

/**
 * @brief Initialize and enable loaded tools. This is the same regardless of tool type.
 */
void PolarisV::initializeAndEnableTools()
{
//    std::cout << std::endl << "Initializing and enabling tools..." << std::endl;

    // Initialize and enable tools
    std::vector<PortHandleInfo> portHandles = capi.portHandleSearchRequest(PortHandleSearchRequestOption::NotInit);
    for (int i = 0; i < portHandles.size(); i++)
    {
        onErrorPrintDebugMessage("capi.portHandleInitialize()", capi.portHandleInitialize(portHandles[i].getPortHandle()));
        onErrorPrintDebugMessage("capi.portHandleEnable()", capi.portHandleEnable(portHandles[i].getPortHandle()));
    }

    // Print all enabled tools
    portHandles = capi.portHandleSearchRequest(PortHandleSearchRequestOption::Enabled);
    for (int i = 0; i < portHandles.size(); i++)
    {
//        std::cout << portHandles[i].toString() << std::endl;
    }
}

/**
 * @brief Loads a tool from a tool definition file (.rom)
 */
void PolarisV::loadTool(QString fileName)
{
    // Request a port handle to load a passive tool into
    int portHandle = capi.portHandleRequest();
    onErrorPrintDebugMessage("capi.portHandleRequest()", portHandle);

    QDir dir =QDir::currentPath();
    dir.cdUp();
    dir.cdUp();
    dir.cd("sroms");
    QString directory=dir.path();
    directory+=QDir::separator();
    directory+=fileName;
    std::string loaddir=directory.toStdString();
    // Load the .rom file using the previously obtained port handle
    capi.loadSromToPort(loaddir, portHandle);
}

/**
 * @brief Demonstrate loading passive tools.
 * @details Passive tools use NDI spheres to passively reflect IR light to the cameras.
 */
void PolarisV::configurePassiveTools(QString fileName)
{
    // Load a few passive tool definitions from a .rom files
//    std::cout << std::endl << "Configuring Passive Tools - Loading .rom Files..." << std::endl;
    loadTool(fileName);
}

/**
 * @brief Demonstrate detecting active tools.
 * @details Active tools are connected through a System Control Unit (SCU) with physical wires.
 */
void PolarisV::configureActiveTools(std::string scuHostname)
{
    // Setup the SCU connection for demonstrating active tools
//    std::cout << std::endl << "Configuring Active Tools - Setup SCU Connection" << std::endl;
    onErrorPrintDebugMessage("capi.setUserParameter()", capi.setUserParameter("Param.Connect.SCU Hostname", scuHostname));
//    std::cout << capi.getUserParameter("Param.Connect.SCU Hostname") << std::endl;

    // Wait a few seconds for the SCU to detect any wired tools plugged in
//    std::cout << std::endl << "Demo Active Tools - Detecting Tools..." << std::endl;
    sleepSeconds(2);

    // Print all port handles
    std::vector<PortHandleInfo> portHandles = capi.portHandleSearchRequest(PortHandleSearchRequestOption::NotInit);
    for (int i = 0; i < portHandles.size(); i++)
    {
//        std::cout << portHandles[i].toString() << std::endl;
    }
}

/**
 * @brief Demonstrate loading an active wireless tool.
 * @details Active wireless tools are battery powered and emit IR in response to a chirp from the illuminators.
 */
void PolarisV::configureActiveWirelessTools()
{
    // Load an active wireless tool definitions from a .rom files
//    std::cout << std::endl << "Configuring an Active Wireless Tool - Loading .rom File..." << std::endl;
    loadTool("sroms/active-wireless.rom");
}

/**
 * @brief Demonstrate loading dummy tools of each tool type.
 * @details Dummy tools are used to report 3Ds in the absence of real tools.
 *          Dummy tools should not be loaded with regular tools of the same type.
 *          TSTART will fail if real and dummy tools are enabled simultaneously.
 */
void PolarisV::configureDummyTools()
{
//    std::cout << std::endl << "Loading passive, active-wireless, and active dummy tools..." << std::endl;
    onErrorPrintDebugMessage("capi.loadPassiveDummyTool()", capi.loadPassiveDummyTool());
    onErrorPrintDebugMessage("capi.loadActiveWirelessDummyTool()", capi.loadActiveWirelessDummyTool());
    onErrorPrintDebugMessage("capi.loadActiveDummyTool()", capi.loadActiveDummyTool());
}

/**
 * @brief Demonstrate getting/setting user parameters.
 */
void PolarisV::configureUserParameters()
{
//    std::cout << capi.getUserParameter("Param.User.String0") << std::endl;
    onErrorPrintDebugMessage("capi.setUserParameter(Param.User.String0, customString)", capi.setUserParameter("Param.User.String0", "customString"));
//    std::cout << capi.getUserParameter("Param.User.String0") << std::endl;
    onErrorPrintDebugMessage("capi.setUserParameter(Param.User.String0, emptyString)", capi.setUserParameter("Param.User.String0", ""));
}


/**
 * @brief Determines whether an NDI device supports the BX2 command by looking at the API revision
 */
void PolarisV::determineApiSupportForBX2()
{
    // Lookup the API revision
    std::string response = capi.getApiRevision();

    // Refer to the API guide for how to interpret the APIREV response
    char deviceFamily = response[0];
    int majorVersion = capi.stringToInt(response.substr(2,3));

    // As of early 2017, the only NDI device supporting BX2 is the Vega
    // Vega is a Polaris device with API major version 003
    if ( deviceFamily == 'G' && majorVersion >= 3)
    {
        apiSupportsBX2 = true;
    }
}

/**
 * @brief   The entry point for the CAPIsample application.
 * @details The invocation of CAPIsample is expected to pass a few arguments: ./CAPIsample [hostname] [scu_hostname]
 *          arg(0) - (default)  The path to this application (ignore this)
 *          arg(1) - (required) The measurement device's hostname, IP address, or serial port.
 *          Eg: Connecting to device by IP address: "169.254.8.50"
 *          Eg: Connecting to device by zeroconf hostname: "P9-B0103.local"
 *          Eg: Connecting to serial port varies by OS: "COM10" (Win), "/dev/ttyUSB0" (Linux), "/dev/cu.usbserial-001014FA" (Mac)
 *          arg(2) - (optional) A System Control Unit (SCU) hostname, used to connect active tools.
 */

int PolarisV::startStreaming()
{

    // Once the system is put into tracking mode, data is returned for whatever tools are enabled
    // Start tracking, output a few frames of data, and stop tracking
//    std::cout << std::endl << "Entering tracking mode and collecting data..." << std::endl;
    onErrorPrintDebugMessage("capi.startTracking()", capi.startTracking());
    _streaming=true;
    while(_streaming)
    {
        printTrackingData();
    }

    // Stop tracking (back to configuration mode)
//    std::cout << std::endl << "Leaving tracking mode and returning to configuration mode..." << std::endl;
    onErrorPrintDebugMessage("capi.stopTracking()", capi.stopTracking());
    emit streamingStopped();

    // Give the user a chance to view the output in the terminal before exiting
//    std::cout << "CAPI complete." << std::endl;
    return 0;
}

int PolarisV::getFrame()
{

    // Once the system is put into tracking mode, data is returned for whatever tools are enabled
    // Start tracking, output a few frames of data, and stop tracking
//    std::cout << std::endl << "Entering tracking mode and collecting data..." << std::endl;
    _singleFrame = true;
    _tools.clear();
    onErrorPrintDebugMessage("capi.startTracking()", capi.startTracking());

    printTrackingData();

    _singleFrame = false;
    // Stop tracking (back to configuration mode)
//    std::cout << std::endl << "Leaving tracking mode and returning to configuration mode..." << std::endl;
    onErrorPrintDebugMessage("capi.stopTracking()", capi.stopTracking());
    emit streamingStopped();

//    for(int i = 0;i<(_tools.length()-1);i++)
//    {
//        qDebug()<<static_cast<QString>(_tools[i])<<static_cast<QQuaternion>(_tools[i])<<static_cast<QMatrix4x4>(_tools[i]);
//    }

    // Give the user a chance to view the output in the terminal before exiting
//    std::cout << "CAPI complete." << std::endl;
    return 0;
}

//void PolarisV::setRomFile(QString rom)
//{
//fileName=rom;
//configurePassiveTools();
////    passiveTool=rom+".rom";
//initializeAndEnableTools();
//}



int PolarisV::getData(int number)
{

    // Once the system is put into tracking mode, data is returned for whatever tools are enabled
    // Start tracking, output a few frames of data, and stop tracking
    std::cout << std::endl << "Entering tracking mode and collecting data..." << std::endl;
    onErrorPrintDebugMessage("capi.startTracking()", capi.startTracking());
    int lines=0;
    while(number<lines)
    {
        printTrackingData();
        lines++;
    }

    // Stop tracking (back to configuration mode)
    std::cout << std::endl << "Leaving tracking mode and returning to configuration mode..." << std::endl;
    onErrorPrintDebugMessage("capi.stopTracking()", capi.stopTracking());
    emit streamingStopped();

    // Give the user a chance to view the output in the terminal before exiting
    std::cout << "CAPI complete." << std::endl;

    return 0;
}

void PolarisV::stopStreaming()
{
    _streaming = false;
}


