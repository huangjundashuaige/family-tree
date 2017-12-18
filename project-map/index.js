

$(function()
{

/* 位于BMap命名空间下的Map类表示地图，通过new操作符可以创建一个地图实例。
* 其参数可以是元素id也可以是元素对象。
* 注意在调用此构造函数时应确保容器元素已经添加到地图上。*/
var map = new BMap.Map("container");

/*
创建点坐标  
* 这里我们使用BMap命名空间下的Point类来创建一个坐标点。
* Point类描述了一个地理坐标点，其中116.404表示经度，39.915表示纬度。*/
var point = new BMap.Point(113.399137,23.074449); 

/*
地图初始化
* 在创建地图实例后，我们需要对其进行初始化，BMap.Map.centerAndZoom()方法要求设置中心点坐标和地图级别。 
* 地图必须经过初始化才可以执行其他操作。*/
map.centerAndZoom(point, 18);
var walking = new BMap.WalkingRoute(map, {renderOptions:{map: map, panel: "r-result"}});
var Driving = new BMap.DrivingRoute(map, {renderOptions:{map: map, panel: "r-result"}});


$("#findWalkWay").click(function(){

	walking.clearResults();
	walking.setLocation("中山大学(东校区)");
	walking.disableAutoViewport();
	var start,end;
	if($("#start_place").val().indexOf("楼")!=-1
		||$("#start_place").val().indexOf("院")!=-1
		||$("#start_place").val().indexOf("教")!=-1
		||$("#start_place").val().indexOf("座")!=-1
		||$("#start_place").val().indexOf("验")!=-1
		||$("#start_place").val().indexOf("馆")!=-1
		||$("#start_place").val().indexOf("场")!=-1
		||$("#start_place").val().indexOf("门")!=-1)
		start="中山大学东校区"+$("#start_place").val();
	else start = $("#start_place").val();
	if($("#end_place").val().indexOf("楼")!=-1
		||$("#end_place").val().indexOf("院")!=-1
		||$("#end_place").val().indexOf("教")!=-1
		||$("#end_place").val().indexOf("座")!=-1
		||$("#end_place").val().indexOf("验")!=-1
		||$("#end_place").val().indexOf("馆")!=-1
		||$("#end_place").val().indexOf("场")!=-1
		||$("#end_place").val().indexOf("门")!=-1)
		end="中山大学东校区"+$("#end_place").val();
	else end = $("#end_place").val();	
	console.log(start);
	console.log(end);
	walking.search(start, end);
});

$("#findDriveWay").click(function(){
	
	Driving.setLocation("中山大学(东校区)");
	Driving.disableAutoViewport();
	var start,end;
	if($("#start_place").val().indexOf("楼")!=-1
		||$("#start_place").val().indexOf("院")!=-1
		||$("#start_place").val().indexOf("教")!=-1
		||$("#start_place").val().indexOf("座")!=-1
		||$("#start_place").val().indexOf("验")!=-1
		||$("#start_place").val().indexOf("馆")!=-1
		||$("#start_place").val().indexOf("场")!=-1
		||$("#start_place").val().indexOf("门")!=-1
		)
		start="中山大学东校区"+$("#start_place").val();
	else start = $("#start_place").val();
	if($("#end_place").val().indexOf("楼")!=-1
		||$("#end_place").val().indexOf("院")!=-1
		||$("#end_place").val().indexOf("教")!=-1
		||$("#end_place").val().indexOf("座")!=-1
		||$("#end_place").val().indexOf("验")!=-1
		||$("#end_place").val().indexOf("馆")!=-1
		||$("#end_place").val().indexOf("场")!=-1
		||$("#end_place").val().indexOf("门")!=-1)
		end="中山大学东校区"+$("#end_place").val();
	else end = $("#end_place").val();	
	console.log(start);
	console.log(end);
	Driving.search(start, end);
});


/*
下面示例显示一个地图，等待两秒钟后，它会移动到新中心点。
* panTo()
*      将让地图平滑移动至新中心点，如果移动距离超过了当前地图区域大小，则地图会直跳到该点。
* zoomTo()
* 
* setCenter()
* 
* */
map.enableScrollWheelZoom();
/*window.setTimeout(function(){  
   map.panTo(new BMap.Point(116.450, 39.918));    
}, 1000);*/

/*
默认情况下地图不支持鼠标滚轮缩放操作，因为这样可能会影响整个页面的用户体验，
但是如果您希望在地图中使用鼠标滚轮控制缩放，则可以调用map.enableScrollWheelZoom方法来开启。
配置选项可以在Map类参考的配置方法一节中找到。
* */


});