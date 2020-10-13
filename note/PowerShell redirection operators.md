# PowerShell is replacing Command Prompt

@from：官网：微软 https://support.microsoft.com/en-us/help/4027690/windows-powershell-is-replacing-command-prompt

Applies to: Windows 10

------



- To create the best command-line experience, **PowerShell** is now the command shell for File Explorer. It replaces **Command Prompt** (cmd.exe) in the **Windows Logo Key** + **X** menu, in **File Explorer'**s File menu, and in the context menu that appears when you shift-right-click the whitespace in **File Explorer**. You can still enter **cmd** (or **powershell**) in File Explorer's address bar to launch the command shell.
- For those who prefer using **Command Prompt**, you can opt out of the **Windows Logo Key** ﻿+ **X** change by opening **Settings** > **Personalization** > **Taskbar**, and turning off, **Replace Command Prompt with Windows PowerShell in the menu when I right-click the start button or press Windows key+X**.

------

Last Updated: Nov 21, 2017

# About Redirection

@from：官网：微软 https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_redirection?view=powershell-7

07/22/2020

## Short description

Explains how to redirect output from PowerShell to text files.

## Long description

By default, PowerShell sends its command output to the PowerShell console. However, you can direct the output to a text file, and you can redirect error output to the regular output stream.

You can use the following methods to redirect output:

- Use the `Out-File` cmdlet, which sends command output to a text file. Typically, you use the `Out-File` cmdlet when you need to use its parameters, such as the `Encoding`, `Force`, `Width`, or `NoClobber` parameters.
- Use the `Tee-Object` cmdlet, which sends command output to a text file and then sends it to the pipeline.
- Use the <u>PowerShell redirection operators</u>.

### <u>PowerShell redirection operators</u>

The redirection operators enable you to send streams of data to a file or the **Success** output stream.

The <u>PowerShell redirection operators</u> use the following numbers to represent the available output streams:

| Stream # | Description            | Introduced in  |
| :------- | :--------------------- | :------------- |
| 1        | **Success** Stream     | PowerShell 2.0 |
| 2        | **Error** Stream       | PowerShell 2.0 |
| 3        | **Warning** Stream     | PowerShell 3.0 |
| 4        | **Verbose** Stream     | PowerShell 3.0 |
| 5        | **Debug** Stream       | PowerShell 3.0 |
| 6        | **Information** Stream | PowerShell 5.0 |
| *        | All Streams            | PowerShell 3.0 |

```
Note

There is also a **Progress** stream in PowerShell, but it is not used for redirection.
```

The <u>PowerShell redirection operators</u> are as follows, where `n` represents the stream number. The **Success** stream ( `1` ) is the default if no stream is specified.

| Operator | Description                                                 | Syntax |
| :------- | :---------------------------------------------------------- | :----- |
| `>`      | Send specified stream to a file.                            | `n>`   |
| `>>`     | **Append** specified stream to a file.                      | `n>>`  |
| `>&1`    | *Redirects* the specified stream to the **Success** stream. | `n>&1` |

```
Note

Unlike some Unix shells, you can only redirect other streams to the **Success** stream.
```

## Examples

### Example 1: Redirect errors and output to a file

This example runs `dir` on one item that will succeed, and one that will error.

```powershell
dir 'C:\', 'fakepath' 2>&1 > .\dir.log
```

It uses `2>&1` to redirect the **Error** stream to the **Success** stream, and `>` to send the resultant **Success** stream to a file called `dir.log`

### Example 2: ==Send all Success stream data to a file==

This example sends all **Success** stream data to a file called `script.log`.

```powershell
.\script.ps1 > script.log
```

### Example 3: Send Success, Warning, and Error streams to a file

This example shows how you can combine redirection operators to achieve a desired result.

```powershell
&{
   Write-Warning "hello"
   Write-Error "hello"
   Write-Output "hi"
} 3>&1 2>&1 > P:\Temp\redirection.log
```

- `3>&1` redirects the **Warning** stream to the **Success** stream.
- `2>&1` redirects the **Error** stream to the **Success** stream (which also now includes all **Warning** stream data)
- `>` redirects the **Success** stream (which now contains both **Warning** and **Error** streams) to a file called `C:\temp\redirection.log`)

### Example 4: ==Redirect all streams to a file==

This example sends all streams output from a script called `script.ps1` to a file called `script.log`

```powershell
.\script.ps1 *> script.log
```

### Example 5: Suppress all Write-Host and Information stream data

This example suppresses all information stream data. To read more about **Information** stream cmdlets, see [Write-Host](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/write-host?view=powershell-7) and [Write-Information](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/write-information?view=powershell-7)

```powershell
&{
   Write-Host "Hello"
   Write-Information "Hello" -InformationAction Continue
} 6> $null
```

### Example 6: Show the affect of Action Preferences

略

## Notes

The redirection operators that do not append data (`>` and `n>`) overwrite the current contents of the specified file without warning.

However, if the file is a read-only, hidden, or system file, the redirection **fails**. The append redirection operators (`>>` and `n>>`) do not write to a read-only file, but they append content to a system or hidden file.

To force the redirection of content to a read-only, hidden, or system file, use the `Out-File` cmdlet with its `Force` parameter.

When you are writing to files, the redirection operators use **Unicode encoding**. If the file has a different encoding, the output might not be formatted correctly. To redirect content to non-Unicode files, use the `Out-File` cmdlet with its `Encoding` parameter.

### Potential confusion with comparison operators

The `>` operator is not to be confused with the [Greater-than](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_comparison_operators?view=powershell-7#-gt) comparison operator (often denoted as `>` in other programming languages).

Depending on the objects being compared, the output using `>` can appear to be correct (because 36 is not greater than 42).

```powershell
PS> if (36 > 42) { "true" } else { "false" }
false
```

However, a check of the local filesystem can see that a file called `42` was written, with the contents `36`.

```powershell
PS> dir

Mode                LastWriteTime         Length Name
----                -------------         ------ ----
------          1/02/20  10:10 am              3 42

PS> cat 42
36
```

Attempting to use the reverse comparison `<` (less than), yields a system error:

```powershell
PS> if (36 < 42) { "true" } else { "false" }
At line:1 char:8
+ if (36 < 42) { "true" } else { "false" }
+        ~
The '<' operator is reserved for future use.
+ CategoryInfo          : ParserError: (:) [], ParentContainsErrorRecordException
+ FullyQualifiedErrorId : RedirectionNotSupported
```

If numeric comparison is the required operation, `-lt` and `-gt` should be used. See: [`-gt` Comparison Operator](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_comparison_operators?view=powershell-7#-gt)

## See also

[Out-File](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/out-file?view=powershell-7)

[Tee-Object](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/tee-object?view=powershell-7)

[about_Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_operators?view=powershell-7)

[about_Command_Syntax](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_command_syntax?view=powershell-7)

[about_Path_Syntax](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_path_syntax?view=powershell-7)

## Feedback

Submit and view feedback for

[This product](https://github.com/PowerShell/PowerShell/issues/new/choose) [This page](https://github.com/MicrosoftDocs/PowerShell-Docs/issues/new?title=&body= [Enter feedback here]  --- %23%23%23%23 Document Details ⚠ *Do not edit this section. It is required for docs.microsoft.com ➟ GitHub issue linking.* * ID%3A c276a962-ace4-a158-8b48-5181e58a3def * Version Independent ID%3A 2d6a2602-4480-d4d2-d63d-739c4d93e4b1 * Content%3A [about_Redirection - PowerShell](https%3A%2F%2Fdocs.microsoft.com%2Fen-us%2Fpowershell%2Fmodule%2Fmicrosoft.powershell.core%2Fabout%2Fabout_redirection%3Fview%3Dpowershell-7) * Content Source%3A [reference%2F7.0%2FMicrosoft.PowerShell.Core%2FAbout%2Fabout_Redirection.md](https%3A%2F%2Fgithub.com%2FMicrosoftDocs%2FPowerShell-Docs%2Fblob%2Fstaging%2Freference%2F7.0%2FMicrosoft.PowerShell.Core%2FAbout%2Fabout_Redirection.md) * Product%3A **powershell** * Technology%3A **powershell-conceptual** * GitHub Login%3A %40SteveL-MSFT * Microsoft Alias%3A **slee**)

[ View all page feedback ](https://github.com/MicrosoftDocs/PowerShell-Docs/issues?utf8=✓&q="2d6a2602-4480-d4d2-d63d-739c4d93e4b1"&in=body)

# 总结

`PowerShell is replacing Command Prompt`——所以以后优先使用PowerShell ，而不是Command Prompt (cmd.exe) 

如果需要使用穷举大法+打表大法来求解的话，那么可以使用<u>PowerShell redirection operators</u>来获得ans.txt

这个伟大的<u>PowerShell redirection operators</u>就是`>`，其具体用法如下所示

```powershell
PS D:\#GitHub\OJ> cd "d:\#GitHub\OJ\sec\" ; if ($?) { g++ 六角填数.cpp -o 六角填数 } ; if ($?) { .\六角填数 }
10
PS D:\#GitHub\OJ\sec> .\六角填数.exe > 六角填数.txt
PS D:\#GitHub\OJ\sec> type .\六角填数.txt
10
```