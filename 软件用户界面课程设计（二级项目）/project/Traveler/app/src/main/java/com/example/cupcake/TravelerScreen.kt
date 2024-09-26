
package com.example.cupcake

import androidx.annotation.StringRes
import androidx.compose.animation.animateContentSize
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AccountCircle
import androidx.compose.material.icons.filled.ArrowBack
import androidx.compose.material.icons.filled.FavoriteBorder
import androidx.compose.material3.AlertDialog
import androidx.compose.material3.BottomAppBar
import androidx.compose.material3.Divider
import androidx.compose.material3.FilledTonalButton
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.material3.TextButton
import androidx.compose.material3.TopAppBar
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.dimensionResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.currentBackStackEntryAsState
import androidx.navigation.compose.rememberNavController
import com.example.cupcake.data.DataSource
import com.example.cupcake.ui.OrderSummaryScreen
import com.example.cupcake.ui.OrderViewModel
import com.example.cupcake.ui.SelectOptionScreen
import com.example.cupcake.ui.StartOrderScreen

enum class TravelerScreen(@StringRes val title: Int) {
    Start(title = R.string.app_name),
    Flavor(title = R.string.choose_flavor),
    Pickup(title = R.string.choose_pickup_date),
    Summary(title = R.string.order_summary),
    Plan(title = R.string.plan),
    My(title = R.string.My),
    Community(title = R.string.Community),
    Message(title = R.string.Message),
}

/**
 * Composable that displays the topBar and displays back button if back navigation is possible.
 */
@Composable
fun CupcakeAppBar(
    currentScreen: TravelerScreen,
    canNavigateBack: Boolean,
    navigateUp: () -> Unit,
    modifier: Modifier = Modifier
) {
    TopAppBar(
//        title = { Text(stringResource(id = R.string.app_name)) },
        title = { Text(stringResource(currentScreen.title)) },
        colors = TopAppBarDefaults.mediumTopAppBarColors(
            containerColor = MaterialTheme.colorScheme.primaryContainer
        ),
        modifier = modifier,
        navigationIcon = {
            if (canNavigateBack) {
                IconButton(onClick = navigateUp) {
                    Icon(
                        imageVector = Icons.Filled.ArrowBack,
                        contentDescription = stringResource(R.string.back_button)
                    )
                }
            }
        }
    )
}

@Composable
fun CupcakeApp(
    viewModel: OrderViewModel = viewModel(),
    navController: NavHostController = rememberNavController()
) {
    val backStackEntry by navController.currentBackStackEntryAsState()
    val currentScreen = TravelerScreen.valueOf(
        backStackEntry?.destination?.route ?: TravelerScreen.Start.name
    )
    Scaffold(
        topBar = {
            CupcakeAppBar(
                currentScreen = currentScreen,
                canNavigateBack = navController.previousBackStackEntry != null,
                navigateUp = { /* TODO: implement back navigation */ }
            )
        },
        bottomBar = {
            BottomAppBar(
                containerColor = MaterialTheme.colorScheme.primaryContainer,
                contentColor = MaterialTheme.colorScheme.primary,
                modifier = Modifier.height(120.dp)
            ) {
                Row(
                    modifier = Modifier.fillMaxWidth(),
                    horizontalArrangement = Arrangement.SpaceEvenly
                ) {
                    TextButton(
                        onClick = { navController.navigate(TravelerScreen.Start.name) }
                    ) {
                        Text(text = "首页", fontSize = 20.sp)
                    }
                    TextButton(
                        onClick = { navController.navigate(TravelerScreen.Plan.name) }
                    ) {
                        Text("行程", fontSize = 20.sp)
                    }
                    TextButton(
                        onClick = { navController.navigate(TravelerScreen.Message.name) }
                    ) {
                        Text("消息", fontSize = 20.sp)
                    }
                    TextButton(
                        onClick = { navController.navigate(TravelerScreen.Community.name) }
                    ) {
                        Text("社区", fontSize = 20.sp)
                    }
                    TextButton(
                        onClick = { navController.navigate(TravelerScreen.My.name) }
                    ) {
                        Text("我的", fontSize = 20.sp)
                    }
                }
            }
        },
    ) { innerPadding ->
        val uiState by viewModel.uiState.collectAsState()

        NavHost(
            navController = navController,
            startDestination = TravelerScreen.Start.name,
            modifier = Modifier.padding(innerPadding)
        ) {
            composable(route = TravelerScreen.Start.name) {
                StartOrderScreen(
                    quantityOptions = DataSource.quantityOptions,
                    onNextButtonClicked = {
                        viewModel.setQuantity(it)
                        navController.navigate(TravelerScreen.Flavor.name)
                    },
                    modifier = Modifier
                        .fillMaxSize()
                        .padding(dimensionResource(R.dimen.padding_medium))
                )
            }
            composable(route = TravelerScreen.Flavor.name) {
                val context = LocalContext.current
                SelectOptionScreen(
                    subtotal = uiState.price,
                    onNextButtonClicked = { navController.navigate(TravelerScreen.Pickup.name) },
                    onCancelButtonClicked = {
                        // cancelOrderAndNavigateToStart(viewModel, navController)
                    },
                    options = DataSource.flavors.map { id -> context.resources.getString(id) },
                    onSelectionChanged = { viewModel.setFlavor(it) },
                    modifier = Modifier.fillMaxHeight()
                )
            }
            composable(route = TravelerScreen.Pickup.name) {
                SelectOptionScreen(
                    subtotal = uiState.price,
                    onNextButtonClicked = { navController.navigate(TravelerScreen.Summary.name) },
                    onCancelButtonClicked = {
                        // cancelOrderAndNavigateToStart(viewModel, navController)
                    },
                    options = uiState.pickupOptions,
                    onSelectionChanged = { viewModel.setDate(it) },
                    modifier = Modifier.fillMaxHeight()
                )
            }
            composable(route = TravelerScreen.Summary.name) {
                OrderSummaryScreen(
                    orderUiState = uiState,
                    onCancelButtonClicked = {
                        // cancelOrderAndNavigateToStart(viewModel, navController)
                    },
                    onSendButtonClicked = { subject: String, summary: String ->

                    },
                    modifier = Modifier.fillMaxHeight()
                )
            }
            composable(route = TravelerScreen.Plan.name) {

                AlertDialogDemo()

                Column(
                    modifier = Modifier
                        .padding(innerPadding),
                    verticalArrangement = Arrangement.spacedBy(16.dp),
                ) {
                    LazyVerticalGrid(
                        columns = GridCells.Fixed(1),
                        horizontalArrangement = Arrangement.SpaceEvenly,
                        verticalArrangement = Arrangement.spacedBy(16.dp),
                        modifier = Modifier.padding(all = 16.dp)
                    ) {
                        item{
                            Column {
                                Text("1. xxx——xxxxx——xxxx——xx——xxxxx", maxLines = Int.MAX_VALUE, fontSize = 32.sp)
                                FilledTonalButton(onClick = { }, modifier = Modifier.padding(horizontal = 4.dp)) {
                                    Text("选择")
                                }
                            }
                        }
                        item{
                            Column {
                                Text("2. xxx——xxxxx——xxxx——xx——xxxx——xxx——xxxx", maxLines = Int.MAX_VALUE, fontSize = 32.sp)
                                FilledTonalButton(onClick = { }, modifier = Modifier.padding(horizontal = 4.dp)) {
                                    Text("选择")
                                }
                            }
                        }
                        item{
                            Column {
                                Text("3. xxx——xxxxx——xxxx——xx——xxxxx", maxLines = Int.MAX_VALUE, fontSize = 32.sp)
                                FilledTonalButton(onClick = { }, modifier = Modifier.padding(horizontal = 4.dp)) {
                                    Text("选择")
                                }
                            }
                        }
                    }
                }
            }
            composable(route = TravelerScreen.Message.name) {
                Column(
                    modifier = Modifier
                        .padding(innerPadding),
                    verticalArrangement = Arrangement.spacedBy(16.dp),
                ) {
                    MessageCard("海港区 4:00", "晴，36℃")
                    Divider(
                        //颜色
                        color = Color.Gray,
                        //线的高度
                        thickness = 2.dp,
                    )
                    Text(
                        text = "距离您乘坐的K648次列车还有XX小时，请注意开车时间。",
                        style = MaterialTheme.typography.bodyMedium,
                        maxLines = Int.MAX_VALUE,
                        modifier = Modifier.animateContentSize(),
                        fontSize = 20.sp
                    )
                }
            }
            composable(route = TravelerScreen.My.name) {
                Column(
                    modifier = Modifier
                        .padding(innerPadding),
                    verticalArrangement = Arrangement.spacedBy(16.dp),
                ) {
                    Row(
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(top = 16.dp),
                        horizontalArrangement = Arrangement.SpaceEvenly
                    ) {
                        Icon(Icons.Filled.AccountCircle, null, modifier = Modifier.size(96.dp))
                        Text("匿名M", modifier = Modifier.padding(all = 28.dp), fontSize = 24.sp)
                    }
                    Divider(
                        //颜色
                        color = Color.Gray,
                        //线的高度
                        thickness = 2.dp,
                    )
                    Text(
                        text = "订单",
                        style = MaterialTheme.typography.bodyMedium,
                        maxLines = 1,
                        modifier = Modifier.padding(horizontal = 16.dp),
                        fontSize = 20.sp,
                    )
                    Divider(
                        //颜色
                        color = Color.Gray,
                        //线的高度
                        thickness = 2.dp,
                    )
                    Text(
                        text = "工具",
                        style = MaterialTheme.typography.bodyMedium,
                        maxLines = 1,
                        modifier = Modifier.padding(horizontal = 16.dp),
                        fontSize = 20.sp
                    )
                    Divider(
                        //颜色
                        color = Color.Gray,
                        //线的高度
                        thickness = 2.dp,
                    )
                    Text(
                        text = "常用信息",
                        style = MaterialTheme.typography.bodyMedium,
                        maxLines = 1,
                        modifier = Modifier.padding(horizontal = 16.dp),
                        fontSize = 20.sp
                    )
                    Divider(
                        //颜色
                        color = Color.Gray,
                        //线的高度
                        thickness = 2.dp,
                    )
                    Text(
                        text = "设置",
                        style = MaterialTheme.typography.bodyMedium,
                        maxLines = 1,
                        modifier = Modifier.padding(horizontal = 16.dp),
                        fontSize = 20.sp
                    )
                    Divider(
                        //颜色
                        color = Color.Gray,
                        //线的高度
                        thickness = 2.dp,
                    )

                }
            }
            composable(route = TravelerScreen.Community.name) {

                val scrollState = rememberScrollState()

                Column(
                    modifier = Modifier
                        .padding(innerPadding)
                        .verticalScroll(scrollState),
                    verticalArrangement = Arrangement.spacedBy(0.dp),
                ) {
                    MessageCard(username = "高远", msg = "今天骑车又摔了，还好周围没车😭😭😭")
                    MessageCard(username = "XXX", msg = "今天舍友骑车又摔了，还好周围没车😭😭😭")
                    MessageCard(username = "XXX", msg = "今天舍友骑车又摔了，还好周围没车😭😭😭")
                    MessageCard(username = "Admin", msg = "这是一条长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长长信息")

                }
            }
        }
    }
}




@Composable
fun MessageCard(username: String, msg: String) {

    var isExpanded by remember { mutableStateOf(false) }
        Surface(
            //shape = MaterialTheme.shapes.medium,
            shape = RoundedCornerShape(16.dp),
            shadowElevation = 4.dp,
            modifier = Modifier
                .padding(all = 16.dp)
                .clickable {
                    isExpanded = !isExpanded
                },
        ){
            Row(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(all = 4.dp),
                horizontalArrangement = Arrangement.SpaceBetween
            ) {
                Column {
                    Row{
                        Icon(Icons.Filled.AccountCircle, null, modifier = Modifier.size(40.dp))
                        Text(
                            text = username,
                            style = MaterialTheme.typography.titleSmall,
                            fontSize = 24.sp,
                            modifier = Modifier.padding(horizontal = 4.dp)
                        )
                    }
                    Spacer(modifier = Modifier.padding(vertical = 4.dp))
                    Text(
                        text = msg,
                        style = MaterialTheme.typography.bodyMedium,
                        maxLines = if (isExpanded) Int.MAX_VALUE else 3,
                        modifier = Modifier
                            .animateContentSize()
                            .padding(horizontal = 4.dp),
                        fontSize = 20.sp,
                        overflow = TextOverflow.Ellipsis
                    )
                    Spacer(modifier = Modifier.padding(vertical = 8.dp))
                    Row(
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(horizontal = 16.dp),
                        Arrangement.SpaceBetween
                    ){
                        Text(
                            text = "今天 11:45",
                            style = MaterialTheme.typography.labelLarge,
                        )
                        Row{
                            Icon(Icons.Filled.FavoriteBorder, null, modifier = Modifier
                                .padding(horizontal = 4.dp)
                                .size(20.dp))
                            Text(text = "24", style = MaterialTheme.typography.labelLarge,)
                        }
                    }
                }
            }
        }
    }



@Preview
@Composable
fun AlertDialogDemo(){
    val openDialog = remember { mutableStateOf(true) }

    if (openDialog.value) {
        AlertDialog(
            onDismissRequest = {
                // 当用户点击对话框以外的地方或者按下系统返回键将会执行的代码
                openDialog.value = false
            },
            title = {
                Text(
                    text = "是否重新规划路线",
                    fontWeight = FontWeight.W700,
                    style = MaterialTheme.typography.headlineSmall,
                    onTextLayout = {}
                )
            },
//            text = {
//                Text(
//                    text = "是否重新规划路线？",
//                    fontSize = 16.sp,
//                    onTextLayout = {}
//                )
//            },
            confirmButton = {
                TextButton(
                    onClick = {
                        openDialog.value = false
                    },
                ) {
                    Text(
                        "否",
                        fontWeight = FontWeight.W700,
                        style = MaterialTheme.typography.labelMedium,
                        onTextLayout = {}
                    )
                }
            },
            dismissButton = {
                TextButton(
                    onClick = {
                        openDialog.value = false
                    }
                ) {
                    Text(
                        "是",
                        fontWeight = FontWeight.W700,
                        style = MaterialTheme.typography.labelMedium,
                        onTextLayout = {},
                    )
                }
            }
        )
    }
}